#ifndef _RMS_ANALYZE_PUB_
#define _RMS_ANALYZE_PUB_

#include <QtGui>
#include <string>

using namespace std;

#define  INVALID_0  0	/**<   Invalid data type                                                       */
/* Process information in monitor direction (station-specific parameter)                               */
#define  M_SP_NA_1  1	/**<   Single-point information                                                */
#define  M_SP_TA_1  2	/**<   Single-point information with time tag                                  */
#define  M_DP_NA_1  3	/**<   Double-point information                                                */
#define  M_DP_TA_1  4	/**<   Double-point information with time tag                                  */
#define  M_ST_NA_1  5	/**<   Step position information                                               */
#define  M_ST_TA_1  6	/**<   Step position information with time tag                                 */
#define  M_BO_NA_1  7	/**<   Bitstring of 32 bit                                                     */
#define  M_BO_TA_1  8	/**<   Bitstring of 32 bit with time tag                                       */
#define  M_ME_NA_1  9	/**<   Measured value, normalised value                                        */
#define  M_ME_TA_1  10	/**<   Measured value, normalised value with time tag                          */
#define  M_ME_NB_1  11	/**<   Measured value, scaled value                                            */
#define  M_ME_TB_1  12	/**<   Measured value, scaled value with time tag                              */
#define  M_ME_NC_1  13	/**<   Measured value, short floating point value                              */
#define  M_ME_TC_1  14	/**<   Measured value, short floating point value with time tag                */
#define  M_IT_NA_1  15	/**<   Integrated totals                                                       */
#define  M_IT_TA_1  16	/**<   Integrated totals with time tag                                         */
#define  M_EP_TA_1  17	/**<   Event of protection equipment with time tag                             */
#define  M_EP_TB_1  18	/**<   Packed start events of protection equipment with time tag               */
#define  M_EP_TC_1  19	/**<   Packed output circuit information of protection equipment with time tag */
#define  M_PS_NA_1  20	/**<   Packed single point information with time tag                           */
#define  M_ME_ND_1  21	/**<   Measured value, normalised value without quality descriptor             */
#define  M_SP_TB_1  30	/**<   Single point information with time tag CP56Time2a                       */
#define  M_DP_TB_1  31	/**<   Double point information with time tag CP56Time2a                       */
#define  M_ST_TB_1  32	/**<   Step position information with time tag CP56Time2a                      */
#define  M_BO_TB_1  33	/**<   Bitstring of 32 bit with time tag CP56Time2a                            */
#define  M_ME_TD_1  34	/**<   Measured value, normalised value with time tag CP56Time2a               */
#define  M_ME_TE_1  35	/**<   Measured value, scaled value with time tag CP56Time2a                   */
#define  M_ME_TF_1  36	/**<   Measured value, short floating point value with time tag CP56Time2a     */ 
#define  M_IT_TB_1  37	/**<   Integrated totals with time tag CP56Time2a                              */
#define  M_EP_TD_1  38	/**<   Event of protection equipment with time tag CP56Time2a                  */
#define  M_EP_TE_1  39	/**<   Packed start events of protection equipment with time tag CP56Time2a    */
#define  M_EP_TF_1  40	/**<   Packed tripping events of protection equipment with time tag CP56Time2a */
/* Process information in control direction (station-specific parameter)                               */
#define  C_SC_NA_1  45	/**<   Single command                                                          */
#define  C_DC_NA_1  46	/**<   Double command                                                          */
#define  C_RC_NA_1  47	/**<   Regulating step command                                                 */
#define  C_SE_NA_1  48	/**<   Set point command, normalised value                                     */
#define  C_SE_NB_1  49	/**<   Set point command, scaled value                                         */
#define  C_SE_NC_1  50	/**<   Set point command, short floating point value                           */
#define  C_BO_NA_1  51	/**<   Bitstring of 32 bit                                                     */
#define  C_SC_TA_1  58	/**<   Single command with time tag CP56Time2a                                 */
#define  C_DC_TA_1  59	/**<   Double command with time tag CP56Time2a                                 */
#define  C_RC_TA_1  60	/**<   Regulating step command with time tag CP56Time2a                        */
#define  C_SE_TA_1  61	/**<   Set point command, normalised value with time tag CP56Time2a            */
#define  C_SE_TB_1  62	/**<   Set point command, scaled value with time tag CP56Time2a                */
#define  C_SE_TC_1  63	/**<   Set point command, short floating point value with time tag CP56Time2a  */
#define  C_BO_TA_1  64	/**<   Bitstring of 32 bit with time tag CP56Time2a                            */
/* System information in monitor direction (station-specific parameter)                                */
#define  M_EI_NA_1  70	/**<   End of initialisation                                                   */
/*   System information in control direction (station-specific parameter)                              */
#define  C_IC_NA_1  100	/**<   Interrogation command    ��ֵ�ٻ�                                       */
#define  C_CI_NA_1  101	/**<   Counter interrogation command                                           */
#define  C_RD_NA_1  102	/**<   Read command                                                            */
#define  C_CS_NA_1  103	/**<   Clock synchronisation command                                           */
#define  C_TS_NA_1  104	/**<   Test command                                                            */
#define  C_RP_NA_1  105	/**<   Reset process command                                                   */
#define  C_CD_NA_1  106	/**<   Delay acquisition command                                               */
#define  C_TS_TA_1  107	/**<   Test command with time tag CP56Time2a                                   */
/* Parameter in control direction (station-specific parameter)                                         */
#define  P_ME_NA_1  110	/**<   Parameter of measured value, normalised value                           */
#define  P_ME_NB_1  111	/**<   Parameter of measured value, scaled value                               */
#define  P_ME_NC_1  112	/**<   Parameter of measured value, short floating point value                 */
#define  P_AC_NA_1  113	/**<   Active parameter                                                        */
/* File Transfer (station-specific parameter)                                                          */
#define  F_FR_NA_1  120	/**<   File ready                                                              */
#define  F_SR_NA_1  121	/**<   Section ready                                                           */
#define  F_SC_NA_1  122	/**<   Call directory, select file, call file, call section                    */
#define  F_LS_NA_1  123	/**<   Last section, last segment                                              */
#define  F_AF_NA_1  124	/**<   Ack file, ack section                                                   */
#define  F_SG_NA_1  125	/**<   Segment                                                                 */
#define  F_DR_TA_1  126	/**<   Directory                                                               */

#define	ASDU0_DONOTHING	         0	    /**< (00)����                              */

/** IEC60870-5-103��Լ�еı��������� ( ��վ ==> IED )                              */
#define	ASDU6_C_SYN_TA_3		 6      /**< (06)ʱ��ͬ��                          */ 
#define	ASDU7_C_IGI_NA_3		 7      /**< (07)�ܲ�ѯ                            */ 
#define	ASDU10_C_GD_NA_3		 10	    /**< (0A)ͨ�÷�������                      */ 
#define ASDU13_C_LB_NA_3		 13		/**< (0D)�ٻ�¼���ļ�                      */
#define ASDU15_C_LBL_NA_3		 15		/**< (0F)�ٻ�¼���ļ��б�                  */
#define ASDU17_C_HIS_NA_3		 17		/**< (11)�ٻ�װ�ù�����ʷ��Ϣ              */
#define	ASDU20_C_GRC_NA_3		 20	    /**< (14)һ������                          */
#define	ASDU21_C_GC_NA_3		 21	    /**< (15)ͨ�÷�������                      */
#define	ASDU24_C_ODT_NA_3		 24	    /**< (18)�Ŷ����ݴ�������                  */
#define	ASDU25_C_ADT_NA_3   	 25	    /**< (19)�Ŷ����ݴ������                  */
#define	ASDU101_C_FLL_NA_3   	 101    /**< (65)�ٻ�һ���ļ��б�                  */
#define	ASDU103_C_FL_NA_3   	 103    /**< (67)�ٻ�һ���ļ�                      */
#define	ASDU105_C_DFI_NA_3   	 105    /**< (69)�´�һ���ļ�����Ϣ                */
#define	ASDU107_C_DFD_NA_3   	 107    /**< (6B)�´�һ���ļ�������                */

/** IEC60870-5-103��Լ�еı��������� ( IED ==> ��վ )                              */
#define	ASDU1_M_TM_TA_3			 1	    /**< (01)��ʱ��ı���                      */
#define	ASDU2_M_TMR_TA_3		 2	    /**< (02)�������ʱ��Ĵ�ʱ��ı���        */ 
#define	ASDU3_M_MEI_NA_3		 3	    /**< (03)����ֵI                           */ 
#define	ASDU4_M_TME_TA_3	     4	    /**< (04)�������ʱ��Ĵ�ʱ��ı���ֵ      */ 
#define	ASDU5_M_IRC_NA_3 		 5	    /**< (05)��ʶ                              */
#define	ASDU5_M_IRF_NA_3 		 5	    /**< (05)��ʶ                              */
#define	ASDU5_M_IRS_NA_3 		 5	    /**< (05)��ʶ                              */
#define	ASDU6_M_SYN_TA_3    	 6	    /**< (06)ʱ��ͬ��                          */ 
#define	ASDU8_M_TGI_NA_3		 8	    /**< (08)�ܲ�ѯ��ֹ                        */ 
#define	ASDU9_M_MEII_NA_3		 9	    /**< (09)����ֵII                          */ 
#define	ASDU10_M_GD_NA_3    	 10	    /**< (0A)ͨ�÷�������                      */
#define	ASDU10_M_GD_TA_3    	 10	    /**< (0A)ͨ�÷�������                      */
#define	ASDU11_M_GI_NA_3  		 11	    /**< (0B)ͨ�÷����ʶ                      */
#define	ASDU11_M_GI_TA_3  		 11	    /**< (0B)ͨ�÷����ʶ                      */
#define	ASDU12_M_LBS_NA_3  		 12	    /**< (0C)��Ҫ¼������                      */
#define ASDU14_M_LB_NA_3		 14		/**< (0E)����¼���ļ�                      */
#define ASDU16_M_LBL_NA_3		 16		/**< (10)����¼���ļ��б�                  */
#define ASDU18_M_HIS_NA_3		 18		/**< (12)����װ�ù�����ʷ��Ϣ              */
#define	ASDU23_M_LDR_TA_3		 23	    /**< (17)����¼���Ŷ���	                   */ 
#define	ASDU26_M_PTD_TA_3		 26	    /**< (1A)�Ŷ����ݴ���׼������	           */ 
#define	ASDU27_M_RTC_NA_3	     27	    /**< (1B)����¼��ͨ������׼������	       */ 
#define	ASDU28_M_RTT_NA_3	     28	    /**< (1C)����־��״̬��λ����׼������      */
#define	ASDU29_M_TOT_TA_3		 29	    /**< (1D)���ʹ���־��״̬��λ	           */
#define	ASDU30_M_TDN_NA_3		 30	    /**< (1E)�����Ŷ�ֵ	                       */
#define	ASDU31_M_EOT_NA_3		 31	    /**< (1F)���ͽ���	                       */
#define	ASDU42_M_TGI_NA_3		 42	    /**< (2A)���ٻ�Ӧ��,����˫����Ϣ           */
#define	ASDU102_M_FLL_NA_3		 102    /**< (66)����һ���ļ��б�                  */
#define	ASDU104_M_FL_NA_3		 104    /**< (68)����һ���ļ�                      */
#define	ASDU106_M_DFI_NA_3		 106    /**< (6A)�´��ļ���Ϣ��ȷ��                */
#define	ASDU108_M_DFD_NA_3		 108    /**< (6C)�´��ļ����ݵ�ȷ��                */

/** IEC60870-5-103����ԭ��(COT)( ��վ ==> IED )                                    */
#define COT_C_SYN_8              8	    /**< (08)ʱ��ͬ��                          */ 
#define COT_C_GI_START_9         9	    /**< (09)�ܲ�ѯ����                        */ 
#define COT_C_GRC_20             20     /**< (14)һ������                          */ 
#define COT_C_DIST_DATA_31       31     /**< (1F)�Ŷ����ݵĴ���                    */
#define COT_C_G_WRITE_40         40     /**< (28)ͨ�÷���д����                    */
#define COT_C_G_READ_42          42     /**< (2A)ͨ�÷��������                    */

/** IEC60870-5-103����ԭ��(COT) ( IED ==> ��վ )                                   */
#define COT_M_NOTUSED_0           0     /**< (00)not used                          */
#define COT_M_SPONT_1             1	    /**< (01)�Է� spontaneous                  */
#define COT_M_CYC_2               2	    /**< (02)ѭ�� periodic, cyclic             */
#define COT_M_RESET_FCB_3         3	    /**< (03)��λ֡����λ                      */
#define COT_M_RESET_CU_4          4	    /**< (04)��λͨ�ŵ�Ԫ                      */
#define COT_M_RESET_5             5	    /**< (05)����/��������                     */
#define COT_M_TEST_7              7	    /**< (07)����ģʽ                          */
#define COT_M_SYN_8               8	    /**< (08)ʱ��ͬ��                          */
#define COT_M_GI_9                9	    /**< (09)�ܲ�ѯ                            */
#define COT_M_GI_END_10           10    /**< (0A)�ܲ�ѯֹͣ                        */
#define COT_M_LOCAL_11            11    /**< (0B)���ز���                          */
#define COT_M_REMOTE_12           12    /**< (0C)Զ������                          */
#define COT_M_COMMAND_ACK_20      20    /**< (14)����Ŀ϶��Ͽ�                    */
#define COT_M_COMMAND_NCK_21      21    /**< (15)����ķ��Ͽ�                    */
#define COT_M_DIST_DATA_31        31    /**< (1F)�Ŷ����ݵĴ���                    */
#define COT_M_G_WRITE_ACK_40      40    /**< (28)ͨ�÷���д����Ŀ϶��Ͽ�          */ 
#define COT_M_G_WRITE_NCK_41      41    /**< (29)ͨ�÷���д����ķ��Ͽ�          */
#define COT_M_G_READ_ACK_42       42    /**< (2A)��ͨ�÷����������Ч������Ӧ      */
#define COT_M_G_READ_NCK_43       43    /**< (2B)��ͨ�÷����������Ч������Ӧ      */
#define COT_M_G_WRITE_CONFIRM_44  44    /**< (2C)ͨ�÷���дȷ��                    */
                                                                          
/** IEC60870-5-103ר�з�Χ��������(FUN)                                            */
/** ... ... etc.                                                                   */

/** IEC60870-5-103���ݷ�Χ��������(FUN)                                            */
#define FUN_DPR_128               128	/**< (80)���뱣��                          */
#define FUN_OPR_160               160	/**< (A0)��������                          */
#define FUN_TDP_176               176	/**< (B0)��ѹ�������                    */
#define FUN_LDP_192               192	/**< (C0)��·�����                      */
#define FUN_GEN_254               254	/**< (FE)ͨ�÷��๦������                  */
#define FUN_GLB_255               255	/**< (FF)ȫ�ֹ�������                      */

/** IEC60870-5-103ר�з�Χ��Ϣ���(INF)                                            */
/** ... ... etc.                                                                   */

/** IEC60870-5-103���ݷ�Χ��Ϣ���(INF)( IED ==> ��վ )                            */
#define INF_M_GLB_ZERO            0	    /**< (00)�ܲ�ѯ����/ʱ��ͬ��               */
#define INF_M_RESET_FCB_02        2	    /**< (02)��λ֡������                      */
#define INF_M_RESET_CU_03         3	    /**< (03)��λͨ�ŵ�Ԫ                      */
#define INF_M_RESTART_04          4	    /**< (04)����/��������                     */
#define INF_M_POWERON_05          5	    /**< (05)��Դ����                          */
#define INF_M_READ_G_TITLE_240    240   /**< (F0)����ȫ�����������ı���          */
#define INF_M_READ_G_VALUE_241    241   /**< (F1)��һ�����ȫ����Ŀ��ֵ������      */
#define INF_M_READ_E_LIST_243     243   /**< (F3)��������Ŀ��Ŀ¼                  */
#define INF_M_READ_E_VALUE_244    244   /**< (F4)��������Ŀ��ֵ������              */
#define INF_M_GI_245              245   /**< (F5)ͨ�÷��������ܲ�ѯ��ֹ            */
#define INF_M_WRITE_CONFIRM_249   249   /**< (F9)��ȷ�ϵ�д��Ŀ                    */
#define INF_M_WRITE_EXECUTE_250   250   /**< (FA)��ִ�е�д��Ŀ                    */
#define INF_M_WRITE_TERM_251      251   /**< (FB)����ֹ��д��Ŀ                    */
                                                                              
/** IEC60870-5-103���ݷ�Χ��Ϣ���(INF)( ��վ ==> IED )                            */
#define INF_C_GLB_ZERO            0	    /**< (00)�ܲ�ѯ�����ٻ�������/ʱ��ͬ��     */
#define INF_C_RESET_CU_03         3	    /**< (03)��λͨ�ŵ�Ԫ                      */
#define INF_C_AUTO_CLOSING_16     16	/**< (10)�Զ��غ�բͶ��/�Ƴ�               */
#define INF_C_REMOTE_PT_17        17	/**< (11)Զ������Ͷ��/�Ƴ�                 */
#define INF_C_PT_18               18    /**< (12)����Ͷ��/�Ƴ�                     */
#define INF_C_LED_19              19	/**< (13)LED��λ                           */
#define INF_C_ACT1_23             23	/**< (17)��������1                         */
#define INF_C_ACT2_24             24	/**< (18)��������2                         */
#define INF_C_ACT3_25             25	/**< (19)��������3                         */
#define INF_C_ACT4_26             26	/**< (1A)��������4                         */
#define INF_C_READ_G_TITLE_240    240   /**< (F0)����ȫ�����������ı���          */
#define INF_C_READ_G_VALUE_241    241   /**< (F1)��һ�����ȫ����Ŀ��ֵ������      */
#define INF_C_READ_E_LIST_243     243   /**< (F3)��������Ŀ��Ŀ¼                  */
#define INF_C_READ_E_VALUE_244    244   /**< (F4)��������Ŀ��ֵ������              */
#define INF_C_GI_245              245   /**< (F5)��ͨ�÷������ݵ��ܲ�ѯ�����ٻ���  */
#define INF_C_WRITE_248           248   /**< (F8)д��Ŀ                            */
#define INF_C_WRITE_CONFIRM_249   249   /**< (F9)��ȷ�ϵ�д��Ŀ                    */
#define INF_C_WRITE_EXECUTE_250   250   /**< (FA)��ִ�е�д��Ŀ                    */
#define INF_C_WRITE_TERM_251      251   /**< (FB)д��Ŀ��ֹ                        */

/** IEC60870-5-103ͨ�÷�����������                                                 */
#define GDD_NONE                  0     /**< ������                                */ 
#define GDD_ASCII                 1     /**< OS8ASCII                              */ 
#define GDD_BSI                   2     /**< ����8λ��                             */ 
#define GDD_UI                    3     /**< �޷�������                            */ 
#define GDD_I                     4     /**< �з�������                            */ 
#define GDD_UF                    5     /**< �޷��Ÿ�����                          */ 
#define GDD_F                     6     /**< �з��Ÿ�����                          */ 
#define GDD_IEEE754SP             7     /**< R32.23IEEE��׼��754��ʵ��             */ 
#define GDD_IEEE754DP             8     /**< R64.53IEEE��׼��754ʵ��               */ 
#define GDD_DPI                   9     /**< ˫����Ϣ                              */ 
#define GDD_SPI                   10    /**< ������Ϣ                              */ 
#define GDD_DPI_TR                11    /**< ��˲��Ͳ���˫����Ϣ                */ 
#define GDD_MEQ                   12    /**< ��Ʒ�������ʵı���ֵ                  */ 
#define GDD_BINTIME               14    /**< ������ʱ��                            */ 
#define GDD_GIN                   15    /**< ͨ�÷����־���                      */ 
#define GDD_RET                   16    /**< ���ʱ��                              */ 
#define GDD_FUN_INF               17    /**< �������ͺ���Ϣ���                    */ 
#define GDD_TIMETAG               18    /**< ��ʱ��ı���                          */ 
#define GDD_RETTAG                19    /**< �����ʱ���ʱ�걨��                  */ 
#define GDD_ME_RETTAG             20    /**< �����ʱ���ʱ��ı���ֵ              */ 
#define GDD_EXT_FILENO            21    /**< �ⲿ�ı����                          */ 
#define GDD_GRC                   22    /**< ͨ�÷���ش���                        */ 
#define GDD_STRUCTURE             23    /**< ���ݽṹ                              */
#define GDD_INDEX                 24    /**< ����                                  */

/** IEC60870-5-103������� */
#define KOD_NONE                  0     /**< ����ָ�����������(NO KOD SPECIFIED)  */
#define KOD_ACTUAL_VALUE          1     /**< ʵ��ֵ(ACTUAL VALUE)                  */
#define KOD_DEFAULT_VALUE         2     /**< ȱʡֵ(DEFAULT VALUE)                 */
#define KOD_RANGE                 3     /**< ����(��Сֵ�����ֵ������)(RANGE)     */
#define KOD_PRECISION             5     /**< ����(n��m)(PRECISION n��m)            */
#define KOD_FACTOR                6     /**< ����(FACTOR)                          */
#define KOD_REFERENCE             7     /**< ���α�(%REFERENCE)                    */
#define KOD_ENUMERATION           8     /**< �б�(ENUMERATION)                     */
#define KOD_DIMENSION             9     /**< ����(DIMENSION)                       */
#define KOD_DESCRIPTION           10    /**< ����(DESCRIPTION)                     */
#define KOD_PASSWORD_ENTRY        12    /**< ������Ŀ(PASSWORD ENTRY)              */
#define KOD_IS_RDONLY             13    /**< ֻ��(IS READ ONLY)                    */
#define KOD_IS_WDONLY             14    /**< ֻд(IS WRITE ONLY)                   */
#define KOD_TYP_INF               19    /**< ��Ӧ�Ĺ������ͺ���Ϣ���              */
#define KOD_EVENTS                20    /**< ��Ӧ���¼�(CORRESPONDING EVENTS)      */
#define KOD_ENUM_TEXT_ARRAY       21    /**< �б���ı�����(ENUMERATED TEXT ARRAY) */
#define KOD_ENUM_VAL_ARRAY        22    /**< �б��ֵ����(ENUMERATED VALUE ARRAY)  */
#define KOD_RELATED_ENTRIES       23    /**< ���������Ŀ(RELATED ENTRIES)         */
                                                                                                                    
/** IEC60870-5-103ͨ�÷���ش���                                                   */
#define GRC_ACCEPT                0     /**< �Ͽ�                                  */
#define GRC_INVALID_GIN           1     /**< ��Ч��ͨ�÷����ʶ���(GIN)           */
#define GRC_NOREQS_DATA           2     /**< �����������������                    */
#define GRC_DATA_INVALID          3     /**< ���ݲ����ã���������һ��              */
#define GRC_CONFIRM_ERR           4     /**< �ı��趨ʱȷ�ϳ���                    */
#define GRC_RANGE_OV              5     /**< �ı��趨ʱ��������                    */
#define GRC_ENTRY_OV              6     /**< ��Ŀ�ķ�Χ̫��                        */
#define GRC_COMMANDNUM_OV         7     /**< ̫�������                            */
#define GRC_ENTRY_RDONLY          8     /**< ��Ŀ��ֻ����(IS READ ONLY)            */
#define GRC_NEED_PASSWORD         9     /**< �趨�ܿ����                        */
#define GRC_OP_BUSY               10    /**< �����趨�ڽ�����                      */
#define GRC_ERR_DES               11    /**< ���������������Ĳ��                  */

/** IEC60870-5-103��������                                                                                 */
#define TOO_FAULT_SELECT_1        1     /**< ���ϵ�ѡ��                                                    */ 
#define TOO_REQ_TD_2              2     /**< �����Ŷ�����                                                  */ 
#define TOO_BRK_TD_3              3     /**< ��ֹ�Ŷ�����                                                  */ 
#define TOO_CHANNEL_REQ_8         8     /**< ͨ��������                                                    */ 
#define TOO_CHANNEL_BRK_9         9     /**< ͨ������ֹ                                                    */ 
#define TOO_REQ_COS_16            16    /**< �������־��״̬��λ                                          */ 
#define TOO_BRK_COS_17            17    /**< ��ֹ����־��״̬��λ                                          */ 
#define TOO_REQ_RECTD_24          24    /**< ���󱻼�¼���Ŷ���                                            */ 
#define TOO_NOBRK_TD_END_32       32    /**< ������ֹ���Ŷ����ݴ���Ľ���                                  */ 
#define TOO_CSBRK_TD_END_33       33    /**< �ɿ���ϵͳ����ֹ���Ŷ����ݴ���Ľ���                          */ 
#define TOO_PTBRK_TD_END_34       34    /**< �ɼ̵籣���豸(������Ԫ)����ֹ���Ŷ����ݴ���Ľ���          */ 
#define TOO_NOBRK_CT_END_35       35    /**< ������ֹ��ͨ������Ľ���                                      */ 
#define TOO_CSBRK_CT_END_36       36    /**< �ɿ���ϵͳ����ֹ��ͨ������Ľ���                              */ 
#define TOO_PTBRK_CT_END_37       37    /**< �ɼ̵籣���豸(������Ԫ)����ֹ��ͨ������Ľ���              */ 
#define TOO_NOBRK_COS_END_38      38    /**< ������ֹ�Ĵ���־��״̬��λ�Ĵ���Ľ���                        */ 
#define TOO_CSBRK_COS_END_39      39    /**< �ɿ���ϵͳ����ֹ�Ĵ���־��״̬��λ�Ĵ���Ľ���                */ 
#define TOO_PTBRK_COS_END_40      40    /**< �ɼ̵籣���豸(������Ԫ)����ֹ�Ĵ���־��״̬��λ����Ľ���  */ 
#define TOO_TRANS_TD_ACK_64       64    /**< �ɹ����Ŷ����ݴ���(�϶�)                                      */ 
#define TOO_TRANS_TD_NCK_65       65    /**< ���ɹ����Ŷ����ݴ���(��)                                    */ 
#define TOO_CHANNEL_ACK_66        66    /**< �ɹ���ͨ������(�϶�)                                          */ 
#define TOO_CHANNEL_NCK_67        67    /**< ���ɹ���ͨ������(��)                                        */ 
#define TOO_TCOS_ACK_68           68    /**< �ɹ��ش���־��״̬��λ����(�϶�)                              */ 
#define TOO_TCOS_NCK_69           69    /**< ���ɹ��ش���־��״̬��λ����(��)                            */

#define GDD_LEN         3
#define GIN_LEN         2
#define KOD_LEN         1

#pragma pack(1)
struct vsq_t {   
	unsigned char  NUM:7;
	unsigned char  SQ:1;
};
typedef union VSQ VSQ;      
union VSQ {      
	unsigned char		bits;
	vsq_t		parts;
};

struct cp56time2a_t {
    unsigned short   ms   :16;   /**< Milliseconds 0..59,999 ms     */
    unsigned short	 min  :6;    /**< Minutes 0..59 min             */
    unsigned short	 RES1 :1;    /**< Spare bit                     */
    unsigned short	 IV   :1;    /**< Invalid time                  */
    unsigned short	 hour :5;    /**< Hours 0..23h                  */
    unsigned short	 RES2 :2;    /**< Spare bit                     */
    unsigned short	 su   :1;    /**< Summer time                   */
    unsigned short	 day  :5;    /**< Days of month 1..31           */
    unsigned short	 week :3;    /**< Days of week 1..7(Not used 0) */
    unsigned short	 month:4;    /**< Months 1..12                  */
    unsigned short	 RES3 :4;    /**< Spare bit                     */
    unsigned char    year :7;    /**< Years 0..99 since 2000        */
    unsigned char    RES4 :1;    /**< Spare bit                     */
};
typedef union CP56Time2a CP56Time2a;
union CP56Time2a {
	unsigned char        bits[7];
	cp56time2a_t parts;
};

struct cp32time2a_t {
	unsigned short	 ms   :16;   /**< Milliseconds 0..59,999 ms     */
    unsigned short	 min  :6;    /**< Minutes 0..59 min             */
    unsigned short	 RES1 :1;    /**< Spare bit                     */
    unsigned short	 IV   :1;    /**< Invalid time                  */
    unsigned short	 hour :5;    /**< Hours 0..23h                  */
    unsigned short	 RES2 :2;    /**< Spare bit                     */
    unsigned short	 su   :1;    /**< Summer time                   */
};
typedef union CP32Time2a CP32Time2a;
union CP32Time2a {
	unsigned char        bits[4];
	cp32time2a_t parts;
};

struct cp24time2a_t {      
    unsigned short   ms   :16;   /**< Milliseconds 0..59,999 ms */
    unsigned char    min  :6;    /**< Minutes 0..59 min         */
    unsigned char    RES1 :1;    /**< Spare bit                 */
    unsigned char    IV   :1;    /**< Invalid time              */
};
typedef union CP24Time2a CP24Time2a;
union CP24Time2a {
	unsigned char        bits[3];
	cp24time2a_t parts;
};

struct cp16time2a_t {      
    unsigned short	  ms;        /**< Milliseconds 0..59,999 ms */
};
typedef union CP16Time2a CP16Time2a;
union CP16Time2a {
	unsigned char        bits[2];
	cp16time2a_t parts;
};

struct siq_t {      
	unsigned char  SPI:1;
	unsigned char  RES:3;
	unsigned char  BL:1;
	unsigned char  SB:1;
	unsigned char  NT:1;
	unsigned char  IV:1;
};
typedef union SIQ SIQ;      
union SIQ {      
	unsigned char   bits;
	siq_t   parts;
};

struct diq_t {      
	unsigned char  DPI:2;
	unsigned char  RES:2;
	unsigned char  BL:1;
	unsigned char  SB:1;
	unsigned char  NT:1;
	unsigned char  IV:1;
};
typedef union DIQ DIQ;      
union DIQ {      
	unsigned char  bits;
	diq_t  parts;
};

struct vti_t {      
	unsigned char  value:7;
	unsigned char  transient:1;  //�豸��˲��״̬
};
typedef union VTI VTI;      
union VTI {      
	unsigned char  bits;
	vti_t  parts;
};

struct qds_t {      
	unsigned char  OV:1;
	unsigned char  RES:3;
	unsigned char  BL:1;
	unsigned char  SB:1;
	unsigned char  NT:1;
	unsigned char  IV:1;
};
typedef union QDS QDS;      
union QDS {      
	unsigned char  bits;
	qds_t  parts;
};

typedef union BSI BSI;
union BSI {      
	unsigned int	  bits;
	unsigned char     parts[4];
};

struct NVA {      
	short	  value;
};

struct sva_t {      
	unsigned short value:15;
	unsigned short sign:1;
};
typedef union SVA SVA;      
union SVA {      
	short	bits;
	sva_t   parts;
};

struct ieee754sp_t {
	unsigned int	 mant:23;
	unsigned int	 bexp:8;
	unsigned int	 sign:1;
};
typedef union IEEE754SP IEEE754SP;
union IEEE754SP {
	unsigned int	    bits;
	ieee754sp_t parts;
	float       f;
};

struct bcr_t {      
	unsigned int	 counter;
	unsigned char	 SQ:5;
	unsigned char    CY:1;
	unsigned char    CA:1;
	unsigned char    IV:1;
};
typedef union BCR BCR;      
union BCR {      
	unsigned char   bits[5];
	bcr_t   parts;
};

struct sep_t {      
	unsigned char ES:2;
	unsigned char RES:1;
	unsigned char EI:1;
	unsigned char BL:1;
	unsigned char SB:1;
	unsigned char NT:1;
	unsigned char IV:1;
};
typedef union SEP SEP;      
union SEP {      
	unsigned char   bits;
	sep_t   parts;
};

struct spe_t {      
	unsigned char GS:1;
	unsigned char SL1:1;
	unsigned char SL2:1;
	unsigned char SL3:1;
	unsigned char SIE:1;
	unsigned char SRD:1;
	unsigned char RES:2;
};
typedef union SPE SPE;      
union SPE {      
	unsigned char   bits;
	spe_t   parts;
};

struct qdp_t {      
	unsigned char  RES:3;
	unsigned char  EI:1;
	unsigned char  BL:1;
	unsigned char  SB:1;
	unsigned char  NT:1;
	unsigned char  IV:1;
};
typedef union QDP QDP;      
union QDP {      
	unsigned char   bits;
	qdp_t   parts;
};

struct oci_t {      
	unsigned char GC:1;
	unsigned char CL1:1;
	unsigned char CL2:1;
	unsigned char CL3:1;
	unsigned char RES:4;
};
typedef union OCI OCI;      
union OCI {      
	unsigned char   bits;
	oci_t   parts;
};

struct scd_t {      
	unsigned short	 ST;
	unsigned short	 CD;
};
typedef union SCD SCD;      
union SCD {      
	unsigned int	 bits;
	scd_t    parts;
};

struct sco_t {      
	unsigned char   SCS:1;
	unsigned char   RES:1;
	unsigned char   QU:5;
	unsigned char   SE:1;
};
typedef union SCO SCO;      
union SCO {      
	unsigned char   bits;
	sco_t   parts;
};

struct dco_t {      
	unsigned char   DCS:2;
	unsigned char   QU:5;
	unsigned char   SE:1;
};
typedef union DCO DCO;      
union DCO {      
	unsigned char   bits;
	dco_t   parts;
};

struct rco_t {      
	unsigned char   RCS:2;
	unsigned char   QU:5;
	unsigned char   SE:1;
};
typedef union RCO RCO;      
union RCO {      
	unsigned char   bits;
	rco_t   parts;
};

struct qos_t {      
	unsigned char   QL:7;
	unsigned char   SE:1;
};
typedef union QOSP QOSP;      
union QOSP {      
	unsigned char   bits;
	qos_t   parts;
};

struct coi_t {      
	unsigned char   cause:7;
	unsigned char   state:1;
};
typedef union COI COI;      
union COI {      
	unsigned char   bits;
	coi_t   parts;
};

struct QOI {      
	unsigned char   qoi;
};

struct qcc_t {
	unsigned char   RQT:6;
	unsigned char   FRZ:2;
};
typedef union QCC QCC;      
union QCC {      
	unsigned char   bits;
	qcc_t   parts;
};

struct FBP {
	unsigned short  HEX;
};

struct QRP {
	unsigned char  qrp;
};

struct qpm_t {
	unsigned char  KPA:6;
	unsigned char  LPC:1;
	unsigned char  POP:1;
};
typedef union QPM QPM;  
union QPM {      
	unsigned char   bits;
	qpm_t   parts;
};

struct QPA {
	unsigned char  qpa;
};

typedef unsigned short NOF;

typedef unsigned char NOS;

struct LOF {
	unsigned char lof[3];
};

typedef unsigned char LOS;

typedef unsigned char CHS; 

struct sof_t {
	unsigned char STATUS:5;
	unsigned char LFD:1;
	unsigned char FOR:1;
	unsigned char FA:1;
};
typedef union SOF SOF;      
union SOF {      
	unsigned char   bits;
	sof_t   parts;
};

struct frq_t {
	unsigned char FILES:7;
	unsigned char ACK:1;      /**< =0 ack; =1 deny */
};
typedef union FRQ FRQ;      
union FRQ {      
	unsigned char   bits;
	frq_t   parts;
};

struct srq_t {
	unsigned char  SESSION:7;
	unsigned char  READY:1;
};
typedef union SRQ SRQ;      
union SRQ {      
	unsigned char   bits;
	srq_t   parts;
};

struct scq_t {
	unsigned char  REQUEST:4;
	unsigned char  RESPONSE:4;
};
typedef union SCQ SCQ;      
union SCQ {      
	unsigned char   bits;
	scq_t   parts;
};

typedef unsigned char LSQ;

struct afq_t {
	unsigned char  ACK:4;
	unsigned char  STATUS:4;
};
typedef union AFQ AFQ;      
union AFQ {      
	unsigned char   bits;
	afq_t   parts;
};

//������Ϣ�ṹ
struct M_SP_NA_1_t {
	SIQ      siq;
};
//��ʱ��ĵ�����Ϣ�ṹ
struct M_SP_TA_1_t {
	SIQ        siq;
	CP24Time2a tm;
};
//˫����Ϣ�ṹ
struct M_DP_NA_1_t {
	DIQ      diq;
};
//��ʱ���˫����Ϣ�ṹ
struct M_DP_TA_1_t {
	DIQ        diq;
	CP24Time2a tm;
};
//��λ����Ϣ�ṹ
struct M_ST_NA_1_t {
	VTI      vti;
	QDS      qds;
};
//��ʱ��Ĳ�λ����Ϣ�ṹ
struct M_ST_TA_1_t {
	VTI        vti;
	QDS        qds;
	CP24Time2a tm;
};	
//32���ش��ṹ
struct M_BO_NA_1_t {	
	BSI        bsi;
	QDS        qds;
};		
//��ʱ���32���ش��ṹ
struct M_BO_TA_1_t {
	BSI        bsi;
	QDS        qds;
	CP24Time2a tm;
};
//����ֵ,��һ��ֵ�ṹ
struct M_ME_NA_1_t {
	NVA      nva;
	QDS      qds;
};
//��ʱ��Ĳ���ֵ,��һ��ֵ�ṹ
struct M_ME_TA_1_t {
	NVA        nva;
	QDS        qds;
	CP24Time2a tm;
};	
//����ֵ,��Ȼ�ֵ�ṹ
struct M_ME_NB_1_t {
	SVA        sva;
	QDS        qds;
};	
//��ʱ��Ĳ���ֵ,��Ȼ�ֵ�ṹ
struct M_ME_TB_1_t {
	SVA        sva;
	QDS        qds;
	CP24Time2a tm;
};	
//����ֵ,�̸������ṹ
struct M_ME_NC_1_t {
	IEEE754SP std;
	QDS       qds;
};	
//��ʱ��Ĳ���ֵ,�̸������ṹ
struct M_ME_TC_1_t {
	IEEE754SP   std;
	QDS         qds;
	CP24Time2a  tm;
};	
//�ۼ����ṹ
struct M_IT_NA_1_t {
	BCR        bcr;
};
//��ʱ����ۼ����ṹ
struct M_IT_TA_1_t {
	BCR         bcr;
	CP24Time2a  tm;
};	
//��ʱ��ļ̵籣��װ���¼��ṹ
struct M_EP_TA_1_t {
	SEP         sep;
	CP16Time2a  tm16;
	CP24Time2a  tm24;
};	
//��ʱ��ļ̵籣��װ�ó��������¼��ṹ
struct M_EP_TB_1_t {
	SPE         spe;
	QDP         qdp;
	CP16Time2a  tm16;
	CP24Time2a  tm24;
};	
//��ʱ��ļ̵籣��װ�ó��������·��Ϣ�ṹ
struct M_EP_TC_1_t {
	OCI         oci;
	QDP         qdp;
	CP16Time2a  tm16;
	CP24Time2a  tm24;
};	
//����λ����ĳ��鵥����Ϣ�ṹ
struct M_PS_NA_1_t {
	SCD      scd;
	QDS      qds;
};	
//����ֵ,����Ʒ�������ʵĹ�һ��ֵ�ṹ
struct M_ME_ND_1_t {
	NVA      nva;
};
//��CP56Time2aʱ��ĵ�����Ϣ�ṹ
struct M_SP_TB_1_t {
	SIQ        siq;
	CP56Time2a tm;
};	
//��CP56Time2aʱ���˫����Ϣ�ṹ
struct M_DP_TB_1_t {
	DIQ        diq;
	CP56Time2a tm;
};	
//��CP56Time2aʱ��Ĳ�λ����Ϣ�ṹ
struct M_ST_TB_1_t {
	VTI        vti;
	QDS        qds;
	CP56Time2a tm;
};	
//��CP56Time2aʱ���32���ش��ṹ
struct M_BO_TB_1_t {
	BSI        bsi;
	QDS        qds;
	CP56Time2a tm;
};
//��CP56Time2aʱ��Ĳ���ֵ,��һ��ֵ�ṹ
struct M_ME_TD_1_t {
	NVA        nva;
	QDS        qds;
	CP56Time2a tm;
};	
//��CP56Time2aʱ��Ĳ���ֵ,��Ȼ�ֵ�ṹ
struct M_ME_TE_1_t {
	SVA        sva;
	QDS        qds;
	CP56Time2a tm;
};	
//��CP56Time2aʱ��Ĳ���ֵ,�̸������ṹ
struct M_ME_TF_1_t {
	IEEE754SP   std;
	QDS         qds;
	CP56Time2a  tm;
};	
//��CP56Time2aʱ����ۼ����ṹ
struct M_IT_TB_1_t {
	BCR        bcr;
	CP56Time2a tm;
};	
//��CP56Time2aʱ��ļ̵籣��װ���¼��ṹ
struct M_EP_TD_1_t {
	SEP         sep;
	CP16Time2a  tm16;
	CP56Time2a  tm56;
};	
//��CP56Time2aʱ��ļ̵籣��װ�ó��������¼��ṹ
struct M_EP_TE_1_t {
	SPE         spe;
	QDP         qdp;
	CP16Time2a  tm16;
	CP56Time2a  tm56;
};	
//��CP56Time2aʱ��ļ̵籣��װ�ó��������·��Ϣ�ṹ
struct M_EP_TF_1_t {
	OCI         oci;
	QDP         qdp;
	CP16Time2a  tm16;
	CP56Time2a  tm56;
};
//��������
struct C_SC_NA_1_t {
	SCO      sco;
};	
//˫������
struct C_DC_NA_1_t {
	DCO      dco;
};	
//���ڲ�����
struct C_RC_NA_1_t {
	RCO      rco;
};	
//�趨ֵ����,��һ��ֵ
struct C_SE_NA_1_t {
	NVA      nva;
	QOSP     qos;
};		
//�趨ֵ����,��Ȼ�ֵ
struct C_SE_NB_1_t {
	SVA      sva;
	QOSP     qos;
};	
//�趨ֵ����̸�����
struct C_SE_NC_1_t {
	IEEE754SP std;
	QOSP      qos;
};	
//�趨ֵ����,32���ش�
struct C_BO_NA_1_t {
	BSI       bsi;
};
//��ʼ������
struct M_EI_NA_1_t {
	COI      coi;
};	
//���ٻ�����
struct C_IC_NA_1_t {
	QOI      qoi;
};	
//�ۼ����ٻ�����
struct C_CI_NA_1_t {
	QCC      qcc;
};	
//ʱ��ͬ������
struct C_CS_NA_1_t {
	CP56Time2a tm;
};	
//��������
struct C_TS_NA_1_t {
	FBP      fbp;
};	
//��λ��������
struct C_RP_NA_1_t {
	QRP      qrp;
};	
//�ռ�������ʱ
struct C_CD_NA_1_t {
	CP16Time2a  tm;
};	
//����ֵ����,��һ��ֵ
struct P_ME_NA_1_t {
	NVA      nva;
	QPM      qpm;
};	
//����ֵ��������Ȼ�ֵ
struct P_ME_NB_1_t {
	SVA      sva;
	QPM      qpm;
};	
//����ֵ����,�̸�����
struct P_ME_NC_1_t {
	IEEE754SP std;
	QPM       qpm;
};	
//��������
struct P_AC_NA_1_t {
	QPA      qpa;
};
//�ļ���������
struct F_FR_NA_1_t {
	NOF		nof;
	LOF		lof;
	FRQ		frq;
};
//�ڻ�������
struct F_SR_NA_1_t {
	NOF     nof;
	NOS     nos;
	LOF		lof;
};	
//�ٻ�Ŀ¼,ѡ���ļ�,�ٻ��ļ��ٻ���
struct F_SC_NA_1_t {
	NOF     nof;
	NOS     nos;
	SCQ     scq;
};	
//���Ľ�,���Ķ�
struct F_LS_NA_1_t {
	NOF     nof;
	NOS     nos;
    LSQ     lsq;
    CHS     chs;
};	
//�Ͽ��ļ�,�Ͽɽ�
struct F_AF_NA_1_t {
	NOF     nof;
	NOS     nos;
    AFQ     afq;
};	
//��
struct F_SG_NA_1_t {
	NOF     nof;
	NOS     nos;
    LOS     los;
    unsigned char   seg[1];
};	
//Ŀ¼
struct F_DR_TA_1_t {
	NOF        nof;
    LOF        lof;
	SOF        nos;
    CP56Time2a tm;
};	

/** IEC60870-5-103��Լ */
struct GIN_t 
{      
    unsigned char  group;    /**< group */
    unsigned char  entry;    /**< entry */
};

struct GDD_t 
{      
    unsigned char  type;      /**< GDD type  */
    unsigned char  size;      /**< data size */
    unsigned char  num:7;     /**< number    */
    unsigned char  cont:1;    /**< continue  */
};

struct NGD 
{  
    unsigned char  num:6;    /**< number   */
    unsigned char  count:1;  /**< count    */
    unsigned char  cont:1;   /**< continue */
};
union NGD_t 
{  
    unsigned char  bits; 
    NGD    parts;
};
#pragma pack()

//��Ʒ����
bool DescUserData(char* DrawStr,unsigned char typid,char* udata);
size_t SizeOfType(unsigned char typid);

#endif // _RMS_ANALYZE_PUB_
