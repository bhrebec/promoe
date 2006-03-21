#include <xmmsclient/xmmsclient.h>
#include <sigc++/sigc++.h>

#include "xmmsclient_promoe.h"

static
void generic_handler (xmmsc_result_t *res, void *userdata)
{
	XMMSResult* r = static_cast<XMMSResult*>(userdata);
	if (!r) {
		cout << "********* FATAL ERROR ***********" << endl;
		cout << "The generic handler was called without a result!" << endl;
		return;
	}
	r->emit ();
}

XMMSClient::XMMSClient (const char *name)
{
	m_xmmsc = xmmsc_init (name);
}

bool
XMMSClient::connect (const char *path)
{
	if (!xmmsc_connect (m_xmmsc, path)) {
		return false;
	}

	return true;
}

XMMSClient::~XMMSClient ()
{
	xmmsc_unref (m_xmmsc);
}

XMMSResult::XMMSResult (xmmsc_result_t *res)
  : m_res(res), m_inited(false), m_signal()
{
}

XMMSResult::XMMSResult (const XMMSResult &src)
  : m_res(src.m_res)
{
}

void
XMMSResult::restart (void)
{
	xmmsc_result_t *nres;
	nres = xmmsc_result_restart (m_res);
	xmmsc_result_unref (m_res);
	xmmsc_result_unref (nres);
	m_res = nres;
}

void
XMMSResult::connect (const sigc::slot<void, XMMSResult*>& slot_)
{
	if (!m_inited) {
		xmmsc_result_notifier_set (m_res, &generic_handler, this);
		m_inited = true;
	}
	m_signal.connect (slot_);
}

static void
dict_foreach (const void *key, 
			  xmmsc_result_value_type_t type, 
			  const void *value, 
			  void *udata)
{
	list<const char *> *i (static_cast<list<const char*>*>(udata));
	i->push_front (static_cast<const char*>(key));
}

list<const char *>
XMMSResultDict::getDictKeys (void)
{
	list<const char *> i;

	xmmsc_result_dict_foreach (m_res, dict_foreach, static_cast<void*>(&i));

	return i;
}

static void
propdict_foreach (const void *key, 
			  xmmsc_result_value_type_t type, 
			  const void *value, 
			  const char *source,
			  void *udata)
{
	list<const char *> *i (static_cast<list<const char*>*>(udata));
	i->push_front (static_cast<const char*>(key));
}

list<const char *>
XMMSResultDict::getPropDictKeys (void)
{
	list<const char *> i;

	xmmsc_result_propdict_foreach (m_res, propdict_foreach, static_cast<void*>(&i));

	return i;
}

XMMSResult::~XMMSResult ()
{
	xmmsc_result_unref (m_res);
}
