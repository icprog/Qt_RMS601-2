/**
 * �� �� �� : PcapFile.h
 * �������� : 2014-4-22 11:32
 * ��    �� : �ο�
 * �޸����� : $Date: $
 * ��ǰ�汾 : $Revision: $
 * �������� : ���ļ��ӵ��ļ�����
 **/

#ifndef __PCAP_FILE_H__
#define __PCAP_FILE_H__

#include "sbase/SApi.h"
#ifdef WIN32
#include "Lzma7z.h"
#endif

#define	MBYTE1				(1024*1024)
#define	MAXZIPLEN			(MBYTE1*50)	//����ļ�ѹ����С
#define	MINZIPLEN			(MBYTE1*5)	//��С�ļ�ѹ����С
#define	MAXSAVEFILENUM		200			//����ļ�ѹ������
#define	MINSAVEFILENUM		20			//��С�ļ�ѹ������
#define MAXFRAMECACHE		(MBYTE1*20)	//��󻺴����ݴ�С
#define SERVERPORT			8791
#define COMMFRAMESYN		0x09D7

#define	IP_TYPE			0x0800
#define	TCP_PROTOCOL	6
#define	UDP_PROTOCOL	17

#pragma pack(1)
typedef struct commframe_header_t commframe_header_t;
struct commframe_header_t {
	unsigned short	syn;
	unsigned int	len;
};

typedef struct pcap_file_header_t pcap_file_header_t;
struct pcap_file_header_t {
	unsigned int	magic;
	unsigned short	version_major;
	unsigned short  version_minor;
	int				thiszone;	/* gmt to local correction */
	unsigned int	sigfigs;	/* accuracy of timestamps */
	unsigned int	snaplen;	/* max length saved portion of each pkt */
	unsigned int	linktype;	/* data link type (LINKTYPE_*) */
};

typedef struct pcap_frame_header_t pcap_frame_header_t;
struct pcap_frame_header_t {
	long			tv_sec;     /* seconds */
	long			tv_usec;    /* microseconds */
	unsigned int	caplen;		/* length of portion present */
	unsigned int	len;		/* length this packet (off wire) */
};

typedef struct mac_header_t mac_header_t;
struct mac_header_t
{
	unsigned char	dst_mac_addr[6];
	unsigned char	src_mac_addr[6];
	unsigned short  type;
	void Ntoh()
	{
		type = ntohs(type);
	}
};

typedef struct ip_header_t ip_header_t;
struct ip_header_t
{
	unsigned char	ver_len;        // �汾 + �ײ�����
	unsigned char	tos;            // ��������
	unsigned short	len;            // �ܳ���
	unsigned short	id;             // ��ʶ
	unsigned short 	flag_off;       // 3Ϊƫ�ƺ�13λƬƫ��
	unsigned char	ttl;            // ����ʱ��
	unsigned char	ptl;            // Э��
	unsigned short	sum;            // �ײ�У���
	unsigned int 	src_ip;         // ԴIP
	unsigned int	dst_ip;         // Ŀ��IP
	void Ntoh()
	{
		len = ntohs(len);
		id = ntohs(id);
		flag_off = ntohs(flag_off);
		sum = ntohs(sum);
		src_ip = ntohl(src_ip);
		dst_ip = ntohl(dst_ip);
	}
};

typedef struct tcp_header_t tcp_header_t;
struct tcp_header_t
{
	unsigned short	src_port;    // Դ�˿�
	unsigned short	dst_port;    // Ŀ��˿�
	unsigned int	seq_num;     // �������
	unsigned int	ack_num;     // ȷ�����
	unsigned short	off_flags;   // ����ƫ�� + ��ʶλ('s)
	unsigned short	window;      // �������ڴ�С
	unsigned short	chk_sum;     // У���
	unsigned short	urg_ptr;     // ����ָ��
	void Ntoh()
	{
		src_port = ntohs(src_port);
		dst_port = ntohs(dst_port);
		seq_num = ntohl(seq_num);
		ack_num = ntohl(ack_num);
		off_flags = ntohs(off_flags);
		window = ntohs(window);
		chk_sum = ntohs(chk_sum);
		urg_ptr = ntohs(urg_ptr);
	}
};
#pragma pack()

class CPcapFile
{
public:
	CPcapFile(void);
	~CPcapFile(void);

	bool	SetPathName(string path);
	void	SetStoreFileSize(int sSize) { storeFileSize = sSize; };
	void	SetStoreFileNum(int sNum) { storeFileNum = sNum; };
	void	SetFormat7z(bool bZip,bool b7z);
	bool	SavePcapFile(string ethName,char *buffer,int length);
	bool	CachePcapFrame(string ethName,char *buffer,int length);
	bool	OpenPcapFile(string fileName);
	void	ClosePcapFile();
	int		GetFileLen(string sFile);
	void	BackupFile(string ethName);

	void	MakePcapFileHeader(pcap_file_header_t & pfh);
	bool	WritePcapFileHeader(string path);
	bool	WritePcapFileBuffer(string path,char *buffer,int length);	

private:
#ifdef WIN32
	CLzma7z		*lzma7z;
#endif
	string		m_sFile;
	FILE*		m_fpFile;
	string		storePath;
	bool		bCompress;
	bool		bFormat7z;
	int			storeFileSize;
	int			storeFileNum;
	string		exe7z;
	string		srcCompressFile;
	string		dstCompressFile;

	SLock		*m_pLock;		//�߳���
	static void* ThreadCompress(void *lp);
};

#endif	//__PCAP_FILE_H__
