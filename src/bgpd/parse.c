/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 25 "../../../openbgpd-portable/src/bgpd/parse.y"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/ip_ipsp.h>
#include <arpa/inet.h>

#include <ctype.h>
#include <endian.h>
#include <err.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

#include "bgpd.h"
#include "session.h"
#include "rde.h"
#include "log.h"

#define MACRO_NAME_LEN		128

TAILQ_HEAD(files, file)		 files = TAILQ_HEAD_INITIALIZER(files);
static struct file {
	TAILQ_ENTRY(file)	 entry;
	FILE			*stream;
	char			*name;
	size_t			 ungetpos;
	size_t			 ungetsize;
	u_char			*ungetbuf;
	int			 eof_reached;
	int			 lineno;
	int			 errors;
} *file, *topfile;
struct file	*pushfile(const char *, int);
int		 popfile(void);
int		 check_file_secrecy(int, const char *);
int		 yyparse(void);
int		 yylex(void);
int		 yyerror(const char *, ...)
    __attribute__((__format__ (printf, 1, 2)))
    __attribute__((__nonnull__ (1)));
int		 kw_cmp(const void *, const void *);
int		 lookup(char *);
int		 igetc(void);
int		 lgetc(int);
void		 lungetc(int);
int		 findeol(void);
int		 expand_macro(void);

TAILQ_HEAD(symhead, sym)	 symhead = TAILQ_HEAD_INITIALIZER(symhead);
struct sym {
	TAILQ_ENTRY(sym)	 entry;
	int			 used;
	int			 persist;
	char			*nam;
	char			*val;
};
int		 symset(const char *, const char *, int);
char		*symget(const char *);

static struct bgpd_config	*conf;
static struct network_head	*netconf;
static struct peer_head		*new_peers, *cur_peers;
static struct rtr_config_head	*cur_rtrs;
static struct peer		*curpeer;
static struct peer		*curgroup;
static struct rde_rib		*currib;
static struct l3vpn		*curvpn;
static struct prefixset		*curpset, *curoset;
static struct roa_tree		*curroatree;
static struct rtr_config	*currtr;
static struct filter_head	*filter_l;
static struct filter_head	*peerfilter_l;
static struct filter_head	*groupfilter_l;
static struct filter_rule	*curpeer_filter[2];
static struct filter_rule	*curgroup_filter[2];
static int			 noexpires;

struct filter_rib_l {
	struct filter_rib_l	*next;
	char			 name[PEER_DESCR_LEN];
};

struct filter_peers_l {
	struct filter_peers_l	*next;
	struct filter_peers	 p;
};

struct filter_prefix_l {
	struct filter_prefix_l	*next;
	struct filter_prefix	 p;
};

struct filter_prefixlen {
	enum comp_ops		op;
	int			len_min;
	int			len_max;
};

struct filter_as_l {
	struct filter_as_l	*next;
	struct filter_as	 a;
};

struct filter_match_l {
	struct filter_match	 m;
	struct filter_prefix_l	*prefix_l;
	struct filter_as_l	*as_l;
	struct filter_prefixset	*prefixset;
} fmopts;

struct peer	*alloc_peer(void);
struct peer	*new_peer(void);
struct peer	*new_group(void);
int		 add_mrtconfig(enum mrt_type, char *, int, struct peer *,
		    char *);
struct rde_rib	*add_rib(char *);
struct rde_rib	*find_rib(char *);
int		 rib_add_fib(struct rde_rib *, u_int);
int		 get_id(struct peer *);
int		 merge_prefixspec(struct filter_prefix *,
		    struct filter_prefixlen *);
int		 expand_rule(struct filter_rule *, struct filter_rib_l *,
		    struct filter_peers_l *, struct filter_match_l *,
		    struct filter_set_head *);
int		 str2key(char *, char *, size_t);
int		 neighbor_consistent(struct peer *);
int		 merge_filterset(struct filter_set_head *, struct filter_set *);
void		 optimize_filters(struct filter_head *);
struct filter_rule	*get_rule(enum action_types);

int		 parsecommunity(struct community *, int, char *);
int		 parseextcommunity(struct community *, char *,
		    char *);
static int	 new_as_set(char *);
static void	 add_as_set(uint32_t);
static void	 done_as_set(void);
static struct prefixset	*new_prefix_set(char *, int);
static void	 add_roa_set(struct prefixset_item *, uint32_t, uint8_t,
		    time_t);
static struct rtr_config	*get_rtr(struct bgpd_addr *);
static int	 insert_rtr(struct rtr_config *);

typedef struct {
	union {
		long long		 number;
		char			*string;
		struct bgpd_addr	 addr;
		uint8_t			 u8;
		struct filter_rib_l	*filter_rib;
		struct filter_peers_l	*filter_peers;
		struct filter_match_l	 filter_match;
		struct filter_prefixset	*filter_prefixset;
		struct filter_prefix_l	*filter_prefix;
		struct filter_as_l	*filter_as;
		struct filter_set	*filter_set;
		struct filter_set_head	*filter_set_head;
		struct {
			struct bgpd_addr	prefix;
			uint8_t			len;
		}			prefix;
		struct filter_prefixlen	prefixlen;
		struct prefixset_item	*prefixset_item;
		struct {
			uint8_t			enc_alg;
			uint8_t			enc_key_len;
			char			enc_key[IPSEC_ENC_KEY_LEN];
		}			encspec;
	} v;
	int lineno;
} YYSTYPE;


#line 252 "parse.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AS = 258,                      /* AS  */
    ROUTERID = 259,                /* ROUTERID  */
    HOLDTIME = 260,                /* HOLDTIME  */
    YMIN = 261,                    /* YMIN  */
    LISTEN = 262,                  /* LISTEN  */
    ON = 263,                      /* ON  */
    FIBUPDATE = 264,               /* FIBUPDATE  */
    FIBPRIORITY = 265,             /* FIBPRIORITY  */
    RTABLE = 266,                  /* RTABLE  */
    NONE = 267,                    /* NONE  */
    UNICAST = 268,                 /* UNICAST  */
    VPN = 269,                     /* VPN  */
    RD = 270,                      /* RD  */
    EXPORT = 271,                  /* EXPORT  */
    EXPORTTRGT = 272,              /* EXPORTTRGT  */
    IMPORTTRGT = 273,              /* IMPORTTRGT  */
    DEFAULTROUTE = 274,            /* DEFAULTROUTE  */
    RDE = 275,                     /* RDE  */
    RIB = 276,                     /* RIB  */
    EVALUATE = 277,                /* EVALUATE  */
    IGNORE = 278,                  /* IGNORE  */
    COMPARE = 279,                 /* COMPARE  */
    RTR = 280,                     /* RTR  */
    PORT = 281,                    /* PORT  */
    GROUP = 282,                   /* GROUP  */
    NEIGHBOR = 283,                /* NEIGHBOR  */
    NETWORK = 284,                 /* NETWORK  */
    EBGP = 285,                    /* EBGP  */
    IBGP = 286,                    /* IBGP  */
    LOCALAS = 287,                 /* LOCALAS  */
    REMOTEAS = 288,                /* REMOTEAS  */
    DESCR = 289,                   /* DESCR  */
    LOCALADDR = 290,               /* LOCALADDR  */
    MULTIHOP = 291,                /* MULTIHOP  */
    PASSIVE = 292,                 /* PASSIVE  */
    MAXPREFIX = 293,               /* MAXPREFIX  */
    RESTART = 294,                 /* RESTART  */
    ANNOUNCE = 295,                /* ANNOUNCE  */
    CAPABILITIES = 296,            /* CAPABILITIES  */
    REFRESH = 297,                 /* REFRESH  */
    AS4BYTE = 298,                 /* AS4BYTE  */
    CONNECTRETRY = 299,            /* CONNECTRETRY  */
    ENHANCED = 300,                /* ENHANCED  */
    ADDPATH = 301,                 /* ADDPATH  */
    SEND = 302,                    /* SEND  */
    RECV = 303,                    /* RECV  */
    DEMOTE = 304,                  /* DEMOTE  */
    ENFORCE = 305,                 /* ENFORCE  */
    NEIGHBORAS = 306,              /* NEIGHBORAS  */
    ASOVERRIDE = 307,              /* ASOVERRIDE  */
    REFLECTOR = 308,               /* REFLECTOR  */
    DEPEND = 309,                  /* DEPEND  */
    DOWN = 310,                    /* DOWN  */
    DUMP = 311,                    /* DUMP  */
    IN = 312,                      /* IN  */
    OUT = 313,                     /* OUT  */
    SOCKET = 314,                  /* SOCKET  */
    RESTRICTED = 315,              /* RESTRICTED  */
    LOG = 316,                     /* LOG  */
    TRANSPARENT = 317,             /* TRANSPARENT  */
    TCP = 318,                     /* TCP  */
    MD5SIG = 319,                  /* MD5SIG  */
    PASSWORD = 320,                /* PASSWORD  */
    KEY = 321,                     /* KEY  */
    TTLSECURITY = 322,             /* TTLSECURITY  */
    ALLOW = 323,                   /* ALLOW  */
    DENY = 324,                    /* DENY  */
    MATCH = 325,                   /* MATCH  */
    QUICK = 326,                   /* QUICK  */
    FROM = 327,                    /* FROM  */
    TO = 328,                      /* TO  */
    ANY = 329,                     /* ANY  */
    CONNECTED = 330,               /* CONNECTED  */
    STATIC = 331,                  /* STATIC  */
    COMMUNITY = 332,               /* COMMUNITY  */
    EXTCOMMUNITY = 333,            /* EXTCOMMUNITY  */
    LARGECOMMUNITY = 334,          /* LARGECOMMUNITY  */
    DELETE = 335,                  /* DELETE  */
    PREFIX = 336,                  /* PREFIX  */
    PREFIXLEN = 337,               /* PREFIXLEN  */
    PREFIXSET = 338,               /* PREFIXSET  */
    ROASET = 339,                  /* ROASET  */
    ORIGINSET = 340,               /* ORIGINSET  */
    OVS = 341,                     /* OVS  */
    EXPIRES = 342,                 /* EXPIRES  */
    ASSET = 343,                   /* ASSET  */
    SOURCEAS = 344,                /* SOURCEAS  */
    TRANSITAS = 345,               /* TRANSITAS  */
    PEERAS = 346,                  /* PEERAS  */
    MAXASLEN = 347,                /* MAXASLEN  */
    MAXASSEQ = 348,                /* MAXASSEQ  */
    SET = 349,                     /* SET  */
    LOCALPREF = 350,               /* LOCALPREF  */
    MED = 351,                     /* MED  */
    METRIC = 352,                  /* METRIC  */
    NEXTHOP = 353,                 /* NEXTHOP  */
    REJECT = 354,                  /* REJECT  */
    BLACKHOLE = 355,               /* BLACKHOLE  */
    NOMODIFY = 356,                /* NOMODIFY  */
    SELF = 357,                    /* SELF  */
    PREPEND_SELF = 358,            /* PREPEND_SELF  */
    PREPEND_PEER = 359,            /* PREPEND_PEER  */
    PFTABLE = 360,                 /* PFTABLE  */
    WEIGHT = 361,                  /* WEIGHT  */
    RTLABEL = 362,                 /* RTLABEL  */
    ORIGIN = 363,                  /* ORIGIN  */
    PRIORITY = 364,                /* PRIORITY  */
    ERROR = 365,                   /* ERROR  */
    INCLUDE = 366,                 /* INCLUDE  */
    IPSEC = 367,                   /* IPSEC  */
    ESP = 368,                     /* ESP  */
    AH = 369,                      /* AH  */
    SPI = 370,                     /* SPI  */
    IKE = 371,                     /* IKE  */
    IPV4 = 372,                    /* IPV4  */
    IPV6 = 373,                    /* IPV6  */
    QUALIFY = 374,                 /* QUALIFY  */
    VIA = 375,                     /* VIA  */
    NE = 376,                      /* NE  */
    LE = 377,                      /* LE  */
    GE = 378,                      /* GE  */
    XRANGE = 379,                  /* XRANGE  */
    LONGER = 380,                  /* LONGER  */
    MAXLEN = 381,                  /* MAXLEN  */
    STRING = 382,                  /* STRING  */
    NUMBER = 383                   /* NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AS 258
#define ROUTERID 259
#define HOLDTIME 260
#define YMIN 261
#define LISTEN 262
#define ON 263
#define FIBUPDATE 264
#define FIBPRIORITY 265
#define RTABLE 266
#define NONE 267
#define UNICAST 268
#define VPN 269
#define RD 270
#define EXPORT 271
#define EXPORTTRGT 272
#define IMPORTTRGT 273
#define DEFAULTROUTE 274
#define RDE 275
#define RIB 276
#define EVALUATE 277
#define IGNORE 278
#define COMPARE 279
#define RTR 280
#define PORT 281
#define GROUP 282
#define NEIGHBOR 283
#define NETWORK 284
#define EBGP 285
#define IBGP 286
#define LOCALAS 287
#define REMOTEAS 288
#define DESCR 289
#define LOCALADDR 290
#define MULTIHOP 291
#define PASSIVE 292
#define MAXPREFIX 293
#define RESTART 294
#define ANNOUNCE 295
#define CAPABILITIES 296
#define REFRESH 297
#define AS4BYTE 298
#define CONNECTRETRY 299
#define ENHANCED 300
#define ADDPATH 301
#define SEND 302
#define RECV 303
#define DEMOTE 304
#define ENFORCE 305
#define NEIGHBORAS 306
#define ASOVERRIDE 307
#define REFLECTOR 308
#define DEPEND 309
#define DOWN 310
#define DUMP 311
#define IN 312
#define OUT 313
#define SOCKET 314
#define RESTRICTED 315
#define LOG 316
#define TRANSPARENT 317
#define TCP 318
#define MD5SIG 319
#define PASSWORD 320
#define KEY 321
#define TTLSECURITY 322
#define ALLOW 323
#define DENY 324
#define MATCH 325
#define QUICK 326
#define FROM 327
#define TO 328
#define ANY 329
#define CONNECTED 330
#define STATIC 331
#define COMMUNITY 332
#define EXTCOMMUNITY 333
#define LARGECOMMUNITY 334
#define DELETE 335
#define PREFIX 336
#define PREFIXLEN 337
#define PREFIXSET 338
#define ROASET 339
#define ORIGINSET 340
#define OVS 341
#define EXPIRES 342
#define ASSET 343
#define SOURCEAS 344
#define TRANSITAS 345
#define PEERAS 346
#define MAXASLEN 347
#define MAXASSEQ 348
#define SET 349
#define LOCALPREF 350
#define MED 351
#define METRIC 352
#define NEXTHOP 353
#define REJECT 354
#define BLACKHOLE 355
#define NOMODIFY 356
#define SELF 357
#define PREPEND_SELF 358
#define PREPEND_PEER 359
#define PFTABLE 360
#define WEIGHT 361
#define RTLABEL 362
#define ORIGIN 363
#define PRIORITY 364
#define ERROR 365
#define INCLUDE 366
#define IPSEC 367
#define ESP 368
#define AH 369
#define SPI 370
#define IKE 371
#define IPV4 372
#define IPV6 373
#define QUALIFY 374
#define VIA 375
#define NE 376
#define LE 377
#define GE 378
#define XRANGE 379
#define LONGER 380
#define MAXLEN 381
#define STRING 382
#define NUMBER 383

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AS = 3,                         /* AS  */
  YYSYMBOL_ROUTERID = 4,                   /* ROUTERID  */
  YYSYMBOL_HOLDTIME = 5,                   /* HOLDTIME  */
  YYSYMBOL_YMIN = 6,                       /* YMIN  */
  YYSYMBOL_LISTEN = 7,                     /* LISTEN  */
  YYSYMBOL_ON = 8,                         /* ON  */
  YYSYMBOL_FIBUPDATE = 9,                  /* FIBUPDATE  */
  YYSYMBOL_FIBPRIORITY = 10,               /* FIBPRIORITY  */
  YYSYMBOL_RTABLE = 11,                    /* RTABLE  */
  YYSYMBOL_NONE = 12,                      /* NONE  */
  YYSYMBOL_UNICAST = 13,                   /* UNICAST  */
  YYSYMBOL_VPN = 14,                       /* VPN  */
  YYSYMBOL_RD = 15,                        /* RD  */
  YYSYMBOL_EXPORT = 16,                    /* EXPORT  */
  YYSYMBOL_EXPORTTRGT = 17,                /* EXPORTTRGT  */
  YYSYMBOL_IMPORTTRGT = 18,                /* IMPORTTRGT  */
  YYSYMBOL_DEFAULTROUTE = 19,              /* DEFAULTROUTE  */
  YYSYMBOL_RDE = 20,                       /* RDE  */
  YYSYMBOL_RIB = 21,                       /* RIB  */
  YYSYMBOL_EVALUATE = 22,                  /* EVALUATE  */
  YYSYMBOL_IGNORE = 23,                    /* IGNORE  */
  YYSYMBOL_COMPARE = 24,                   /* COMPARE  */
  YYSYMBOL_RTR = 25,                       /* RTR  */
  YYSYMBOL_PORT = 26,                      /* PORT  */
  YYSYMBOL_GROUP = 27,                     /* GROUP  */
  YYSYMBOL_NEIGHBOR = 28,                  /* NEIGHBOR  */
  YYSYMBOL_NETWORK = 29,                   /* NETWORK  */
  YYSYMBOL_EBGP = 30,                      /* EBGP  */
  YYSYMBOL_IBGP = 31,                      /* IBGP  */
  YYSYMBOL_LOCALAS = 32,                   /* LOCALAS  */
  YYSYMBOL_REMOTEAS = 33,                  /* REMOTEAS  */
  YYSYMBOL_DESCR = 34,                     /* DESCR  */
  YYSYMBOL_LOCALADDR = 35,                 /* LOCALADDR  */
  YYSYMBOL_MULTIHOP = 36,                  /* MULTIHOP  */
  YYSYMBOL_PASSIVE = 37,                   /* PASSIVE  */
  YYSYMBOL_MAXPREFIX = 38,                 /* MAXPREFIX  */
  YYSYMBOL_RESTART = 39,                   /* RESTART  */
  YYSYMBOL_ANNOUNCE = 40,                  /* ANNOUNCE  */
  YYSYMBOL_CAPABILITIES = 41,              /* CAPABILITIES  */
  YYSYMBOL_REFRESH = 42,                   /* REFRESH  */
  YYSYMBOL_AS4BYTE = 43,                   /* AS4BYTE  */
  YYSYMBOL_CONNECTRETRY = 44,              /* CONNECTRETRY  */
  YYSYMBOL_ENHANCED = 45,                  /* ENHANCED  */
  YYSYMBOL_ADDPATH = 46,                   /* ADDPATH  */
  YYSYMBOL_SEND = 47,                      /* SEND  */
  YYSYMBOL_RECV = 48,                      /* RECV  */
  YYSYMBOL_DEMOTE = 49,                    /* DEMOTE  */
  YYSYMBOL_ENFORCE = 50,                   /* ENFORCE  */
  YYSYMBOL_NEIGHBORAS = 51,                /* NEIGHBORAS  */
  YYSYMBOL_ASOVERRIDE = 52,                /* ASOVERRIDE  */
  YYSYMBOL_REFLECTOR = 53,                 /* REFLECTOR  */
  YYSYMBOL_DEPEND = 54,                    /* DEPEND  */
  YYSYMBOL_DOWN = 55,                      /* DOWN  */
  YYSYMBOL_DUMP = 56,                      /* DUMP  */
  YYSYMBOL_IN = 57,                        /* IN  */
  YYSYMBOL_OUT = 58,                       /* OUT  */
  YYSYMBOL_SOCKET = 59,                    /* SOCKET  */
  YYSYMBOL_RESTRICTED = 60,                /* RESTRICTED  */
  YYSYMBOL_LOG = 61,                       /* LOG  */
  YYSYMBOL_TRANSPARENT = 62,               /* TRANSPARENT  */
  YYSYMBOL_TCP = 63,                       /* TCP  */
  YYSYMBOL_MD5SIG = 64,                    /* MD5SIG  */
  YYSYMBOL_PASSWORD = 65,                  /* PASSWORD  */
  YYSYMBOL_KEY = 66,                       /* KEY  */
  YYSYMBOL_TTLSECURITY = 67,               /* TTLSECURITY  */
  YYSYMBOL_ALLOW = 68,                     /* ALLOW  */
  YYSYMBOL_DENY = 69,                      /* DENY  */
  YYSYMBOL_MATCH = 70,                     /* MATCH  */
  YYSYMBOL_QUICK = 71,                     /* QUICK  */
  YYSYMBOL_FROM = 72,                      /* FROM  */
  YYSYMBOL_TO = 73,                        /* TO  */
  YYSYMBOL_ANY = 74,                       /* ANY  */
  YYSYMBOL_CONNECTED = 75,                 /* CONNECTED  */
  YYSYMBOL_STATIC = 76,                    /* STATIC  */
  YYSYMBOL_COMMUNITY = 77,                 /* COMMUNITY  */
  YYSYMBOL_EXTCOMMUNITY = 78,              /* EXTCOMMUNITY  */
  YYSYMBOL_LARGECOMMUNITY = 79,            /* LARGECOMMUNITY  */
  YYSYMBOL_DELETE = 80,                    /* DELETE  */
  YYSYMBOL_PREFIX = 81,                    /* PREFIX  */
  YYSYMBOL_PREFIXLEN = 82,                 /* PREFIXLEN  */
  YYSYMBOL_PREFIXSET = 83,                 /* PREFIXSET  */
  YYSYMBOL_ROASET = 84,                    /* ROASET  */
  YYSYMBOL_ORIGINSET = 85,                 /* ORIGINSET  */
  YYSYMBOL_OVS = 86,                       /* OVS  */
  YYSYMBOL_EXPIRES = 87,                   /* EXPIRES  */
  YYSYMBOL_ASSET = 88,                     /* ASSET  */
  YYSYMBOL_SOURCEAS = 89,                  /* SOURCEAS  */
  YYSYMBOL_TRANSITAS = 90,                 /* TRANSITAS  */
  YYSYMBOL_PEERAS = 91,                    /* PEERAS  */
  YYSYMBOL_MAXASLEN = 92,                  /* MAXASLEN  */
  YYSYMBOL_MAXASSEQ = 93,                  /* MAXASSEQ  */
  YYSYMBOL_SET = 94,                       /* SET  */
  YYSYMBOL_LOCALPREF = 95,                 /* LOCALPREF  */
  YYSYMBOL_MED = 96,                       /* MED  */
  YYSYMBOL_METRIC = 97,                    /* METRIC  */
  YYSYMBOL_NEXTHOP = 98,                   /* NEXTHOP  */
  YYSYMBOL_REJECT = 99,                    /* REJECT  */
  YYSYMBOL_BLACKHOLE = 100,                /* BLACKHOLE  */
  YYSYMBOL_NOMODIFY = 101,                 /* NOMODIFY  */
  YYSYMBOL_SELF = 102,                     /* SELF  */
  YYSYMBOL_PREPEND_SELF = 103,             /* PREPEND_SELF  */
  YYSYMBOL_PREPEND_PEER = 104,             /* PREPEND_PEER  */
  YYSYMBOL_PFTABLE = 105,                  /* PFTABLE  */
  YYSYMBOL_WEIGHT = 106,                   /* WEIGHT  */
  YYSYMBOL_RTLABEL = 107,                  /* RTLABEL  */
  YYSYMBOL_ORIGIN = 108,                   /* ORIGIN  */
  YYSYMBOL_PRIORITY = 109,                 /* PRIORITY  */
  YYSYMBOL_ERROR = 110,                    /* ERROR  */
  YYSYMBOL_INCLUDE = 111,                  /* INCLUDE  */
  YYSYMBOL_IPSEC = 112,                    /* IPSEC  */
  YYSYMBOL_ESP = 113,                      /* ESP  */
  YYSYMBOL_AH = 114,                       /* AH  */
  YYSYMBOL_SPI = 115,                      /* SPI  */
  YYSYMBOL_IKE = 116,                      /* IKE  */
  YYSYMBOL_IPV4 = 117,                     /* IPV4  */
  YYSYMBOL_IPV6 = 118,                     /* IPV6  */
  YYSYMBOL_QUALIFY = 119,                  /* QUALIFY  */
  YYSYMBOL_VIA = 120,                      /* VIA  */
  YYSYMBOL_NE = 121,                       /* NE  */
  YYSYMBOL_LE = 122,                       /* LE  */
  YYSYMBOL_GE = 123,                       /* GE  */
  YYSYMBOL_XRANGE = 124,                   /* XRANGE  */
  YYSYMBOL_LONGER = 125,                   /* LONGER  */
  YYSYMBOL_MAXLEN = 126,                   /* MAXLEN  */
  YYSYMBOL_STRING = 127,                   /* STRING  */
  YYSYMBOL_NUMBER = 128,                   /* NUMBER  */
  YYSYMBOL_129_n_ = 129,                   /* '\n'  */
  YYSYMBOL_130_ = 130,                     /* '='  */
  YYSYMBOL_131_ = 131,                     /* '{'  */
  YYSYMBOL_132_ = 132,                     /* '}'  */
  YYSYMBOL_133_ = 133,                     /* '/'  */
  YYSYMBOL_134_ = 134,                     /* '+'  */
  YYSYMBOL_135_ = 135,                     /* '-'  */
  YYSYMBOL_136_ = 136,                     /* ','  */
  YYSYMBOL_137_ = 137,                     /* '<'  */
  YYSYMBOL_138_ = 138,                     /* '>'  */
  YYSYMBOL_YYACCEPT = 139,                 /* $accept  */
  YYSYMBOL_grammar = 140,                  /* grammar  */
  YYSYMBOL_asnumber = 141,                 /* asnumber  */
  YYSYMBOL_as4number = 142,                /* as4number  */
  YYSYMBOL_as4number_any = 143,            /* as4number_any  */
  YYSYMBOL_string = 144,                   /* string  */
  YYSYMBOL_yesno = 145,                    /* yesno  */
  YYSYMBOL_varset = 146,                   /* varset  */
  YYSYMBOL_include = 147,                  /* include  */
  YYSYMBOL_as_set = 148,                   /* as_set  */
  YYSYMBOL_149_1 = 149,                    /* $@1  */
  YYSYMBOL_as_set_l = 150,                 /* as_set_l  */
  YYSYMBOL_prefixset = 151,                /* prefixset  */
  YYSYMBOL_152_2 = 152,                    /* $@2  */
  YYSYMBOL_prefixset_l = 153,              /* prefixset_l  */
  YYSYMBOL_prefixset_item = 154,           /* prefixset_item  */
  YYSYMBOL_roa_set = 155,                  /* roa_set  */
  YYSYMBOL_156_3 = 156,                    /* $@3  */
  YYSYMBOL_origin_set = 157,               /* origin_set  */
  YYSYMBOL_158_4 = 158,                    /* $@4  */
  YYSYMBOL_expires = 159,                  /* expires  */
  YYSYMBOL_roa_set_l = 160,                /* roa_set_l  */
  YYSYMBOL_rtr = 161,                      /* rtr  */
  YYSYMBOL_162_5 = 162,                    /* $@5  */
  YYSYMBOL_rtropt_l = 163,                 /* rtropt_l  */
  YYSYMBOL_rtropt = 164,                   /* rtropt  */
  YYSYMBOL_conf_main = 165,                /* conf_main  */
  YYSYMBOL_rib = 166,                      /* rib  */
  YYSYMBOL_167_6 = 167,                    /* $@6  */
  YYSYMBOL_ribopts = 168,                  /* ribopts  */
  YYSYMBOL_fibupdate = 169,                /* fibupdate  */
  YYSYMBOL_mrtdump = 170,                  /* mrtdump  */
  YYSYMBOL_network = 171,                  /* network  */
  YYSYMBOL_inout = 172,                    /* inout  */
  YYSYMBOL_restricted = 173,               /* restricted  */
  YYSYMBOL_address = 174,                  /* address  */
  YYSYMBOL_prefix = 175,                   /* prefix  */
  YYSYMBOL_addrspec = 176,                 /* addrspec  */
  YYSYMBOL_optnumber = 177,                /* optnumber  */
  YYSYMBOL_l3vpn = 178,                    /* l3vpn  */
  YYSYMBOL_179_7 = 179,                    /* $@7  */
  YYSYMBOL_l3vpnopts_l = 180,              /* l3vpnopts_l  */
  YYSYMBOL_l3vpnopts = 181,                /* l3vpnopts  */
  YYSYMBOL_neighbor = 182,                 /* neighbor  */
  YYSYMBOL_183_8 = 183,                    /* $@8  */
  YYSYMBOL_184_9 = 184,                    /* $@9  */
  YYSYMBOL_group = 185,                    /* group  */
  YYSYMBOL_186_10 = 186,                   /* $@10  */
  YYSYMBOL_groupopts_l = 187,              /* groupopts_l  */
  YYSYMBOL_peeropts_h = 188,               /* peeropts_h  */
  YYSYMBOL_peeropts_l = 189,               /* peeropts_l  */
  YYSYMBOL_peeropts = 190,                 /* peeropts  */
  YYSYMBOL_restart = 191,                  /* restart  */
  YYSYMBOL_family = 192,                   /* family  */
  YYSYMBOL_safi = 193,                     /* safi  */
  YYSYMBOL_nettype = 194,                  /* nettype  */
  YYSYMBOL_espah = 195,                    /* espah  */
  YYSYMBOL_encspec = 196,                  /* encspec  */
  YYSYMBOL_filterrule = 197,               /* filterrule  */
  YYSYMBOL_action = 198,                   /* action  */
  YYSYMBOL_quick = 199,                    /* quick  */
  YYSYMBOL_direction = 200,                /* direction  */
  YYSYMBOL_filter_rib_h = 201,             /* filter_rib_h  */
  YYSYMBOL_filter_rib_l = 202,             /* filter_rib_l  */
  YYSYMBOL_filter_rib = 203,               /* filter_rib  */
  YYSYMBOL_filter_peer_h = 204,            /* filter_peer_h  */
  YYSYMBOL_filter_peer_l = 205,            /* filter_peer_l  */
  YYSYMBOL_filter_peer = 206,              /* filter_peer  */
  YYSYMBOL_filter_prefix_h = 207,          /* filter_prefix_h  */
  YYSYMBOL_filter_prefix_m = 208,          /* filter_prefix_m  */
  YYSYMBOL_filter_prefix_l = 209,          /* filter_prefix_l  */
  YYSYMBOL_filter_prefix = 210,            /* filter_prefix  */
  YYSYMBOL_filter_as_h = 211,              /* filter_as_h  */
  YYSYMBOL_filter_as_t_l = 212,            /* filter_as_t_l  */
  YYSYMBOL_filter_as_t = 213,              /* filter_as_t  */
  YYSYMBOL_filter_as_l_h = 214,            /* filter_as_l_h  */
  YYSYMBOL_filter_as_l = 215,              /* filter_as_l  */
  YYSYMBOL_filter_as = 216,                /* filter_as  */
  YYSYMBOL_filter_match_h = 217,           /* filter_match_h  */
  YYSYMBOL_218_11 = 218,                   /* $@11  */
  YYSYMBOL_filter_match = 219,             /* filter_match  */
  YYSYMBOL_filter_elm = 220,               /* filter_elm  */
  YYSYMBOL_prefixlenop = 221,              /* prefixlenop  */
  YYSYMBOL_filter_as_type = 222,           /* filter_as_type  */
  YYSYMBOL_filter_set = 223,               /* filter_set  */
  YYSYMBOL_filter_set_l = 224,             /* filter_set_l  */
  YYSYMBOL_community = 225,                /* community  */
  YYSYMBOL_delete = 226,                   /* delete  */
  YYSYMBOL_filter_set_opt = 227,           /* filter_set_opt  */
  YYSYMBOL_origincode = 228,               /* origincode  */
  YYSYMBOL_validity = 229,                 /* validity  */
  YYSYMBOL_optnl = 230,                    /* optnl  */
  YYSYMBOL_comma = 231,                    /* comma  */
  YYSYMBOL_unaryop = 232,                  /* unaryop  */
  YYSYMBOL_equalityop = 233,               /* equalityop  */
  YYSYMBOL_binaryop = 234                  /* binaryop  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   720

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  139
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  318
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  593

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   383


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     129,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   134,   136,   135,     2,   133,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     137,   130,   138,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   131,     2,   132,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   257,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   275,   286,
     318,   328,   355,   360,   366,   369,   384,   412,   427,   427,
     441,   449,   450,   452,   452,   462,   472,   486,   502,   519,
     519,   526,   529,   529,   542,   554,   557,   565,   575,   587,
     596,   596,   608,   609,   611,   622,   630,   640,   647,   651,
     658,   666,   674,   688,   708,   715,   726,   732,   738,   747,
     748,   776,   808,   809,   819,   829,   842,   855,   868,   884,
     891,   907,   907,   917,   918,   927,   936,   937,   945,   975,
     996,  1025,  1044,  1068,  1088,  1089,  1092,  1093,  1096,  1117,
    1135,  1155,  1162,  1165,  1166,  1169,  1169,  1214,  1215,  1216,
    1217,  1220,  1238,  1256,  1274,  1280,  1283,  1284,  1283,  1318,
    1318,  1350,  1351,  1352,  1353,  1354,  1357,  1358,  1359,  1362,
    1363,  1364,  1365,  1368,  1371,  1378,  1382,  1393,  1406,  1416,
    1423,  1426,  1429,  1440,  1456,  1464,  1472,  1491,  1494,  1497,
    1500,  1503,  1506,  1516,  1519,  1522,  1528,  1534,  1549,  1557,
    1565,  1583,  1599,  1609,  1702,  1705,  1712,  1724,  1725,  1735,
    1751,  1763,  1787,  1793,  1804,  1810,  1818,  1833,  1834,  1844,
    1845,  1848,  1849,  1850,  1853,  1854,  1857,  1858,  1861,  1864,
    1897,  1924,  1925,  1926,  1929,  1930,  1933,  1934,  1937,  1938,
    1939,  1941,  1942,  1948,  1970,  1971,  1974,  1975,  1981,  1988,
    2008,  2015,  2036,  2042,  2050,  2065,  2080,  2081,  2084,  2085,
    2086,  2098,  2099,  2105,  2120,  2121,  2124,  2125,  2137,  2141,
    2148,  2171,  2172,  2173,  2186,  2187,  2193,  2201,  2207,  2215,
    2229,  2232,  2232,  2240,  2241,  2244,  2257,  2264,  2276,  2288,
    2306,  2328,  2347,  2355,  2362,  2411,  2431,  2441,  2442,  2448,
    2459,  2502,  2518,  2519,  2520,  2521,  2524,  2525,  2532,  2535,
    2540,  2549,  2550,  2553,  2554,  2557,  2572,  2582,  2592,  2607,
    2617,  2627,  2642,  2652,  2662,  2677,  2687,  2697,  2704,  2709,
    2714,  2719,  2724,  2734,  2744,  2749,  2776,  2790,  2818,  2836,
    2852,  2860,  2875,  2890,  2891,  2894,  2895,  2896,  2897,  2900,
    2901,  2902,  2903,  2904,  2905,  2908,  2909,  2912,  2913
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AS", "ROUTERID",
  "HOLDTIME", "YMIN", "LISTEN", "ON", "FIBUPDATE", "FIBPRIORITY", "RTABLE",
  "NONE", "UNICAST", "VPN", "RD", "EXPORT", "EXPORTTRGT", "IMPORTTRGT",
  "DEFAULTROUTE", "RDE", "RIB", "EVALUATE", "IGNORE", "COMPARE", "RTR",
  "PORT", "GROUP", "NEIGHBOR", "NETWORK", "EBGP", "IBGP", "LOCALAS",
  "REMOTEAS", "DESCR", "LOCALADDR", "MULTIHOP", "PASSIVE", "MAXPREFIX",
  "RESTART", "ANNOUNCE", "CAPABILITIES", "REFRESH", "AS4BYTE",
  "CONNECTRETRY", "ENHANCED", "ADDPATH", "SEND", "RECV", "DEMOTE",
  "ENFORCE", "NEIGHBORAS", "ASOVERRIDE", "REFLECTOR", "DEPEND", "DOWN",
  "DUMP", "IN", "OUT", "SOCKET", "RESTRICTED", "LOG", "TRANSPARENT", "TCP",
  "MD5SIG", "PASSWORD", "KEY", "TTLSECURITY", "ALLOW", "DENY", "MATCH",
  "QUICK", "FROM", "TO", "ANY", "CONNECTED", "STATIC", "COMMUNITY",
  "EXTCOMMUNITY", "LARGECOMMUNITY", "DELETE", "PREFIX", "PREFIXLEN",
  "PREFIXSET", "ROASET", "ORIGINSET", "OVS", "EXPIRES", "ASSET",
  "SOURCEAS", "TRANSITAS", "PEERAS", "MAXASLEN", "MAXASSEQ", "SET",
  "LOCALPREF", "MED", "METRIC", "NEXTHOP", "REJECT", "BLACKHOLE",
  "NOMODIFY", "SELF", "PREPEND_SELF", "PREPEND_PEER", "PFTABLE", "WEIGHT",
  "RTLABEL", "ORIGIN", "PRIORITY", "ERROR", "INCLUDE", "IPSEC", "ESP",
  "AH", "SPI", "IKE", "IPV4", "IPV6", "QUALIFY", "VIA", "NE", "LE", "GE",
  "XRANGE", "LONGER", "MAXLEN", "STRING", "NUMBER", "'\\n'", "'='", "'{'",
  "'}'", "'/'", "'+'", "'-'", "','", "'<'", "'>'", "$accept", "grammar",
  "asnumber", "as4number", "as4number_any", "string", "yesno", "varset",
  "include", "as_set", "$@1", "as_set_l", "prefixset", "$@2",
  "prefixset_l", "prefixset_item", "roa_set", "$@3", "origin_set", "$@4",
  "expires", "roa_set_l", "rtr", "$@5", "rtropt_l", "rtropt", "conf_main",
  "rib", "$@6", "ribopts", "fibupdate", "mrtdump", "network", "inout",
  "restricted", "address", "prefix", "addrspec", "optnumber", "l3vpn",
  "$@7", "l3vpnopts_l", "l3vpnopts", "neighbor", "$@8", "$@9", "group",
  "$@10", "groupopts_l", "peeropts_h", "peeropts_l", "peeropts", "restart",
  "family", "safi", "nettype", "espah", "encspec", "filterrule", "action",
  "quick", "direction", "filter_rib_h", "filter_rib_l", "filter_rib",
  "filter_peer_h", "filter_peer_l", "filter_peer", "filter_prefix_h",
  "filter_prefix_m", "filter_prefix_l", "filter_prefix", "filter_as_h",
  "filter_as_t_l", "filter_as_t", "filter_as_l_h", "filter_as_l",
  "filter_as", "filter_match_h", "$@11", "filter_match", "filter_elm",
  "prefixlenop", "filter_as_type", "filter_set", "filter_set_l",
  "community", "delete", "filter_set_opt", "origincode", "validity",
  "optnl", "comma", "unaryop", "equalityop", "binaryop", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,    10,
      61,   123,   125,    47,    43,    45,    44,    60,    62
};
#endif

#define YYPACT_NINF (-420)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-306)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -420,   472,  -420,   -59,   -35,   -47,    26,    87,    32,    -4,
      50,    37,    36,   -47,    55,   110,    61,     7,    73,    79,
      32,  -420,  -420,  -420,    88,   -13,    99,   107,    93,   153,
     116,   128,  -420,   119,   142,   151,   161,   164,   166,   170,
     172,   188,  -420,  -420,   198,   207,   254,   221,   222,   250,
    -420,  -420,  -420,  -420,   214,  -420,  -420,   224,  -420,   -47,
    -420,  -420,  -420,  -420,   345,   227,   232,   336,   169,   230,
    -420,   235,   238,  -420,  -420,   233,   234,   274,    63,  -420,
     244,    19,   312,  -420,  -420,   242,   245,   246,   247,   259,
      32,  -420,    55,  -420,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,   102,  -420,  -420,  -420,   359,  -420,
    -420,   355,   255,  -420,  -420,   258,  -420,  -420,   256,  -420,
     260,   274,   261,   262,   565,  -420,  -420,  -420,   265,   266,
     274,   268,  -420,  -420,   269,   272,  -420,  -420,   245,   245,
     264,   245,   245,   273,  -420,   235,   233,  -420,  -420,  -420,
      25,    89,   278,  -420,    31,  -420,   245,  -420,  -420,  -420,
    -420,  -420,  -420,   306,  -420,    97,   105,   122,   -28,   281,
     284,   277,   125,   287,   288,   245,   306,  -420,   274,   274,
    -420,   292,  -420,  -420,   269,   279,  -420,  -420,   178,   290,
     293,  -420,   270,  -420,   245,  -420,  -420,  -420,    24,  -420,
     285,    32,   296,   371,  -420,  -420,    53,   276,  -420,   -45,
    -420,   298,   310,  -420,   311,   313,  -420,   314,   315,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,  -420,  -420,   316,   317,
    -420,  -420,  -420,   612,   294,  -420,  -420,   269,  -420,  -420,
     178,   331,    48,   -21,  -420,   178,  -420,   213,   553,  -420,
     327,   -35,   328,  -420,  -420,  -420,   245,  -420,    -9,  -420,
    -420,  -420,   431,  -420,   320,   334,   -47,   245,  -420,   333,
      29,   117,   441,   338,   339,   -35,   -35,    55,   -47,   340,
    -420,   341,    68,   343,    43,    32,   -47,   458,   344,   347,
     351,    32,   416,    32,   580,   396,   231,  -420,  -420,   450,
    -420,   358,   360,   363,   366,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,    48,  -420,  -420,  -420,    48,  -420,   213,
     245,   365,   370,   178,   124,  -420,   367,  -420,    48,  -420,
    -420,  -420,    48,  -420,   372,     4,  -420,  -420,  -420,    22,
     274,   118,    21,  -420,  -420,  -420,  -420,    34,  -420,   375,
    -420,  -420,  -420,   378,  -420,  -420,   214,  -420,   235,  -420,
    -420,    69,    32,    32,    32,    32,   456,   459,   321,  -420,
      32,    32,  -420,  -420,   379,  -420,   289,  -420,  -420,   283,
    -420,   245,  -420,    32,  -420,  -420,   -10,  -420,  -420,  -420,
    -420,  -420,   376,   612,   380,   178,   423,   381,   245,  -420,
     422,  -420,  -420,  -420,   -38,  -420,  -420,  -420,   386,  -420,
     383,   385,   213,   397,  -420,   387,   327,    48,  -420,  -420,
    -420,   -27,   139,   391,   393,   394,  -420,  -420,  -420,   395,
     399,     1,   -21,   -21,    78,  -420,  -420,  -420,   118,  -420,
      14,   398,   401,    32,   405,   408,   410,  -420,  -420,  -420,
     409,  -420,  -420,  -420,  -420,  -420,   411,   483,  -420,  -420,
    -420,  -420,  -420,    32,    32,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,    55,    55,   612,  -420,  -420,   428,  -420,  -420,
    -420,  -420,   417,  -420,  -420,   213,  -420,  -420,   418,  -420,
    -420,  -420,  -420,   415,  -420,  -420,   419,  -420,  -420,   420,
      22,   424,   426,   192,   -21,  -420,   -21,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -420,    85,  -420,  -420,  -420,
     427,  -420,  -420,    92,   -38,  -420,   213,  -420,  -420,  -420,
    -420,   434,   435,  -420,  -420,  -420,  -420,  -420,   235,   235,
      48,   421,  -420,   423,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,   178,   432,   140,  -420,  -420,  -420,   245,  -420,    78,
    -420,    -5,   433,   162,  -420,   213,  -420,  -420,  -420,   440,
     436,  -420,   171,  -420,   178,  -420,  -420,   186,  -420,    -5,
    -420,  -420,   439,   192,  -420,    92,  -420,   448,  -420,  -420,
     449,  -420,  -420
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   192,   193,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    69,     0,     0,     0,     0,     0,   194,
      17,    19,    18,    20,    57,    98,    59,     0,    60,     0,
      25,    65,    64,    78,     0,     0,     0,     0,     0,    49,
      24,   119,     0,   179,   180,     0,     0,   266,     0,    79,
       0,     0,    97,    68,    66,     0,   303,     0,     0,     0,
       0,    27,     0,     4,     5,     6,     7,     8,     9,    10,
      12,    11,    13,    14,     0,    15,    16,   195,   198,    58,
      61,    62,     0,    81,    76,     0,    73,    74,     0,    23,
       0,   266,     0,     0,     0,    89,   185,   184,     0,     0,
     266,     0,    94,    95,   103,     0,    96,    80,   303,   303,
      39,   303,   303,     0,    67,    26,    98,   101,   102,   117,
       0,     0,     0,   105,    86,    75,   303,   121,    90,    99,
     100,   294,   271,   273,   272,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   303,   273,   267,   266,   266,
      93,     0,   104,    70,   103,    33,   304,    41,     0,    42,
      28,    77,   128,   203,   303,   199,   196,   197,     0,    63,
       0,     0,     0,     0,    82,    83,     0,     0,   274,     0,
     275,     0,     0,   278,     0,     0,   281,     0,     0,   289,
     288,   290,   291,   287,   292,   293,   295,   284,     0,     0,
     296,   301,   300,     0,     0,    91,    92,   103,    88,    35,
       0,     0,   305,   257,    44,     0,    30,     0,     0,   118,
       0,     0,     0,   212,   213,   208,   303,   209,   241,   204,
     107,    87,    86,    85,     0,     0,     0,   303,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,   168,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   120,     0,
     167,     0,     0,     0,     0,   276,   277,   279,   280,   282,
     283,   285,   286,   305,   270,   297,    71,   305,    36,     0,
     303,   306,     0,     0,     0,   258,     0,    38,   305,    21,
      22,    31,   305,   129,     0,   303,   201,   210,   211,     0,
     266,     0,     0,    84,    56,    54,    55,     0,   125,     0,
     144,   153,   154,     0,   143,   175,   134,   133,   136,   137,
     139,   177,     0,     0,     0,     0,     0,     0,     0,   171,
       0,     0,   157,   169,     0,   142,     0,   173,   172,     0,
     164,   303,   165,     0,   186,   187,     0,   138,   124,   123,
     299,   298,     0,     0,     0,     0,    45,   307,   303,    40,
       0,   310,   311,   313,     0,   309,   312,   314,     0,   259,
       0,     0,     0,     0,   127,     0,     0,   305,   206,   190,
     262,     0,     0,     0,     0,     0,   263,   264,   265,     0,
       0,     0,   257,   257,     0,   245,   246,   224,   242,   243,
       0,     0,     0,     0,     0,     0,     0,   108,   106,   115,
       0,    51,    53,   145,   176,   135,     0,   177,   158,   150,
     147,   148,   151,     0,     0,   181,   182,   183,   146,   156,
     155,   170,     0,     0,     0,   174,   162,     0,   268,   269,
      34,    37,     0,    47,   308,     0,   318,   317,     0,   260,
      43,    29,    32,     0,   130,   126,     0,   200,   202,     0,
       0,     0,     0,     0,   257,   216,   257,   255,   302,   256,
     247,   248,   253,   252,   214,   215,   305,   226,   244,   237,
       0,   316,   315,     0,   236,   228,     0,   249,   110,   114,
     111,     0,     0,   109,   178,   159,   149,   152,   160,   161,
     305,     0,    46,    45,   261,   132,   131,   205,   207,   251,
     250,     0,     0,   305,   221,   223,   254,   303,   225,     0,
     230,     0,     0,   305,   234,     0,   238,   112,   113,     0,
       0,    48,   305,   217,     0,   307,   227,   305,   229,     0,
     239,   166,     0,   219,   222,   232,   235,   188,   220,   233,
       0,   163,   189
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -420,  -420,    13,  -185,  -241,   -89,    -7,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -420,  -220,  -420,  -420,  -420,  -420,
      35,   302,  -420,  -420,  -420,   203,  -420,  -420,  -420,  -420,
     305,   576,   239,   194,  -420,    -3,   -15,  -420,  -153,  -420,
    -420,  -420,  -420,   377,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -232,   135,   300,  -420,  -420,  -420,  -420,  -420,  -420,
    -420,  -420,  -420,  -420,  -243,  -420,  -420,  -321,  -420,    11,
      44,  -398,  -420,  -420,  -411,    12,    39,  -419,  -420,  -420,
    -420,   158,  -389,  -420,  -116,   130,  -308,   437,  -120,  -420,
    -420,  -130,  -298,  -420,  -420,    74
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,   330,    54,   524,    71,   299,    33,    34,    35,
     247,   332,    36,   240,   317,   241,    37,   188,    38,   245,
     483,   242,    39,   118,   267,   268,    40,    41,   154,   204,
     205,   300,    43,   135,   137,   257,   243,   149,   183,    44,
     200,   342,   450,    45,    46,   192,    47,   120,   207,   249,
     413,   302,   458,    78,   468,   130,   386,   591,    48,    49,
     108,   198,   151,   335,   195,   258,   417,   259,   435,   552,
     553,   554,   436,   516,   437,   562,   563,   564,   340,   341,
     438,   439,   327,   440,   125,   313,   176,   209,   314,   232,
     509,   140,   323,   408,   526,   488
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    61,    56,   145,   177,   158,   331,   336,   185,   186,
      69,   189,   190,    84,   180,   393,   334,    53,   418,   395,
     318,   525,   442,   517,   505,   251,   206,   251,    80,   512,
     443,   238,    57,   441,   412,   349,   444,   416,   445,   446,
     201,   303,   202,   514,   515,   233,   519,   132,   133,   252,
      15,   252,   253,   254,   253,   254,   111,    65,    66,   501,
     264,   324,   235,   236,   250,   519,   337,   109,   265,   266,
      50,   219,   220,   221,   222,   370,   132,   133,   396,   264,
      55,   420,   304,   144,   316,  -240,   486,   265,   266,   148,
     356,   357,    51,    52,   371,    59,   255,   487,   255,    55,
     502,   147,   520,   400,   325,   326,   476,   362,   456,   363,
     364,   365,   322,   366,   367,   555,   521,   556,    86,   500,
    -240,   420,   329,    52,    62,   522,   339,   457,    55,   351,
     441,  -305,    67,   320,    81,   521,   352,   347,   126,   127,
     321,   329,    52,   519,   522,   523,   134,   203,   576,    55,
     447,    55,   193,   448,    58,   256,   194,   350,    60,    60,
     586,   196,   197,    68,    64,   223,   451,   426,   427,   428,
     128,   492,   129,   498,   382,   481,   584,   320,    63,   548,
    -303,   496,    70,   392,   321,    73,    74,   394,   358,    79,
     397,   116,   117,    72,   261,   162,   421,   164,   410,   422,
      82,   423,   411,   424,   425,   415,    83,   426,   427,   428,
     429,   430,    89,   521,   557,    85,   431,   558,   559,   329,
      52,   321,   522,   561,   419,   210,    87,    73,    74,   146,
      76,   211,   212,   213,    88,   432,   433,    75,    76,   214,
     215,    90,   393,    91,   543,   401,   402,   403,    93,   434,
     216,   474,   404,   227,   405,   574,   217,   218,    92,   228,
     229,   406,   407,   346,    53,   579,    75,    76,   484,   557,
     503,    94,  -218,   479,   574,   359,   321,   269,   372,   579,
      95,   270,   104,   373,   378,   566,   380,   499,    53,    53,
      96,   557,   271,    97,  -231,    98,   272,   273,   321,    99,
     557,   100,   274,   583,  -116,    75,    76,   321,   275,   276,
     277,   278,   279,   280,   281,   557,   282,   101,   585,    75,
      76,   107,   321,   551,   580,   283,   284,   102,   285,   286,
     287,   288,   289,   465,   466,   467,   103,   290,   291,   292,
     329,    52,    52,   293,   384,   385,   132,   133,   472,   473,
     105,   106,   110,   112,   113,   459,   460,   461,   462,   114,
     115,   -50,   119,   469,   470,   121,   122,   123,   124,   455,
     294,   131,   136,   138,   139,   295,   475,   141,   142,   143,
     150,   152,   153,   538,   539,   155,   208,   156,   296,   159,
     160,   157,   178,   263,   179,   181,   187,   182,   493,   184,
     191,   248,   270,    60,   226,   297,   199,   504,   298,   224,
     569,   239,   225,   271,   230,   231,   260,   272,   273,   237,
     319,   315,   244,   274,   262,   246,   305,   575,   513,   275,
     276,   277,   278,   279,   280,   281,   529,   282,   306,   307,
     201,   308,   309,   310,   311,   312,   283,   284,   344,   285,
     286,   287,   288,   289,   193,   338,   536,   537,   290,   291,
     292,   345,   348,   353,   293,   354,   374,   355,   360,   361,
     369,   375,     2,     3,   376,     4,     5,     6,   377,     7,
     379,     8,     9,    10,   383,   387,    11,   388,   504,   389,
     390,   294,    12,   391,   398,   409,   295,    13,   463,    14,
    -116,    15,   399,   453,   414,   454,   471,   464,   478,   296,
     482,   485,   480,  -304,   489,   490,    16,   491,   506,   497,
     507,   508,   456,   510,    60,   527,   494,   511,    17,   495,
     528,    18,   530,    19,    20,   531,   504,   532,   533,   534,
      21,    22,    23,   541,   545,   542,   544,   328,   546,   570,
     452,   549,   547,   550,   560,    24,    25,    26,   270,   504,
      27,   567,   568,   582,   573,   578,   587,   343,   504,   271,
      28,    29,   581,   272,   273,   590,   592,    42,   571,   274,
     477,   449,   368,    30,   301,   275,   276,   277,   278,   279,
     280,   281,   535,   282,   588,   572,   518,   589,   565,    31,
     577,    32,   283,   284,   540,   285,   286,   287,   288,   289,
       0,     0,     0,   234,   290,   291,   292,   161,     0,     0,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   163,   164,     0,     0,   294,     0,     0,
       0,     0,   295,     0,     0,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   161,   296,     0,     0,   169,   170,
     171,   172,   173,   174,     0,   165,   166,   167,   168,     0,
      60,     0,   333,   169,   170,   171,   172,   173,   174,   162,
     163,   164,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,   167,
     168,   381,     0,     0,     0,   169,   170,   171,   172,   173,
     174
};

static const yytype_int16 yycheck[] =
{
      15,     8,     5,    92,   124,   121,   247,   250,   138,   139,
      13,   141,   142,    20,   130,   313,   248,     4,   339,   317,
     240,   440,     1,   434,   422,     3,   156,     3,    21,    28,
       9,   184,     6,   341,   332,     6,    15,   335,    17,    18,
       9,    86,    11,   432,   433,   175,    51,    57,    58,    27,
      29,    27,    30,    31,    30,    31,    59,    21,    22,    86,
      26,    82,   178,   179,   194,    51,   251,    54,    34,    35,
     129,    99,   100,   101,   102,    32,    57,    58,   319,    26,
     127,     3,   127,    90,   237,    94,   124,    34,    35,   104,
     275,   276,   127,   128,    51,     8,    74,   135,    74,   127,
     127,   104,    88,   323,   125,   126,   116,    39,    39,    41,
      42,    43,   242,    45,    46,   504,   121,   506,   131,   417,
     129,     3,   127,   128,   128,   130,   256,    58,   127,    12,
     438,   127,    96,   129,   127,   121,    19,   267,    75,    76,
     136,   127,   128,    51,   130,   131,   127,   154,   559,   127,
     129,   127,   127,   132,   128,   131,   131,   128,   127,   127,
     579,    72,    73,   127,   127,   168,   132,    89,    90,    91,
     107,   412,   109,   416,   294,   395,   574,   129,   128,   500,
     132,   413,   127,   313,   136,   117,   118,   317,   277,   128,
     320,    22,    23,    83,   201,    77,    78,    79,   328,    81,
     127,    83,   332,    85,    86,   335,   127,    89,    90,    91,
      92,    93,   119,   121,   129,   127,    98,   132,   516,   127,
     128,   136,   130,   131,   340,   128,   127,   117,   118,   127,
     128,   134,   135,   128,   127,   117,   118,   127,   128,   134,
     135,    88,   540,   127,   485,   121,   122,   123,   129,   131,
     128,   381,   128,   128,   130,   553,   134,   135,   130,   134,
     135,   137,   138,   266,   251,   563,   127,   128,   398,   129,
     131,   129,   132,   393,   572,   278,   136,     1,   285,   577,
     129,     5,    28,   286,   291,   526,   293,   417,   275,   276,
     129,   129,    16,   129,   132,   129,    20,    21,   136,   129,
     129,   129,    26,   132,    28,   127,   128,   136,    32,    33,
      34,    35,    36,    37,    38,   129,    40,   129,   132,   127,
     128,    71,   136,   131,   565,    49,    50,   129,    52,    53,
      54,    55,    56,    12,    13,    14,   129,    61,    62,    63,
     127,   128,   128,    67,   113,   114,    57,    58,    65,    66,
     129,   129,   128,     8,   127,   362,   363,   364,   365,   127,
      24,   131,   127,   370,   371,   127,   133,   133,    94,   356,
      94,   127,    60,   131,   129,    99,   383,   131,   131,   120,
      21,    26,   127,   472,   473,   127,    80,   131,   112,   128,
     128,   131,   127,    22,   128,   127,   132,   128,     1,   127,
     127,   131,     5,   127,   127,   129,   128,   422,   132,   128,
     540,   132,   128,    16,   127,   127,   131,    20,    21,   127,
      89,   127,   132,    26,   128,   132,   128,   557,   431,    32,
      33,    34,    35,    36,    37,    38,   443,    40,   128,   128,
       9,   128,   128,   128,   128,   128,    49,    50,   128,    52,
      53,    54,    55,    56,   127,   127,   463,   464,    61,    62,
      63,   127,   129,    22,    67,   127,     8,   128,   128,   128,
     127,   127,     0,     1,   127,     3,     4,     5,   127,     7,
      64,     9,    10,    11,    88,    35,    14,   129,   503,   129,
     127,    94,    20,   127,   129,   128,    99,    25,    42,    27,
      28,    29,   132,   128,   132,   127,   127,    48,   132,   112,
      87,    89,   132,   132,   128,   132,    44,   132,   127,   132,
     127,   127,    39,   128,   127,   127,   129,   128,    56,   132,
     129,    59,   127,    61,    62,   127,   551,   127,   129,   128,
      68,    69,    70,   115,   129,   128,   128,   245,   129,   128,
     347,   127,   132,   127,   127,    83,    84,    85,     5,   574,
      88,   127,   127,   127,   132,   132,   127,   262,   583,    16,
      98,    99,   132,    20,    21,   127,   127,     1,   543,    26,
     386,   342,   282,   111,   207,    32,    33,    34,    35,    36,
      37,    38,   457,    40,   583,   551,   438,   585,   524,   127,
     561,   129,    49,    50,   474,    52,    53,    54,    55,    56,
      -1,    -1,    -1,   176,    61,    62,    63,    52,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    77,    78,    79,
      95,    96,    97,    98,    52,   112,    -1,    -1,   103,   104,
     105,   106,   107,   108,    -1,    95,    96,    97,    98,    -1,
     127,    -1,   129,   103,   104,   105,   106,   107,   108,    77,
      78,    79,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,   131,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   140,     0,     1,     3,     4,     5,     7,     9,    10,
      11,    14,    20,    25,    27,    29,    44,    56,    59,    61,
      62,    68,    69,    70,    83,    84,    85,    88,    98,    99,
     111,   127,   129,   146,   147,   148,   151,   155,   157,   161,
     165,   166,   170,   171,   178,   182,   183,   185,   197,   198,
     129,   127,   128,   141,   142,   127,   174,     6,   128,     8,
     127,   145,   128,   128,   127,    21,    22,    96,   127,   174,
     127,   144,    83,   117,   118,   127,   128,   175,   192,   128,
      21,   127,   127,   127,   145,   127,   131,   127,   127,   119,
      88,   127,   130,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,    28,   129,   129,    71,   199,   141,
     128,   174,     8,   127,   127,    24,    22,    23,   162,   127,
     186,   127,   133,   133,    94,   223,    75,    76,   107,   109,
     194,   127,    57,    58,   127,   172,    60,   173,   131,   129,
     230,   131,   131,   120,   145,   144,   127,   174,   175,   176,
      21,   201,    26,   127,   167,   127,   131,   131,   223,   128,
     128,    52,    77,    78,    79,    95,    96,    97,    98,   103,
     104,   105,   106,   107,   108,   131,   225,   227,   127,   128,
     223,   127,   128,   177,   127,   230,   230,   132,   156,   230,
     230,   127,   184,   127,   131,   203,    72,    73,   200,   128,
     179,     9,    11,   145,   168,   169,   230,   187,    80,   226,
     128,   134,   135,   128,   134,   135,   128,   134,   135,    99,
     100,   101,   102,   174,   128,   128,   127,   128,   134,   135,
     127,   127,   228,   230,   226,   223,   223,   127,   177,   132,
     152,   154,   160,   175,   132,   158,   132,   149,   131,   188,
     230,     3,    27,    30,    31,    74,   131,   174,   204,   206,
     131,   145,   128,    22,    26,    34,    35,   163,   164,     1,
       5,    16,    20,    21,    26,    32,    33,    34,    35,    36,
      37,    38,    40,    49,    50,    52,    53,    54,    55,    56,
      61,    62,    63,    67,    94,    99,   112,   129,   132,   145,
     170,   182,   190,    86,   127,   128,   128,   128,   128,   128,
     128,   128,   128,   224,   227,   127,   177,   153,   154,    89,
     129,   136,   230,   231,    82,   125,   126,   221,   160,   127,
     141,   143,   150,   129,   190,   202,   203,   142,   127,   230,
     217,   218,   180,   169,   128,   127,   174,   230,   129,     6,
     128,    12,    19,    22,   127,   128,   142,   142,   144,   174,
     128,   128,    39,    41,    42,    43,    45,    46,   192,   127,
      32,    51,   145,   174,     8,   127,   127,   127,   145,    64,
     145,   131,   227,    88,   113,   114,   195,    35,   129,   129,
     127,   127,   230,   231,   230,   231,   143,   230,   129,   132,
     154,   121,   122,   123,   128,   130,   137,   138,   232,   128,
     230,   230,   231,   189,   132,   230,   231,   205,   206,   223,
       3,    78,    81,    83,    85,    86,    89,    90,    91,    92,
      93,    98,   117,   118,   131,   207,   211,   213,   219,   220,
     222,   225,     1,     9,    15,    17,    18,   129,   132,   171,
     181,   132,   164,   128,   127,   141,    39,    58,   191,   145,
     145,   145,   145,    42,    48,    12,    13,    14,   193,   145,
     145,   127,    65,    66,   230,   145,   116,   172,   132,   227,
     132,   154,    87,   159,   230,    89,   124,   135,   234,   128,
     132,   132,   143,     1,   129,   132,   190,   132,   203,   230,
     231,    86,   127,   131,   175,   210,   127,   127,   127,   229,
     128,   128,    28,   174,   221,   221,   212,   213,   220,    51,
      88,   121,   130,   131,   143,   216,   233,   127,   129,   145,
     127,   127,   127,   129,   128,   191,   145,   145,   144,   144,
     224,   115,   128,   143,   128,   129,   129,   132,   206,   127,
     127,   131,   208,   209,   210,   221,   221,   129,   132,   231,
     127,   131,   214,   215,   216,   234,   143,   127,   127,   230,
     128,   159,   209,   132,   231,   230,   213,   215,   132,   231,
     143,   132,   127,   132,   210,   132,   216,   127,   208,   214,
     127,   196,   127
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   139,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   141,   142,
     142,   143,   143,   144,   144,   145,   146,   147,   149,   148,
     148,   150,   150,   152,   151,   151,   153,   153,   154,   156,
     155,   155,   158,   157,   157,   159,   159,   160,   160,   161,
     162,   161,   163,   163,   164,   164,   164,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   167,   166,   168,   168,   168,   169,   169,   170,   171,
     171,   171,   171,   171,   172,   172,   173,   173,   174,   175,
     175,   176,   176,   177,   177,   179,   178,   180,   180,   180,
     180,   181,   181,   181,   181,   181,   183,   184,   182,   186,
     185,   187,   187,   187,   187,   187,   188,   188,   188,   189,
     189,   189,   189,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   191,   191,   192,
     192,   193,   193,   193,   194,   194,   195,   195,   196,   196,
     197,   198,   198,   198,   199,   199,   200,   200,   201,   201,
     201,   202,   202,   203,   204,   204,   205,   205,   206,   206,
     206,   206,   206,   206,   207,   207,   207,   207,   208,   208,
     208,   209,   209,   210,   211,   211,   212,   212,   213,   213,
     213,   214,   214,   214,   215,   215,   216,   216,   216,   216,
     217,   218,   217,   219,   219,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   221,   221,   221,
     221,   221,   222,   222,   222,   222,   223,   223,   223,   224,
     224,   225,   225,   226,   226,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   228,   229,   230,   230,   231,   231,   231,   231,   232,
     232,   232,   232,   232,   232,   233,   233,   234,   234
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     2,     1,     1,     3,     2,     0,     8,
       5,     1,     3,     0,     8,     5,     1,     3,     2,     0,
       7,     4,     0,     8,     5,     0,     2,     4,     6,     2,
       0,     8,     1,     3,     2,     2,     2,     2,     3,     2,
       2,     3,     3,     5,     2,     2,     2,     3,     2,     1,
       4,     6,     1,     3,     3,     4,     3,     4,     2,     2,
       3,     0,     5,     1,     3,     2,     0,     2,     5,     3,
       4,     5,     5,     4,     1,     1,     1,     0,     1,     3,
       3,     1,     1,     0,     1,     0,     8,     0,     2,     3,
       3,     2,     3,     3,     2,     1,     0,     0,     5,     0,
       6,     0,     2,     3,     3,     3,     4,     3,     0,     0,
       2,     3,     3,     2,     2,     3,     2,     2,     2,     2,
       1,     1,     2,     2,     2,     3,     3,     3,     3,     4,
       3,     3,     4,     2,     2,     3,     3,     2,     3,     4,
       4,     4,     3,     8,     2,     2,     6,     1,     1,     2,
       3,     2,     2,     2,     3,     2,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       7,     1,     1,     1,     0,     1,     1,     1,     0,     2,
       6,     1,     3,     1,     1,     5,     1,     3,     1,     1,
       2,     2,     1,     1,     2,     2,     2,     4,     1,     3,
       4,     1,     3,     2,     1,     3,     1,     3,     2,     4,
       3,     1,     3,     4,     1,     3,     1,     1,     2,     3,
       0,     0,     2,     1,     2,     1,     1,     2,     2,     2,
       3,     3,     2,     2,     3,     2,     2,     0,     1,     2,
       3,     4,     1,     1,     1,     1,     0,     2,     6,     3,
       1,     1,     1,     0,     1,     2,     3,     3,     2,     3,
       3,     2,     3,     3,     2,     3,     3,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     3,     4,     4,
       2,     1,     1,     0,     2,     0,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 17: /* grammar: grammar error '\n'  */
#line 272 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { file->errors++; }
#line 2246 "parse.c"
    break;

  case 18: /* asnumber: NUMBER  */
#line 275 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			/*
			 * According to iana 65535 and 4294967295 are reserved
			 * but enforcing this is not duty of the parser.
			 */
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > UINT_MAX) {
				yyerror("AS too big: max %u", UINT_MAX);
				YYERROR;
			}
		}
#line 2261 "parse.c"
    break;

  case 19: /* as4number: STRING  */
#line 286 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			const char	*errstr;
			char		*dot;
			uint32_t	 uvalh = 0, uval;

			if ((dot = strchr((yyvsp[0].v.string),'.')) != NULL) {
				*dot++ = '\0';
				uvalh = strtonum((yyvsp[0].v.string), 0, USHRT_MAX, &errstr);
				if (errstr) {
					yyerror("number %s is %s", (yyvsp[0].v.string), errstr);
					free((yyvsp[0].v.string));
					YYERROR;
				}
				uval = strtonum(dot, 0, USHRT_MAX, &errstr);
				if (errstr) {
					yyerror("number %s is %s", dot, errstr);
					free((yyvsp[0].v.string));
					YYERROR;
				}
				free((yyvsp[0].v.string));
			} else {
				yyerror("AS %s is bad", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			if (uvalh == 0 && (uval == AS_TRANS || uval == 0)) {
				yyerror("AS %u is reserved and may not be used",
				    uval);
				YYERROR;
			}
			(yyval.v.number) = uval | (uvalh << 16);
		}
#line 2298 "parse.c"
    break;

  case 20: /* as4number: asnumber  */
#line 318 "../../../openbgpd-portable/src/bgpd/parse.y"
                           {
			if ((yyvsp[0].v.number) == AS_TRANS || (yyvsp[0].v.number) == 0) {
				yyerror("AS %u is reserved and may not be used",
				    (uint32_t)(yyvsp[0].v.number));
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2311 "parse.c"
    break;

  case 21: /* as4number_any: STRING  */
#line 328 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			const char	*errstr;
			char		*dot;
			uint32_t	 uvalh = 0, uval;

			if ((dot = strchr((yyvsp[0].v.string),'.')) != NULL) {
				*dot++ = '\0';
				uvalh = strtonum((yyvsp[0].v.string), 0, USHRT_MAX, &errstr);
				if (errstr) {
					yyerror("number %s is %s", (yyvsp[0].v.string), errstr);
					free((yyvsp[0].v.string));
					YYERROR;
				}
				uval = strtonum(dot, 0, USHRT_MAX, &errstr);
				if (errstr) {
					yyerror("number %s is %s", dot, errstr);
					free((yyvsp[0].v.string));
					YYERROR;
				}
				free((yyvsp[0].v.string));
			} else {
				yyerror("AS %s is bad", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			(yyval.v.number) = uval | (uvalh << 16);
		}
#line 2343 "parse.c"
    break;

  case 22: /* as4number_any: asnumber  */
#line 355 "../../../openbgpd-portable/src/bgpd/parse.y"
                           {
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2351 "parse.c"
    break;

  case 23: /* string: string STRING  */
#line 360 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (asprintf(&(yyval.v.string), "%s %s", (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1)
				fatal("string: asprintf");
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.string));
		}
#line 2362 "parse.c"
    break;

  case 25: /* yesno: STRING  */
#line 369 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (!strcmp((yyvsp[0].v.string), "yes"))
				(yyval.v.number) = 1;
			else if (!strcmp((yyvsp[0].v.string), "no"))
				(yyval.v.number) = 0;
			else {
				yyerror("syntax error, "
				    "either yes or no expected");
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 2380 "parse.c"
    break;

  case 26: /* varset: STRING '=' string  */
#line 384 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			char *s = (yyvsp[-2].v.string);
			if (strlen((yyvsp[-2].v.string)) >= MACRO_NAME_LEN) {
				yyerror("macro name to long, max %d characters",
				    MACRO_NAME_LEN - 1);
				free((yyvsp[-2].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			do {
				if (isalnum((unsigned char)*s) || *s == '_')
					continue;
				yyerror("macro name can only contain "
					    "alphanumerics and '_'");
				free((yyvsp[-2].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			} while (*++s);

			if (cmd_opts & BGPD_OPT_VERBOSE)
				printf("%s = \"%s\"\n", (yyvsp[-2].v.string), (yyvsp[0].v.string));
			if (symset((yyvsp[-2].v.string), (yyvsp[0].v.string), 0) == -1)
				fatal("cannot store variable");
			free((yyvsp[-2].v.string));
			free((yyvsp[0].v.string));
		}
#line 2411 "parse.c"
    break;

  case 27: /* include: INCLUDE STRING  */
#line 412 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			struct file	*nfile;

			if ((nfile = pushfile((yyvsp[0].v.string), 1)) == NULL) {
				yyerror("failed to include file %s", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));

			file = nfile;
			lungetc('\n');
		}
#line 2429 "parse.c"
    break;

  case 28: /* $@1: %empty  */
#line 427 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (strlen((yyvsp[-2].v.string)) >= SET_NAME_LEN) {
				yyerror("as-set name %s too long", (yyvsp[-2].v.string));
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			if (new_as_set((yyvsp[-2].v.string)) != 0) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			free((yyvsp[-2].v.string));
		}
#line 2446 "parse.c"
    break;

  case 29: /* as_set: ASSET STRING '{' optnl $@1 as_set_l optnl '}'  */
#line 438 "../../../openbgpd-portable/src/bgpd/parse.y"
                                     {
			done_as_set();
		}
#line 2454 "parse.c"
    break;

  case 30: /* as_set: ASSET STRING '{' optnl '}'  */
#line 441 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (new_as_set((yyvsp[-3].v.string)) != 0) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
		}
#line 2466 "parse.c"
    break;

  case 31: /* as_set_l: as4number_any  */
#line 449 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { add_as_set((yyvsp[0].v.number)); }
#line 2472 "parse.c"
    break;

  case 32: /* as_set_l: as_set_l comma as4number_any  */
#line 450 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { add_as_set((yyvsp[0].v.number)); }
#line 2478 "parse.c"
    break;

  case 33: /* $@2: %empty  */
#line 452 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curpset = new_prefix_set((yyvsp[-2].v.string), 0)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			free((yyvsp[-2].v.string));
		}
#line 2490 "parse.c"
    break;

  case 34: /* prefixset: PREFIXSET STRING '{' optnl $@2 prefixset_l optnl '}'  */
#line 458 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2499 "parse.c"
    break;

  case 35: /* prefixset: PREFIXSET STRING '{' optnl '}'  */
#line 462 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curpset = new_prefix_set((yyvsp[-3].v.string), 0)) == NULL) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2513 "parse.c"
    break;

  case 36: /* prefixset_l: prefixset_item  */
#line 472 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			struct prefixset_item	*psi;
			if ((yyvsp[0].v.prefixset_item)->p.op != OP_NONE)
				curpset->sflags |= PREFIXSET_FLAG_OPS;
			psi = RB_INSERT(prefixset_tree, &curpset->psitems, (yyvsp[0].v.prefixset_item));
			if (psi != NULL) {
				if (cmd_opts & BGPD_OPT_VERBOSE2)
					log_warnx("warning: duplicate entry in "
					    "prefixset \"%s\" for %s/%u",
					    curpset->name,
					    log_addr(&(yyvsp[0].v.prefixset_item)->p.addr), (yyvsp[0].v.prefixset_item)->p.len);
				free((yyvsp[0].v.prefixset_item));
			}
		}
#line 2532 "parse.c"
    break;

  case 37: /* prefixset_l: prefixset_l comma prefixset_item  */
#line 486 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			struct prefixset_item	*psi;
			if ((yyvsp[0].v.prefixset_item)->p.op != OP_NONE)
				curpset->sflags |= PREFIXSET_FLAG_OPS;
			psi = RB_INSERT(prefixset_tree, &curpset->psitems, (yyvsp[0].v.prefixset_item));
			if (psi != NULL) {
				if (cmd_opts & BGPD_OPT_VERBOSE2)
					log_warnx("warning: duplicate entry in "
					    "prefixset \"%s\" for %s/%u",
					    curpset->name,
					    log_addr(&(yyvsp[0].v.prefixset_item)->p.addr), (yyvsp[0].v.prefixset_item)->p.len);
				free((yyvsp[0].v.prefixset_item));
			}
		}
#line 2551 "parse.c"
    break;

  case 38: /* prefixset_item: prefix prefixlenop  */
#line 502 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((yyvsp[0].v.prefixlen).op != OP_NONE && (yyvsp[0].v.prefixlen).op != OP_RANGE) {
				yyerror("unsupported prefixlen operation in "
				    "prefix-set");
				YYERROR;
			}
			if (((yyval.v.prefixset_item) = calloc(1, sizeof(*(yyval.v.prefixset_item)))) == NULL)
				fatal(NULL);
			memcpy(&(yyval.v.prefixset_item)->p.addr, &(yyvsp[-1].v.prefix).prefix, sizeof((yyval.v.prefixset_item)->p.addr));
			(yyval.v.prefixset_item)->p.len = (yyvsp[-1].v.prefix).len;
			if (merge_prefixspec(&(yyval.v.prefixset_item)->p, &(yyvsp[0].v.prefixlen)) == -1) {
				free((yyval.v.prefixset_item));
				YYERROR;
			}
		}
#line 2571 "parse.c"
    break;

  case 39: /* $@3: %empty  */
#line 519 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			curroatree = &conf->roa;
			noexpires = 0;
		}
#line 2580 "parse.c"
    break;

  case 40: /* roa_set: ROASET '{' optnl $@3 roa_set_l optnl '}'  */
#line 522 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			curroatree = NULL;
			noexpires = 1;
		}
#line 2589 "parse.c"
    break;

  case 42: /* $@4: %empty  */
#line 529 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curoset = new_prefix_set((yyvsp[-2].v.string), 1)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			curroatree = &curoset->roaitems;
			noexpires = 1;
			free((yyvsp[-2].v.string));
		}
#line 2603 "parse.c"
    break;

  case 43: /* origin_set: ORIGINSET STRING '{' optnl $@4 roa_set_l optnl '}'  */
#line 537 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			SIMPLEQ_INSERT_TAIL(&conf->originsets, curoset, entry);
			curoset = NULL;
			curroatree = NULL;
		}
#line 2613 "parse.c"
    break;

  case 44: /* origin_set: ORIGINSET STRING '{' optnl '}'  */
#line 542 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			if ((curoset = new_prefix_set((yyvsp[-3].v.string), 1)) == NULL) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
			SIMPLEQ_INSERT_TAIL(&conf->originsets, curoset, entry);
			curoset = NULL;
			curroatree = NULL;
		}
#line 2628 "parse.c"
    break;

  case 45: /* expires: %empty  */
#line 554 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			(yyval.v.number) = 0;
		}
#line 2636 "parse.c"
    break;

  case 46: /* expires: EXPIRES NUMBER  */
#line 557 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (noexpires) {
				yyerror("syntax error, expires not allowed");
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2648 "parse.c"
    break;

  case 47: /* roa_set_l: prefixset_item SOURCEAS as4number_any expires  */
#line 565 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                        {
			if ((yyvsp[-3].v.prefixset_item)->p.len_min != (yyvsp[-3].v.prefixset_item)->p.len) {
				yyerror("unsupported prefixlen operation in "
				    "roa-set");
				free((yyvsp[-3].v.prefixset_item));
				YYERROR;
			}
			add_roa_set((yyvsp[-3].v.prefixset_item), (yyvsp[-1].v.number), (yyvsp[-3].v.prefixset_item)->p.len_max, (yyvsp[0].v.number));
			free((yyvsp[-3].v.prefixset_item));
		}
#line 2663 "parse.c"
    break;

  case 48: /* roa_set_l: roa_set_l comma prefixset_item SOURCEAS as4number_any expires  */
#line 575 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                                {
			if ((yyvsp[-3].v.prefixset_item)->p.len_min != (yyvsp[-3].v.prefixset_item)->p.len) {
				yyerror("unsupported prefixlen operation in "
				    "roa-set");
				free((yyvsp[-3].v.prefixset_item));
				YYERROR;
			}
			add_roa_set((yyvsp[-3].v.prefixset_item), (yyvsp[-1].v.number), (yyvsp[-3].v.prefixset_item)->p.len_max, (yyvsp[0].v.number));
			free((yyvsp[-3].v.prefixset_item));
		}
#line 2678 "parse.c"
    break;

  case 49: /* rtr: RTR address  */
#line 587 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = RTR_PORT;
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2692 "parse.c"
    break;

  case 50: /* $@5: %empty  */
#line 596 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = RTR_PORT;
		}
#line 2701 "parse.c"
    break;

  case 51: /* rtr: RTR address $@5 '{' optnl rtropt_l optnl '}'  */
#line 599 "../../../openbgpd-portable/src/bgpd/parse.y"
                                               {
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2713 "parse.c"
    break;

  case 54: /* rtropt: DESCR STRING  */
#line 611 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (strlcpy(currtr->descr, (yyvsp[0].v.string),
			    sizeof(currtr->descr)) >=
			    sizeof(currtr->descr)) {
				yyerror("descr \"%s\" too long: max %zu",
				    (yyvsp[0].v.string), sizeof(currtr->descr) - 1);
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 2729 "parse.c"
    break;

  case 55: /* rtropt: LOCALADDR address  */
#line 622 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.addr).aid != currtr->remote_addr.aid) {
				yyerror("Bad address family %s for "
				    "local-addr", aid2str((yyvsp[0].v.addr).aid));
				YYERROR;
			}
			currtr->local_addr = (yyvsp[0].v.addr);
		}
#line 2742 "parse.c"
    break;

  case 56: /* rtropt: PORT NUMBER  */
#line 630 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("port must be between %u and %u",
				    1, USHRT_MAX);
				YYERROR;
			}
			currtr->remote_port = (yyvsp[0].v.number);
		}
#line 2755 "parse.c"
    break;

  case 57: /* conf_main: AS as4number  */
#line 640 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			conf->as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				conf->short_as = AS_TRANS;
			else
				conf->short_as = (yyvsp[0].v.number);
		}
#line 2767 "parse.c"
    break;

  case 58: /* conf_main: AS as4number asnumber  */
#line 647 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			conf->as = (yyvsp[-1].v.number);
			conf->short_as = (yyvsp[0].v.number);
		}
#line 2776 "parse.c"
    break;

  case 59: /* conf_main: ROUTERID address  */
#line 651 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.addr).aid != AID_INET) {
				yyerror("router-id must be an IPv4 address");
				YYERROR;
			}
			conf->bgpid = (yyvsp[0].v.addr).v4.s_addr;
		}
#line 2788 "parse.c"
    break;

  case 60: /* conf_main: HOLDTIME NUMBER  */
#line 658 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->holdtime = (yyvsp[0].v.number);
		}
#line 2801 "parse.c"
    break;

  case 61: /* conf_main: HOLDTIME YMIN NUMBER  */
#line 666 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->min_holdtime = (yyvsp[0].v.number);
		}
#line 2814 "parse.c"
    break;

  case 62: /* conf_main: LISTEN ON address  */
#line 674 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			struct listen_addr	*la;
			struct sockaddr		*sa;

			if ((la = calloc(1, sizeof(struct listen_addr))) ==
			    NULL)
				fatal("parse conf_main listen on calloc");

			la->fd = -1;
			la->reconf = RECONF_REINIT;
			sa = addr2sa(&(yyvsp[0].v.addr), BGP_PORT, &la->sa_len);
			memcpy(&la->sa, sa, la->sa_len);
			TAILQ_INSERT_TAIL(conf->listen_addrs, la, entry);
		}
#line 2833 "parse.c"
    break;

  case 63: /* conf_main: LISTEN ON address PORT NUMBER  */
#line 688 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			struct listen_addr	*la;
			struct sockaddr		*sa;

			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("port must be between %u and %u",
				    1, USHRT_MAX);
				YYERROR;
			}

			if ((la = calloc(1, sizeof(struct listen_addr))) ==
			    NULL)
				fatal("parse conf_main listen on calloc");

			la->fd = -1;
			la->reconf = RECONF_REINIT;
			sa = addr2sa(&(yyvsp[-2].v.addr), (yyvsp[0].v.number), &la->sa_len);
			memcpy(&la->sa, sa, la->sa_len);
			TAILQ_INSERT_TAIL(conf->listen_addrs, la, entry);
		}
#line 2858 "parse.c"
    break;

  case 64: /* conf_main: FIBPRIORITY NUMBER  */
#line 708 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) <= RTP_NONE || (yyvsp[0].v.number) > RTP_MAX) {
				yyerror("invalid fib-priority");
				YYERROR;
			}
			conf->fib_priority = (yyvsp[0].v.number);
		}
#line 2870 "parse.c"
    break;

  case 65: /* conf_main: FIBUPDATE yesno  */
#line 715 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			struct rde_rib *rr;
			rr = find_rib("Loc-RIB");
			if (rr == NULL)
				fatalx("RTABLE can not find the main RIB!");

			if ((yyvsp[0].v.number) == 0)
				rr->flags |= F_RIB_NOFIBSYNC;
			else
				rr->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 2886 "parse.c"
    break;

  case 66: /* conf_main: TRANSPARENT yesno  */
#line 726 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_DECISION_TRANS_AS;
			else
				conf->flags &= ~BGPD_FLAG_DECISION_TRANS_AS;
		}
#line 2897 "parse.c"
    break;

  case 67: /* conf_main: REJECT ASSET yesno  */
#line 732 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_NO_AS_SET;
			else
				conf->flags &= ~BGPD_FLAG_NO_AS_SET;
		}
#line 2908 "parse.c"
    break;

  case 68: /* conf_main: LOG STRING  */
#line 738 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (!strcmp((yyvsp[0].v.string), "updates"))
				conf->log |= BGPD_LOG_UPDATES;
			else {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 2922 "parse.c"
    break;

  case 70: /* conf_main: DUMP STRING STRING optnumber  */
#line 748 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			int action;

			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT_MAX) {
				yyerror("bad timeout");
				free((yyvsp[-2].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			if (!strcmp((yyvsp[-2].v.string), "table"))
				action = MRT_TABLE_DUMP;
			else if (!strcmp((yyvsp[-2].v.string), "table-mp"))
				action = MRT_TABLE_DUMP_MP;
			else if (!strcmp((yyvsp[-2].v.string), "table-v2"))
				action = MRT_TABLE_DUMP_V2;
			else {
				yyerror("unknown mrt dump type");
				free((yyvsp[-2].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			free((yyvsp[-2].v.string));
			if (add_mrtconfig(action, (yyvsp[-1].v.string), (yyvsp[0].v.number), NULL, NULL) == -1) {
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			free((yyvsp[-1].v.string));
		}
#line 2955 "parse.c"
    break;

  case 71: /* conf_main: DUMP RIB STRING STRING STRING optnumber  */
#line 776 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                        {
			int action;

			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT_MAX) {
				yyerror("bad timeout");
				free((yyvsp[-3].v.string));
				free((yyvsp[-2].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			if (!strcmp((yyvsp[-2].v.string), "table"))
				action = MRT_TABLE_DUMP;
			else if (!strcmp((yyvsp[-2].v.string), "table-mp"))
				action = MRT_TABLE_DUMP_MP;
			else if (!strcmp((yyvsp[-2].v.string), "table-v2"))
				action = MRT_TABLE_DUMP_V2;
			else {
				yyerror("unknown mrt dump type");
				free((yyvsp[-3].v.string));
				free((yyvsp[-2].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			free((yyvsp[-2].v.string));
			if (add_mrtconfig(action, (yyvsp[-1].v.string), (yyvsp[0].v.number), NULL, (yyvsp[-3].v.string)) == -1) {
				free((yyvsp[-3].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
			free((yyvsp[-1].v.string));
		}
#line 2992 "parse.c"
    break;

  case 73: /* conf_main: RDE STRING EVALUATE  */
#line 809 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (!strcmp((yyvsp[-1].v.string), "route-age"))
				conf->flags |= BGPD_FLAG_DECISION_ROUTEAGE;
			else {
				yyerror("unknown route decision type");
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			free((yyvsp[-1].v.string));
		}
#line 3007 "parse.c"
    break;

  case 74: /* conf_main: RDE STRING IGNORE  */
#line 819 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (!strcmp((yyvsp[-1].v.string), "route-age"))
				conf->flags &= ~BGPD_FLAG_DECISION_ROUTEAGE;
			else {
				yyerror("unknown route decision type");
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			free((yyvsp[-1].v.string));
		}
#line 3022 "parse.c"
    break;

  case 75: /* conf_main: RDE MED COMPARE STRING  */
#line 829 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (!strcmp((yyvsp[0].v.string), "always"))
				conf->flags |= BGPD_FLAG_DECISION_MED_ALWAYS;
			else if (!strcmp((yyvsp[0].v.string), "strict"))
				conf->flags &= ~BGPD_FLAG_DECISION_MED_ALWAYS;
			else {
				yyerror("rde med compare: "
				    "unknown setting \"%s\"", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 3040 "parse.c"
    break;

  case 76: /* conf_main: RDE EVALUATE STRING  */
#line 842 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			if (!strcmp((yyvsp[0].v.string), "all"))
				conf->flags |= BGPD_FLAG_DECISION_ALL_PATHS;
			else if (!strcmp((yyvsp[0].v.string), "default"))
				conf->flags &= ~BGPD_FLAG_DECISION_ALL_PATHS;
			else {
				yyerror("rde evaluate: "
				    "unknown setting \"%s\"", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 3058 "parse.c"
    break;

  case 77: /* conf_main: NEXTHOP QUALIFY VIA STRING  */
#line 855 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (!strcmp((yyvsp[0].v.string), "bgp"))
				conf->flags |= BGPD_FLAG_NEXTHOP_BGP;
			else if (!strcmp((yyvsp[0].v.string), "default"))
				conf->flags |= BGPD_FLAG_NEXTHOP_DEFAULT;
			else {
				yyerror("nexthop depend on: "
				    "unknown setting \"%s\"", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 3076 "parse.c"
    break;

  case 78: /* conf_main: RTABLE NUMBER  */
#line 868 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			struct rde_rib *rr;
			if ((yyvsp[0].v.number) > RT_TABLEID_MAX) {
				yyerror("rtable %llu too big: max %u", (yyvsp[0].v.number),
				    RT_TABLEID_MAX);
				YYERROR;
			}
			if (ktable_exists((yyvsp[0].v.number), NULL) != 1) {
				yyerror("rtable id %lld does not exist", (yyvsp[0].v.number));
				YYERROR;
			}
			rr = find_rib("Loc-RIB");
			if (rr == NULL)
				fatalx("RTABLE can not find the main RIB!");
			rr->rtableid = (yyvsp[0].v.number);
		}
#line 3097 "parse.c"
    break;

  case 79: /* conf_main: CONNECTRETRY NUMBER  */
#line 884 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			if ((yyvsp[0].v.number) > USHRT_MAX || (yyvsp[0].v.number) < 1) {
				yyerror("invalid connect-retry");
				YYERROR;
			}
			conf->connectretry = (yyvsp[0].v.number);
		}
#line 3109 "parse.c"
    break;

  case 80: /* conf_main: SOCKET STRING restricted  */
#line 891 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if (strlen((yyvsp[-1].v.string)) >=
			    sizeof(((struct sockaddr_un *)0)->sun_path)) {
				yyerror("socket path too long");
				YYERROR;
			}
			if ((yyvsp[0].v.number)) {
				free(conf->rcsock);
				conf->rcsock = (yyvsp[-1].v.string);
			} else {
				free(conf->csock);
				conf->csock = (yyvsp[-1].v.string);
			}
		}
#line 3128 "parse.c"
    break;

  case 81: /* $@6: %empty  */
#line 907 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if ((currib = add_rib((yyvsp[0].v.string))) == NULL) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 3140 "parse.c"
    break;

  case 82: /* rib: RDE RIB STRING $@6 ribopts  */
#line 913 "../../../openbgpd-portable/src/bgpd/parse.y"
                          {
			currib = NULL;
		}
#line 3148 "parse.c"
    break;

  case 84: /* ribopts: RTABLE NUMBER fibupdate  */
#line 918 "../../../openbgpd-portable/src/bgpd/parse.y"
                                          {
			if ((yyvsp[-1].v.number) > RT_TABLEID_MAX) {
				yyerror("rtable %llu too big: max %u", (yyvsp[-1].v.number),
				    RT_TABLEID_MAX);
				YYERROR;
			}
			if (rib_add_fib(currib, (yyvsp[-1].v.number)) == -1)
				YYERROR;
		}
#line 3162 "parse.c"
    break;

  case 85: /* ribopts: yesno EVALUATE  */
#line 927 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if ((yyvsp[-1].v.number)) {
				yyerror("bad rde rib definition");
				YYERROR;
			}
			currib->flags |= F_RIB_NOEVALUATE;
		}
#line 3174 "parse.c"
    break;

  case 87: /* fibupdate: FIBUPDATE yesno  */
#line 937 "../../../openbgpd-portable/src/bgpd/parse.y"
                                  {
			if ((yyvsp[0].v.number) == 0)
				currib->flags |= F_RIB_NOFIBSYNC;
			else
				currib->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3185 "parse.c"
    break;

  case 88: /* mrtdump: DUMP STRING inout STRING optnumber  */
#line 945 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			int action;

			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT_MAX) {
				yyerror("bad timeout");
				free((yyvsp[-3].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			if (!strcmp((yyvsp[-3].v.string), "all"))
				action = (yyvsp[-2].v.number) ? MRT_ALL_IN : MRT_ALL_OUT;
			else if (!strcmp((yyvsp[-3].v.string), "updates"))
				action = (yyvsp[-2].v.number) ? MRT_UPDATE_IN : MRT_UPDATE_OUT;
			else {
				yyerror("unknown mrt msg dump type");
				free((yyvsp[-3].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			if (add_mrtconfig(action, (yyvsp[-1].v.string), (yyvsp[0].v.number), curpeer, NULL) ==
			    -1) {
				free((yyvsp[-3].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
			free((yyvsp[-1].v.string));
		}
#line 3218 "parse.c"
    break;

  case 89: /* network: NETWORK prefix filter_set  */
#line 975 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			struct network	*n, *m;

			if ((n = calloc(1, sizeof(struct network))) == NULL)
				fatal("new_network");
			memcpy(&n->net.prefix, &(yyvsp[-1].v.prefix).prefix,
			    sizeof(n->net.prefix));
			n->net.prefixlen = (yyvsp[-1].v.prefix).len;
			filterset_move((yyvsp[0].v.filter_set_head), &n->net.attrset);
			free((yyvsp[0].v.filter_set_head));
			TAILQ_FOREACH(m, netconf, entry) {
				if (n->net.type == m->net.type &&
				    n->net.prefixlen == m->net.prefixlen &&
				    prefix_compare(&n->net.prefix,
				    &m->net.prefix, n->net.prefixlen) == 0)
					yyerror("duplicate prefix "
					    "in network statement");
			}

			TAILQ_INSERT_TAIL(netconf, n, entry);
		}
#line 3244 "parse.c"
    break;

  case 90: /* network: NETWORK PREFIXSET STRING filter_set  */
#line 996 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			struct prefixset *ps;
			struct network	*n;
			if ((ps = find_prefixset((yyvsp[-1].v.string), &conf->prefixsets))
			    == NULL) {
				yyerror("prefix-set '%s' not defined", (yyvsp[-1].v.string));
				free((yyvsp[-1].v.string));
				filterset_free((yyvsp[0].v.filter_set_head));
				free((yyvsp[0].v.filter_set_head));
				YYERROR;
			}
			if (ps->sflags & PREFIXSET_FLAG_OPS) {
				yyerror("prefix-set %s has prefixlen operators "
				    "and cannot be used in network statements.",
				    ps->name);
				free((yyvsp[-1].v.string));
				filterset_free((yyvsp[0].v.filter_set_head));
				free((yyvsp[0].v.filter_set_head));
				YYERROR;
			}
			if ((n = calloc(1, sizeof(struct network))) == NULL)
				fatal("new_network");
			strlcpy(n->net.psname, ps->name, sizeof(n->net.psname));
			filterset_move((yyvsp[0].v.filter_set_head), &n->net.attrset);
			n->net.type = NETWORK_PREFIXSET;
			TAILQ_INSERT_TAIL(netconf, n, entry);
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.filter_set_head));
		}
#line 3278 "parse.c"
    break;

  case 91: /* network: NETWORK family RTLABEL STRING filter_set  */
#line 1025 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			struct network	*n;

			if ((n = calloc(1, sizeof(struct network))) == NULL)
				fatal("new_network");
			if (afi2aid((yyvsp[-3].v.number), SAFI_UNICAST, &n->net.prefix.aid) ==
			    -1) {
				yyerror("unknown family");
				filterset_free((yyvsp[0].v.filter_set_head));
				free((yyvsp[0].v.filter_set_head));
				YYERROR;
			}
			n->net.type = NETWORK_RTLABEL;
			n->net.rtlabel = rtlabel_name2id((yyvsp[-1].v.string));
			filterset_move((yyvsp[0].v.filter_set_head), &n->net.attrset);
			free((yyvsp[0].v.filter_set_head));

			TAILQ_INSERT_TAIL(netconf, n, entry);
		}
#line 3302 "parse.c"
    break;

  case 92: /* network: NETWORK family PRIORITY NUMBER filter_set  */
#line 1044 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			struct network	*n;
			if ((yyvsp[-1].v.number) < RTP_LOCAL && (yyvsp[-1].v.number) > RTP_MAX) {
				yyerror("priority %lld > max %d or < min %d", (yyvsp[-1].v.number),
				    RTP_MAX, RTP_LOCAL);
				YYERROR;
			}

			if ((n = calloc(1, sizeof(struct network))) == NULL)
				fatal("new_network");
			if (afi2aid((yyvsp[-3].v.number), SAFI_UNICAST, &n->net.prefix.aid) ==
			    -1) {
				yyerror("unknown family");
				filterset_free((yyvsp[0].v.filter_set_head));
				free((yyvsp[0].v.filter_set_head));
				YYERROR;
			}
			n->net.type = NETWORK_PRIORITY;
			n->net.priority = (yyvsp[-1].v.number);
			filterset_move((yyvsp[0].v.filter_set_head), &n->net.attrset);
			free((yyvsp[0].v.filter_set_head));

			TAILQ_INSERT_TAIL(netconf, n, entry);
		}
#line 3331 "parse.c"
    break;

  case 93: /* network: NETWORK family nettype filter_set  */
#line 1068 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			struct network	*n;

			if ((n = calloc(1, sizeof(struct network))) == NULL)
				fatal("new_network");
			if (afi2aid((yyvsp[-2].v.number), SAFI_UNICAST, &n->net.prefix.aid) ==
			    -1) {
				yyerror("unknown family");
				filterset_free((yyvsp[0].v.filter_set_head));
				free((yyvsp[0].v.filter_set_head));
				YYERROR;
			}
			n->net.type = (yyvsp[-1].v.number) ? NETWORK_STATIC : NETWORK_CONNECTED;
			filterset_move((yyvsp[0].v.filter_set_head), &n->net.attrset);
			free((yyvsp[0].v.filter_set_head));

			TAILQ_INSERT_TAIL(netconf, n, entry);
		}
#line 3354 "parse.c"
    break;

  case 94: /* inout: IN  */
#line 1088 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 3360 "parse.c"
    break;

  case 95: /* inout: OUT  */
#line 1089 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 3366 "parse.c"
    break;

  case 96: /* restricted: RESTRICTED  */
#line 1092 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 3372 "parse.c"
    break;

  case 97: /* restricted: %empty  */
#line 1093 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 3378 "parse.c"
    break;

  case 98: /* address: STRING  */
#line 1096 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			uint8_t	len;

			if (!host((yyvsp[0].v.string), &(yyval.v.addr), &len)) {
				yyerror("could not parse address spec \"%s\"",
				    (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));

			if (((yyval.v.addr).aid == AID_INET && len != 32) ||
			    ((yyval.v.addr).aid == AID_INET6 && len != 128)) {
				/* unreachable */
				yyerror("got prefixlen %u, expected %u",
				    len, (yyval.v.addr).aid == AID_INET ? 32 : 128);
				YYERROR;
			}
		}
#line 3402 "parse.c"
    break;

  case 99: /* prefix: STRING '/' NUMBER  */
#line 1117 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			char	*s;
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > 128) {
				yyerror("bad prefixlen %lld", (yyvsp[0].v.number));
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			if (asprintf(&s, "%s/%lld", (yyvsp[-2].v.string), (yyvsp[0].v.number)) == -1)
				fatal(NULL);
			free((yyvsp[-2].v.string));

			if (!host(s, &(yyval.v.prefix).prefix, &(yyval.v.prefix).len)) {
				yyerror("could not parse address \"%s\"", s);
				free(s);
				YYERROR;
			}
			free(s);
		}
#line 3425 "parse.c"
    break;

  case 100: /* prefix: NUMBER '/' NUMBER  */
#line 1135 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			char	*s;

			/* does not match IPv6 */
			if ((yyvsp[-2].v.number) < 0 || (yyvsp[-2].v.number) > 255 || (yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > 32) {
				yyerror("bad prefix %lld/%lld", (yyvsp[-2].v.number), (yyvsp[0].v.number));
				YYERROR;
			}
			if (asprintf(&s, "%lld/%lld", (yyvsp[-2].v.number), (yyvsp[0].v.number)) == -1)
				fatal(NULL);

			if (!host(s, &(yyval.v.prefix).prefix, &(yyval.v.prefix).len)) {
				yyerror("could not parse address \"%s\"", s);
				free(s);
				YYERROR;
			}
			free(s);
		}
#line 3448 "parse.c"
    break;

  case 101: /* addrspec: address  */
#line 1155 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			memcpy(&(yyval.v.prefix).prefix, &(yyvsp[0].v.addr), sizeof(struct bgpd_addr));
			if ((yyval.v.prefix).prefix.aid == AID_INET)
				(yyval.v.prefix).len = 32;
			else
				(yyval.v.prefix).len = 128;
		}
#line 3460 "parse.c"
    break;

  case 103: /* optnumber: %empty  */
#line 1165 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0; }
#line 3466 "parse.c"
    break;

  case 105: /* $@7: %empty  */
#line 1169 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			u_int rdomain, label;

			if (get_mpe_config((yyvsp[0].v.string), &rdomain, &label) == -1) {
				if ((cmd_opts & BGPD_OPT_NOACTION) == 0) {
					yyerror("troubles getting config of %s",
					    (yyvsp[0].v.string));
					free((yyvsp[0].v.string));
					free((yyvsp[-2].v.string));
					YYERROR;
				}
			}

			if (!(curvpn = calloc(1, sizeof(struct l3vpn))))
				fatal(NULL);
			strlcpy(curvpn->ifmpe, (yyvsp[0].v.string), IFNAMSIZ);

			if (strlcpy(curvpn->descr, (yyvsp[-2].v.string),
			    sizeof(curvpn->descr)) >=
			    sizeof(curvpn->descr)) {
				yyerror("descr \"%s\" too long: max %zu",
				    (yyvsp[-2].v.string), sizeof(curvpn->descr) - 1);
				free((yyvsp[-2].v.string));
				free((yyvsp[0].v.string));
				free(curvpn);
				curvpn = NULL;
				YYERROR;
			}
			free((yyvsp[-2].v.string));
			free((yyvsp[0].v.string));

			TAILQ_INIT(&curvpn->import);
			TAILQ_INIT(&curvpn->export);
			TAILQ_INIT(&curvpn->net_l);
			curvpn->label = label;
			curvpn->rtableid = rdomain;
			netconf = &curvpn->net_l;
		}
#line 3509 "parse.c"
    break;

  case 106: /* l3vpn: VPN STRING ON STRING $@7 '{' l3vpnopts_l '}'  */
#line 1206 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			/* insert into list */
			SIMPLEQ_INSERT_TAIL(&conf->l3vpns, curvpn, entry);
			curvpn = NULL;
			netconf = &conf->networks;
		}
#line 3520 "parse.c"
    break;

  case 111: /* l3vpnopts: RD STRING  */
#line 1220 "../../../openbgpd-portable/src/bgpd/parse.y"
                            {
			struct community	ext;

			memset(&ext, 0, sizeof(ext));
			if (parseextcommunity(&ext, "rt", (yyvsp[0].v.string)) == -1) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
			/*
			 * RD is almost encoded like an ext-community,
			 * but only almost so convert here.
			 */
			if (community_to_rd(&ext, &curvpn->rd) == -1) {
				yyerror("bad encoding of rd");
				YYERROR;
			}
		}
#line 3543 "parse.c"
    break;

  case 112: /* l3vpnopts: EXPORTTRGT STRING STRING  */
#line 1238 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			struct filter_set	*set;

			if ((set = calloc(1, sizeof(struct filter_set))) ==
			    NULL)
				fatal(NULL);
			set->type = ACTION_SET_COMMUNITY;
			if (parseextcommunity(&set->action.community,
			    (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1) {
				free((yyvsp[0].v.string));
				free((yyvsp[-1].v.string));
				free(set);
				YYERROR;
			}
			free((yyvsp[0].v.string));
			free((yyvsp[-1].v.string));
			TAILQ_INSERT_TAIL(&curvpn->export, set, entry);
		}
#line 3566 "parse.c"
    break;

  case 113: /* l3vpnopts: IMPORTTRGT STRING STRING  */
#line 1256 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			struct filter_set	*set;

			if ((set = calloc(1, sizeof(struct filter_set))) ==
			    NULL)
				fatal(NULL);
			set->type = ACTION_SET_COMMUNITY;
			if (parseextcommunity(&set->action.community,
			    (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1) {
				free((yyvsp[0].v.string));
				free((yyvsp[-1].v.string));
				free(set);
				YYERROR;
			}
			free((yyvsp[0].v.string));
			free((yyvsp[-1].v.string));
			TAILQ_INSERT_TAIL(&curvpn->import, set, entry);
		}
#line 3589 "parse.c"
    break;

  case 114: /* l3vpnopts: FIBUPDATE yesno  */
#line 1274 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) == 0)
				curvpn->flags |= F_RIB_NOFIBSYNC;
			else
				curvpn->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3600 "parse.c"
    break;

  case 116: /* $@8: %empty  */
#line 1283 "../../../openbgpd-portable/src/bgpd/parse.y"
                  {	curpeer = new_peer(); }
#line 3606 "parse.c"
    break;

  case 117: /* $@9: %empty  */
#line 1284 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			memcpy(&curpeer->conf.remote_addr, &(yyvsp[0].v.prefix).prefix,
			    sizeof(curpeer->conf.remote_addr));
			curpeer->conf.remote_masklen = (yyvsp[0].v.prefix).len;
			if (((yyvsp[0].v.prefix).prefix.aid == AID_INET && (yyvsp[0].v.prefix).len != 32) ||
			    ((yyvsp[0].v.prefix).prefix.aid == AID_INET6 && (yyvsp[0].v.prefix).len != 128))
				curpeer->conf.template = 1;
			curpeer->conf.capabilities.mp[
			    curpeer->conf.remote_addr.aid] = 1;
			if (get_id(curpeer)) {
				yyerror("get_id failed");
				YYERROR;
			}
		}
#line 3625 "parse.c"
    break;

  case 118: /* neighbor: $@8 NEIGHBOR addrspec $@9 peeropts_h  */
#line 1298 "../../../openbgpd-portable/src/bgpd/parse.y"
                               {
			if (curpeer_filter[0] != NULL)
				TAILQ_INSERT_TAIL(peerfilter_l,
				    curpeer_filter[0], entry);
			if (curpeer_filter[1] != NULL)
				TAILQ_INSERT_TAIL(peerfilter_l,
				    curpeer_filter[1], entry);
			curpeer_filter[0] = NULL;
			curpeer_filter[1] = NULL;

			if (neighbor_consistent(curpeer) == -1) {
				free(curpeer);
				YYERROR;
			}
			if (RB_INSERT(peer_head, new_peers, curpeer) != NULL)
				fatalx("%s: peer tree is corrupt", __func__);
			curpeer = curgroup;
		}
#line 3648 "parse.c"
    break;

  case 119: /* $@10: %empty  */
#line 1318 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			curgroup = curpeer = new_group();
			if (strlcpy(curgroup->conf.group, (yyvsp[0].v.string),
			    sizeof(curgroup->conf.group)) >=
			    sizeof(curgroup->conf.group)) {
				yyerror("group name \"%s\" too long: max %zu",
				    (yyvsp[0].v.string), sizeof(curgroup->conf.group) - 1);
				free((yyvsp[0].v.string));
				free(curgroup);
				YYERROR;
			}
			free((yyvsp[0].v.string));
			if (get_id(curgroup)) {
				yyerror("get_id failed");
				free(curgroup);
				YYERROR;
			}
		}
#line 3671 "parse.c"
    break;

  case 120: /* group: GROUP string $@10 '{' groupopts_l '}'  */
#line 1335 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (curgroup_filter[0] != NULL)
				TAILQ_INSERT_TAIL(groupfilter_l,
				    curgroup_filter[0], entry);
			if (curgroup_filter[1] != NULL)
				TAILQ_INSERT_TAIL(groupfilter_l,
				    curgroup_filter[1], entry);
			curgroup_filter[0] = NULL;
			curgroup_filter[1] = NULL;

			free(curgroup);
			curgroup = NULL;
		}
#line 3689 "parse.c"
    break;

  case 133: /* peeropts: REMOTEAS as4number  */
#line 1368 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.remote_as = (yyvsp[0].v.number);
		}
#line 3697 "parse.c"
    break;

  case 134: /* peeropts: LOCALAS as4number  */
#line 1371 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.local_as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				curpeer->conf.local_short_as = AS_TRANS;
			else
				curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3709 "parse.c"
    break;

  case 135: /* peeropts: LOCALAS as4number asnumber  */
#line 1378 "../../../openbgpd-portable/src/bgpd/parse.y"
                                             {
			curpeer->conf.local_as = (yyvsp[-1].v.number);
			curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3718 "parse.c"
    break;

  case 136: /* peeropts: DESCR string  */
#line 1382 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (strlcpy(curpeer->conf.descr, (yyvsp[0].v.string),
			    sizeof(curpeer->conf.descr)) >=
			    sizeof(curpeer->conf.descr)) {
				yyerror("descr \"%s\" too long: max %zu",
				    (yyvsp[0].v.string), sizeof(curpeer->conf.descr) - 1);
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 3734 "parse.c"
    break;

  case 137: /* peeropts: LOCALADDR address  */
#line 1393 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.addr).aid == AID_INET)
				memcpy(&curpeer->conf.local_addr_v4, &(yyvsp[0].v.addr),
				    sizeof(curpeer->conf.local_addr_v4));
			else if ((yyvsp[0].v.addr).aid == AID_INET6)
				memcpy(&curpeer->conf.local_addr_v6, &(yyvsp[0].v.addr),
				    sizeof(curpeer->conf.local_addr_v6));
			else {
				yyerror("Unsupported address family %s for "
				    "local-addr", aid2str((yyvsp[0].v.addr).aid));
				YYERROR;
			}
		}
#line 3752 "parse.c"
    break;

  case 138: /* peeropts: yesno LOCALADDR  */
#line 1406 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[-1].v.number)) {
				yyerror("bad local-address definition");
				YYERROR;
			}
			memset(&curpeer->conf.local_addr_v4, 0,
			    sizeof(curpeer->conf.local_addr_v4));
			memset(&curpeer->conf.local_addr_v6, 0,
			    sizeof(curpeer->conf.local_addr_v6));
		}
#line 3767 "parse.c"
    break;

  case 139: /* peeropts: MULTIHOP NUMBER  */
#line 1416 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 2 || (yyvsp[0].v.number) > 255) {
				yyerror("invalid multihop distance %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			curpeer->conf.distance = (yyvsp[0].v.number);
		}
#line 3779 "parse.c"
    break;

  case 140: /* peeropts: PASSIVE  */
#line 1423 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.passive = 1;
		}
#line 3787 "parse.c"
    break;

  case 141: /* peeropts: DOWN  */
#line 1426 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.down = 1;
		}
#line 3795 "parse.c"
    break;

  case 142: /* peeropts: DOWN STRING  */
#line 1429 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.down = 1;
			if (strlcpy(curpeer->conf.reason, (yyvsp[0].v.string),
				sizeof(curpeer->conf.reason)) >=
				sizeof(curpeer->conf.reason)) {
				    yyerror("shutdown reason too long");
				    free((yyvsp[0].v.string));
				    YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 3811 "parse.c"
    break;

  case 143: /* peeropts: RIB STRING  */
#line 1440 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (!find_rib((yyvsp[0].v.string))) {
				yyerror("rib \"%s\" does not exist.", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			if (strlcpy(curpeer->conf.rib, (yyvsp[0].v.string),
			    sizeof(curpeer->conf.rib)) >=
			    sizeof(curpeer->conf.rib)) {
				yyerror("rib name \"%s\" too long: max %zu",
				    (yyvsp[0].v.string), sizeof(curpeer->conf.rib) - 1);
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 3832 "parse.c"
    break;

  case 144: /* peeropts: HOLDTIME NUMBER  */
#line 1456 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.holdtime = (yyvsp[0].v.number);
		}
#line 3845 "parse.c"
    break;

  case 145: /* peeropts: HOLDTIME YMIN NUMBER  */
#line 1464 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.min_holdtime = (yyvsp[0].v.number);
		}
#line 3858 "parse.c"
    break;

  case 146: /* peeropts: ANNOUNCE family safi  */
#line 1472 "../../../openbgpd-portable/src/bgpd/parse.y"
                                       {
			uint8_t		aid, safi;
			uint16_t	afi;

			if ((yyvsp[0].v.number) == SAFI_NONE) {
				for (aid = 0; aid < AID_MAX; aid++) {
					if (aid2afi(aid, &afi, &safi) == -1 ||
					    afi != (yyvsp[-1].v.number))
						continue;
					curpeer->conf.capabilities.mp[aid] = 0;
				}
			} else {
				if (afi2aid((yyvsp[-1].v.number), (yyvsp[0].v.number), &aid) == -1) {
					yyerror("unknown AFI/SAFI pair");
					YYERROR;
				}
				curpeer->conf.capabilities.mp[aid] = 1;
			}
		}
#line 3882 "parse.c"
    break;

  case 147: /* peeropts: ANNOUNCE CAPABILITIES yesno  */
#line 1491 "../../../openbgpd-portable/src/bgpd/parse.y"
                                              {
			curpeer->conf.announce_capa = (yyvsp[0].v.number);
		}
#line 3890 "parse.c"
    break;

  case 148: /* peeropts: ANNOUNCE REFRESH yesno  */
#line 1494 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.refresh = (yyvsp[0].v.number);
		}
#line 3898 "parse.c"
    break;

  case 149: /* peeropts: ANNOUNCE ENHANCED REFRESH yesno  */
#line 1497 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                  {
			curpeer->conf.capabilities.enhanced_rr = (yyvsp[0].v.number);
		}
#line 3906 "parse.c"
    break;

  case 150: /* peeropts: ANNOUNCE RESTART yesno  */
#line 1500 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.grestart.restart = (yyvsp[0].v.number);
		}
#line 3914 "parse.c"
    break;

  case 151: /* peeropts: ANNOUNCE AS4BYTE yesno  */
#line 1503 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.as4byte = (yyvsp[0].v.number);
		}
#line 3922 "parse.c"
    break;

  case 152: /* peeropts: ANNOUNCE ADDPATH RECV yesno  */
#line 1506 "../../../openbgpd-portable/src/bgpd/parse.y"
                                              {
			int8_t *ap = curpeer->conf.capabilities.add_path;
			uint8_t i;

			for (i = 0; i < AID_MAX; i++)
				if ((yyvsp[0].v.number))
					*ap++ |= CAPA_AP_RECV;
				else
					*ap++ &= ~CAPA_AP_RECV;
		}
#line 3937 "parse.c"
    break;

  case 153: /* peeropts: EXPORT NONE  */
#line 1516 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			curpeer->conf.export_type = EXPORT_NONE;
		}
#line 3945 "parse.c"
    break;

  case 154: /* peeropts: EXPORT DEFAULTROUTE  */
#line 1519 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			curpeer->conf.export_type = EXPORT_DEFAULT_ROUTE;
		}
#line 3953 "parse.c"
    break;

  case 155: /* peeropts: ENFORCE NEIGHBORAS yesno  */
#line 1522 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_as = ENFORCE_AS_OFF;
		}
#line 3964 "parse.c"
    break;

  case 156: /* peeropts: ENFORCE LOCALAS yesno  */
#line 1528 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_local_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_local_as = ENFORCE_AS_OFF;
		}
#line 3975 "parse.c"
    break;

  case 157: /* peeropts: ASOVERRIDE yesno  */
#line 1534 "../../../openbgpd-portable/src/bgpd/parse.y"
                                   {
			if ((yyvsp[0].v.number)) {
				struct filter_rule	*r;
				struct filter_set	*s;

				if ((s = calloc(1, sizeof(struct filter_set)))
				    == NULL)
					fatal(NULL);
				s->type = ACTION_SET_AS_OVERRIDE;

				r = get_rule(s->type);
				if (merge_filterset(&r->set, s) == -1)
					YYERROR;
			}
		}
#line 3995 "parse.c"
    break;

  case 158: /* peeropts: MAXPREFIX NUMBER restart  */
#line 1549 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if ((yyvsp[-1].v.number) < 0 || (yyvsp[-1].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_prefix = (yyvsp[-1].v.number);
			curpeer->conf.max_prefix_restart = (yyvsp[0].v.number);
		}
#line 4008 "parse.c"
    break;

  case 159: /* peeropts: MAXPREFIX NUMBER OUT restart  */
#line 1557 "../../../openbgpd-portable/src/bgpd/parse.y"
                                               {
			if ((yyvsp[-2].v.number) < 0 || (yyvsp[-2].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_out_prefix = (yyvsp[-2].v.number);
			curpeer->conf.max_out_prefix_restart = (yyvsp[0].v.number);
		}
#line 4021 "parse.c"
    break;

  case 160: /* peeropts: TCP MD5SIG PASSWORD string  */
#line 1565 "../../../openbgpd-portable/src/bgpd/parse.y"
                                             {
			if (curpeer->conf.auth.method) {
				yyerror("auth method cannot be redefined");
				free((yyvsp[0].v.string));
				YYERROR;
			}
			if (strlcpy(curpeer->conf.auth.md5key, (yyvsp[0].v.string),
			    sizeof(curpeer->conf.auth.md5key)) >=
			    sizeof(curpeer->conf.auth.md5key)) {
				yyerror("tcp md5sig password too long: max %zu",
				    sizeof(curpeer->conf.auth.md5key) - 1);
				free((yyvsp[0].v.string));
				YYERROR;
			}
			curpeer->conf.auth.method = AUTH_MD5SIG;
			curpeer->conf.auth.md5key_len = strlen((yyvsp[0].v.string));
			free((yyvsp[0].v.string));
		}
#line 4044 "parse.c"
    break;

  case 161: /* peeropts: TCP MD5SIG KEY string  */
#line 1583 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (curpeer->conf.auth.method) {
				yyerror("auth method cannot be redefined");
				free((yyvsp[0].v.string));
				YYERROR;
			}

			if (str2key((yyvsp[0].v.string), curpeer->conf.auth.md5key,
			    sizeof(curpeer->conf.auth.md5key)) == -1) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			curpeer->conf.auth.method = AUTH_MD5SIG;
			curpeer->conf.auth.md5key_len = strlen((yyvsp[0].v.string)) / 2;
			free((yyvsp[0].v.string));
		}
#line 4065 "parse.c"
    break;

  case 162: /* peeropts: IPSEC espah IKE  */
#line 1599 "../../../openbgpd-portable/src/bgpd/parse.y"
                                  {
			if (curpeer->conf.auth.method) {
				yyerror("auth method cannot be redefined");
				YYERROR;
			}
			if ((yyvsp[-1].v.number))
				curpeer->conf.auth.method = AUTH_IPSEC_IKE_ESP;
			else
				curpeer->conf.auth.method = AUTH_IPSEC_IKE_AH;
		}
#line 4080 "parse.c"
    break;

  case 163: /* peeropts: IPSEC espah inout SPI NUMBER STRING STRING encspec  */
#line 1609 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                     {
			uint32_t	auth_alg;
			uint8_t		keylen;

			if (curpeer->conf.auth.method &&
			    (((curpeer->conf.auth.spi_in && (yyvsp[-5].v.number) == 1) ||
			    (curpeer->conf.auth.spi_out && (yyvsp[-5].v.number) == 0)) ||
			    ((yyvsp[-6].v.number) == 1 && curpeer->conf.auth.method !=
			    AUTH_IPSEC_MANUAL_ESP) ||
			    ((yyvsp[-6].v.number) == 0 && curpeer->conf.auth.method !=
			    AUTH_IPSEC_MANUAL_AH))) {
				yyerror("auth method cannot be redefined");
				free((yyvsp[-2].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}

			if (!strcmp((yyvsp[-2].v.string), "sha1")) {
				auth_alg = SADB_AALG_SHA1HMAC;
				keylen = 20;
			} else if (!strcmp((yyvsp[-2].v.string), "md5")) {
				auth_alg = SADB_AALG_MD5HMAC;
				keylen = 16;
			} else {
				yyerror("unknown auth algorithm \"%s\"", (yyvsp[-2].v.string));
				free((yyvsp[-2].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			free((yyvsp[-2].v.string));

			if (strlen((yyvsp[-1].v.string)) / 2 != keylen) {
				yyerror("auth key len: must be %u bytes, "
				    "is %zu bytes", keylen, strlen((yyvsp[-1].v.string)) / 2);
				free((yyvsp[-1].v.string));
				YYERROR;
			}

			if ((yyvsp[-6].v.number))
				curpeer->conf.auth.method =
				    AUTH_IPSEC_MANUAL_ESP;
			else {
				if ((yyvsp[0].v.encspec).enc_alg) {
					yyerror("\"ipsec ah\" doesn't take "
					    "encryption keys");
					free((yyvsp[-1].v.string));
					YYERROR;
				}
				curpeer->conf.auth.method =
				    AUTH_IPSEC_MANUAL_AH;
			}

			if ((yyvsp[-3].v.number) <= SPI_RESERVED_MAX || (yyvsp[-3].v.number) > UINT_MAX) {
				yyerror("bad spi number %lld", (yyvsp[-3].v.number));
				free((yyvsp[-1].v.string));
				YYERROR;
			}

			if ((yyvsp[-5].v.number) == 1) {
				if (str2key((yyvsp[-1].v.string), curpeer->conf.auth.auth_key_in,
				    sizeof(curpeer->conf.auth.auth_key_in)) ==
				    -1) {
					free((yyvsp[-1].v.string));
					YYERROR;
				}
				curpeer->conf.auth.spi_in = (yyvsp[-3].v.number);
				curpeer->conf.auth.auth_alg_in = auth_alg;
				curpeer->conf.auth.enc_alg_in = (yyvsp[0].v.encspec).enc_alg;
				memcpy(&curpeer->conf.auth.enc_key_in,
				    &(yyvsp[0].v.encspec).enc_key,
				    sizeof(curpeer->conf.auth.enc_key_in));
				curpeer->conf.auth.enc_keylen_in =
				    (yyvsp[0].v.encspec).enc_key_len;
				curpeer->conf.auth.auth_keylen_in = keylen;
			} else {
				if (str2key((yyvsp[-1].v.string), curpeer->conf.auth.auth_key_out,
				    sizeof(curpeer->conf.auth.auth_key_out)) ==
				    -1) {
					free((yyvsp[-1].v.string));
					YYERROR;
				}
				curpeer->conf.auth.spi_out = (yyvsp[-3].v.number);
				curpeer->conf.auth.auth_alg_out = auth_alg;
				curpeer->conf.auth.enc_alg_out = (yyvsp[0].v.encspec).enc_alg;
				memcpy(&curpeer->conf.auth.enc_key_out,
				    &(yyvsp[0].v.encspec).enc_key,
				    sizeof(curpeer->conf.auth.enc_key_out));
				curpeer->conf.auth.enc_keylen_out =
				    (yyvsp[0].v.encspec).enc_key_len;
				curpeer->conf.auth.auth_keylen_out = keylen;
			}
			free((yyvsp[-1].v.string));
		}
#line 4178 "parse.c"
    break;

  case 164: /* peeropts: TTLSECURITY yesno  */
#line 1702 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.ttlsec = (yyvsp[0].v.number);
		}
#line 4186 "parse.c"
    break;

  case 165: /* peeropts: SET filter_set_opt  */
#line 1705 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			struct filter_rule	*r;

			r = get_rule((yyvsp[0].v.filter_set)->type);
			if (merge_filterset(&r->set, (yyvsp[0].v.filter_set)) == -1)
				YYERROR;
		}
#line 4198 "parse.c"
    break;

  case 166: /* peeropts: SET '{' optnl filter_set_l optnl '}'  */
#line 1712 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			struct filter_rule	*r;
			struct filter_set	*s;

			while ((s = TAILQ_FIRST((yyvsp[-2].v.filter_set_head))) != NULL) {
				TAILQ_REMOVE((yyvsp[-2].v.filter_set_head), s, entry);
				r = get_rule(s->type);
				if (merge_filterset(&r->set, s) == -1)
					YYERROR;
			}
			free((yyvsp[-2].v.filter_set_head));
		}
#line 4215 "parse.c"
    break;

  case 168: /* peeropts: REFLECTOR  */
#line 1725 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((conf->flags & BGPD_FLAG_REFLECTOR) &&
			    conf->clusterid != 0) {
				yyerror("only one route reflector "
				    "cluster allowed");
				YYERROR;
			}
			conf->flags |= BGPD_FLAG_REFLECTOR;
			curpeer->conf.reflector_client = 1;
		}
#line 4230 "parse.c"
    break;

  case 169: /* peeropts: REFLECTOR address  */
#line 1735 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.addr).aid != AID_INET) {
				yyerror("route reflector cluster-id must be "
				    "an IPv4 address");
				YYERROR;
			}
			if ((conf->flags & BGPD_FLAG_REFLECTOR) &&
			    conf->clusterid != (yyvsp[0].v.addr).v4.s_addr) {
				yyerror("only one route reflector "
				    "cluster allowed");
				YYERROR;
			}
			conf->flags |= BGPD_FLAG_REFLECTOR;
			curpeer->conf.reflector_client = 1;
			conf->clusterid = (yyvsp[0].v.addr).v4.s_addr;
		}
#line 4251 "parse.c"
    break;

  case 170: /* peeropts: DEPEND ON STRING  */
#line 1751 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (strlcpy(curpeer->conf.if_depend, (yyvsp[0].v.string),
			    sizeof(curpeer->conf.if_depend)) >=
			    sizeof(curpeer->conf.if_depend)) {
				yyerror("interface name \"%s\" too long: "
				    "max %zu", (yyvsp[0].v.string),
				    sizeof(curpeer->conf.if_depend) - 1);
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 4268 "parse.c"
    break;

  case 171: /* peeropts: DEMOTE STRING  */
#line 1763 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
#ifdef HAVE_CARP
			if (strlcpy(curpeer->conf.demote_group, (yyvsp[0].v.string),
			    sizeof(curpeer->conf.demote_group)) >=
			    sizeof(curpeer->conf.demote_group)) {
				yyerror("demote group name \"%s\" too long: "
				    "max %zu", (yyvsp[0].v.string),
				    sizeof(curpeer->conf.demote_group) - 1);
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
			if (carp_demote_init(curpeer->conf.demote_group,
			    cmd_opts & BGPD_OPT_FORCE_DEMOTE) == -1) {
				yyerror("error initializing group \"%s\"",
				    curpeer->conf.demote_group);
				YYERROR;
			}
#else
			yyerror("carp demote not supported");
			free((yyvsp[0].v.string));
			YYERROR;
#endif
		}
#line 4297 "parse.c"
    break;

  case 172: /* peeropts: TRANSPARENT yesno  */
#line 1787 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_TRANS_AS;
			else
				curpeer->conf.flags &= ~PEERFLAG_TRANS_AS;
		}
#line 4308 "parse.c"
    break;

  case 173: /* peeropts: LOG STRING  */
#line 1793 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (!strcmp((yyvsp[0].v.string), "updates"))
				curpeer->conf.flags |= PEERFLAG_LOG_UPDATES;
			else if (!strcmp((yyvsp[0].v.string), "no"))
				curpeer->conf.flags &= ~PEERFLAG_LOG_UPDATES;
			else {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 4324 "parse.c"
    break;

  case 174: /* peeropts: REJECT ASSET yesno  */
#line 1804 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_NO_AS_SET;
			else
				curpeer->conf.flags &= ~PEERFLAG_NO_AS_SET;
		}
#line 4335 "parse.c"
    break;

  case 175: /* peeropts: PORT NUMBER  */
#line 1810 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("port must be between %u and %u",
				    1, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.remote_port = (yyvsp[0].v.number);
		}
#line 4348 "parse.c"
    break;

  case 176: /* peeropts: RDE EVALUATE STRING  */
#line 1818 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			if (!strcmp((yyvsp[0].v.string), "all"))
				curpeer->conf.flags |= PEERFLAG_EVALUATE_ALL;
			else if (!strcmp((yyvsp[0].v.string), "default"))
				curpeer->conf.flags &= ~PEERFLAG_EVALUATE_ALL;
			else {
				yyerror("rde evaluate: "
				    "unknown setting \"%s\"", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 4366 "parse.c"
    break;

  case 177: /* restart: %empty  */
#line 1833 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0; }
#line 4372 "parse.c"
    break;

  case 178: /* restart: RESTART NUMBER  */
#line 1834 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("restart out of range. 1 to %u minutes",
				    USHRT_MAX);
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 4385 "parse.c"
    break;

  case 179: /* family: IPV4  */
#line 1844 "../../../openbgpd-portable/src/bgpd/parse.y"
                        { (yyval.v.number) = AFI_IPv4; }
#line 4391 "parse.c"
    break;

  case 180: /* family: IPV6  */
#line 1845 "../../../openbgpd-portable/src/bgpd/parse.y"
                        { (yyval.v.number) = AFI_IPv6; }
#line 4397 "parse.c"
    break;

  case 181: /* safi: NONE  */
#line 1848 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_NONE; }
#line 4403 "parse.c"
    break;

  case 182: /* safi: UNICAST  */
#line 1849 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_UNICAST; }
#line 4409 "parse.c"
    break;

  case 183: /* safi: VPN  */
#line 1850 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_MPLSVPN; }
#line 4415 "parse.c"
    break;

  case 184: /* nettype: STATIC  */
#line 1853 "../../../openbgpd-portable/src/bgpd/parse.y"
                         { (yyval.v.number) = 1; }
#line 4421 "parse.c"
    break;

  case 185: /* nettype: CONNECTED  */
#line 1854 "../../../openbgpd-portable/src/bgpd/parse.y"
                            { (yyval.v.number) = 0; }
#line 4427 "parse.c"
    break;

  case 186: /* espah: ESP  */
#line 1857 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 4433 "parse.c"
    break;

  case 187: /* espah: AH  */
#line 1858 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 4439 "parse.c"
    break;

  case 188: /* encspec: %empty  */
#line 1861 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			bzero(&(yyval.v.encspec), sizeof((yyval.v.encspec)));
		}
#line 4447 "parse.c"
    break;

  case 189: /* encspec: STRING STRING  */
#line 1864 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			bzero(&(yyval.v.encspec), sizeof((yyval.v.encspec)));
			if (!strcmp((yyvsp[-1].v.string), "3des") || !strcmp((yyvsp[-1].v.string), "3des-cbc")) {
				(yyval.v.encspec).enc_alg = SADB_EALG_3DESCBC;
				(yyval.v.encspec).enc_key_len = 21; /* XXX verify */
			} else if (!strcmp((yyvsp[-1].v.string), "aes") ||
			    !strcmp((yyvsp[-1].v.string), "aes-128-cbc")) {
				(yyval.v.encspec).enc_alg = SADB_X_EALG_AES;
				(yyval.v.encspec).enc_key_len = 16;
			} else {
				yyerror("unknown enc algorithm \"%s\"", (yyvsp[-1].v.string));
				free((yyvsp[-1].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[-1].v.string));

			if (strlen((yyvsp[0].v.string)) / 2 != (yyval.v.encspec).enc_key_len) {
				yyerror("enc key length wrong: should be %u "
				    "bytes, is %zu bytes",
				    (yyval.v.encspec).enc_key_len * 2, strlen((yyvsp[0].v.string)));
				free((yyvsp[0].v.string));
				YYERROR;
			}

			if (str2key((yyvsp[0].v.string), (yyval.v.encspec).enc_key, sizeof((yyval.v.encspec).enc_key)) == -1) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 4483 "parse.c"
    break;

  case 190: /* filterrule: action quick filter_rib_h direction filter_peer_h filter_match_h filter_set  */
#line 1899 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_rule	 r;
			struct filter_rib_l	 *rb, *rbnext;

			bzero(&r, sizeof(r));
			r.action = (yyvsp[-6].v.u8);
			r.quick = (yyvsp[-5].v.u8);
			r.dir = (yyvsp[-3].v.u8);
			if ((yyvsp[-4].v.filter_rib)) {
				if (r.dir != DIR_IN) {
					yyerror("rib only allowed on \"from\" "
					    "rules.");

					for (rb = (yyvsp[-4].v.filter_rib); rb != NULL; rb = rbnext) {
						rbnext = rb->next;
						free(rb);
					}
					YYERROR;
				}
			}
			if (expand_rule(&r, (yyvsp[-4].v.filter_rib), (yyvsp[-2].v.filter_peers), &(yyvsp[-1].v.filter_match), (yyvsp[0].v.filter_set_head)) == -1)
				YYERROR;
		}
#line 4511 "parse.c"
    break;

  case 191: /* action: ALLOW  */
#line 1924 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_ALLOW; }
#line 4517 "parse.c"
    break;

  case 192: /* action: DENY  */
#line 1925 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_DENY; }
#line 4523 "parse.c"
    break;

  case 193: /* action: MATCH  */
#line 1926 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_NONE; }
#line 4529 "parse.c"
    break;

  case 194: /* quick: %empty  */
#line 1929 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 0; }
#line 4535 "parse.c"
    break;

  case 195: /* quick: QUICK  */
#line 1930 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 1; }
#line 4541 "parse.c"
    break;

  case 196: /* direction: FROM  */
#line 1933 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = DIR_IN; }
#line 4547 "parse.c"
    break;

  case 197: /* direction: TO  */
#line 1934 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = DIR_OUT; }
#line 4553 "parse.c"
    break;

  case 198: /* filter_rib_h: %empty  */
#line 1937 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = NULL; }
#line 4559 "parse.c"
    break;

  case 199: /* filter_rib_h: RIB filter_rib  */
#line 1938 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4565 "parse.c"
    break;

  case 200: /* filter_rib_h: RIB '{' optnl filter_rib_l optnl '}'  */
#line 1939 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_rib) = (yyvsp[-2].v.filter_rib); }
#line 4571 "parse.c"
    break;

  case 201: /* filter_rib_l: filter_rib  */
#line 1941 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4577 "parse.c"
    break;

  case 202: /* filter_rib_l: filter_rib_l comma filter_rib  */
#line 1942 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			(yyvsp[0].v.filter_rib)->next = (yyvsp[-2].v.filter_rib);
			(yyval.v.filter_rib) = (yyvsp[0].v.filter_rib);
		}
#line 4586 "parse.c"
    break;

  case 203: /* filter_rib: STRING  */
#line 1948 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (!find_rib((yyvsp[0].v.string))) {
				yyerror("rib \"%s\" does not exist.", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			if (((yyval.v.filter_rib) = calloc(1, sizeof(struct filter_rib_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_rib)->next = NULL;
			if (strlcpy((yyval.v.filter_rib)->name, (yyvsp[0].v.string), sizeof((yyval.v.filter_rib)->name)) >=
			    sizeof((yyval.v.filter_rib)->name)) {
				yyerror("rib name \"%s\" too long: "
				    "max %zu", (yyvsp[0].v.string), sizeof((yyval.v.filter_rib)->name) - 1);
				free((yyvsp[0].v.string));
				free((yyval.v.filter_rib));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 4611 "parse.c"
    break;

  case 205: /* filter_peer_h: '{' optnl filter_peer_l optnl '}'  */
#line 1971 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_peers) = (yyvsp[-2].v.filter_peers); }
#line 4617 "parse.c"
    break;

  case 206: /* filter_peer_l: filter_peer  */
#line 1974 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_peers) = (yyvsp[0].v.filter_peers); }
#line 4623 "parse.c"
    break;

  case 207: /* filter_peer_l: filter_peer_l comma filter_peer  */
#line 1975 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyvsp[0].v.filter_peers)->next = (yyvsp[-2].v.filter_peers);
			(yyval.v.filter_peers) = (yyvsp[0].v.filter_peers);
		}
#line 4632 "parse.c"
    break;

  case 208: /* filter_peer: ANY  */
#line 1981 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.peerid = (yyval.v.filter_peers)->p.groupid = 0;
			(yyval.v.filter_peers)->next = NULL;
		}
#line 4644 "parse.c"
    break;

  case 209: /* filter_peer: address  */
#line 1988 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			struct peer *p;

			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.remote_as = (yyval.v.filter_peers)->p.groupid = (yyval.v.filter_peers)->p.peerid = 0;
			(yyval.v.filter_peers)->next = NULL;
			RB_FOREACH(p, peer_head, new_peers)
				if (!memcmp(&p->conf.remote_addr,
				    &(yyvsp[0].v.addr), sizeof(p->conf.remote_addr))) {
					(yyval.v.filter_peers)->p.peerid = p->conf.id;
					break;
				}
			if ((yyval.v.filter_peers)->p.peerid == 0) {
				yyerror("no such peer: %s", log_addr(&(yyvsp[0].v.addr)));
				free((yyval.v.filter_peers));
				YYERROR;
			}
		}
#line 4669 "parse.c"
    break;

  case 210: /* filter_peer: AS as4number  */
#line 2008 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.groupid = (yyval.v.filter_peers)->p.peerid = 0;
			(yyval.v.filter_peers)->p.remote_as = (yyvsp[0].v.number);
		}
#line 4681 "parse.c"
    break;

  case 211: /* filter_peer: GROUP STRING  */
#line 2015 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			struct peer *p;

			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.remote_as = (yyval.v.filter_peers)->p.peerid = 0;
			(yyval.v.filter_peers)->next = NULL;
			RB_FOREACH(p, peer_head, new_peers)
				if (!strcmp(p->conf.group, (yyvsp[0].v.string))) {
					(yyval.v.filter_peers)->p.groupid = p->conf.groupid;
					break;
				}
			if ((yyval.v.filter_peers)->p.groupid == 0) {
				yyerror("no such group: \"%s\"", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				free((yyval.v.filter_peers));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 4707 "parse.c"
    break;

  case 212: /* filter_peer: EBGP  */
#line 2036 "../../../openbgpd-portable/src/bgpd/parse.y"
                       {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ebgp = 1;
		}
#line 4718 "parse.c"
    break;

  case 213: /* filter_peer: IBGP  */
#line 2042 "../../../openbgpd-portable/src/bgpd/parse.y"
                       {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ibgp = 1;
		}
#line 4729 "parse.c"
    break;

  case 214: /* filter_prefix_h: IPV4 prefixlenop  */
#line 2050 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                         {
			if ((yyvsp[0].v.prefixlen).op == OP_NONE) {
				(yyvsp[0].v.prefixlen).op = OP_RANGE;
				(yyvsp[0].v.prefixlen).len_min = 0;
				(yyvsp[0].v.prefixlen).len_max = -1;
			}
			if (((yyval.v.filter_prefix) = calloc(1, sizeof(struct filter_prefix_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_prefix)->p.addr.aid = AID_INET;
			if (merge_prefixspec(&(yyval.v.filter_prefix)->p, &(yyvsp[0].v.prefixlen)) == -1) {
				free((yyval.v.filter_prefix));
				YYERROR;
			}
		}
#line 4749 "parse.c"
    break;

  case 215: /* filter_prefix_h: IPV6 prefixlenop  */
#line 2065 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((yyvsp[0].v.prefixlen).op == OP_NONE) {
				(yyvsp[0].v.prefixlen).op = OP_RANGE;
				(yyvsp[0].v.prefixlen).len_min = 0;
				(yyvsp[0].v.prefixlen).len_max = -1;
			}
			if (((yyval.v.filter_prefix) = calloc(1, sizeof(struct filter_prefix_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_prefix)->p.addr.aid = AID_INET6;
			if (merge_prefixspec(&(yyval.v.filter_prefix)->p, &(yyvsp[0].v.prefixlen)) == -1) {
				free((yyval.v.filter_prefix));
				YYERROR;
			}
		}
#line 4769 "parse.c"
    break;

  case 216: /* filter_prefix_h: PREFIX filter_prefix  */
#line 2080 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4775 "parse.c"
    break;

  case 217: /* filter_prefix_h: PREFIX '{' filter_prefix_m '}'  */
#line 2081 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4781 "parse.c"
    break;

  case 219: /* filter_prefix_m: '{' filter_prefix_l '}'  */
#line 2085 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4787 "parse.c"
    break;

  case 220: /* filter_prefix_m: '{' filter_prefix_l '}' filter_prefix_m  */
#line 2087 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_prefix_l  *p;

			/* merge, both can be lists */
			for (p = (yyvsp[-2].v.filter_prefix); p != NULL && p->next != NULL; p = p->next)
				;       /* nothing */
			if (p != NULL)
				p->next = (yyvsp[0].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[-2].v.filter_prefix);
		}
#line 4802 "parse.c"
    break;

  case 221: /* filter_prefix_l: filter_prefix  */
#line 2098 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4808 "parse.c"
    break;

  case 222: /* filter_prefix_l: filter_prefix_l comma filter_prefix  */
#line 2099 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyvsp[0].v.filter_prefix)->next = (yyvsp[-2].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix);
		}
#line 4817 "parse.c"
    break;

  case 223: /* filter_prefix: prefix prefixlenop  */
#line 2105 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if (((yyval.v.filter_prefix) = calloc(1, sizeof(struct filter_prefix_l))) ==
			    NULL)
				fatal(NULL);
			memcpy(&(yyval.v.filter_prefix)->p.addr, &(yyvsp[-1].v.prefix).prefix,
			    sizeof((yyval.v.filter_prefix)->p.addr));
			(yyval.v.filter_prefix)->p.len = (yyvsp[-1].v.prefix).len;

			if (merge_prefixspec(&(yyval.v.filter_prefix)->p, &(yyvsp[0].v.prefixlen)) == -1) {
				free((yyval.v.filter_prefix));
				YYERROR;
			}
		}
#line 4835 "parse.c"
    break;

  case 225: /* filter_as_h: '{' filter_as_t_l '}'  */
#line 2121 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4841 "parse.c"
    break;

  case 227: /* filter_as_t_l: filter_as_t_l comma filter_as_t  */
#line 2125 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4856 "parse.c"
    break;

  case 228: /* filter_as_t: filter_as_type filter_as  */
#line 2137 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as)->a.type = (yyvsp[-1].v.u8);
		}
#line 4865 "parse.c"
    break;

  case 229: /* filter_as_t: filter_as_type '{' filter_as_l_h '}'  */
#line 2141 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			struct filter_as_l	*a;

			(yyval.v.filter_as) = (yyvsp[-1].v.filter_as);
			for (a = (yyval.v.filter_as); a != NULL; a = a->next)
				a->a.type = (yyvsp[-3].v.u8);
		}
#line 4877 "parse.c"
    break;

  case 230: /* filter_as_t: filter_as_type ASSET STRING  */
#line 2148 "../../../openbgpd-portable/src/bgpd/parse.y"
                                              {
			if (as_sets_lookup(&conf->as_sets, (yyvsp[0].v.string)) == NULL) {
				yyerror("as-set \"%s\" not defined", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.type = (yyvsp[-2].v.u8);
			(yyval.v.filter_as)->a.flags = AS_FLAG_AS_SET_NAME;
			if (strlcpy((yyval.v.filter_as)->a.name, (yyvsp[0].v.string), sizeof((yyval.v.filter_as)->a.name)) >=
			    sizeof((yyval.v.filter_as)->a.name)) {
				yyerror("as-set name \"%s\" too long: "
				    "max %zu", (yyvsp[0].v.string), sizeof((yyval.v.filter_as)->a.name) - 1);
				free((yyvsp[0].v.string));
				free((yyval.v.filter_as));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 4903 "parse.c"
    break;

  case 232: /* filter_as_l_h: '{' filter_as_l '}'  */
#line 2172 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4909 "parse.c"
    break;

  case 233: /* filter_as_l_h: '{' filter_as_l '}' filter_as_l_h  */
#line 2174 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4924 "parse.c"
    break;

  case 235: /* filter_as_l: filter_as_l comma filter_as  */
#line 2187 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			(yyvsp[0].v.filter_as)->next = (yyvsp[-2].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
		}
#line 4933 "parse.c"
    break;

  case 236: /* filter_as: as4number_any  */
#line 2193 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.op = OP_EQ;
		}
#line 4946 "parse.c"
    break;

  case 237: /* filter_as: NEIGHBORAS  */
#line 2201 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.flags = AS_FLAG_NEIGHBORAS;
		}
#line 4957 "parse.c"
    break;

  case 238: /* filter_as: equalityop as4number_any  */
#line 2207 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.op = (yyvsp[-1].v.u8);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
		}
#line 4970 "parse.c"
    break;

  case 239: /* filter_as: as4number_any binaryop as4number_any  */
#line 2215 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                       {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			if ((yyvsp[-2].v.number) >= (yyvsp[0].v.number)) {
				yyerror("start AS is bigger than end");
				YYERROR;
			}
			(yyval.v.filter_as)->a.op = (yyvsp[-1].v.u8);
			(yyval.v.filter_as)->a.as_min = (yyvsp[-2].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
		}
#line 4987 "parse.c"
    break;

  case 240: /* filter_match_h: %empty  */
#line 2229 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			bzero(&(yyval.v.filter_match), sizeof((yyval.v.filter_match)));
		}
#line 4995 "parse.c"
    break;

  case 241: /* $@11: %empty  */
#line 2232 "../../../openbgpd-portable/src/bgpd/parse.y"
                  {
			bzero(&fmopts, sizeof(fmopts));
		}
#line 5003 "parse.c"
    break;

  case 242: /* filter_match_h: $@11 filter_match  */
#line 2235 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			memcpy(&(yyval.v.filter_match), &fmopts, sizeof((yyval.v.filter_match)));
		}
#line 5011 "parse.c"
    break;

  case 245: /* filter_elm: filter_prefix_h  */
#line 2244 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.prefix_l != NULL) {
				yyerror("\"prefix\" already specified");
				YYERROR;
			}
			if (fmopts.m.prefixset.name[0] != '\0') {
				yyerror("\"prefix-set\" already specified, "
				    "cannot be used with \"prefix\" in the "
				    "same filter rule");
				YYERROR;
			}
			fmopts.prefix_l = (yyvsp[0].v.filter_prefix);
		}
#line 5029 "parse.c"
    break;

  case 246: /* filter_elm: filter_as_h  */
#line 2257 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.as_l != NULL) {
				yyerror("AS filters already specified");
				YYERROR;
			}
			fmopts.as_l = (yyvsp[0].v.filter_as);
		}
#line 5041 "parse.c"
    break;

  case 247: /* filter_elm: MAXASLEN NUMBER  */
#line 2264 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.aslen.type != ASLEN_NONE) {
				yyerror("AS length filters already specified");
				YYERROR;
			}
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > UINT_MAX) {
				yyerror("bad max-as-len %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			fmopts.m.aslen.type = ASLEN_MAX;
			fmopts.m.aslen.aslen = (yyvsp[0].v.number);
		}
#line 5058 "parse.c"
    break;

  case 248: /* filter_elm: MAXASSEQ NUMBER  */
#line 2276 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.aslen.type != ASLEN_NONE) {
				yyerror("AS length filters already specified");
				YYERROR;
			}
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > UINT_MAX) {
				yyerror("bad max-as-seq %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			fmopts.m.aslen.type = ASLEN_SEQ;
			fmopts.m.aslen.aslen = (yyvsp[0].v.number);
		}
#line 5075 "parse.c"
    break;

  case 249: /* filter_elm: community STRING  */
#line 2288 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			int i;
			for (i = 0; i < MAX_COMM_MATCH; i++) {
				if (fmopts.m.community[i].flags == 0)
					break;
			}
			if (i >= MAX_COMM_MATCH) {
				yyerror("too many \"community\" filters "
				    "specified");
				free((yyvsp[0].v.string));
				YYERROR;
			}
			if (parsecommunity(&fmopts.m.community[i], (yyvsp[-1].v.u8), (yyvsp[0].v.string)) == -1) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 5098 "parse.c"
    break;

  case 250: /* filter_elm: EXTCOMMUNITY STRING STRING  */
#line 2306 "../../../openbgpd-portable/src/bgpd/parse.y"
                                             {
			int i;
			for (i = 0; i < MAX_COMM_MATCH; i++) {
				if (fmopts.m.community[i].flags == 0)
					break;
			}
			if (i >= MAX_COMM_MATCH) {
				yyerror("too many \"community\" filters "
				    "specified");
				free((yyvsp[-1].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			if (parseextcommunity(&fmopts.m.community[i],
			    (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1) {
				free((yyvsp[-1].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.string));
		}
#line 5125 "parse.c"
    break;

  case 251: /* filter_elm: EXTCOMMUNITY OVS STRING  */
#line 2328 "../../../openbgpd-portable/src/bgpd/parse.y"
                                          {
			int i;
			for (i = 0; i < MAX_COMM_MATCH; i++) {
				if (fmopts.m.community[i].flags == 0)
					break;
			}
			if (i >= MAX_COMM_MATCH) {
				yyerror("too many \"community\" filters "
				    "specified");
				free((yyvsp[0].v.string));
				YYERROR;
			}
			if (parseextcommunity(&fmopts.m.community[i],
			    "ovs", (yyvsp[0].v.string)) == -1) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 5149 "parse.c"
    break;

  case 252: /* filter_elm: NEXTHOP address  */
#line 2347 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.addr = (yyvsp[0].v.addr);
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_ADDR;
		}
#line 5162 "parse.c"
    break;

  case 253: /* filter_elm: NEXTHOP NEIGHBOR  */
#line 2355 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_NEIGHBOR;
		}
#line 5174 "parse.c"
    break;

  case 254: /* filter_elm: PREFIXSET STRING prefixlenop  */
#line 2362 "../../../openbgpd-portable/src/bgpd/parse.y"
                                               {
			struct prefixset *ps;
			if (fmopts.prefix_l != NULL) {
				yyerror("\"prefix\" already specified, cannot "
				    "be used with \"prefix-set\" in the same "
				    "filter rule");
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			if (fmopts.m.prefixset.name[0] != '\0') {
				yyerror("prefix-set filter already specified");
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			if ((ps = find_prefixset((yyvsp[-1].v.string), &conf->prefixsets))
			    == NULL) {
				yyerror("prefix-set '%s' not defined", (yyvsp[-1].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			if (strlcpy(fmopts.m.prefixset.name, (yyvsp[-1].v.string),
			    sizeof(fmopts.m.prefixset.name)) >=
			    sizeof(fmopts.m.prefixset.name)) {
				yyerror("prefix-set name too long");
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			if (!((yyvsp[0].v.prefixlen).op == OP_NONE ||
			    ((yyvsp[0].v.prefixlen).op == OP_RANGE &&
			     (yyvsp[0].v.prefixlen).len_min == -1 && (yyvsp[0].v.prefixlen).len_max == -1))) {
				yyerror("prefix-sets can only use option "
				    "or-longer");
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			if ((yyvsp[0].v.prefixlen).op == OP_RANGE && ps->sflags & PREFIXSET_FLAG_OPS) {
				yyerror("prefix-set %s contains prefixlen "
				    "operators and cannot be used with an "
				    "or-longer filter", (yyvsp[-1].v.string));
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			if ((yyvsp[0].v.prefixlen).op == OP_RANGE && (yyvsp[0].v.prefixlen).len_min == -1 &&
			    (yyvsp[0].v.prefixlen).len_min == -1)
				fmopts.m.prefixset.flags |=
				    PREFIXSET_FLAG_LONGER;
			fmopts.m.prefixset.flags |= PREFIXSET_FLAG_FILTER;
			free((yyvsp[-1].v.string));
		}
#line 5228 "parse.c"
    break;

  case 255: /* filter_elm: ORIGINSET STRING  */
#line 2411 "../../../openbgpd-portable/src/bgpd/parse.y"
                                   {
			if (fmopts.m.originset.name[0] != '\0') {
				yyerror("origin-set filter already specified");
				free((yyvsp[0].v.string));
				YYERROR;
			}
			if (find_prefixset((yyvsp[0].v.string), &conf->originsets) == NULL) {
				yyerror("origin-set '%s' not defined", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			if (strlcpy(fmopts.m.originset.name, (yyvsp[0].v.string),
			    sizeof(fmopts.m.originset.name)) >=
			    sizeof(fmopts.m.originset.name)) {
				yyerror("origin-set name too long");
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 5253 "parse.c"
    break;

  case 256: /* filter_elm: OVS validity  */
#line 2431 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.ovs.is_set) {
				yyerror("ovs filter already specified");
				YYERROR;
			}
			fmopts.m.ovs.validity = (yyvsp[0].v.number);
			fmopts.m.ovs.is_set = 1;
		}
#line 5266 "parse.c"
    break;

  case 257: /* prefixlenop: %empty  */
#line 2441 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen))); }
#line 5272 "parse.c"
    break;

  case 258: /* prefixlenop: LONGER  */
#line 2442 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen)));
			(yyval.v.prefixlen).op = OP_RANGE;
			(yyval.v.prefixlen).len_min = -1;
			(yyval.v.prefixlen).len_max = -1;
		}
#line 5283 "parse.c"
    break;

  case 259: /* prefixlenop: MAXLEN NUMBER  */
#line 2448 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen)));
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > 128) {
				yyerror("prefixlen must be >= 0 and <= 128");
				YYERROR;
			}

			(yyval.v.prefixlen).op = OP_RANGE;
			(yyval.v.prefixlen).len_min = -1;
			(yyval.v.prefixlen).len_max = (yyvsp[0].v.number);
		}
#line 5299 "parse.c"
    break;

  case 260: /* prefixlenop: PREFIXLEN unaryop NUMBER  */
#line 2459 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			int min, max;

			bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen)));
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > 128) {
				yyerror("prefixlen must be >= 0 and <= 128");
				YYERROR;
			}
			/*
			 * convert the unary operation into the equivalent
			 * range check
			 */
			(yyval.v.prefixlen).op = OP_RANGE;

			switch ((yyvsp[-1].v.u8)) {
			case OP_NE:
				(yyval.v.prefixlen).op = (yyvsp[-1].v.u8);
			case OP_EQ:
				min = max = (yyvsp[0].v.number);
				break;
			case OP_LT:
				if ((yyvsp[0].v.number) == 0) {
					yyerror("prefixlen must be > 0");
					YYERROR;
				}
				(yyvsp[0].v.number) -= 1;
			case OP_LE:
				min = -1;
				max = (yyvsp[0].v.number);
				break;
			case OP_GT:
				(yyvsp[0].v.number) += 1;
			case OP_GE:
				min = (yyvsp[0].v.number);
				max = -1;
				break;
			default:
				yyerror("unknown prefixlen operation");
				YYERROR;
			}
			(yyval.v.prefixlen).len_min = min;
			(yyval.v.prefixlen).len_max = max;
		}
#line 5347 "parse.c"
    break;

  case 261: /* prefixlenop: PREFIXLEN NUMBER binaryop NUMBER  */
#line 2502 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen)));
			if ((yyvsp[-2].v.number) < 0 || (yyvsp[-2].v.number) > 128 || (yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > 128) {
				yyerror("prefixlen must be < 128");
				YYERROR;
			}
			if ((yyvsp[-2].v.number) > (yyvsp[0].v.number)) {
				yyerror("start prefixlen is bigger than end");
				YYERROR;
			}
			(yyval.v.prefixlen).op = (yyvsp[-1].v.u8);
			(yyval.v.prefixlen).len_min = (yyvsp[-2].v.number);
			(yyval.v.prefixlen).len_max = (yyvsp[0].v.number);
		}
#line 5366 "parse.c"
    break;

  case 262: /* filter_as_type: AS  */
#line 2518 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_ALL; }
#line 5372 "parse.c"
    break;

  case 263: /* filter_as_type: SOURCEAS  */
#line 2519 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_SOURCE; }
#line 5378 "parse.c"
    break;

  case 264: /* filter_as_type: TRANSITAS  */
#line 2520 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_TRANSIT; }
#line 5384 "parse.c"
    break;

  case 265: /* filter_as_type: PEERAS  */
#line 2521 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_PEER; }
#line 5390 "parse.c"
    break;

  case 266: /* filter_set: %empty  */
#line 2524 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                { (yyval.v.filter_set_head) = NULL; }
#line 5396 "parse.c"
    break;

  case 267: /* filter_set: SET filter_set_opt  */
#line 2525 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5408 "parse.c"
    break;

  case 268: /* filter_set: SET '{' optnl filter_set_l optnl '}'  */
#line 2532 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head); }
#line 5414 "parse.c"
    break;

  case 269: /* filter_set_l: filter_set_l comma filter_set_opt  */
#line 2535 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head);
			if (merge_filterset((yyval.v.filter_set_head), (yyvsp[0].v.filter_set)) == 1)
				YYERROR;
		}
#line 5424 "parse.c"
    break;

  case 270: /* filter_set_l: filter_set_opt  */
#line 2540 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5436 "parse.c"
    break;

  case 271: /* community: COMMUNITY  */
#line 2549 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.u8) = COMMUNITY_TYPE_BASIC; }
#line 5442 "parse.c"
    break;

  case 272: /* community: LARGECOMMUNITY  */
#line 2550 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.u8) = COMMUNITY_TYPE_LARGE; }
#line 5448 "parse.c"
    break;

  case 273: /* delete: %empty  */
#line 2553 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 0; }
#line 5454 "parse.c"
    break;

  case 274: /* delete: DELETE  */
#line 2554 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 1; }
#line 5460 "parse.c"
    break;

  case 275: /* filter_set_opt: LOCALPREF NUMBER  */
#line 2557 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) < -INT_MAX || (yyvsp[0].v.number) > UINT_MAX) {
				yyerror("bad localpref %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			if ((yyvsp[0].v.number) >= 0) {
				(yyval.v.filter_set)->type = ACTION_SET_LOCALPREF;
				(yyval.v.filter_set)->action.metric = (yyvsp[0].v.number);
			} else {
				(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_LOCALPREF;
				(yyval.v.filter_set)->action.relative = (yyvsp[0].v.number);
			}
		}
#line 5480 "parse.c"
    break;

  case 276: /* filter_set_opt: LOCALPREF '+' NUMBER  */
#line 2572 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT_MAX) {
				yyerror("bad localpref +%lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_LOCALPREF;
			(yyval.v.filter_set)->action.relative = (yyvsp[0].v.number);
		}
#line 5495 "parse.c"
    break;

  case 277: /* filter_set_opt: LOCALPREF '-' NUMBER  */
#line 2582 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT_MAX) {
				yyerror("bad localpref -%lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_LOCALPREF;
			(yyval.v.filter_set)->action.relative = -(yyvsp[0].v.number);
		}
#line 5510 "parse.c"
    break;

  case 278: /* filter_set_opt: MED NUMBER  */
#line 2592 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) < -INT_MAX || (yyvsp[0].v.number) > UINT_MAX) {
				yyerror("bad metric %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			if ((yyvsp[0].v.number) >= 0) {
				(yyval.v.filter_set)->type = ACTION_SET_MED;
				(yyval.v.filter_set)->action.metric = (yyvsp[0].v.number);
			} else {
				(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_MED;
				(yyval.v.filter_set)->action.relative = (yyvsp[0].v.number);
			}
		}
#line 5530 "parse.c"
    break;

  case 279: /* filter_set_opt: MED '+' NUMBER  */
#line 2607 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT_MAX) {
				yyerror("bad metric +%lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_MED;
			(yyval.v.filter_set)->action.relative = (yyvsp[0].v.number);
		}
#line 5545 "parse.c"
    break;

  case 280: /* filter_set_opt: MED '-' NUMBER  */
#line 2617 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT_MAX) {
				yyerror("bad metric -%lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_MED;
			(yyval.v.filter_set)->action.relative = -(yyvsp[0].v.number);
		}
#line 5560 "parse.c"
    break;

  case 281: /* filter_set_opt: METRIC NUMBER  */
#line 2627 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {	/* alias for MED */
			if ((yyvsp[0].v.number) < -INT_MAX || (yyvsp[0].v.number) > UINT_MAX) {
				yyerror("bad metric %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			if ((yyvsp[0].v.number) >= 0) {
				(yyval.v.filter_set)->type = ACTION_SET_MED;
				(yyval.v.filter_set)->action.metric = (yyvsp[0].v.number);
			} else {
				(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_MED;
				(yyval.v.filter_set)->action.relative = (yyvsp[0].v.number);
			}
		}
#line 5580 "parse.c"
    break;

  case 282: /* filter_set_opt: METRIC '+' NUMBER  */
#line 2642 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT_MAX) {
				yyerror("bad metric +%lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_MED;
			(yyval.v.filter_set)->action.metric = (yyvsp[0].v.number);
		}
#line 5595 "parse.c"
    break;

  case 283: /* filter_set_opt: METRIC '-' NUMBER  */
#line 2652 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT_MAX) {
				yyerror("bad metric -%lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_MED;
			(yyval.v.filter_set)->action.relative = -(yyvsp[0].v.number);
		}
#line 5610 "parse.c"
    break;

  case 284: /* filter_set_opt: WEIGHT NUMBER  */
#line 2662 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((yyvsp[0].v.number) < -INT_MAX || (yyvsp[0].v.number) > UINT_MAX) {
				yyerror("bad weight %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			if ((yyvsp[0].v.number) > 0) {
				(yyval.v.filter_set)->type = ACTION_SET_WEIGHT;
				(yyval.v.filter_set)->action.metric = (yyvsp[0].v.number);
			} else {
				(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_WEIGHT;
				(yyval.v.filter_set)->action.relative = (yyvsp[0].v.number);
			}
		}
#line 5630 "parse.c"
    break;

  case 285: /* filter_set_opt: WEIGHT '+' NUMBER  */
#line 2677 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT_MAX) {
				yyerror("bad weight +%lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_WEIGHT;
			(yyval.v.filter_set)->action.relative = (yyvsp[0].v.number);
		}
#line 5645 "parse.c"
    break;

  case 286: /* filter_set_opt: WEIGHT '-' NUMBER  */
#line 2687 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT_MAX) {
				yyerror("bad weight -%lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_RELATIVE_WEIGHT;
			(yyval.v.filter_set)->action.relative = -(yyvsp[0].v.number);
		}
#line 5660 "parse.c"
    break;

  case 287: /* filter_set_opt: NEXTHOP address  */
#line 2697 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP;
			memcpy(&(yyval.v.filter_set)->action.nexthop, &(yyvsp[0].v.addr),
			    sizeof((yyval.v.filter_set)->action.nexthop));
		}
#line 5672 "parse.c"
    break;

  case 288: /* filter_set_opt: NEXTHOP BLACKHOLE  */
#line 2704 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_BLACKHOLE;
		}
#line 5682 "parse.c"
    break;

  case 289: /* filter_set_opt: NEXTHOP REJECT  */
#line 2709 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_REJECT;
		}
#line 5692 "parse.c"
    break;

  case 290: /* filter_set_opt: NEXTHOP NOMODIFY  */
#line 2714 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_NOMODIFY;
		}
#line 5702 "parse.c"
    break;

  case 291: /* filter_set_opt: NEXTHOP SELF  */
#line 2719 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_SELF;
		}
#line 5712 "parse.c"
    break;

  case 292: /* filter_set_opt: PREPEND_SELF NUMBER  */
#line 2724 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > 128) {
				yyerror("bad number of prepends");
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_PREPEND_SELF;
			(yyval.v.filter_set)->action.prepend = (yyvsp[0].v.number);
		}
#line 5727 "parse.c"
    break;

  case 293: /* filter_set_opt: PREPEND_PEER NUMBER  */
#line 2734 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > 128) {
				yyerror("bad number of prepends");
				YYERROR;
			}
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_PREPEND_PEER;
			(yyval.v.filter_set)->action.prepend = (yyvsp[0].v.number);
		}
#line 5742 "parse.c"
    break;

  case 294: /* filter_set_opt: ASOVERRIDE  */
#line 2744 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_AS_OVERRIDE;
		}
#line 5752 "parse.c"
    break;

  case 295: /* filter_set_opt: PFTABLE STRING  */
#line 2749 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_PFTABLE;
			if (!(cmd_opts & BGPD_OPT_NOACTION) &&
			    pftable_exists((yyvsp[0].v.string)) != 0) {
				yyerror("pftable name does not exist");
				free((yyvsp[0].v.string));
				free((yyval.v.filter_set));
				YYERROR;
			}
			if (strlcpy((yyval.v.filter_set)->action.pftable, (yyvsp[0].v.string),
			    sizeof((yyval.v.filter_set)->action.pftable)) >=
			    sizeof((yyval.v.filter_set)->action.pftable)) {
				yyerror("pftable name too long");
				free((yyvsp[0].v.string));
				free((yyval.v.filter_set));
				YYERROR;
			}
			if (pftable_add((yyvsp[0].v.string)) != 0) {
				yyerror("Couldn't register table");
				free((yyvsp[0].v.string));
				free((yyval.v.filter_set));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 5784 "parse.c"
    break;

  case 296: /* filter_set_opt: RTLABEL STRING  */
#line 2776 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_RTLABEL;
			if (strlcpy((yyval.v.filter_set)->action.rtlabel, (yyvsp[0].v.string),
			    sizeof((yyval.v.filter_set)->action.rtlabel)) >=
			    sizeof((yyval.v.filter_set)->action.rtlabel)) {
				yyerror("rtlabel name too long");
				free((yyvsp[0].v.string));
				free((yyval.v.filter_set));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 5803 "parse.c"
    break;

  case 297: /* filter_set_opt: community delete STRING  */
#line 2790 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			uint8_t f1, f2, f3;

			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			if ((yyvsp[-1].v.u8))
				(yyval.v.filter_set)->type = ACTION_DEL_COMMUNITY;
			else
				(yyval.v.filter_set)->type = ACTION_SET_COMMUNITY;

			if (parsecommunity(&(yyval.v.filter_set)->action.community, (yyvsp[-2].v.u8), (yyvsp[0].v.string)) ==
			    -1) {
				free((yyvsp[0].v.string));
				free((yyval.v.filter_set));
				YYERROR;
			}
			free((yyvsp[0].v.string));
			/* Don't allow setting of any match */
			f1 = (yyval.v.filter_set)->action.community.flags >> 8;
			f2 = (yyval.v.filter_set)->action.community.flags >> 16;
			f3 = (yyval.v.filter_set)->action.community.flags >> 24;
			if (!(yyvsp[-1].v.u8) && (f1 == COMMUNITY_ANY ||
			    f2 == COMMUNITY_ANY || f3 == COMMUNITY_ANY)) {
				yyerror("'*' is not allowed in set community");
				free((yyval.v.filter_set));
				YYERROR;
			}
		}
#line 5836 "parse.c"
    break;

  case 298: /* filter_set_opt: EXTCOMMUNITY delete STRING STRING  */
#line 2818 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			if ((yyvsp[-2].v.u8))
				(yyval.v.filter_set)->type = ACTION_DEL_COMMUNITY;
			else
				(yyval.v.filter_set)->type = ACTION_SET_COMMUNITY;

			if (parseextcommunity(&(yyval.v.filter_set)->action.community,
			    (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1) {
				free((yyvsp[-1].v.string));
				free((yyvsp[0].v.string));
				free((yyval.v.filter_set));
				YYERROR;
			}
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.string));
		}
#line 5859 "parse.c"
    break;

  case 299: /* filter_set_opt: EXTCOMMUNITY delete OVS STRING  */
#line 2836 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                 {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			if ((yyvsp[-2].v.u8))
				(yyval.v.filter_set)->type = ACTION_DEL_COMMUNITY;
			else
				(yyval.v.filter_set)->type = ACTION_SET_COMMUNITY;

			if (parseextcommunity(&(yyval.v.filter_set)->action.community,
			    "ovs", (yyvsp[0].v.string)) == -1) {
				free((yyvsp[0].v.string));
				free((yyval.v.filter_set));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 5880 "parse.c"
    break;

  case 300: /* filter_set_opt: ORIGIN origincode  */
#line 2852 "../../../openbgpd-portable/src/bgpd/parse.y"
                                    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_ORIGIN;
			(yyval.v.filter_set)->action.origin = (yyvsp[0].v.number);
		}
#line 5891 "parse.c"
    break;

  case 301: /* origincode: STRING  */
#line 2860 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (!strcmp((yyvsp[0].v.string), "egp"))
				(yyval.v.number) = ORIGIN_EGP;
			else if (!strcmp((yyvsp[0].v.string), "igp"))
				(yyval.v.number) = ORIGIN_IGP;
			else if (!strcmp((yyvsp[0].v.string), "incomplete"))
				(yyval.v.number) = ORIGIN_INCOMPLETE;
			else {
				yyerror("unknown origin \"%s\"", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 5910 "parse.c"
    break;

  case 302: /* validity: STRING  */
#line 2875 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (!strcmp((yyvsp[0].v.string), "not-found"))
				(yyval.v.number) = ROA_NOTFOUND;
			else if (!strcmp((yyvsp[0].v.string), "invalid"))
				(yyval.v.number) = ROA_INVALID;
			else if (!strcmp((yyvsp[0].v.string), "valid"))
				(yyval.v.number) = ROA_VALID;
			else {
				yyerror("unknown validity \"%s\"", (yyvsp[0].v.string));
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 5929 "parse.c"
    break;

  case 309: /* unaryop: '='  */
#line 2900 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_EQ; }
#line 5935 "parse.c"
    break;

  case 310: /* unaryop: NE  */
#line 2901 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_NE; }
#line 5941 "parse.c"
    break;

  case 311: /* unaryop: LE  */
#line 2902 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_LE; }
#line 5947 "parse.c"
    break;

  case 312: /* unaryop: '<'  */
#line 2903 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_LT; }
#line 5953 "parse.c"
    break;

  case 313: /* unaryop: GE  */
#line 2904 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_GE; }
#line 5959 "parse.c"
    break;

  case 314: /* unaryop: '>'  */
#line 2905 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_GT; }
#line 5965 "parse.c"
    break;

  case 315: /* equalityop: '='  */
#line 2908 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_EQ; }
#line 5971 "parse.c"
    break;

  case 316: /* equalityop: NE  */
#line 2909 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_NE; }
#line 5977 "parse.c"
    break;

  case 317: /* binaryop: '-'  */
#line 2912 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_RANGE; }
#line 5983 "parse.c"
    break;

  case 318: /* binaryop: XRANGE  */
#line 2913 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_XRANGE; }
#line 5989 "parse.c"
    break;


#line 5993 "parse.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2916 "../../../openbgpd-portable/src/bgpd/parse.y"


struct keywords {
	const char	*k_name;
	int		 k_val;
};

int
yyerror(const char *fmt, ...)
{
	va_list		 ap;
	char		*msg;

	file->errors++;
	va_start(ap, fmt);
	if (vasprintf(&msg, fmt, ap) == -1)
		fatalx("yyerror vasprintf");
	va_end(ap);
	logit(LOG_CRIT, "%s:%d: %s", file->name, yylval.lineno, msg);
	free(msg);
	return (0);
}

int
kw_cmp(const void *k, const void *e)
{
	return (strcmp(k, ((const struct keywords *)e)->k_name));
}

int
lookup(char *s)
{
	/* this has to be sorted always */
	static const struct keywords keywords[] = {
		{ "AS",			AS},
		{ "IPv4",		IPV4},
		{ "IPv6",		IPV6},
		{ "add-path",		ADDPATH},
		{ "ah",			AH},
		{ "allow",		ALLOW},
		{ "announce",		ANNOUNCE},
		{ "any",		ANY},
		{ "as-4byte",		AS4BYTE },
		{ "as-override",	ASOVERRIDE},
		{ "as-set",		ASSET },
		{ "blackhole",		BLACKHOLE},
		{ "capabilities",	CAPABILITIES},
		{ "community",		COMMUNITY},
		{ "compare",		COMPARE},
		{ "connect-retry",	CONNECTRETRY},
		{ "connected",		CONNECTED},
		{ "default-route",	DEFAULTROUTE},
		{ "delete",		DELETE},
		{ "demote",		DEMOTE},
		{ "deny",		DENY},
		{ "depend",		DEPEND},
		{ "descr",		DESCR},
		{ "down",		DOWN},
		{ "dump",		DUMP},
		{ "ebgp",		EBGP},
		{ "enforce",		ENFORCE},
		{ "enhanced",		ENHANCED },
		{ "esp",		ESP},
		{ "evaluate",		EVALUATE},
		{ "expires",		EXPIRES},
		{ "export",		EXPORT},
		{ "export-target",	EXPORTTRGT},
		{ "ext-community",	EXTCOMMUNITY},
		{ "fib-priority",	FIBPRIORITY},
		{ "fib-update",		FIBUPDATE},
		{ "from",		FROM},
		{ "group",		GROUP},
		{ "holdtime",		HOLDTIME},
		{ "ibgp",		IBGP},
		{ "ignore",		IGNORE},
		{ "ike",		IKE},
		{ "import-target",	IMPORTTRGT},
		{ "in",			IN},
		{ "include",		INCLUDE},
		{ "inet",		IPV4},
		{ "inet6",		IPV6},
		{ "ipsec",		IPSEC},
		{ "key",		KEY},
		{ "large-community",	LARGECOMMUNITY},
		{ "listen",		LISTEN},
		{ "local-address",	LOCALADDR},
		{ "local-as",		LOCALAS},
		{ "localpref",		LOCALPREF},
		{ "log",		LOG},
		{ "match",		MATCH},
		{ "max-as-len",		MAXASLEN},
		{ "max-as-seq",		MAXASSEQ},
		{ "max-prefix",		MAXPREFIX},
		{ "maxlen",		MAXLEN},
		{ "md5sig",		MD5SIG},
		{ "med",		MED},
		{ "metric",		METRIC},
		{ "min",		YMIN},
		{ "multihop",		MULTIHOP},
		{ "neighbor",		NEIGHBOR},
		{ "neighbor-as",	NEIGHBORAS},
		{ "network",		NETWORK},
		{ "nexthop",		NEXTHOP},
		{ "no-modify",		NOMODIFY},
		{ "none",		NONE},
		{ "on",			ON},
		{ "or-longer",		LONGER},
		{ "origin",		ORIGIN},
		{ "origin-set",		ORIGINSET},
		{ "out",		OUT},
		{ "ovs",		OVS},
		{ "passive",		PASSIVE},
		{ "password",		PASSWORD},
		{ "peer-as",		PEERAS},
		{ "pftable",		PFTABLE},
		{ "port",		PORT},
		{ "prefix",		PREFIX},
		{ "prefix-set",		PREFIXSET},
		{ "prefixlen",		PREFIXLEN},
		{ "prepend-neighbor",	PREPEND_PEER},
		{ "prepend-self",	PREPEND_SELF},
		{ "priority",		PRIORITY},
		{ "qualify",		QUALIFY},
		{ "quick",		QUICK},
		{ "rd",			RD},
		{ "rde",		RDE},
		{ "recv",		RECV},
		{ "refresh",		REFRESH },
		{ "reject",		REJECT},
		{ "remote-as",		REMOTEAS},
		{ "restart",		RESTART},
		{ "restricted",		RESTRICTED},
		{ "rib",		RIB},
		{ "roa-set",		ROASET },
		{ "route-reflector",	REFLECTOR},
		{ "router-id",		ROUTERID},
		{ "rtable",		RTABLE},
		{ "rtlabel",		RTLABEL},
		{ "rtr",		RTR},
		{ "self",		SELF},
		{ "send",		SEND},
		{ "set",		SET},
		{ "socket",		SOCKET },
		{ "source-as",		SOURCEAS},
		{ "spi",		SPI},
		{ "static",		STATIC},
		{ "tcp",		TCP},
		{ "to",			TO},
		{ "transit-as",		TRANSITAS},
		{ "transparent-as",	TRANSPARENT},
		{ "ttl-security",	TTLSECURITY},
		{ "unicast",		UNICAST},
		{ "via",		VIA},
		{ "vpn",		VPN},
		{ "weight",		WEIGHT}
	};
	const struct keywords	*p;

	p = bsearch(s, keywords, sizeof(keywords)/sizeof(keywords[0]),
	    sizeof(keywords[0]), kw_cmp);

	if (p)
		return (p->k_val);
	else
		return (STRING);
}

#define START_EXPAND	1
#define DONE_EXPAND	2

static int	expanding;

int
igetc(void)
{
	int	c;

	while (1) {
		if (file->ungetpos > 0)
			c = file->ungetbuf[--file->ungetpos];
		else
			c = getc(file->stream);

		if (c == START_EXPAND)
			expanding = 1;
		else if (c == DONE_EXPAND)
			expanding = 0;
		else
			break;
	}
	return (c);
}

int
lgetc(int quotec)
{
	int		c, next;

	if (quotec) {
		if ((c = igetc()) == EOF) {
			yyerror("reached end of file while parsing "
			    "quoted string");
			if (file == topfile || popfile() == EOF)
				return (EOF);
			return (quotec);
		}
		return (c);
	}

	while ((c = igetc()) == '\\') {
		next = igetc();
		if (next != '\n') {
			c = next;
			break;
		}
		yylval.lineno = file->lineno;
		file->lineno++;
	}

	if (c == EOF) {
		/*
		 * Fake EOL when hit EOF for the first time. This gets line
		 * count right if last line in included file is syntactically
		 * invalid and has no newline.
		 */
		if (file->eof_reached == 0) {
			file->eof_reached = 1;
			return ('\n');
		}
		while (c == EOF) {
			if (file == topfile || popfile() == EOF)
				return (EOF);
			c = igetc();
		}
	}
	return (c);
}

void
lungetc(int c)
{
	if (c == EOF)
		return;

	if (file->ungetpos >= file->ungetsize) {
		void *p = reallocarray(file->ungetbuf, file->ungetsize, 2);
		if (p == NULL)
			err(1, "lungetc");
		file->ungetbuf = p;
		file->ungetsize *= 2;
	}
	file->ungetbuf[file->ungetpos++] = c;
}

int
findeol(void)
{
	int	c;

	/* skip to either EOF or the first real EOL */
	while (1) {
		c = lgetc(0);
		if (c == '\n') {
			file->lineno++;
			break;
		}
		if (c == EOF)
			break;
	}
	return (ERROR);
}

int
expand_macro(void)
{
	char	 buf[MACRO_NAME_LEN];
	char	*p, *val;
	int	 c;

	p = buf;
	while (1) {
		if ((c = lgetc('$')) == EOF)
			return (ERROR);
		if (p + 1 >= buf + sizeof(buf) - 1) {
			yyerror("macro name too long");
			return (ERROR);
		}
		if (isalnum(c) || c == '_') {
			*p++ = c;
			continue;
		}
		*p = '\0';
		lungetc(c);
		break;
	}
	val = symget(buf);
	if (val == NULL)
		yyerror("macro '%s' not defined", buf);
	p = val + strlen(val) - 1;
	lungetc(DONE_EXPAND);
	while (p >= val) {
		lungetc((unsigned char)*p);
		p--;
	}
	lungetc(START_EXPAND);
	return (0);
}

int
yylex(void)
{
	char	 buf[8096];
	char	*p;
	int	 quotec, next, c;
	int	 token;

top:
	p = buf;
	while ((c = lgetc(0)) == ' ' || c == '\t')
		; /* nothing */

	yylval.lineno = file->lineno;
	if (c == '#')
		while ((c = lgetc(0)) != '\n' && c != EOF)
			; /* nothing */
	if (c == '$' && !expanding) {
		c = expand_macro();
		if (c != 0)
			return (c);
		goto top;
	}

	switch (c) {
	case '\'':
	case '"':
		quotec = c;
		while (1) {
			if ((c = lgetc(quotec)) == EOF)
				return (0);
			if (c == '\n') {
				file->lineno++;
				continue;
			} else if (c == '\\') {
				if ((next = lgetc(quotec)) == EOF)
					return (0);
				if (next == quotec || next == ' ' ||
				    next == '\t')
					c = next;
				else if (next == '\n') {
					file->lineno++;
					continue;
				} else
					lungetc(next);
			} else if (c == quotec) {
				*p = '\0';
				break;
			} else if (c == '\0') {
				yyerror("syntax error: unterminated quote");
				return (findeol());
			}
			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			*p++ = c;
		}
		yylval.v.string = strdup(buf);
		if (yylval.v.string == NULL)
			fatal("yylex: strdup");
		return (STRING);
	case '!':
		next = lgetc(0);
		if (next == '=')
			return (NE);
		lungetc(next);
		break;
	case '<':
		next = lgetc(0);
		if (next == '=')
			return (LE);
		lungetc(next);
		break;
	case '>':
		next = lgetc(0);
		if (next == '<')
			return (XRANGE);
		else if (next == '=')
			return (GE);
		lungetc(next);
		break;
	}

#define allowed_to_end_number(x) \
	(isspace(x) || x == ')' || x ==',' || x == '/' || x == '}' || x == '=')

	if (c == '-' || isdigit(c)) {
		do {
			*p++ = c;
			if ((size_t)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && isdigit(c));
		lungetc(c);
		if (p == buf + 1 && buf[0] == '-')
			goto nodigits;
		if (c == EOF || allowed_to_end_number(c)) {
			const char *errstr = NULL;

			*p = '\0';
			yylval.v.number = strtonum(buf, LLONG_MIN,
			    LLONG_MAX, &errstr);
			if (errstr) {
				yyerror("\"%s\" invalid number: %s",
				    buf, errstr);
				return (findeol());
			}
			return (NUMBER);
		} else {
nodigits:
			while (p > buf + 1)
				lungetc((unsigned char)*--p);
			c = (unsigned char)*--p;
			if (c == '-')
				return (c);
		}
	}

#define allowed_in_string(x) \
	(isalnum(x) || (ispunct(x) && x != '(' && x != ')' && \
	x != '{' && x != '}' && x != '<' && x != '>' && \
	x != '!' && x != '=' && x != '/' && x != '#' && \
	x != ','))

	if (isalnum(c) || c == ':' || c == '_' || c == '*') {
		do {
			if (c == '$' && !expanding) {
				c = expand_macro();
				if (c != 0)
					return (c);
			} else
				*p++ = c;

			if ((size_t)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && (allowed_in_string(c)));
		lungetc(c);
		*p = '\0';
		if ((token = lookup(buf)) == STRING)
			if ((yylval.v.string = strdup(buf)) == NULL)
				fatal("yylex: strdup");
		return (token);
	}
	if (c == '\n') {
		yylval.lineno = file->lineno;
		file->lineno++;
	}
	if (c == EOF)
		return (0);
	return (c);
}

int
check_file_secrecy(int fd, const char *fname)
{
	struct stat	st;

	if (fstat(fd, &st)) {
		log_warn("cannot stat %s", fname);
		return (-1);
	}
	return (0);
}

struct file *
pushfile(const char *name, int secret)
{
	struct file	*nfile;

	if ((nfile = calloc(1, sizeof(struct file))) == NULL) {
		log_warn("%s", __func__);
		return (NULL);
	}
	if ((nfile->name = strdup(name)) == NULL) {
		log_warn("%s", __func__);
		free(nfile);
		return (NULL);
	}
	if ((nfile->stream = fopen(nfile->name, "r")) == NULL) {
		log_warn("%s: %s", __func__, nfile->name);
		free(nfile->name);
		free(nfile);
		return (NULL);
	}
	if (secret &&
	    check_file_secrecy(fileno(nfile->stream), nfile->name)) {
		fclose(nfile->stream);
		free(nfile->name);
		free(nfile);
		return (NULL);
	}
	nfile->lineno = TAILQ_EMPTY(&files) ? 1 : 0;
	nfile->ungetsize = 16;
	nfile->ungetbuf = malloc(nfile->ungetsize);
	if (nfile->ungetbuf == NULL) {
		log_warn("%s", __func__);
		fclose(nfile->stream);
		free(nfile->name);
		free(nfile);
		return (NULL);
	}
	TAILQ_INSERT_TAIL(&files, nfile, entry);
	return (nfile);
}

int
popfile(void)
{
	struct file	*prev;

	if ((prev = TAILQ_PREV(file, files, entry)) != NULL)
		prev->errors += file->errors;

	TAILQ_REMOVE(&files, file, entry);
	fclose(file->stream);
	free(file->name);
	free(file->ungetbuf);
	free(file);
	file = prev;
	return (file ? 0 : EOF);
}

static void
init_config(struct bgpd_config *c)
{
	u_int rdomid;

	c->min_holdtime = MIN_HOLDTIME;
	c->holdtime = INTERVAL_HOLD;
	c->connectretry = INTERVAL_CONNECTRETRY;
	c->bgpid = get_bgpid();
	c->fib_priority = RTP_BGP;
	c->default_tableid = getrtable();
	ktable_exists(c->default_tableid, &rdomid);
	if (rdomid != c->default_tableid)
		fatalx("current routing table %u is not a routing domain",
		    c->default_tableid);

	if (asprintf(&c->csock, "%s.%d", SOCKET_NAME, c->default_tableid) == -1)
		fatal(NULL);
}

struct bgpd_config *
parse_config(char *filename, struct peer_head *ph, struct rtr_config_head *rh)
{
	struct sym		*sym, *next;
	struct rde_rib		*rr;
	struct network		*n;
	int			 errors = 0;

	conf = new_config();
	init_config(conf);

	if ((filter_l = calloc(1, sizeof(struct filter_head))) == NULL)
		fatal(NULL);
	if ((peerfilter_l = calloc(1, sizeof(struct filter_head))) == NULL)
		fatal(NULL);
	if ((groupfilter_l = calloc(1, sizeof(struct filter_head))) == NULL)
		fatal(NULL);
	TAILQ_INIT(filter_l);
	TAILQ_INIT(peerfilter_l);
	TAILQ_INIT(groupfilter_l);

	curpeer = NULL;
	curgroup = NULL;

	cur_peers = ph;
	cur_rtrs = rh;
	new_peers = &conf->peers;
	netconf = &conf->networks;

	if ((rr = add_rib("Adj-RIB-In")) == NULL)
		fatal("add_rib failed");
	rr->flags = F_RIB_NOFIB | F_RIB_NOEVALUATE;
	if ((rr = add_rib("Loc-RIB")) == NULL)
		fatal("add_rib failed");
	rib_add_fib(rr, conf->default_tableid);
	rr->flags = F_RIB_LOCAL;

	if ((file = pushfile(filename, 1)) == NULL)
		goto errors;
	topfile = file;

	yyparse();
	errors = file->errors;
	popfile();

	/* check that we dont try to announce our own routes */
	TAILQ_FOREACH(n, netconf, entry)
	    if (n->net.priority == conf->fib_priority) {
		    errors++;
		    logit(LOG_CRIT, "network priority %d == fib-priority "
			"%d is not allowed.",
			n->net.priority, conf->fib_priority);
	    }

	/* Free macros and check which have not been used. */
	TAILQ_FOREACH_SAFE(sym, &symhead, entry, next) {
		if ((cmd_opts & BGPD_OPT_VERBOSE2) && !sym->used)
			fprintf(stderr, "warning: macro \"%s\" not "
			    "used\n", sym->nam);
		if (!sym->persist) {
			free(sym->nam);
			free(sym->val);
			TAILQ_REMOVE(&symhead, sym, entry);
			free(sym);
		}
	}

	if (!conf->as) {
		log_warnx("configuration error: AS not given");
		errors++;
	}

	/* clear the globals */
	curpeer = NULL;
	curgroup = NULL;
	cur_peers = NULL;
	new_peers = NULL;
	netconf = NULL;

	if (errors) {
errors:
		while ((rr = SIMPLEQ_FIRST(&ribnames)) != NULL) {
			SIMPLEQ_REMOVE_HEAD(&ribnames, entry);
			free(rr);
		}

		filterlist_free(filter_l);
		filterlist_free(peerfilter_l);
		filterlist_free(groupfilter_l);

		free_config(conf);
		return (NULL);
	}

	/* Create default listeners if none where specified. */
	if (TAILQ_EMPTY(conf->listen_addrs)) {
		struct listen_addr *la;

		if ((la = calloc(1, sizeof(struct listen_addr))) == NULL)
			fatal("setup_listeners calloc");
		la->fd = -1;
		la->flags = DEFAULT_LISTENER;
		la->reconf = RECONF_REINIT;
		la->sa_len = sizeof(struct sockaddr_in);
		((struct sockaddr_in *)&la->sa)->sin_family = AF_INET;
		((struct sockaddr_in *)&la->sa)->sin_addr.s_addr =
		    htonl(INADDR_ANY);
		((struct sockaddr_in *)&la->sa)->sin_port = htons(BGP_PORT);
		TAILQ_INSERT_TAIL(conf->listen_addrs, la, entry);

		if ((la = calloc(1, sizeof(struct listen_addr))) == NULL)
			fatal("setup_listeners calloc");
		la->fd = -1;
		la->flags = DEFAULT_LISTENER;
		la->reconf = RECONF_REINIT;
		la->sa_len = sizeof(struct sockaddr_in6);
		((struct sockaddr_in6 *)&la->sa)->sin6_family = AF_INET6;
		((struct sockaddr_in6 *)&la->sa)->sin6_port = htons(BGP_PORT);
		TAILQ_INSERT_TAIL(conf->listen_addrs, la, entry);
	}

	/* update clusterid in case it was not set explicitly */
	if ((conf->flags & BGPD_FLAG_REFLECTOR) && conf->clusterid == 0)
		conf->clusterid = conf->bgpid;

	/*
	 * Concatenate filter list and static group and peer filtersets
	 * together. Static group sets come first then peer sets
	 * last normal filter rules.
	 */
	TAILQ_CONCAT(conf->filters, groupfilter_l, entry);
	TAILQ_CONCAT(conf->filters, peerfilter_l, entry);
	TAILQ_CONCAT(conf->filters, filter_l, entry);

	optimize_filters(conf->filters);

	free(filter_l);
	free(peerfilter_l);
	free(groupfilter_l);

	return (conf);
}

int
symset(const char *nam, const char *val, int persist)
{
	struct sym	*sym;

	TAILQ_FOREACH(sym, &symhead, entry) {
		if (strcmp(nam, sym->nam) == 0)
			break;
	}

	if (sym != NULL) {
		if (sym->persist == 1)
			return (0);
		else {
			free(sym->nam);
			free(sym->val);
			TAILQ_REMOVE(&symhead, sym, entry);
			free(sym);
		}
	}
	if ((sym = calloc(1, sizeof(*sym))) == NULL)
		return (-1);

	sym->nam = strdup(nam);
	if (sym->nam == NULL) {
		free(sym);
		return (-1);
	}
	sym->val = strdup(val);
	if (sym->val == NULL) {
		free(sym->nam);
		free(sym);
		return (-1);
	}
	sym->used = 0;
	sym->persist = persist;
	TAILQ_INSERT_TAIL(&symhead, sym, entry);
	return (0);
}

int
cmdline_symset(char *s)
{
	char	*sym, *val;
	int	ret;

	if ((val = strrchr(s, '=')) == NULL)
		return (-1);
	sym = strndup(s, val - s);
	if (sym == NULL)
		fatal("%s: strndup", __func__);
	ret = symset(sym, val + 1, 1);
	free(sym);

	return (ret);
}

char *
symget(const char *nam)
{
	struct sym	*sym;

	TAILQ_FOREACH(sym, &symhead, entry) {
		if (strcmp(nam, sym->nam) == 0) {
			sym->used = 1;
			return (sym->val);
		}
	}
	return (NULL);
}

static int
cmpcommunity(struct community *a, struct community *b)
{
	if (a->flags > b->flags)
		return 1;
	if (a->flags < b->flags)
		return -1;
	if (a->data1 > b->data1)
		return 1;
	if (a->data1 < b->data1)
		return -1;
	if (a->data2 > b->data2)
		return 1;
	if (a->data2 < b->data2)
		return -1;
	if (a->data3 > b->data3)
		return 1;
	if (a->data3 < b->data3)
		return -1;
	return 0;
}

static int
getcommunity(char *s, int large, uint32_t *val, uint32_t *flag)
{
	long long	 max = USHRT_MAX;
	const char	*errstr;

	*flag = 0;
	*val = 0;
	if (strcmp(s, "*") == 0) {
		*flag = COMMUNITY_ANY;
		return 0;
	} else if (strcmp(s, "neighbor-as") == 0) {
		*flag = COMMUNITY_NEIGHBOR_AS;
		return 0;
	} else if (strcmp(s, "local-as") == 0) {
		*flag =  COMMUNITY_LOCAL_AS;
		return 0;
	}
	if (large)
		max = UINT_MAX;
	*val = strtonum(s, 0, max, &errstr);
	if (errstr) {
		yyerror("Community %s is %s (max: %lld)", s, errstr, max);
		return -1;
	}
	return 0;
}

static void
setcommunity(struct community *c, uint32_t as, uint32_t data,
    uint32_t asflag, uint32_t dataflag)
{
	c->flags = COMMUNITY_TYPE_BASIC;
	c->flags |= asflag << 8;
	c->flags |= dataflag << 16;
	c->data1 = as;
	c->data2 = data;
	c->data3 = 0;
}

static int
parselargecommunity(struct community *c, char *s)
{
	char *p, *q;
	uint32_t dflag1, dflag2, dflag3;

	if ((p = strchr(s, ':')) == NULL) {
		yyerror("Bad community syntax");
		return (-1);
	}
	*p++ = 0;

	if ((q = strchr(p, ':')) == NULL) {
		yyerror("Bad community syntax");
		return (-1);
	}
	*q++ = 0;

	if (getcommunity(s, 1, &c->data1, &dflag1) == -1 ||
	    getcommunity(p, 1, &c->data2, &dflag2) == -1 ||
	    getcommunity(q, 1, &c->data3, &dflag3) == -1)
		return (-1);
	c->flags = COMMUNITY_TYPE_LARGE;
	c->flags |= dflag1 << 8;;
	c->flags |= dflag2 << 16;;
	c->flags |= dflag3 << 24;;
	return (0);
}

int
parsecommunity(struct community *c, int type, char *s)
{
	char *p;
	uint32_t as, data, asflag, dataflag;

	if (type == COMMUNITY_TYPE_LARGE)
		return parselargecommunity(c, s);

	/* Well-known communities */
	if (strcasecmp(s, "GRACEFUL_SHUTDOWN") == 0) {
		setcommunity(c, COMMUNITY_WELLKNOWN,
		    COMMUNITY_GRACEFUL_SHUTDOWN, 0, 0);
		return (0);
	} else if (strcasecmp(s, "NO_EXPORT") == 0) {
		setcommunity(c, COMMUNITY_WELLKNOWN,
		    COMMUNITY_NO_EXPORT, 0, 0);
		return (0);
	} else if (strcasecmp(s, "NO_ADVERTISE") == 0) {
		setcommunity(c, COMMUNITY_WELLKNOWN,
		    COMMUNITY_NO_ADVERTISE, 0, 0);
		return (0);
	} else if (strcasecmp(s, "NO_EXPORT_SUBCONFED") == 0) {
		setcommunity(c, COMMUNITY_WELLKNOWN,
		    COMMUNITY_NO_EXPSUBCONFED, 0, 0);
		return (0);
	} else if (strcasecmp(s, "NO_PEER") == 0) {
		setcommunity(c, COMMUNITY_WELLKNOWN,
		    COMMUNITY_NO_PEER, 0, 0);
		return (0);
	} else if (strcasecmp(s, "BLACKHOLE") == 0) {
		setcommunity(c, COMMUNITY_WELLKNOWN,
		    COMMUNITY_BLACKHOLE, 0, 0);
		return (0);
	}

	if ((p = strchr(s, ':')) == NULL) {
		yyerror("Bad community syntax");
		return (-1);
	}
	*p++ = 0;

	if (getcommunity(s, 0, &as, &asflag) == -1 ||
	    getcommunity(p, 0, &data, &dataflag) == -1)
		return (-1);
	setcommunity(c, as, data, asflag, dataflag);
	return (0);
}

static int
parsesubtype(char *name, int *type, int *subtype)
{
	const struct ext_comm_pairs *cp;
	int found = 0;

	for (cp = iana_ext_comms; cp->subname != NULL; cp++) {
		if (strcmp(name, cp->subname) == 0) {
			if (found == 0) {
				*type = cp->type;
				*subtype = cp->subtype;
			}
			found++;
		}
	}
	if (found > 1)
		*type = -1;
	return (found);
}

static int
parseextvalue(int type, char *s, uint32_t *v, uint32_t *flag)
{
	const char	*errstr;
	char		*p;
	struct in_addr	 ip;
	uint32_t	 uvalh, uval;

	if (type != -1) {
		/* nothing */
	} else if (strcmp(s, "neighbor-as") == 0) {
		*flag = COMMUNITY_NEIGHBOR_AS;
		*v = 0;
		return EXT_COMMUNITY_TRANS_FOUR_AS;
	} else if (strcmp(s, "local-as") == 0) {
		*flag = COMMUNITY_LOCAL_AS;
		*v = 0;
		return EXT_COMMUNITY_TRANS_FOUR_AS;
	} else if ((p = strchr(s, '.')) == NULL) {
		/* AS_PLAIN number (4 or 2 byte) */
		strtonum(s, 0, USHRT_MAX, &errstr);
		if (errstr == NULL)
			type = EXT_COMMUNITY_TRANS_TWO_AS;
		else
			type = EXT_COMMUNITY_TRANS_FOUR_AS;
	} else if (strchr(p + 1, '.') == NULL) {
		/* AS_DOT number (4-byte) */
		type = EXT_COMMUNITY_TRANS_FOUR_AS;
	} else {
		/* more than one dot -> IP address */
		type = EXT_COMMUNITY_TRANS_IPV4;
	}

	switch (type) {
	case EXT_COMMUNITY_TRANS_TWO_AS:
		uval = strtonum(s, 0, USHRT_MAX, &errstr);
		if (errstr) {
			yyerror("Bad ext-community %s is %s", s, errstr);
			return (-1);
		}
		*v = uval;
		break;
	case EXT_COMMUNITY_TRANS_FOUR_AS:
		if ((p = strchr(s, '.')) == NULL) {
			uval = strtonum(s, 0, UINT_MAX, &errstr);
			if (errstr) {
				yyerror("Bad ext-community %s is %s", s,
				    errstr);
				return (-1);
			}
			*v = uval;
			break;
		}
		*p++ = '\0';
		uvalh = strtonum(s, 0, USHRT_MAX, &errstr);
		if (errstr) {
			yyerror("Bad ext-community %s is %s", s, errstr);
			return (-1);
		}
		uval = strtonum(p, 0, USHRT_MAX, &errstr);
		if (errstr) {
			yyerror("Bad ext-community %s is %s", p, errstr);
			return (-1);
		}
		*v = uval | (uvalh << 16);
		break;
	case EXT_COMMUNITY_TRANS_IPV4:
		if (inet_aton(s, &ip) == 0) {
			yyerror("Bad ext-community %s not parseable", s);
			return (-1);
		}
		*v = ntohl(ip.s_addr);
		break;
	default:
		fatalx("%s: unexpected type %d", __func__, type);
	}
	return (type);
}

int
parseextcommunity(struct community *c, char *t, char *s)
{
	const struct ext_comm_pairs *cp;
	char		*p, *ep;
	uint64_t	 ullval;
	uint32_t	 uval, uval2, dflag1 = 0, dflag2 = 0;
	int		 type = 0, subtype = 0;

	if (strcmp(t, "*") == 0 && strcmp(s, "*") == 0) {
		c->flags = COMMUNITY_TYPE_EXT;
		c->flags |= COMMUNITY_ANY << 24;
		return (0);
	}
	if (parsesubtype(t, &type, &subtype) == 0) {
		yyerror("Bad ext-community unknown type");
		return (-1);
	}

	switch (type) {
	case EXT_COMMUNITY_TRANS_TWO_AS:
	case EXT_COMMUNITY_TRANS_FOUR_AS:
	case EXT_COMMUNITY_TRANS_IPV4:
	case -1:
		if (strcmp(s, "*") == 0) {
			dflag1 = COMMUNITY_ANY;
			break;
		}
		if ((p = strchr(s, ':')) == NULL) {
			yyerror("Bad ext-community %s", s);
			return (-1);
		}
		*p++ = '\0';
		if ((type = parseextvalue(type, s, &uval, &dflag1)) == -1)
			return (-1);

		switch (type) {
		case EXT_COMMUNITY_TRANS_TWO_AS:
			if (getcommunity(p, 1, &uval2, &dflag2) == -1)
				return (-1);
			break;
		case EXT_COMMUNITY_TRANS_IPV4:
		case EXT_COMMUNITY_TRANS_FOUR_AS:
			if (getcommunity(p, 0, &uval2, &dflag2) == -1)
				return (-1);
			break;
		default:
			fatalx("parseextcommunity: unexpected result");
		}

		c->data1 = uval;
		c->data2 = uval2;
		break;
	case EXT_COMMUNITY_TRANS_OPAQUE:
	case EXT_COMMUNITY_TRANS_EVPN:
		if (strcmp(s, "*") == 0) {
			dflag1 = COMMUNITY_ANY;
			break;
		}
		errno = 0;
		ullval = strtoull(s, &ep, 0);
		if (s[0] == '\0' || *ep != '\0') {
			yyerror("Bad ext-community bad value");
			return (-1);
		}
		if (errno == ERANGE && ullval > EXT_COMMUNITY_OPAQUE_MAX) {
			yyerror("Bad ext-community value too big");
			return (-1);
		}
		c->data1 = ullval >> 32;
		c->data2 = ullval;
		break;
	case EXT_COMMUNITY_NON_TRANS_OPAQUE:
		if (subtype == EXT_COMMUNITY_SUBTYPE_OVS) {
			if (strcmp(s, "valid") == 0) {
				c->data2 = EXT_COMMUNITY_OVS_VALID;
				break;
			} else if (strcmp(s, "invalid") == 0) {
				c->data2 = EXT_COMMUNITY_OVS_INVALID;
				break;
			} else if (strcmp(s, "not-found") == 0) {
				c->data2 = EXT_COMMUNITY_OVS_NOTFOUND;
				break;
			} else if (strcmp(s, "*") == 0) {
				dflag1 = COMMUNITY_ANY;
				break;
			}
		}
		yyerror("Bad ext-community %s", s);
		return (-1);
	}

	c->data3 = type << 8 | subtype;

	/* special handling of ext-community rt * since type is not known */
	if (dflag1 == COMMUNITY_ANY && type == -1) {
		c->flags = COMMUNITY_TYPE_EXT;
		c->flags |= dflag1 << 8;
		return (0);
	}

	/* verify type/subtype combo */
	for (cp = iana_ext_comms; cp->subname != NULL; cp++) {
		if (cp->type == type && cp->subtype == subtype) {
			c->flags = COMMUNITY_TYPE_EXT;
			c->flags |= dflag1 << 8;
			c->flags |= dflag2 << 16;
			return (0);
		}
	}

	yyerror("Bad ext-community bad format for type");
	return (-1);
}

struct peer *
alloc_peer(void)
{
	struct peer	*p;
	uint8_t		 i;

	if ((p = calloc(1, sizeof(struct peer))) == NULL)
		fatal("new_peer");

	/* some sane defaults */
	p->state = STATE_NONE;
	p->reconf_action = RECONF_REINIT;
	p->conf.distance = 1;
	p->conf.export_type = EXPORT_UNSET;
	p->conf.announce_capa = 1;
	for (i = 0; i < AID_MAX; i++)
		p->conf.capabilities.mp[i] = 0;
	p->conf.capabilities.refresh = 1;
	p->conf.capabilities.grestart.restart = 1;
	p->conf.capabilities.as4byte = 1;
	p->conf.local_as = conf->as;
	p->conf.local_short_as = conf->short_as;
	p->conf.remote_port = BGP_PORT;

	if (conf->flags & BGPD_FLAG_DECISION_TRANS_AS)
		p->conf.flags |= PEERFLAG_TRANS_AS;
	if (conf->flags & BGPD_FLAG_DECISION_ALL_PATHS)
		p->conf.flags |= PEERFLAG_EVALUATE_ALL;
	if (conf->flags & BGPD_FLAG_NO_AS_SET)
		p->conf.flags |= PEERFLAG_NO_AS_SET;

	return (p);
}

struct peer *
new_peer(void)
{
	struct peer		*p;

	p = alloc_peer();

	if (curgroup != NULL) {
		memcpy(p, curgroup, sizeof(struct peer));
		p->conf.groupid = curgroup->conf.id;
	}
	return (p);
}

struct peer *
new_group(void)
{
	return (alloc_peer());
}

int
add_mrtconfig(enum mrt_type type, char *name, int timeout, struct peer *p,
    char *rib)
{
	struct mrt	*m, *n;

	LIST_FOREACH(m, conf->mrt, entry) {
		if ((rib && strcmp(rib, m->rib)) ||
		    (!rib && *m->rib))
			continue;
		if (p == NULL) {
			if (m->peer_id != 0 || m->group_id != 0)
				continue;
		} else {
			if (m->peer_id != p->conf.id ||
			    m->group_id != p->conf.groupid)
				continue;
		}
		if (m->type == type) {
			yyerror("only one mrtdump per type allowed.");
			return (-1);
		}
	}

	if ((n = calloc(1, sizeof(struct mrt_config))) == NULL)
		fatal("add_mrtconfig");

	n->type = type;
	n->state = MRT_STATE_OPEN;
	if (strlcpy(MRT2MC(n)->name, name, sizeof(MRT2MC(n)->name)) >=
	    sizeof(MRT2MC(n)->name)) {
		yyerror("filename \"%s\" too long: max %zu",
		    name, sizeof(MRT2MC(n)->name) - 1);
		free(n);
		return (-1);
	}
	MRT2MC(n)->ReopenTimerInterval = timeout;
	if (p != NULL) {
		if (curgroup == p) {
			n->peer_id = 0;
			n->group_id = p->conf.id;
		} else {
			n->peer_id = p->conf.id;
			n->group_id = p->conf.groupid;
		}
	}
	if (rib) {
		if (!find_rib(rib)) {
			yyerror("rib \"%s\" does not exist.", rib);
			free(n);
			return (-1);
		}
		if (strlcpy(n->rib, rib, sizeof(n->rib)) >=
		    sizeof(n->rib)) {
			yyerror("rib name \"%s\" too long: max %zu",
			    name, sizeof(n->rib) - 1);
			free(n);
			return (-1);
		}
	}

	LIST_INSERT_HEAD(conf->mrt, n, entry);

	return (0);
}

struct rde_rib *
add_rib(char *name)
{
	struct rde_rib	*rr;

	if ((rr = find_rib(name)) == NULL) {
		if ((rr = calloc(1, sizeof(*rr))) == NULL) {
			log_warn("add_rib");
			return (NULL);
		}
		if (strlcpy(rr->name, name, sizeof(rr->name)) >=
		    sizeof(rr->name)) {
			yyerror("rib name \"%s\" too long: max %zu",
			    name, sizeof(rr->name) - 1);
			free(rr);
			return (NULL);
		}
		rr->flags = F_RIB_NOFIB;
		SIMPLEQ_INSERT_TAIL(&ribnames, rr, entry);
	}
	return (rr);
}

struct rde_rib *
find_rib(char *name)
{
	struct rde_rib	*rr;

	SIMPLEQ_FOREACH(rr, &ribnames, entry) {
		if (!strcmp(rr->name, name))
			return (rr);
	}
	return (NULL);
}

int
rib_add_fib(struct rde_rib *rr, u_int rtableid)
{
	u_int	rdom;

	if (ktable_exists(rtableid, &rdom) != 1) {
		yyerror("rtable id %u does not exist", rtableid);
		return (-1);
	}
	/*
	 * conf->default_tableid is also a rdomain because that is checked
	 * in init_config()
	 */
	if (rdom != conf->default_tableid) {
		log_warnx("rtable %u does not belong to rdomain %u",
		    rtableid, conf->default_tableid);
		return (-1);
	}
	rr->rtableid = rtableid;
	rr->flags &= ~F_RIB_NOFIB;
	return (0);
}

struct prefixset *
find_prefixset(char *name, struct prefixset_head *p)
{
	struct prefixset *ps;

	SIMPLEQ_FOREACH(ps, p, entry) {
		if (!strcmp(ps->name, name))
			return (ps);
	}
	return (NULL);
}

int
get_id(struct peer *newpeer)
{
	static uint32_t id = PEER_ID_STATIC_MIN;
	struct peer	*p = NULL;

	/* check if the peer already existed before */
	if (newpeer->conf.remote_addr.aid) {
		/* neighbor */
		if (cur_peers)
			RB_FOREACH(p, peer_head, cur_peers)
				if (p->conf.remote_masklen ==
				    newpeer->conf.remote_masklen &&
				    memcmp(&p->conf.remote_addr,
				    &newpeer->conf.remote_addr,
				    sizeof(p->conf.remote_addr)) == 0)
					break;
		if (p) {
			newpeer->conf.id = p->conf.id;
			return (0);
		}
	} else {
		/* group */
		if (cur_peers)
			RB_FOREACH(p, peer_head, cur_peers)
				if (strcmp(p->conf.group,
				    newpeer->conf.group) == 0)
					break;
		if (p) {
			newpeer->conf.id = p->conf.groupid;
			return (0);
		}
	}

	/* else new one */
	if (id < PEER_ID_STATIC_MAX) {
		newpeer->conf.id = id++;
		return (0);
	}

	return (-1);
}

int
merge_prefixspec(struct filter_prefix *p, struct filter_prefixlen *pl)
{
	uint8_t max_len = 0;

	switch (p->addr.aid) {
	case AID_INET:
	case AID_VPN_IPv4:
		max_len = 32;
		break;
	case AID_INET6:
	case AID_VPN_IPv6:
		max_len = 128;
		break;
	}

	if (pl->op == OP_NONE) {
		p->len_min = p->len_max = p->len;
		return (0);
	}

	if (pl->len_min == -1)
		pl->len_min = p->len;
	if (pl->len_max == -1)
		pl->len_max = max_len;

	if (pl->len_max > max_len) {
		yyerror("prefixlen %d too big, limit %d",
		    pl->len_max, max_len);
		return (-1);
	}
	if (pl->len_min > pl->len_max) {
		yyerror("prefixlen %d too big, limit %d",
		    pl->len_min, pl->len_max);
		return (-1);
	}
	if (pl->len_min < p->len) {
		yyerror("prefixlen %d smaller than prefix, limit %d",
		    pl->len_min, p->len);
		return (-1);
	}

	p->op = pl->op;
	p->len_min = pl->len_min;
	p->len_max = pl->len_max;
	return (0);
}

int
expand_rule(struct filter_rule *rule, struct filter_rib_l *rib,
    struct filter_peers_l *peer, struct filter_match_l *match,
    struct filter_set_head *set)
{
	struct filter_rule	*r;
	struct filter_rib_l	*rb, *rbnext;
	struct filter_peers_l	*p, *pnext;
	struct filter_prefix_l	*prefix, *prefix_next;
	struct filter_as_l	*a, *anext;
	struct filter_set	*s;

	rb = rib;
	do {
		p = peer;
		do {
			a = match->as_l;
			do {
				prefix = match->prefix_l;
				do {
					if ((r = calloc(1,
					    sizeof(struct filter_rule))) ==
						 NULL) {
						log_warn("expand_rule");
						return (-1);
					}

					memcpy(r, rule, sizeof(struct filter_rule));
					memcpy(&r->match, match,
					    sizeof(struct filter_match));
					filterset_copy(set, &r->set);

					if (rb != NULL)
						strlcpy(r->rib, rb->name,
						     sizeof(r->rib));

					if (p != NULL)
						memcpy(&r->peer, &p->p,
						    sizeof(struct filter_peers));

					if (prefix != NULL)
						memcpy(&r->match.prefix, &prefix->p,
						    sizeof(r->match.prefix));

					if (a != NULL)
						memcpy(&r->match.as, &a->a,
						    sizeof(struct filter_as));

					TAILQ_INSERT_TAIL(filter_l, r, entry);

					if (prefix != NULL)
						prefix = prefix->next;
				} while (prefix != NULL);

				if (a != NULL)
					a = a->next;
			} while (a != NULL);

			if (p != NULL)
				p = p->next;
		} while (p != NULL);

		if (rb != NULL)
			rb = rb->next;
	} while (rb != NULL);

	for (rb = rib; rb != NULL; rb = rbnext) {
		rbnext = rb->next;
		free(rb);
	}

	for (p = peer; p != NULL; p = pnext) {
		pnext = p->next;
		free(p);
	}

	for (a = match->as_l; a != NULL; a = anext) {
		anext = a->next;
		free(a);
	}

	for (prefix = match->prefix_l; prefix != NULL; prefix = prefix_next) {
		prefix_next = prefix->next;
		free(prefix);
	}

	if (set != NULL) {
		while ((s = TAILQ_FIRST(set)) != NULL) {
			TAILQ_REMOVE(set, s, entry);
			free(s);
		}
		free(set);
	}

	return (0);
}

int
str2key(char *s, char *dest, size_t max_len)
{
	unsigned	i;
	char		t[3];

	if (strlen(s) / 2 > max_len) {
		yyerror("key too long");
		return (-1);
	}

	if (strlen(s) % 2) {
		yyerror("key must be of even length");
		return (-1);
	}

	for (i = 0; i < strlen(s) / 2; i++) {
		t[0] = s[2*i];
		t[1] = s[2*i + 1];
		t[2] = 0;
		if (!isxdigit(t[0]) || !isxdigit(t[1])) {
			yyerror("key must be specified in hex");
			return (-1);
		}
		dest[i] = strtoul(t, NULL, 16);
	}

	return (0);
}

int
neighbor_consistent(struct peer *p)
{
	struct bgpd_addr *local_addr;
	struct peer *xp;

	switch (p->conf.remote_addr.aid) {
	case AID_INET:
		local_addr = &p->conf.local_addr_v4;
		break;
	case AID_INET6:
		local_addr = &p->conf.local_addr_v6;
		break;
	default:
		yyerror("Bad address family for remote-addr");
		return (-1);
	}

	/* with any form of ipsec local-address is required */
	if ((p->conf.auth.method == AUTH_IPSEC_IKE_ESP ||
	    p->conf.auth.method == AUTH_IPSEC_IKE_AH ||
	    p->conf.auth.method == AUTH_IPSEC_MANUAL_ESP ||
	    p->conf.auth.method == AUTH_IPSEC_MANUAL_AH) &&
	    local_addr->aid == AID_UNSPEC) {
		yyerror("neighbors with any form of IPsec configured "
		    "need local-address to be specified");
		return (-1);
	}

	/* with static keying we need both directions */
	if ((p->conf.auth.method == AUTH_IPSEC_MANUAL_ESP ||
	    p->conf.auth.method == AUTH_IPSEC_MANUAL_AH) &&
	    (!p->conf.auth.spi_in || !p->conf.auth.spi_out)) {
		yyerror("with manual keyed IPsec, SPIs and keys "
		    "for both directions are required");
		return (-1);
	}

	if (!conf->as) {
		yyerror("AS needs to be given before neighbor definitions");
		return (-1);
	}

	/* set default values if they where undefined */
	p->conf.ebgp = (p->conf.remote_as != conf->as);
	if (p->conf.enforce_as == ENFORCE_AS_UNDEF)
		p->conf.enforce_as = p->conf.ebgp ?
		    ENFORCE_AS_ON : ENFORCE_AS_OFF;
	if (p->conf.enforce_local_as == ENFORCE_AS_UNDEF)
		p->conf.enforce_local_as = ENFORCE_AS_ON;

	if (p->conf.remote_as == 0 && !p->conf.template) {
		yyerror("peer AS may not be zero");
		return (-1);
	}

	/* EBGP neighbors are not allowed in route reflector clusters */
	if (p->conf.reflector_client && p->conf.ebgp) {
		yyerror("EBGP neighbors are not allowed in route "
		    "reflector clusters");
		return (-1);
	}

	/* check for duplicate peer definitions */
	RB_FOREACH(xp, peer_head, new_peers)
		if (xp->conf.remote_masklen ==
		    p->conf.remote_masklen &&
		    memcmp(&xp->conf.remote_addr,
		    &p->conf.remote_addr,
		    sizeof(p->conf.remote_addr)) == 0)
			break;
	if (xp != NULL) {
		char *descr = log_fmt_peer(&p->conf);
		yyerror("duplicate %s", descr);
		free(descr);
		return (-1);
	}

	return (0);
}

static void
filterset_add(struct filter_set_head *sh, struct filter_set *s)
{
	struct filter_set	*t;

	TAILQ_FOREACH(t, sh, entry) {
		if (s->type < t->type) {
			TAILQ_INSERT_BEFORE(t, s, entry);
			return;
		}
		if (s->type == t->type) {
			switch (s->type) {
			case ACTION_SET_COMMUNITY:
			case ACTION_DEL_COMMUNITY:
				switch (cmpcommunity(&s->action.community,
				    &t->action.community)) {
				case -1:
					TAILQ_INSERT_BEFORE(t, s, entry);
					return;
				case 0:
					break;
				case 1:
					continue;
				}
				break;
			case ACTION_SET_NEXTHOP:
				/* only last nexthop per AF matters */
				if (s->action.nexthop.aid <
				    t->action.nexthop.aid) {
					TAILQ_INSERT_BEFORE(t, s, entry);
					return;
				} else if (s->action.nexthop.aid ==
				    t->action.nexthop.aid) {
					t->action.nexthop = s->action.nexthop;
					break;
				}
				continue;
			case ACTION_SET_NEXTHOP_BLACKHOLE:
			case ACTION_SET_NEXTHOP_REJECT:
			case ACTION_SET_NEXTHOP_NOMODIFY:
			case ACTION_SET_NEXTHOP_SELF:
				/* set it only once */
				break;
			case ACTION_SET_LOCALPREF:
			case ACTION_SET_MED:
			case ACTION_SET_WEIGHT:
				/* only last set matters */
				t->action.metric = s->action.metric;
				break;
			case ACTION_SET_RELATIVE_LOCALPREF:
			case ACTION_SET_RELATIVE_MED:
			case ACTION_SET_RELATIVE_WEIGHT:
				/* sum all relative numbers */
				t->action.relative += s->action.relative;
				break;
			case ACTION_SET_ORIGIN:
				/* only last set matters */
				t->action.origin = s->action.origin;
				break;
			case ACTION_PFTABLE:
				/* only last set matters */
				strlcpy(t->action.pftable, s->action.pftable,
				    sizeof(t->action.pftable));
				break;
			case ACTION_RTLABEL:
				/* only last set matters */
				strlcpy(t->action.rtlabel, s->action.rtlabel,
				    sizeof(t->action.rtlabel));
				break;
			default:
				break;
			}
			free(s);
			return;
		}
	}

	TAILQ_INSERT_TAIL(sh, s, entry);
}

int
merge_filterset(struct filter_set_head *sh, struct filter_set *s)
{
	struct filter_set	*t;

	TAILQ_FOREACH(t, sh, entry) {
		/*
		 * need to cycle across the full list because even
		 * if types are not equal filterset_cmp() may return 0.
		 */
		if (filterset_cmp(s, t) == 0) {
			if (s->type == ACTION_SET_COMMUNITY)
				yyerror("community is already set");
			else if (s->type == ACTION_DEL_COMMUNITY)
				yyerror("community will already be deleted");
			else
				yyerror("redefining set parameter %s",
				    filterset_name(s->type));
			return (-1);
		}
	}

	filterset_add(sh, s);
	return (0);
}

static int
filter_equal(struct filter_rule *fa, struct filter_rule *fb)
{
	if (fa == NULL || fb == NULL)
		return 0;
	if (fa->action != fb->action || fa->quick != fb->quick ||
	    fa->dir != fb->dir)
		return 0;
	if (memcmp(&fa->peer, &fb->peer, sizeof(fa->peer)))
		return 0;
	if (memcmp(&fa->match, &fb->match, sizeof(fa->match)))
		return 0;

	return 1;
}

/* do a basic optimization by folding equal rules together */
void
optimize_filters(struct filter_head *fh)
{
	struct filter_rule *r, *nr;

	TAILQ_FOREACH_SAFE(r, fh, entry, nr) {
		while (filter_equal(r, nr)) {
			struct filter_set	*t;

			while ((t = TAILQ_FIRST(&nr->set)) != NULL) {
				TAILQ_REMOVE(&nr->set, t, entry);
				filterset_add(&r->set, t);
			}

			TAILQ_REMOVE(fh, nr, entry);
			free(nr);
			nr = TAILQ_NEXT(r, entry);
		}
	}
}

struct filter_rule *
get_rule(enum action_types type)
{
	struct filter_rule	*r;
	int			 out;

	switch (type) {
	case ACTION_SET_PREPEND_SELF:
	case ACTION_SET_NEXTHOP_NOMODIFY:
	case ACTION_SET_NEXTHOP_SELF:
		out = 1;
		break;
	default:
		out = 0;
		break;
	}
	r = (curpeer == curgroup) ? curgroup_filter[out] : curpeer_filter[out];
	if (r == NULL) {
		if ((r = calloc(1, sizeof(struct filter_rule))) == NULL)
			fatal(NULL);
		r->quick = 0;
		r->dir = out ? DIR_OUT : DIR_IN;
		r->action = ACTION_NONE;
		TAILQ_INIT(&r->set);
		if (curpeer == curgroup) {
			/* group */
			r->peer.groupid = curgroup->conf.id;
			curgroup_filter[out] = r;
		} else {
			/* peer */
			r->peer.peerid = curpeer->conf.id;
			curpeer_filter[out] = r;
		}
	}
	return (r);
}

struct set_table *curset;
static int
new_as_set(char *name)
{
	struct as_set *aset;

	if (as_sets_lookup(&conf->as_sets, name) != NULL) {
		yyerror("as-set \"%s\" already exists", name);
		return -1;
	}

	aset = as_sets_new(&conf->as_sets, name, 0, sizeof(uint32_t));
	if (aset == NULL)
		fatal(NULL);

	curset = aset->set;
	return 0;
}

static void
add_as_set(uint32_t as)
{
	if (curset == NULL)
		fatalx("%s: bad mojo jojo", __func__);

	if (set_add(curset, &as, 1) != 0)
		fatal(NULL);
}

static void
done_as_set(void)
{
	curset = NULL;
}

static struct prefixset *
new_prefix_set(char *name, int is_roa)
{
	const char *type = "prefix-set";
	struct prefixset_head *sets = &conf->prefixsets;
	struct prefixset *pset;

	if (is_roa) {
		type = "origin-set";
		sets = &conf->originsets;
	}

	if (find_prefixset(name, sets) != NULL)  {
		yyerror("%s \"%s\" already exists", type, name);
		return NULL;
	}
	if ((pset = calloc(1, sizeof(*pset))) == NULL)
		fatal("prefixset");
	if (strlcpy(pset->name, name, sizeof(pset->name)) >=
	    sizeof(pset->name)) {
		yyerror("%s \"%s\" too long: max %zu", type,
		    name, sizeof(pset->name) - 1);
		free(pset);
		return NULL;
	}
	RB_INIT(&pset->psitems);
	RB_INIT(&pset->roaitems);
	return pset;
}

static void
add_roa_set(struct prefixset_item *npsi, uint32_t as, uint8_t max,
    time_t expires)
{
	struct roa *roa, *r;

	if ((roa = calloc(1, sizeof(*roa))) == NULL)
		fatal("add_roa_set");

	roa->aid = npsi->p.addr.aid;
	roa->prefixlen = npsi->p.len;
	roa->maxlen = max;
	roa->asnum = as;
	roa->expires = expires;
	switch (roa->aid) {
	case AID_INET:
		roa->prefix.inet = npsi->p.addr.v4;
		break;
	case AID_INET6:
		roa->prefix.inet6 = npsi->p.addr.v6;
		break;
	default:
		fatalx("Bad address family for roa_set address");
	}

	r = RB_INSERT(roa_tree, curroatree, roa);
	if (r != NULL) {
		/* just ignore duplicates */
		if (r->expires != 0 && expires != 0 && expires > r->expires)
			r->expires = expires;
		free(roa);
	}
}

static struct rtr_config *
get_rtr(struct bgpd_addr *addr)
{
	struct rtr_config *n;

	n = calloc(1, sizeof(*n));
	if (n == NULL) {
		yyerror("out of memory");
		return NULL;
	}

	n->remote_addr = *addr;
	strlcpy(n->descr, log_addr(addr), sizeof(currtr->descr));

	return n;
}

static int
insert_rtr(struct rtr_config *new)
{
	static uint32_t id;
	struct rtr_config *r;

	if (id == UINT32_MAX) {
		yyerror("out of rtr session IDs");
		return -1;
	}

	SIMPLEQ_FOREACH(r, &conf->rtrs, entry)
		if (memcmp(&r->remote_addr, &new->remote_addr,
		    sizeof(r->remote_addr)) == 0 &&
		    r->remote_port == new->remote_port) {
			yyerror("duplicate rtr session to %s:%u",
			    log_addr(&new->remote_addr), new->remote_port);
			return -1;
		}

	if (cur_rtrs)
		SIMPLEQ_FOREACH(r, cur_rtrs, entry)
			if (memcmp(&r->remote_addr, &new->remote_addr,
			    sizeof(r->remote_addr)) == 0 &&
			    r->remote_port == new->remote_port) {
				new->id = r->id;
				break;
			}

	if (new->id == 0)
		new->id = ++id;

	SIMPLEQ_INSERT_TAIL(&conf->rtrs, currtr, entry);

	return 0;
}
