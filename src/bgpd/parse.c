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
			enum auth_enc_alg	enc_alg;
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
    PLUS = 304,                    /* PLUS  */
    POLICY = 305,                  /* POLICY  */
    DEMOTE = 306,                  /* DEMOTE  */
    ENFORCE = 307,                 /* ENFORCE  */
    NEIGHBORAS = 308,              /* NEIGHBORAS  */
    ASOVERRIDE = 309,              /* ASOVERRIDE  */
    REFLECTOR = 310,               /* REFLECTOR  */
    DEPEND = 311,                  /* DEPEND  */
    DOWN = 312,                    /* DOWN  */
    DUMP = 313,                    /* DUMP  */
    IN = 314,                      /* IN  */
    OUT = 315,                     /* OUT  */
    SOCKET = 316,                  /* SOCKET  */
    RESTRICTED = 317,              /* RESTRICTED  */
    LOG = 318,                     /* LOG  */
    TRANSPARENT = 319,             /* TRANSPARENT  */
    TCP = 320,                     /* TCP  */
    MD5SIG = 321,                  /* MD5SIG  */
    PASSWORD = 322,                /* PASSWORD  */
    KEY = 323,                     /* KEY  */
    TTLSECURITY = 324,             /* TTLSECURITY  */
    ALLOW = 325,                   /* ALLOW  */
    DENY = 326,                    /* DENY  */
    MATCH = 327,                   /* MATCH  */
    QUICK = 328,                   /* QUICK  */
    FROM = 329,                    /* FROM  */
    TO = 330,                      /* TO  */
    ANY = 331,                     /* ANY  */
    CONNECTED = 332,               /* CONNECTED  */
    STATIC = 333,                  /* STATIC  */
    COMMUNITY = 334,               /* COMMUNITY  */
    EXTCOMMUNITY = 335,            /* EXTCOMMUNITY  */
    LARGECOMMUNITY = 336,          /* LARGECOMMUNITY  */
    DELETE = 337,                  /* DELETE  */
    MAXCOMMUNITIES = 338,          /* MAXCOMMUNITIES  */
    MAXEXTCOMMUNITIES = 339,       /* MAXEXTCOMMUNITIES  */
    MAXLARGECOMMUNITIES = 340,     /* MAXLARGECOMMUNITIES  */
    PREFIX = 341,                  /* PREFIX  */
    PREFIXLEN = 342,               /* PREFIXLEN  */
    PREFIXSET = 343,               /* PREFIXSET  */
    ROASET = 344,                  /* ROASET  */
    ORIGINSET = 345,               /* ORIGINSET  */
    OVS = 346,                     /* OVS  */
    EXPIRES = 347,                 /* EXPIRES  */
    ASSET = 348,                   /* ASSET  */
    SOURCEAS = 349,                /* SOURCEAS  */
    TRANSITAS = 350,               /* TRANSITAS  */
    PEERAS = 351,                  /* PEERAS  */
    MAXASLEN = 352,                /* MAXASLEN  */
    MAXASSEQ = 353,                /* MAXASSEQ  */
    SET = 354,                     /* SET  */
    LOCALPREF = 355,               /* LOCALPREF  */
    MED = 356,                     /* MED  */
    METRIC = 357,                  /* METRIC  */
    NEXTHOP = 358,                 /* NEXTHOP  */
    REJECT = 359,                  /* REJECT  */
    BLACKHOLE = 360,               /* BLACKHOLE  */
    NOMODIFY = 361,                /* NOMODIFY  */
    SELF = 362,                    /* SELF  */
    PREPEND_SELF = 363,            /* PREPEND_SELF  */
    PREPEND_PEER = 364,            /* PREPEND_PEER  */
    PFTABLE = 365,                 /* PFTABLE  */
    WEIGHT = 366,                  /* WEIGHT  */
    RTLABEL = 367,                 /* RTLABEL  */
    ORIGIN = 368,                  /* ORIGIN  */
    PRIORITY = 369,                /* PRIORITY  */
    ERROR = 370,                   /* ERROR  */
    INCLUDE = 371,                 /* INCLUDE  */
    IPSEC = 372,                   /* IPSEC  */
    ESP = 373,                     /* ESP  */
    AH = 374,                      /* AH  */
    SPI = 375,                     /* SPI  */
    IKE = 376,                     /* IKE  */
    IPV4 = 377,                    /* IPV4  */
    IPV6 = 378,                    /* IPV6  */
    QUALIFY = 379,                 /* QUALIFY  */
    VIA = 380,                     /* VIA  */
    NE = 381,                      /* NE  */
    LE = 382,                      /* LE  */
    GE = 383,                      /* GE  */
    XRANGE = 384,                  /* XRANGE  */
    LONGER = 385,                  /* LONGER  */
    MAXLEN = 386,                  /* MAXLEN  */
    MAX = 387,                     /* MAX  */
    STRING = 388,                  /* STRING  */
    NUMBER = 389                   /* NUMBER  */
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
#define PLUS 304
#define POLICY 305
#define DEMOTE 306
#define ENFORCE 307
#define NEIGHBORAS 308
#define ASOVERRIDE 309
#define REFLECTOR 310
#define DEPEND 311
#define DOWN 312
#define DUMP 313
#define IN 314
#define OUT 315
#define SOCKET 316
#define RESTRICTED 317
#define LOG 318
#define TRANSPARENT 319
#define TCP 320
#define MD5SIG 321
#define PASSWORD 322
#define KEY 323
#define TTLSECURITY 324
#define ALLOW 325
#define DENY 326
#define MATCH 327
#define QUICK 328
#define FROM 329
#define TO 330
#define ANY 331
#define CONNECTED 332
#define STATIC 333
#define COMMUNITY 334
#define EXTCOMMUNITY 335
#define LARGECOMMUNITY 336
#define DELETE 337
#define MAXCOMMUNITIES 338
#define MAXEXTCOMMUNITIES 339
#define MAXLARGECOMMUNITIES 340
#define PREFIX 341
#define PREFIXLEN 342
#define PREFIXSET 343
#define ROASET 344
#define ORIGINSET 345
#define OVS 346
#define EXPIRES 347
#define ASSET 348
#define SOURCEAS 349
#define TRANSITAS 350
#define PEERAS 351
#define MAXASLEN 352
#define MAXASSEQ 353
#define SET 354
#define LOCALPREF 355
#define MED 356
#define METRIC 357
#define NEXTHOP 358
#define REJECT 359
#define BLACKHOLE 360
#define NOMODIFY 361
#define SELF 362
#define PREPEND_SELF 363
#define PREPEND_PEER 364
#define PFTABLE 365
#define WEIGHT 366
#define RTLABEL 367
#define ORIGIN 368
#define PRIORITY 369
#define ERROR 370
#define INCLUDE 371
#define IPSEC 372
#define ESP 373
#define AH 374
#define SPI 375
#define IKE 376
#define IPV4 377
#define IPV6 378
#define QUALIFY 379
#define VIA 380
#define NE 381
#define LE 382
#define GE 383
#define XRANGE 384
#define LONGER 385
#define MAXLEN 386
#define MAX 387
#define STRING 388
#define NUMBER 389

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
  YYSYMBOL_PLUS = 49,                      /* PLUS  */
  YYSYMBOL_POLICY = 50,                    /* POLICY  */
  YYSYMBOL_DEMOTE = 51,                    /* DEMOTE  */
  YYSYMBOL_ENFORCE = 52,                   /* ENFORCE  */
  YYSYMBOL_NEIGHBORAS = 53,                /* NEIGHBORAS  */
  YYSYMBOL_ASOVERRIDE = 54,                /* ASOVERRIDE  */
  YYSYMBOL_REFLECTOR = 55,                 /* REFLECTOR  */
  YYSYMBOL_DEPEND = 56,                    /* DEPEND  */
  YYSYMBOL_DOWN = 57,                      /* DOWN  */
  YYSYMBOL_DUMP = 58,                      /* DUMP  */
  YYSYMBOL_IN = 59,                        /* IN  */
  YYSYMBOL_OUT = 60,                       /* OUT  */
  YYSYMBOL_SOCKET = 61,                    /* SOCKET  */
  YYSYMBOL_RESTRICTED = 62,                /* RESTRICTED  */
  YYSYMBOL_LOG = 63,                       /* LOG  */
  YYSYMBOL_TRANSPARENT = 64,               /* TRANSPARENT  */
  YYSYMBOL_TCP = 65,                       /* TCP  */
  YYSYMBOL_MD5SIG = 66,                    /* MD5SIG  */
  YYSYMBOL_PASSWORD = 67,                  /* PASSWORD  */
  YYSYMBOL_KEY = 68,                       /* KEY  */
  YYSYMBOL_TTLSECURITY = 69,               /* TTLSECURITY  */
  YYSYMBOL_ALLOW = 70,                     /* ALLOW  */
  YYSYMBOL_DENY = 71,                      /* DENY  */
  YYSYMBOL_MATCH = 72,                     /* MATCH  */
  YYSYMBOL_QUICK = 73,                     /* QUICK  */
  YYSYMBOL_FROM = 74,                      /* FROM  */
  YYSYMBOL_TO = 75,                        /* TO  */
  YYSYMBOL_ANY = 76,                       /* ANY  */
  YYSYMBOL_CONNECTED = 77,                 /* CONNECTED  */
  YYSYMBOL_STATIC = 78,                    /* STATIC  */
  YYSYMBOL_COMMUNITY = 79,                 /* COMMUNITY  */
  YYSYMBOL_EXTCOMMUNITY = 80,              /* EXTCOMMUNITY  */
  YYSYMBOL_LARGECOMMUNITY = 81,            /* LARGECOMMUNITY  */
  YYSYMBOL_DELETE = 82,                    /* DELETE  */
  YYSYMBOL_MAXCOMMUNITIES = 83,            /* MAXCOMMUNITIES  */
  YYSYMBOL_MAXEXTCOMMUNITIES = 84,         /* MAXEXTCOMMUNITIES  */
  YYSYMBOL_MAXLARGECOMMUNITIES = 85,       /* MAXLARGECOMMUNITIES  */
  YYSYMBOL_PREFIX = 86,                    /* PREFIX  */
  YYSYMBOL_PREFIXLEN = 87,                 /* PREFIXLEN  */
  YYSYMBOL_PREFIXSET = 88,                 /* PREFIXSET  */
  YYSYMBOL_ROASET = 89,                    /* ROASET  */
  YYSYMBOL_ORIGINSET = 90,                 /* ORIGINSET  */
  YYSYMBOL_OVS = 91,                       /* OVS  */
  YYSYMBOL_EXPIRES = 92,                   /* EXPIRES  */
  YYSYMBOL_ASSET = 93,                     /* ASSET  */
  YYSYMBOL_SOURCEAS = 94,                  /* SOURCEAS  */
  YYSYMBOL_TRANSITAS = 95,                 /* TRANSITAS  */
  YYSYMBOL_PEERAS = 96,                    /* PEERAS  */
  YYSYMBOL_MAXASLEN = 97,                  /* MAXASLEN  */
  YYSYMBOL_MAXASSEQ = 98,                  /* MAXASSEQ  */
  YYSYMBOL_SET = 99,                       /* SET  */
  YYSYMBOL_LOCALPREF = 100,                /* LOCALPREF  */
  YYSYMBOL_MED = 101,                      /* MED  */
  YYSYMBOL_METRIC = 102,                   /* METRIC  */
  YYSYMBOL_NEXTHOP = 103,                  /* NEXTHOP  */
  YYSYMBOL_REJECT = 104,                   /* REJECT  */
  YYSYMBOL_BLACKHOLE = 105,                /* BLACKHOLE  */
  YYSYMBOL_NOMODIFY = 106,                 /* NOMODIFY  */
  YYSYMBOL_SELF = 107,                     /* SELF  */
  YYSYMBOL_PREPEND_SELF = 108,             /* PREPEND_SELF  */
  YYSYMBOL_PREPEND_PEER = 109,             /* PREPEND_PEER  */
  YYSYMBOL_PFTABLE = 110,                  /* PFTABLE  */
  YYSYMBOL_WEIGHT = 111,                   /* WEIGHT  */
  YYSYMBOL_RTLABEL = 112,                  /* RTLABEL  */
  YYSYMBOL_ORIGIN = 113,                   /* ORIGIN  */
  YYSYMBOL_PRIORITY = 114,                 /* PRIORITY  */
  YYSYMBOL_ERROR = 115,                    /* ERROR  */
  YYSYMBOL_INCLUDE = 116,                  /* INCLUDE  */
  YYSYMBOL_IPSEC = 117,                    /* IPSEC  */
  YYSYMBOL_ESP = 118,                      /* ESP  */
  YYSYMBOL_AH = 119,                       /* AH  */
  YYSYMBOL_SPI = 120,                      /* SPI  */
  YYSYMBOL_IKE = 121,                      /* IKE  */
  YYSYMBOL_IPV4 = 122,                     /* IPV4  */
  YYSYMBOL_IPV6 = 123,                     /* IPV6  */
  YYSYMBOL_QUALIFY = 124,                  /* QUALIFY  */
  YYSYMBOL_VIA = 125,                      /* VIA  */
  YYSYMBOL_NE = 126,                       /* NE  */
  YYSYMBOL_LE = 127,                       /* LE  */
  YYSYMBOL_GE = 128,                       /* GE  */
  YYSYMBOL_XRANGE = 129,                   /* XRANGE  */
  YYSYMBOL_LONGER = 130,                   /* LONGER  */
  YYSYMBOL_MAXLEN = 131,                   /* MAXLEN  */
  YYSYMBOL_MAX = 132,                      /* MAX  */
  YYSYMBOL_STRING = 133,                   /* STRING  */
  YYSYMBOL_NUMBER = 134,                   /* NUMBER  */
  YYSYMBOL_135_n_ = 135,                   /* '\n'  */
  YYSYMBOL_136_ = 136,                     /* '='  */
  YYSYMBOL_137_ = 137,                     /* '{'  */
  YYSYMBOL_138_ = 138,                     /* '}'  */
  YYSYMBOL_139_ = 139,                     /* '/'  */
  YYSYMBOL_140_ = 140,                     /* '+'  */
  YYSYMBOL_141_ = 141,                     /* '-'  */
  YYSYMBOL_142_ = 142,                     /* ','  */
  YYSYMBOL_143_ = 143,                     /* '<'  */
  YYSYMBOL_144_ = 144,                     /* '>'  */
  YYSYMBOL_YYACCEPT = 145,                 /* $accept  */
  YYSYMBOL_grammar = 146,                  /* grammar  */
  YYSYMBOL_asnumber = 147,                 /* asnumber  */
  YYSYMBOL_as4number = 148,                /* as4number  */
  YYSYMBOL_as4number_any = 149,            /* as4number_any  */
  YYSYMBOL_string = 150,                   /* string  */
  YYSYMBOL_yesno = 151,                    /* yesno  */
  YYSYMBOL_varset = 152,                   /* varset  */
  YYSYMBOL_include = 153,                  /* include  */
  YYSYMBOL_as_set = 154,                   /* as_set  */
  YYSYMBOL_155_1 = 155,                    /* $@1  */
  YYSYMBOL_as_set_l = 156,                 /* as_set_l  */
  YYSYMBOL_prefixset = 157,                /* prefixset  */
  YYSYMBOL_158_2 = 158,                    /* $@2  */
  YYSYMBOL_prefixset_l = 159,              /* prefixset_l  */
  YYSYMBOL_prefixset_item = 160,           /* prefixset_item  */
  YYSYMBOL_roa_set = 161,                  /* roa_set  */
  YYSYMBOL_162_3 = 162,                    /* $@3  */
  YYSYMBOL_origin_set = 163,               /* origin_set  */
  YYSYMBOL_164_4 = 164,                    /* $@4  */
  YYSYMBOL_expires = 165,                  /* expires  */
  YYSYMBOL_roa_set_l = 166,                /* roa_set_l  */
  YYSYMBOL_rtr = 167,                      /* rtr  */
  YYSYMBOL_168_5 = 168,                    /* $@5  */
  YYSYMBOL_rtropt_l = 169,                 /* rtropt_l  */
  YYSYMBOL_rtropt = 170,                   /* rtropt  */
  YYSYMBOL_conf_main = 171,                /* conf_main  */
  YYSYMBOL_rib = 172,                      /* rib  */
  YYSYMBOL_173_6 = 173,                    /* $@6  */
  YYSYMBOL_ribopts = 174,                  /* ribopts  */
  YYSYMBOL_fibupdate = 175,                /* fibupdate  */
  YYSYMBOL_mrtdump = 176,                  /* mrtdump  */
  YYSYMBOL_network = 177,                  /* network  */
  YYSYMBOL_inout = 178,                    /* inout  */
  YYSYMBOL_restricted = 179,               /* restricted  */
  YYSYMBOL_address = 180,                  /* address  */
  YYSYMBOL_prefix = 181,                   /* prefix  */
  YYSYMBOL_addrspec = 182,                 /* addrspec  */
  YYSYMBOL_optnumber = 183,                /* optnumber  */
  YYSYMBOL_l3vpn = 184,                    /* l3vpn  */
  YYSYMBOL_185_7 = 185,                    /* $@7  */
  YYSYMBOL_l3vpnopts_l = 186,              /* l3vpnopts_l  */
  YYSYMBOL_l3vpnopts = 187,                /* l3vpnopts  */
  YYSYMBOL_neighbor = 188,                 /* neighbor  */
  YYSYMBOL_189_8 = 189,                    /* $@8  */
  YYSYMBOL_190_9 = 190,                    /* $@9  */
  YYSYMBOL_group = 191,                    /* group  */
  YYSYMBOL_192_10 = 192,                   /* $@10  */
  YYSYMBOL_groupopts_l = 193,              /* groupopts_l  */
  YYSYMBOL_addpathextra = 194,             /* addpathextra  */
  YYSYMBOL_addpathmax = 195,               /* addpathmax  */
  YYSYMBOL_peeropts_h = 196,               /* peeropts_h  */
  YYSYMBOL_peeropts_l = 197,               /* peeropts_l  */
  YYSYMBOL_peeropts = 198,                 /* peeropts  */
  YYSYMBOL_restart = 199,                  /* restart  */
  YYSYMBOL_family = 200,                   /* family  */
  YYSYMBOL_safi = 201,                     /* safi  */
  YYSYMBOL_nettype = 202,                  /* nettype  */
  YYSYMBOL_espah = 203,                    /* espah  */
  YYSYMBOL_encspec = 204,                  /* encspec  */
  YYSYMBOL_filterrule = 205,               /* filterrule  */
  YYSYMBOL_action = 206,                   /* action  */
  YYSYMBOL_quick = 207,                    /* quick  */
  YYSYMBOL_direction = 208,                /* direction  */
  YYSYMBOL_filter_rib_h = 209,             /* filter_rib_h  */
  YYSYMBOL_filter_rib_l = 210,             /* filter_rib_l  */
  YYSYMBOL_filter_rib = 211,               /* filter_rib  */
  YYSYMBOL_filter_peer_h = 212,            /* filter_peer_h  */
  YYSYMBOL_filter_peer_l = 213,            /* filter_peer_l  */
  YYSYMBOL_filter_peer = 214,              /* filter_peer  */
  YYSYMBOL_filter_prefix_h = 215,          /* filter_prefix_h  */
  YYSYMBOL_filter_prefix_m = 216,          /* filter_prefix_m  */
  YYSYMBOL_filter_prefix_l = 217,          /* filter_prefix_l  */
  YYSYMBOL_filter_prefix = 218,            /* filter_prefix  */
  YYSYMBOL_filter_as_h = 219,              /* filter_as_h  */
  YYSYMBOL_filter_as_t_l = 220,            /* filter_as_t_l  */
  YYSYMBOL_filter_as_t = 221,              /* filter_as_t  */
  YYSYMBOL_filter_as_l_h = 222,            /* filter_as_l_h  */
  YYSYMBOL_filter_as_l = 223,              /* filter_as_l  */
  YYSYMBOL_filter_as = 224,                /* filter_as  */
  YYSYMBOL_filter_match_h = 225,           /* filter_match_h  */
  YYSYMBOL_226_11 = 226,                   /* $@11  */
  YYSYMBOL_filter_match = 227,             /* filter_match  */
  YYSYMBOL_filter_elm = 228,               /* filter_elm  */
  YYSYMBOL_prefixlenop = 229,              /* prefixlenop  */
  YYSYMBOL_filter_as_type = 230,           /* filter_as_type  */
  YYSYMBOL_filter_set = 231,               /* filter_set  */
  YYSYMBOL_filter_set_l = 232,             /* filter_set_l  */
  YYSYMBOL_community = 233,                /* community  */
  YYSYMBOL_delete = 234,                   /* delete  */
  YYSYMBOL_enforce = 235,                  /* enforce  */
  YYSYMBOL_filter_set_opt = 236,           /* filter_set_opt  */
  YYSYMBOL_origincode = 237,               /* origincode  */
  YYSYMBOL_validity = 238,                 /* validity  */
  YYSYMBOL_optnl = 239,                    /* optnl  */
  YYSYMBOL_comma = 240,                    /* comma  */
  YYSYMBOL_unaryop = 241,                  /* unaryop  */
  YYSYMBOL_equalityop = 242,               /* equalityop  */
  YYSYMBOL_binaryop = 243                  /* binaryop  */
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
#define YYNTOKENS  145
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  329
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  611

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   389


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
     135,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   140,   142,   141,     2,   139,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     143,   136,   144,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   137,     2,   138,     2,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   259,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   277,   288,
     320,   330,   357,   362,   368,   371,   386,   414,   429,   429,
     443,   451,   452,   454,   454,   464,   474,   488,   504,   521,
     521,   528,   531,   531,   544,   556,   559,   567,   577,   589,
     598,   598,   610,   611,   613,   624,   632,   642,   649,   653,
     660,   668,   676,   690,   710,   717,   728,   734,   740,   749,
     750,   778,   810,   811,   821,   831,   844,   857,   870,   886,
     893,   909,   909,   919,   920,   929,   938,   939,   947,   977,
     998,  1027,  1046,  1069,  1089,  1090,  1093,  1094,  1097,  1118,
    1136,  1156,  1163,  1166,  1167,  1170,  1170,  1215,  1216,  1217,
    1218,  1221,  1239,  1257,  1275,  1281,  1284,  1285,  1284,  1319,
    1319,  1351,  1352,  1353,  1354,  1355,  1358,  1359,  1369,  1370,
    1380,  1381,  1382,  1385,  1386,  1387,  1388,  1391,  1394,  1401,
    1405,  1416,  1429,  1439,  1446,  1449,  1452,  1463,  1479,  1487,
    1495,  1514,  1517,  1520,  1523,  1526,  1529,  1539,  1583,  1610,
    1613,  1616,  1622,  1628,  1643,  1651,  1659,  1677,  1693,  1703,
    1796,  1799,  1806,  1818,  1819,  1829,  1845,  1857,  1881,  1887,
    1898,  1904,  1912,  1927,  1928,  1938,  1939,  1942,  1943,  1944,
    1947,  1948,  1951,  1952,  1955,  1958,  1991,  2018,  2019,  2020,
    2023,  2024,  2027,  2028,  2031,  2032,  2033,  2035,  2036,  2042,
    2064,  2065,  2068,  2069,  2075,  2082,  2102,  2109,  2130,  2136,
    2144,  2159,  2174,  2175,  2178,  2179,  2180,  2192,  2193,  2199,
    2214,  2215,  2218,  2219,  2231,  2235,  2242,  2265,  2266,  2267,
    2280,  2281,  2287,  2295,  2301,  2309,  2323,  2326,  2326,  2334,
    2335,  2338,  2351,  2358,  2370,  2382,  2400,  2422,  2441,  2457,
    2469,  2481,  2489,  2496,  2545,  2565,  2575,  2576,  2582,  2593,
    2636,  2652,  2653,  2654,  2655,  2658,  2659,  2666,  2669,  2674,
    2683,  2684,  2687,  2688,  2691,  2692,  2695,  2710,  2720,  2730,
    2745,  2755,  2765,  2780,  2790,  2800,  2815,  2825,  2835,  2842,
    2847,  2852,  2857,  2862,  2872,  2882,  2887,  2914,  2928,  2956,
    2974,  2990,  2998,  3013,  3028,  3029,  3032,  3033,  3034,  3035,
    3038,  3039,  3040,  3041,  3042,  3043,  3046,  3047,  3050,  3051
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
  "CONNECTRETRY", "ENHANCED", "ADDPATH", "SEND", "RECV", "PLUS", "POLICY",
  "DEMOTE", "ENFORCE", "NEIGHBORAS", "ASOVERRIDE", "REFLECTOR", "DEPEND",
  "DOWN", "DUMP", "IN", "OUT", "SOCKET", "RESTRICTED", "LOG",
  "TRANSPARENT", "TCP", "MD5SIG", "PASSWORD", "KEY", "TTLSECURITY",
  "ALLOW", "DENY", "MATCH", "QUICK", "FROM", "TO", "ANY", "CONNECTED",
  "STATIC", "COMMUNITY", "EXTCOMMUNITY", "LARGECOMMUNITY", "DELETE",
  "MAXCOMMUNITIES", "MAXEXTCOMMUNITIES", "MAXLARGECOMMUNITIES", "PREFIX",
  "PREFIXLEN", "PREFIXSET", "ROASET", "ORIGINSET", "OVS", "EXPIRES",
  "ASSET", "SOURCEAS", "TRANSITAS", "PEERAS", "MAXASLEN", "MAXASSEQ",
  "SET", "LOCALPREF", "MED", "METRIC", "NEXTHOP", "REJECT", "BLACKHOLE",
  "NOMODIFY", "SELF", "PREPEND_SELF", "PREPEND_PEER", "PFTABLE", "WEIGHT",
  "RTLABEL", "ORIGIN", "PRIORITY", "ERROR", "INCLUDE", "IPSEC", "ESP",
  "AH", "SPI", "IKE", "IPV4", "IPV6", "QUALIFY", "VIA", "NE", "LE", "GE",
  "XRANGE", "LONGER", "MAXLEN", "MAX", "STRING", "NUMBER", "'\\n'", "'='",
  "'{'", "'}'", "'/'", "'+'", "'-'", "','", "'<'", "'>'", "$accept",
  "grammar", "asnumber", "as4number", "as4number_any", "string", "yesno",
  "varset", "include", "as_set", "$@1", "as_set_l", "prefixset", "$@2",
  "prefixset_l", "prefixset_item", "roa_set", "$@3", "origin_set", "$@4",
  "expires", "roa_set_l", "rtr", "$@5", "rtropt_l", "rtropt", "conf_main",
  "rib", "$@6", "ribopts", "fibupdate", "mrtdump", "network", "inout",
  "restricted", "address", "prefix", "addrspec", "optnumber", "l3vpn",
  "$@7", "l3vpnopts_l", "l3vpnopts", "neighbor", "$@8", "$@9", "group",
  "$@10", "groupopts_l", "addpathextra", "addpathmax", "peeropts_h",
  "peeropts_l", "peeropts", "restart", "family", "safi", "nettype",
  "espah", "encspec", "filterrule", "action", "quick", "direction",
  "filter_rib_h", "filter_rib_l", "filter_rib", "filter_peer_h",
  "filter_peer_l", "filter_peer", "filter_prefix_h", "filter_prefix_m",
  "filter_prefix_l", "filter_prefix", "filter_as_h", "filter_as_t_l",
  "filter_as_t", "filter_as_l_h", "filter_as_l", "filter_as",
  "filter_match_h", "$@11", "filter_match", "filter_elm", "prefixlenop",
  "filter_as_type", "filter_set", "filter_set_l", "community", "delete",
  "enforce", "filter_set_opt", "origincode", "validity", "optnl", "comma",
  "unaryop", "equalityop", "binaryop", YY_NULLPTR
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
     385,   386,   387,   388,   389,    10,    61,   123,   125,    47,
      43,    45,    44,    60,    62
};
#endif

#define YYPACT_NINF (-424)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-317)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -424,   454,  -424,   -71,   109,   -59,    17,    72,   -47,   -29,
      10,   -39,    12,   -59,   -11,   -35,    14,    42,    20,    43,
     -47,  -424,  -424,  -424,    47,    13,    60,    73,    90,   130,
      95,    97,  -424,    96,   100,   110,   120,   140,   145,   165,
     167,   171,  -424,  -424,   182,   197,   240,   228,   238,   198,
    -424,  -424,  -424,  -424,   180,  -424,  -424,   194,  -424,   -59,
    -424,  -424,  -424,  -424,   338,   242,   243,   350,   225,   244,
    -424,   246,   247,  -424,  -424,   239,   250,   283,    -2,  -424,
     251,   -12,   323,  -424,  -424,   249,   257,   259,   260,   269,
     -47,  -424,   -11,  -424,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,  -424,   126,  -424,  -424,  -424,   377,  -424,
    -424,   380,   275,  -424,  -424,   276,  -424,  -424,   273,  -424,
     277,   283,   278,   279,   558,  -424,  -424,  -424,   282,   286,
     283,   284,  -424,  -424,   292,   294,  -424,  -424,   257,   257,
     290,   257,   257,   296,  -424,   246,   239,  -424,  -424,  -424,
     -19,   245,   300,  -424,    16,  -424,   257,  -424,  -424,  -424,
    -424,  -424,  -424,   353,  -424,   124,   133,   136,   106,   303,
     305,   308,   184,   309,   310,   257,   353,  -424,   283,   283,
    -424,   311,  -424,  -424,   292,   312,  -424,  -424,   218,   313,
     315,  -424,   319,  -424,   257,  -424,  -424,  -424,    19,  -424,
     330,   -47,   318,   423,  -424,  -424,    99,   367,  -424,   -51,
    -424,   335,   336,  -424,   339,   341,  -424,   342,   343,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -424,  -424,   344,   346,
    -424,  -424,  -424,   618,   316,  -424,  -424,   292,  -424,  -424,
     218,   352,    53,   -28,  -424,   218,  -424,   220,   546,  -424,
     354,   109,   355,  -424,  -424,  -424,   257,  -424,   -34,  -424,
    -424,  -424,   438,  -424,   351,   356,   -59,   257,  -424,   337,
      35,    58,   426,   357,   358,   109,   109,   -11,   -59,   359,
    -424,   360,   211,   362,    39,   -47,   -59,   478,   363,   366,
     368,   -47,   425,   -47,   574,   410,   241,  -424,  -424,   469,
    -424,   371,   372,   375,   376,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,    53,  -424,  -424,  -424,    53,  -424,   220,
     257,   378,   373,   218,   195,  -424,   382,  -424,    53,  -424,
    -424,  -424,    53,  -424,   381,    82,  -424,  -424,  -424,    54,
     283,   213,    27,  -424,  -424,  -424,  -424,    26,  -424,   386,
    -424,  -424,  -424,   388,  -424,  -424,   180,  -424,   246,  -424,
    -424,    51,   -47,   -47,   -47,   -47,   468,   314,   389,   191,
    -424,   -47,   -47,  -424,  -424,   390,  -424,   307,  -424,  -424,
     302,  -424,   257,  -424,   -47,  -424,  -424,    -5,  -424,  -424,
    -424,  -424,  -424,   391,   618,   392,   218,   422,   393,   257,
    -424,   433,  -424,  -424,  -424,   -63,  -424,  -424,  -424,   394,
    -424,   395,   396,   220,   103,  -424,   397,   354,    53,  -424,
    -424,  -424,   -40,   398,   402,   403,   -37,   405,   406,   407,
    -424,  -424,  -424,   411,   412,     9,   -28,   -28,    32,  -424,
    -424,  -424,   213,  -424,    93,   408,   414,   -47,   417,   419,
     420,  -424,  -424,  -424,   421,  -424,  -424,  -424,  -424,  -424,
     427,   515,  -424,  -424,  -424,  -424,  -424,   -47,   430,   -47,
     503,  -424,  -424,  -424,  -424,  -424,  -424,  -424,   -11,   -11,
     618,  -424,  -424,   439,  -424,  -424,  -424,  -424,   431,  -424,
    -424,   220,  -424,  -424,   434,  -424,  -424,  -424,  -424,   429,
    -424,  -424,   436,  -424,  -424,   437,    54,   441,   443,  -424,
    -424,  -424,   193,   -28,  -424,   -28,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,    83,  -424,  -424,  -424,   444,
    -424,  -424,    64,   -63,  -424,   220,  -424,  -424,  -424,  -424,
     455,   457,  -424,  -424,  -424,  -424,   511,  -424,  -424,  -424,
     246,   246,    53,   435,  -424,   422,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,   218,   453,   102,  -424,  -424,  -424,   257,
    -424,    32,  -424,   179,   456,   205,  -424,   220,  -424,  -424,
    -424,   458,   461,   467,   462,  -424,   206,  -424,   218,  -424,
    -424,   207,  -424,   179,  -424,  -424,   465,  -424,  -424,   463,
     193,  -424,    64,  -424,  -424,   473,  -424,  -424,   474,  -424,
    -424
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   197,   198,   199,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    69,     0,     0,     0,     0,     0,   200,
      17,    19,    18,    20,    57,    98,    59,     0,    60,     0,
      25,    65,    64,    78,     0,     0,     0,     0,     0,    49,
      24,   119,     0,   185,   186,     0,     0,   275,     0,    79,
       0,     0,    97,    68,    66,     0,   314,     0,     0,     0,
       0,    27,     0,     4,     5,     6,     7,     8,     9,    10,
      12,    11,    13,    14,     0,    15,    16,   201,   204,    58,
      61,    62,     0,    81,    76,     0,    73,    74,     0,    23,
       0,   275,     0,     0,     0,    89,   191,   190,     0,     0,
     275,     0,    94,    95,   103,     0,    96,    80,   314,   314,
      39,   314,   314,     0,    67,    26,    98,   101,   102,   117,
       0,     0,     0,   105,    86,    75,   314,   121,    90,    99,
     100,   305,   280,   282,   281,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   314,   282,   276,   275,   275,
      93,     0,   104,    70,   103,    33,   315,    41,     0,    42,
      28,    77,   132,   209,   314,   205,   202,   203,     0,    63,
       0,     0,     0,     0,    82,    83,     0,     0,   283,     0,
     286,     0,     0,   289,     0,     0,   292,     0,     0,   300,
     299,   301,   302,   298,   303,   304,   306,   295,     0,     0,
     307,   312,   311,     0,     0,    91,    92,   103,    88,    35,
       0,     0,   316,   266,    44,     0,    30,     0,     0,   118,
       0,     0,     0,   218,   219,   214,   314,   215,   247,   210,
     107,    87,    86,    85,     0,     0,     0,   314,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,   174,     0,   145,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   120,     0,
     173,     0,     0,     0,     0,   287,   288,   290,   291,   293,
     294,   296,   297,   316,   279,   308,    71,   316,    36,     0,
     314,   317,     0,     0,     0,   267,     0,    38,   316,    21,
      22,    31,   316,   133,     0,   314,   207,   216,   217,     0,
     275,     0,     0,    84,    56,    54,    55,     0,   125,     0,
     148,   159,   160,     0,   147,   181,   138,   137,   140,   141,
     143,   183,     0,     0,     0,     0,     0,     0,     0,     0,
     177,     0,     0,   163,   175,     0,   146,     0,   179,   178,
       0,   170,   314,   171,     0,   192,   193,     0,   142,   124,
     123,   310,   309,     0,     0,     0,     0,    45,   318,   314,
      40,     0,   321,   322,   324,     0,   320,   323,   325,     0,
     268,     0,     0,     0,     0,   131,     0,     0,   316,   212,
     196,   271,     0,     0,     0,     0,     0,     0,     0,     0,
     272,   273,   274,     0,     0,     0,   266,   266,     0,   251,
     252,   230,   248,   249,     0,     0,     0,     0,     0,     0,
       0,   108,   106,   115,     0,    51,    53,   149,   182,   139,
       0,   183,   164,   154,   151,   152,   155,     0,     0,     0,
     284,   187,   188,   189,   150,   162,   161,   176,     0,     0,
       0,   180,   168,     0,   277,   278,    34,    37,     0,    47,
     319,     0,   329,   328,     0,   269,    43,    29,    32,     0,
     134,   130,     0,   206,   208,     0,     0,     0,     0,   258,
     259,   260,     0,   266,   222,   266,   264,   313,   265,   253,
     254,   262,   261,   220,   221,   316,   232,   250,   243,     0,
     327,   326,     0,   242,   234,     0,   255,   110,   114,   111,
       0,     0,   109,   184,   165,   153,   126,   156,   285,   158,
     166,   167,   316,     0,    46,    45,   270,   136,   135,   211,
     213,   257,   256,     0,     0,   316,   227,   229,   263,   314,
     231,     0,   236,     0,     0,   316,   240,     0,   244,   112,
     113,     0,   128,     0,     0,    48,   316,   223,     0,   318,
     233,   316,   235,     0,   245,   127,     0,   157,   172,     0,
     225,   228,   238,   241,   129,   194,   226,   239,     0,   169,
     195
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -424,  -424,    15,  -208,  -240,   -88,    -7,  -424,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,  -214,  -424,  -424,  -424,  -424,
      59,   374,  -424,  -424,  -424,   261,  -424,  -424,  -424,  -424,
     361,   612,   274,   230,  -424,     3,   -15,  -424,  -146,  -424,
    -424,  -424,  -424,   413,  -424,  -424,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,  -231,   157,   340,  -424,  -424,  -424,  -424,
    -424,  -424,  -424,  -424,  -424,  -424,  -239,  -424,  -424,  -321,
    -424,    21,    61,  -414,  -424,  -424,  -408,    23,    56,  -423,
    -424,  -424,  -424,   185,  -228,  -424,  -106,   146,  -310,   459,
    -424,  -115,  -424,  -424,  -136,  -303,  -424,  -424,    98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,   330,    54,   533,    71,   299,    33,    34,    35,
     247,   332,    36,   240,   317,   241,    37,   188,    38,   245,
     489,   242,    39,   118,   267,   268,    40,    41,   154,   204,
     205,   300,    43,   135,   137,   257,   243,   149,   183,    44,
     200,   342,   454,    45,    46,   192,    47,   120,   207,   582,
     597,   249,   414,   302,   462,    78,   474,   130,   387,   609,
      48,    49,   108,   198,   151,   335,   195,   258,   418,   259,
     439,   564,   565,   566,   440,   525,   441,   574,   575,   576,
     340,   341,   442,   443,   327,   444,   125,   313,   176,   209,
     549,   314,   232,   518,   140,   323,   409,   535,   494
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    61,   185,   186,   145,   189,   190,   331,    56,   177,
     394,   336,   514,    84,   396,   158,    69,   334,   419,    53,
     206,   534,   251,    57,   180,   201,   318,   202,   446,   413,
     526,   445,   417,    65,    66,   421,   447,   521,   238,   233,
     303,   349,   448,   337,   449,   450,   252,   132,   133,   253,
     254,   507,   264,    72,   132,   133,    15,   251,   250,   324,
     265,   266,   111,    80,    50,  -246,   492,   356,   357,   109,
     351,   371,   235,   236,    55,   126,   127,   352,   493,   397,
      59,   252,   304,   144,   253,   254,    60,    73,    74,   148,
     460,   316,   372,   508,    64,   255,    75,    76,    75,    76,
     512,  -246,   325,   326,   499,    62,   322,   147,   270,   401,
     128,   461,   129,    67,   193,   506,   482,   528,   194,   271,
     339,   134,    70,   272,   273,   264,   430,   431,   432,   274,
     255,   347,   445,   265,   266,   275,   276,   277,   278,   279,
     280,   281,    55,   282,    63,    68,   528,   203,    79,    60,
      86,    58,    55,    82,   283,   284,   256,   285,   286,   287,
     288,   289,   451,   590,   455,   452,   290,   291,   292,   350,
     603,   223,   293,   498,   601,    81,    83,   393,   504,   383,
      85,   395,   487,   502,   398,   560,   529,    55,   320,   358,
     530,  -314,   411,    87,   261,   321,   412,   329,    52,   416,
     531,   573,   294,   471,   472,   473,    88,   295,   523,   524,
     219,   220,   221,   222,    89,  -316,   421,   320,   569,   530,
     296,   570,   571,    90,   321,   321,   329,    52,    91,   531,
     532,    93,   528,    92,   420,    94,    60,   569,   500,    55,
    -224,   501,    51,    52,   321,    95,   480,   116,   117,   394,
     362,   555,   363,   364,   365,    96,   366,   367,   210,   146,
      76,   368,   588,   490,   211,   212,    53,   213,   104,   346,
     216,   107,   593,   214,   215,    97,   217,   218,   373,   485,
      98,   359,   505,   588,   379,   567,   381,   568,   593,   374,
      53,    53,   162,   422,   164,   578,   423,   424,   425,   426,
      99,   427,   100,   428,   429,   530,   101,   430,   431,   432,
     433,   434,   329,    52,    52,   531,   435,   102,   227,   196,
     197,   402,   403,   404,   228,   229,    75,    76,   110,   405,
     563,   406,   103,    73,    74,   436,   437,   594,   407,   408,
     569,   569,   569,  -237,   600,   602,   112,   321,   321,   321,
     438,    75,    76,   329,    52,   463,   464,   465,   466,   385,
     386,   468,   469,   105,   475,   476,   132,   133,   269,   478,
     479,   459,   270,   106,   115,   113,   114,   481,   122,   119,
     121,   -50,   124,   271,   131,   136,   138,   272,   273,   123,
     550,   551,   139,   274,   143,  -116,   141,   142,   150,   275,
     276,   277,   278,   279,   280,   281,   152,   282,   153,   155,
     156,   513,   159,   160,   157,   178,   583,   181,   283,   284,
     179,   285,   286,   287,   288,   289,   182,   184,   187,   191,
     290,   291,   292,   589,   199,   208,   293,   224,   522,   225,
     538,   226,   230,   231,   237,   263,   319,   201,   353,   315,
     239,   244,   262,   246,     2,     3,   248,     4,     5,     6,
     545,     7,   547,     8,     9,    10,   294,   260,    11,   305,
     306,   295,   348,   307,    12,   308,   309,   310,   311,    13,
     312,    14,  -116,    15,   296,   344,   375,   193,   338,   345,
     354,   380,   355,   360,   361,   370,   376,   513,    16,   377,
      60,   378,   297,   384,   388,   298,   389,   390,   391,   392,
     467,   400,    17,   399,   488,    18,   410,    19,    20,   415,
     457,   458,   470,   477,    21,    22,    23,   491,   495,   484,
     486,  -315,   509,   496,   497,   503,   510,   511,   515,   516,
     517,   536,    24,    25,    26,   519,   520,    27,   513,   537,
     539,   270,   540,   541,   460,   548,   542,    28,    29,   553,
     581,   543,   271,   546,   557,   554,   272,   273,   556,   584,
      30,   558,   274,   513,   561,   559,   562,   572,   275,   276,
     277,   278,   279,   280,   281,   513,   282,    31,   579,    32,
     580,   587,   595,   596,   592,   599,   605,   283,   284,   604,
     285,   286,   287,   288,   289,   598,   608,   610,   456,   290,
     291,   292,   161,    42,   585,   293,   453,   483,   544,   328,
     301,   606,   369,   343,   586,   607,   552,   527,   161,   591,
       0,   577,     0,     0,     0,   234,     0,   162,   163,   164,
       0,     0,     0,     0,     0,   294,     0,     0,     0,     0,
     295,     0,     0,   162,   163,   164,     0,     0,   165,   166,
     167,   168,     0,   296,     0,     0,   169,   170,   171,   172,
     173,   174,   161,     0,   165,   166,   167,   168,     0,    60,
       0,   333,   169,   170,   171,   172,   173,   174,     0,     0,
       0,     0,     0,     0,     0,   175,     0,   162,   163,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,     0,     0,     0,     0,     0,     0,   165,   166,
     167,   168,     0,     0,     0,     0,   169,   170,   171,   172,
     173,   174
};

static const yytype_int16 yycheck[] =
{
      15,     8,   138,   139,    92,   141,   142,   247,     5,   124,
     313,   250,   426,    20,   317,   121,    13,   248,   339,     4,
     156,   444,     3,     6,   130,     9,   240,    11,     1,   332,
     438,   341,   335,    21,    22,     3,     9,    28,   184,   175,
      91,     6,    15,   251,    17,    18,    27,    59,    60,    30,
      31,    91,    26,    88,    59,    60,    29,     3,   194,    87,
      34,    35,    59,    21,   135,    99,   129,   275,   276,    54,
      12,    32,   178,   179,   133,    77,    78,    19,   141,   319,
       8,    27,   133,    90,    30,    31,   133,   122,   123,   104,
      39,   237,    53,   133,   133,    76,   133,   134,   133,   134,
     137,   135,   130,   131,     1,   134,   242,   104,     5,   323,
     112,    60,   114,   101,   133,   418,   121,    53,   137,    16,
     256,   133,   133,    20,    21,    26,    94,    95,    96,    26,
      76,   267,   442,    34,    35,    32,    33,    34,    35,    36,
      37,    38,   133,    40,   134,   133,    53,   154,   134,   133,
     137,   134,   133,   133,    51,    52,   137,    54,    55,    56,
      57,    58,   135,   571,   138,   138,    63,    64,    65,   134,
     593,   168,    69,   413,   588,   133,   133,   313,   417,   294,
     133,   317,   396,   414,   320,   506,    93,   133,   135,   277,
     126,   138,   328,   133,   201,   142,   332,   133,   134,   335,
     136,   137,    99,    12,    13,    14,   133,   104,   436,   437,
     104,   105,   106,   107,   124,   133,     3,   135,   135,   126,
     117,   138,   525,    93,   142,   142,   133,   134,   133,   136,
     137,   135,    53,   136,   340,   135,   133,   135,   135,   133,
     138,   138,   133,   134,   142,   135,   382,    22,    23,   552,
      39,   491,    41,    42,    43,   135,    45,    46,   134,   133,
     134,    50,   565,   399,   140,   141,   251,   134,    28,   266,
     134,    73,   575,   140,   141,   135,   140,   141,   285,   394,
     135,   278,   418,   586,   291,   513,   293,   515,   591,   286,
     275,   276,    79,    80,    81,   535,    83,    84,    85,    86,
     135,    88,   135,    90,    91,   126,   135,    94,    95,    96,
      97,    98,   133,   134,   134,   136,   103,   135,   134,    74,
      75,   126,   127,   128,   140,   141,   133,   134,   134,   134,
     137,   136,   135,   122,   123,   122,   123,   577,   143,   144,
     135,   135,   135,   138,   138,   138,     8,   142,   142,   142,
     137,   133,   134,   133,   134,   362,   363,   364,   365,   118,
     119,    47,    48,   135,   371,   372,    59,    60,     1,    67,
      68,   356,     5,   135,    24,   133,   133,   384,   139,   133,
     133,   137,    99,    16,   133,    62,   137,    20,    21,   139,
     478,   479,   135,    26,   125,    28,   137,   137,    21,    32,
      33,    34,    35,    36,    37,    38,    26,    40,   133,   133,
     137,   426,   134,   134,   137,   133,   552,   133,    51,    52,
     134,    54,    55,    56,    57,    58,   134,   133,   138,   133,
      63,    64,    65,   569,   134,    82,    69,   134,   435,   134,
     447,   133,   133,   133,   133,    22,    94,     9,    22,   133,
     138,   138,   134,   138,     0,     1,   137,     3,     4,     5,
     467,     7,   469,     9,    10,    11,    99,   137,    14,   134,
     134,   104,   135,   134,    20,   134,   134,   134,   134,    25,
     134,    27,    28,    29,   117,   134,     8,   133,   133,   133,
     133,    66,   134,   134,   134,   133,   133,   512,    44,   133,
     133,   133,   135,    93,    35,   138,   135,   135,   133,   133,
      42,   138,    58,   135,    92,    61,   134,    63,    64,   138,
     134,   133,   133,   133,    70,    71,    72,    94,   134,   138,
     138,   138,   134,   138,   138,   138,   134,   134,   133,   133,
     133,   133,    88,    89,    90,   134,   134,    93,   563,   135,
     133,     5,   133,   133,    39,    52,   135,   103,   104,   120,
      49,   134,    16,   133,   135,   134,    20,    21,   134,   134,
     116,   135,    26,   588,   133,   138,   133,   133,    32,    33,
      34,    35,    36,    37,    38,   600,    40,   133,   133,   135,
     133,   138,   134,   132,   138,   133,   133,    51,    52,   134,
      54,    55,    56,    57,    58,   138,   133,   133,   347,    63,
      64,    65,    54,     1,   555,    69,   342,   387,   461,   245,
     207,   600,   282,   262,   563,   602,   480,   442,    54,   573,
      -1,   533,    -1,    -1,    -1,   176,    -1,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    79,    80,    81,    -1,    -1,   100,   101,
     102,   103,    -1,   117,    -1,    -1,   108,   109,   110,   111,
     112,   113,    54,    -1,   100,   101,   102,   103,    -1,   133,
      -1,   135,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,    -1,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   146,     0,     1,     3,     4,     5,     7,     9,    10,
      11,    14,    20,    25,    27,    29,    44,    58,    61,    63,
      64,    70,    71,    72,    88,    89,    90,    93,   103,   104,
     116,   133,   135,   152,   153,   154,   157,   161,   163,   167,
     171,   172,   176,   177,   184,   188,   189,   191,   205,   206,
     135,   133,   134,   147,   148,   133,   180,     6,   134,     8,
     133,   151,   134,   134,   133,    21,    22,   101,   133,   180,
     133,   150,    88,   122,   123,   133,   134,   181,   200,   134,
      21,   133,   133,   133,   151,   133,   137,   133,   133,   124,
      93,   133,   136,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,    28,   135,   135,    73,   207,   147,
     134,   180,     8,   133,   133,    24,    22,    23,   168,   133,
     192,   133,   139,   139,    99,   231,    77,    78,   112,   114,
     202,   133,    59,    60,   133,   178,    62,   179,   137,   135,
     239,   137,   137,   125,   151,   150,   133,   180,   181,   182,
      21,   209,    26,   133,   173,   133,   137,   137,   231,   134,
     134,    54,    79,    80,    81,   100,   101,   102,   103,   108,
     109,   110,   111,   112,   113,   137,   233,   236,   133,   134,
     231,   133,   134,   183,   133,   239,   239,   138,   162,   239,
     239,   133,   190,   133,   137,   211,    74,    75,   208,   134,
     185,     9,    11,   151,   174,   175,   239,   193,    82,   234,
     134,   140,   141,   134,   140,   141,   134,   140,   141,   104,
     105,   106,   107,   180,   134,   134,   133,   134,   140,   141,
     133,   133,   237,   239,   234,   231,   231,   133,   183,   138,
     158,   160,   166,   181,   138,   164,   138,   155,   137,   196,
     239,     3,    27,    30,    31,    76,   137,   180,   212,   214,
     137,   151,   134,    22,    26,    34,    35,   169,   170,     1,
       5,    16,    20,    21,    26,    32,    33,    34,    35,    36,
      37,    38,    40,    51,    52,    54,    55,    56,    57,    58,
      63,    64,    65,    69,    99,   104,   117,   135,   138,   151,
     176,   188,   198,    91,   133,   134,   134,   134,   134,   134,
     134,   134,   134,   232,   236,   133,   183,   159,   160,    94,
     135,   142,   239,   240,    87,   130,   131,   229,   166,   133,
     147,   149,   156,   135,   198,   210,   211,   148,   133,   239,
     225,   226,   186,   175,   134,   133,   180,   239,   135,     6,
     134,    12,    19,    22,   133,   134,   148,   148,   150,   180,
     134,   134,    39,    41,    42,    43,    45,    46,    50,   200,
     133,    32,    53,   151,   180,     8,   133,   133,   133,   151,
      66,   151,   137,   236,    93,   118,   119,   203,    35,   135,
     135,   133,   133,   239,   240,   239,   240,   149,   239,   135,
     138,   160,   126,   127,   128,   134,   136,   143,   144,   241,
     134,   239,   239,   240,   197,   138,   239,   240,   213,   214,
     231,     3,    80,    83,    84,    85,    86,    88,    90,    91,
      94,    95,    96,    97,    98,   103,   122,   123,   137,   215,
     219,   221,   227,   228,   230,   233,     1,     9,    15,    17,
      18,   135,   138,   177,   187,   138,   170,   134,   133,   147,
      39,    60,   199,   151,   151,   151,   151,    42,    47,    48,
     133,    12,    13,    14,   201,   151,   151,   133,    67,    68,
     239,   151,   121,   178,   138,   236,   138,   160,    92,   165,
     239,    94,   129,   141,   243,   134,   138,   138,   149,     1,
     135,   138,   198,   138,   211,   239,   240,    91,   133,   134,
     134,   134,   137,   181,   218,   133,   133,   133,   238,   134,
     134,    28,   180,   229,   229,   220,   221,   228,    53,    93,
     126,   136,   137,   149,   224,   242,   133,   135,   151,   133,
     133,   133,   135,   134,   199,   151,   133,   151,    52,   235,
     150,   150,   232,   120,   134,   149,   134,   135,   135,   138,
     214,   133,   133,   137,   216,   217,   218,   229,   229,   135,
     138,   240,   133,   137,   222,   223,   224,   243,   149,   133,
     133,    49,   194,   239,   134,   165,   217,   138,   240,   239,
     221,   223,   138,   240,   149,   134,   132,   195,   138,   133,
     138,   218,   138,   224,   134,   133,   216,   222,   133,   204,
     133
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   145,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   147,   148,
     148,   149,   149,   150,   150,   151,   152,   153,   155,   154,
     154,   156,   156,   158,   157,   157,   159,   159,   160,   162,
     161,   161,   164,   163,   163,   165,   165,   166,   166,   167,
     168,   167,   169,   169,   170,   170,   170,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   173,   172,   174,   174,   174,   175,   175,   176,   177,
     177,   177,   177,   177,   178,   178,   179,   179,   180,   181,
     181,   182,   182,   183,   183,   185,   184,   186,   186,   186,
     186,   187,   187,   187,   187,   187,   189,   190,   188,   192,
     191,   193,   193,   193,   193,   193,   194,   194,   195,   195,
     196,   196,   196,   197,   197,   197,   197,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   199,   199,   200,   200,   201,   201,   201,
     202,   202,   203,   203,   204,   204,   205,   206,   206,   206,
     207,   207,   208,   208,   209,   209,   209,   210,   210,   211,
     212,   212,   213,   213,   214,   214,   214,   214,   214,   214,
     215,   215,   215,   215,   216,   216,   216,   217,   217,   218,
     219,   219,   220,   220,   221,   221,   221,   222,   222,   222,
     223,   223,   224,   224,   224,   224,   225,   226,   225,   227,
     227,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   229,   229,   229,   229,
     229,   230,   230,   230,   230,   231,   231,   231,   232,   232,
     233,   233,   234,   234,   235,   235,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   237,   238,   239,   239,   240,   240,   240,   240,
     241,   241,   241,   241,   241,   241,   242,   242,   243,   243
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
       6,     0,     2,     3,     3,     3,     0,     2,     0,     2,
       4,     3,     0,     0,     2,     3,     3,     2,     2,     3,
       2,     2,     2,     2,     1,     1,     2,     2,     2,     3,
       3,     3,     3,     4,     3,     3,     4,     6,     4,     2,
       2,     3,     3,     2,     3,     4,     4,     4,     3,     8,
       2,     2,     6,     1,     1,     2,     3,     2,     2,     2,
       3,     2,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     7,     1,     1,     1,
       0,     1,     1,     1,     0,     2,     6,     1,     3,     1,
       1,     5,     1,     3,     1,     1,     2,     2,     1,     1,
       2,     2,     2,     4,     1,     3,     4,     1,     3,     2,
       1,     3,     1,     3,     2,     4,     3,     1,     3,     4,
       1,     3,     1,     1,     2,     3,     0,     0,     2,     1,
       2,     1,     1,     2,     2,     2,     3,     3,     2,     2,
       2,     2,     2,     3,     2,     2,     0,     1,     2,     3,
       4,     1,     1,     1,     1,     0,     2,     6,     3,     1,
       1,     1,     0,     1,     0,     1,     2,     3,     3,     2,
       3,     3,     2,     3,     3,     2,     3,     3,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     3,     4,
       4,     2,     1,     1,     0,     2,     0,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 274 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { file->errors++; }
#line 2281 "parse.c"
    break;

  case 18: /* asnumber: NUMBER  */
#line 277 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2296 "parse.c"
    break;

  case 19: /* as4number: STRING  */
#line 288 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2333 "parse.c"
    break;

  case 20: /* as4number: asnumber  */
#line 320 "../../../openbgpd-portable/src/bgpd/parse.y"
                           {
			if ((yyvsp[0].v.number) == AS_TRANS || (yyvsp[0].v.number) == 0) {
				yyerror("AS %u is reserved and may not be used",
				    (uint32_t)(yyvsp[0].v.number));
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2346 "parse.c"
    break;

  case 21: /* as4number_any: STRING  */
#line 330 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2378 "parse.c"
    break;

  case 22: /* as4number_any: asnumber  */
#line 357 "../../../openbgpd-portable/src/bgpd/parse.y"
                           {
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2386 "parse.c"
    break;

  case 23: /* string: string STRING  */
#line 362 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (asprintf(&(yyval.v.string), "%s %s", (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1)
				fatal("string: asprintf");
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.string));
		}
#line 2397 "parse.c"
    break;

  case 25: /* yesno: STRING  */
#line 371 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2415 "parse.c"
    break;

  case 26: /* varset: STRING '=' string  */
#line 386 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2446 "parse.c"
    break;

  case 27: /* include: INCLUDE STRING  */
#line 414 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2464 "parse.c"
    break;

  case 28: /* $@1: %empty  */
#line 429 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2481 "parse.c"
    break;

  case 29: /* as_set: ASSET STRING '{' optnl $@1 as_set_l optnl '}'  */
#line 440 "../../../openbgpd-portable/src/bgpd/parse.y"
                                     {
			done_as_set();
		}
#line 2489 "parse.c"
    break;

  case 30: /* as_set: ASSET STRING '{' optnl '}'  */
#line 443 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (new_as_set((yyvsp[-3].v.string)) != 0) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
		}
#line 2501 "parse.c"
    break;

  case 31: /* as_set_l: as4number_any  */
#line 451 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { add_as_set((yyvsp[0].v.number)); }
#line 2507 "parse.c"
    break;

  case 32: /* as_set_l: as_set_l comma as4number_any  */
#line 452 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { add_as_set((yyvsp[0].v.number)); }
#line 2513 "parse.c"
    break;

  case 33: /* $@2: %empty  */
#line 454 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curpset = new_prefix_set((yyvsp[-2].v.string), 0)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			free((yyvsp[-2].v.string));
		}
#line 2525 "parse.c"
    break;

  case 34: /* prefixset: PREFIXSET STRING '{' optnl $@2 prefixset_l optnl '}'  */
#line 460 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2534 "parse.c"
    break;

  case 35: /* prefixset: PREFIXSET STRING '{' optnl '}'  */
#line 464 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curpset = new_prefix_set((yyvsp[-3].v.string), 0)) == NULL) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2548 "parse.c"
    break;

  case 36: /* prefixset_l: prefixset_item  */
#line 474 "../../../openbgpd-portable/src/bgpd/parse.y"
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

  case 37: /* prefixset_l: prefixset_l comma prefixset_item  */
#line 488 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2586 "parse.c"
    break;

  case 38: /* prefixset_item: prefix prefixlenop  */
#line 504 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2606 "parse.c"
    break;

  case 39: /* $@3: %empty  */
#line 521 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			curroatree = &conf->roa;
			noexpires = 0;
		}
#line 2615 "parse.c"
    break;

  case 40: /* roa_set: ROASET '{' optnl $@3 roa_set_l optnl '}'  */
#line 524 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			curroatree = NULL;
			noexpires = 1;
		}
#line 2624 "parse.c"
    break;

  case 42: /* $@4: %empty  */
#line 531 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curoset = new_prefix_set((yyvsp[-2].v.string), 1)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			curroatree = &curoset->roaitems;
			noexpires = 1;
			free((yyvsp[-2].v.string));
		}
#line 2638 "parse.c"
    break;

  case 43: /* origin_set: ORIGINSET STRING '{' optnl $@4 roa_set_l optnl '}'  */
#line 539 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			SIMPLEQ_INSERT_TAIL(&conf->originsets, curoset, entry);
			curoset = NULL;
			curroatree = NULL;
		}
#line 2648 "parse.c"
    break;

  case 44: /* origin_set: ORIGINSET STRING '{' optnl '}'  */
#line 544 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2663 "parse.c"
    break;

  case 45: /* expires: %empty  */
#line 556 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			(yyval.v.number) = 0;
		}
#line 2671 "parse.c"
    break;

  case 46: /* expires: EXPIRES NUMBER  */
#line 559 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (noexpires) {
				yyerror("syntax error, expires not allowed");
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2683 "parse.c"
    break;

  case 47: /* roa_set_l: prefixset_item SOURCEAS as4number_any expires  */
#line 567 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2698 "parse.c"
    break;

  case 48: /* roa_set_l: roa_set_l comma prefixset_item SOURCEAS as4number_any expires  */
#line 577 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2713 "parse.c"
    break;

  case 49: /* rtr: RTR address  */
#line 589 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = RTR_PORT;
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2727 "parse.c"
    break;

  case 50: /* $@5: %empty  */
#line 598 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = RTR_PORT;
		}
#line 2736 "parse.c"
    break;

  case 51: /* rtr: RTR address $@5 '{' optnl rtropt_l optnl '}'  */
#line 601 "../../../openbgpd-portable/src/bgpd/parse.y"
                                               {
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2748 "parse.c"
    break;

  case 54: /* rtropt: DESCR STRING  */
#line 613 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2764 "parse.c"
    break;

  case 55: /* rtropt: LOCALADDR address  */
#line 624 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.addr).aid != currtr->remote_addr.aid) {
				yyerror("Bad address family %s for "
				    "local-addr", aid2str((yyvsp[0].v.addr).aid));
				YYERROR;
			}
			currtr->local_addr = (yyvsp[0].v.addr);
		}
#line 2777 "parse.c"
    break;

  case 56: /* rtropt: PORT NUMBER  */
#line 632 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("port must be between %u and %u",
				    1, USHRT_MAX);
				YYERROR;
			}
			currtr->remote_port = (yyvsp[0].v.number);
		}
#line 2790 "parse.c"
    break;

  case 57: /* conf_main: AS as4number  */
#line 642 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			conf->as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				conf->short_as = AS_TRANS;
			else
				conf->short_as = (yyvsp[0].v.number);
		}
#line 2802 "parse.c"
    break;

  case 58: /* conf_main: AS as4number asnumber  */
#line 649 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			conf->as = (yyvsp[-1].v.number);
			conf->short_as = (yyvsp[0].v.number);
		}
#line 2811 "parse.c"
    break;

  case 59: /* conf_main: ROUTERID address  */
#line 653 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.addr).aid != AID_INET) {
				yyerror("router-id must be an IPv4 address");
				YYERROR;
			}
			conf->bgpid = (yyvsp[0].v.addr).v4.s_addr;
		}
#line 2823 "parse.c"
    break;

  case 60: /* conf_main: HOLDTIME NUMBER  */
#line 660 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->holdtime = (yyvsp[0].v.number);
		}
#line 2836 "parse.c"
    break;

  case 61: /* conf_main: HOLDTIME YMIN NUMBER  */
#line 668 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->min_holdtime = (yyvsp[0].v.number);
		}
#line 2849 "parse.c"
    break;

  case 62: /* conf_main: LISTEN ON address  */
#line 676 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2868 "parse.c"
    break;

  case 63: /* conf_main: LISTEN ON address PORT NUMBER  */
#line 690 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2893 "parse.c"
    break;

  case 64: /* conf_main: FIBPRIORITY NUMBER  */
#line 710 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (!kr_check_prio((yyvsp[0].v.number))) {
				yyerror("fib-priority %lld out of range", (yyvsp[0].v.number));
				YYERROR;
			}
			conf->fib_priority = (yyvsp[0].v.number);
		}
#line 2905 "parse.c"
    break;

  case 65: /* conf_main: FIBUPDATE yesno  */
#line 717 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			struct rde_rib *rr;
			rr = find_rib("Loc-RIB");
			if (rr == NULL)
				fatalx("RTABLE cannot find the main RIB!");

			if ((yyvsp[0].v.number) == 0)
				rr->flags |= F_RIB_NOFIBSYNC;
			else
				rr->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 2921 "parse.c"
    break;

  case 66: /* conf_main: TRANSPARENT yesno  */
#line 728 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_DECISION_TRANS_AS;
			else
				conf->flags &= ~BGPD_FLAG_DECISION_TRANS_AS;
		}
#line 2932 "parse.c"
    break;

  case 67: /* conf_main: REJECT ASSET yesno  */
#line 734 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_NO_AS_SET;
			else
				conf->flags &= ~BGPD_FLAG_NO_AS_SET;
		}
#line 2943 "parse.c"
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
#line 2957 "parse.c"
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
#line 2990 "parse.c"
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
#line 3027 "parse.c"
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
#line 3042 "parse.c"
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
#line 3057 "parse.c"
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
#line 3075 "parse.c"
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
#line 3093 "parse.c"
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
#line 3111 "parse.c"
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
				fatalx("RTABLE cannot find the main RIB!");
			rr->rtableid = (yyvsp[0].v.number);
		}
#line 3132 "parse.c"
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
#line 3144 "parse.c"
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
#line 3163 "parse.c"
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
#line 3175 "parse.c"
    break;

  case 82: /* rib: RDE RIB STRING $@6 ribopts  */
#line 915 "../../../openbgpd-portable/src/bgpd/parse.y"
                          {
			currib = NULL;
		}
#line 3183 "parse.c"
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
#line 3197 "parse.c"
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
#line 3209 "parse.c"
    break;

  case 87: /* fibupdate: FIBUPDATE yesno  */
#line 939 "../../../openbgpd-portable/src/bgpd/parse.y"
                                  {
			if ((yyvsp[0].v.number) == 0)
				currib->flags |= F_RIB_NOFIBSYNC;
			else
				currib->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3220 "parse.c"
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
#line 3253 "parse.c"
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
#line 3279 "parse.c"
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
#line 3313 "parse.c"
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
#line 3337 "parse.c"
    break;

  case 92: /* network: NETWORK family PRIORITY NUMBER filter_set  */
#line 1046 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			struct network	*n;
			if (!kr_check_prio((yyvsp[-1].v.number))) {
				yyerror("priority %lld out of range", (yyvsp[-1].v.number));
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
#line 3365 "parse.c"
    break;

  case 93: /* network: NETWORK family nettype filter_set  */
#line 1069 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3388 "parse.c"
    break;

  case 94: /* inout: IN  */
#line 1089 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 3394 "parse.c"
    break;

  case 95: /* inout: OUT  */
#line 1090 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 3400 "parse.c"
    break;

  case 96: /* restricted: RESTRICTED  */
#line 1093 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 3406 "parse.c"
    break;

  case 97: /* restricted: %empty  */
#line 1094 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 3412 "parse.c"
    break;

  case 98: /* address: STRING  */
#line 1097 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3436 "parse.c"
    break;

  case 99: /* prefix: STRING '/' NUMBER  */
#line 1118 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3459 "parse.c"
    break;

  case 100: /* prefix: NUMBER '/' NUMBER  */
#line 1136 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3482 "parse.c"
    break;

  case 101: /* addrspec: address  */
#line 1156 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			memcpy(&(yyval.v.prefix).prefix, &(yyvsp[0].v.addr), sizeof(struct bgpd_addr));
			if ((yyval.v.prefix).prefix.aid == AID_INET)
				(yyval.v.prefix).len = 32;
			else
				(yyval.v.prefix).len = 128;
		}
#line 3494 "parse.c"
    break;

  case 103: /* optnumber: %empty  */
#line 1166 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0; }
#line 3500 "parse.c"
    break;

  case 105: /* $@7: %empty  */
#line 1170 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3543 "parse.c"
    break;

  case 106: /* l3vpn: VPN STRING ON STRING $@7 '{' l3vpnopts_l '}'  */
#line 1207 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			/* insert into list */
			SIMPLEQ_INSERT_TAIL(&conf->l3vpns, curvpn, entry);
			curvpn = NULL;
			netconf = &conf->networks;
		}
#line 3554 "parse.c"
    break;

  case 111: /* l3vpnopts: RD STRING  */
#line 1221 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3577 "parse.c"
    break;

  case 112: /* l3vpnopts: EXPORTTRGT STRING STRING  */
#line 1239 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3600 "parse.c"
    break;

  case 113: /* l3vpnopts: IMPORTTRGT STRING STRING  */
#line 1257 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3623 "parse.c"
    break;

  case 114: /* l3vpnopts: FIBUPDATE yesno  */
#line 1275 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) == 0)
				curvpn->flags |= F_RIB_NOFIBSYNC;
			else
				curvpn->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3634 "parse.c"
    break;

  case 116: /* $@8: %empty  */
#line 1284 "../../../openbgpd-portable/src/bgpd/parse.y"
                  {	curpeer = new_peer(); }
#line 3640 "parse.c"
    break;

  case 117: /* $@9: %empty  */
#line 1285 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3659 "parse.c"
    break;

  case 118: /* neighbor: $@8 NEIGHBOR addrspec $@9 peeropts_h  */
#line 1299 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3682 "parse.c"
    break;

  case 119: /* $@10: %empty  */
#line 1319 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3705 "parse.c"
    break;

  case 120: /* group: GROUP string $@10 '{' groupopts_l '}'  */
#line 1336 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3723 "parse.c"
    break;

  case 126: /* addpathextra: %empty  */
#line 1358 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0;	}
#line 3729 "parse.c"
    break;

  case 127: /* addpathextra: PLUS NUMBER  */
#line 1359 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("additional paths must be between "
				    "%u and %u", 1, USHRT_MAX);
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 3742 "parse.c"
    break;

  case 128: /* addpathmax: %empty  */
#line 1369 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0;	}
#line 3748 "parse.c"
    break;

  case 129: /* addpathmax: MAX NUMBER  */
#line 1370 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("maximum additional paths must be "
				    "between %u and %u", 1, USHRT_MAX);
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 3761 "parse.c"
    break;

  case 137: /* peeropts: REMOTEAS as4number  */
#line 1391 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.remote_as = (yyvsp[0].v.number);
		}
#line 3769 "parse.c"
    break;

  case 138: /* peeropts: LOCALAS as4number  */
#line 1394 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.local_as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				curpeer->conf.local_short_as = AS_TRANS;
			else
				curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3781 "parse.c"
    break;

  case 139: /* peeropts: LOCALAS as4number asnumber  */
#line 1401 "../../../openbgpd-portable/src/bgpd/parse.y"
                                             {
			curpeer->conf.local_as = (yyvsp[-1].v.number);
			curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3790 "parse.c"
    break;

  case 140: /* peeropts: DESCR string  */
#line 1405 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3806 "parse.c"
    break;

  case 141: /* peeropts: LOCALADDR address  */
#line 1416 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3824 "parse.c"
    break;

  case 142: /* peeropts: yesno LOCALADDR  */
#line 1429 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3839 "parse.c"
    break;

  case 143: /* peeropts: MULTIHOP NUMBER  */
#line 1439 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 2 || (yyvsp[0].v.number) > 255) {
				yyerror("invalid multihop distance %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			curpeer->conf.distance = (yyvsp[0].v.number);
		}
#line 3851 "parse.c"
    break;

  case 144: /* peeropts: PASSIVE  */
#line 1446 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.passive = 1;
		}
#line 3859 "parse.c"
    break;

  case 145: /* peeropts: DOWN  */
#line 1449 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.down = 1;
		}
#line 3867 "parse.c"
    break;

  case 146: /* peeropts: DOWN STRING  */
#line 1452 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3883 "parse.c"
    break;

  case 147: /* peeropts: RIB STRING  */
#line 1463 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3904 "parse.c"
    break;

  case 148: /* peeropts: HOLDTIME NUMBER  */
#line 1479 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.holdtime = (yyvsp[0].v.number);
		}
#line 3917 "parse.c"
    break;

  case 149: /* peeropts: HOLDTIME YMIN NUMBER  */
#line 1487 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.min_holdtime = (yyvsp[0].v.number);
		}
#line 3930 "parse.c"
    break;

  case 150: /* peeropts: ANNOUNCE family safi  */
#line 1495 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3954 "parse.c"
    break;

  case 151: /* peeropts: ANNOUNCE CAPABILITIES yesno  */
#line 1514 "../../../openbgpd-portable/src/bgpd/parse.y"
                                              {
			curpeer->conf.announce_capa = (yyvsp[0].v.number);
		}
#line 3962 "parse.c"
    break;

  case 152: /* peeropts: ANNOUNCE REFRESH yesno  */
#line 1517 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.refresh = (yyvsp[0].v.number);
		}
#line 3970 "parse.c"
    break;

  case 153: /* peeropts: ANNOUNCE ENHANCED REFRESH yesno  */
#line 1520 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                  {
			curpeer->conf.capabilities.enhanced_rr = (yyvsp[0].v.number);
		}
#line 3978 "parse.c"
    break;

  case 154: /* peeropts: ANNOUNCE RESTART yesno  */
#line 1523 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.grestart.restart = (yyvsp[0].v.number);
		}
#line 3986 "parse.c"
    break;

  case 155: /* peeropts: ANNOUNCE AS4BYTE yesno  */
#line 1526 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.as4byte = (yyvsp[0].v.number);
		}
#line 3994 "parse.c"
    break;

  case 156: /* peeropts: ANNOUNCE ADDPATH RECV yesno  */
#line 1529 "../../../openbgpd-portable/src/bgpd/parse.y"
                                              {
			int8_t *ap = curpeer->conf.capabilities.add_path;
			uint8_t i;

			for (i = 0; i < AID_MAX; i++)
				if ((yyvsp[0].v.number))
					*ap++ |= CAPA_AP_RECV;
				else
					*ap++ &= ~CAPA_AP_RECV;
		}
#line 4009 "parse.c"
    break;

  case 157: /* peeropts: ANNOUNCE ADDPATH SEND STRING addpathextra addpathmax  */
#line 1539 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                       {
			int8_t *ap = curpeer->conf.capabilities.add_path;
			enum addpath_mode mode;
			u_int8_t i;

			if (!strcmp((yyvsp[-2].v.string), "no")) {
				free((yyvsp[-2].v.string));
				if ((yyvsp[-1].v.number) != 0 || (yyvsp[0].v.number) != 0) {
					yyerror("no additional option allowed "
					    "for 'add-path send no'");
					YYERROR;
				}
				for (i = 0; i < AID_MAX; i++)
					*ap++ &= ~CAPA_AP_SEND;
				break;
			} else if (!strcmp((yyvsp[-2].v.string), "all")) {
				free((yyvsp[-2].v.string));
				if ((yyvsp[-1].v.number) != 0 || (yyvsp[0].v.number) != 0) {
					yyerror("no additional option allowed "
					    "for 'add-path send all'");
					YYERROR;
				}
				mode = ADDPATH_EVAL_ALL;
			} else if (!strcmp((yyvsp[-2].v.string), "best")) {
				free((yyvsp[-2].v.string));
				mode = ADDPATH_EVAL_BEST;
			} else if (!strcmp((yyvsp[-2].v.string), "ecmp")) {
				free((yyvsp[-2].v.string));
				mode = ADDPATH_EVAL_ECMP;
			} else if (!strcmp((yyvsp[-2].v.string), "as-wide-best")) {
				free((yyvsp[-2].v.string));
				mode = ADDPATH_EVAL_AS_WIDE;
			} else {
				yyerror("announce add-path send: "
				    "unknown mode \"%s\"", (yyvsp[-2].v.string));
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			for (i = 0; i < AID_MAX; i++)
				*ap++ |= CAPA_AP_SEND;
			curpeer->conf.eval.mode = mode;
			curpeer->conf.eval.extrapaths = (yyvsp[-1].v.number);
			curpeer->conf.eval.maxpaths = (yyvsp[0].v.number);
		}
#line 4058 "parse.c"
    break;

  case 158: /* peeropts: ANNOUNCE POLICY STRING enforce  */
#line 1583 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                 {
			curpeer->conf.capabilities.role_ena = (yyvsp[0].v.number);
			if (strcmp((yyvsp[-1].v.string), "no") == 0) {
				curpeer->conf.capabilities.role_ena = 0;
			} else if (strcmp((yyvsp[-1].v.string), "provider") == 0) {
				curpeer->conf.capabilities.role =
				    CAPA_ROLE_PROVIDER;
			} else if (strcmp((yyvsp[-1].v.string), "rs") == 0) {
				curpeer->conf.capabilities.role =
				    CAPA_ROLE_RS;
			} else if (strcmp((yyvsp[-1].v.string), "rs-client") == 0) {
				curpeer->conf.capabilities.role =
				    CAPA_ROLE_RS_CLIENT;
			} else if (strcmp((yyvsp[-1].v.string), "customer") == 0) {
				curpeer->conf.capabilities.role =
				    CAPA_ROLE_CUSTOMER;
			} else if (strcmp((yyvsp[-1].v.string), "peer") == 0) {
				curpeer->conf.capabilities.role =
				    CAPA_ROLE_PEER;
			} else {
				yyerror("syntax error, one of no, provider, "
				    "rs, rs-client, customer, peer expected");
				free((yyvsp[-1].v.string));
				YYERROR;
			}
			free((yyvsp[-1].v.string));
		}
#line 4090 "parse.c"
    break;

  case 159: /* peeropts: EXPORT NONE  */
#line 1610 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			curpeer->conf.export_type = EXPORT_NONE;
		}
#line 4098 "parse.c"
    break;

  case 160: /* peeropts: EXPORT DEFAULTROUTE  */
#line 1613 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			curpeer->conf.export_type = EXPORT_DEFAULT_ROUTE;
		}
#line 4106 "parse.c"
    break;

  case 161: /* peeropts: ENFORCE NEIGHBORAS yesno  */
#line 1616 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_as = ENFORCE_AS_OFF;
		}
#line 4117 "parse.c"
    break;

  case 162: /* peeropts: ENFORCE LOCALAS yesno  */
#line 1622 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_local_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_local_as = ENFORCE_AS_OFF;
		}
#line 4128 "parse.c"
    break;

  case 163: /* peeropts: ASOVERRIDE yesno  */
#line 1628 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4148 "parse.c"
    break;

  case 164: /* peeropts: MAXPREFIX NUMBER restart  */
#line 1643 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if ((yyvsp[-1].v.number) < 0 || (yyvsp[-1].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_prefix = (yyvsp[-1].v.number);
			curpeer->conf.max_prefix_restart = (yyvsp[0].v.number);
		}
#line 4161 "parse.c"
    break;

  case 165: /* peeropts: MAXPREFIX NUMBER OUT restart  */
#line 1651 "../../../openbgpd-portable/src/bgpd/parse.y"
                                               {
			if ((yyvsp[-2].v.number) < 0 || (yyvsp[-2].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_out_prefix = (yyvsp[-2].v.number);
			curpeer->conf.max_out_prefix_restart = (yyvsp[0].v.number);
		}
#line 4174 "parse.c"
    break;

  case 166: /* peeropts: TCP MD5SIG PASSWORD string  */
#line 1659 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4197 "parse.c"
    break;

  case 167: /* peeropts: TCP MD5SIG KEY string  */
#line 1677 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4218 "parse.c"
    break;

  case 168: /* peeropts: IPSEC espah IKE  */
#line 1693 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4233 "parse.c"
    break;

  case 169: /* peeropts: IPSEC espah inout SPI NUMBER STRING STRING encspec  */
#line 1703 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                     {
			enum auth_alg	auth_alg;
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
				auth_alg = AUTH_AALG_SHA1HMAC;
				keylen = 20;
			} else if (!strcmp((yyvsp[-2].v.string), "md5")) {
				auth_alg = AUTH_AALG_MD5HMAC;
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
#line 4331 "parse.c"
    break;

  case 170: /* peeropts: TTLSECURITY yesno  */
#line 1796 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.ttlsec = (yyvsp[0].v.number);
		}
#line 4339 "parse.c"
    break;

  case 171: /* peeropts: SET filter_set_opt  */
#line 1799 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			struct filter_rule	*r;

			r = get_rule((yyvsp[0].v.filter_set)->type);
			if (merge_filterset(&r->set, (yyvsp[0].v.filter_set)) == -1)
				YYERROR;
		}
#line 4351 "parse.c"
    break;

  case 172: /* peeropts: SET '{' optnl filter_set_l optnl '}'  */
#line 1806 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4368 "parse.c"
    break;

  case 174: /* peeropts: REFLECTOR  */
#line 1819 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4383 "parse.c"
    break;

  case 175: /* peeropts: REFLECTOR address  */
#line 1829 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4404 "parse.c"
    break;

  case 176: /* peeropts: DEPEND ON STRING  */
#line 1845 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4421 "parse.c"
    break;

  case 177: /* peeropts: DEMOTE STRING  */
#line 1857 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4450 "parse.c"
    break;

  case 178: /* peeropts: TRANSPARENT yesno  */
#line 1881 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_TRANS_AS;
			else
				curpeer->conf.flags &= ~PEERFLAG_TRANS_AS;
		}
#line 4461 "parse.c"
    break;

  case 179: /* peeropts: LOG STRING  */
#line 1887 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4477 "parse.c"
    break;

  case 180: /* peeropts: REJECT ASSET yesno  */
#line 1898 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_NO_AS_SET;
			else
				curpeer->conf.flags &= ~PEERFLAG_NO_AS_SET;
		}
#line 4488 "parse.c"
    break;

  case 181: /* peeropts: PORT NUMBER  */
#line 1904 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("port must be between %u and %u",
				    1, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.remote_port = (yyvsp[0].v.number);
		}
#line 4501 "parse.c"
    break;

  case 182: /* peeropts: RDE EVALUATE STRING  */
#line 1912 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4519 "parse.c"
    break;

  case 183: /* restart: %empty  */
#line 1927 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0; }
#line 4525 "parse.c"
    break;

  case 184: /* restart: RESTART NUMBER  */
#line 1928 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("restart out of range. 1 to %u minutes",
				    USHRT_MAX);
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 4538 "parse.c"
    break;

  case 185: /* family: IPV4  */
#line 1938 "../../../openbgpd-portable/src/bgpd/parse.y"
                        { (yyval.v.number) = AFI_IPv4; }
#line 4544 "parse.c"
    break;

  case 186: /* family: IPV6  */
#line 1939 "../../../openbgpd-portable/src/bgpd/parse.y"
                        { (yyval.v.number) = AFI_IPv6; }
#line 4550 "parse.c"
    break;

  case 187: /* safi: NONE  */
#line 1942 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_NONE; }
#line 4556 "parse.c"
    break;

  case 188: /* safi: UNICAST  */
#line 1943 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_UNICAST; }
#line 4562 "parse.c"
    break;

  case 189: /* safi: VPN  */
#line 1944 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_MPLSVPN; }
#line 4568 "parse.c"
    break;

  case 190: /* nettype: STATIC  */
#line 1947 "../../../openbgpd-portable/src/bgpd/parse.y"
                         { (yyval.v.number) = 1; }
#line 4574 "parse.c"
    break;

  case 191: /* nettype: CONNECTED  */
#line 1948 "../../../openbgpd-portable/src/bgpd/parse.y"
                            { (yyval.v.number) = 0; }
#line 4580 "parse.c"
    break;

  case 192: /* espah: ESP  */
#line 1951 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 4586 "parse.c"
    break;

  case 193: /* espah: AH  */
#line 1952 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 4592 "parse.c"
    break;

  case 194: /* encspec: %empty  */
#line 1955 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			memset(&(yyval.v.encspec), 0, sizeof((yyval.v.encspec)));
		}
#line 4600 "parse.c"
    break;

  case 195: /* encspec: STRING STRING  */
#line 1958 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			memset(&(yyval.v.encspec), 0, sizeof((yyval.v.encspec)));
			if (!strcmp((yyvsp[-1].v.string), "3des") || !strcmp((yyvsp[-1].v.string), "3des-cbc")) {
				(yyval.v.encspec).enc_alg = AUTH_EALG_3DESCBC;
				(yyval.v.encspec).enc_key_len = 21; /* XXX verify */
			} else if (!strcmp((yyvsp[-1].v.string), "aes") ||
			    !strcmp((yyvsp[-1].v.string), "aes-128-cbc")) {
				(yyval.v.encspec).enc_alg = AUTH_EALG_AES;
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
#line 4636 "parse.c"
    break;

  case 196: /* filterrule: action quick filter_rib_h direction filter_peer_h filter_match_h filter_set  */
#line 1993 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_rule	 r;
			struct filter_rib_l	 *rb, *rbnext;

			memset(&r, 0, sizeof(r));
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
#line 4664 "parse.c"
    break;

  case 197: /* action: ALLOW  */
#line 2018 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_ALLOW; }
#line 4670 "parse.c"
    break;

  case 198: /* action: DENY  */
#line 2019 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_DENY; }
#line 4676 "parse.c"
    break;

  case 199: /* action: MATCH  */
#line 2020 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_NONE; }
#line 4682 "parse.c"
    break;

  case 200: /* quick: %empty  */
#line 2023 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 0; }
#line 4688 "parse.c"
    break;

  case 201: /* quick: QUICK  */
#line 2024 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 1; }
#line 4694 "parse.c"
    break;

  case 202: /* direction: FROM  */
#line 2027 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = DIR_IN; }
#line 4700 "parse.c"
    break;

  case 203: /* direction: TO  */
#line 2028 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = DIR_OUT; }
#line 4706 "parse.c"
    break;

  case 204: /* filter_rib_h: %empty  */
#line 2031 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = NULL; }
#line 4712 "parse.c"
    break;

  case 205: /* filter_rib_h: RIB filter_rib  */
#line 2032 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4718 "parse.c"
    break;

  case 206: /* filter_rib_h: RIB '{' optnl filter_rib_l optnl '}'  */
#line 2033 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_rib) = (yyvsp[-2].v.filter_rib); }
#line 4724 "parse.c"
    break;

  case 207: /* filter_rib_l: filter_rib  */
#line 2035 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4730 "parse.c"
    break;

  case 208: /* filter_rib_l: filter_rib_l comma filter_rib  */
#line 2036 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			(yyvsp[0].v.filter_rib)->next = (yyvsp[-2].v.filter_rib);
			(yyval.v.filter_rib) = (yyvsp[0].v.filter_rib);
		}
#line 4739 "parse.c"
    break;

  case 209: /* filter_rib: STRING  */
#line 2042 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4764 "parse.c"
    break;

  case 211: /* filter_peer_h: '{' optnl filter_peer_l optnl '}'  */
#line 2065 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_peers) = (yyvsp[-2].v.filter_peers); }
#line 4770 "parse.c"
    break;

  case 212: /* filter_peer_l: filter_peer  */
#line 2068 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_peers) = (yyvsp[0].v.filter_peers); }
#line 4776 "parse.c"
    break;

  case 213: /* filter_peer_l: filter_peer_l comma filter_peer  */
#line 2069 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyvsp[0].v.filter_peers)->next = (yyvsp[-2].v.filter_peers);
			(yyval.v.filter_peers) = (yyvsp[0].v.filter_peers);
		}
#line 4785 "parse.c"
    break;

  case 214: /* filter_peer: ANY  */
#line 2075 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.peerid = (yyval.v.filter_peers)->p.groupid = 0;
			(yyval.v.filter_peers)->next = NULL;
		}
#line 4797 "parse.c"
    break;

  case 215: /* filter_peer: address  */
#line 2082 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4822 "parse.c"
    break;

  case 216: /* filter_peer: AS as4number  */
#line 2102 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.groupid = (yyval.v.filter_peers)->p.peerid = 0;
			(yyval.v.filter_peers)->p.remote_as = (yyvsp[0].v.number);
		}
#line 4834 "parse.c"
    break;

  case 217: /* filter_peer: GROUP STRING  */
#line 2109 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4860 "parse.c"
    break;

  case 218: /* filter_peer: EBGP  */
#line 2130 "../../../openbgpd-portable/src/bgpd/parse.y"
                       {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ebgp = 1;
		}
#line 4871 "parse.c"
    break;

  case 219: /* filter_peer: IBGP  */
#line 2136 "../../../openbgpd-portable/src/bgpd/parse.y"
                       {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ibgp = 1;
		}
#line 4882 "parse.c"
    break;

  case 220: /* filter_prefix_h: IPV4 prefixlenop  */
#line 2144 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4902 "parse.c"
    break;

  case 221: /* filter_prefix_h: IPV6 prefixlenop  */
#line 2159 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4922 "parse.c"
    break;

  case 222: /* filter_prefix_h: PREFIX filter_prefix  */
#line 2174 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4928 "parse.c"
    break;

  case 223: /* filter_prefix_h: PREFIX '{' filter_prefix_m '}'  */
#line 2175 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4934 "parse.c"
    break;

  case 225: /* filter_prefix_m: '{' filter_prefix_l '}'  */
#line 2179 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4940 "parse.c"
    break;

  case 226: /* filter_prefix_m: '{' filter_prefix_l '}' filter_prefix_m  */
#line 2181 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_prefix_l	*p;

			/* merge, both can be lists */
			for (p = (yyvsp[-2].v.filter_prefix); p != NULL && p->next != NULL; p = p->next)
				;	/* nothing */
			if (p != NULL)
				p->next = (yyvsp[0].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[-2].v.filter_prefix);
		}
#line 4955 "parse.c"
    break;

  case 227: /* filter_prefix_l: filter_prefix  */
#line 2192 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4961 "parse.c"
    break;

  case 228: /* filter_prefix_l: filter_prefix_l comma filter_prefix  */
#line 2193 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyvsp[0].v.filter_prefix)->next = (yyvsp[-2].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix);
		}
#line 4970 "parse.c"
    break;

  case 229: /* filter_prefix: prefix prefixlenop  */
#line 2199 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4988 "parse.c"
    break;

  case 231: /* filter_as_h: '{' filter_as_t_l '}'  */
#line 2215 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4994 "parse.c"
    break;

  case 233: /* filter_as_t_l: filter_as_t_l comma filter_as_t  */
#line 2219 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 5009 "parse.c"
    break;

  case 234: /* filter_as_t: filter_as_type filter_as  */
#line 2231 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as)->a.type = (yyvsp[-1].v.u8);
		}
#line 5018 "parse.c"
    break;

  case 235: /* filter_as_t: filter_as_type '{' filter_as_l_h '}'  */
#line 2235 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			struct filter_as_l	*a;

			(yyval.v.filter_as) = (yyvsp[-1].v.filter_as);
			for (a = (yyval.v.filter_as); a != NULL; a = a->next)
				a->a.type = (yyvsp[-3].v.u8);
		}
#line 5030 "parse.c"
    break;

  case 236: /* filter_as_t: filter_as_type ASSET STRING  */
#line 2242 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5056 "parse.c"
    break;

  case 238: /* filter_as_l_h: '{' filter_as_l '}'  */
#line 2266 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 5062 "parse.c"
    break;

  case 239: /* filter_as_l_h: '{' filter_as_l '}' filter_as_l_h  */
#line 2268 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 5077 "parse.c"
    break;

  case 241: /* filter_as_l: filter_as_l comma filter_as  */
#line 2281 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			(yyvsp[0].v.filter_as)->next = (yyvsp[-2].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
		}
#line 5086 "parse.c"
    break;

  case 242: /* filter_as: as4number_any  */
#line 2287 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.op = OP_EQ;
		}
#line 5099 "parse.c"
    break;

  case 243: /* filter_as: NEIGHBORAS  */
#line 2295 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.flags = AS_FLAG_NEIGHBORAS;
		}
#line 5110 "parse.c"
    break;

  case 244: /* filter_as: equalityop as4number_any  */
#line 2301 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.op = (yyvsp[-1].v.u8);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
		}
#line 5123 "parse.c"
    break;

  case 245: /* filter_as: as4number_any binaryop as4number_any  */
#line 2309 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5140 "parse.c"
    break;

  case 246: /* filter_match_h: %empty  */
#line 2323 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			memset(&(yyval.v.filter_match), 0, sizeof((yyval.v.filter_match)));
		}
#line 5148 "parse.c"
    break;

  case 247: /* $@11: %empty  */
#line 2326 "../../../openbgpd-portable/src/bgpd/parse.y"
                  {
			memset(&fmopts, 0, sizeof(fmopts));
		}
#line 5156 "parse.c"
    break;

  case 248: /* filter_match_h: $@11 filter_match  */
#line 2329 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			memcpy(&(yyval.v.filter_match), &fmopts, sizeof((yyval.v.filter_match)));
		}
#line 5164 "parse.c"
    break;

  case 251: /* filter_elm: filter_prefix_h  */
#line 2338 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5182 "parse.c"
    break;

  case 252: /* filter_elm: filter_as_h  */
#line 2351 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.as_l != NULL) {
				yyerror("AS filters already specified");
				YYERROR;
			}
			fmopts.as_l = (yyvsp[0].v.filter_as);
		}
#line 5194 "parse.c"
    break;

  case 253: /* filter_elm: MAXASLEN NUMBER  */
#line 2358 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5211 "parse.c"
    break;

  case 254: /* filter_elm: MAXASSEQ NUMBER  */
#line 2370 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5228 "parse.c"
    break;

  case 255: /* filter_elm: community STRING  */
#line 2382 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5251 "parse.c"
    break;

  case 256: /* filter_elm: EXTCOMMUNITY STRING STRING  */
#line 2400 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5278 "parse.c"
    break;

  case 257: /* filter_elm: EXTCOMMUNITY OVS STRING  */
#line 2422 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5302 "parse.c"
    break;

  case 258: /* filter_elm: MAXCOMMUNITIES NUMBER  */
#line 2441 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5323 "parse.c"
    break;

  case 259: /* filter_elm: MAXEXTCOMMUNITIES NUMBER  */
#line 2457 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5340 "parse.c"
    break;

  case 260: /* filter_elm: MAXLARGECOMMUNITIES NUMBER  */
#line 2469 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5357 "parse.c"
    break;

  case 261: /* filter_elm: NEXTHOP address  */
#line 2481 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.addr = (yyvsp[0].v.addr);
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_ADDR;
		}
#line 5370 "parse.c"
    break;

  case 262: /* filter_elm: NEXTHOP NEIGHBOR  */
#line 2489 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_NEIGHBOR;
		}
#line 5382 "parse.c"
    break;

  case 263: /* filter_elm: PREFIXSET STRING prefixlenop  */
#line 2496 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5436 "parse.c"
    break;

  case 264: /* filter_elm: ORIGINSET STRING  */
#line 2545 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5461 "parse.c"
    break;

  case 265: /* filter_elm: OVS validity  */
#line 2565 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.ovs.is_set) {
				yyerror("ovs filter already specified");
				YYERROR;
			}
			fmopts.m.ovs.validity = (yyvsp[0].v.number);
			fmopts.m.ovs.is_set = 1;
		}
#line 5474 "parse.c"
    break;

  case 266: /* prefixlenop: %empty  */
#line 2575 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { memset(&(yyval.v.prefixlen), 0, sizeof((yyval.v.prefixlen))); }
#line 5480 "parse.c"
    break;

  case 267: /* prefixlenop: LONGER  */
#line 2576 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			memset(&(yyval.v.prefixlen), 0, sizeof((yyval.v.prefixlen)));
			(yyval.v.prefixlen).op = OP_RANGE;
			(yyval.v.prefixlen).len_min = -1;
			(yyval.v.prefixlen).len_max = -1;
		}
#line 5491 "parse.c"
    break;

  case 268: /* prefixlenop: MAXLEN NUMBER  */
#line 2582 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			memset(&(yyval.v.prefixlen), 0, sizeof((yyval.v.prefixlen)));
			if ((yyvsp[0].v.number) < 0 || (yyvsp[0].v.number) > 128) {
				yyerror("prefixlen must be >= 0 and <= 128");
				YYERROR;
			}

			(yyval.v.prefixlen).op = OP_RANGE;
			(yyval.v.prefixlen).len_min = -1;
			(yyval.v.prefixlen).len_max = (yyvsp[0].v.number);
		}
#line 5507 "parse.c"
    break;

  case 269: /* prefixlenop: PREFIXLEN unaryop NUMBER  */
#line 2593 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			int min, max;

			memset(&(yyval.v.prefixlen), 0, sizeof((yyval.v.prefixlen)));
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
#line 5555 "parse.c"
    break;

  case 270: /* prefixlenop: PREFIXLEN NUMBER binaryop NUMBER  */
#line 2636 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			memset(&(yyval.v.prefixlen), 0, sizeof((yyval.v.prefixlen)));
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
#line 5574 "parse.c"
    break;

  case 271: /* filter_as_type: AS  */
#line 2652 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_ALL; }
#line 5580 "parse.c"
    break;

  case 272: /* filter_as_type: SOURCEAS  */
#line 2653 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_SOURCE; }
#line 5586 "parse.c"
    break;

  case 273: /* filter_as_type: TRANSITAS  */
#line 2654 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_TRANSIT; }
#line 5592 "parse.c"
    break;

  case 274: /* filter_as_type: PEERAS  */
#line 2655 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_PEER; }
#line 5598 "parse.c"
    break;

  case 275: /* filter_set: %empty  */
#line 2658 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                { (yyval.v.filter_set_head) = NULL; }
#line 5604 "parse.c"
    break;

  case 276: /* filter_set: SET filter_set_opt  */
#line 2659 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5616 "parse.c"
    break;

  case 277: /* filter_set: SET '{' optnl filter_set_l optnl '}'  */
#line 2666 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head); }
#line 5622 "parse.c"
    break;

  case 278: /* filter_set_l: filter_set_l comma filter_set_opt  */
#line 2669 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head);
			if (merge_filterset((yyval.v.filter_set_head), (yyvsp[0].v.filter_set)) == 1)
				YYERROR;
		}
#line 5632 "parse.c"
    break;

  case 279: /* filter_set_l: filter_set_opt  */
#line 2674 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5644 "parse.c"
    break;

  case 280: /* community: COMMUNITY  */
#line 2683 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.u8) = COMMUNITY_TYPE_BASIC; }
#line 5650 "parse.c"
    break;

  case 281: /* community: LARGECOMMUNITY  */
#line 2684 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.u8) = COMMUNITY_TYPE_LARGE; }
#line 5656 "parse.c"
    break;

  case 282: /* delete: %empty  */
#line 2687 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 0; }
#line 5662 "parse.c"
    break;

  case 283: /* delete: DELETE  */
#line 2688 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 1; }
#line 5668 "parse.c"
    break;

  case 284: /* enforce: %empty  */
#line 2691 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 5674 "parse.c"
    break;

  case 285: /* enforce: ENFORCE  */
#line 2692 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 2; }
#line 5680 "parse.c"
    break;

  case 286: /* filter_set_opt: LOCALPREF NUMBER  */
#line 2695 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5700 "parse.c"
    break;

  case 287: /* filter_set_opt: LOCALPREF '+' NUMBER  */
#line 2710 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5715 "parse.c"
    break;

  case 288: /* filter_set_opt: LOCALPREF '-' NUMBER  */
#line 2720 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5730 "parse.c"
    break;

  case 289: /* filter_set_opt: MED NUMBER  */
#line 2730 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5750 "parse.c"
    break;

  case 290: /* filter_set_opt: MED '+' NUMBER  */
#line 2745 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5765 "parse.c"
    break;

  case 291: /* filter_set_opt: MED '-' NUMBER  */
#line 2755 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5780 "parse.c"
    break;

  case 292: /* filter_set_opt: METRIC NUMBER  */
#line 2765 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5800 "parse.c"
    break;

  case 293: /* filter_set_opt: METRIC '+' NUMBER  */
#line 2780 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5815 "parse.c"
    break;

  case 294: /* filter_set_opt: METRIC '-' NUMBER  */
#line 2790 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5830 "parse.c"
    break;

  case 295: /* filter_set_opt: WEIGHT NUMBER  */
#line 2800 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5850 "parse.c"
    break;

  case 296: /* filter_set_opt: WEIGHT '+' NUMBER  */
#line 2815 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5865 "parse.c"
    break;

  case 297: /* filter_set_opt: WEIGHT '-' NUMBER  */
#line 2825 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5880 "parse.c"
    break;

  case 298: /* filter_set_opt: NEXTHOP address  */
#line 2835 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP;
			memcpy(&(yyval.v.filter_set)->action.nexthop, &(yyvsp[0].v.addr),
			    sizeof((yyval.v.filter_set)->action.nexthop));
		}
#line 5892 "parse.c"
    break;

  case 299: /* filter_set_opt: NEXTHOP BLACKHOLE  */
#line 2842 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_BLACKHOLE;
		}
#line 5902 "parse.c"
    break;

  case 300: /* filter_set_opt: NEXTHOP REJECT  */
#line 2847 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_REJECT;
		}
#line 5912 "parse.c"
    break;

  case 301: /* filter_set_opt: NEXTHOP NOMODIFY  */
#line 2852 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_NOMODIFY;
		}
#line 5922 "parse.c"
    break;

  case 302: /* filter_set_opt: NEXTHOP SELF  */
#line 2857 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_SELF;
		}
#line 5932 "parse.c"
    break;

  case 303: /* filter_set_opt: PREPEND_SELF NUMBER  */
#line 2862 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5947 "parse.c"
    break;

  case 304: /* filter_set_opt: PREPEND_PEER NUMBER  */
#line 2872 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5962 "parse.c"
    break;

  case 305: /* filter_set_opt: ASOVERRIDE  */
#line 2882 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_AS_OVERRIDE;
		}
#line 5972 "parse.c"
    break;

  case 306: /* filter_set_opt: PFTABLE STRING  */
#line 2887 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 6004 "parse.c"
    break;

  case 307: /* filter_set_opt: RTLABEL STRING  */
#line 2914 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 6023 "parse.c"
    break;

  case 308: /* filter_set_opt: community delete STRING  */
#line 2928 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 6056 "parse.c"
    break;

  case 309: /* filter_set_opt: EXTCOMMUNITY delete STRING STRING  */
#line 2956 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 6079 "parse.c"
    break;

  case 310: /* filter_set_opt: EXTCOMMUNITY delete OVS STRING  */
#line 2974 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 6100 "parse.c"
    break;

  case 311: /* filter_set_opt: ORIGIN origincode  */
#line 2990 "../../../openbgpd-portable/src/bgpd/parse.y"
                                    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_ORIGIN;
			(yyval.v.filter_set)->action.origin = (yyvsp[0].v.number);
		}
#line 6111 "parse.c"
    break;

  case 312: /* origincode: STRING  */
#line 2998 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 6130 "parse.c"
    break;

  case 313: /* validity: STRING  */
#line 3013 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 6149 "parse.c"
    break;

  case 320: /* unaryop: '='  */
#line 3038 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_EQ; }
#line 6155 "parse.c"
    break;

  case 321: /* unaryop: NE  */
#line 3039 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_NE; }
#line 6161 "parse.c"
    break;

  case 322: /* unaryop: LE  */
#line 3040 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_LE; }
#line 6167 "parse.c"
    break;

  case 323: /* unaryop: '<'  */
#line 3041 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_LT; }
#line 6173 "parse.c"
    break;

  case 324: /* unaryop: GE  */
#line 3042 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_GE; }
#line 6179 "parse.c"
    break;

  case 325: /* unaryop: '>'  */
#line 3043 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_GT; }
#line 6185 "parse.c"
    break;

  case 326: /* equalityop: '='  */
#line 3046 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_EQ; }
#line 6191 "parse.c"
    break;

  case 327: /* equalityop: NE  */
#line 3047 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_NE; }
#line 6197 "parse.c"
    break;

  case 328: /* binaryop: '-'  */
#line 3050 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_RANGE; }
#line 6203 "parse.c"
    break;

  case 329: /* binaryop: XRANGE  */
#line 3051 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_XRANGE; }
#line 6209 "parse.c"
    break;


#line 6213 "parse.c"

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

#line 3054 "../../../openbgpd-portable/src/bgpd/parse.y"


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
		{ "max",		MAX},
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
		{ "plus",		PLUS},
		{ "policy",		POLICY},
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
	c->fib_priority = kr_default_prio();
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
		*flag = COMMUNITY_LOCAL_AS;
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
