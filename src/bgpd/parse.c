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
    MAXCOMMUNITIES = 336,          /* MAXCOMMUNITIES  */
    MAXEXTCOMMUNITIES = 337,       /* MAXEXTCOMMUNITIES  */
    MAXLARGECOMMUNITIES = 338,     /* MAXLARGECOMMUNITIES  */
    PREFIX = 339,                  /* PREFIX  */
    PREFIXLEN = 340,               /* PREFIXLEN  */
    PREFIXSET = 341,               /* PREFIXSET  */
    ROASET = 342,                  /* ROASET  */
    ORIGINSET = 343,               /* ORIGINSET  */
    OVS = 344,                     /* OVS  */
    EXPIRES = 345,                 /* EXPIRES  */
    ASSET = 346,                   /* ASSET  */
    SOURCEAS = 347,                /* SOURCEAS  */
    TRANSITAS = 348,               /* TRANSITAS  */
    PEERAS = 349,                  /* PEERAS  */
    MAXASLEN = 350,                /* MAXASLEN  */
    MAXASSEQ = 351,                /* MAXASSEQ  */
    SET = 352,                     /* SET  */
    LOCALPREF = 353,               /* LOCALPREF  */
    MED = 354,                     /* MED  */
    METRIC = 355,                  /* METRIC  */
    NEXTHOP = 356,                 /* NEXTHOP  */
    REJECT = 357,                  /* REJECT  */
    BLACKHOLE = 358,               /* BLACKHOLE  */
    NOMODIFY = 359,                /* NOMODIFY  */
    SELF = 360,                    /* SELF  */
    PREPEND_SELF = 361,            /* PREPEND_SELF  */
    PREPEND_PEER = 362,            /* PREPEND_PEER  */
    PFTABLE = 363,                 /* PFTABLE  */
    WEIGHT = 364,                  /* WEIGHT  */
    RTLABEL = 365,                 /* RTLABEL  */
    ORIGIN = 366,                  /* ORIGIN  */
    PRIORITY = 367,                /* PRIORITY  */
    ERROR = 368,                   /* ERROR  */
    INCLUDE = 369,                 /* INCLUDE  */
    IPSEC = 370,                   /* IPSEC  */
    ESP = 371,                     /* ESP  */
    AH = 372,                      /* AH  */
    SPI = 373,                     /* SPI  */
    IKE = 374,                     /* IKE  */
    IPV4 = 375,                    /* IPV4  */
    IPV6 = 376,                    /* IPV6  */
    QUALIFY = 377,                 /* QUALIFY  */
    VIA = 378,                     /* VIA  */
    NE = 379,                      /* NE  */
    LE = 380,                      /* LE  */
    GE = 381,                      /* GE  */
    XRANGE = 382,                  /* XRANGE  */
    LONGER = 383,                  /* LONGER  */
    MAXLEN = 384,                  /* MAXLEN  */
    STRING = 385,                  /* STRING  */
    NUMBER = 386                   /* NUMBER  */
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
#define MAXCOMMUNITIES 336
#define MAXEXTCOMMUNITIES 337
#define MAXLARGECOMMUNITIES 338
#define PREFIX 339
#define PREFIXLEN 340
#define PREFIXSET 341
#define ROASET 342
#define ORIGINSET 343
#define OVS 344
#define EXPIRES 345
#define ASSET 346
#define SOURCEAS 347
#define TRANSITAS 348
#define PEERAS 349
#define MAXASLEN 350
#define MAXASSEQ 351
#define SET 352
#define LOCALPREF 353
#define MED 354
#define METRIC 355
#define NEXTHOP 356
#define REJECT 357
#define BLACKHOLE 358
#define NOMODIFY 359
#define SELF 360
#define PREPEND_SELF 361
#define PREPEND_PEER 362
#define PFTABLE 363
#define WEIGHT 364
#define RTLABEL 365
#define ORIGIN 366
#define PRIORITY 367
#define ERROR 368
#define INCLUDE 369
#define IPSEC 370
#define ESP 371
#define AH 372
#define SPI 373
#define IKE 374
#define IPV4 375
#define IPV6 376
#define QUALIFY 377
#define VIA 378
#define NE 379
#define LE 380
#define GE 381
#define XRANGE 382
#define LONGER 383
#define MAXLEN 384
#define STRING 385
#define NUMBER 386

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
  YYSYMBOL_MAXCOMMUNITIES = 81,            /* MAXCOMMUNITIES  */
  YYSYMBOL_MAXEXTCOMMUNITIES = 82,         /* MAXEXTCOMMUNITIES  */
  YYSYMBOL_MAXLARGECOMMUNITIES = 83,       /* MAXLARGECOMMUNITIES  */
  YYSYMBOL_PREFIX = 84,                    /* PREFIX  */
  YYSYMBOL_PREFIXLEN = 85,                 /* PREFIXLEN  */
  YYSYMBOL_PREFIXSET = 86,                 /* PREFIXSET  */
  YYSYMBOL_ROASET = 87,                    /* ROASET  */
  YYSYMBOL_ORIGINSET = 88,                 /* ORIGINSET  */
  YYSYMBOL_OVS = 89,                       /* OVS  */
  YYSYMBOL_EXPIRES = 90,                   /* EXPIRES  */
  YYSYMBOL_ASSET = 91,                     /* ASSET  */
  YYSYMBOL_SOURCEAS = 92,                  /* SOURCEAS  */
  YYSYMBOL_TRANSITAS = 93,                 /* TRANSITAS  */
  YYSYMBOL_PEERAS = 94,                    /* PEERAS  */
  YYSYMBOL_MAXASLEN = 95,                  /* MAXASLEN  */
  YYSYMBOL_MAXASSEQ = 96,                  /* MAXASSEQ  */
  YYSYMBOL_SET = 97,                       /* SET  */
  YYSYMBOL_LOCALPREF = 98,                 /* LOCALPREF  */
  YYSYMBOL_MED = 99,                       /* MED  */
  YYSYMBOL_METRIC = 100,                   /* METRIC  */
  YYSYMBOL_NEXTHOP = 101,                  /* NEXTHOP  */
  YYSYMBOL_REJECT = 102,                   /* REJECT  */
  YYSYMBOL_BLACKHOLE = 103,                /* BLACKHOLE  */
  YYSYMBOL_NOMODIFY = 104,                 /* NOMODIFY  */
  YYSYMBOL_SELF = 105,                     /* SELF  */
  YYSYMBOL_PREPEND_SELF = 106,             /* PREPEND_SELF  */
  YYSYMBOL_PREPEND_PEER = 107,             /* PREPEND_PEER  */
  YYSYMBOL_PFTABLE = 108,                  /* PFTABLE  */
  YYSYMBOL_WEIGHT = 109,                   /* WEIGHT  */
  YYSYMBOL_RTLABEL = 110,                  /* RTLABEL  */
  YYSYMBOL_ORIGIN = 111,                   /* ORIGIN  */
  YYSYMBOL_PRIORITY = 112,                 /* PRIORITY  */
  YYSYMBOL_ERROR = 113,                    /* ERROR  */
  YYSYMBOL_INCLUDE = 114,                  /* INCLUDE  */
  YYSYMBOL_IPSEC = 115,                    /* IPSEC  */
  YYSYMBOL_ESP = 116,                      /* ESP  */
  YYSYMBOL_AH = 117,                       /* AH  */
  YYSYMBOL_SPI = 118,                      /* SPI  */
  YYSYMBOL_IKE = 119,                      /* IKE  */
  YYSYMBOL_IPV4 = 120,                     /* IPV4  */
  YYSYMBOL_IPV6 = 121,                     /* IPV6  */
  YYSYMBOL_QUALIFY = 122,                  /* QUALIFY  */
  YYSYMBOL_VIA = 123,                      /* VIA  */
  YYSYMBOL_NE = 124,                       /* NE  */
  YYSYMBOL_LE = 125,                       /* LE  */
  YYSYMBOL_GE = 126,                       /* GE  */
  YYSYMBOL_XRANGE = 127,                   /* XRANGE  */
  YYSYMBOL_LONGER = 128,                   /* LONGER  */
  YYSYMBOL_MAXLEN = 129,                   /* MAXLEN  */
  YYSYMBOL_STRING = 130,                   /* STRING  */
  YYSYMBOL_NUMBER = 131,                   /* NUMBER  */
  YYSYMBOL_132_n_ = 132,                   /* '\n'  */
  YYSYMBOL_133_ = 133,                     /* '='  */
  YYSYMBOL_134_ = 134,                     /* '{'  */
  YYSYMBOL_135_ = 135,                     /* '}'  */
  YYSYMBOL_136_ = 136,                     /* '/'  */
  YYSYMBOL_137_ = 137,                     /* '+'  */
  YYSYMBOL_138_ = 138,                     /* '-'  */
  YYSYMBOL_139_ = 139,                     /* ','  */
  YYSYMBOL_140_ = 140,                     /* '<'  */
  YYSYMBOL_141_ = 141,                     /* '>'  */
  YYSYMBOL_YYACCEPT = 142,                 /* $accept  */
  YYSYMBOL_grammar = 143,                  /* grammar  */
  YYSYMBOL_asnumber = 144,                 /* asnumber  */
  YYSYMBOL_as4number = 145,                /* as4number  */
  YYSYMBOL_as4number_any = 146,            /* as4number_any  */
  YYSYMBOL_string = 147,                   /* string  */
  YYSYMBOL_yesno = 148,                    /* yesno  */
  YYSYMBOL_varset = 149,                   /* varset  */
  YYSYMBOL_include = 150,                  /* include  */
  YYSYMBOL_as_set = 151,                   /* as_set  */
  YYSYMBOL_152_1 = 152,                    /* $@1  */
  YYSYMBOL_as_set_l = 153,                 /* as_set_l  */
  YYSYMBOL_prefixset = 154,                /* prefixset  */
  YYSYMBOL_155_2 = 155,                    /* $@2  */
  YYSYMBOL_prefixset_l = 156,              /* prefixset_l  */
  YYSYMBOL_prefixset_item = 157,           /* prefixset_item  */
  YYSYMBOL_roa_set = 158,                  /* roa_set  */
  YYSYMBOL_159_3 = 159,                    /* $@3  */
  YYSYMBOL_origin_set = 160,               /* origin_set  */
  YYSYMBOL_161_4 = 161,                    /* $@4  */
  YYSYMBOL_expires = 162,                  /* expires  */
  YYSYMBOL_roa_set_l = 163,                /* roa_set_l  */
  YYSYMBOL_rtr = 164,                      /* rtr  */
  YYSYMBOL_165_5 = 165,                    /* $@5  */
  YYSYMBOL_rtropt_l = 166,                 /* rtropt_l  */
  YYSYMBOL_rtropt = 167,                   /* rtropt  */
  YYSYMBOL_conf_main = 168,                /* conf_main  */
  YYSYMBOL_rib = 169,                      /* rib  */
  YYSYMBOL_170_6 = 170,                    /* $@6  */
  YYSYMBOL_ribopts = 171,                  /* ribopts  */
  YYSYMBOL_fibupdate = 172,                /* fibupdate  */
  YYSYMBOL_mrtdump = 173,                  /* mrtdump  */
  YYSYMBOL_network = 174,                  /* network  */
  YYSYMBOL_inout = 175,                    /* inout  */
  YYSYMBOL_restricted = 176,               /* restricted  */
  YYSYMBOL_address = 177,                  /* address  */
  YYSYMBOL_prefix = 178,                   /* prefix  */
  YYSYMBOL_addrspec = 179,                 /* addrspec  */
  YYSYMBOL_optnumber = 180,                /* optnumber  */
  YYSYMBOL_l3vpn = 181,                    /* l3vpn  */
  YYSYMBOL_182_7 = 182,                    /* $@7  */
  YYSYMBOL_l3vpnopts_l = 183,              /* l3vpnopts_l  */
  YYSYMBOL_l3vpnopts = 184,                /* l3vpnopts  */
  YYSYMBOL_neighbor = 185,                 /* neighbor  */
  YYSYMBOL_186_8 = 186,                    /* $@8  */
  YYSYMBOL_187_9 = 187,                    /* $@9  */
  YYSYMBOL_group = 188,                    /* group  */
  YYSYMBOL_189_10 = 189,                   /* $@10  */
  YYSYMBOL_groupopts_l = 190,              /* groupopts_l  */
  YYSYMBOL_peeropts_h = 191,               /* peeropts_h  */
  YYSYMBOL_peeropts_l = 192,               /* peeropts_l  */
  YYSYMBOL_peeropts = 193,                 /* peeropts  */
  YYSYMBOL_restart = 194,                  /* restart  */
  YYSYMBOL_family = 195,                   /* family  */
  YYSYMBOL_safi = 196,                     /* safi  */
  YYSYMBOL_nettype = 197,                  /* nettype  */
  YYSYMBOL_espah = 198,                    /* espah  */
  YYSYMBOL_encspec = 199,                  /* encspec  */
  YYSYMBOL_filterrule = 200,               /* filterrule  */
  YYSYMBOL_action = 201,                   /* action  */
  YYSYMBOL_quick = 202,                    /* quick  */
  YYSYMBOL_direction = 203,                /* direction  */
  YYSYMBOL_filter_rib_h = 204,             /* filter_rib_h  */
  YYSYMBOL_filter_rib_l = 205,             /* filter_rib_l  */
  YYSYMBOL_filter_rib = 206,               /* filter_rib  */
  YYSYMBOL_filter_peer_h = 207,            /* filter_peer_h  */
  YYSYMBOL_filter_peer_l = 208,            /* filter_peer_l  */
  YYSYMBOL_filter_peer = 209,              /* filter_peer  */
  YYSYMBOL_filter_prefix_h = 210,          /* filter_prefix_h  */
  YYSYMBOL_filter_prefix_m = 211,          /* filter_prefix_m  */
  YYSYMBOL_filter_prefix_l = 212,          /* filter_prefix_l  */
  YYSYMBOL_filter_prefix = 213,            /* filter_prefix  */
  YYSYMBOL_filter_as_h = 214,              /* filter_as_h  */
  YYSYMBOL_filter_as_t_l = 215,            /* filter_as_t_l  */
  YYSYMBOL_filter_as_t = 216,              /* filter_as_t  */
  YYSYMBOL_filter_as_l_h = 217,            /* filter_as_l_h  */
  YYSYMBOL_filter_as_l = 218,              /* filter_as_l  */
  YYSYMBOL_filter_as = 219,                /* filter_as  */
  YYSYMBOL_filter_match_h = 220,           /* filter_match_h  */
  YYSYMBOL_221_11 = 221,                   /* $@11  */
  YYSYMBOL_filter_match = 222,             /* filter_match  */
  YYSYMBOL_filter_elm = 223,               /* filter_elm  */
  YYSYMBOL_prefixlenop = 224,              /* prefixlenop  */
  YYSYMBOL_filter_as_type = 225,           /* filter_as_type  */
  YYSYMBOL_filter_set = 226,               /* filter_set  */
  YYSYMBOL_filter_set_l = 227,             /* filter_set_l  */
  YYSYMBOL_community = 228,                /* community  */
  YYSYMBOL_delete = 229,                   /* delete  */
  YYSYMBOL_filter_set_opt = 230,           /* filter_set_opt  */
  YYSYMBOL_origincode = 231,               /* origincode  */
  YYSYMBOL_validity = 232,                 /* validity  */
  YYSYMBOL_optnl = 233,                    /* optnl  */
  YYSYMBOL_comma = 234,                    /* comma  */
  YYSYMBOL_unaryop = 235,                  /* unaryop  */
  YYSYMBOL_equalityop = 236,               /* equalityop  */
  YYSYMBOL_binaryop = 237                  /* binaryop  */
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
#define YYLAST   731

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  142
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  321
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  599

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   386


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
     132,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   137,   139,   138,     2,   136,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     140,   133,   141,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   134,     2,   135,     2,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   258,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   276,   287,
     319,   329,   356,   361,   367,   370,   385,   413,   428,   428,
     442,   450,   451,   453,   453,   463,   473,   487,   503,   520,
     520,   527,   530,   530,   543,   555,   558,   566,   576,   588,
     597,   597,   609,   610,   612,   623,   631,   641,   648,   652,
     659,   667,   675,   689,   709,   717,   728,   734,   740,   749,
     750,   778,   810,   811,   821,   831,   844,   857,   870,   886,
     893,   909,   909,   919,   920,   929,   938,   939,   947,   977,
     998,  1027,  1046,  1070,  1090,  1091,  1094,  1095,  1098,  1119,
    1137,  1157,  1164,  1167,  1168,  1171,  1171,  1216,  1217,  1218,
    1219,  1222,  1240,  1258,  1276,  1282,  1285,  1286,  1285,  1320,
    1320,  1352,  1353,  1354,  1355,  1356,  1359,  1360,  1361,  1364,
    1365,  1366,  1367,  1370,  1373,  1380,  1384,  1395,  1408,  1418,
    1425,  1428,  1431,  1442,  1458,  1466,  1474,  1493,  1496,  1499,
    1502,  1505,  1508,  1518,  1521,  1524,  1530,  1536,  1551,  1559,
    1567,  1585,  1601,  1611,  1704,  1707,  1714,  1726,  1727,  1737,
    1753,  1765,  1789,  1795,  1806,  1812,  1820,  1835,  1836,  1846,
    1847,  1850,  1851,  1852,  1855,  1856,  1859,  1860,  1863,  1866,
    1899,  1926,  1927,  1928,  1931,  1932,  1935,  1936,  1939,  1940,
    1941,  1943,  1944,  1950,  1972,  1973,  1976,  1977,  1983,  1990,
    2010,  2017,  2038,  2044,  2052,  2067,  2082,  2083,  2086,  2087,
    2088,  2100,  2101,  2107,  2122,  2123,  2126,  2127,  2139,  2143,
    2150,  2173,  2174,  2175,  2188,  2189,  2195,  2203,  2209,  2217,
    2231,  2234,  2234,  2242,  2243,  2246,  2259,  2266,  2278,  2290,
    2308,  2330,  2349,  2365,  2377,  2389,  2397,  2404,  2453,  2473,
    2483,  2484,  2490,  2501,  2544,  2560,  2561,  2562,  2563,  2566,
    2567,  2574,  2577,  2582,  2591,  2592,  2595,  2596,  2599,  2614,
    2624,  2634,  2649,  2659,  2669,  2684,  2694,  2704,  2719,  2729,
    2739,  2746,  2751,  2756,  2761,  2766,  2776,  2786,  2791,  2818,
    2832,  2860,  2878,  2894,  2902,  2917,  2932,  2933,  2936,  2937,
    2938,  2939,  2942,  2943,  2944,  2945,  2946,  2947,  2950,  2951,
    2954,  2955
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
  "EXTCOMMUNITY", "LARGECOMMUNITY", "DELETE", "MAXCOMMUNITIES",
  "MAXEXTCOMMUNITIES", "MAXLARGECOMMUNITIES", "PREFIX", "PREFIXLEN",
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,    10,    61,   123,   125,    47,    43,    45,    44,
      60,    62
};
#endif

#define YYPACT_NINF (-423)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-309)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -423,   291,  -423,   -63,   -51,   -42,    19,    86,   -28,   -26,
      -6,    -8,    25,   -42,     4,   -13,    20,     8,    10,    32,
     -28,  -423,  -423,  -423,    34,    35,    61,    67,    77,   110,
      73,    80,  -423,    88,    91,   103,   111,   118,   123,   128,
     134,   138,  -423,  -423,   140,   144,   190,   147,   150,   160,
    -423,  -423,  -423,  -423,   166,  -423,  -423,   168,  -423,   -42,
    -423,  -423,  -423,  -423,   285,   174,   177,   298,   162,   181,
    -423,   196,   202,  -423,  -423,   206,   215,   249,    17,  -423,
     224,    29,   310,  -423,  -423,   228,   239,   238,   240,   250,
     -28,  -423,     4,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,    78,  -423,  -423,  -423,   354,  -423,
    -423,   355,   253,  -423,  -423,   254,  -423,  -423,   246,  -423,
     251,   249,   257,   258,   568,  -423,  -423,  -423,   260,   263,
     249,   261,  -423,  -423,   264,   266,  -423,  -423,   239,   239,
     262,   239,   239,   268,  -423,   196,   206,  -423,  -423,  -423,
      -2,   172,   269,  -423,    31,  -423,   239,  -423,  -423,  -423,
    -423,  -423,  -423,   319,  -423,    69,    99,   101,    74,   270,
     273,   276,   121,   277,   278,   239,   319,  -423,   249,   249,
    -423,   279,  -423,  -423,   264,   283,  -423,  -423,   210,   287,
     289,  -423,   280,  -423,   239,  -423,  -423,  -423,    24,  -423,
     286,   -28,   281,   389,  -423,  -423,    56,   414,  -423,   -21,
    -423,   294,   295,  -423,   296,   297,  -423,   301,   305,  -423,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,  -423,   306,   307,
    -423,  -423,  -423,   620,   299,  -423,  -423,   264,  -423,  -423,
     210,   321,   130,   -32,  -423,   210,  -423,   214,   556,  -423,
     311,   -51,   313,  -423,  -423,  -423,   239,  -423,   -16,  -423,
    -423,  -423,   408,  -423,   314,   323,   -42,   239,  -423,   312,
      26,    66,   433,   326,   327,   -51,   -51,     4,   -42,   330,
    -423,   331,   282,   335,    33,   -28,   -42,   449,   341,   342,
     343,   -28,   410,   -28,   583,   387,   232,  -423,  -423,   444,
    -423,   348,   350,   353,   356,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,   130,  -423,  -423,  -423,   130,  -423,   214,
     239,   352,   357,   210,   116,  -423,   358,  -423,   130,  -423,
    -423,  -423,   130,  -423,   360,    50,  -423,  -423,  -423,    30,
     249,   133,    21,  -423,  -423,  -423,  -423,     9,  -423,   359,
    -423,  -423,  -423,   361,  -423,  -423,   166,  -423,   196,  -423,
    -423,    37,   -28,   -28,   -28,   -28,   443,   439,   154,  -423,
     -28,   -28,  -423,  -423,   363,  -423,   308,  -423,  -423,   302,
    -423,   239,  -423,   -28,  -423,  -423,    -9,  -423,  -423,  -423,
    -423,  -423,   362,   620,   364,   210,   398,   365,   239,  -423,
     404,  -423,  -423,  -423,   -64,  -423,  -423,  -423,   367,  -423,
     366,   368,   214,   501,  -423,   369,   311,   130,  -423,  -423,
    -423,   -19,   374,   376,   377,   178,   379,   380,   382,  -423,
    -423,  -423,   383,   384,     0,   -32,   -32,    49,  -423,  -423,
    -423,   133,  -423,    15,   388,   381,   -28,   390,   393,   394,
    -423,  -423,  -423,   396,  -423,  -423,  -423,  -423,  -423,   395,
     480,  -423,  -423,  -423,  -423,  -423,   -28,   -28,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,     4,     4,   620,  -423,  -423,
     407,  -423,  -423,  -423,  -423,   399,  -423,  -423,   214,  -423,
    -423,   400,  -423,  -423,  -423,  -423,   411,  -423,  -423,   413,
    -423,  -423,   397,    30,   417,   418,  -423,  -423,  -423,   183,
     -32,  -423,   -32,  -423,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,   142,  -423,  -423,  -423,   422,  -423,  -423,    62,
     -64,  -423,   214,  -423,  -423,  -423,  -423,   428,   429,  -423,
    -423,  -423,  -423,  -423,   196,   196,   130,   409,  -423,   398,
    -423,  -423,  -423,  -423,  -423,  -423,  -423,   210,   425,   171,
    -423,  -423,  -423,   239,  -423,    49,  -423,   -10,   431,   198,
    -423,   214,  -423,  -423,  -423,   432,   440,  -423,   199,  -423,
     210,  -423,  -423,   204,  -423,   -10,  -423,  -423,   441,   183,
    -423,    62,  -423,   445,  -423,  -423,   448,  -423,  -423
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
      24,   119,     0,   179,   180,     0,     0,   269,     0,    79,
       0,     0,    97,    68,    66,     0,   306,     0,     0,     0,
       0,    27,     0,     4,     5,     6,     7,     8,     9,    10,
      12,    11,    13,    14,     0,    15,    16,   195,   198,    58,
      61,    62,     0,    81,    76,     0,    73,    74,     0,    23,
       0,   269,     0,     0,     0,    89,   185,   184,     0,     0,
     269,     0,    94,    95,   103,     0,    96,    80,   306,   306,
      39,   306,   306,     0,    67,    26,    98,   101,   102,   117,
       0,     0,     0,   105,    86,    75,   306,   121,    90,    99,
     100,   297,   274,   276,   275,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,   276,   270,   269,   269,
      93,     0,   104,    70,   103,    33,   307,    41,     0,    42,
      28,    77,   128,   203,   306,   199,   196,   197,     0,    63,
       0,     0,     0,     0,    82,    83,     0,     0,   277,     0,
     278,     0,     0,   281,     0,     0,   284,     0,     0,   292,
     291,   293,   294,   290,   295,   296,   298,   287,     0,     0,
     299,   304,   303,     0,     0,    91,    92,   103,    88,    35,
       0,     0,   308,   260,    44,     0,    30,     0,     0,   118,
       0,     0,     0,   212,   213,   208,   306,   209,   241,   204,
     107,    87,    86,    85,     0,     0,     0,   306,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,   168,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   120,     0,
     167,     0,     0,     0,     0,   279,   280,   282,   283,   285,
     286,   288,   289,   308,   273,   300,    71,   308,    36,     0,
     306,   309,     0,     0,     0,   261,     0,    38,   308,    21,
      22,    31,   308,   129,     0,   306,   201,   210,   211,     0,
     269,     0,     0,    84,    56,    54,    55,     0,   125,     0,
     144,   153,   154,     0,   143,   175,   134,   133,   136,   137,
     139,   177,     0,     0,     0,     0,     0,     0,     0,   171,
       0,     0,   157,   169,     0,   142,     0,   173,   172,     0,
     164,   306,   165,     0,   186,   187,     0,   138,   124,   123,
     302,   301,     0,     0,     0,     0,    45,   310,   306,    40,
       0,   313,   314,   316,     0,   312,   315,   317,     0,   262,
       0,     0,     0,     0,   127,     0,     0,   308,   206,   190,
     265,     0,     0,     0,     0,     0,     0,     0,     0,   266,
     267,   268,     0,     0,     0,   260,   260,     0,   245,   246,
     224,   242,   243,     0,     0,     0,     0,     0,     0,     0,
     108,   106,   115,     0,    51,    53,   145,   176,   135,     0,
     177,   158,   150,   147,   148,   151,     0,     0,   181,   182,
     183,   146,   156,   155,   170,     0,     0,     0,   174,   162,
       0,   271,   272,    34,    37,     0,    47,   311,     0,   321,
     320,     0,   263,    43,    29,    32,     0,   130,   126,     0,
     200,   202,     0,     0,     0,     0,   252,   253,   254,     0,
     260,   216,   260,   258,   305,   259,   247,   248,   256,   255,
     214,   215,   308,   226,   244,   237,     0,   319,   318,     0,
     236,   228,     0,   249,   110,   114,   111,     0,     0,   109,
     178,   159,   149,   152,   160,   161,   308,     0,    46,    45,
     264,   132,   131,   205,   207,   251,   250,     0,     0,   308,
     221,   223,   257,   306,   225,     0,   230,     0,     0,   308,
     234,     0,   238,   112,   113,     0,     0,    48,   308,   217,
       0,   310,   227,   308,   229,     0,   239,   166,     0,   219,
     222,   232,   235,   188,   220,   233,     0,   163,   189
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -423,  -423,    13,  -176,  -242,   -89,    -7,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,  -423,  -220,  -423,  -423,  -423,  -423,
      36,   324,  -423,  -423,  -423,   226,  -423,  -423,  -423,  -423,
     317,   579,   241,   195,  -423,    -3,   -15,  -423,  -122,  -423,
    -423,  -423,  -423,   392,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -232,   124,   304,  -423,  -423,  -423,  -423,  -423,  -423,
    -423,  -423,  -423,  -423,  -244,  -423,  -423,  -332,  -423,     6,
      40,  -407,  -423,  -423,  -413,    -4,    46,  -422,  -423,  -423,
    -423,   159,  -377,  -423,  -107,   125,  -310,   438,  -120,  -423,
    -423,  -130,  -298,  -423,  -423,    71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,   330,    54,   530,    71,   299,    33,    34,    35,
     247,   332,    36,   240,   317,   241,    37,   188,    38,   245,
     486,   242,    39,   118,   267,   268,    40,    41,   154,   204,
     205,   300,    43,   135,   137,   257,   243,   149,   183,    44,
     200,   342,   453,    45,    46,   192,    47,   120,   207,   249,
     413,   302,   461,    78,   471,   130,   386,   597,    48,    49,
     108,   198,   151,   335,   195,   258,   417,   259,   438,   558,
     559,   560,   439,   522,   440,   568,   569,   570,   340,   341,
     441,   442,   327,   443,   125,   313,   176,   209,   314,   232,
     515,   140,   323,   408,   532,   491
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    61,    56,   145,   177,   331,   336,   418,   185,   186,
      69,   189,   190,    84,   158,   393,   334,    53,   511,   395,
     318,   531,   445,   180,   523,    57,   206,   251,   518,    80,
     446,   444,   349,   251,   412,   264,   447,   416,   448,   449,
     201,   525,   202,   265,   266,   233,    65,    66,   132,   133,
      15,   252,   420,   324,   253,   254,   111,   252,   520,   521,
     253,   254,   238,   489,   250,   370,   525,   109,   303,    50,
     504,   235,   236,    72,   490,   337,   459,   396,   351,    51,
      52,  -240,   264,   144,   371,   352,   132,   133,    55,   148,
     265,   266,   126,   127,    59,   460,   325,   326,   255,   356,
     357,   147,    60,   400,   255,    62,   526,    73,    74,   304,
     479,   505,   322,   525,   527,   316,  -240,    75,    76,   503,
     329,    52,    64,   528,    67,    63,   339,   128,   193,   129,
      55,   444,   194,   561,    70,   562,   420,   347,    81,   527,
      82,   429,   430,   431,   454,   329,    52,   203,   528,   529,
      58,    79,   582,   450,    55,    68,   451,   350,   256,   134,
      55,    60,    83,   592,    85,   223,   468,   469,   470,    86,
     495,   554,   501,   590,   382,   484,   219,   220,   221,   222,
    -308,   499,   320,   392,   116,   117,   527,   394,   358,   321,
     397,    87,   329,    52,   261,   528,   567,    88,   410,    89,
     210,    90,   411,    91,    55,   415,   211,   212,   146,    76,
     162,   421,   164,    92,   422,   423,   424,   425,   104,   426,
      93,   427,   428,    94,   565,   429,   430,   431,   432,   433,
     213,   107,   216,   419,   434,    95,   214,   215,   217,   218,
     401,   402,   403,    96,   196,   197,   549,   404,   393,   405,
      97,   477,   227,   435,   436,    98,   406,   407,   228,   229,
      99,   580,   320,   346,    53,  -306,   100,   437,   487,   321,
     101,   585,   102,   482,   563,   359,   103,   564,   372,   105,
     580,   321,   106,   373,   378,   585,   380,   502,    53,    53,
     572,     2,     3,   112,     4,     5,     6,    52,     7,   110,
       8,     9,    10,   563,   113,    11,  -218,   114,    75,    76,
     321,    12,   509,    75,    76,   -50,    13,   557,    14,  -116,
      15,   362,   115,   363,   364,   365,   119,   366,   367,   586,
     563,   563,   121,  -231,   589,    16,   563,   321,   321,   591,
      75,    76,   122,   321,   329,    52,   124,    17,   384,   385,
      18,   123,    19,    20,   131,   462,   463,   464,   465,    21,
      22,    23,   138,   472,   473,   132,   133,   475,   476,   458,
     136,   139,   141,   143,   142,   150,   478,    24,    25,    26,
     156,   152,    27,   153,   155,   157,   544,   545,   159,   160,
     178,   181,    28,    29,   179,   182,   184,   187,   191,   208,
     199,   224,    73,    74,   225,    30,   226,   230,   231,   237,
     510,   263,   262,   319,   248,   269,   575,   201,   239,   270,
     260,    31,   244,    32,   246,   305,   306,   307,   308,   315,
     271,   519,   309,   581,   272,   273,   310,   311,   312,   535,
     274,   193,  -116,   338,   348,   344,   275,   276,   277,   278,
     279,   280,   281,   345,   282,   353,   354,   374,   355,   542,
     543,   360,   361,   283,   284,   369,   285,   286,   287,   288,
     289,   375,   376,   377,   379,   290,   291,   292,   383,   387,
     388,   293,   389,   390,   398,   466,   391,   467,   485,   409,
     456,   457,   399,   474,   510,   414,   488,   481,   492,   483,
    -307,   493,   496,   494,   500,   506,   270,   507,   508,   512,
     513,   294,   514,   534,   516,   517,   295,   271,   533,   459,
     536,   272,   273,   537,   538,   547,   540,   274,   539,   296,
     548,   550,   553,   275,   276,   277,   278,   279,   280,   281,
     576,   282,   510,   551,    60,   552,   297,   555,   556,   298,
     283,   284,   566,   285,   286,   287,   288,   289,   573,   574,
     579,   270,   290,   291,   292,   510,   584,   587,   293,   328,
     588,   593,   271,   455,   510,   596,   272,   273,   598,   343,
      42,   480,   274,   452,   541,   577,   368,   595,   275,   276,
     277,   278,   279,   280,   281,   594,   282,   578,   294,   301,
     524,   571,   546,   295,     0,   283,   284,     0,   285,   286,
     287,   288,   289,   583,   234,     0,   296,   290,   291,   292,
     161,     0,     0,   293,     0,     0,     0,     0,     0,     0,
       0,    60,     0,   497,     0,   161,   498,     0,     0,     0,
       0,     0,     0,     0,     0,   162,   163,   164,     0,     0,
       0,     0,     0,   294,     0,     0,     0,     0,   295,     0,
     162,   163,   164,     0,     0,     0,   165,   166,   167,   168,
       0,   296,   161,     0,   169,   170,   171,   172,   173,   174,
       0,   165,   166,   167,   168,     0,    60,     0,   333,   169,
     170,   171,   172,   173,   174,     0,     0,   162,   163,   164,
       0,     0,   175,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   381,   165,   166,
     167,   168,     0,     0,     0,     0,   169,   170,   171,   172,
     173,   174
};

static const yytype_int16 yycheck[] =
{
      15,     8,     5,    92,   124,   247,   250,   339,   138,   139,
      13,   141,   142,    20,   121,   313,   248,     4,   425,   317,
     240,   443,     1,   130,   437,     6,   156,     3,    28,    21,
       9,   341,     6,     3,   332,    26,    15,   335,    17,    18,
       9,    51,    11,    34,    35,   175,    21,    22,    57,    58,
      29,    27,     3,    85,    30,    31,    59,    27,   435,   436,
      30,    31,   184,   127,   194,    32,    51,    54,    89,   132,
      89,   178,   179,    86,   138,   251,    39,   319,    12,   130,
     131,    97,    26,    90,    51,    19,    57,    58,   130,   104,
      34,    35,    75,    76,     8,    58,   128,   129,    74,   275,
     276,   104,   130,   323,    74,   131,    91,   120,   121,   130,
     119,   130,   242,    51,   124,   237,   132,   130,   131,   417,
     130,   131,   130,   133,    99,   131,   256,   110,   130,   112,
     130,   441,   134,   510,   130,   512,     3,   267,   130,   124,
     130,    92,    93,    94,   135,   130,   131,   154,   133,   134,
     131,   131,   565,   132,   130,   130,   135,   131,   134,   130,
     130,   130,   130,   585,   130,   168,    12,    13,    14,   134,
     412,   503,   416,   580,   294,   395,   102,   103,   104,   105,
     130,   413,   132,   313,    22,    23,   124,   317,   277,   139,
     320,   130,   130,   131,   201,   133,   134,   130,   328,   122,
     131,    91,   332,   130,   130,   335,   137,   138,   130,   131,
      77,    78,    79,   133,    81,    82,    83,    84,    28,    86,
     132,    88,    89,   132,   522,    92,    93,    94,    95,    96,
     131,    71,   131,   340,   101,   132,   137,   138,   137,   138,
     124,   125,   126,   132,    72,    73,   488,   131,   546,   133,
     132,   381,   131,   120,   121,   132,   140,   141,   137,   138,
     132,   559,   132,   266,   251,   135,   132,   134,   398,   139,
     132,   569,   132,   393,   132,   278,   132,   135,   285,   132,
     578,   139,   132,   286,   291,   583,   293,   417,   275,   276,
     532,     0,     1,     8,     3,     4,     5,   131,     7,   131,
       9,    10,    11,   132,   130,    14,   135,   130,   130,   131,
     139,    20,   134,   130,   131,   134,    25,   134,    27,    28,
      29,    39,    24,    41,    42,    43,   130,    45,    46,   571,
     132,   132,   130,   135,   135,    44,   132,   139,   139,   135,
     130,   131,   136,   139,   130,   131,    97,    56,   116,   117,
      59,   136,    61,    62,   130,   362,   363,   364,   365,    68,
      69,    70,   134,   370,   371,    57,    58,    65,    66,   356,
      60,   132,   134,   123,   134,    21,   383,    86,    87,    88,
     134,    26,    91,   130,   130,   134,   475,   476,   131,   131,
     130,   130,   101,   102,   131,   131,   130,   135,   130,    80,
     131,   131,   120,   121,   131,   114,   130,   130,   130,   130,
     425,    22,   131,    92,   134,     1,   546,     9,   135,     5,
     134,   130,   135,   132,   135,   131,   131,   131,   131,   130,
      16,   434,   131,   563,    20,    21,   131,   131,   131,   446,
      26,   130,    28,   130,   132,   131,    32,    33,    34,    35,
      36,    37,    38,   130,    40,    22,   130,     8,   131,   466,
     467,   131,   131,    49,    50,   130,    52,    53,    54,    55,
      56,   130,   130,   130,    64,    61,    62,    63,    91,    35,
     132,    67,   132,   130,   132,    42,   130,    48,    90,   131,
     131,   130,   135,   130,   509,   135,    92,   135,   131,   135,
     135,   135,     1,   135,   135,   131,     5,   131,   131,   130,
     130,    97,   130,   132,   131,   131,   102,    16,   130,    39,
     130,    20,    21,   130,   130,   118,   131,    26,   132,   115,
     131,   131,   135,    32,    33,    34,    35,    36,    37,    38,
     131,    40,   557,   132,   130,   132,   132,   130,   130,   135,
      49,    50,   130,    52,    53,    54,    55,    56,   130,   130,
     135,     5,    61,    62,    63,   580,   135,   135,    67,   245,
     130,   130,    16,   347,   589,   130,    20,    21,   130,   262,
       1,   386,    26,   342,   460,   549,   282,   591,    32,    33,
      34,    35,    36,    37,    38,   589,    40,   557,    97,   207,
     441,   530,   477,   102,    -1,    49,    50,    -1,    52,    53,
      54,    55,    56,   567,   176,    -1,   115,    61,    62,    63,
      52,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,   132,    -1,    52,   135,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,   102,    -1,
      77,    78,    79,    -1,    -1,    -1,    98,    99,   100,   101,
      -1,   115,    52,    -1,   106,   107,   108,   109,   110,   111,
      -1,    98,    99,   100,   101,    -1,   130,    -1,   132,   106,
     107,   108,   109,   110,   111,    -1,    -1,    77,    78,    79,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    98,    99,
     100,   101,    -1,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   143,     0,     1,     3,     4,     5,     7,     9,    10,
      11,    14,    20,    25,    27,    29,    44,    56,    59,    61,
      62,    68,    69,    70,    86,    87,    88,    91,   101,   102,
     114,   130,   132,   149,   150,   151,   154,   158,   160,   164,
     168,   169,   173,   174,   181,   185,   186,   188,   200,   201,
     132,   130,   131,   144,   145,   130,   177,     6,   131,     8,
     130,   148,   131,   131,   130,    21,    22,    99,   130,   177,
     130,   147,    86,   120,   121,   130,   131,   178,   195,   131,
      21,   130,   130,   130,   148,   130,   134,   130,   130,   122,
      91,   130,   133,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,    28,   132,   132,    71,   202,   144,
     131,   177,     8,   130,   130,    24,    22,    23,   165,   130,
     189,   130,   136,   136,    97,   226,    75,    76,   110,   112,
     197,   130,    57,    58,   130,   175,    60,   176,   134,   132,
     233,   134,   134,   123,   148,   147,   130,   177,   178,   179,
      21,   204,    26,   130,   170,   130,   134,   134,   226,   131,
     131,    52,    77,    78,    79,    98,    99,   100,   101,   106,
     107,   108,   109,   110,   111,   134,   228,   230,   130,   131,
     226,   130,   131,   180,   130,   233,   233,   135,   159,   233,
     233,   130,   187,   130,   134,   206,    72,    73,   203,   131,
     182,     9,    11,   148,   171,   172,   233,   190,    80,   229,
     131,   137,   138,   131,   137,   138,   131,   137,   138,   102,
     103,   104,   105,   177,   131,   131,   130,   131,   137,   138,
     130,   130,   231,   233,   229,   226,   226,   130,   180,   135,
     155,   157,   163,   178,   135,   161,   135,   152,   134,   191,
     233,     3,    27,    30,    31,    74,   134,   177,   207,   209,
     134,   148,   131,    22,    26,    34,    35,   166,   167,     1,
       5,    16,    20,    21,    26,    32,    33,    34,    35,    36,
      37,    38,    40,    49,    50,    52,    53,    54,    55,    56,
      61,    62,    63,    67,    97,   102,   115,   132,   135,   148,
     173,   185,   193,    89,   130,   131,   131,   131,   131,   131,
     131,   131,   131,   227,   230,   130,   180,   156,   157,    92,
     132,   139,   233,   234,    85,   128,   129,   224,   163,   130,
     144,   146,   153,   132,   193,   205,   206,   145,   130,   233,
     220,   221,   183,   172,   131,   130,   177,   233,   132,     6,
     131,    12,    19,    22,   130,   131,   145,   145,   147,   177,
     131,   131,    39,    41,    42,    43,    45,    46,   195,   130,
      32,    51,   148,   177,     8,   130,   130,   130,   148,    64,
     148,   134,   230,    91,   116,   117,   198,    35,   132,   132,
     130,   130,   233,   234,   233,   234,   146,   233,   132,   135,
     157,   124,   125,   126,   131,   133,   140,   141,   235,   131,
     233,   233,   234,   192,   135,   233,   234,   208,   209,   226,
       3,    78,    81,    82,    83,    84,    86,    88,    89,    92,
      93,    94,    95,    96,   101,   120,   121,   134,   210,   214,
     216,   222,   223,   225,   228,     1,     9,    15,    17,    18,
     132,   135,   174,   184,   135,   167,   131,   130,   144,    39,
      58,   194,   148,   148,   148,   148,    42,    48,    12,    13,
      14,   196,   148,   148,   130,    65,    66,   233,   148,   119,
     175,   135,   230,   135,   157,    90,   162,   233,    92,   127,
     138,   237,   131,   135,   135,   146,     1,   132,   135,   193,
     135,   206,   233,   234,    89,   130,   131,   131,   131,   134,
     178,   213,   130,   130,   130,   232,   131,   131,    28,   177,
     224,   224,   215,   216,   223,    51,    91,   124,   133,   134,
     146,   219,   236,   130,   132,   148,   130,   130,   130,   132,
     131,   194,   148,   148,   147,   147,   227,   118,   131,   146,
     131,   132,   132,   135,   209,   130,   130,   134,   211,   212,
     213,   224,   224,   132,   135,   234,   130,   134,   217,   218,
     219,   237,   146,   130,   130,   233,   131,   162,   212,   135,
     234,   233,   216,   218,   135,   234,   146,   135,   130,   135,
     213,   135,   219,   130,   211,   217,   130,   199,   130
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   142,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   144,   145,
     145,   146,   146,   147,   147,   148,   149,   150,   152,   151,
     151,   153,   153,   155,   154,   154,   156,   156,   157,   159,
     158,   158,   161,   160,   160,   162,   162,   163,   163,   164,
     165,   164,   166,   166,   167,   167,   167,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   170,   169,   171,   171,   171,   172,   172,   173,   174,
     174,   174,   174,   174,   175,   175,   176,   176,   177,   178,
     178,   179,   179,   180,   180,   182,   181,   183,   183,   183,
     183,   184,   184,   184,   184,   184,   186,   187,   185,   189,
     188,   190,   190,   190,   190,   190,   191,   191,   191,   192,
     192,   192,   192,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   194,   194,   195,
     195,   196,   196,   196,   197,   197,   198,   198,   199,   199,
     200,   201,   201,   201,   202,   202,   203,   203,   204,   204,
     204,   205,   205,   206,   207,   207,   208,   208,   209,   209,
     209,   209,   209,   209,   210,   210,   210,   210,   211,   211,
     211,   212,   212,   213,   214,   214,   215,   215,   216,   216,
     216,   217,   217,   217,   218,   218,   219,   219,   219,   219,
     220,   221,   220,   222,   222,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     224,   224,   224,   224,   224,   225,   225,   225,   225,   226,
     226,   226,   227,   227,   228,   228,   229,   229,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   231,   232,   233,   233,   234,   234,
     234,   234,   235,   235,   235,   235,   235,   235,   236,   236,
     237,   237
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
       3,     3,     2,     2,     2,     2,     2,     3,     2,     2,
       0,     1,     2,     3,     4,     1,     1,     1,     1,     0,
       2,     6,     3,     1,     1,     1,     0,     1,     2,     3,
       3,     2,     3,     3,     2,     3,     3,     2,     3,     3,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       3,     4,     4,     2,     1,     1,     0,     2,     0,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 273 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { file->errors++; }
#line 2262 "parse.c"
    break;

  case 18: /* asnumber: NUMBER  */
#line 276 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2277 "parse.c"
    break;

  case 19: /* as4number: STRING  */
#line 287 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2314 "parse.c"
    break;

  case 20: /* as4number: asnumber  */
#line 319 "../../../openbgpd-portable/src/bgpd/parse.y"
                           {
			if ((yyvsp[0].v.number) == AS_TRANS || (yyvsp[0].v.number) == 0) {
				yyerror("AS %u is reserved and may not be used",
				    (uint32_t)(yyvsp[0].v.number));
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2327 "parse.c"
    break;

  case 21: /* as4number_any: STRING  */
#line 329 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2359 "parse.c"
    break;

  case 22: /* as4number_any: asnumber  */
#line 356 "../../../openbgpd-portable/src/bgpd/parse.y"
                           {
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2367 "parse.c"
    break;

  case 23: /* string: string STRING  */
#line 361 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (asprintf(&(yyval.v.string), "%s %s", (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1)
				fatal("string: asprintf");
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.string));
		}
#line 2378 "parse.c"
    break;

  case 25: /* yesno: STRING  */
#line 370 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2396 "parse.c"
    break;

  case 26: /* varset: STRING '=' string  */
#line 385 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2427 "parse.c"
    break;

  case 27: /* include: INCLUDE STRING  */
#line 413 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2445 "parse.c"
    break;

  case 28: /* $@1: %empty  */
#line 428 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2462 "parse.c"
    break;

  case 29: /* as_set: ASSET STRING '{' optnl $@1 as_set_l optnl '}'  */
#line 439 "../../../openbgpd-portable/src/bgpd/parse.y"
                                     {
			done_as_set();
		}
#line 2470 "parse.c"
    break;

  case 30: /* as_set: ASSET STRING '{' optnl '}'  */
#line 442 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (new_as_set((yyvsp[-3].v.string)) != 0) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
		}
#line 2482 "parse.c"
    break;

  case 31: /* as_set_l: as4number_any  */
#line 450 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { add_as_set((yyvsp[0].v.number)); }
#line 2488 "parse.c"
    break;

  case 32: /* as_set_l: as_set_l comma as4number_any  */
#line 451 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { add_as_set((yyvsp[0].v.number)); }
#line 2494 "parse.c"
    break;

  case 33: /* $@2: %empty  */
#line 453 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curpset = new_prefix_set((yyvsp[-2].v.string), 0)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			free((yyvsp[-2].v.string));
		}
#line 2506 "parse.c"
    break;

  case 34: /* prefixset: PREFIXSET STRING '{' optnl $@2 prefixset_l optnl '}'  */
#line 459 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2515 "parse.c"
    break;

  case 35: /* prefixset: PREFIXSET STRING '{' optnl '}'  */
#line 463 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curpset = new_prefix_set((yyvsp[-3].v.string), 0)) == NULL) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2529 "parse.c"
    break;

  case 36: /* prefixset_l: prefixset_item  */
#line 473 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2548 "parse.c"
    break;

  case 37: /* prefixset_l: prefixset_l comma prefixset_item  */
#line 487 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2567 "parse.c"
    break;

  case 38: /* prefixset_item: prefix prefixlenop  */
#line 503 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2587 "parse.c"
    break;

  case 39: /* $@3: %empty  */
#line 520 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			curroatree = &conf->roa;
			noexpires = 0;
		}
#line 2596 "parse.c"
    break;

  case 40: /* roa_set: ROASET '{' optnl $@3 roa_set_l optnl '}'  */
#line 523 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			curroatree = NULL;
			noexpires = 1;
		}
#line 2605 "parse.c"
    break;

  case 42: /* $@4: %empty  */
#line 530 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curoset = new_prefix_set((yyvsp[-2].v.string), 1)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			curroatree = &curoset->roaitems;
			noexpires = 1;
			free((yyvsp[-2].v.string));
		}
#line 2619 "parse.c"
    break;

  case 43: /* origin_set: ORIGINSET STRING '{' optnl $@4 roa_set_l optnl '}'  */
#line 538 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			SIMPLEQ_INSERT_TAIL(&conf->originsets, curoset, entry);
			curoset = NULL;
			curroatree = NULL;
		}
#line 2629 "parse.c"
    break;

  case 44: /* origin_set: ORIGINSET STRING '{' optnl '}'  */
#line 543 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2644 "parse.c"
    break;

  case 45: /* expires: %empty  */
#line 555 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			(yyval.v.number) = 0;
		}
#line 2652 "parse.c"
    break;

  case 46: /* expires: EXPIRES NUMBER  */
#line 558 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (noexpires) {
				yyerror("syntax error, expires not allowed");
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2664 "parse.c"
    break;

  case 47: /* roa_set_l: prefixset_item SOURCEAS as4number_any expires  */
#line 566 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2679 "parse.c"
    break;

  case 48: /* roa_set_l: roa_set_l comma prefixset_item SOURCEAS as4number_any expires  */
#line 576 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2694 "parse.c"
    break;

  case 49: /* rtr: RTR address  */
#line 588 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = RTR_PORT;
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2708 "parse.c"
    break;

  case 50: /* $@5: %empty  */
#line 597 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = RTR_PORT;
		}
#line 2717 "parse.c"
    break;

  case 51: /* rtr: RTR address $@5 '{' optnl rtropt_l optnl '}'  */
#line 600 "../../../openbgpd-portable/src/bgpd/parse.y"
                                               {
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2729 "parse.c"
    break;

  case 54: /* rtropt: DESCR STRING  */
#line 612 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2745 "parse.c"
    break;

  case 55: /* rtropt: LOCALADDR address  */
#line 623 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.addr).aid != currtr->remote_addr.aid) {
				yyerror("Bad address family %s for "
				    "local-addr", aid2str((yyvsp[0].v.addr).aid));
				YYERROR;
			}
			currtr->local_addr = (yyvsp[0].v.addr);
		}
#line 2758 "parse.c"
    break;

  case 56: /* rtropt: PORT NUMBER  */
#line 631 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("port must be between %u and %u",
				    1, USHRT_MAX);
				YYERROR;
			}
			currtr->remote_port = (yyvsp[0].v.number);
		}
#line 2771 "parse.c"
    break;

  case 57: /* conf_main: AS as4number  */
#line 641 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			conf->as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				conf->short_as = AS_TRANS;
			else
				conf->short_as = (yyvsp[0].v.number);
		}
#line 2783 "parse.c"
    break;

  case 58: /* conf_main: AS as4number asnumber  */
#line 648 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			conf->as = (yyvsp[-1].v.number);
			conf->short_as = (yyvsp[0].v.number);
		}
#line 2792 "parse.c"
    break;

  case 59: /* conf_main: ROUTERID address  */
#line 652 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.addr).aid != AID_INET) {
				yyerror("router-id must be an IPv4 address");
				YYERROR;
			}
			conf->bgpid = (yyvsp[0].v.addr).v4.s_addr;
		}
#line 2804 "parse.c"
    break;

  case 60: /* conf_main: HOLDTIME NUMBER  */
#line 659 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->holdtime = (yyvsp[0].v.number);
		}
#line 2817 "parse.c"
    break;

  case 61: /* conf_main: HOLDTIME YMIN NUMBER  */
#line 667 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->min_holdtime = (yyvsp[0].v.number);
		}
#line 2830 "parse.c"
    break;

  case 62: /* conf_main: LISTEN ON address  */
#line 675 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2849 "parse.c"
    break;

  case 63: /* conf_main: LISTEN ON address PORT NUMBER  */
#line 689 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2874 "parse.c"
    break;

  case 64: /* conf_main: FIBPRIORITY NUMBER  */
#line 709 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) <= RTP_LOCAL || (yyvsp[0].v.number) > RTP_MAX) {
				yyerror("fib-priority %lld must be between "
				    "%u and %u", (yyvsp[0].v.number), RTP_LOCAL + 1, RTP_MAX);
				YYERROR;
			}
			conf->fib_priority = (yyvsp[0].v.number);
		}
#line 2887 "parse.c"
    break;

  case 65: /* conf_main: FIBUPDATE yesno  */
#line 717 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2903 "parse.c"
    break;

  case 66: /* conf_main: TRANSPARENT yesno  */
#line 728 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_DECISION_TRANS_AS;
			else
				conf->flags &= ~BGPD_FLAG_DECISION_TRANS_AS;
		}
#line 2914 "parse.c"
    break;

  case 67: /* conf_main: REJECT ASSET yesno  */
#line 734 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_NO_AS_SET;
			else
				conf->flags &= ~BGPD_FLAG_NO_AS_SET;
		}
#line 2925 "parse.c"
    break;

  case 68: /* conf_main: LOG STRING  */
#line 740 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (!strcmp((yyvsp[0].v.string), "updates"))
				conf->log |= BGPD_LOG_UPDATES;
			else {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 2939 "parse.c"
    break;

  case 70: /* conf_main: DUMP STRING STRING optnumber  */
#line 750 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2972 "parse.c"
    break;

  case 71: /* conf_main: DUMP RIB STRING STRING STRING optnumber  */
#line 778 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3009 "parse.c"
    break;

  case 73: /* conf_main: RDE STRING EVALUATE  */
#line 811 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3024 "parse.c"
    break;

  case 74: /* conf_main: RDE STRING IGNORE  */
#line 821 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3039 "parse.c"
    break;

  case 75: /* conf_main: RDE MED COMPARE STRING  */
#line 831 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3057 "parse.c"
    break;

  case 76: /* conf_main: RDE EVALUATE STRING  */
#line 844 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3075 "parse.c"
    break;

  case 77: /* conf_main: NEXTHOP QUALIFY VIA STRING  */
#line 857 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3093 "parse.c"
    break;

  case 78: /* conf_main: RTABLE NUMBER  */
#line 870 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			struct rde_rib *rr;
			if ((yyvsp[0].v.number) > RT_TABLEID_MAX) {
				yyerror("rtable %llu too big: max %u", (yyvsp[0].v.number),
				    RT_TABLEID_MAX);
				YYERROR;
			}
			if (!ktable_exists((yyvsp[0].v.number), NULL)) {
				yyerror("rtable id %lld does not exist", (yyvsp[0].v.number));
				YYERROR;
			}
			rr = find_rib("Loc-RIB");
			if (rr == NULL)
				fatalx("RTABLE can not find the main RIB!");
			rr->rtableid = (yyvsp[0].v.number);
		}
#line 3114 "parse.c"
    break;

  case 79: /* conf_main: CONNECTRETRY NUMBER  */
#line 886 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			if ((yyvsp[0].v.number) > USHRT_MAX || (yyvsp[0].v.number) < 1) {
				yyerror("invalid connect-retry");
				YYERROR;
			}
			conf->connectretry = (yyvsp[0].v.number);
		}
#line 3126 "parse.c"
    break;

  case 80: /* conf_main: SOCKET STRING restricted  */
#line 893 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3145 "parse.c"
    break;

  case 81: /* $@6: %empty  */
#line 909 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if ((currib = add_rib((yyvsp[0].v.string))) == NULL) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 3157 "parse.c"
    break;

  case 82: /* rib: RDE RIB STRING $@6 ribopts  */
#line 915 "../../../openbgpd-portable/src/bgpd/parse.y"
                          {
			currib = NULL;
		}
#line 3165 "parse.c"
    break;

  case 84: /* ribopts: RTABLE NUMBER fibupdate  */
#line 920 "../../../openbgpd-portable/src/bgpd/parse.y"
                                          {
			if ((yyvsp[-1].v.number) > RT_TABLEID_MAX) {
				yyerror("rtable %llu too big: max %u", (yyvsp[-1].v.number),
				    RT_TABLEID_MAX);
				YYERROR;
			}
			if (rib_add_fib(currib, (yyvsp[-1].v.number)) == -1)
				YYERROR;
		}
#line 3179 "parse.c"
    break;

  case 85: /* ribopts: yesno EVALUATE  */
#line 929 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if ((yyvsp[-1].v.number)) {
				yyerror("bad rde rib definition");
				YYERROR;
			}
			currib->flags |= F_RIB_NOEVALUATE;
		}
#line 3191 "parse.c"
    break;

  case 87: /* fibupdate: FIBUPDATE yesno  */
#line 939 "../../../openbgpd-portable/src/bgpd/parse.y"
                                  {
			if ((yyvsp[0].v.number) == 0)
				currib->flags |= F_RIB_NOFIBSYNC;
			else
				currib->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3202 "parse.c"
    break;

  case 88: /* mrtdump: DUMP STRING inout STRING optnumber  */
#line 947 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3235 "parse.c"
    break;

  case 89: /* network: NETWORK prefix filter_set  */
#line 977 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3261 "parse.c"
    break;

  case 90: /* network: NETWORK PREFIXSET STRING filter_set  */
#line 998 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3295 "parse.c"
    break;

  case 91: /* network: NETWORK family RTLABEL STRING filter_set  */
#line 1027 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3319 "parse.c"
    break;

  case 92: /* network: NETWORK family PRIORITY NUMBER filter_set  */
#line 1046 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			struct network	*n;
			if ((yyvsp[-1].v.number) <= RTP_LOCAL && (yyvsp[-1].v.number) > RTP_MAX) {
				yyerror("priority %lld must be between "
				    "%u and %u", (yyvsp[-1].v.number), RTP_LOCAL + 1, RTP_MAX);
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
#line 3348 "parse.c"
    break;

  case 93: /* network: NETWORK family nettype filter_set  */
#line 1070 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3371 "parse.c"
    break;

  case 94: /* inout: IN  */
#line 1090 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 3377 "parse.c"
    break;

  case 95: /* inout: OUT  */
#line 1091 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 3383 "parse.c"
    break;

  case 96: /* restricted: RESTRICTED  */
#line 1094 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 3389 "parse.c"
    break;

  case 97: /* restricted: %empty  */
#line 1095 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 3395 "parse.c"
    break;

  case 98: /* address: STRING  */
#line 1098 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3419 "parse.c"
    break;

  case 99: /* prefix: STRING '/' NUMBER  */
#line 1119 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3442 "parse.c"
    break;

  case 100: /* prefix: NUMBER '/' NUMBER  */
#line 1137 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3465 "parse.c"
    break;

  case 101: /* addrspec: address  */
#line 1157 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			memcpy(&(yyval.v.prefix).prefix, &(yyvsp[0].v.addr), sizeof(struct bgpd_addr));
			if ((yyval.v.prefix).prefix.aid == AID_INET)
				(yyval.v.prefix).len = 32;
			else
				(yyval.v.prefix).len = 128;
		}
#line 3477 "parse.c"
    break;

  case 103: /* optnumber: %empty  */
#line 1167 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0; }
#line 3483 "parse.c"
    break;

  case 105: /* $@7: %empty  */
#line 1171 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3526 "parse.c"
    break;

  case 106: /* l3vpn: VPN STRING ON STRING $@7 '{' l3vpnopts_l '}'  */
#line 1208 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			/* insert into list */
			SIMPLEQ_INSERT_TAIL(&conf->l3vpns, curvpn, entry);
			curvpn = NULL;
			netconf = &conf->networks;
		}
#line 3537 "parse.c"
    break;

  case 111: /* l3vpnopts: RD STRING  */
#line 1222 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3560 "parse.c"
    break;

  case 112: /* l3vpnopts: EXPORTTRGT STRING STRING  */
#line 1240 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3583 "parse.c"
    break;

  case 113: /* l3vpnopts: IMPORTTRGT STRING STRING  */
#line 1258 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3606 "parse.c"
    break;

  case 114: /* l3vpnopts: FIBUPDATE yesno  */
#line 1276 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) == 0)
				curvpn->flags |= F_RIB_NOFIBSYNC;
			else
				curvpn->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3617 "parse.c"
    break;

  case 116: /* $@8: %empty  */
#line 1285 "../../../openbgpd-portable/src/bgpd/parse.y"
                  {	curpeer = new_peer(); }
#line 3623 "parse.c"
    break;

  case 117: /* $@9: %empty  */
#line 1286 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3642 "parse.c"
    break;

  case 118: /* neighbor: $@8 NEIGHBOR addrspec $@9 peeropts_h  */
#line 1300 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3665 "parse.c"
    break;

  case 119: /* $@10: %empty  */
#line 1320 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3688 "parse.c"
    break;

  case 120: /* group: GROUP string $@10 '{' groupopts_l '}'  */
#line 1337 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3706 "parse.c"
    break;

  case 133: /* peeropts: REMOTEAS as4number  */
#line 1370 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.remote_as = (yyvsp[0].v.number);
		}
#line 3714 "parse.c"
    break;

  case 134: /* peeropts: LOCALAS as4number  */
#line 1373 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.local_as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				curpeer->conf.local_short_as = AS_TRANS;
			else
				curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3726 "parse.c"
    break;

  case 135: /* peeropts: LOCALAS as4number asnumber  */
#line 1380 "../../../openbgpd-portable/src/bgpd/parse.y"
                                             {
			curpeer->conf.local_as = (yyvsp[-1].v.number);
			curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3735 "parse.c"
    break;

  case 136: /* peeropts: DESCR string  */
#line 1384 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3751 "parse.c"
    break;

  case 137: /* peeropts: LOCALADDR address  */
#line 1395 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3769 "parse.c"
    break;

  case 138: /* peeropts: yesno LOCALADDR  */
#line 1408 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3784 "parse.c"
    break;

  case 139: /* peeropts: MULTIHOP NUMBER  */
#line 1418 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 2 || (yyvsp[0].v.number) > 255) {
				yyerror("invalid multihop distance %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			curpeer->conf.distance = (yyvsp[0].v.number);
		}
#line 3796 "parse.c"
    break;

  case 140: /* peeropts: PASSIVE  */
#line 1425 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.passive = 1;
		}
#line 3804 "parse.c"
    break;

  case 141: /* peeropts: DOWN  */
#line 1428 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.down = 1;
		}
#line 3812 "parse.c"
    break;

  case 142: /* peeropts: DOWN STRING  */
#line 1431 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3828 "parse.c"
    break;

  case 143: /* peeropts: RIB STRING  */
#line 1442 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3849 "parse.c"
    break;

  case 144: /* peeropts: HOLDTIME NUMBER  */
#line 1458 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.holdtime = (yyvsp[0].v.number);
		}
#line 3862 "parse.c"
    break;

  case 145: /* peeropts: HOLDTIME YMIN NUMBER  */
#line 1466 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.min_holdtime = (yyvsp[0].v.number);
		}
#line 3875 "parse.c"
    break;

  case 146: /* peeropts: ANNOUNCE family safi  */
#line 1474 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3899 "parse.c"
    break;

  case 147: /* peeropts: ANNOUNCE CAPABILITIES yesno  */
#line 1493 "../../../openbgpd-portable/src/bgpd/parse.y"
                                              {
			curpeer->conf.announce_capa = (yyvsp[0].v.number);
		}
#line 3907 "parse.c"
    break;

  case 148: /* peeropts: ANNOUNCE REFRESH yesno  */
#line 1496 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.refresh = (yyvsp[0].v.number);
		}
#line 3915 "parse.c"
    break;

  case 149: /* peeropts: ANNOUNCE ENHANCED REFRESH yesno  */
#line 1499 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                  {
			curpeer->conf.capabilities.enhanced_rr = (yyvsp[0].v.number);
		}
#line 3923 "parse.c"
    break;

  case 150: /* peeropts: ANNOUNCE RESTART yesno  */
#line 1502 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.grestart.restart = (yyvsp[0].v.number);
		}
#line 3931 "parse.c"
    break;

  case 151: /* peeropts: ANNOUNCE AS4BYTE yesno  */
#line 1505 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.as4byte = (yyvsp[0].v.number);
		}
#line 3939 "parse.c"
    break;

  case 152: /* peeropts: ANNOUNCE ADDPATH RECV yesno  */
#line 1508 "../../../openbgpd-portable/src/bgpd/parse.y"
                                              {
			int8_t *ap = curpeer->conf.capabilities.add_path;
			uint8_t i;

			for (i = 0; i < AID_MAX; i++)
				if ((yyvsp[0].v.number))
					*ap++ |= CAPA_AP_RECV;
				else
					*ap++ &= ~CAPA_AP_RECV;
		}
#line 3954 "parse.c"
    break;

  case 153: /* peeropts: EXPORT NONE  */
#line 1518 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			curpeer->conf.export_type = EXPORT_NONE;
		}
#line 3962 "parse.c"
    break;

  case 154: /* peeropts: EXPORT DEFAULTROUTE  */
#line 1521 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			curpeer->conf.export_type = EXPORT_DEFAULT_ROUTE;
		}
#line 3970 "parse.c"
    break;

  case 155: /* peeropts: ENFORCE NEIGHBORAS yesno  */
#line 1524 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_as = ENFORCE_AS_OFF;
		}
#line 3981 "parse.c"
    break;

  case 156: /* peeropts: ENFORCE LOCALAS yesno  */
#line 1530 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_local_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_local_as = ENFORCE_AS_OFF;
		}
#line 3992 "parse.c"
    break;

  case 157: /* peeropts: ASOVERRIDE yesno  */
#line 1536 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4012 "parse.c"
    break;

  case 158: /* peeropts: MAXPREFIX NUMBER restart  */
#line 1551 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if ((yyvsp[-1].v.number) < 0 || (yyvsp[-1].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_prefix = (yyvsp[-1].v.number);
			curpeer->conf.max_prefix_restart = (yyvsp[0].v.number);
		}
#line 4025 "parse.c"
    break;

  case 159: /* peeropts: MAXPREFIX NUMBER OUT restart  */
#line 1559 "../../../openbgpd-portable/src/bgpd/parse.y"
                                               {
			if ((yyvsp[-2].v.number) < 0 || (yyvsp[-2].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_out_prefix = (yyvsp[-2].v.number);
			curpeer->conf.max_out_prefix_restart = (yyvsp[0].v.number);
		}
#line 4038 "parse.c"
    break;

  case 160: /* peeropts: TCP MD5SIG PASSWORD string  */
#line 1567 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4061 "parse.c"
    break;

  case 161: /* peeropts: TCP MD5SIG KEY string  */
#line 1585 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4082 "parse.c"
    break;

  case 162: /* peeropts: IPSEC espah IKE  */
#line 1601 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4097 "parse.c"
    break;

  case 163: /* peeropts: IPSEC espah inout SPI NUMBER STRING STRING encspec  */
#line 1611 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4195 "parse.c"
    break;

  case 164: /* peeropts: TTLSECURITY yesno  */
#line 1704 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.ttlsec = (yyvsp[0].v.number);
		}
#line 4203 "parse.c"
    break;

  case 165: /* peeropts: SET filter_set_opt  */
#line 1707 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			struct filter_rule	*r;

			r = get_rule((yyvsp[0].v.filter_set)->type);
			if (merge_filterset(&r->set, (yyvsp[0].v.filter_set)) == -1)
				YYERROR;
		}
#line 4215 "parse.c"
    break;

  case 166: /* peeropts: SET '{' optnl filter_set_l optnl '}'  */
#line 1714 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4232 "parse.c"
    break;

  case 168: /* peeropts: REFLECTOR  */
#line 1727 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4247 "parse.c"
    break;

  case 169: /* peeropts: REFLECTOR address  */
#line 1737 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4268 "parse.c"
    break;

  case 170: /* peeropts: DEPEND ON STRING  */
#line 1753 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4285 "parse.c"
    break;

  case 171: /* peeropts: DEMOTE STRING  */
#line 1765 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4314 "parse.c"
    break;

  case 172: /* peeropts: TRANSPARENT yesno  */
#line 1789 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_TRANS_AS;
			else
				curpeer->conf.flags &= ~PEERFLAG_TRANS_AS;
		}
#line 4325 "parse.c"
    break;

  case 173: /* peeropts: LOG STRING  */
#line 1795 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4341 "parse.c"
    break;

  case 174: /* peeropts: REJECT ASSET yesno  */
#line 1806 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_NO_AS_SET;
			else
				curpeer->conf.flags &= ~PEERFLAG_NO_AS_SET;
		}
#line 4352 "parse.c"
    break;

  case 175: /* peeropts: PORT NUMBER  */
#line 1812 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("port must be between %u and %u",
				    1, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.remote_port = (yyvsp[0].v.number);
		}
#line 4365 "parse.c"
    break;

  case 176: /* peeropts: RDE EVALUATE STRING  */
#line 1820 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4383 "parse.c"
    break;

  case 177: /* restart: %empty  */
#line 1835 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0; }
#line 4389 "parse.c"
    break;

  case 178: /* restart: RESTART NUMBER  */
#line 1836 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("restart out of range. 1 to %u minutes",
				    USHRT_MAX);
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 4402 "parse.c"
    break;

  case 179: /* family: IPV4  */
#line 1846 "../../../openbgpd-portable/src/bgpd/parse.y"
                        { (yyval.v.number) = AFI_IPv4; }
#line 4408 "parse.c"
    break;

  case 180: /* family: IPV6  */
#line 1847 "../../../openbgpd-portable/src/bgpd/parse.y"
                        { (yyval.v.number) = AFI_IPv6; }
#line 4414 "parse.c"
    break;

  case 181: /* safi: NONE  */
#line 1850 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_NONE; }
#line 4420 "parse.c"
    break;

  case 182: /* safi: UNICAST  */
#line 1851 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_UNICAST; }
#line 4426 "parse.c"
    break;

  case 183: /* safi: VPN  */
#line 1852 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_MPLSVPN; }
#line 4432 "parse.c"
    break;

  case 184: /* nettype: STATIC  */
#line 1855 "../../../openbgpd-portable/src/bgpd/parse.y"
                         { (yyval.v.number) = 1; }
#line 4438 "parse.c"
    break;

  case 185: /* nettype: CONNECTED  */
#line 1856 "../../../openbgpd-portable/src/bgpd/parse.y"
                            { (yyval.v.number) = 0; }
#line 4444 "parse.c"
    break;

  case 186: /* espah: ESP  */
#line 1859 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 4450 "parse.c"
    break;

  case 187: /* espah: AH  */
#line 1860 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 4456 "parse.c"
    break;

  case 188: /* encspec: %empty  */
#line 1863 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			bzero(&(yyval.v.encspec), sizeof((yyval.v.encspec)));
		}
#line 4464 "parse.c"
    break;

  case 189: /* encspec: STRING STRING  */
#line 1866 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4500 "parse.c"
    break;

  case 190: /* filterrule: action quick filter_rib_h direction filter_peer_h filter_match_h filter_set  */
#line 1901 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4528 "parse.c"
    break;

  case 191: /* action: ALLOW  */
#line 1926 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_ALLOW; }
#line 4534 "parse.c"
    break;

  case 192: /* action: DENY  */
#line 1927 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_DENY; }
#line 4540 "parse.c"
    break;

  case 193: /* action: MATCH  */
#line 1928 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_NONE; }
#line 4546 "parse.c"
    break;

  case 194: /* quick: %empty  */
#line 1931 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 0; }
#line 4552 "parse.c"
    break;

  case 195: /* quick: QUICK  */
#line 1932 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 1; }
#line 4558 "parse.c"
    break;

  case 196: /* direction: FROM  */
#line 1935 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = DIR_IN; }
#line 4564 "parse.c"
    break;

  case 197: /* direction: TO  */
#line 1936 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = DIR_OUT; }
#line 4570 "parse.c"
    break;

  case 198: /* filter_rib_h: %empty  */
#line 1939 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = NULL; }
#line 4576 "parse.c"
    break;

  case 199: /* filter_rib_h: RIB filter_rib  */
#line 1940 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4582 "parse.c"
    break;

  case 200: /* filter_rib_h: RIB '{' optnl filter_rib_l optnl '}'  */
#line 1941 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_rib) = (yyvsp[-2].v.filter_rib); }
#line 4588 "parse.c"
    break;

  case 201: /* filter_rib_l: filter_rib  */
#line 1943 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4594 "parse.c"
    break;

  case 202: /* filter_rib_l: filter_rib_l comma filter_rib  */
#line 1944 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			(yyvsp[0].v.filter_rib)->next = (yyvsp[-2].v.filter_rib);
			(yyval.v.filter_rib) = (yyvsp[0].v.filter_rib);
		}
#line 4603 "parse.c"
    break;

  case 203: /* filter_rib: STRING  */
#line 1950 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4628 "parse.c"
    break;

  case 205: /* filter_peer_h: '{' optnl filter_peer_l optnl '}'  */
#line 1973 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_peers) = (yyvsp[-2].v.filter_peers); }
#line 4634 "parse.c"
    break;

  case 206: /* filter_peer_l: filter_peer  */
#line 1976 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_peers) = (yyvsp[0].v.filter_peers); }
#line 4640 "parse.c"
    break;

  case 207: /* filter_peer_l: filter_peer_l comma filter_peer  */
#line 1977 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyvsp[0].v.filter_peers)->next = (yyvsp[-2].v.filter_peers);
			(yyval.v.filter_peers) = (yyvsp[0].v.filter_peers);
		}
#line 4649 "parse.c"
    break;

  case 208: /* filter_peer: ANY  */
#line 1983 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.peerid = (yyval.v.filter_peers)->p.groupid = 0;
			(yyval.v.filter_peers)->next = NULL;
		}
#line 4661 "parse.c"
    break;

  case 209: /* filter_peer: address  */
#line 1990 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4686 "parse.c"
    break;

  case 210: /* filter_peer: AS as4number  */
#line 2010 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.groupid = (yyval.v.filter_peers)->p.peerid = 0;
			(yyval.v.filter_peers)->p.remote_as = (yyvsp[0].v.number);
		}
#line 4698 "parse.c"
    break;

  case 211: /* filter_peer: GROUP STRING  */
#line 2017 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4724 "parse.c"
    break;

  case 212: /* filter_peer: EBGP  */
#line 2038 "../../../openbgpd-portable/src/bgpd/parse.y"
                       {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ebgp = 1;
		}
#line 4735 "parse.c"
    break;

  case 213: /* filter_peer: IBGP  */
#line 2044 "../../../openbgpd-portable/src/bgpd/parse.y"
                       {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ibgp = 1;
		}
#line 4746 "parse.c"
    break;

  case 214: /* filter_prefix_h: IPV4 prefixlenop  */
#line 2052 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4766 "parse.c"
    break;

  case 215: /* filter_prefix_h: IPV6 prefixlenop  */
#line 2067 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4786 "parse.c"
    break;

  case 216: /* filter_prefix_h: PREFIX filter_prefix  */
#line 2082 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4792 "parse.c"
    break;

  case 217: /* filter_prefix_h: PREFIX '{' filter_prefix_m '}'  */
#line 2083 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4798 "parse.c"
    break;

  case 219: /* filter_prefix_m: '{' filter_prefix_l '}'  */
#line 2087 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4804 "parse.c"
    break;

  case 220: /* filter_prefix_m: '{' filter_prefix_l '}' filter_prefix_m  */
#line 2089 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_prefix_l  *p;

			/* merge, both can be lists */
			for (p = (yyvsp[-2].v.filter_prefix); p != NULL && p->next != NULL; p = p->next)
				;       /* nothing */
			if (p != NULL)
				p->next = (yyvsp[0].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[-2].v.filter_prefix);
		}
#line 4819 "parse.c"
    break;

  case 221: /* filter_prefix_l: filter_prefix  */
#line 2100 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4825 "parse.c"
    break;

  case 222: /* filter_prefix_l: filter_prefix_l comma filter_prefix  */
#line 2101 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyvsp[0].v.filter_prefix)->next = (yyvsp[-2].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix);
		}
#line 4834 "parse.c"
    break;

  case 223: /* filter_prefix: prefix prefixlenop  */
#line 2107 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4852 "parse.c"
    break;

  case 225: /* filter_as_h: '{' filter_as_t_l '}'  */
#line 2123 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4858 "parse.c"
    break;

  case 227: /* filter_as_t_l: filter_as_t_l comma filter_as_t  */
#line 2127 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4873 "parse.c"
    break;

  case 228: /* filter_as_t: filter_as_type filter_as  */
#line 2139 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as)->a.type = (yyvsp[-1].v.u8);
		}
#line 4882 "parse.c"
    break;

  case 229: /* filter_as_t: filter_as_type '{' filter_as_l_h '}'  */
#line 2143 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			struct filter_as_l	*a;

			(yyval.v.filter_as) = (yyvsp[-1].v.filter_as);
			for (a = (yyval.v.filter_as); a != NULL; a = a->next)
				a->a.type = (yyvsp[-3].v.u8);
		}
#line 4894 "parse.c"
    break;

  case 230: /* filter_as_t: filter_as_type ASSET STRING  */
#line 2150 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4920 "parse.c"
    break;

  case 232: /* filter_as_l_h: '{' filter_as_l '}'  */
#line 2174 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4926 "parse.c"
    break;

  case 233: /* filter_as_l_h: '{' filter_as_l '}' filter_as_l_h  */
#line 2176 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4941 "parse.c"
    break;

  case 235: /* filter_as_l: filter_as_l comma filter_as  */
#line 2189 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			(yyvsp[0].v.filter_as)->next = (yyvsp[-2].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
		}
#line 4950 "parse.c"
    break;

  case 236: /* filter_as: as4number_any  */
#line 2195 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.op = OP_EQ;
		}
#line 4963 "parse.c"
    break;

  case 237: /* filter_as: NEIGHBORAS  */
#line 2203 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.flags = AS_FLAG_NEIGHBORAS;
		}
#line 4974 "parse.c"
    break;

  case 238: /* filter_as: equalityop as4number_any  */
#line 2209 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.op = (yyvsp[-1].v.u8);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
		}
#line 4987 "parse.c"
    break;

  case 239: /* filter_as: as4number_any binaryop as4number_any  */
#line 2217 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5004 "parse.c"
    break;

  case 240: /* filter_match_h: %empty  */
#line 2231 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			bzero(&(yyval.v.filter_match), sizeof((yyval.v.filter_match)));
		}
#line 5012 "parse.c"
    break;

  case 241: /* $@11: %empty  */
#line 2234 "../../../openbgpd-portable/src/bgpd/parse.y"
                  {
			bzero(&fmopts, sizeof(fmopts));
		}
#line 5020 "parse.c"
    break;

  case 242: /* filter_match_h: $@11 filter_match  */
#line 2237 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			memcpy(&(yyval.v.filter_match), &fmopts, sizeof((yyval.v.filter_match)));
		}
#line 5028 "parse.c"
    break;

  case 245: /* filter_elm: filter_prefix_h  */
#line 2246 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5046 "parse.c"
    break;

  case 246: /* filter_elm: filter_as_h  */
#line 2259 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.as_l != NULL) {
				yyerror("AS filters already specified");
				YYERROR;
			}
			fmopts.as_l = (yyvsp[0].v.filter_as);
		}
#line 5058 "parse.c"
    break;

  case 247: /* filter_elm: MAXASLEN NUMBER  */
#line 2266 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5075 "parse.c"
    break;

  case 248: /* filter_elm: MAXASSEQ NUMBER  */
#line 2278 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5092 "parse.c"
    break;

  case 249: /* filter_elm: community STRING  */
#line 2290 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5115 "parse.c"
    break;

  case 250: /* filter_elm: EXTCOMMUNITY STRING STRING  */
#line 2308 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5142 "parse.c"
    break;

  case 251: /* filter_elm: EXTCOMMUNITY OVS STRING  */
#line 2330 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5166 "parse.c"
    break;

  case 252: /* filter_elm: MAXCOMMUNITIES NUMBER  */
#line 2349 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT16_MAX) {
				yyerror("bad max-comunities %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (fmopts.m.maxcomm != 0) {
				yyerror("%s already specified",
				    "max-communities");
				YYERROR;
			}
			/*
			 * Offset by 1 since 0 means not used.
			 * The match function then uses >= to compensate.
			 */
			fmopts.m.maxcomm = (yyvsp[0].v.number) + 1;
		}
#line 5187 "parse.c"
    break;

  case 253: /* filter_elm: MAXEXTCOMMUNITIES NUMBER  */
#line 2365 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT16_MAX) {
				yyerror("bad max-ext-communities %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (fmopts.m.maxextcomm != 0) {
				yyerror("%s already specified",
				    "max-ext-communities");
				YYERROR;
			}
			fmopts.m.maxextcomm = (yyvsp[0].v.number) + 1;
		}
#line 5204 "parse.c"
    break;

  case 254: /* filter_elm: MAXLARGECOMMUNITIES NUMBER  */
#line 2377 "../../../openbgpd-portable/src/bgpd/parse.y"
                                             {
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > INT16_MAX) {
				yyerror("bad max-large-communities %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			if (fmopts.m.maxlargecomm != 0) {
				yyerror("%s already specified",
				    "max-large-communities");
				YYERROR;
			}
			fmopts.m.maxlargecomm = (yyvsp[0].v.number) + 1;
		}
#line 5221 "parse.c"
    break;

  case 255: /* filter_elm: NEXTHOP address  */
#line 2389 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.addr = (yyvsp[0].v.addr);
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_ADDR;
		}
#line 5234 "parse.c"
    break;

  case 256: /* filter_elm: NEXTHOP NEIGHBOR  */
#line 2397 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_NEIGHBOR;
		}
#line 5246 "parse.c"
    break;

  case 257: /* filter_elm: PREFIXSET STRING prefixlenop  */
#line 2404 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5300 "parse.c"
    break;

  case 258: /* filter_elm: ORIGINSET STRING  */
#line 2453 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5325 "parse.c"
    break;

  case 259: /* filter_elm: OVS validity  */
#line 2473 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.ovs.is_set) {
				yyerror("ovs filter already specified");
				YYERROR;
			}
			fmopts.m.ovs.validity = (yyvsp[0].v.number);
			fmopts.m.ovs.is_set = 1;
		}
#line 5338 "parse.c"
    break;

  case 260: /* prefixlenop: %empty  */
#line 2483 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen))); }
#line 5344 "parse.c"
    break;

  case 261: /* prefixlenop: LONGER  */
#line 2484 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen)));
			(yyval.v.prefixlen).op = OP_RANGE;
			(yyval.v.prefixlen).len_min = -1;
			(yyval.v.prefixlen).len_max = -1;
		}
#line 5355 "parse.c"
    break;

  case 262: /* prefixlenop: MAXLEN NUMBER  */
#line 2490 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5371 "parse.c"
    break;

  case 263: /* prefixlenop: PREFIXLEN unaryop NUMBER  */
#line 2501 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5419 "parse.c"
    break;

  case 264: /* prefixlenop: PREFIXLEN NUMBER binaryop NUMBER  */
#line 2544 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5438 "parse.c"
    break;

  case 265: /* filter_as_type: AS  */
#line 2560 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_ALL; }
#line 5444 "parse.c"
    break;

  case 266: /* filter_as_type: SOURCEAS  */
#line 2561 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_SOURCE; }
#line 5450 "parse.c"
    break;

  case 267: /* filter_as_type: TRANSITAS  */
#line 2562 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_TRANSIT; }
#line 5456 "parse.c"
    break;

  case 268: /* filter_as_type: PEERAS  */
#line 2563 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_PEER; }
#line 5462 "parse.c"
    break;

  case 269: /* filter_set: %empty  */
#line 2566 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                { (yyval.v.filter_set_head) = NULL; }
#line 5468 "parse.c"
    break;

  case 270: /* filter_set: SET filter_set_opt  */
#line 2567 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5480 "parse.c"
    break;

  case 271: /* filter_set: SET '{' optnl filter_set_l optnl '}'  */
#line 2574 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head); }
#line 5486 "parse.c"
    break;

  case 272: /* filter_set_l: filter_set_l comma filter_set_opt  */
#line 2577 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head);
			if (merge_filterset((yyval.v.filter_set_head), (yyvsp[0].v.filter_set)) == 1)
				YYERROR;
		}
#line 5496 "parse.c"
    break;

  case 273: /* filter_set_l: filter_set_opt  */
#line 2582 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5508 "parse.c"
    break;

  case 274: /* community: COMMUNITY  */
#line 2591 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.u8) = COMMUNITY_TYPE_BASIC; }
#line 5514 "parse.c"
    break;

  case 275: /* community: LARGECOMMUNITY  */
#line 2592 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.u8) = COMMUNITY_TYPE_LARGE; }
#line 5520 "parse.c"
    break;

  case 276: /* delete: %empty  */
#line 2595 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 0; }
#line 5526 "parse.c"
    break;

  case 277: /* delete: DELETE  */
#line 2596 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 1; }
#line 5532 "parse.c"
    break;

  case 278: /* filter_set_opt: LOCALPREF NUMBER  */
#line 2599 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5552 "parse.c"
    break;

  case 279: /* filter_set_opt: LOCALPREF '+' NUMBER  */
#line 2614 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5567 "parse.c"
    break;

  case 280: /* filter_set_opt: LOCALPREF '-' NUMBER  */
#line 2624 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5582 "parse.c"
    break;

  case 281: /* filter_set_opt: MED NUMBER  */
#line 2634 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5602 "parse.c"
    break;

  case 282: /* filter_set_opt: MED '+' NUMBER  */
#line 2649 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5617 "parse.c"
    break;

  case 283: /* filter_set_opt: MED '-' NUMBER  */
#line 2659 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5632 "parse.c"
    break;

  case 284: /* filter_set_opt: METRIC NUMBER  */
#line 2669 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5652 "parse.c"
    break;

  case 285: /* filter_set_opt: METRIC '+' NUMBER  */
#line 2684 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5667 "parse.c"
    break;

  case 286: /* filter_set_opt: METRIC '-' NUMBER  */
#line 2694 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5682 "parse.c"
    break;

  case 287: /* filter_set_opt: WEIGHT NUMBER  */
#line 2704 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5702 "parse.c"
    break;

  case 288: /* filter_set_opt: WEIGHT '+' NUMBER  */
#line 2719 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5717 "parse.c"
    break;

  case 289: /* filter_set_opt: WEIGHT '-' NUMBER  */
#line 2729 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5732 "parse.c"
    break;

  case 290: /* filter_set_opt: NEXTHOP address  */
#line 2739 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP;
			memcpy(&(yyval.v.filter_set)->action.nexthop, &(yyvsp[0].v.addr),
			    sizeof((yyval.v.filter_set)->action.nexthop));
		}
#line 5744 "parse.c"
    break;

  case 291: /* filter_set_opt: NEXTHOP BLACKHOLE  */
#line 2746 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_BLACKHOLE;
		}
#line 5754 "parse.c"
    break;

  case 292: /* filter_set_opt: NEXTHOP REJECT  */
#line 2751 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_REJECT;
		}
#line 5764 "parse.c"
    break;

  case 293: /* filter_set_opt: NEXTHOP NOMODIFY  */
#line 2756 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_NOMODIFY;
		}
#line 5774 "parse.c"
    break;

  case 294: /* filter_set_opt: NEXTHOP SELF  */
#line 2761 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_SELF;
		}
#line 5784 "parse.c"
    break;

  case 295: /* filter_set_opt: PREPEND_SELF NUMBER  */
#line 2766 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5799 "parse.c"
    break;

  case 296: /* filter_set_opt: PREPEND_PEER NUMBER  */
#line 2776 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5814 "parse.c"
    break;

  case 297: /* filter_set_opt: ASOVERRIDE  */
#line 2786 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_AS_OVERRIDE;
		}
#line 5824 "parse.c"
    break;

  case 298: /* filter_set_opt: PFTABLE STRING  */
#line 2791 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5856 "parse.c"
    break;

  case 299: /* filter_set_opt: RTLABEL STRING  */
#line 2818 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5875 "parse.c"
    break;

  case 300: /* filter_set_opt: community delete STRING  */
#line 2832 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5908 "parse.c"
    break;

  case 301: /* filter_set_opt: EXTCOMMUNITY delete STRING STRING  */
#line 2860 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5931 "parse.c"
    break;

  case 302: /* filter_set_opt: EXTCOMMUNITY delete OVS STRING  */
#line 2878 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5952 "parse.c"
    break;

  case 303: /* filter_set_opt: ORIGIN origincode  */
#line 2894 "../../../openbgpd-portable/src/bgpd/parse.y"
                                    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_ORIGIN;
			(yyval.v.filter_set)->action.origin = (yyvsp[0].v.number);
		}
#line 5963 "parse.c"
    break;

  case 304: /* origincode: STRING  */
#line 2902 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5982 "parse.c"
    break;

  case 305: /* validity: STRING  */
#line 2917 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 6001 "parse.c"
    break;

  case 312: /* unaryop: '='  */
#line 2942 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_EQ; }
#line 6007 "parse.c"
    break;

  case 313: /* unaryop: NE  */
#line 2943 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_NE; }
#line 6013 "parse.c"
    break;

  case 314: /* unaryop: LE  */
#line 2944 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_LE; }
#line 6019 "parse.c"
    break;

  case 315: /* unaryop: '<'  */
#line 2945 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_LT; }
#line 6025 "parse.c"
    break;

  case 316: /* unaryop: GE  */
#line 2946 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_GE; }
#line 6031 "parse.c"
    break;

  case 317: /* unaryop: '>'  */
#line 2947 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_GT; }
#line 6037 "parse.c"
    break;

  case 318: /* equalityop: '='  */
#line 2950 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_EQ; }
#line 6043 "parse.c"
    break;

  case 319: /* equalityop: NE  */
#line 2951 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_NE; }
#line 6049 "parse.c"
    break;

  case 320: /* binaryop: '-'  */
#line 2954 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_RANGE; }
#line 6055 "parse.c"
    break;

  case 321: /* binaryop: XRANGE  */
#line 2955 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_XRANGE; }
#line 6061 "parse.c"
    break;


#line 6065 "parse.c"

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

#line 2958 "../../../openbgpd-portable/src/bgpd/parse.y"


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
		{ "max-communities",	MAXCOMMUNITIES},
		{ "max-ext-communities",	MAXEXTCOMMUNITIES},
		{ "max-large-communities",	MAXLARGECOMMUNITIES},
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
	if (val == NULL) {
		yyerror("macro '%s' not defined", buf);
		return (ERROR);
	}
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
	if (!ktable_exists(c->default_tableid, &rdomid))
		fatalx("current routing table %u does not exist",
		    c->default_tableid);
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

	if (!ktable_exists(rtableid, &rdom)) {
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

	if (find_prefixset(name, sets) != NULL) {
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
