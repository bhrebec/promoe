#ifndef __SKIN_H__
#define __SKIN_H__

#include <iostream>

#include <QPixmap>
#include <QPainter>
#include <QWidget>
#include <QMap>
#include <QDir>

class Skin : public QWidget
{
	Q_OBJECT
	public:
		static Skin *getInstance (void);

		void setSkin (const QString& name);
		static QPixmap getPixmap (const QString&, QDir);
		
		const QPixmap getItem (uint part) const { return m_items[part]; }
		const QPixmap getPls (uint part) const { return m_playlist[part]; }
		const QPixmap getLetter (uint c) const { return m_letterMap[c]; }
		const QPixmap getNumber (uint c) const { return m_numbers[c]; }
		uint getNumberSize () { return m_numbers.size(); }
		const QByteArray getPLeditValue (QByteArray c) const { return m_pledit_txt[c]; }

		enum Part {
			NONE,
			MAIN_WINDOW,
			ABOUT_0,
			ABOUT_1,
			MONO_0,
			MONO_1,
			STEREO_0,
			STEREO_1,
			MENUBUTTON_0,
			MENUBUTTON_1,
			MINIMIZE_0,
			MINIMIZE_1,
			CLOSE_0,
			CLOSE_1,
			SHADE_1_0,
			SHADE_1_1,
			SHADE_2_0,
			SHADE_2_1,
			TITLEBAR_0,
			TITLEBAR_1,
			STATUSBAR_0,
			STATUSBAR_1,
			SEEKBAR,
			SEEKBAR_POS_0,
			SEEKBAR_POS_1,
			REPEAT_ON_0,
			REPEAT_ON_1,
			REPEAT_OFF_0,
			REPEAT_OFF_1,
			SHUFFLE_ON_0,
			SHUFFLE_ON_1,
			SHUFFLE_OFF_0,
			SHUFFLE_OFF_1,
			EQ_ON_0,
			EQ_ON_1,
			EQ_OFF_0,
			EQ_OFF_1,
			PLS_ON_0,
			PLS_ON_1,
			PLS_OFF_0,
			PLS_OFF_1,
			BTN_PREV_0,
			BTN_PREV_1,
			BTN_PLAY_0,
			BTN_PLAY_1,
			BTN_PAUSE_0,
			BTN_PAUSE_1,
			BTN_STOP_0,
			BTN_STOP_1,
			BTN_NEXT_0,
			BTN_NEXT_1,
			BTN_EJECT_0,
			BTN_EJECT_1,
			TEXTBG,
			PIC_PLAY,
			PIC_PAUSE,
			PIC_STOP,
			POSBAR,
			POSBAR_BTN_0,
			POSBAR_BTN_1,
			VOLUMEBAR_POS_0,
			VOLUMEBAR_POS_1,
			VOLUMEBAR_POS_2,
			VOLUMEBAR_POS_3,
			VOLUMEBAR_POS_4,
			VOLUMEBAR_POS_5,
			VOLUMEBAR_POS_6,
			VOLUMEBAR_POS_7,
			VOLUMEBAR_POS_8,
			VOLUMEBAR_POS_9,
			VOLUMEBAR_POS_10,
			VOLUMEBAR_POS_11,
			VOLUMEBAR_POS_12,
			VOLUMEBAR_POS_13,
			VOLUMEBAR_POS_14,
			VOLUMEBAR_POS_15,
			VOLUMEBAR_POS_16,
			VOLUMEBAR_POS_17,
			VOLUMEBAR_POS_18,
			VOLUMEBAR_POS_19,
			VOLUMEBAR_POS_20,
			VOLUMEBAR_POS_21,
			VOLUMEBAR_POS_22,
			VOLUMEBAR_POS_23,
			VOLUMEBAR_POS_24,
			VOLUMEBAR_POS_25,
			VOLUMEBAR_POS_26,
			VOLUMEBAR_POS_27,
			VOLBAR_BTN_0,
			VOLBAR_BTN_1,
			CLUTTER_ON,
			CLUTTER_OFF,
			CLUTTER_O,
			CLUTTER_A,
			CLUTTER_I,
			CLUTTER_D,
			CLUTTER_V,
			EQ_WIN_BG,
			EQ_WIN_ON_0,
			EQ_WIN_ON_1,
			EQ_WIN_OFF_0,
			EQ_WIN_OFF_1,
			EQ_WIN_AUTO_ON_0,
			EQ_WIN_AUTO_ON_1,
			EQ_WIN_AUTO_OFF_0,
			EQ_WIN_AUTO_OFF_1,
			EQ_WIN_PRESET_0,
			EQ_WIN_PRESET_1,
			EQ_WIN_GRAPH_BG,
			EQ_WIN_BAR_POS_0,
			EQ_WIN_BAR_POS_1,
			EQ_WIN_BAR_POS_2,
			EQ_WIN_BAR_POS_3,
			EQ_WIN_BAR_POS_4,
			EQ_WIN_BAR_POS_5,
			EQ_WIN_BAR_POS_6,
			EQ_WIN_BAR_POS_7,
			EQ_WIN_BAR_POS_8,
			EQ_WIN_BAR_POS_9,
			EQ_WIN_BAR_POS_10,
			EQ_WIN_BAR_POS_11,
			EQ_WIN_BAR_POS_12,
			EQ_WIN_BAR_POS_13,
			EQ_WIN_BAR_POS_14,
			EQ_WIN_BAR_POS_15,
			EQ_WIN_BAR_POS_16,
			EQ_WIN_BAR_POS_17,
			EQ_WIN_BAR_POS_18,
			EQ_WIN_BAR_POS_19,
			EQ_WIN_BAR_POS_20,
			EQ_WIN_BAR_POS_21,
			EQ_WIN_BAR_POS_22,
			EQ_WIN_BAR_POS_23,
			EQ_WIN_BAR_POS_24,
			EQ_WIN_BAR_POS_25,
			EQ_WIN_BAR_POS_26,
			EQ_WIN_BAR_POS_27,
			EQ_WIN_BAR_BTN_0,
			EQ_WIN_BAR_BTN_1,
			BALANCE_POS_0,
			BALANCE_POS_1,
			BALANCE_POS_2,
			BALANCE_POS_3,
			BALANCE_POS_4,
			BALANCE_POS_5,
			BALANCE_POS_6,
			BALANCE_POS_7,
			BALANCE_POS_8,
			BALANCE_POS_9,
			BALANCE_POS_10,
			BALANCE_POS_11,
			BALANCE_POS_12,
			BALANCE_POS_13,
			BALANCE_POS_14,
			BALANCE_POS_15,
			BALANCE_POS_16,
			BALANCE_POS_17,
			BALANCE_POS_18,
			BALANCE_POS_19,
			BALANCE_POS_20,
			BALANCE_POS_21,
			BALANCE_POS_22,
			BALANCE_POS_23,
			BALANCE_POS_24,
			BALANCE_POS_25,
			BALANCE_POS_26,
			BALANCE_POS_27,
			BALANCE_BTN_0,
			BALANCE_BTN_1,
		};

		enum PlaylistParts {
			PLS_CORNER_UL_0,
			PLS_CORNER_UL_1,
			PLS_CORNER_UR_0,
			PLS_CORNER_UR_1,

			PLS_TBAR_0,
			PLS_TBAR_1,

			PLS_TFILL_0,
			PLS_TFILL_1,
			PLS_BFILL_0,
			PLS_BFILL_1 = PLS_BFILL_0,

			PLS_VISMINI_0,
			PLS_VISMINI_1 = PLS_VISMINI_0,

			PLS_LFILL_0,
			PLS_LFILL_1 = PLS_LFILL_0,
			PLS_RFILL_0,
			PLS_RFILL_1 = PLS_RFILL_0,
			PLS_RFILL2_0,
			PLS_RFILL2_1 = PLS_RFILL2_0,
			PLS_RFILL3_0,
			PLS_RFILL3_1 = PLS_RFILL3_0,

			PLS_CLOSE_BTN_0,
			PLS_CLOSE_BTN_1,
			PLS_SHADE_BTN_0,
			PLS_SHADE_BTN_1,
			PLS_MAX_BTN_0,
			PLS_MAX_BTN_1,

			PLS_SCROLL_0,
			PLS_SCROLL_1,
			PLS_WS_LE_0,
			PLS_WS_LE_1 = PLS_WS_LE_0,
			PLS_WS_RE_0,
			PLS_WS_RE_1,
			PLS_WS_MID_0,
			PLS_WS_MID_1 = PLS_WS_MID_0,
			PLS_LCBAR,
			PLS_RCBAR,
			
			PLS_MSC_BTN_0,
			PLS_MSC_BTN_1,

			PLS_ADD,
			PLS_ADD_DEC,
			PLS_ADD_URL_0,
			PLS_ADD_URL_1,
			PLS_ADD_DIR_0,
			PLS_ADD_DIR_1,
			PLS_ADD_FIL_0,
			PLS_ADD_FIL_1,

			PLS_DEL,
			PLS_DEL_DEC,
			PLS_DEL_ALL_0,
			PLS_DEL_ALL_1,
			PLS_DEL_CRP_0,
			PLS_DEL_CRP_1,
			PLS_DEL_FIL_0,
			PLS_DEL_FIL_1,

			PLS_SEL,
			PLS_SEL_DEC,
			PLS_SEL_INV_0,
			PLS_SEL_INV_1,
			PLS_SEL_NIL_0,
			PLS_SEL_NIL_1,
			PLS_SEL_ALL_0,
			PLS_SEL_ALL_1,

			PLS_MSC,
			PLS_MSC_DEC,
			PLS_MSC_SRT_0,
			PLS_MSC_SRT_1,
			PLS_MSC_INF_0,
			PLS_MSC_INF_1,
			PLS_MSC_OPT_0,
			PLS_MSC_OPT_1,

			PLS_LST,
			PLS_LST_DEC,
			PLS_LST_NEW_0,
			PLS_LST_NEW_1,
			PLS_LST_SAV_0,
			PLS_LST_SAV_1,
			PLS_LST_OPN_0,
			PLS_LST_OPN_1
		};
	private:
		Skin() {};
		static Skin *singleton;

		QPixmap *getPixmap (const QString& file);
		void BuildLetterMap (void);
		void BuildButtons (void);
		void BuildToggleButtons (void);
		void BuildTitleBar (void);
		void BuildSliders (void);
		void BuildOther (void);
		void BuildNumbers (void);
		void BuildPlaylist (void);
		void ParsePLEdit (void);
		void BuildEqualizer (void);


		QString m_skinname;
		QString m_path;

		QMap<uint, QPixmap> m_items;
		QMap<uint, QPixmap> m_letterMap;
		QMap<uint, QPixmap> m_volume_bar;
		QMap<uint, QPixmap> m_balance;
		QMap<uint, QPixmap> m_numbers;
		QMap<uint, QPixmap> m_playlist;
		QMap<uint, QPixmap> m_equalizer;

		QMap<QByteArray, QByteArray> m_pledit_txt;
		QList<QPixmap *> m_buttons;

		bool m_volbtn;
		bool m_balbtn;

	signals:
		void skinChanged (Skin *skin);
};

#endif