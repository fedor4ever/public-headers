/* NAMESER.H
 * 
 * Portions copyright (c) 1993-1999 Symbian Ltd.  All rights reserved.
 */

/** @file
@publishedAll
@released
*/

/*
 * Copyright (c) 1983, 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * -
 * Portions Copyright (c) 1993 by Digital Equipment Corporation.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies, and that
 * the name of Digital Equipment Corporation not be used in advertising or
 * publicity pertaining to distribution of the document or software without
 * specific, written prior permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT
 * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 * -
 * Portions Copyright (c) 1995 by International Business Machines, Inc.
 *
 * International Business Machines, Inc. (hereinafter called IBM) grants
 * permission under its copyrights to use, copy, modify, and distribute this
 * Software with or without fee, provided that the above copyright notice and
 * all paragraphs of this notice appear in all copies, and that the name of IBM
 * not be used in connection with the marketing of any product incorporating
 * the Software or modifications thereof, without specific, written prior
 * permission.
 *
 * To the extent it has a right to do so, IBM grants an immunity from suit
 * under its patents, if any, for the use, sale or manufacture of products to
 * the extent that such products are used for performing Domain Name System
 * dynamic updates in TCP/IP networks by means of the Software.  No immunity is
 * granted for any product per se or for any other function of any product.
 * THE SOFTWARE IS PROVIDED "AS IS", AND IBM DISCLAIMS ALL WARRANTIES,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE.  IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL,
 * DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE, EVEN
 * IF IBM IS APPRISED OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 *      @(#)nameser.h	8.2 (Berkeley) 2/16/94
 *	From Id: nameser.h,v 8.11 1996/10/08 04:51:02 vixie Exp
 *	$Id: nameser.h,v 1.11 1997/02/23 09:17:20 peter Exp $
 */

#ifndef _ARPA_NAMESER_H_
#define	_ARPA_NAMESER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/param.h>
#include <sys/types.h>

/**
revision information.  this is the release date in YYYYMMDD format.
it can change every day so the right thing to do with it is use it
in preprocessor commands such as "#if (__BIND > 19931104)".  do not
compare for equality; rather, use it to determine whether your resolver
is new enough to contain a certain feature.
*/

#define	__BIND		19960801	/* interface version stamp */

/**
Define constants based on rfc883
*/

/** maximum packet size */
#define	PACKETSZ	512		

/** maximum presentation domain name */
#define MAXDNAME	1025		

/** maximum compressed domain name */
#define	MAXCDNAME	255		

/** maximum length of domain label */
#define	MAXLABEL	63		

/** #/bytes of fixed data in header */
#define	HFIXEDSZ	12		

/** #/bytes of fixed data in query */
#define	QFIXEDSZ	4		

/** #/bytes of fixed data in r record */
#define	RRFIXEDSZ	10		

/** for systems without 32-bit ints */
#define	INT32SZ		4		

/** for systems without 16-bit ints */
#define	INT16SZ		2		

/** IPv4 T_A */
#define INADDRSZ	4		

/** IPv6 T_AAAA */
#define IN6ADDRSZ	16		

/**
Internet nameserver port number
*/
#define	NAMESERVER_PORT	53


/**
Currently defined opcodes
*/

/** standard query */
#define	QUERY		0x0		

	/** inverse query */
#define	IQUERY		0x1	

/** nameserver status query */
#define	STATUS		0x2		

/* 0x3 reserved */
/*#define xxx		0x3 */
#define	NS_NOTIFY_OP	0x4		/* notify secondary of SOA change */


/**
Currently defined response codes
*/

/** no error */
#define	NOERROR		0	

/** format error */
#define	FORMERR		1		

/** server failure */
#define	SERVFAIL	2		

/** non existent domain */
#define	NXDOMAIN	3		

/** not implemented */
#define	NOTIMP		4		

/** query refused */
#define	REFUSED		5		



/**
Type values for resources and queries
*/

/** host address */
#define	T_A		1		

/** authoritative server */
#define	T_NS		2		

/** mail destination */
#define	T_MD		3		

/** mail forwarder */
#define	T_MF		4	

/** canonical name */
#define T_CNAME		5		

/** start of authority zone */
#define	T_SOA		6		

/** mailbox domain name */
#define	T_MB		7		

/** mail group member */
#define	T_MG		8		

/** mail rename name */
#define	T_MR		9		

/** null resource record */
#define	T_NULL		10		

/** well known service */
#define	T_WKS		11		

/** domain name pointer */
#define	T_PTR		12		

/** host information */
#define	T_HINFO		13		

/** mailbox information */
#define	T_MINFO		14		

/** mail routing information */
#define	T_MX		15		

/** text strings */
#define	T_TXT		16		

/** responsible person */
#define	T_RP		17		

/** AFS cell database */
#define	T_AFSDB		18		

/** X_25 calling address */
#define	T_X25		19		

/** ISDN calling address */
#define	T_ISDN		20		

/** router */
#define	T_RT		21		

/** NSAP address */
#define	T_NSAP		22		

/** reverse NSAP lookup (deprecated) */
#define	T_NSAP_PTR	23		

/** security signature */
#define	T_SIG		24		

/** security key */
#define	T_KEY		25	

/** X.400 mail mapping */
#define	T_PX		26		

/** geographical position (withdrawn) */
#define	T_GPOS		27	

/** IP6 Address */
#define	T_AAAA		28		

/** Location Information */
#define	T_LOC		29		

/** Next Valid Name in Zone */
#define T_NXT		30		

/** Endpoint identifier */
#define T_EID		31		

/** Nimrod locator */
#define T_NIMLOC	32	

/** Server selection */
#define T_SRV		33		

/** ATM Address */
#define T_ATMA		34		

/** Naming Authority PoinTeR */
#define T_NAPTR		35		

/** user (finger) information
non standard 
*/
#define	T_UINFO		100		

/** user ID */
#define	T_UID		101		

/** group ID */
#define	T_GID		102		

/** Unspecified format (binary data) */
#define	T_UNSPEC	103		

/** Query type values which do not appear in resource records
incremental zone transfer */
#define T_IXFR		251		

/** transfer zone of authority */
#define	T_AXFR		252		

/** transfer mailbox records */
#define	T_MAILB		253		

/** transfer mail agent records */
#define	T_MAILA		254		

/** wildcard match */
#define	T_ANY		255		

/**
Values for class field
*/
#define	C_IN		1		/* the arpa internet */
#define	C_CHAOS		3		/* for chaos net (MIT) */
#define	C_HS		4		/* for Hesiod name server (MIT) (XXX) */
	/* Query class values which do not appear in resource records */
#define	C_ANY		255		/* wildcard match */

/**
Flags field of the KEY RR rdata
*/
#define	KEYFLAG_TYPEMASK	0xC000	/* Mask for "type" bits */
#define	KEYFLAG_TYPE_AUTH_CONF	0x0000	/* Key usable for both */
#define	KEYFLAG_TYPE_CONF_ONLY	0x8000	/* Key usable for confidentiality */
#define	KEYFLAG_TYPE_AUTH_ONLY	0x4000	/* Key usable for authentication */
#define	KEYFLAG_TYPE_NO_KEY	0xC000	/* No key usable for either; no key */
/** The type bits can also be interpreted independently, as single bits: */
#define	KEYFLAG_NO_AUTH		0x8000	/* Key not usable for authentication */
#define	KEYFLAG_NO_CONF		0x4000	/* Key not usable for confidentiality */

#define	KEYFLAG_EXPERIMENTAL	0x2000	/* Security is *mandatory* if bit=0 */
#define	KEYFLAG_RESERVED3	0x1000  /* reserved - must be zero */
#define	KEYFLAG_RESERVED4	0x0800  /* reserved - must be zero */
#define	KEYFLAG_USERACCOUNT	0x0400	/* key is assoc. with a user acct */
#define	KEYFLAG_ENTITY		0x0200	/* key is assoc. with entity eg host */
#define	KEYFLAG_ZONEKEY		0x0100	/* key is zone key for the zone named */
#define	KEYFLAG_IPSEC		0x0080  /* key is for IPSEC use (host or user)*/
#define	KEYFLAG_EMAIL		0x0040  /* key is for email (MIME security) */
#define	KEYFLAG_RESERVED10	0x0020  /* reserved - must be zero */
#define	KEYFLAG_RESERVED11	0x0010  /* reserved - must be zero */
#define	KEYFLAG_SIGNATORYMASK	0x000F	/* key can sign DNS RR's of same name */

#define  KEYFLAG_RESERVED_BITMASK ( KEYFLAG_RESERVED3 | \
				    KEYFLAG_RESERVED4 | \
				    KEYFLAG_RESERVED10| KEYFLAG_RESERVED11) 

/**
The Algorithm field of the KEY and SIG RR's is an integer, {1..254} 
*/
#define	ALGORITHM_MD5RSA	1	/* MD5 with RSA */
#define	ALGORITHM_EXPIRE_ONLY	253	/* No alg, no security */
#define	ALGORITHM_PRIVATE_OID	254	/* Key begins with OID indicating alg */

/**
Signatures 
*/
					/** Size of a mod or exp in bits */
#define	MIN_MD5RSA_KEY_PART_BITS	 512
#define	MAX_MD5RSA_KEY_PART_BITS	2552
					/** Total of binary mod and exp, bytes */
#define	MAX_MD5RSA_KEY_BYTES		((MAX_MD5RSA_KEY_PART_BITS+7/8)*2+3)
					/** Max length of text sig block */
#define	MAX_KEY_BASE64			(((MAX_MD5RSA_KEY_BYTES+2)/3)*4)

/**
Status return codes for T_UNSPEC conversion routines
*/
#define	CONV_SUCCESS	0
#define	CONV_OVERFLOW	(-1)
#define	CONV_BADFMT	(-2)
#define	CONV_BADCKSUM	(-3)
#define	CONV_BADBUFLEN	(-4)

/**
Structure for query header.  The order of the fields is machine- and
compiler-dependent, depending on the byte/bit order and the layout
of bit fields.  We use bit fields only in int variables, as this
is all ANSI requires.  This requires a somewhat confusing rearrangement.
EPOC32 is little-endian
*/
typedef struct {
	unsigned	id :16;		/* query identification number */
			/* fields in third byte */
	unsigned	rd :1;		/* recursion desired */
	unsigned	tc :1;		/* truncated message */
	unsigned	aa :1;		/* authoritative answer */
	unsigned	opcode :4;	/* purpose of message */
	unsigned	qr :1;		/* response flag */
			/* fields in fourth byte */
	unsigned	rcode :4;	/* response code */
	unsigned	cd: 1;		/* checking disabled by resolver */
	unsigned	ad: 1;		/* authentic data from named */
	unsigned	unused :1;	/* unused bits (MBZ as of 4.9.3a3) */
	unsigned	ra :1;		/* recursion available */
			/* remaining bytes */
	unsigned	qdcount :16;	/* number of question entries */
	unsigned	ancount :16;	/* number of answer entries */
	unsigned	nscount :16;	/* number of authority entries */
	unsigned	arcount :16;	/* number of resource entries */
} HEADER;

/**
Defines for handling compressed domain names
*/
#define	INDIR_MASK	0xc0

extern	u_int16_t	_getshort (const u_char *);
extern	u_int32_t	_getlong (const u_char *);

/**
Inline versions of get/put short/long.  Pointer is advanced.

These macros demonstrate the property of C whereby it can be
portable or it can be elegant but rarely both.
*/
#define	GETSHORT(s, cp) { \
	register u_char *t_cp = (u_char *)(cp); \
	(s) = ((u_int16_t)t_cp[0] << 8) \
	    | ((u_int16_t)t_cp[1]) \
	    ; \
	(cp) += INT16SZ; \
}

#define	GETLONG(l, cp) { \
	register u_char *t_cp = (u_char *)(cp); \
	(l) = ((u_int32_t)t_cp[0] << 24) \
	    | ((u_int32_t)t_cp[1] << 16) \
	    | ((u_int32_t)t_cp[2] << 8) \
	    | ((u_int32_t)t_cp[3]) \
	    ; \
	(cp) += INT32SZ; \
}

#define	PUTSHORT(s, cp) { \
	register u_int16_t t_s = (u_int16_t)(s); \
	register u_char *t_cp = (u_char *)(cp); \
	*t_cp++ = t_s >> 8; \
	*t_cp   = t_s; \
	(cp) += INT16SZ; \
}

#define	PUTLONG(l, cp) { \
	register u_int32_t t_l = (u_int32_t)(l); \
	register u_char *t_cp = (u_char *)(cp); \
	*t_cp++ = t_l >> 24; \
	*t_cp++ = t_l >> 16; \
	*t_cp++ = t_l >> 8; \
	*t_cp   = t_l; \
	(cp) += INT32SZ; \
}

#ifdef __cplusplus
}
#endif
#endif /* !_ARPA_NAMESER_H_ */
