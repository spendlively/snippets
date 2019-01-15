/* SPDX-License-Identifier: GPL-2.0 */
/******************************************************************************
 *
 * Copyright(c) 2007 - 2016  Realtek Corporation.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/

#ifndef __PHYDMPREDEFINE_H__
#define __PHYDMPREDEFINE_H__

/* 1 ============================================================
 * 1  Definition
 * 1 ============================================================
 */

#define PHYDM_CODE_BASE "PHYDM_TRUNK"
#define PHYDM_RELEASE_DATE "00000000"

/* Max path of IC */
#define MAX_PATH_NUM_8188E 1
#define MAX_PATH_NUM_8192E 2
#define MAX_PATH_NUM_8723B 1
#define MAX_PATH_NUM_8812A 2
#define MAX_PATH_NUM_8821A 1
#define MAX_PATH_NUM_8814A 4
#define MAX_PATH_NUM_8822B 2
#define MAX_PATH_NUM_8821B 2
#define MAX_PATH_NUM_8703B 1
#define MAX_PATH_NUM_8188F 1
#define MAX_PATH_NUM_8723D 1
#define MAX_PATH_NUM_8197F 2
#define MAX_PATH_NUM_8821C 1
/* JJ ADD 20161014 */
#define MAX_PATH_NUM_8710B 1

/* Max RF path */
#define ODM_RF_PATH_MAX 2
#define ODM_RF_PATH_MAX_JAGUAR 4

/*Bit define path*/
#define PHYDM_A BIT(0)
#define PHYDM_B BIT(1)
#define PHYDM_C BIT(2)
#define PHYDM_D BIT(3)
#define PHYDM_AB (BIT(0) | BIT(1))
#define PHYDM_AC (BIT(0) | BIT(2))
#define PHYDM_AD (BIT(0) | BIT(3))
#define PHYDM_BC (BIT(1) | BIT(2))
#define PHYDM_BD (BIT(1) | BIT(3))
#define PHYDM_CD (BIT(2) | BIT(3))
#define PHYDM_ABC (BIT(0) | BIT(1) | BIT(2))
#define PHYDM_ABD (BIT(0) | BIT(1) | BIT(3))
#define PHYDM_ACD (BIT(0) | BIT(2) | BIT(3))
#define PHYDM_BCD (BIT(1) | BIT(2) | BIT(3))
#define PHYDM_ABCD (BIT(0) | BIT(1) | BIT(2) | BIT(3))

/* number of entry */
/* defined in wifi.h (32+1) */
#define ODM_ASSOCIATE_ENTRY_NUM ASSOCIATE_ENTRY_NUM

#define RX_SMOOTH_FACTOR 20

/* -----MGN rate--------------------------------- */

enum ODM_MGN_RATE {
	ODM_MGN_1M = 0x02,
	ODM_MGN_2M = 0x04,
	ODM_MGN_5_5M = 0x0B,
	ODM_MGN_6M = 0x0C,
	ODM_MGN_9M = 0x12,
	ODM_MGN_11M = 0x16,
	ODM_MGN_12M = 0x18,
	ODM_MGN_18M = 0x24,
	ODM_MGN_24M = 0x30,
	ODM_MGN_36M = 0x48,
	ODM_MGN_48M = 0x60,
	ODM_MGN_54M = 0x6C,
	ODM_MGN_MCS32 = 0x7F,
	ODM_MGN_MCS0,
	ODM_MGN_MCS1,
	ODM_MGN_MCS2,
	ODM_MGN_MCS3,
	ODM_MGN_MCS4,
	ODM_MGN_MCS5,
	ODM_MGN_MCS6,
	ODM_MGN_MCS7,
	ODM_MGN_MCS8,
	ODM_MGN_MCS9,
	ODM_MGN_MCS10,
	ODM_MGN_MCS11,
	ODM_MGN_MCS12,
	ODM_MGN_MCS13,
	ODM_MGN_MCS14,
	ODM_MGN_MCS15,
	ODM_MGN_MCS16,
	ODM_MGN_MCS17,
	ODM_MGN_MCS18,
	ODM_MGN_MCS19,
	ODM_MGN_MCS20,
	ODM_MGN_MCS21,
	ODM_MGN_MCS22,
	ODM_MGN_MCS23,
	ODM_MGN_MCS24,
	ODM_MGN_MCS25,
	ODM_MGN_MCS26,
	ODM_MGN_MCS27,
	ODM_MGN_MCS28,
	ODM_MGN_MCS29,
	ODM_MGN_MCS30,
	ODM_MGN_MCS31,
	ODM_MGN_VHT1SS_MCS0,
	ODM_MGN_VHT1SS_MCS1,
	ODM_MGN_VHT1SS_MCS2,
	ODM_MGN_VHT1SS_MCS3,
	ODM_MGN_VHT1SS_MCS4,
	ODM_MGN_VHT1SS_MCS5,
	ODM_MGN_VHT1SS_MCS6,
	ODM_MGN_VHT1SS_MCS7,
	ODM_MGN_VHT1SS_MCS8,
	ODM_MGN_VHT1SS_MCS9,
	ODM_MGN_VHT2SS_MCS0,
	ODM_MGN_VHT2SS_MCS1,
	ODM_MGN_VHT2SS_MCS2,
	ODM_MGN_VHT2SS_MCS3,
	ODM_MGN_VHT2SS_MCS4,
	ODM_MGN_VHT2SS_MCS5,
	ODM_MGN_VHT2SS_MCS6,
	ODM_MGN_VHT2SS_MCS7,
	ODM_MGN_VHT2SS_MCS8,
	ODM_MGN_VHT2SS_MCS9,
	ODM_MGN_VHT3SS_MCS0,
	ODM_MGN_VHT3SS_MCS1,
	ODM_MGN_VHT3SS_MCS2,
	ODM_MGN_VHT3SS_MCS3,
	ODM_MGN_VHT3SS_MCS4,
	ODM_MGN_VHT3SS_MCS5,
	ODM_MGN_VHT3SS_MCS6,
	ODM_MGN_VHT3SS_MCS7,
	ODM_MGN_VHT3SS_MCS8,
	ODM_MGN_VHT3SS_MCS9,
	ODM_MGN_VHT4SS_MCS0,
	ODM_MGN_VHT4SS_MCS1,
	ODM_MGN_VHT4SS_MCS2,
	ODM_MGN_VHT4SS_MCS3,
	ODM_MGN_VHT4SS_MCS4,
	ODM_MGN_VHT4SS_MCS5,
	ODM_MGN_VHT4SS_MCS6,
	ODM_MGN_VHT4SS_MCS7,
	ODM_MGN_VHT4SS_MCS8,
	ODM_MGN_VHT4SS_MCS9,
	ODM_MGN_UNKNOWN
};

#define ODM_MGN_MCS0_SG 0xc0
#define ODM_MGN_MCS1_SG 0xc1
#define ODM_MGN_MCS2_SG 0xc2
#define ODM_MGN_MCS3_SG 0xc3
#define ODM_MGN_MCS4_SG 0xc4
#define ODM_MGN_MCS5_SG 0xc5
#define ODM_MGN_MCS6_SG 0xc6
#define ODM_MGN_MCS7_SG 0xc7
#define ODM_MGN_MCS8_SG 0xc8
#define ODM_MGN_MCS9_SG 0xc9
#define ODM_MGN_MCS10_SG 0xca
#define ODM_MGN_MCS11_SG 0xcb
#define ODM_MGN_MCS12_SG 0xcc
#define ODM_MGN_MCS13_SG 0xcd
#define ODM_MGN_MCS14_SG 0xce
#define ODM_MGN_MCS15_SG 0xcf

/* -----DESC rate--------------------------------- */

#define ODM_RATEMCS15_SG 0x1c
#define ODM_RATEMCS32 0x20

/* CCK Rates, TxHT = 0 */
#define ODM_RATE1M 0x00
#define ODM_RATE2M 0x01
#define ODM_RATE5_5M 0x02
#define ODM_RATE11M 0x03
/* OFDM Rates, TxHT = 0 */
#define ODM_RATE6M 0x04
#define ODM_RATE9M 0x05
#define ODM_RATE12M 0x06
#define ODM_RATE18M 0x07
#define ODM_RATE24M 0x08
#define ODM_RATE36M 0x09
#define ODM_RATE48M 0x0A
#define ODM_RATE54M 0x0B
/* MCS Rates, TxHT = 1 */
#define ODM_RATEMCS0 0x0C
#define ODM_RATEMCS1 0x0D
#define ODM_RATEMCS2 0x0E
#define ODM_RATEMCS3 0x0F
#define ODM_RATEMCS4 0x10
#define ODM_RATEMCS5 0x11
#define ODM_RATEMCS6 0x12
#define ODM_RATEMCS7 0x13
#define ODM_RATEMCS8 0x14
#define ODM_RATEMCS9 0x15
#define ODM_RATEMCS10 0x16
#define ODM_RATEMCS11 0x17
#define ODM_RATEMCS12 0x18
#define ODM_RATEMCS13 0x19
#define ODM_RATEMCS14 0x1A
#define ODM_RATEMCS15 0x1B
#define ODM_RATEMCS16 0x1C
#define ODM_RATEMCS17 0x1D
#define ODM_RATEMCS18 0x1E
#define ODM_RATEMCS19 0x1F
#define ODM_RATEMCS20 0x20
#define ODM_RATEMCS21 0x21
#define ODM_RATEMCS22 0x22
#define ODM_RATEMCS23 0x23
#define ODM_RATEMCS24 0x24
#define ODM_RATEMCS25 0x25
#define ODM_RATEMCS26 0x26
#define ODM_RATEMCS27 0x27
#define ODM_RATEMCS28 0x28
#define ODM_RATEMCS29 0x29
#define ODM_RATEMCS30 0x2A
#define ODM_RATEMCS31 0x2B
#define ODM_RATEVHTSS1MCS0 0x2C
#define ODM_RATEVHTSS1MCS1 0x2D
#define ODM_RATEVHTSS1MCS2 0x2E
#define ODM_RATEVHTSS1MCS3 0x2F
#define ODM_RATEVHTSS1MCS4 0x30
#define ODM_RATEVHTSS1MCS5 0x31
#define ODM_RATEVHTSS1MCS6 0x32
#define ODM_RATEVHTSS1MCS7 0x33
#define ODM_RATEVHTSS1MCS8 0x34
#define ODM_RATEVHTSS1MCS9 0x35
#define ODM_RATEVHTSS2MCS0 0x36
#define ODM_RATEVHTSS2MCS1 0x37
#define ODM_RATEVHTSS2MCS2 0x38
#define ODM_RATEVHTSS2MCS3 0x39
#define ODM_RATEVHTSS2MCS4 0x3A
#define ODM_RATEVHTSS2MCS5 0x3B
#define ODM_RATEVHTSS2MCS6 0x3C
#define ODM_RATEVHTSS2MCS7 0x3D
#define ODM_RATEVHTSS2MCS8 0x3E
#define ODM_RATEVHTSS2MCS9 0x3F
#define ODM_RATEVHTSS3MCS0 0x40
#define ODM_RATEVHTSS3MCS1 0x41
#define ODM_RATEVHTSS3MCS2 0x42
#define ODM_RATEVHTSS3MCS3 0x43
#define ODM_RATEVHTSS3MCS4 0x44
#define ODM_RATEVHTSS3MCS5 0x45
#define ODM_RATEVHTSS3MCS6 0x46
#define ODM_RATEVHTSS3MCS7 0x47
#define ODM_RATEVHTSS3MCS8 0x48
#define ODM_RATEVHTSS3MCS9 0x49
#define ODM_RATEVHTSS4MCS0 0x4A
#define ODM_RATEVHTSS4MCS1 0x4B
#define ODM_RATEVHTSS4MCS2 0x4C
#define ODM_RATEVHTSS4MCS3 0x4D
#define ODM_RATEVHTSS4MCS4 0x4E
#define ODM_RATEVHTSS4MCS5 0x4F
#define ODM_RATEVHTSS4MCS6 0x50
#define ODM_RATEVHTSS4MCS7 0x51
#define ODM_RATEVHTSS4MCS8 0x52
#define ODM_RATEVHTSS4MCS9 0x53

#define ODM_NUM_RATE_IDX (ODM_RATEVHTSS4MCS9 + 1)

/* 1 ============================================================
 * 1  enumeration
 * 1 ============================================================
 */

/*	ODM_CMNINFO_INTERFACE */
enum odm_interface {
	ODM_ITRF_PCIE = 0x1,
	ODM_ITRF_USB = 0x2,
	ODM_ITRF_SDIO = 0x4,
	ODM_ITRF_ALL = 0x7,
};

/* ODM_CMNINFO_IC_TYPE */
enum odm_ic_type {
	ODM_RTL8188E = BIT(0),
	ODM_RTL8812 = BIT(1),
	ODM_RTL8821 = BIT(2),
	ODM_RTL8192E = BIT(3),
	ODM_RTL8723B = BIT(4),
	ODM_RTL8814A = BIT(5),
	ODM_RTL8881A = BIT(6),
	ODM_RTL8822B = BIT(7),
	ODM_RTL8703B = BIT(8),
	ODM_RTL8195A = BIT(9),
	ODM_RTL8188F = BIT(10),
	ODM_RTL8723D = BIT(11),
	ODM_RTL8197F = BIT(12),
	ODM_RTL8821C = BIT(13),
	ODM_RTL8814B = BIT(14),
	ODM_RTL8198F = BIT(15),
	/* JJ ADD 20161014 */
	ODM_RTL8710B = BIT(16),
};

/* JJ ADD 20161014 */
#define ODM_IC_1SS                                                             \
	(ODM_RTL8188E | ODM_RTL8188F | ODM_RTL8723B | ODM_RTL8703B |           \
	 ODM_RTL8723D | ODM_RTL8881A | ODM_RTL8821 | ODM_RTL8821C |            \
	 ODM_RTL8195A | ODM_RTL8710B)
#define ODM_IC_2SS (ODM_RTL8192E | ODM_RTL8197F | ODM_RTL8812 | ODM_RTL8822B)
#define ODM_IC_3SS (ODM_RTL8814A)
#define ODM_IC_4SS (ODM_RTL8814B | ODM_RTL8198F)

/* JJ ADD 20161014 */
#define ODM_IC_11N_SERIES                                                      \
	(ODM_RTL8188E | ODM_RTL8192E | ODM_RTL8723B | ODM_RTL8703B |           \
	 ODM_RTL8188F | ODM_RTL8723D | ODM_RTL8197F | ODM_RTL8710B)
#define ODM_IC_11AC_SERIES                                                     \
	(ODM_RTL8812 | ODM_RTL8821 | ODM_RTL8814A | ODM_RTL8881A |             \
	 ODM_RTL8822B | ODM_RTL8821C)
#define ODM_IC_11AC_1_SERIES (ODM_RTL8812 | ODM_RTL8821 | ODM_RTL8881A)
#define ODM_IC_11AC_2_SERIES (ODM_RTL8814A | ODM_RTL8822B | ODM_RTL8821C)
#define ODM_IC_TXBF_SUPPORT                                                    \
	(ODM_RTL8192E | ODM_RTL8812 | ODM_RTL8821 | ODM_RTL8814A |             \
	 ODM_RTL8881A | ODM_RTL8822B | ODM_RTL8197F | ODM_RTL8821C)
#define ODM_IC_11N_GAIN_IDX_EDCCA                                              \
	(ODM_RTL8195A | ODM_RTL8703B | ODM_RTL8188F | ODM_RTL8723D |           \
	 ODM_RTL8197F | ODM_RTL8710B)
#define ODM_IC_11AC_GAIN_IDX_EDCCA (ODM_RTL8814A | ODM_RTL8822B | ODM_RTL8821C)
#define ODM_IC_PHY_STATUE_NEW_TYPE                                             \
	(ODM_RTL8197F | ODM_RTL8822B | ODM_RTL8723D | ODM_RTL8821C |           \
	 ODM_RTL8710B)

#define PHYDM_IC_8051_SERIES                                                   \
	(ODM_RTL8881A | ODM_RTL8812 | ODM_RTL8821 | ODM_RTL8188E |             \
	 ODM_RTL8192E | ODM_RTL8723B | ODM_RTL8703B | ODM_RTL8188F)
#define PHYDM_IC_3081_SERIES                                                   \
	(ODM_RTL8814A | ODM_RTL8822B | ODM_RTL8197F | ODM_RTL8821C)

#define PHYDM_IC_SUPPORT_LA_MODE                                               \
	(ODM_RTL8814A | ODM_RTL8822B | ODM_RTL8197F | ODM_RTL8821C)

/* JJ ADD 20161014 */

/* ODM_CMNINFO_CUT_VER */
enum odm_cut_version {
	ODM_CUT_A = 0,
	ODM_CUT_B = 1,
	ODM_CUT_C = 2,
	ODM_CUT_D = 3,
	ODM_CUT_E = 4,
	ODM_CUT_F = 5,

	ODM_CUT_I = 8,
	ODM_CUT_J = 9,
	ODM_CUT_K = 10,
	ODM_CUT_TEST = 15,
};

/* ODM_CMNINFO_FAB_VER */
enum odm_fab {
	ODM_TSMC = 0,
	ODM_UMC = 1,
};

/* ODM_CMNINFO_RF_TYPE
 *
 * For example 1T2R (A+AB = BIT(0)|BIT(4)|BIT(5))
 */
enum odm_rf_path {
	ODM_RF_A = BIT(0),
	ODM_RF_B = BIT(1),
	ODM_RF_C = BIT(2),
	ODM_RF_D = BIT(3),
};

enum odm_rf_tx_num {
	ODM_1T = 1,
	ODM_2T = 2,
	ODM_3T = 3,
	ODM_4T = 4,
};

enum odm_rf_type {
	ODM_1T1R,
	ODM_1T2R,
	ODM_2T2R,
	ODM_2T2R_GREEN,
	ODM_2T3R,
	ODM_2T4R,
	ODM_3T3R,
	ODM_3T4R,
	ODM_4T4R,
	ODM_XTXR
};

enum odm_mac_phy_mode {
	ODM_SMSP = 0,
	ODM_DMSP = 1,
	ODM_DMDP = 2,
};

enum odm_bt_coexist {
	ODM_BT_BUSY = 1,
	ODM_BT_ON = 2,
	ODM_BT_OFF = 3,
	ODM_BT_NONE = 4,
};

/* ODM_CMNINFO_OP_MODE */
enum odm_operation_mode {
	ODM_NO_LINK = BIT(0),
	ODM_LINK = BIT(1),
	ODM_SCAN = BIT(2),
	ODM_POWERSAVE = BIT(3),
	ODM_AP_MODE = BIT(4),
	ODM_CLIENT_MODE = BIT(5),
	ODM_AD_HOC = BIT(6),
	ODM_WIFI_DIRECT = BIT(7),
	ODM_WIFI_DISPLAY = BIT(8),
};

/* ODM_CMNINFO_WM_MODE */
enum odm_wireless_mode {
	ODM_WM_UNKNOWN = 0x0,
	ODM_WM_B = BIT(0),
	ODM_WM_G = BIT(1),
	ODM_WM_A = BIT(2),
	ODM_WM_N24G = BIT(3),
	ODM_WM_N5G = BIT(4),
	ODM_WM_AUTO = BIT(5),
	ODM_WM_AC = BIT(6),
};

/* ODM_CMNINFO_BAND */
enum odm_band_type {
	ODM_BAND_2_4G = 0,
	ODM_BAND_5G,
	ODM_BAND_ON_BOTH,
	ODM_BANDMAX
};

/* ODM_CMNINFO_SEC_CHNL_OFFSET */
enum phydm_sec_chnl_offset {
	PHYDM_DONT_CARE = 0,
	PHYDM_BELOW = 1,
	PHYDM_ABOVE = 2
};

/* ODM_CMNINFO_SEC_MODE */
enum odm_security {
	ODM_SEC_OPEN = 0,
	ODM_SEC_WEP40 = 1,
	ODM_SEC_TKIP = 2,
	ODM_SEC_RESERVE = 3,
	ODM_SEC_AESCCMP = 4,
	ODM_SEC_WEP104 = 5,
	ODM_WEP_WPA_MIXED = 6, /* WEP + WPA */
	ODM_SEC_SMS4 = 7,
};

/* ODM_CMNINFO_BW */
enum odm_bw {
	ODM_BW20M = 0,
	ODM_BW40M = 1,
	ODM_BW80M = 2,
	ODM_BW160M = 3,
	ODM_BW5M = 4,
	ODM_BW10M = 5,
	ODM_BW_MAX = 6
};

/* ODM_CMNINFO_CHNL */

/* ODM_CMNINFO_BOARD_TYPE */
enum odm_board_type {
	ODM_BOARD_DEFAULT = 0, /* The DEFAULT case. */
	ODM_BOARD_MINICARD = BIT(0), /* 0 = non-mini card, 1= mini card. */
	ODM_BOARD_SLIM = BIT(1), /* 0 = non-slim card, 1 = slim card */
	ODM_BOARD_BT = BIT(2), /* 0 = without BT card, 1 = with BT */
	ODM_BOARD_EXT_PA =
		BIT(3), /* 0 = no 2G ext-PA, 1 = existing 2G ext-PA */
	ODM_BOARD_EXT_LNA =
		BIT(4), /* 0 = no 2G ext-LNA, 1 = existing 2G ext-LNA */
	ODM_BOARD_EXT_TRSW =
		BIT(5), /* 0 = no ext-TRSW, 1 = existing ext-TRSW */
	ODM_BOARD_EXT_PA_5G =
		BIT(6), /* 0 = no 5G ext-PA, 1 = existing 5G ext-PA */
	ODM_BOARD_EXT_LNA_5G =
		BIT(7), /* 0 = no 5G ext-LNA, 1 = existing 5G ext-LNA */
};

enum odm_package_type {
	ODM_PACKAGE_DEFAULT = 0,
	ODM_PACKAGE_QFN68 = BIT(0),
	ODM_PACKAGE_TFBGA90 = BIT(1),
	ODM_PACKAGE_TFBGA79 = BIT(2),
};

enum odm_type_gpa {
	TYPE_GPA0 = 0x0000,
	TYPE_GPA1 = 0x0055,
	TYPE_GPA2 = 0x00AA,
	TYPE_GPA3 = 0x00FF,
	TYPE_GPA4 = 0x5500,
	TYPE_GPA5 = 0x5555,
	TYPE_GPA6 = 0x55AA,
	TYPE_GPA7 = 0x55FF,
	TYPE_GPA8 = 0xAA00,
	TYPE_GPA9 = 0xAA55,
	TYPE_GPA10 = 0xAAAA,
	TYPE_GPA11 = 0xAAFF,
	TYPE_GPA12 = 0xFF00,
	TYPE_GPA13 = 0xFF55,
	TYPE_GPA14 = 0xFFAA,
	TYPE_GPA15 = 0xFFFF,
};

enum odm_type_apa {
	TYPE_APA0 = 0x0000,
	TYPE_APA1 = 0x0055,
	TYPE_APA2 = 0x00AA,
	TYPE_APA3 = 0x00FF,
	TYPE_APA4 = 0x5500,
	TYPE_APA5 = 0x5555,
	TYPE_APA6 = 0x55AA,
	TYPE_APA7 = 0x55FF,
	TYPE_APA8 = 0xAA00,
	TYPE_APA9 = 0xAA55,
	TYPE_APA10 = 0xAAAA,
	TYPE_APA11 = 0xAAFF,
	TYPE_APA12 = 0xFF00,
	TYPE_APA13 = 0xFF55,
	TYPE_APA14 = 0xFFAA,
	TYPE_APA15 = 0xFFFF,
};

enum odm_type_glna {
	TYPE_GLNA0 = 0x0000,
	TYPE_GLNA1 = 0x0055,
	TYPE_GLNA2 = 0x00AA,
	TYPE_GLNA3 = 0x00FF,
	TYPE_GLNA4 = 0x5500,
	TYPE_GLNA5 = 0x5555,
	TYPE_GLNA6 = 0x55AA,
	TYPE_GLNA7 = 0x55FF,
	TYPE_GLNA8 = 0xAA00,
	TYPE_GLNA9 = 0xAA55,
	TYPE_GLNA10 = 0xAAAA,
	TYPE_GLNA11 = 0xAAFF,
	TYPE_GLNA12 = 0xFF00,
	TYPE_GLNA13 = 0xFF55,
	TYPE_GLNA14 = 0xFFAA,
	TYPE_GLNA15 = 0xFFFF,
};

enum odm_type_alna {
	TYPE_ALNA0 = 0x0000,
	TYPE_ALNA1 = 0x0055,
	TYPE_ALNA2 = 0x00AA,
	TYPE_ALNA3 = 0x00FF,
	TYPE_ALNA4 = 0x5500,
	TYPE_ALNA5 = 0x5555,
	TYPE_ALNA6 = 0x55AA,
	TYPE_ALNA7 = 0x55FF,
	TYPE_ALNA8 = 0xAA00,
	TYPE_ALNA9 = 0xAA55,
	TYPE_ALNA10 = 0xAAAA,
	TYPE_ALNA11 = 0xAAFF,
	TYPE_ALNA12 = 0xFF00,
	TYPE_ALNA13 = 0xFF55,
	TYPE_ALNA14 = 0xFFAA,
	TYPE_ALNA15 = 0xFFFF,
};

enum odm_rf_radio_path {
	ODM_RF_PATH_A = 0, /* Radio path A */
	ODM_RF_PATH_B = 1, /* Radio path B */
	ODM_RF_PATH_C = 2, /* Radio path C */
	ODM_RF_PATH_D = 3, /* Radio path D */
	ODM_RF_PATH_AB,
	ODM_RF_PATH_AC,
	ODM_RF_PATH_AD,
	ODM_RF_PATH_BC,
	ODM_RF_PATH_BD,
	ODM_RF_PATH_CD,
	ODM_RF_PATH_ABC,
	ODM_RF_PATH_ACD,
	ODM_RF_PATH_BCD,
	ODM_RF_PATH_ABCD,
	/* ODM_RF_PATH_MAX,    */ /* Max RF number 90 support */
};

enum odm_parameter_init {
	ODM_PRE_SETTING = 0,
	ODM_POST_SETTING = 1,
};

#endif
