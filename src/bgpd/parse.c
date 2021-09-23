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
static void	 add_as_set(u_int32_t);
static void	 done_as_set(void);
static struct prefixset	*new_prefix_set(char *, int);
static void	 add_roa_set(struct prefixset_item *, u_int32_t, u_int8_t,
		    time_t);
static struct rtr_config	*get_rtr(struct bgpd_addr *);
static int	 insert_rtr(struct rtr_config *);

typedef struct {
	union {
		long long		 number;
		char			*string;
		struct bgpd_addr	 addr;
		u_int8_t		 u8;
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
			u_int8_t		len;
		}			prefix;
		struct filter_prefixlen	prefixlen;
		struct prefixset_item	*prefixset_item;
		struct {
			u_int8_t		enc_alg;
			char			enc_key[IPSEC_ENC_KEY_LEN];
			u_int8_t		enc_key_len;
		}			encspec;
	} v;
	int lineno;
} YYSTYPE;


#line 249 "parse.c"

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
#define YYLAST   707

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  139
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  316
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  589

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
       0,   254,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   272,   283,
     315,   325,   352,   357,   363,   366,   381,   401,   416,   416,
     430,   438,   439,   441,   441,   451,   461,   475,   491,   508,
     508,   515,   518,   518,   531,   543,   546,   554,   564,   576,
     585,   585,   597,   598,   600,   611,   619,   629,   636,   640,
     647,   655,   663,   677,   684,   695,   701,   707,   716,   717,
     745,   777,   778,   788,   798,   811,   824,   837,   853,   860,
     876,   876,   886,   887,   896,   905,   906,   914,   944,   965,
     994,  1013,  1037,  1057,  1058,  1061,  1062,  1065,  1086,  1104,
    1124,  1131,  1134,  1135,  1138,  1138,  1183,  1184,  1185,  1186,
    1189,  1207,  1225,  1243,  1249,  1252,  1253,  1252,  1287,  1287,
    1319,  1320,  1321,  1322,  1323,  1326,  1327,  1328,  1331,  1332,
    1333,  1334,  1337,  1340,  1347,  1351,  1362,  1375,  1385,  1392,
    1395,  1398,  1409,  1425,  1433,  1441,  1460,  1463,  1466,  1469,
    1472,  1475,  1485,  1488,  1491,  1497,  1503,  1518,  1526,  1534,
    1552,  1568,  1578,  1671,  1674,  1681,  1693,  1694,  1704,  1720,
    1732,  1756,  1762,  1773,  1779,  1794,  1795,  1805,  1806,  1809,
    1810,  1811,  1814,  1815,  1818,  1819,  1822,  1825,  1858,  1885,
    1886,  1887,  1890,  1891,  1894,  1895,  1898,  1899,  1900,  1902,
    1903,  1909,  1931,  1932,  1935,  1936,  1942,  1949,  1969,  1976,
    1997,  2003,  2011,  2026,  2041,  2042,  2045,  2046,  2047,  2059,
    2060,  2066,  2081,  2082,  2085,  2086,  2098,  2102,  2109,  2132,
    2133,  2134,  2147,  2148,  2154,  2162,  2168,  2176,  2190,  2193,
    2193,  2201,  2202,  2205,  2218,  2225,  2237,  2249,  2267,  2289,
    2308,  2316,  2323,  2372,  2392,  2402,  2403,  2409,  2420,  2463,
    2479,  2480,  2481,  2482,  2485,  2486,  2493,  2496,  2501,  2510,
    2511,  2514,  2515,  2518,  2533,  2543,  2553,  2568,  2578,  2588,
    2603,  2613,  2623,  2638,  2648,  2658,  2665,  2670,  2675,  2680,
    2685,  2695,  2705,  2710,  2737,  2751,  2779,  2797,  2813,  2821,
    2836,  2851,  2852,  2855,  2856,  2857,  2858,  2861,  2862,  2863,
    2864,  2865,  2866,  2869,  2870,  2873,  2874
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

#define YYPACT_NINF (-421)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-304)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -421,   549,  -421,   -59,   -67,   -40,    23,    92,   -24,   -13,
     -10,     1,    11,   -40,     4,   -19,    12,     9,    10,    15,
     -24,  -421,  -421,  -421,    18,    34,    44,    46,    77,   113,
      76,    75,  -421,    79,    91,    98,   100,   122,   131,   136,
     138,   147,  -421,  -421,   150,   158,   228,   173,   191,   146,
    -421,  -421,  -421,  -421,   182,  -421,  -421,   196,  -421,   -40,
    -421,  -421,  -421,  -421,   314,   229,   230,   331,   208,   227,
    -421,   234,   235,  -421,  -421,   233,   236,   269,    74,  -421,
     237,    14,   307,  -421,  -421,   239,   242,   243,   244,   248,
     -24,  -421,     4,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,   143,  -421,  -421,  -421,   355,  -421,
    -421,  -421,   250,  -421,  -421,   252,  -421,  -421,   249,  -421,
     253,   269,   255,   257,   518,  -421,  -421,  -421,   259,   260,
     269,   262,  -421,  -421,   264,   263,  -421,  -421,   242,   242,
     261,   242,   242,   268,  -421,   234,   233,  -421,  -421,  -421,
      64,   220,  -421,    16,  -421,   242,  -421,  -421,  -421,  -421,
    -421,  -421,   316,  -421,   106,   109,   120,   123,   271,   272,
     270,   129,   275,   277,   242,   316,  -421,   269,   269,  -421,
     278,  -421,  -421,   264,   280,  -421,  -421,   181,   283,   285,
    -421,   256,  -421,   242,  -421,  -421,  -421,    21,   276,   -24,
     282,   389,  -421,  -421,   127,   393,  -421,   -39,  -421,   288,
     291,  -421,   292,   294,  -421,   295,   306,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,  -421,  -421,   308,   309,  -421,  -421,
    -421,   590,   311,  -421,  -421,   264,  -421,  -421,   181,   346,
     117,   -45,  -421,   181,  -421,   210,   279,  -421,   312,   -67,
     313,  -421,  -421,  -421,   242,  -421,    -9,  -421,  -421,  -421,
     432,  -421,   322,   317,   -40,   242,  -421,   328,    30,    72,
     429,   332,   -67,   -67,     4,   -40,   330,  -421,   333,    71,
     335,    41,   -24,   -40,   455,   337,   338,   339,   -24,   403,
     -24,   576,   380,   231,  -421,  -421,   434,  -421,   341,   342,
     345,   347,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
     117,  -421,  -421,  -421,   117,  -421,   210,   242,   344,   348,
     181,   168,  -421,   349,  -421,   117,  -421,  -421,  -421,   117,
    -421,   350,   -25,  -421,  -421,  -421,    32,   269,   121,    25,
    -421,  -421,  -421,  -421,    31,  -421,   353,  -421,  -421,  -421,
     351,  -421,   182,  -421,   234,  -421,  -421,    35,   -24,   -24,
     -24,   -24,   441,   428,   172,  -421,   -24,   -24,  -421,  -421,
     358,  -421,   290,  -421,  -421,   284,  -421,   242,  -421,   -24,
    -421,  -421,    19,  -421,  -421,  -421,  -421,  -421,   354,   590,
     356,   181,   402,   359,   242,  -421,   404,  -421,  -421,  -421,
     -49,  -421,  -421,  -421,   368,  -421,   365,   366,   210,   474,
    -421,   367,   312,   117,  -421,  -421,  -421,   -33,    -2,   373,
     374,   375,  -421,  -421,  -421,   376,   385,    17,   -45,   -45,
      43,  -421,  -421,  -421,   121,  -421,   105,   388,   387,   -24,
     390,   391,   392,  -421,  -421,  -421,   405,  -421,  -421,  -421,
    -421,  -421,   410,   464,  -421,  -421,  -421,  -421,  -421,   -24,
     -24,  -421,  -421,  -421,  -421,  -421,  -421,  -421,     4,     4,
     590,  -421,  -421,   406,  -421,  -421,  -421,  -421,   411,  -421,
    -421,   210,  -421,  -421,   412,  -421,  -421,  -421,  -421,   413,
    -421,  -421,   414,  -421,  -421,   399,    32,   417,   418,   176,
     -45,  -421,   -45,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,   137,  -421,  -421,  -421,   419,  -421,  -421,    39,
     -49,  -421,   210,  -421,  -421,  -421,  -421,   420,   421,  -421,
    -421,  -421,  -421,  -421,   234,   234,   117,   423,  -421,   402,
    -421,  -421,  -421,  -421,  -421,  -421,  -421,   181,   401,   165,
    -421,  -421,  -421,   242,  -421,    43,  -421,    88,   425,   189,
    -421,   210,  -421,  -421,  -421,   430,   438,  -421,   194,  -421,
     181,  -421,  -421,   207,  -421,    88,  -421,  -421,   439,   176,
    -421,    39,  -421,   440,  -421,  -421,   444,  -421,  -421
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,   190,   191,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    68,     0,     0,     0,     0,     0,   192,
      17,    19,    18,    20,    57,    97,    59,     0,    60,     0,
      25,    64,    63,    77,     0,     0,     0,     0,     0,    49,
      24,   118,     0,   177,   178,     0,     0,   264,     0,    78,
       0,     0,    96,    67,    65,     0,   301,     0,     0,     0,
       0,    27,     0,     4,     5,     6,     7,     8,     9,    10,
      12,    11,    13,    14,     0,    15,    16,   193,   196,    58,
      61,    62,     0,    80,    75,     0,    72,    73,     0,    23,
       0,   264,     0,     0,     0,    88,   183,   182,     0,     0,
     264,     0,    93,    94,   102,     0,    95,    79,   301,   301,
      39,   301,   301,     0,    66,    26,    97,   100,   101,   116,
       0,     0,   104,    85,    74,   301,   120,    89,    98,    99,
     292,   269,   271,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   301,   271,   265,   264,   264,    92,
       0,   103,    69,   102,    33,   302,    41,     0,    42,    28,
      76,   127,   201,   301,   197,   194,   195,     0,     0,     0,
       0,     0,    81,    82,     0,     0,   272,     0,   273,     0,
       0,   276,     0,     0,   279,     0,     0,   287,   286,   288,
     289,   285,   290,   291,   293,   282,     0,     0,   294,   299,
     298,     0,     0,    90,    91,   102,    87,    35,     0,     0,
     303,   255,    44,     0,    30,     0,     0,   117,     0,     0,
       0,   210,   211,   206,   301,   207,   239,   202,   106,    86,
      85,    84,     0,     0,     0,   301,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,     0,     0,
       0,     0,     0,   167,     0,   140,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   119,     0,   166,     0,     0,
       0,     0,   274,   275,   277,   278,   280,   281,   283,   284,
     303,   268,   295,    70,   303,    36,     0,   301,   304,     0,
       0,     0,   256,     0,    38,   303,    21,    22,    31,   303,
     128,     0,   301,   199,   208,   209,     0,   264,     0,     0,
      83,    56,    54,    55,     0,   124,     0,   143,   152,   153,
       0,   142,   133,   132,   135,   136,   138,   175,     0,     0,
       0,     0,     0,     0,     0,   170,     0,     0,   156,   168,
       0,   141,     0,   172,   171,     0,   163,   301,   164,     0,
     184,   185,     0,   137,   123,   122,   297,   296,     0,     0,
       0,     0,    45,   305,   301,    40,     0,   308,   309,   311,
       0,   307,   310,   312,     0,   257,     0,     0,     0,     0,
     126,     0,     0,   303,   204,   188,   260,     0,     0,     0,
       0,     0,   261,   262,   263,     0,     0,     0,   255,   255,
       0,   243,   244,   222,   240,   241,     0,     0,     0,     0,
       0,     0,     0,   107,   105,   114,     0,    51,    53,   144,
     174,   134,     0,   175,   157,   149,   146,   147,   150,     0,
       0,   179,   180,   181,   145,   155,   154,   169,     0,     0,
       0,   173,   161,     0,   266,   267,    34,    37,     0,    47,
     306,     0,   316,   315,     0,   258,    43,    29,    32,     0,
     129,   125,     0,   198,   200,     0,     0,     0,     0,     0,
     255,   214,   255,   253,   300,   254,   245,   246,   251,   250,
     212,   213,   303,   224,   242,   235,     0,   314,   313,     0,
     234,   226,     0,   247,   109,   113,   110,     0,     0,   108,
     176,   158,   148,   151,   159,   160,   303,     0,    46,    45,
     259,   131,   130,   203,   205,   249,   248,     0,     0,   303,
     219,   221,   252,   301,   223,     0,   228,     0,     0,   303,
     232,     0,   236,   111,   112,     0,     0,    48,   303,   215,
       0,   305,   225,   303,   227,     0,   237,   165,     0,   217,
     220,   230,   233,   186,   218,   231,     0,   162,   187
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -421,  -421,    13,  -194,  -234,   -87,    -7,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,  -421,  -223,  -421,  -421,  -421,  -421,
      22,   329,  -421,  -421,  -421,   238,  -421,  -421,  -421,  -421,
     315,   578,   241,   199,  -421,    -3,   -15,  -421,  -139,  -421,
    -421,  -421,  -421,   378,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -232,   132,   305,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,  -240,  -421,  -421,  -318,  -421,     8,
      42,  -390,  -421,  -421,  -408,     7,    33,  -420,  -421,  -421,
    -421,   157,  -379,  -421,  -109,   124,  -307,   424,  -115,  -421,
    -421,  -135,  -291,  -421,  -421,    78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,   327,    54,   520,    71,   296,    33,    34,    35,
     245,   329,    36,   238,   314,   239,    37,   187,    38,   243,
     479,   240,    39,   118,   265,   266,    40,    41,   153,   202,
     203,   297,    43,   135,   137,   255,   241,   149,   182,    44,
     198,   339,   446,    45,    46,   191,    47,   120,   205,   247,
     409,   299,   454,    78,   464,   130,   382,   587,    48,    49,
     108,   197,   151,   332,   194,   256,   413,   257,   431,   548,
     549,   550,   432,   512,   433,   558,   559,   560,   337,   338,
     434,   435,   324,   436,   125,   310,   175,   207,   311,   230,
     505,   140,   320,   404,   522,   484
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    61,    56,   184,   185,   145,   188,   189,   333,   176,
      69,   328,   157,    84,   331,   315,   521,    53,   414,   389,
     204,   179,   513,   391,   249,   199,   438,   200,   501,    57,
      80,   437,    65,    66,   439,   249,   346,   321,   408,   231,
     440,   412,   441,   442,   236,   508,   416,   300,   250,   510,
     511,   251,   252,   497,    15,   334,   111,   262,   248,   250,
      51,    52,   251,   252,    72,   263,   264,   109,   233,   234,
      50,   132,   133,   366,   452,   482,   132,   133,   352,   353,
     322,   323,   392,   144,   348,  -238,   483,    55,   301,   148,
     515,   349,   367,   453,   498,   253,   313,   396,    73,    74,
      59,   147,  -303,    60,   317,   319,   253,    67,    75,    76,
     358,   318,   359,   360,   361,    62,   362,   363,    63,   336,
    -238,   551,   496,   552,   416,    75,    76,   437,    64,   499,
     344,    70,   422,   423,   424,   472,    81,    82,    68,   515,
      79,   134,    83,    60,    55,    85,   201,   572,    55,   126,
     127,    58,   254,   262,   443,   582,   515,   444,   347,    55,
     517,   263,   264,   447,   221,    86,   326,    52,   477,   518,
     557,    87,   494,    88,   488,   388,   378,   492,   544,   390,
     580,   128,   393,   129,   461,   462,   463,   354,    73,    74,
     406,   192,   259,   516,   407,   193,    89,   411,   161,   417,
     163,    90,   418,    91,   419,    92,   420,   421,    93,   517,
     422,   423,   424,   425,   426,   326,    52,   107,   518,   427,
      94,   555,   217,   218,   219,   220,   517,    95,   415,    96,
     116,   117,   326,    52,   208,   518,   519,   211,   428,   429,
     209,   210,   470,   212,   213,   389,   317,   539,   214,  -301,
      55,    97,   430,   318,   215,   216,   104,   225,   570,   480,
      98,   343,    53,   226,   227,    99,   553,   100,   575,   554,
     146,    76,   355,   318,   475,   368,   101,   570,   495,   102,
     369,   374,   575,   376,   268,    53,    53,   103,   562,   397,
     398,   399,   195,   196,   553,   269,   400,  -216,   401,   270,
     271,   318,   105,    75,    76,   402,   403,   547,    75,    76,
      52,   272,   273,   274,   275,   276,   277,   278,   553,   279,
     106,  -229,   112,   553,   110,   318,   579,   576,   280,   281,
     318,   282,   283,   284,   285,   286,   553,   326,    52,   581,
     287,   288,   289,   318,   380,   381,   290,   132,   133,   468,
     469,   455,   456,   457,   458,   115,   113,   114,   -50,   465,
     466,   119,   121,   124,   131,   451,   122,   136,   143,   123,
     138,   139,   471,   291,   141,   142,   150,   152,   292,   154,
     155,   534,   535,   158,   156,   159,   177,   246,   178,   180,
     183,   293,   181,   186,   267,   190,   206,   224,   268,   222,
     223,   565,   228,   500,   229,   235,    60,   258,   330,   269,
     260,   261,   237,   270,   271,   242,   302,   244,   571,   303,
     304,  -115,   305,   306,   509,   272,   273,   274,   275,   276,
     277,   278,   525,   279,   307,   316,   308,   309,   312,   192,
     335,   199,   280,   281,   342,   282,   283,   284,   285,   286,
     341,   350,   532,   533,   287,   288,   289,   345,   356,   351,
     290,   357,   365,   370,   371,   372,   373,   375,   379,   383,
     384,   385,   386,   394,   387,   489,   460,   405,   450,   268,
     395,   449,   410,   459,   500,   467,   474,   291,   476,   478,
     269,  -302,   292,   481,   270,   271,   485,   486,   487,   493,
     502,   503,   504,   452,   506,   293,   272,   273,   274,   275,
     276,   277,   278,   507,   279,   523,   524,   526,   527,   528,
      60,   537,   294,   280,   281,   295,   282,   283,   284,   285,
     286,   543,   500,   569,   529,   287,   288,   289,   530,   538,
     540,   290,   541,   542,   545,   546,   556,   563,   564,     2,
       3,   566,     4,     5,     6,   500,     7,   574,     8,     9,
      10,   567,   577,    11,   500,   578,   583,   586,   291,    12,
     160,   588,   325,   292,    13,   340,    14,  -115,    15,    42,
     445,   473,   448,   298,   364,   531,   293,   584,   585,   568,
     573,   514,     0,    16,   536,   161,   162,   163,   561,   232,
       0,    60,     0,   490,     0,    17,   491,     0,    18,     0,
      19,    20,     0,   164,   165,   166,   167,    21,    22,    23,
       0,   168,   169,   170,   171,   172,   173,     0,   160,     0,
       0,     0,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,   160,     0,     0,     0,     0,    28,    29,   174,
       0,     0,     0,   161,   162,   163,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,   161,   162,   163,
       0,   164,   165,   166,   167,     0,    31,     0,    32,   168,
     169,   170,   171,   172,   173,   164,   165,   166,   167,     0,
       0,     0,     0,   168,   169,   170,   171,   172,   173,     0,
       0,     0,     0,     0,     0,     0,     0,   377
};

static const yytype_int16 yycheck[] =
{
      15,     8,     5,   138,   139,    92,   141,   142,   248,   124,
      13,   245,   121,    20,   246,   238,   436,     4,   336,   310,
     155,   130,   430,   314,     3,     9,     1,    11,   418,     6,
      21,   338,    21,    22,     9,     3,     6,    82,   329,   174,
      15,   332,    17,    18,   183,    28,     3,    86,    27,   428,
     429,    30,    31,    86,    29,   249,    59,    26,   193,    27,
     127,   128,    30,    31,    83,    34,    35,    54,   177,   178,
     129,    57,    58,    32,    39,   124,    57,    58,   272,   273,
     125,   126,   316,    90,    12,    94,   135,   127,   127,   104,
      51,    19,    51,    58,   127,    74,   235,   320,   117,   118,
       8,   104,   127,   127,   129,   240,    74,    96,   127,   128,
      39,   136,    41,    42,    43,   128,    45,    46,   128,   254,
     129,   500,   413,   502,     3,   127,   128,   434,   127,   131,
     265,   127,    89,    90,    91,   116,   127,   127,   127,    51,
     128,   127,   127,   127,   127,   127,   153,   555,   127,    75,
      76,   128,   131,    26,   129,   575,    51,   132,   128,   127,
     121,    34,    35,   132,   167,   131,   127,   128,   391,   130,
     131,   127,   412,   127,   408,   310,   291,   409,   496,   314,
     570,   107,   317,   109,    12,    13,    14,   274,   117,   118,
     325,   127,   199,    88,   329,   131,   119,   332,    77,    78,
      79,    88,    81,   127,    83,   130,    85,    86,   129,   121,
      89,    90,    91,    92,    93,   127,   128,    71,   130,    98,
     129,   512,    99,   100,   101,   102,   121,   129,   337,   129,
      22,    23,   127,   128,   128,   130,   131,   128,   117,   118,
     134,   135,   377,   134,   135,   536,   129,   481,   128,   132,
     127,   129,   131,   136,   134,   135,    28,   128,   549,   394,
     129,   264,   249,   134,   135,   129,   129,   129,   559,   132,
     127,   128,   275,   136,   389,   282,   129,   568,   413,   129,
     283,   288,   573,   290,     5,   272,   273,   129,   522,   121,
     122,   123,    72,    73,   129,    16,   128,   132,   130,    20,
      21,   136,   129,   127,   128,   137,   138,   131,   127,   128,
     128,    32,    33,    34,    35,    36,    37,    38,   129,    40,
     129,   132,     8,   129,   128,   136,   132,   561,    49,    50,
     136,    52,    53,    54,    55,    56,   129,   127,   128,   132,
      61,    62,    63,   136,   113,   114,    67,    57,    58,    65,
      66,   358,   359,   360,   361,    24,   127,   127,   131,   366,
     367,   127,   127,    94,   127,   352,   133,    60,   120,   133,
     131,   129,   379,    94,   131,   131,    21,   127,    99,   127,
     131,   468,   469,   128,   131,   128,   127,   131,   128,   127,
     127,   112,   128,   132,     1,   127,    80,   127,     5,   128,
     128,   536,   127,   418,   127,   127,   127,   131,   129,    16,
     128,    22,   132,    20,    21,   132,   128,   132,   553,   128,
     128,    28,   128,   128,   427,    32,    33,    34,    35,    36,
      37,    38,   439,    40,   128,    89,   128,   128,   127,   127,
     127,     9,    49,    50,   127,    52,    53,    54,    55,    56,
     128,    22,   459,   460,    61,    62,    63,   129,   128,   127,
      67,   128,   127,     8,   127,   127,   127,    64,    88,    35,
     129,   129,   127,   129,   127,     1,    48,   128,   127,     5,
     132,   128,   132,    42,   499,   127,   132,    94,   132,    87,
      16,   132,    99,    89,    20,    21,   128,   132,   132,   132,
     127,   127,   127,    39,   128,   112,    32,    33,    34,    35,
      36,    37,    38,   128,    40,   127,   129,   127,   127,   127,
     127,   115,   129,    49,    50,   132,    52,    53,    54,    55,
      56,   132,   547,   132,   129,    61,    62,    63,   128,   128,
     128,    67,   129,   129,   127,   127,   127,   127,   127,     0,
       1,   128,     3,     4,     5,   570,     7,   132,     9,    10,
      11,   539,   132,    14,   579,   127,   127,   127,    94,    20,
      52,   127,   243,    99,    25,   260,    27,    28,    29,     1,
     339,   382,   344,   205,   279,   453,   112,   579,   581,   547,
     557,   434,    -1,    44,   470,    77,    78,    79,   520,   175,
      -1,   127,    -1,   129,    -1,    56,   132,    -1,    59,    -1,
      61,    62,    -1,    95,    96,    97,    98,    68,    69,    70,
      -1,   103,   104,   105,   106,   107,   108,    -1,    52,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    88,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    98,    99,   131,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    95,    96,    97,    98,    -1,   127,    -1,   129,   103,
     104,   105,   106,   107,   108,    95,    96,    97,    98,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131
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
      21,   201,   127,   167,   127,   131,   131,   223,   128,   128,
      52,    77,    78,    79,    95,    96,    97,    98,   103,   104,
     105,   106,   107,   108,   131,   225,   227,   127,   128,   223,
     127,   128,   177,   127,   230,   230,   132,   156,   230,   230,
     127,   184,   127,   131,   203,    72,    73,   200,   179,     9,
      11,   145,   168,   169,   230,   187,    80,   226,   128,   134,
     135,   128,   134,   135,   128,   134,   135,    99,   100,   101,
     102,   174,   128,   128,   127,   128,   134,   135,   127,   127,
     228,   230,   226,   223,   223,   127,   177,   132,   152,   154,
     160,   175,   132,   158,   132,   149,   131,   188,   230,     3,
      27,    30,    31,    74,   131,   174,   204,   206,   131,   145,
     128,    22,    26,    34,    35,   163,   164,     1,     5,    16,
      20,    21,    32,    33,    34,    35,    36,    37,    38,    40,
      49,    50,    52,    53,    54,    55,    56,    61,    62,    63,
      67,    94,    99,   112,   129,   132,   145,   170,   182,   190,
      86,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     224,   227,   127,   177,   153,   154,    89,   129,   136,   230,
     231,    82,   125,   126,   221,   160,   127,   141,   143,   150,
     129,   190,   202,   203,   142,   127,   230,   217,   218,   180,
     169,   128,   127,   174,   230,   129,     6,   128,    12,    19,
      22,   127,   142,   142,   144,   174,   128,   128,    39,    41,
      42,    43,    45,    46,   192,   127,    32,    51,   145,   174,
       8,   127,   127,   127,   145,    64,   145,   131,   227,    88,
     113,   114,   195,    35,   129,   129,   127,   127,   230,   231,
     230,   231,   143,   230,   129,   132,   154,   121,   122,   123,
     128,   130,   137,   138,   232,   128,   230,   230,   231,   189,
     132,   230,   231,   205,   206,   223,     3,    78,    81,    83,
      85,    86,    89,    90,    91,    92,    93,    98,   117,   118,
     131,   207,   211,   213,   219,   220,   222,   225,     1,     9,
      15,    17,    18,   129,   132,   171,   181,   132,   164,   128,
     127,   141,    39,    58,   191,   145,   145,   145,   145,    42,
      48,    12,    13,    14,   193,   145,   145,   127,    65,    66,
     230,   145,   116,   172,   132,   227,   132,   154,    87,   159,
     230,    89,   124,   135,   234,   128,   132,   132,   143,     1,
     129,   132,   190,   132,   203,   230,   231,    86,   127,   131,
     175,   210,   127,   127,   127,   229,   128,   128,    28,   174,
     221,   221,   212,   213,   220,    51,    88,   121,   130,   131,
     143,   216,   233,   127,   129,   145,   127,   127,   127,   129,
     128,   191,   145,   145,   144,   144,   224,   115,   128,   143,
     128,   129,   129,   132,   206,   127,   127,   131,   208,   209,
     210,   221,   221,   129,   132,   231,   127,   131,   214,   215,
     216,   234,   143,   127,   127,   230,   128,   159,   209,   132,
     231,   230,   213,   215,   132,   231,   143,   132,   127,   132,
     210,   132,   216,   127,   208,   214,   127,   196,   127
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
     167,   166,   168,   168,   168,   169,   169,   170,   171,   171,
     171,   171,   171,   172,   172,   173,   173,   174,   175,   175,
     176,   176,   177,   177,   179,   178,   180,   180,   180,   180,
     181,   181,   181,   181,   181,   183,   184,   182,   186,   185,
     187,   187,   187,   187,   187,   188,   188,   188,   189,   189,
     189,   189,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   191,   191,   192,   192,   193,
     193,   193,   194,   194,   195,   195,   196,   196,   197,   198,
     198,   198,   199,   199,   200,   200,   201,   201,   201,   202,
     202,   203,   204,   204,   205,   205,   206,   206,   206,   206,
     206,   206,   207,   207,   207,   207,   208,   208,   208,   209,
     209,   210,   211,   211,   212,   212,   213,   213,   213,   214,
     214,   214,   215,   215,   216,   216,   216,   216,   217,   218,
     217,   219,   219,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   221,   221,   221,   221,   221,
     222,   222,   222,   222,   223,   223,   223,   224,   224,   225,
     225,   226,   226,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   228,
     229,   230,   230,   231,   231,   231,   231,   232,   232,   232,
     232,   232,   232,   233,   233,   234,   234
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
       2,     3,     3,     2,     2,     2,     3,     2,     1,     4,
       6,     1,     3,     3,     4,     3,     4,     2,     2,     3,
       0,     5,     1,     3,     2,     0,     2,     5,     3,     4,
       5,     5,     4,     1,     1,     1,     0,     1,     3,     3,
       1,     1,     0,     1,     0,     8,     0,     2,     3,     3,
       2,     3,     3,     2,     1,     0,     0,     5,     0,     6,
       0,     2,     3,     3,     3,     4,     3,     0,     0,     2,
       3,     3,     2,     2,     3,     2,     2,     2,     2,     1,
       1,     2,     2,     2,     3,     3,     3,     3,     4,     3,
       3,     4,     2,     2,     3,     3,     2,     3,     4,     4,
       4,     3,     8,     2,     2,     6,     1,     1,     2,     3,
       2,     2,     2,     3,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     7,     1,
       1,     1,     0,     1,     1,     1,     0,     2,     6,     1,
       3,     1,     1,     5,     1,     3,     1,     1,     2,     2,
       1,     1,     2,     2,     2,     4,     1,     3,     4,     1,
       3,     2,     1,     3,     1,     3,     2,     4,     3,     1,
       3,     4,     1,     3,     1,     1,     2,     3,     0,     0,
       2,     1,     2,     1,     1,     2,     2,     2,     3,     3,
       2,     2,     3,     2,     2,     0,     1,     2,     3,     4,
       1,     1,     1,     1,     0,     2,     6,     3,     1,     1,
       1,     0,     1,     2,     3,     3,     2,     3,     3,     2,
       3,     3,     2,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     3,     4,     4,     2,     1,
       1,     0,     2,     0,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 269 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { file->errors++; }
#line 2236 "parse.c"
    break;

  case 18: /* asnumber: NUMBER  */
#line 272 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2251 "parse.c"
    break;

  case 19: /* as4number: STRING  */
#line 283 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			const char	*errstr;
			char		*dot;
			u_int32_t	 uvalh = 0, uval;

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
#line 2288 "parse.c"
    break;

  case 20: /* as4number: asnumber  */
#line 315 "../../../openbgpd-portable/src/bgpd/parse.y"
                           {
			if ((yyvsp[0].v.number) == AS_TRANS || (yyvsp[0].v.number) == 0) {
				yyerror("AS %u is reserved and may not be used",
				    (u_int32_t)(yyvsp[0].v.number));
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2301 "parse.c"
    break;

  case 21: /* as4number_any: STRING  */
#line 325 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			const char	*errstr;
			char		*dot;
			u_int32_t	 uvalh = 0, uval;

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
#line 2333 "parse.c"
    break;

  case 22: /* as4number_any: asnumber  */
#line 352 "../../../openbgpd-portable/src/bgpd/parse.y"
                           {
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2341 "parse.c"
    break;

  case 23: /* string: string STRING  */
#line 357 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (asprintf(&(yyval.v.string), "%s %s", (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1)
				fatal("string: asprintf");
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.string));
		}
#line 2352 "parse.c"
    break;

  case 25: /* yesno: STRING  */
#line 366 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2370 "parse.c"
    break;

  case 26: /* varset: STRING '=' string  */
#line 381 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			char *s = (yyvsp[-2].v.string);
			if (cmd_opts & BGPD_OPT_VERBOSE)
				printf("%s = \"%s\"\n", (yyvsp[-2].v.string), (yyvsp[0].v.string));
			while (*s++) {
				if (isspace((unsigned char)*s)) {
					yyerror("macro name cannot contain "
					    "whitespace");
					free((yyvsp[-2].v.string));
					free((yyvsp[0].v.string));
					YYERROR;
				}
			}
			if (symset((yyvsp[-2].v.string), (yyvsp[0].v.string), 0) == -1)
				fatal("cannot store variable");
			free((yyvsp[-2].v.string));
			free((yyvsp[0].v.string));
		}
#line 2393 "parse.c"
    break;

  case 27: /* include: INCLUDE STRING  */
#line 401 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2411 "parse.c"
    break;

  case 28: /* $@1: %empty  */
#line 416 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2428 "parse.c"
    break;

  case 29: /* as_set: ASSET STRING '{' optnl $@1 as_set_l optnl '}'  */
#line 427 "../../../openbgpd-portable/src/bgpd/parse.y"
                                     {
			done_as_set();
		}
#line 2436 "parse.c"
    break;

  case 30: /* as_set: ASSET STRING '{' optnl '}'  */
#line 430 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (new_as_set((yyvsp[-3].v.string)) != 0) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
		}
#line 2448 "parse.c"
    break;

  case 31: /* as_set_l: as4number_any  */
#line 438 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { add_as_set((yyvsp[0].v.number)); }
#line 2454 "parse.c"
    break;

  case 32: /* as_set_l: as_set_l comma as4number_any  */
#line 439 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { add_as_set((yyvsp[0].v.number)); }
#line 2460 "parse.c"
    break;

  case 33: /* $@2: %empty  */
#line 441 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curpset = new_prefix_set((yyvsp[-2].v.string), 0)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			free((yyvsp[-2].v.string));
		}
#line 2472 "parse.c"
    break;

  case 34: /* prefixset: PREFIXSET STRING '{' optnl $@2 prefixset_l optnl '}'  */
#line 447 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2481 "parse.c"
    break;

  case 35: /* prefixset: PREFIXSET STRING '{' optnl '}'  */
#line 451 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curpset = new_prefix_set((yyvsp[-3].v.string), 0)) == NULL) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2495 "parse.c"
    break;

  case 36: /* prefixset_l: prefixset_item  */
#line 461 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2514 "parse.c"
    break;

  case 37: /* prefixset_l: prefixset_l comma prefixset_item  */
#line 475 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2533 "parse.c"
    break;

  case 38: /* prefixset_item: prefix prefixlenop  */
#line 491 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2553 "parse.c"
    break;

  case 39: /* $@3: %empty  */
#line 508 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			curroatree = &conf->roa;
			noexpires = 0;
		}
#line 2562 "parse.c"
    break;

  case 40: /* roa_set: ROASET '{' optnl $@3 roa_set_l optnl '}'  */
#line 511 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			curroatree = NULL;
			noexpires = 1;
		}
#line 2571 "parse.c"
    break;

  case 42: /* $@4: %empty  */
#line 518 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curoset = new_prefix_set((yyvsp[-2].v.string), 1)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			curroatree = &curoset->roaitems;
			noexpires = 1;
			free((yyvsp[-2].v.string));
		}
#line 2585 "parse.c"
    break;

  case 43: /* origin_set: ORIGINSET STRING '{' optnl $@4 roa_set_l optnl '}'  */
#line 526 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			SIMPLEQ_INSERT_TAIL(&conf->originsets, curoset, entry);
			curoset = NULL;
			curroatree = NULL;
		}
#line 2595 "parse.c"
    break;

  case 44: /* origin_set: ORIGINSET STRING '{' optnl '}'  */
#line 531 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2610 "parse.c"
    break;

  case 45: /* expires: %empty  */
#line 543 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			(yyval.v.number) = 0;
		}
#line 2618 "parse.c"
    break;

  case 46: /* expires: EXPIRES NUMBER  */
#line 546 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (noexpires) {
				yyerror("syntax error, expires not allowed");
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2630 "parse.c"
    break;

  case 47: /* roa_set_l: prefixset_item SOURCEAS as4number_any expires  */
#line 554 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2645 "parse.c"
    break;

  case 48: /* roa_set_l: roa_set_l comma prefixset_item SOURCEAS as4number_any expires  */
#line 564 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2660 "parse.c"
    break;

  case 49: /* rtr: RTR address  */
#line 576 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = 323;
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2674 "parse.c"
    break;

  case 50: /* $@5: %empty  */
#line 585 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = 323;
		}
#line 2683 "parse.c"
    break;

  case 51: /* rtr: RTR address $@5 '{' optnl rtropt_l optnl '}'  */
#line 588 "../../../openbgpd-portable/src/bgpd/parse.y"
                                               {
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2695 "parse.c"
    break;

  case 54: /* rtropt: DESCR STRING  */
#line 600 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2711 "parse.c"
    break;

  case 55: /* rtropt: LOCALADDR address  */
#line 611 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.addr).aid != currtr->remote_addr.aid) {
				yyerror("Bad address family %s for "
				    "local-addr", aid2str((yyvsp[0].v.addr).aid));
				YYERROR;
			}
			currtr->local_addr = (yyvsp[0].v.addr);
		}
#line 2724 "parse.c"
    break;

  case 56: /* rtropt: PORT NUMBER  */
#line 619 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("local-port must be between %u and %u",
				    1, USHRT_MAX);
				YYERROR;
			}
			currtr->remote_port = (yyvsp[0].v.number);
		}
#line 2737 "parse.c"
    break;

  case 57: /* conf_main: AS as4number  */
#line 629 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			conf->as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				conf->short_as = AS_TRANS;
			else
				conf->short_as = (yyvsp[0].v.number);
		}
#line 2749 "parse.c"
    break;

  case 58: /* conf_main: AS as4number asnumber  */
#line 636 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			conf->as = (yyvsp[-1].v.number);
			conf->short_as = (yyvsp[0].v.number);
		}
#line 2758 "parse.c"
    break;

  case 59: /* conf_main: ROUTERID address  */
#line 640 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.addr).aid != AID_INET) {
				yyerror("router-id must be an IPv4 address");
				YYERROR;
			}
			conf->bgpid = (yyvsp[0].v.addr).v4.s_addr;
		}
#line 2770 "parse.c"
    break;

  case 60: /* conf_main: HOLDTIME NUMBER  */
#line 647 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->holdtime = (yyvsp[0].v.number);
		}
#line 2783 "parse.c"
    break;

  case 61: /* conf_main: HOLDTIME YMIN NUMBER  */
#line 655 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->min_holdtime = (yyvsp[0].v.number);
		}
#line 2796 "parse.c"
    break;

  case 62: /* conf_main: LISTEN ON address  */
#line 663 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2815 "parse.c"
    break;

  case 63: /* conf_main: FIBPRIORITY NUMBER  */
#line 677 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) <= RTP_NONE || (yyvsp[0].v.number) > RTP_MAX) {
				yyerror("invalid fib-priority");
				YYERROR;
			}
			conf->fib_priority = (yyvsp[0].v.number);
		}
#line 2827 "parse.c"
    break;

  case 64: /* conf_main: FIBUPDATE yesno  */
#line 684 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2843 "parse.c"
    break;

  case 65: /* conf_main: TRANSPARENT yesno  */
#line 695 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_DECISION_TRANS_AS;
			else
				conf->flags &= ~BGPD_FLAG_DECISION_TRANS_AS;
		}
#line 2854 "parse.c"
    break;

  case 66: /* conf_main: REJECT ASSET yesno  */
#line 701 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_NO_AS_SET;
			else
				conf->flags &= ~BGPD_FLAG_NO_AS_SET;
		}
#line 2865 "parse.c"
    break;

  case 67: /* conf_main: LOG STRING  */
#line 707 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (!strcmp((yyvsp[0].v.string), "updates"))
				conf->log |= BGPD_LOG_UPDATES;
			else {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 2879 "parse.c"
    break;

  case 69: /* conf_main: DUMP STRING STRING optnumber  */
#line 717 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2912 "parse.c"
    break;

  case 70: /* conf_main: DUMP RIB STRING STRING STRING optnumber  */
#line 745 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2949 "parse.c"
    break;

  case 72: /* conf_main: RDE STRING EVALUATE  */
#line 778 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2964 "parse.c"
    break;

  case 73: /* conf_main: RDE STRING IGNORE  */
#line 788 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2979 "parse.c"
    break;

  case 74: /* conf_main: RDE MED COMPARE STRING  */
#line 798 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2997 "parse.c"
    break;

  case 75: /* conf_main: RDE EVALUATE STRING  */
#line 811 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3015 "parse.c"
    break;

  case 76: /* conf_main: NEXTHOP QUALIFY VIA STRING  */
#line 824 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3033 "parse.c"
    break;

  case 77: /* conf_main: RTABLE NUMBER  */
#line 837 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3054 "parse.c"
    break;

  case 78: /* conf_main: CONNECTRETRY NUMBER  */
#line 853 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			if ((yyvsp[0].v.number) > USHRT_MAX || (yyvsp[0].v.number) < 1) {
				yyerror("invalid connect-retry");
				YYERROR;
			}
			conf->connectretry = (yyvsp[0].v.number);
		}
#line 3066 "parse.c"
    break;

  case 79: /* conf_main: SOCKET STRING restricted  */
#line 860 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3085 "parse.c"
    break;

  case 80: /* $@6: %empty  */
#line 876 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if ((currib = add_rib((yyvsp[0].v.string))) == NULL) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 3097 "parse.c"
    break;

  case 81: /* rib: RDE RIB STRING $@6 ribopts  */
#line 882 "../../../openbgpd-portable/src/bgpd/parse.y"
                          {
			currib = NULL;
		}
#line 3105 "parse.c"
    break;

  case 83: /* ribopts: RTABLE NUMBER fibupdate  */
#line 887 "../../../openbgpd-portable/src/bgpd/parse.y"
                                          {
			if ((yyvsp[-1].v.number) > RT_TABLEID_MAX) {
				yyerror("rtable %llu too big: max %u", (yyvsp[-1].v.number),
				    RT_TABLEID_MAX);
				YYERROR;
			}
			if (rib_add_fib(currib, (yyvsp[-1].v.number)) == -1)
				YYERROR;
		}
#line 3119 "parse.c"
    break;

  case 84: /* ribopts: yesno EVALUATE  */
#line 896 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if ((yyvsp[-1].v.number)) {
				yyerror("bad rde rib definition");
				YYERROR;
			}
			currib->flags |= F_RIB_NOEVALUATE;
		}
#line 3131 "parse.c"
    break;

  case 86: /* fibupdate: FIBUPDATE yesno  */
#line 906 "../../../openbgpd-portable/src/bgpd/parse.y"
                                  {
			if ((yyvsp[0].v.number) == 0)
				currib->flags |= F_RIB_NOFIBSYNC;
			else
				currib->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3142 "parse.c"
    break;

  case 87: /* mrtdump: DUMP STRING inout STRING optnumber  */
#line 914 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3175 "parse.c"
    break;

  case 88: /* network: NETWORK prefix filter_set  */
#line 944 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3201 "parse.c"
    break;

  case 89: /* network: NETWORK PREFIXSET STRING filter_set  */
#line 965 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3235 "parse.c"
    break;

  case 90: /* network: NETWORK family RTLABEL STRING filter_set  */
#line 994 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3259 "parse.c"
    break;

  case 91: /* network: NETWORK family PRIORITY NUMBER filter_set  */
#line 1013 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3288 "parse.c"
    break;

  case 92: /* network: NETWORK family nettype filter_set  */
#line 1037 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3311 "parse.c"
    break;

  case 93: /* inout: IN  */
#line 1057 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 3317 "parse.c"
    break;

  case 94: /* inout: OUT  */
#line 1058 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 3323 "parse.c"
    break;

  case 95: /* restricted: RESTRICTED  */
#line 1061 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 3329 "parse.c"
    break;

  case 96: /* restricted: %empty  */
#line 1062 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 3335 "parse.c"
    break;

  case 97: /* address: STRING  */
#line 1065 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			u_int8_t	len;

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
#line 3359 "parse.c"
    break;

  case 98: /* prefix: STRING '/' NUMBER  */
#line 1086 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3382 "parse.c"
    break;

  case 99: /* prefix: NUMBER '/' NUMBER  */
#line 1104 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3405 "parse.c"
    break;

  case 100: /* addrspec: address  */
#line 1124 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			memcpy(&(yyval.v.prefix).prefix, &(yyvsp[0].v.addr), sizeof(struct bgpd_addr));
			if ((yyval.v.prefix).prefix.aid == AID_INET)
				(yyval.v.prefix).len = 32;
			else
				(yyval.v.prefix).len = 128;
		}
#line 3417 "parse.c"
    break;

  case 102: /* optnumber: %empty  */
#line 1134 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0; }
#line 3423 "parse.c"
    break;

  case 104: /* $@7: %empty  */
#line 1138 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3466 "parse.c"
    break;

  case 105: /* l3vpn: VPN STRING ON STRING $@7 '{' l3vpnopts_l '}'  */
#line 1175 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			/* insert into list */
			SIMPLEQ_INSERT_TAIL(&conf->l3vpns, curvpn, entry);
			curvpn = NULL;
			netconf = &conf->networks;
		}
#line 3477 "parse.c"
    break;

  case 110: /* l3vpnopts: RD STRING  */
#line 1189 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3500 "parse.c"
    break;

  case 111: /* l3vpnopts: EXPORTTRGT STRING STRING  */
#line 1207 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3523 "parse.c"
    break;

  case 112: /* l3vpnopts: IMPORTTRGT STRING STRING  */
#line 1225 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3546 "parse.c"
    break;

  case 113: /* l3vpnopts: FIBUPDATE yesno  */
#line 1243 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) == 0)
				curvpn->flags |= F_RIB_NOFIBSYNC;
			else
				curvpn->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3557 "parse.c"
    break;

  case 115: /* $@8: %empty  */
#line 1252 "../../../openbgpd-portable/src/bgpd/parse.y"
                  {	curpeer = new_peer(); }
#line 3563 "parse.c"
    break;

  case 116: /* $@9: %empty  */
#line 1253 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3582 "parse.c"
    break;

  case 117: /* neighbor: $@8 NEIGHBOR addrspec $@9 peeropts_h  */
#line 1267 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3605 "parse.c"
    break;

  case 118: /* $@10: %empty  */
#line 1287 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3628 "parse.c"
    break;

  case 119: /* group: GROUP string $@10 '{' groupopts_l '}'  */
#line 1304 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3646 "parse.c"
    break;

  case 132: /* peeropts: REMOTEAS as4number  */
#line 1337 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.remote_as = (yyvsp[0].v.number);
		}
#line 3654 "parse.c"
    break;

  case 133: /* peeropts: LOCALAS as4number  */
#line 1340 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.local_as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				curpeer->conf.local_short_as = AS_TRANS;
			else
				curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3666 "parse.c"
    break;

  case 134: /* peeropts: LOCALAS as4number asnumber  */
#line 1347 "../../../openbgpd-portable/src/bgpd/parse.y"
                                             {
			curpeer->conf.local_as = (yyvsp[-1].v.number);
			curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3675 "parse.c"
    break;

  case 135: /* peeropts: DESCR string  */
#line 1351 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3691 "parse.c"
    break;

  case 136: /* peeropts: LOCALADDR address  */
#line 1362 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3709 "parse.c"
    break;

  case 137: /* peeropts: yesno LOCALADDR  */
#line 1375 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3724 "parse.c"
    break;

  case 138: /* peeropts: MULTIHOP NUMBER  */
#line 1385 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 2 || (yyvsp[0].v.number) > 255) {
				yyerror("invalid multihop distance %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			curpeer->conf.distance = (yyvsp[0].v.number);
		}
#line 3736 "parse.c"
    break;

  case 139: /* peeropts: PASSIVE  */
#line 1392 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.passive = 1;
		}
#line 3744 "parse.c"
    break;

  case 140: /* peeropts: DOWN  */
#line 1395 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.down = 1;
		}
#line 3752 "parse.c"
    break;

  case 141: /* peeropts: DOWN STRING  */
#line 1398 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3768 "parse.c"
    break;

  case 142: /* peeropts: RIB STRING  */
#line 1409 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3789 "parse.c"
    break;

  case 143: /* peeropts: HOLDTIME NUMBER  */
#line 1425 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.holdtime = (yyvsp[0].v.number);
		}
#line 3802 "parse.c"
    break;

  case 144: /* peeropts: HOLDTIME YMIN NUMBER  */
#line 1433 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.min_holdtime = (yyvsp[0].v.number);
		}
#line 3815 "parse.c"
    break;

  case 145: /* peeropts: ANNOUNCE family safi  */
#line 1441 "../../../openbgpd-portable/src/bgpd/parse.y"
                                       {
			u_int8_t	aid, safi;
			u_int16_t	afi;

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
#line 3839 "parse.c"
    break;

  case 146: /* peeropts: ANNOUNCE CAPABILITIES yesno  */
#line 1460 "../../../openbgpd-portable/src/bgpd/parse.y"
                                              {
			curpeer->conf.announce_capa = (yyvsp[0].v.number);
		}
#line 3847 "parse.c"
    break;

  case 147: /* peeropts: ANNOUNCE REFRESH yesno  */
#line 1463 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.refresh = (yyvsp[0].v.number);
		}
#line 3855 "parse.c"
    break;

  case 148: /* peeropts: ANNOUNCE ENHANCED REFRESH yesno  */
#line 1466 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                  {
			curpeer->conf.capabilities.enhanced_rr = (yyvsp[0].v.number);
		}
#line 3863 "parse.c"
    break;

  case 149: /* peeropts: ANNOUNCE RESTART yesno  */
#line 1469 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.grestart.restart = (yyvsp[0].v.number);
		}
#line 3871 "parse.c"
    break;

  case 150: /* peeropts: ANNOUNCE AS4BYTE yesno  */
#line 1472 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.as4byte = (yyvsp[0].v.number);
		}
#line 3879 "parse.c"
    break;

  case 151: /* peeropts: ANNOUNCE ADDPATH RECV yesno  */
#line 1475 "../../../openbgpd-portable/src/bgpd/parse.y"
                                              {
			int8_t *ap = curpeer->conf.capabilities.add_path;
			u_int8_t i;

			for (i = 0; i < AID_MAX; i++)
				if ((yyvsp[0].v.number))
					*ap++ |= CAPA_AP_RECV;
				else
					*ap++ &= ~CAPA_AP_RECV;
		}
#line 3894 "parse.c"
    break;

  case 152: /* peeropts: EXPORT NONE  */
#line 1485 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			curpeer->conf.export_type = EXPORT_NONE;
		}
#line 3902 "parse.c"
    break;

  case 153: /* peeropts: EXPORT DEFAULTROUTE  */
#line 1488 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			curpeer->conf.export_type = EXPORT_DEFAULT_ROUTE;
		}
#line 3910 "parse.c"
    break;

  case 154: /* peeropts: ENFORCE NEIGHBORAS yesno  */
#line 1491 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_as = ENFORCE_AS_OFF;
		}
#line 3921 "parse.c"
    break;

  case 155: /* peeropts: ENFORCE LOCALAS yesno  */
#line 1497 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_local_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_local_as = ENFORCE_AS_OFF;
		}
#line 3932 "parse.c"
    break;

  case 156: /* peeropts: ASOVERRIDE yesno  */
#line 1503 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3952 "parse.c"
    break;

  case 157: /* peeropts: MAXPREFIX NUMBER restart  */
#line 1518 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if ((yyvsp[-1].v.number) < 0 || (yyvsp[-1].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_prefix = (yyvsp[-1].v.number);
			curpeer->conf.max_prefix_restart = (yyvsp[0].v.number);
		}
#line 3965 "parse.c"
    break;

  case 158: /* peeropts: MAXPREFIX NUMBER OUT restart  */
#line 1526 "../../../openbgpd-portable/src/bgpd/parse.y"
                                               {
			if ((yyvsp[-2].v.number) < 0 || (yyvsp[-2].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_out_prefix = (yyvsp[-2].v.number);
			curpeer->conf.max_out_prefix_restart = (yyvsp[0].v.number);
		}
#line 3978 "parse.c"
    break;

  case 159: /* peeropts: TCP MD5SIG PASSWORD string  */
#line 1534 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4001 "parse.c"
    break;

  case 160: /* peeropts: TCP MD5SIG KEY string  */
#line 1552 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4022 "parse.c"
    break;

  case 161: /* peeropts: IPSEC espah IKE  */
#line 1568 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4037 "parse.c"
    break;

  case 162: /* peeropts: IPSEC espah inout SPI NUMBER STRING STRING encspec  */
#line 1578 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                     {
			u_int32_t	auth_alg;
			u_int8_t	keylen;

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
#line 4135 "parse.c"
    break;

  case 163: /* peeropts: TTLSECURITY yesno  */
#line 1671 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.ttlsec = (yyvsp[0].v.number);
		}
#line 4143 "parse.c"
    break;

  case 164: /* peeropts: SET filter_set_opt  */
#line 1674 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			struct filter_rule	*r;

			r = get_rule((yyvsp[0].v.filter_set)->type);
			if (merge_filterset(&r->set, (yyvsp[0].v.filter_set)) == -1)
				YYERROR;
		}
#line 4155 "parse.c"
    break;

  case 165: /* peeropts: SET '{' optnl filter_set_l optnl '}'  */
#line 1681 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4172 "parse.c"
    break;

  case 167: /* peeropts: REFLECTOR  */
#line 1694 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4187 "parse.c"
    break;

  case 168: /* peeropts: REFLECTOR address  */
#line 1704 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4208 "parse.c"
    break;

  case 169: /* peeropts: DEPEND ON STRING  */
#line 1720 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4225 "parse.c"
    break;

  case 170: /* peeropts: DEMOTE STRING  */
#line 1732 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4254 "parse.c"
    break;

  case 171: /* peeropts: TRANSPARENT yesno  */
#line 1756 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_TRANS_AS;
			else
				curpeer->conf.flags &= ~PEERFLAG_TRANS_AS;
		}
#line 4265 "parse.c"
    break;

  case 172: /* peeropts: LOG STRING  */
#line 1762 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4281 "parse.c"
    break;

  case 173: /* peeropts: REJECT ASSET yesno  */
#line 1773 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_NO_AS_SET;
			else
				curpeer->conf.flags &= ~PEERFLAG_NO_AS_SET;
		}
#line 4292 "parse.c"
    break;

  case 174: /* peeropts: RDE EVALUATE STRING  */
#line 1779 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4310 "parse.c"
    break;

  case 175: /* restart: %empty  */
#line 1794 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0; }
#line 4316 "parse.c"
    break;

  case 176: /* restart: RESTART NUMBER  */
#line 1795 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("restart out of range. 1 to %u minutes",
				    USHRT_MAX);
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 4329 "parse.c"
    break;

  case 177: /* family: IPV4  */
#line 1805 "../../../openbgpd-portable/src/bgpd/parse.y"
                        { (yyval.v.number) = AFI_IPv4; }
#line 4335 "parse.c"
    break;

  case 178: /* family: IPV6  */
#line 1806 "../../../openbgpd-portable/src/bgpd/parse.y"
                        { (yyval.v.number) = AFI_IPv6; }
#line 4341 "parse.c"
    break;

  case 179: /* safi: NONE  */
#line 1809 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_NONE; }
#line 4347 "parse.c"
    break;

  case 180: /* safi: UNICAST  */
#line 1810 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_UNICAST; }
#line 4353 "parse.c"
    break;

  case 181: /* safi: VPN  */
#line 1811 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_MPLSVPN; }
#line 4359 "parse.c"
    break;

  case 182: /* nettype: STATIC  */
#line 1814 "../../../openbgpd-portable/src/bgpd/parse.y"
                         { (yyval.v.number) = 1; }
#line 4365 "parse.c"
    break;

  case 183: /* nettype: CONNECTED  */
#line 1815 "../../../openbgpd-portable/src/bgpd/parse.y"
                            { (yyval.v.number) = 0; }
#line 4371 "parse.c"
    break;

  case 184: /* espah: ESP  */
#line 1818 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 4377 "parse.c"
    break;

  case 185: /* espah: AH  */
#line 1819 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 4383 "parse.c"
    break;

  case 186: /* encspec: %empty  */
#line 1822 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			bzero(&(yyval.v.encspec), sizeof((yyval.v.encspec)));
		}
#line 4391 "parse.c"
    break;

  case 187: /* encspec: STRING STRING  */
#line 1825 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4427 "parse.c"
    break;

  case 188: /* filterrule: action quick filter_rib_h direction filter_peer_h filter_match_h filter_set  */
#line 1860 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4455 "parse.c"
    break;

  case 189: /* action: ALLOW  */
#line 1885 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_ALLOW; }
#line 4461 "parse.c"
    break;

  case 190: /* action: DENY  */
#line 1886 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_DENY; }
#line 4467 "parse.c"
    break;

  case 191: /* action: MATCH  */
#line 1887 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_NONE; }
#line 4473 "parse.c"
    break;

  case 192: /* quick: %empty  */
#line 1890 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 0; }
#line 4479 "parse.c"
    break;

  case 193: /* quick: QUICK  */
#line 1891 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 1; }
#line 4485 "parse.c"
    break;

  case 194: /* direction: FROM  */
#line 1894 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = DIR_IN; }
#line 4491 "parse.c"
    break;

  case 195: /* direction: TO  */
#line 1895 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = DIR_OUT; }
#line 4497 "parse.c"
    break;

  case 196: /* filter_rib_h: %empty  */
#line 1898 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = NULL; }
#line 4503 "parse.c"
    break;

  case 197: /* filter_rib_h: RIB filter_rib  */
#line 1899 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4509 "parse.c"
    break;

  case 198: /* filter_rib_h: RIB '{' optnl filter_rib_l optnl '}'  */
#line 1900 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_rib) = (yyvsp[-2].v.filter_rib); }
#line 4515 "parse.c"
    break;

  case 199: /* filter_rib_l: filter_rib  */
#line 1902 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4521 "parse.c"
    break;

  case 200: /* filter_rib_l: filter_rib_l comma filter_rib  */
#line 1903 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			(yyvsp[0].v.filter_rib)->next = (yyvsp[-2].v.filter_rib);
			(yyval.v.filter_rib) = (yyvsp[0].v.filter_rib);
		}
#line 4530 "parse.c"
    break;

  case 201: /* filter_rib: STRING  */
#line 1909 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4555 "parse.c"
    break;

  case 203: /* filter_peer_h: '{' optnl filter_peer_l optnl '}'  */
#line 1932 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_peers) = (yyvsp[-2].v.filter_peers); }
#line 4561 "parse.c"
    break;

  case 204: /* filter_peer_l: filter_peer  */
#line 1935 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_peers) = (yyvsp[0].v.filter_peers); }
#line 4567 "parse.c"
    break;

  case 205: /* filter_peer_l: filter_peer_l comma filter_peer  */
#line 1936 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyvsp[0].v.filter_peers)->next = (yyvsp[-2].v.filter_peers);
			(yyval.v.filter_peers) = (yyvsp[0].v.filter_peers);
		}
#line 4576 "parse.c"
    break;

  case 206: /* filter_peer: ANY  */
#line 1942 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.peerid = (yyval.v.filter_peers)->p.groupid = 0;
			(yyval.v.filter_peers)->next = NULL;
		}
#line 4588 "parse.c"
    break;

  case 207: /* filter_peer: address  */
#line 1949 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4613 "parse.c"
    break;

  case 208: /* filter_peer: AS as4number  */
#line 1969 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.groupid = (yyval.v.filter_peers)->p.peerid = 0;
			(yyval.v.filter_peers)->p.remote_as = (yyvsp[0].v.number);
		}
#line 4625 "parse.c"
    break;

  case 209: /* filter_peer: GROUP STRING  */
#line 1976 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4651 "parse.c"
    break;

  case 210: /* filter_peer: EBGP  */
#line 1997 "../../../openbgpd-portable/src/bgpd/parse.y"
                       {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ebgp = 1;
		}
#line 4662 "parse.c"
    break;

  case 211: /* filter_peer: IBGP  */
#line 2003 "../../../openbgpd-portable/src/bgpd/parse.y"
                       {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ibgp = 1;
		}
#line 4673 "parse.c"
    break;

  case 212: /* filter_prefix_h: IPV4 prefixlenop  */
#line 2011 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4693 "parse.c"
    break;

  case 213: /* filter_prefix_h: IPV6 prefixlenop  */
#line 2026 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4713 "parse.c"
    break;

  case 214: /* filter_prefix_h: PREFIX filter_prefix  */
#line 2041 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4719 "parse.c"
    break;

  case 215: /* filter_prefix_h: PREFIX '{' filter_prefix_m '}'  */
#line 2042 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4725 "parse.c"
    break;

  case 217: /* filter_prefix_m: '{' filter_prefix_l '}'  */
#line 2046 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4731 "parse.c"
    break;

  case 218: /* filter_prefix_m: '{' filter_prefix_l '}' filter_prefix_m  */
#line 2048 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_prefix_l  *p;

			/* merge, both can be lists */
			for (p = (yyvsp[-2].v.filter_prefix); p != NULL && p->next != NULL; p = p->next)
				;       /* nothing */
			if (p != NULL)
				p->next = (yyvsp[0].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[-2].v.filter_prefix);
		}
#line 4746 "parse.c"
    break;

  case 219: /* filter_prefix_l: filter_prefix  */
#line 2059 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4752 "parse.c"
    break;

  case 220: /* filter_prefix_l: filter_prefix_l comma filter_prefix  */
#line 2060 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyvsp[0].v.filter_prefix)->next = (yyvsp[-2].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix);
		}
#line 4761 "parse.c"
    break;

  case 221: /* filter_prefix: prefix prefixlenop  */
#line 2066 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4779 "parse.c"
    break;

  case 223: /* filter_as_h: '{' filter_as_t_l '}'  */
#line 2082 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4785 "parse.c"
    break;

  case 225: /* filter_as_t_l: filter_as_t_l comma filter_as_t  */
#line 2086 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4800 "parse.c"
    break;

  case 226: /* filter_as_t: filter_as_type filter_as  */
#line 2098 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as)->a.type = (yyvsp[-1].v.u8);
		}
#line 4809 "parse.c"
    break;

  case 227: /* filter_as_t: filter_as_type '{' filter_as_l_h '}'  */
#line 2102 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			struct filter_as_l	*a;

			(yyval.v.filter_as) = (yyvsp[-1].v.filter_as);
			for (a = (yyval.v.filter_as); a != NULL; a = a->next)
				a->a.type = (yyvsp[-3].v.u8);
		}
#line 4821 "parse.c"
    break;

  case 228: /* filter_as_t: filter_as_type ASSET STRING  */
#line 2109 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4847 "parse.c"
    break;

  case 230: /* filter_as_l_h: '{' filter_as_l '}'  */
#line 2133 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4853 "parse.c"
    break;

  case 231: /* filter_as_l_h: '{' filter_as_l '}' filter_as_l_h  */
#line 2135 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4868 "parse.c"
    break;

  case 233: /* filter_as_l: filter_as_l comma filter_as  */
#line 2148 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			(yyvsp[0].v.filter_as)->next = (yyvsp[-2].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
		}
#line 4877 "parse.c"
    break;

  case 234: /* filter_as: as4number_any  */
#line 2154 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.op = OP_EQ;
		}
#line 4890 "parse.c"
    break;

  case 235: /* filter_as: NEIGHBORAS  */
#line 2162 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.flags = AS_FLAG_NEIGHBORAS;
		}
#line 4901 "parse.c"
    break;

  case 236: /* filter_as: equalityop as4number_any  */
#line 2168 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.op = (yyvsp[-1].v.u8);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
		}
#line 4914 "parse.c"
    break;

  case 237: /* filter_as: as4number_any binaryop as4number_any  */
#line 2176 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4931 "parse.c"
    break;

  case 238: /* filter_match_h: %empty  */
#line 2190 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			bzero(&(yyval.v.filter_match), sizeof((yyval.v.filter_match)));
		}
#line 4939 "parse.c"
    break;

  case 239: /* $@11: %empty  */
#line 2193 "../../../openbgpd-portable/src/bgpd/parse.y"
                  {
			bzero(&fmopts, sizeof(fmopts));
		}
#line 4947 "parse.c"
    break;

  case 240: /* filter_match_h: $@11 filter_match  */
#line 2196 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			memcpy(&(yyval.v.filter_match), &fmopts, sizeof((yyval.v.filter_match)));
		}
#line 4955 "parse.c"
    break;

  case 243: /* filter_elm: filter_prefix_h  */
#line 2205 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4973 "parse.c"
    break;

  case 244: /* filter_elm: filter_as_h  */
#line 2218 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.as_l != NULL) {
				yyerror("AS filters already specified");
				YYERROR;
			}
			fmopts.as_l = (yyvsp[0].v.filter_as);
		}
#line 4985 "parse.c"
    break;

  case 245: /* filter_elm: MAXASLEN NUMBER  */
#line 2225 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5002 "parse.c"
    break;

  case 246: /* filter_elm: MAXASSEQ NUMBER  */
#line 2237 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5019 "parse.c"
    break;

  case 247: /* filter_elm: community STRING  */
#line 2249 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5042 "parse.c"
    break;

  case 248: /* filter_elm: EXTCOMMUNITY STRING STRING  */
#line 2267 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5069 "parse.c"
    break;

  case 249: /* filter_elm: EXTCOMMUNITY OVS STRING  */
#line 2289 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5093 "parse.c"
    break;

  case 250: /* filter_elm: NEXTHOP address  */
#line 2308 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.addr = (yyvsp[0].v.addr);
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_ADDR;
		}
#line 5106 "parse.c"
    break;

  case 251: /* filter_elm: NEXTHOP NEIGHBOR  */
#line 2316 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_NEIGHBOR;
		}
#line 5118 "parse.c"
    break;

  case 252: /* filter_elm: PREFIXSET STRING prefixlenop  */
#line 2323 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5172 "parse.c"
    break;

  case 253: /* filter_elm: ORIGINSET STRING  */
#line 2372 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5197 "parse.c"
    break;

  case 254: /* filter_elm: OVS validity  */
#line 2392 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.ovs.is_set) {
				yyerror("ovs filter already specified");
				YYERROR;
			}
			fmopts.m.ovs.validity = (yyvsp[0].v.number);
			fmopts.m.ovs.is_set = 1;
		}
#line 5210 "parse.c"
    break;

  case 255: /* prefixlenop: %empty  */
#line 2402 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen))); }
#line 5216 "parse.c"
    break;

  case 256: /* prefixlenop: LONGER  */
#line 2403 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen)));
			(yyval.v.prefixlen).op = OP_RANGE;
			(yyval.v.prefixlen).len_min = -1;
			(yyval.v.prefixlen).len_max = -1;
		}
#line 5227 "parse.c"
    break;

  case 257: /* prefixlenop: MAXLEN NUMBER  */
#line 2409 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5243 "parse.c"
    break;

  case 258: /* prefixlenop: PREFIXLEN unaryop NUMBER  */
#line 2420 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5291 "parse.c"
    break;

  case 259: /* prefixlenop: PREFIXLEN NUMBER binaryop NUMBER  */
#line 2463 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5310 "parse.c"
    break;

  case 260: /* filter_as_type: AS  */
#line 2479 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_ALL; }
#line 5316 "parse.c"
    break;

  case 261: /* filter_as_type: SOURCEAS  */
#line 2480 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_SOURCE; }
#line 5322 "parse.c"
    break;

  case 262: /* filter_as_type: TRANSITAS  */
#line 2481 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_TRANSIT; }
#line 5328 "parse.c"
    break;

  case 263: /* filter_as_type: PEERAS  */
#line 2482 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_PEER; }
#line 5334 "parse.c"
    break;

  case 264: /* filter_set: %empty  */
#line 2485 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                { (yyval.v.filter_set_head) = NULL; }
#line 5340 "parse.c"
    break;

  case 265: /* filter_set: SET filter_set_opt  */
#line 2486 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5352 "parse.c"
    break;

  case 266: /* filter_set: SET '{' optnl filter_set_l optnl '}'  */
#line 2493 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head); }
#line 5358 "parse.c"
    break;

  case 267: /* filter_set_l: filter_set_l comma filter_set_opt  */
#line 2496 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head);
			if (merge_filterset((yyval.v.filter_set_head), (yyvsp[0].v.filter_set)) == 1)
				YYERROR;
		}
#line 5368 "parse.c"
    break;

  case 268: /* filter_set_l: filter_set_opt  */
#line 2501 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5380 "parse.c"
    break;

  case 269: /* community: COMMUNITY  */
#line 2510 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.u8) = COMMUNITY_TYPE_BASIC; }
#line 5386 "parse.c"
    break;

  case 270: /* community: LARGECOMMUNITY  */
#line 2511 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.u8) = COMMUNITY_TYPE_LARGE; }
#line 5392 "parse.c"
    break;

  case 271: /* delete: %empty  */
#line 2514 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 0; }
#line 5398 "parse.c"
    break;

  case 272: /* delete: DELETE  */
#line 2515 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 1; }
#line 5404 "parse.c"
    break;

  case 273: /* filter_set_opt: LOCALPREF NUMBER  */
#line 2518 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5424 "parse.c"
    break;

  case 274: /* filter_set_opt: LOCALPREF '+' NUMBER  */
#line 2533 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5439 "parse.c"
    break;

  case 275: /* filter_set_opt: LOCALPREF '-' NUMBER  */
#line 2543 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5454 "parse.c"
    break;

  case 276: /* filter_set_opt: MED NUMBER  */
#line 2553 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5474 "parse.c"
    break;

  case 277: /* filter_set_opt: MED '+' NUMBER  */
#line 2568 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5489 "parse.c"
    break;

  case 278: /* filter_set_opt: MED '-' NUMBER  */
#line 2578 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5504 "parse.c"
    break;

  case 279: /* filter_set_opt: METRIC NUMBER  */
#line 2588 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5524 "parse.c"
    break;

  case 280: /* filter_set_opt: METRIC '+' NUMBER  */
#line 2603 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5539 "parse.c"
    break;

  case 281: /* filter_set_opt: METRIC '-' NUMBER  */
#line 2613 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5554 "parse.c"
    break;

  case 282: /* filter_set_opt: WEIGHT NUMBER  */
#line 2623 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5574 "parse.c"
    break;

  case 283: /* filter_set_opt: WEIGHT '+' NUMBER  */
#line 2638 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5589 "parse.c"
    break;

  case 284: /* filter_set_opt: WEIGHT '-' NUMBER  */
#line 2648 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5604 "parse.c"
    break;

  case 285: /* filter_set_opt: NEXTHOP address  */
#line 2658 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP;
			memcpy(&(yyval.v.filter_set)->action.nexthop, &(yyvsp[0].v.addr),
			    sizeof((yyval.v.filter_set)->action.nexthop));
		}
#line 5616 "parse.c"
    break;

  case 286: /* filter_set_opt: NEXTHOP BLACKHOLE  */
#line 2665 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_BLACKHOLE;
		}
#line 5626 "parse.c"
    break;

  case 287: /* filter_set_opt: NEXTHOP REJECT  */
#line 2670 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_REJECT;
		}
#line 5636 "parse.c"
    break;

  case 288: /* filter_set_opt: NEXTHOP NOMODIFY  */
#line 2675 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_NOMODIFY;
		}
#line 5646 "parse.c"
    break;

  case 289: /* filter_set_opt: NEXTHOP SELF  */
#line 2680 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_SELF;
		}
#line 5656 "parse.c"
    break;

  case 290: /* filter_set_opt: PREPEND_SELF NUMBER  */
#line 2685 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5671 "parse.c"
    break;

  case 291: /* filter_set_opt: PREPEND_PEER NUMBER  */
#line 2695 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5686 "parse.c"
    break;

  case 292: /* filter_set_opt: ASOVERRIDE  */
#line 2705 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_AS_OVERRIDE;
		}
#line 5696 "parse.c"
    break;

  case 293: /* filter_set_opt: PFTABLE STRING  */
#line 2710 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5728 "parse.c"
    break;

  case 294: /* filter_set_opt: RTLABEL STRING  */
#line 2737 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5747 "parse.c"
    break;

  case 295: /* filter_set_opt: community delete STRING  */
#line 2751 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			u_int8_t f1, f2, f3;

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
#line 5780 "parse.c"
    break;

  case 296: /* filter_set_opt: EXTCOMMUNITY delete STRING STRING  */
#line 2779 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5803 "parse.c"
    break;

  case 297: /* filter_set_opt: EXTCOMMUNITY delete OVS STRING  */
#line 2797 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5824 "parse.c"
    break;

  case 298: /* filter_set_opt: ORIGIN origincode  */
#line 2813 "../../../openbgpd-portable/src/bgpd/parse.y"
                                    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_ORIGIN;
			(yyval.v.filter_set)->action.origin = (yyvsp[0].v.number);
		}
#line 5835 "parse.c"
    break;

  case 299: /* origincode: STRING  */
#line 2821 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5854 "parse.c"
    break;

  case 300: /* validity: STRING  */
#line 2836 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5873 "parse.c"
    break;

  case 307: /* unaryop: '='  */
#line 2861 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_EQ; }
#line 5879 "parse.c"
    break;

  case 308: /* unaryop: NE  */
#line 2862 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_NE; }
#line 5885 "parse.c"
    break;

  case 309: /* unaryop: LE  */
#line 2863 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_LE; }
#line 5891 "parse.c"
    break;

  case 310: /* unaryop: '<'  */
#line 2864 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_LT; }
#line 5897 "parse.c"
    break;

  case 311: /* unaryop: GE  */
#line 2865 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_GE; }
#line 5903 "parse.c"
    break;

  case 312: /* unaryop: '>'  */
#line 2866 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_GT; }
#line 5909 "parse.c"
    break;

  case 313: /* equalityop: '='  */
#line 2869 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_EQ; }
#line 5915 "parse.c"
    break;

  case 314: /* equalityop: NE  */
#line 2870 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_NE; }
#line 5921 "parse.c"
    break;

  case 315: /* binaryop: '-'  */
#line 2873 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_RANGE; }
#line 5927 "parse.c"
    break;

  case 316: /* binaryop: XRANGE  */
#line 2874 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_XRANGE; }
#line 5933 "parse.c"
    break;


#line 5937 "parse.c"

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

#line 2877 "../../../openbgpd-portable/src/bgpd/parse.y"


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
yylex(void)
{
	u_char	 buf[8096];
	u_char	*p, *val;
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
		while (1) {
			if ((c = lgetc(0)) == EOF)
				return (0);

			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
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
		if (val == NULL) {
			yyerror("macro '%s' not defined", buf);
			return (findeol());
		}
		p = val + strlen(val) - 1;
		lungetc(DONE_EXPAND);
		while (p >= val) {
			lungetc(*p);
			p--;
		}
		lungetc(START_EXPAND);
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
				lungetc(*--p);
			c = *--p;
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
	} else {
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
getcommunity(char *s, int large, u_int32_t *val, u_int32_t *flag)
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
setcommunity(struct community *c, u_int32_t as, u_int32_t data,
    u_int32_t asflag, u_int32_t dataflag)
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
	u_int32_t dflag1, dflag2, dflag3;

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
	u_int32_t as, data, asflag, dataflag;

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
parseextvalue(int type, char *s, u_int32_t *v, u_int32_t *flag)
{
	const char	*errstr;
	char		*p;
	struct in_addr	 ip;
	u_int32_t	 uvalh, uval;

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
	u_int64_t	 ullval;
	u_int32_t	 uval, uval2, dflag1 = 0, dflag2 = 0;
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
	u_int8_t	 i;

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
		if (strlcpy(p->conf.group, curgroup->conf.group,
		    sizeof(p->conf.group)) >= sizeof(p->conf.group))
			fatalx("new_peer group strlcpy");
		if (strlcpy(p->conf.descr, curgroup->conf.descr,
		    sizeof(p->conf.descr)) >= sizeof(p->conf.descr))
			fatalx("new_peer descr strlcpy");
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
	static u_int32_t id = PEER_ID_STATIC_MIN;
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
	u_int8_t max_len = 0;

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

	aset = as_sets_new(&conf->as_sets, name, 0, sizeof(u_int32_t));
	if (aset == NULL)
		fatal(NULL);

	curset = aset->set;
	return 0;
}

static void
add_as_set(u_int32_t as)
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
add_roa_set(struct prefixset_item *npsi, u_int32_t as, u_int8_t max,
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
