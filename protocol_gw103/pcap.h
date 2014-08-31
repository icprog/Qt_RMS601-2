#ifndef _RMS_ANALYZE_PCAP_
#define _RMS_ANALYZE_PCAP_

#define	IP_TYPE		0x0800
#define ARP_TYPE	0x0806

#define	TCP_PROTOCOL	6
#define	UDP_PROTOCOL	17

#pragma pack(1)
typedef struct pcap_file_header_t pcap_file_header_t;
struct pcap_file_header_t {
	quint32	magic;
	quint16	version_major;
	quint16 version_minor;
	qint32	thiszone;	/* gmt to local correction */
	quint32	sigfigs;	/* accuracy of timestamps */
	quint32	snaplen;	/* max length saved portion of each pkt */
	quint32	linktype;	/* data link type (LINKTYPE_*) */
};

typedef struct pcap_frame_header_t pcap_frame_header_t;
struct pcap_frame_header_t {
	long	tv_sec;     /* seconds */
	long	tv_usec;    /* microseconds */
	quint32	caplen;		/* length of portion present */
	quint32	len;		/* length this packet (off wire) */
};

typedef struct mac_header_t mac_header_t;
struct mac_header_t
{
	qint8	dst_mac_addr[6];
	qint8	src_mac_addr[6];
	quint16	type;
	void Ntoh()
	{
		type = qToBigEndian(type);
	}
};

typedef struct ver_len_t ver_len_t;
struct ver_len_t
{
	quint8 length:4;
	quint8 version:4;
};

typedef struct flag_off_t flag_off_t;
struct flag_off_t
{
	quint16 offset:13;
	quint16 flag:3;
};

typedef struct ip_header_t ip_header_t;
struct ip_header_t
{
	ver_len_t   ver_len;        // �汾 + �ײ�����
	quint8		tos;            // ��������
	quint16		len;            // �ܳ���
	quint16		id;             // ��ʶ
	quint16 	flag_off;       // 3Ϊƫ�ƺ�13λƬƫ��
	quint8		ttl;            // ����ʱ��
	quint8		ptl;            // Э��
	quint16		sum;            // �ײ�У���
	quint32		src_ip;         // ԴIP
	quint32		dst_ip;         // Ŀ��IP
	void Ntoh()
	{
		len = qToBigEndian(len);
		id = qToBigEndian(id);
		flag_off = qToBigEndian(flag_off);
		sum = qToBigEndian(sum);
		src_ip = qToBigEndian(src_ip);
		dst_ip = qToBigEndian(dst_ip);
	}
};

typedef struct off_flags_t off_flags_t;
struct off_flags_t
{
	quint16 FIN:1;
	quint16 SYN:1;
	quint16 RST:1;
	quint16 PSH:1;
	quint16 ACK:1;
	quint16 URG:1;
	quint16 reserve:6;
	quint16 offset:4;
};

typedef struct offset_flags_t offset_flags_t;
struct offset_flags_t
{
	quint16 flags:12;
	quint16 offset:4;
};

typedef struct tcp_header_t tcp_header_t;
struct tcp_header_t
{
	quint16 src_port;    // Դ�˿�
	quint16 dst_port;    // Ŀ��˿�
	quint32 seq_num;     // �������
	quint32 ack_num;     // ȷ�����
	quint16 off_flags;   // ����ƫ�� + ��ʶλ('s)
	quint16 window;      // �������ڴ�С
	quint16 chk_sum;     // У���
	quint16 urg_ptr;     // ����ָ��
	void Ntoh()
	{
		src_port = qToBigEndian(src_port);
		dst_port = qToBigEndian(dst_port);
		seq_num = qToBigEndian(seq_num);
		ack_num = qToBigEndian(ack_num);
		off_flags = qToBigEndian(off_flags);
		window = qToBigEndian(window);
		chk_sum = qToBigEndian(chk_sum);
		urg_ptr = qToBigEndian(urg_ptr);
	}
};

typedef struct udp_header_t udp_header_t;
struct udp_header_t
{
	quint16 src_port;    // Դ�˿�
	quint16 dst_port;    // Ŀ�Ķ˿�
	quint16 len;         // UDP����
	quint16 chk_sum;     // У���
	void Ntoh()
	{
		src_port = qToBigEndian(src_port);
		dst_port = qToBigEndian(dst_port);
		len = qToBigEndian(len);
		chk_sum = qToBigEndian(chk_sum);
	}
};

typedef struct arp_data_t arp_data_t;
struct arp_data_t
{
	quint16 hardware_type;		// Ӳ������
	quint16 protocol_type;		// Э������
	quint8  hardware_size;		// Ӳ������
	quint8  protocol_size;		// Э�鳤��
	quint16 oper_code;			// ������
	qint8	sender_mac_addr[6];	// ������Ӳ����ַ
	quint32	sender_ip;			// ������IP��ַ
	qint8	target_mac_addr[6]; // Ŀ��Ӳ����ַ
	quint32	target_ip;          // Ŀ��IP��ַ
	void Ntoh()
	{
		hardware_type = qToBigEndian(hardware_type);
		protocol_type = qToBigEndian(protocol_type);
		oper_code = qToBigEndian(oper_code);
		sender_ip = qToBigEndian(sender_ip);
		target_ip = qToBigEndian(target_ip);
	}
};
#pragma pack()

#endif // _RMS_ANALYZE_PCAP_
