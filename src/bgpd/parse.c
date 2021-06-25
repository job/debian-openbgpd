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
static void	 add_roa_set(struct prefixset_item *, u_int32_t, u_int8_t);
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


#line 247 "parse.c"

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
    DEMOTE = 301,                  /* DEMOTE  */
    ENFORCE = 302,                 /* ENFORCE  */
    NEIGHBORAS = 303,              /* NEIGHBORAS  */
    ASOVERRIDE = 304,              /* ASOVERRIDE  */
    REFLECTOR = 305,               /* REFLECTOR  */
    DEPEND = 306,                  /* DEPEND  */
    DOWN = 307,                    /* DOWN  */
    DUMP = 308,                    /* DUMP  */
    IN = 309,                      /* IN  */
    OUT = 310,                     /* OUT  */
    SOCKET = 311,                  /* SOCKET  */
    RESTRICTED = 312,              /* RESTRICTED  */
    LOG = 313,                     /* LOG  */
    TRANSPARENT = 314,             /* TRANSPARENT  */
    TCP = 315,                     /* TCP  */
    MD5SIG = 316,                  /* MD5SIG  */
    PASSWORD = 317,                /* PASSWORD  */
    KEY = 318,                     /* KEY  */
    TTLSECURITY = 319,             /* TTLSECURITY  */
    ALLOW = 320,                   /* ALLOW  */
    DENY = 321,                    /* DENY  */
    MATCH = 322,                   /* MATCH  */
    QUICK = 323,                   /* QUICK  */
    FROM = 324,                    /* FROM  */
    TO = 325,                      /* TO  */
    ANY = 326,                     /* ANY  */
    CONNECTED = 327,               /* CONNECTED  */
    STATIC = 328,                  /* STATIC  */
    COMMUNITY = 329,               /* COMMUNITY  */
    EXTCOMMUNITY = 330,            /* EXTCOMMUNITY  */
    LARGECOMMUNITY = 331,          /* LARGECOMMUNITY  */
    DELETE = 332,                  /* DELETE  */
    PREFIX = 333,                  /* PREFIX  */
    PREFIXLEN = 334,               /* PREFIXLEN  */
    PREFIXSET = 335,               /* PREFIXSET  */
    ROASET = 336,                  /* ROASET  */
    ORIGINSET = 337,               /* ORIGINSET  */
    OVS = 338,                     /* OVS  */
    ASSET = 339,                   /* ASSET  */
    SOURCEAS = 340,                /* SOURCEAS  */
    TRANSITAS = 341,               /* TRANSITAS  */
    PEERAS = 342,                  /* PEERAS  */
    MAXASLEN = 343,                /* MAXASLEN  */
    MAXASSEQ = 344,                /* MAXASSEQ  */
    SET = 345,                     /* SET  */
    LOCALPREF = 346,               /* LOCALPREF  */
    MED = 347,                     /* MED  */
    METRIC = 348,                  /* METRIC  */
    NEXTHOP = 349,                 /* NEXTHOP  */
    REJECT = 350,                  /* REJECT  */
    BLACKHOLE = 351,               /* BLACKHOLE  */
    NOMODIFY = 352,                /* NOMODIFY  */
    SELF = 353,                    /* SELF  */
    PREPEND_SELF = 354,            /* PREPEND_SELF  */
    PREPEND_PEER = 355,            /* PREPEND_PEER  */
    PFTABLE = 356,                 /* PFTABLE  */
    WEIGHT = 357,                  /* WEIGHT  */
    RTLABEL = 358,                 /* RTLABEL  */
    ORIGIN = 359,                  /* ORIGIN  */
    PRIORITY = 360,                /* PRIORITY  */
    ERROR = 361,                   /* ERROR  */
    INCLUDE = 362,                 /* INCLUDE  */
    IPSEC = 363,                   /* IPSEC  */
    ESP = 364,                     /* ESP  */
    AH = 365,                      /* AH  */
    SPI = 366,                     /* SPI  */
    IKE = 367,                     /* IKE  */
    IPV4 = 368,                    /* IPV4  */
    IPV6 = 369,                    /* IPV6  */
    QUALIFY = 370,                 /* QUALIFY  */
    VIA = 371,                     /* VIA  */
    NE = 372,                      /* NE  */
    LE = 373,                      /* LE  */
    GE = 374,                      /* GE  */
    XRANGE = 375,                  /* XRANGE  */
    LONGER = 376,                  /* LONGER  */
    MAXLEN = 377,                  /* MAXLEN  */
    STRING = 378,                  /* STRING  */
    NUMBER = 379                   /* NUMBER  */
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
#define DEMOTE 301
#define ENFORCE 302
#define NEIGHBORAS 303
#define ASOVERRIDE 304
#define REFLECTOR 305
#define DEPEND 306
#define DOWN 307
#define DUMP 308
#define IN 309
#define OUT 310
#define SOCKET 311
#define RESTRICTED 312
#define LOG 313
#define TRANSPARENT 314
#define TCP 315
#define MD5SIG 316
#define PASSWORD 317
#define KEY 318
#define TTLSECURITY 319
#define ALLOW 320
#define DENY 321
#define MATCH 322
#define QUICK 323
#define FROM 324
#define TO 325
#define ANY 326
#define CONNECTED 327
#define STATIC 328
#define COMMUNITY 329
#define EXTCOMMUNITY 330
#define LARGECOMMUNITY 331
#define DELETE 332
#define PREFIX 333
#define PREFIXLEN 334
#define PREFIXSET 335
#define ROASET 336
#define ORIGINSET 337
#define OVS 338
#define ASSET 339
#define SOURCEAS 340
#define TRANSITAS 341
#define PEERAS 342
#define MAXASLEN 343
#define MAXASSEQ 344
#define SET 345
#define LOCALPREF 346
#define MED 347
#define METRIC 348
#define NEXTHOP 349
#define REJECT 350
#define BLACKHOLE 351
#define NOMODIFY 352
#define SELF 353
#define PREPEND_SELF 354
#define PREPEND_PEER 355
#define PFTABLE 356
#define WEIGHT 357
#define RTLABEL 358
#define ORIGIN 359
#define PRIORITY 360
#define ERROR 361
#define INCLUDE 362
#define IPSEC 363
#define ESP 364
#define AH 365
#define SPI 366
#define IKE 367
#define IPV4 368
#define IPV6 369
#define QUALIFY 370
#define VIA 371
#define NE 372
#define LE 373
#define GE 374
#define XRANGE 375
#define LONGER 376
#define MAXLEN 377
#define STRING 378
#define NUMBER 379

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
  YYSYMBOL_DEMOTE = 46,                    /* DEMOTE  */
  YYSYMBOL_ENFORCE = 47,                   /* ENFORCE  */
  YYSYMBOL_NEIGHBORAS = 48,                /* NEIGHBORAS  */
  YYSYMBOL_ASOVERRIDE = 49,                /* ASOVERRIDE  */
  YYSYMBOL_REFLECTOR = 50,                 /* REFLECTOR  */
  YYSYMBOL_DEPEND = 51,                    /* DEPEND  */
  YYSYMBOL_DOWN = 52,                      /* DOWN  */
  YYSYMBOL_DUMP = 53,                      /* DUMP  */
  YYSYMBOL_IN = 54,                        /* IN  */
  YYSYMBOL_OUT = 55,                       /* OUT  */
  YYSYMBOL_SOCKET = 56,                    /* SOCKET  */
  YYSYMBOL_RESTRICTED = 57,                /* RESTRICTED  */
  YYSYMBOL_LOG = 58,                       /* LOG  */
  YYSYMBOL_TRANSPARENT = 59,               /* TRANSPARENT  */
  YYSYMBOL_TCP = 60,                       /* TCP  */
  YYSYMBOL_MD5SIG = 61,                    /* MD5SIG  */
  YYSYMBOL_PASSWORD = 62,                  /* PASSWORD  */
  YYSYMBOL_KEY = 63,                       /* KEY  */
  YYSYMBOL_TTLSECURITY = 64,               /* TTLSECURITY  */
  YYSYMBOL_ALLOW = 65,                     /* ALLOW  */
  YYSYMBOL_DENY = 66,                      /* DENY  */
  YYSYMBOL_MATCH = 67,                     /* MATCH  */
  YYSYMBOL_QUICK = 68,                     /* QUICK  */
  YYSYMBOL_FROM = 69,                      /* FROM  */
  YYSYMBOL_TO = 70,                        /* TO  */
  YYSYMBOL_ANY = 71,                       /* ANY  */
  YYSYMBOL_CONNECTED = 72,                 /* CONNECTED  */
  YYSYMBOL_STATIC = 73,                    /* STATIC  */
  YYSYMBOL_COMMUNITY = 74,                 /* COMMUNITY  */
  YYSYMBOL_EXTCOMMUNITY = 75,              /* EXTCOMMUNITY  */
  YYSYMBOL_LARGECOMMUNITY = 76,            /* LARGECOMMUNITY  */
  YYSYMBOL_DELETE = 77,                    /* DELETE  */
  YYSYMBOL_PREFIX = 78,                    /* PREFIX  */
  YYSYMBOL_PREFIXLEN = 79,                 /* PREFIXLEN  */
  YYSYMBOL_PREFIXSET = 80,                 /* PREFIXSET  */
  YYSYMBOL_ROASET = 81,                    /* ROASET  */
  YYSYMBOL_ORIGINSET = 82,                 /* ORIGINSET  */
  YYSYMBOL_OVS = 83,                       /* OVS  */
  YYSYMBOL_ASSET = 84,                     /* ASSET  */
  YYSYMBOL_SOURCEAS = 85,                  /* SOURCEAS  */
  YYSYMBOL_TRANSITAS = 86,                 /* TRANSITAS  */
  YYSYMBOL_PEERAS = 87,                    /* PEERAS  */
  YYSYMBOL_MAXASLEN = 88,                  /* MAXASLEN  */
  YYSYMBOL_MAXASSEQ = 89,                  /* MAXASSEQ  */
  YYSYMBOL_SET = 90,                       /* SET  */
  YYSYMBOL_LOCALPREF = 91,                 /* LOCALPREF  */
  YYSYMBOL_MED = 92,                       /* MED  */
  YYSYMBOL_METRIC = 93,                    /* METRIC  */
  YYSYMBOL_NEXTHOP = 94,                   /* NEXTHOP  */
  YYSYMBOL_REJECT = 95,                    /* REJECT  */
  YYSYMBOL_BLACKHOLE = 96,                 /* BLACKHOLE  */
  YYSYMBOL_NOMODIFY = 97,                  /* NOMODIFY  */
  YYSYMBOL_SELF = 98,                      /* SELF  */
  YYSYMBOL_PREPEND_SELF = 99,              /* PREPEND_SELF  */
  YYSYMBOL_PREPEND_PEER = 100,             /* PREPEND_PEER  */
  YYSYMBOL_PFTABLE = 101,                  /* PFTABLE  */
  YYSYMBOL_WEIGHT = 102,                   /* WEIGHT  */
  YYSYMBOL_RTLABEL = 103,                  /* RTLABEL  */
  YYSYMBOL_ORIGIN = 104,                   /* ORIGIN  */
  YYSYMBOL_PRIORITY = 105,                 /* PRIORITY  */
  YYSYMBOL_ERROR = 106,                    /* ERROR  */
  YYSYMBOL_INCLUDE = 107,                  /* INCLUDE  */
  YYSYMBOL_IPSEC = 108,                    /* IPSEC  */
  YYSYMBOL_ESP = 109,                      /* ESP  */
  YYSYMBOL_AH = 110,                       /* AH  */
  YYSYMBOL_SPI = 111,                      /* SPI  */
  YYSYMBOL_IKE = 112,                      /* IKE  */
  YYSYMBOL_IPV4 = 113,                     /* IPV4  */
  YYSYMBOL_IPV6 = 114,                     /* IPV6  */
  YYSYMBOL_QUALIFY = 115,                  /* QUALIFY  */
  YYSYMBOL_VIA = 116,                      /* VIA  */
  YYSYMBOL_NE = 117,                       /* NE  */
  YYSYMBOL_LE = 118,                       /* LE  */
  YYSYMBOL_GE = 119,                       /* GE  */
  YYSYMBOL_XRANGE = 120,                   /* XRANGE  */
  YYSYMBOL_LONGER = 121,                   /* LONGER  */
  YYSYMBOL_MAXLEN = 122,                   /* MAXLEN  */
  YYSYMBOL_STRING = 123,                   /* STRING  */
  YYSYMBOL_NUMBER = 124,                   /* NUMBER  */
  YYSYMBOL_125_n_ = 125,                   /* '\n'  */
  YYSYMBOL_126_ = 126,                     /* '='  */
  YYSYMBOL_127_ = 127,                     /* '{'  */
  YYSYMBOL_128_ = 128,                     /* '}'  */
  YYSYMBOL_129_ = 129,                     /* '/'  */
  YYSYMBOL_130_ = 130,                     /* '+'  */
  YYSYMBOL_131_ = 131,                     /* '-'  */
  YYSYMBOL_132_ = 132,                     /* ','  */
  YYSYMBOL_133_ = 133,                     /* '<'  */
  YYSYMBOL_134_ = 134,                     /* '>'  */
  YYSYMBOL_YYACCEPT = 135,                 /* $accept  */
  YYSYMBOL_grammar = 136,                  /* grammar  */
  YYSYMBOL_asnumber = 137,                 /* asnumber  */
  YYSYMBOL_as4number = 138,                /* as4number  */
  YYSYMBOL_as4number_any = 139,            /* as4number_any  */
  YYSYMBOL_string = 140,                   /* string  */
  YYSYMBOL_yesno = 141,                    /* yesno  */
  YYSYMBOL_varset = 142,                   /* varset  */
  YYSYMBOL_include = 143,                  /* include  */
  YYSYMBOL_as_set = 144,                   /* as_set  */
  YYSYMBOL_145_1 = 145,                    /* $@1  */
  YYSYMBOL_as_set_l = 146,                 /* as_set_l  */
  YYSYMBOL_prefixset = 147,                /* prefixset  */
  YYSYMBOL_148_2 = 148,                    /* $@2  */
  YYSYMBOL_prefixset_l = 149,              /* prefixset_l  */
  YYSYMBOL_prefixset_item = 150,           /* prefixset_item  */
  YYSYMBOL_roa_set = 151,                  /* roa_set  */
  YYSYMBOL_152_3 = 152,                    /* $@3  */
  YYSYMBOL_origin_set = 153,               /* origin_set  */
  YYSYMBOL_154_4 = 154,                    /* $@4  */
  YYSYMBOL_roa_set_l = 155,                /* roa_set_l  */
  YYSYMBOL_rtr = 156,                      /* rtr  */
  YYSYMBOL_157_5 = 157,                    /* $@5  */
  YYSYMBOL_rtropt_l = 158,                 /* rtropt_l  */
  YYSYMBOL_rtropt = 159,                   /* rtropt  */
  YYSYMBOL_conf_main = 160,                /* conf_main  */
  YYSYMBOL_rib = 161,                      /* rib  */
  YYSYMBOL_162_6 = 162,                    /* $@6  */
  YYSYMBOL_ribopts = 163,                  /* ribopts  */
  YYSYMBOL_fibupdate = 164,                /* fibupdate  */
  YYSYMBOL_mrtdump = 165,                  /* mrtdump  */
  YYSYMBOL_network = 166,                  /* network  */
  YYSYMBOL_inout = 167,                    /* inout  */
  YYSYMBOL_restricted = 168,               /* restricted  */
  YYSYMBOL_address = 169,                  /* address  */
  YYSYMBOL_prefix = 170,                   /* prefix  */
  YYSYMBOL_addrspec = 171,                 /* addrspec  */
  YYSYMBOL_optnumber = 172,                /* optnumber  */
  YYSYMBOL_l3vpn = 173,                    /* l3vpn  */
  YYSYMBOL_174_7 = 174,                    /* $@7  */
  YYSYMBOL_l3vpnopts_l = 175,              /* l3vpnopts_l  */
  YYSYMBOL_l3vpnopts = 176,                /* l3vpnopts  */
  YYSYMBOL_neighbor = 177,                 /* neighbor  */
  YYSYMBOL_178_8 = 178,                    /* $@8  */
  YYSYMBOL_179_9 = 179,                    /* $@9  */
  YYSYMBOL_group = 180,                    /* group  */
  YYSYMBOL_181_10 = 181,                   /* $@10  */
  YYSYMBOL_groupopts_l = 182,              /* groupopts_l  */
  YYSYMBOL_peeropts_h = 183,               /* peeropts_h  */
  YYSYMBOL_peeropts_l = 184,               /* peeropts_l  */
  YYSYMBOL_peeropts = 185,                 /* peeropts  */
  YYSYMBOL_restart = 186,                  /* restart  */
  YYSYMBOL_family = 187,                   /* family  */
  YYSYMBOL_safi = 188,                     /* safi  */
  YYSYMBOL_nettype = 189,                  /* nettype  */
  YYSYMBOL_espah = 190,                    /* espah  */
  YYSYMBOL_encspec = 191,                  /* encspec  */
  YYSYMBOL_filterrule = 192,               /* filterrule  */
  YYSYMBOL_action = 193,                   /* action  */
  YYSYMBOL_quick = 194,                    /* quick  */
  YYSYMBOL_direction = 195,                /* direction  */
  YYSYMBOL_filter_rib_h = 196,             /* filter_rib_h  */
  YYSYMBOL_filter_rib_l = 197,             /* filter_rib_l  */
  YYSYMBOL_filter_rib = 198,               /* filter_rib  */
  YYSYMBOL_filter_peer_h = 199,            /* filter_peer_h  */
  YYSYMBOL_filter_peer_l = 200,            /* filter_peer_l  */
  YYSYMBOL_filter_peer = 201,              /* filter_peer  */
  YYSYMBOL_filter_prefix_h = 202,          /* filter_prefix_h  */
  YYSYMBOL_filter_prefix_m = 203,          /* filter_prefix_m  */
  YYSYMBOL_filter_prefix_l = 204,          /* filter_prefix_l  */
  YYSYMBOL_filter_prefix = 205,            /* filter_prefix  */
  YYSYMBOL_filter_as_h = 206,              /* filter_as_h  */
  YYSYMBOL_filter_as_t_l = 207,            /* filter_as_t_l  */
  YYSYMBOL_filter_as_t = 208,              /* filter_as_t  */
  YYSYMBOL_filter_as_l_h = 209,            /* filter_as_l_h  */
  YYSYMBOL_filter_as_l = 210,              /* filter_as_l  */
  YYSYMBOL_filter_as = 211,                /* filter_as  */
  YYSYMBOL_filter_match_h = 212,           /* filter_match_h  */
  YYSYMBOL_213_11 = 213,                   /* $@11  */
  YYSYMBOL_filter_match = 214,             /* filter_match  */
  YYSYMBOL_filter_elm = 215,               /* filter_elm  */
  YYSYMBOL_prefixlenop = 216,              /* prefixlenop  */
  YYSYMBOL_filter_as_type = 217,           /* filter_as_type  */
  YYSYMBOL_filter_set = 218,               /* filter_set  */
  YYSYMBOL_filter_set_l = 219,             /* filter_set_l  */
  YYSYMBOL_community = 220,                /* community  */
  YYSYMBOL_delete = 221,                   /* delete  */
  YYSYMBOL_filter_set_opt = 222,           /* filter_set_opt  */
  YYSYMBOL_origincode = 223,               /* origincode  */
  YYSYMBOL_validity = 224,                 /* validity  */
  YYSYMBOL_optnl = 225,                    /* optnl  */
  YYSYMBOL_comma = 226,                    /* comma  */
  YYSYMBOL_unaryop = 227,                  /* unaryop  */
  YYSYMBOL_equalityop = 228,               /* equalityop  */
  YYSYMBOL_binaryop = 229                  /* binaryop  */
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
#define YYLAST   673

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  135
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  313
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  582

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   379


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
     125,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   130,   132,   131,     2,   129,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     133,   126,   134,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   127,     2,   128,     2,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   251,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   269,   280,
     312,   322,   349,   354,   360,   363,   378,   398,   413,   413,
     427,   435,   436,   438,   438,   448,   458,   472,   488,   505,
     505,   510,   513,   513,   525,   537,   547,   559,   568,   568,
     580,   581,   583,   594,   602,   612,   619,   623,   630,   638,
     646,   660,   667,   678,   684,   690,   699,   700,   728,   760,
     761,   771,   781,   794,   807,   820,   836,   843,   859,   859,
     869,   870,   879,   888,   889,   897,   927,   948,   977,   996,
    1020,  1040,  1041,  1044,  1045,  1048,  1069,  1087,  1107,  1114,
    1117,  1118,  1121,  1121,  1166,  1167,  1168,  1169,  1172,  1190,
    1208,  1226,  1232,  1235,  1236,  1235,  1270,  1270,  1302,  1303,
    1304,  1305,  1306,  1309,  1310,  1311,  1314,  1315,  1316,  1317,
    1320,  1323,  1330,  1334,  1345,  1358,  1368,  1375,  1378,  1381,
    1392,  1408,  1416,  1424,  1443,  1446,  1449,  1452,  1455,  1458,
    1461,  1464,  1470,  1476,  1491,  1499,  1507,  1525,  1541,  1551,
    1644,  1647,  1654,  1666,  1667,  1677,  1693,  1705,  1729,  1735,
    1746,  1752,  1767,  1768,  1778,  1779,  1782,  1783,  1784,  1787,
    1788,  1791,  1792,  1795,  1798,  1831,  1858,  1859,  1860,  1863,
    1864,  1867,  1868,  1871,  1872,  1873,  1875,  1876,  1882,  1904,
    1905,  1908,  1909,  1915,  1922,  1942,  1949,  1970,  1976,  1984,
    1999,  2014,  2015,  2018,  2019,  2020,  2032,  2033,  2039,  2054,
    2055,  2058,  2059,  2071,  2075,  2082,  2105,  2106,  2107,  2120,
    2121,  2127,  2135,  2141,  2149,  2163,  2166,  2166,  2174,  2175,
    2178,  2191,  2198,  2210,  2222,  2240,  2262,  2281,  2289,  2296,
    2345,  2365,  2375,  2376,  2382,  2393,  2436,  2452,  2453,  2454,
    2455,  2458,  2459,  2466,  2469,  2474,  2483,  2484,  2487,  2488,
    2491,  2506,  2516,  2526,  2541,  2551,  2561,  2576,  2586,  2596,
    2611,  2621,  2631,  2638,  2643,  2648,  2653,  2658,  2668,  2678,
    2683,  2710,  2724,  2752,  2770,  2786,  2794,  2809,  2824,  2825,
    2828,  2829,  2830,  2831,  2834,  2835,  2836,  2837,  2838,  2839,
    2842,  2843,  2846,  2847
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
  "CONNECTRETRY", "ENHANCED", "DEMOTE", "ENFORCE", "NEIGHBORAS",
  "ASOVERRIDE", "REFLECTOR", "DEPEND", "DOWN", "DUMP", "IN", "OUT",
  "SOCKET", "RESTRICTED", "LOG", "TRANSPARENT", "TCP", "MD5SIG",
  "PASSWORD", "KEY", "TTLSECURITY", "ALLOW", "DENY", "MATCH", "QUICK",
  "FROM", "TO", "ANY", "CONNECTED", "STATIC", "COMMUNITY", "EXTCOMMUNITY",
  "LARGECOMMUNITY", "DELETE", "PREFIX", "PREFIXLEN", "PREFIXSET", "ROASET",
  "ORIGINSET", "OVS", "ASSET", "SOURCEAS", "TRANSITAS", "PEERAS",
  "MAXASLEN", "MAXASSEQ", "SET", "LOCALPREF", "MED", "METRIC", "NEXTHOP",
  "REJECT", "BLACKHOLE", "NOMODIFY", "SELF", "PREPEND_SELF",
  "PREPEND_PEER", "PFTABLE", "WEIGHT", "RTLABEL", "ORIGIN", "PRIORITY",
  "ERROR", "INCLUDE", "IPSEC", "ESP", "AH", "SPI", "IKE", "IPV4", "IPV6",
  "QUALIFY", "VIA", "NE", "LE", "GE", "XRANGE", "LONGER", "MAXLEN",
  "STRING", "NUMBER", "'\\n'", "'='", "'{'", "'}'", "'/'", "'+'", "'-'",
  "','", "'<'", "'>'", "$accept", "grammar", "asnumber", "as4number",
  "as4number_any", "string", "yesno", "varset", "include", "as_set", "$@1",
  "as_set_l", "prefixset", "$@2", "prefixset_l", "prefixset_item",
  "roa_set", "$@3", "origin_set", "$@4", "roa_set_l", "rtr", "$@5",
  "rtropt_l", "rtropt", "conf_main", "rib", "$@6", "ribopts", "fibupdate",
  "mrtdump", "network", "inout", "restricted", "address", "prefix",
  "addrspec", "optnumber", "l3vpn", "$@7", "l3vpnopts_l", "l3vpnopts",
  "neighbor", "$@8", "$@9", "group", "$@10", "groupopts_l", "peeropts_h",
  "peeropts_l", "peeropts", "restart", "family", "safi", "nettype",
  "espah", "encspec", "filterrule", "action", "quick", "direction",
  "filter_rib_h", "filter_rib_l", "filter_rib", "filter_peer_h",
  "filter_peer_l", "filter_peer", "filter_prefix_h", "filter_prefix_m",
  "filter_prefix_l", "filter_prefix", "filter_as_h", "filter_as_t_l",
  "filter_as_t", "filter_as_l_h", "filter_as_l", "filter_as",
  "filter_match_h", "$@11", "filter_match", "filter_elm", "prefixlenop",
  "filter_as_type", "filter_set", "filter_set_l", "community", "delete",
  "filter_set_opt", "origincode", "validity", "optnl", "comma", "unaryop",
  "equalityop", "binaryop", YY_NULLPTR
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
     375,   376,   377,   378,   379,    10,    61,   123,   125,    47,
      43,    45,    44,    60,    62
};
#endif

#define YYPACT_NINF (-415)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-301)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -415,   390,  -415,   -97,    72,   -76,    19,    44,   -47,   -39,
     -26,   -12,    14,   -76,     5,    88,     7,     3,    12,    32,
     -47,  -415,  -415,  -415,    40,    22,    62,    80,    91,   130,
      96,   101,  -415,   104,   109,   117,   122,   129,   131,   135,
     140,   151,  -415,  -415,   154,   165,   193,   178,   186,   232,
    -415,  -415,  -415,  -415,   191,  -415,  -415,   200,  -415,   -76,
    -415,  -415,  -415,  -415,   328,   205,   222,   336,   247,   237,
    -415,   255,   258,  -415,  -415,   241,   253,   294,    86,  -415,
     260,    18,   329,  -415,  -415,   261,   264,   271,   276,   269,
     -47,  -415,     5,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,   218,  -415,  -415,  -415,   385,  -415,
    -415,  -415,   284,  -415,  -415,   285,  -415,  -415,   282,  -415,
     286,   294,   287,   290,   515,  -415,  -415,  -415,   301,   292,
     294,   303,  -415,  -415,   304,   306,  -415,  -415,   264,   264,
     299,   264,   264,   307,  -415,   255,   241,  -415,  -415,  -415,
     -20,   293,  -415,    29,  -415,   264,  -415,  -415,  -415,  -415,
    -415,  -415,   355,  -415,    69,   158,   163,   141,   309,   311,
     313,   175,   315,   316,   264,   355,  -415,   294,   294,  -415,
     317,  -415,  -415,   304,   319,  -415,  -415,   243,   322,   324,
    -415,   310,  -415,   264,  -415,  -415,  -415,    90,   318,   -47,
     330,   419,  -415,  -415,   214,   297,  -415,    39,  -415,   334,
     335,  -415,   337,   338,  -415,   339,   340,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,   341,   342,  -415,  -415,
    -415,   484,   321,  -415,  -415,   304,  -415,  -415,   243,   357,
     146,    23,  -415,   243,  -415,   245,   503,  -415,   344,    72,
     345,  -415,  -415,  -415,   264,  -415,   -31,  -415,  -415,  -415,
     444,  -415,   349,   346,   -76,   264,  -415,   350,    26,    78,
     438,   353,    72,    72,     5,   -76,   354,  -415,   358,   183,
     356,    21,   -47,   -76,   469,   360,   363,   364,   -47,   420,
     -47,   546,   404,   263,  -415,  -415,   454,  -415,   365,   366,
     372,   376,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
     146,  -415,  -415,  -415,   146,  -415,   245,   264,   377,   381,
     243,   133,  -415,   386,  -415,   146,  -415,  -415,  -415,   146,
    -415,   383,   121,  -415,  -415,  -415,    24,   294,   418,    95,
    -415,  -415,  -415,  -415,    11,  -415,   392,  -415,  -415,  -415,
     391,  -415,   191,  -415,   255,  -415,  -415,    45,   -47,   -47,
     -47,   -47,   475,   326,  -415,   -47,   -47,  -415,  -415,   395,
    -415,   320,  -415,  -415,   314,  -415,   264,  -415,   -47,  -415,
    -415,   -13,  -415,  -415,  -415,  -415,  -415,   393,   484,   394,
     243,  -415,   397,   264,  -415,   435,  -415,  -415,  -415,    52,
    -415,  -415,  -415,   403,  -415,   400,   401,   245,    28,  -415,
     402,   344,   146,  -415,  -415,  -415,    65,   108,   411,   421,
     423,  -415,  -415,  -415,   427,   441,     2,    23,    23,    47,
    -415,  -415,  -415,   418,  -415,    43,   424,   417,   -47,   443,
     445,   446,  -415,  -415,  -415,   447,  -415,  -415,  -415,  -415,
    -415,   449,   531,  -415,  -415,  -415,  -415,  -415,   -47,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,     5,     5,   484,  -415,
    -415,   460,  -415,  -415,  -415,  -415,  -415,   245,  -415,  -415,
     450,  -415,  -415,  -415,  -415,   455,  -415,  -415,   456,  -415,
    -415,   451,    24,   459,   471,   168,    23,  -415,    23,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,   176,  -415,
    -415,  -415,   473,  -415,  -415,    81,    52,  -415,   245,  -415,
    -415,  -415,  -415,   474,   476,  -415,  -415,  -415,  -415,   255,
     255,   146,   468,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,   243,   472,   182,  -415,  -415,  -415,   264,  -415,    47,
    -415,    92,   477,   184,  -415,   245,  -415,  -415,  -415,   482,
     478,   194,  -415,   243,  -415,  -415,   195,  -415,    92,  -415,
    -415,   479,   168,  -415,    81,  -415,   480,  -415,  -415,   481,
    -415,  -415
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,   187,   188,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    66,     0,     0,     0,     0,     0,   189,
      17,    19,    18,    20,    55,    95,    57,     0,    58,     0,
      25,    62,    61,    75,     0,     0,     0,     0,     0,    47,
      24,   116,     0,   174,   175,     0,     0,   261,     0,    76,
       0,     0,    94,    65,    63,     0,   298,     0,     0,     0,
       0,    27,     0,     4,     5,     6,     7,     8,     9,    10,
      12,    11,    13,    14,     0,    15,    16,   190,   193,    56,
      59,    60,     0,    78,    73,     0,    70,    71,     0,    23,
       0,   261,     0,     0,     0,    86,   180,   179,     0,     0,
     261,     0,    91,    92,   100,     0,    93,    77,   298,   298,
      39,   298,   298,     0,    64,    26,    95,    98,    99,   114,
       0,     0,   102,    83,    72,   298,   118,    87,    96,    97,
     289,   266,   268,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,   268,   262,   261,   261,    90,
       0,   101,    67,   100,    33,   299,    41,     0,    42,    28,
      74,   125,   198,   298,   194,   191,   192,     0,     0,     0,
       0,     0,    79,    80,     0,     0,   269,     0,   270,     0,
       0,   273,     0,     0,   276,     0,     0,   284,   283,   285,
     286,   282,   287,   288,   290,   279,     0,     0,   291,   296,
     295,     0,     0,    88,    89,   100,    85,    35,     0,     0,
     300,   252,    44,     0,    30,     0,     0,   115,     0,     0,
       0,   207,   208,   203,   298,   204,   236,   199,   104,    84,
      83,    82,     0,     0,     0,   298,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
       0,     0,     0,   164,     0,   138,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   117,     0,   163,     0,     0,
       0,     0,   271,   272,   274,   275,   277,   278,   280,   281,
     300,   265,   292,    68,   300,    36,     0,   298,   301,     0,
       0,     0,   253,     0,    38,   300,    21,    22,    31,   300,
     126,     0,   298,   196,   205,   206,     0,   261,     0,     0,
      81,    54,    52,    53,     0,   122,     0,   141,   149,   150,
       0,   140,   131,   130,   133,   134,   136,   172,     0,     0,
       0,     0,     0,     0,   167,     0,     0,   153,   165,     0,
     139,     0,   169,   168,     0,   160,   298,   161,     0,   181,
     182,     0,   135,   121,   120,   294,   293,     0,     0,     0,
       0,    45,   302,   298,    40,     0,   305,   306,   308,     0,
     304,   307,   309,     0,   254,     0,     0,     0,     0,   124,
       0,     0,   300,   201,   185,   257,     0,     0,     0,     0,
       0,   258,   259,   260,     0,     0,     0,   252,   252,     0,
     240,   241,   219,   237,   238,     0,     0,     0,     0,     0,
       0,     0,   105,   103,   112,     0,    49,    51,   142,   171,
     132,     0,   172,   154,   147,   144,   145,   148,     0,   176,
     177,   178,   143,   152,   151,   166,     0,     0,     0,   170,
     158,     0,   263,   264,    34,    37,   303,     0,   313,   312,
       0,   255,    43,    29,    32,     0,   127,   123,     0,   195,
     197,     0,     0,     0,     0,     0,   252,   211,   252,   250,
     297,   251,   242,   243,   248,   247,   209,   210,   300,   221,
     239,   232,     0,   311,   310,     0,   231,   223,     0,   244,
     107,   111,   108,     0,     0,   106,   173,   155,   146,   156,
     157,   300,     0,    46,   256,   129,   128,   200,   202,   246,
     245,     0,     0,   300,   216,   218,   249,   298,   220,     0,
     225,     0,     0,   300,   229,     0,   233,   109,   110,     0,
       0,   300,   212,     0,   302,   222,   300,   224,     0,   234,
     162,     0,   214,   217,   227,   230,   183,   215,   228,     0,
     159,   184
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -415,  -415,    13,   -92,  -234,   -87,    -7,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -212,  -415,  -415,  -415,  -415,
     369,  -415,  -415,  -415,   279,  -415,  -415,  -415,  -415,   367,
     612,   291,   244,  -415,    -3,   -15,  -415,  -126,  -415,  -415,
    -415,  -415,   426,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -231,   172,   362,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -240,  -415,  -415,  -318,  -415,    57,    93,
    -398,  -415,  -415,  -407,    58,    82,  -414,  -415,  -415,  -415,
     202,  -312,  -415,  -107,   185,  -295,   461,  -115,  -415,  -415,
    -135,  -298,  -415,  -415,   127
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,   327,    54,   516,    71,   296,    33,    34,    35,
     245,   329,    36,   238,   314,   239,    37,   187,    38,   243,
     240,    39,   118,   265,   266,    40,    41,   153,   202,   203,
     297,    43,   135,   137,   255,   241,   149,   182,    44,   198,
     339,   445,    45,    46,   191,    47,   120,   205,   247,   408,
     299,   453,    78,   462,   130,   381,   580,    48,    49,   108,
     197,   151,   332,   194,   256,   412,   257,   430,   542,   543,
     544,   431,   508,   432,   552,   553,   554,   337,   338,   433,
     434,   324,   435,   125,   310,   175,   207,   311,   230,   501,
     140,   320,   403,   518,   480
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    61,    56,   184,   185,   145,   188,   189,   333,   176,
      69,   328,   388,    84,   157,   331,   390,    53,   413,   497,
     204,   517,   509,   179,    80,    57,   315,   249,    50,   485,
     504,   407,   346,   268,   411,    65,    66,   262,   199,   231,
     200,   132,   133,   436,   269,   263,   264,    55,   270,   271,
     415,   250,    59,   365,   251,   252,   111,   236,   248,  -235,
     272,   273,   274,   275,   276,   277,   278,   109,   279,   366,
     233,   234,   132,   133,   280,   281,    60,   282,   283,   284,
     285,   286,   391,   144,   451,    62,   287,   288,   289,   148,
     348,   511,   290,   249,  -235,   253,   437,   349,    63,   470,
     452,   147,   321,   192,   438,   319,    67,   193,   395,   313,
     439,    64,   440,   441,   492,   506,   507,   250,   291,   336,
     251,   252,   300,   292,    15,    55,    81,   512,    70,   511,
     344,    79,   421,   422,   423,    82,   293,    68,   436,   446,
     511,   134,   565,    58,   322,   323,   201,    55,   493,    86,
     347,    60,    60,   486,   575,    83,   487,   334,   126,   127,
     513,   253,   301,    85,   221,   573,   326,    52,    72,   514,
     515,   490,   478,   484,   538,   387,   377,   488,   475,   389,
     352,   353,   392,   479,   545,    87,   546,   354,   494,   128,
     405,   129,   259,   208,   406,    51,    52,   410,   513,   209,
     210,    73,    74,    88,   326,    52,    89,   514,   551,   513,
     549,    75,    76,    55,    90,   326,    52,   254,   514,    91,
     442,   104,   358,   443,   359,   360,   361,    92,   362,    93,
     414,    75,    76,   388,    94,   495,   217,   218,   219,   220,
     262,   468,    95,   533,  -300,   563,   317,    96,   263,   264,
     396,   397,   398,   318,    97,   568,    98,   399,   476,   400,
      99,   343,    53,   563,    55,   100,   401,   402,   568,   116,
     117,   317,   355,   473,  -298,   367,   101,   491,   318,   102,
     368,   373,   211,   375,   556,    53,    53,   214,   212,   213,
     103,    75,    76,   215,   216,   541,    73,    74,   267,   225,
     107,   547,   268,   105,   548,   226,   227,   547,   318,   547,
    -213,   106,  -226,   269,   318,    52,   318,   270,   271,   547,
     547,   569,   572,   574,   110,  -113,   318,   318,   113,   272,
     273,   274,   275,   276,   277,   278,   112,   279,   459,   460,
     461,   146,    76,   280,   281,   114,   282,   283,   284,   285,
     286,   454,   455,   456,   457,   287,   288,   289,   463,   464,
     115,   290,   195,   196,   -48,   450,    75,    76,   326,    52,
     122,   469,   379,   380,   132,   133,   466,   467,   119,   529,
     530,   121,   123,   131,   124,   143,   136,   291,   138,   139,
       2,     3,   292,     4,     5,     6,   559,     7,   141,     8,
       9,    10,   496,   142,    11,   293,   150,   152,   154,   155,
      12,   158,   564,   156,   159,    13,   178,    14,  -113,    15,
      60,   415,   294,   505,   177,   295,   180,   186,   181,   183,
     190,   521,   206,   222,    16,   223,   224,   246,   228,   229,
     235,   261,   316,    17,   312,   258,    18,   237,    19,    20,
     242,   528,   244,   199,   260,    21,    22,    23,   302,   303,
     350,   304,   305,   306,   307,   308,   309,   192,   335,   342,
      24,    25,    26,   341,    27,   345,   351,   369,   356,   364,
     496,   374,   357,   370,    28,    29,   371,   372,   378,   382,
     383,   384,   161,   416,   163,   385,   417,    30,   418,   386,
     419,   420,   393,   421,   422,   423,   424,   425,   268,   394,
     404,   409,   426,    31,   449,    32,   448,   458,   465,   269,
     477,   472,   474,   270,   271,  -299,   496,   481,   482,   483,
     489,   427,   428,   160,   498,   272,   273,   274,   275,   276,
     277,   278,   520,   279,   499,   429,   500,   519,   496,   280,
     281,   502,   282,   283,   284,   285,   286,   496,   161,   162,
     163,   287,   288,   289,   160,   503,   522,   290,   523,   524,
     451,   532,   525,   526,   534,   164,   165,   166,   167,   537,
     535,   536,   539,   168,   169,   170,   171,   172,   173,   161,
     162,   163,   560,   291,   540,   160,   550,   557,   292,   558,
     562,   571,   576,   579,   581,   567,   164,   165,   166,   167,
     570,   293,   325,    42,   168,   169,   170,   171,   172,   173,
     161,   162,   163,   447,   527,   471,    60,   340,   330,   577,
     444,   298,   578,   566,   561,   510,   232,   164,   165,   166,
     167,   363,   174,   555,     0,   168,   169,   170,   171,   172,
     173,     0,     0,   531,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   376
};

static const yytype_int16 yycheck[] =
{
      15,     8,     5,   138,   139,    92,   141,   142,   248,   124,
      13,   245,   310,    20,   121,   246,   314,     4,   336,   417,
     155,   435,   429,   130,    21,     6,   238,     3,   125,     1,
      28,   329,     6,     5,   332,    21,    22,    26,     9,   174,
      11,    54,    55,   338,    16,    34,    35,   123,    20,    21,
       3,    27,     8,    32,    30,    31,    59,   183,   193,    90,
      32,    33,    34,    35,    36,    37,    38,    54,    40,    48,
     177,   178,    54,    55,    46,    47,   123,    49,    50,    51,
      52,    53,   316,    90,    39,   124,    58,    59,    60,   104,
      12,    48,    64,     3,   125,    71,     1,    19,   124,   112,
      55,   104,    79,   123,     9,   240,    92,   127,   320,   235,
      15,   123,    17,    18,   412,   427,   428,    27,    90,   254,
      30,    31,    83,    95,    29,   123,   123,    84,   123,    48,
     265,   124,    85,    86,    87,   123,   108,   123,   433,   128,
      48,   123,   549,   124,   121,   122,   153,   123,    83,   127,
     124,   123,   123,   125,   568,   123,   128,   249,    72,    73,
     117,    71,   123,   123,   167,   563,   123,   124,    80,   126,
     127,   411,   120,   407,   492,   310,   291,   408,   390,   314,
     272,   273,   317,   131,   496,   123,   498,   274,   123,   103,
     325,   105,   199,   124,   329,   123,   124,   332,   117,   130,
     131,   113,   114,   123,   123,   124,   115,   126,   127,   117,
     508,   123,   124,   123,    84,   123,   124,   127,   126,   123,
     125,    28,    39,   128,    41,    42,    43,   126,    45,   125,
     337,   123,   124,   531,   125,   127,    95,    96,    97,    98,
      26,   376,   125,   477,   123,   543,   125,   125,    34,    35,
     117,   118,   119,   132,   125,   553,   125,   124,   393,   126,
     125,   264,   249,   561,   123,   125,   133,   134,   566,    22,
      23,   125,   275,   388,   128,   282,   125,   412,   132,   125,
     283,   288,   124,   290,   518,   272,   273,   124,   130,   131,
     125,   123,   124,   130,   131,   127,   113,   114,     1,   124,
      68,   125,     5,   125,   128,   130,   131,   125,   132,   125,
     128,   125,   128,    16,   132,   124,   132,    20,    21,   125,
     125,   555,   128,   128,   124,    28,   132,   132,   123,    32,
      33,    34,    35,    36,    37,    38,     8,    40,    12,    13,
      14,   123,   124,    46,    47,   123,    49,    50,    51,    52,
      53,   358,   359,   360,   361,    58,    59,    60,   365,   366,
      24,    64,    69,    70,   127,   352,   123,   124,   123,   124,
     129,   378,   109,   110,    54,    55,    62,    63,   123,   466,
     467,   123,   129,   123,    90,   116,    57,    90,   127,   125,
       0,     1,    95,     3,     4,     5,   531,     7,   127,     9,
      10,    11,   417,   127,    14,   108,    21,   123,   123,   127,
      20,   124,   547,   127,   124,    25,   124,    27,    28,    29,
     123,     3,   125,   426,   123,   128,   123,   128,   124,   123,
     123,   438,    77,   124,    44,   124,   123,   127,   123,   123,
     123,    22,    85,    53,   123,   127,    56,   128,    58,    59,
     128,   458,   128,     9,   124,    65,    66,    67,   124,   124,
      22,   124,   124,   124,   124,   124,   124,   123,   123,   123,
      80,    81,    82,   124,    84,   125,   123,     8,   124,   123,
     495,    61,   124,   123,    94,    95,   123,   123,    84,    35,
     125,   125,    74,    75,    76,   123,    78,   107,    80,   123,
      82,    83,   125,    85,    86,    87,    88,    89,     5,   128,
     124,   128,    94,   123,   123,   125,   124,    42,   123,    16,
      85,   128,   128,    20,    21,   128,   541,   124,   128,   128,
     128,   113,   114,    49,   123,    32,    33,    34,    35,    36,
      37,    38,   125,    40,   123,   127,   123,   123,   563,    46,
      47,   124,    49,    50,    51,    52,    53,   572,    74,    75,
      76,    58,    59,    60,    49,   124,   123,    64,   123,   123,
      39,   111,   125,   124,   124,    91,    92,    93,    94,   128,
     125,   125,   123,    99,   100,   101,   102,   103,   104,    74,
      75,    76,   124,    90,   123,    49,   123,   123,    95,   123,
     128,   123,   123,   123,   123,   128,    91,    92,    93,    94,
     128,   108,   243,     1,    99,   100,   101,   102,   103,   104,
      74,    75,    76,   344,   452,   381,   123,   260,   125,   572,
     339,   205,   574,   551,   541,   433,   175,    91,    92,    93,
      94,   279,   127,   516,    -1,    99,   100,   101,   102,   103,
     104,    -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   136,     0,     1,     3,     4,     5,     7,     9,    10,
      11,    14,    20,    25,    27,    29,    44,    53,    56,    58,
      59,    65,    66,    67,    80,    81,    82,    84,    94,    95,
     107,   123,   125,   142,   143,   144,   147,   151,   153,   156,
     160,   161,   165,   166,   173,   177,   178,   180,   192,   193,
     125,   123,   124,   137,   138,   123,   169,     6,   124,     8,
     123,   141,   124,   124,   123,    21,    22,    92,   123,   169,
     123,   140,    80,   113,   114,   123,   124,   170,   187,   124,
      21,   123,   123,   123,   141,   123,   127,   123,   123,   115,
      84,   123,   126,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,    28,   125,   125,    68,   194,   137,
     124,   169,     8,   123,   123,    24,    22,    23,   157,   123,
     181,   123,   129,   129,    90,   218,    72,    73,   103,   105,
     189,   123,    54,    55,   123,   167,    57,   168,   127,   125,
     225,   127,   127,   116,   141,   140,   123,   169,   170,   171,
      21,   196,   123,   162,   123,   127,   127,   218,   124,   124,
      49,    74,    75,    76,    91,    92,    93,    94,    99,   100,
     101,   102,   103,   104,   127,   220,   222,   123,   124,   218,
     123,   124,   172,   123,   225,   225,   128,   152,   225,   225,
     123,   179,   123,   127,   198,    69,    70,   195,   174,     9,
      11,   141,   163,   164,   225,   182,    77,   221,   124,   130,
     131,   124,   130,   131,   124,   130,   131,    95,    96,    97,
      98,   169,   124,   124,   123,   124,   130,   131,   123,   123,
     223,   225,   221,   218,   218,   123,   172,   128,   148,   150,
     155,   170,   128,   154,   128,   145,   127,   183,   225,     3,
      27,    30,    31,    71,   127,   169,   199,   201,   127,   141,
     124,    22,    26,    34,    35,   158,   159,     1,     5,    16,
      20,    21,    32,    33,    34,    35,    36,    37,    38,    40,
      46,    47,    49,    50,    51,    52,    53,    58,    59,    60,
      64,    90,    95,   108,   125,   128,   141,   165,   177,   185,
      83,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     219,   222,   123,   172,   149,   150,    85,   125,   132,   225,
     226,    79,   121,   122,   216,   155,   123,   137,   139,   146,
     125,   185,   197,   198,   138,   123,   225,   212,   213,   175,
     164,   124,   123,   169,   225,   125,     6,   124,    12,    19,
      22,   123,   138,   138,   140,   169,   124,   124,    39,    41,
      42,    43,    45,   187,   123,    32,    48,   141,   169,     8,
     123,   123,   123,   141,    61,   141,   127,   222,    84,   109,
     110,   190,    35,   125,   125,   123,   123,   225,   226,   225,
     226,   139,   225,   125,   128,   150,   117,   118,   119,   124,
     126,   133,   134,   227,   124,   225,   225,   226,   184,   128,
     225,   226,   200,   201,   218,     3,    75,    78,    80,    82,
      83,    85,    86,    87,    88,    89,    94,   113,   114,   127,
     202,   206,   208,   214,   215,   217,   220,     1,     9,    15,
      17,    18,   125,   128,   166,   176,   128,   159,   124,   123,
     137,    39,    55,   186,   141,   141,   141,   141,    42,    12,
      13,    14,   188,   141,   141,   123,    62,    63,   225,   141,
     112,   167,   128,   222,   128,   150,   225,    85,   120,   131,
     229,   124,   128,   128,   139,     1,   125,   128,   185,   128,
     198,   225,   226,    83,   123,   127,   170,   205,   123,   123,
     123,   224,   124,   124,    28,   169,   216,   216,   207,   208,
     215,    48,    84,   117,   126,   127,   139,   211,   228,   123,
     125,   141,   123,   123,   123,   125,   124,   186,   141,   140,
     140,   219,   111,   139,   124,   125,   125,   128,   201,   123,
     123,   127,   203,   204,   205,   216,   216,   125,   128,   226,
     123,   127,   209,   210,   211,   229,   139,   123,   123,   225,
     124,   204,   128,   226,   225,   208,   210,   128,   226,   139,
     128,   123,   128,   205,   128,   211,   123,   203,   209,   123,
     191,   123
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   135,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   137,   138,
     138,   139,   139,   140,   140,   141,   142,   143,   145,   144,
     144,   146,   146,   148,   147,   147,   149,   149,   150,   152,
     151,   151,   154,   153,   153,   155,   155,   156,   157,   156,
     158,   158,   159,   159,   159,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   162,   161,
     163,   163,   163,   164,   164,   165,   166,   166,   166,   166,
     166,   167,   167,   168,   168,   169,   170,   170,   171,   171,
     172,   172,   174,   173,   175,   175,   175,   175,   176,   176,
     176,   176,   176,   178,   179,   177,   181,   180,   182,   182,
     182,   182,   182,   183,   183,   183,   184,   184,   184,   184,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   186,   186,   187,   187,   188,   188,   188,   189,
     189,   190,   190,   191,   191,   192,   193,   193,   193,   194,
     194,   195,   195,   196,   196,   196,   197,   197,   198,   199,
     199,   200,   200,   201,   201,   201,   201,   201,   201,   202,
     202,   202,   202,   203,   203,   203,   204,   204,   205,   206,
     206,   207,   207,   208,   208,   208,   209,   209,   209,   210,
     210,   211,   211,   211,   211,   212,   213,   212,   214,   214,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   216,   216,   216,   216,   216,   217,   217,   217,
     217,   218,   218,   218,   219,   219,   220,   220,   221,   221,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   223,   224,   225,   225,
     226,   226,   226,   226,   227,   227,   227,   227,   227,   227,
     228,   228,   229,   229
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     2,     1,     1,     3,     2,     0,     8,
       5,     1,     3,     0,     8,     5,     1,     3,     2,     0,
       7,     4,     0,     8,     5,     3,     5,     2,     0,     8,
       1,     3,     2,     2,     2,     2,     3,     2,     2,     3,
       3,     2,     2,     2,     3,     2,     1,     4,     6,     1,
       3,     3,     4,     3,     4,     2,     2,     3,     0,     5,
       1,     3,     2,     0,     2,     5,     3,     4,     5,     5,
       4,     1,     1,     1,     0,     1,     3,     3,     1,     1,
       0,     1,     0,     8,     0,     2,     3,     3,     2,     3,
       3,     2,     1,     0,     0,     5,     0,     6,     0,     2,
       3,     3,     3,     4,     3,     0,     0,     2,     3,     3,
       2,     2,     3,     2,     2,     2,     2,     1,     1,     2,
       2,     2,     3,     3,     3,     3,     4,     3,     3,     2,
       2,     3,     3,     2,     3,     4,     4,     4,     3,     8,
       2,     2,     6,     1,     1,     2,     3,     2,     2,     2,
       3,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     7,     1,     1,     1,     0,
       1,     1,     1,     0,     2,     6,     1,     3,     1,     1,
       5,     1,     3,     1,     1,     2,     2,     1,     1,     2,
       2,     2,     4,     1,     3,     4,     1,     3,     2,     1,
       3,     1,     3,     2,     4,     3,     1,     3,     4,     1,
       3,     1,     1,     2,     3,     0,     0,     2,     1,     2,
       1,     1,     2,     2,     2,     3,     3,     2,     2,     3,
       2,     2,     0,     1,     2,     3,     4,     1,     1,     1,
       1,     0,     2,     6,     3,     1,     1,     1,     0,     1,
       2,     3,     3,     2,     3,     3,     2,     3,     3,     2,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     3,     4,     4,     2,     1,     1,     0,     2,
       0,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 266 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { file->errors++; }
#line 2214 "parse.c"
    break;

  case 18: /* asnumber: NUMBER  */
#line 269 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2229 "parse.c"
    break;

  case 19: /* as4number: STRING  */
#line 280 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2266 "parse.c"
    break;

  case 20: /* as4number: asnumber  */
#line 312 "../../../openbgpd-portable/src/bgpd/parse.y"
                           {
			if ((yyvsp[0].v.number) == AS_TRANS || (yyvsp[0].v.number) == 0) {
				yyerror("AS %u is reserved and may not be used",
				    (u_int32_t)(yyvsp[0].v.number));
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2279 "parse.c"
    break;

  case 21: /* as4number_any: STRING  */
#line 322 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2311 "parse.c"
    break;

  case 22: /* as4number_any: asnumber  */
#line 349 "../../../openbgpd-portable/src/bgpd/parse.y"
                           {
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2319 "parse.c"
    break;

  case 23: /* string: string STRING  */
#line 354 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (asprintf(&(yyval.v.string), "%s %s", (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1)
				fatal("string: asprintf");
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.string));
		}
#line 2330 "parse.c"
    break;

  case 25: /* yesno: STRING  */
#line 363 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2348 "parse.c"
    break;

  case 26: /* varset: STRING '=' string  */
#line 378 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2371 "parse.c"
    break;

  case 27: /* include: INCLUDE STRING  */
#line 398 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2389 "parse.c"
    break;

  case 28: /* $@1: %empty  */
#line 413 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2406 "parse.c"
    break;

  case 29: /* as_set: ASSET STRING '{' optnl $@1 as_set_l optnl '}'  */
#line 424 "../../../openbgpd-portable/src/bgpd/parse.y"
                                     {
			done_as_set();
		}
#line 2414 "parse.c"
    break;

  case 30: /* as_set: ASSET STRING '{' optnl '}'  */
#line 427 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (new_as_set((yyvsp[-3].v.string)) != 0) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
		}
#line 2426 "parse.c"
    break;

  case 31: /* as_set_l: as4number_any  */
#line 435 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { add_as_set((yyvsp[0].v.number)); }
#line 2432 "parse.c"
    break;

  case 32: /* as_set_l: as_set_l comma as4number_any  */
#line 436 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { add_as_set((yyvsp[0].v.number)); }
#line 2438 "parse.c"
    break;

  case 33: /* $@2: %empty  */
#line 438 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curpset = new_prefix_set((yyvsp[-2].v.string), 0)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			free((yyvsp[-2].v.string));
		}
#line 2450 "parse.c"
    break;

  case 34: /* prefixset: PREFIXSET STRING '{' optnl $@2 prefixset_l optnl '}'  */
#line 444 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2459 "parse.c"
    break;

  case 35: /* prefixset: PREFIXSET STRING '{' optnl '}'  */
#line 448 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curpset = new_prefix_set((yyvsp[-3].v.string), 0)) == NULL) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2473 "parse.c"
    break;

  case 36: /* prefixset_l: prefixset_item  */
#line 458 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2492 "parse.c"
    break;

  case 37: /* prefixset_l: prefixset_l comma prefixset_item  */
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
#line 2511 "parse.c"
    break;

  case 38: /* prefixset_item: prefix prefixlenop  */
#line 488 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2531 "parse.c"
    break;

  case 39: /* $@3: %empty  */
#line 505 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			curroatree = &conf->roa;
		}
#line 2539 "parse.c"
    break;

  case 40: /* roa_set: ROASET '{' optnl $@3 roa_set_l optnl '}'  */
#line 507 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			curroatree = NULL;
		}
#line 2547 "parse.c"
    break;

  case 42: /* $@4: %empty  */
#line 513 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			if ((curoset = new_prefix_set((yyvsp[-2].v.string), 1)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			curroatree = &curoset->roaitems;
			free((yyvsp[-2].v.string));
		}
#line 2560 "parse.c"
    break;

  case 43: /* origin_set: ORIGINSET STRING '{' optnl $@4 roa_set_l optnl '}'  */
#line 520 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			SIMPLEQ_INSERT_TAIL(&conf->originsets, curoset, entry);
			curoset = NULL;
			curroatree = NULL;
		}
#line 2570 "parse.c"
    break;

  case 44: /* origin_set: ORIGINSET STRING '{' optnl '}'  */
#line 525 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2585 "parse.c"
    break;

  case 45: /* roa_set_l: prefixset_item SOURCEAS as4number_any  */
#line 537 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                        {
			if ((yyvsp[-2].v.prefixset_item)->p.len_min != (yyvsp[-2].v.prefixset_item)->p.len) {
				yyerror("unsupported prefixlen operation in "
				    "roa-set");
				free((yyvsp[-2].v.prefixset_item));
				YYERROR;
			}
			add_roa_set((yyvsp[-2].v.prefixset_item), (yyvsp[0].v.number), (yyvsp[-2].v.prefixset_item)->p.len_max);
			free((yyvsp[-2].v.prefixset_item));
		}
#line 2600 "parse.c"
    break;

  case 46: /* roa_set_l: roa_set_l comma prefixset_item SOURCEAS as4number_any  */
#line 547 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                        {
			if ((yyvsp[-2].v.prefixset_item)->p.len_min != (yyvsp[-2].v.prefixset_item)->p.len) {
				yyerror("unsupported prefixlen operation in "
				    "roa-set");
				free((yyvsp[-2].v.prefixset_item));
				YYERROR;
			}
			add_roa_set((yyvsp[-2].v.prefixset_item), (yyvsp[0].v.number), (yyvsp[-2].v.prefixset_item)->p.len_max);
			free((yyvsp[-2].v.prefixset_item));
		}
#line 2615 "parse.c"
    break;

  case 47: /* rtr: RTR address  */
#line 559 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = 323;
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2629 "parse.c"
    break;

  case 48: /* $@5: %empty  */
#line 568 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = 323;
		}
#line 2638 "parse.c"
    break;

  case 49: /* rtr: RTR address $@5 '{' optnl rtropt_l optnl '}'  */
#line 571 "../../../openbgpd-portable/src/bgpd/parse.y"
                                               {
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2650 "parse.c"
    break;

  case 52: /* rtropt: DESCR STRING  */
#line 583 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2666 "parse.c"
    break;

  case 53: /* rtropt: LOCALADDR address  */
#line 594 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.addr).aid != currtr->remote_addr.aid) {
				yyerror("Bad address family %s for "
				    "local-addr", aid2str((yyvsp[0].v.addr).aid));
				YYERROR;
			}
			currtr->local_addr = (yyvsp[0].v.addr);
		}
#line 2679 "parse.c"
    break;

  case 54: /* rtropt: PORT NUMBER  */
#line 602 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("local-port must be between %u and %u",
				    1, USHRT_MAX);
				YYERROR;
			}
			currtr->remote_port = (yyvsp[0].v.number);
		}
#line 2692 "parse.c"
    break;

  case 55: /* conf_main: AS as4number  */
#line 612 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			conf->as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				conf->short_as = AS_TRANS;
			else
				conf->short_as = (yyvsp[0].v.number);
		}
#line 2704 "parse.c"
    break;

  case 56: /* conf_main: AS as4number asnumber  */
#line 619 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			conf->as = (yyvsp[-1].v.number);
			conf->short_as = (yyvsp[0].v.number);
		}
#line 2713 "parse.c"
    break;

  case 57: /* conf_main: ROUTERID address  */
#line 623 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.addr).aid != AID_INET) {
				yyerror("router-id must be an IPv4 address");
				YYERROR;
			}
			conf->bgpid = (yyvsp[0].v.addr).v4.s_addr;
		}
#line 2725 "parse.c"
    break;

  case 58: /* conf_main: HOLDTIME NUMBER  */
#line 630 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->holdtime = (yyvsp[0].v.number);
		}
#line 2738 "parse.c"
    break;

  case 59: /* conf_main: HOLDTIME YMIN NUMBER  */
#line 638 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->min_holdtime = (yyvsp[0].v.number);
		}
#line 2751 "parse.c"
    break;

  case 60: /* conf_main: LISTEN ON address  */
#line 646 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2770 "parse.c"
    break;

  case 61: /* conf_main: FIBPRIORITY NUMBER  */
#line 660 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) <= RTP_NONE || (yyvsp[0].v.number) > RTP_MAX) {
				yyerror("invalid fib-priority");
				YYERROR;
			}
			conf->fib_priority = (yyvsp[0].v.number);
		}
#line 2782 "parse.c"
    break;

  case 62: /* conf_main: FIBUPDATE yesno  */
#line 667 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2798 "parse.c"
    break;

  case 63: /* conf_main: TRANSPARENT yesno  */
#line 678 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_DECISION_TRANS_AS;
			else
				conf->flags &= ~BGPD_FLAG_DECISION_TRANS_AS;
		}
#line 2809 "parse.c"
    break;

  case 64: /* conf_main: REJECT ASSET yesno  */
#line 684 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_NO_AS_SET;
			else
				conf->flags &= ~BGPD_FLAG_NO_AS_SET;
		}
#line 2820 "parse.c"
    break;

  case 65: /* conf_main: LOG STRING  */
#line 690 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (!strcmp((yyvsp[0].v.string), "updates"))
				conf->log |= BGPD_LOG_UPDATES;
			else {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 2834 "parse.c"
    break;

  case 67: /* conf_main: DUMP STRING STRING optnumber  */
#line 700 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2867 "parse.c"
    break;

  case 68: /* conf_main: DUMP RIB STRING STRING STRING optnumber  */
#line 728 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2904 "parse.c"
    break;

  case 70: /* conf_main: RDE STRING EVALUATE  */
#line 761 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2919 "parse.c"
    break;

  case 71: /* conf_main: RDE STRING IGNORE  */
#line 771 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2934 "parse.c"
    break;

  case 72: /* conf_main: RDE MED COMPARE STRING  */
#line 781 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2952 "parse.c"
    break;

  case 73: /* conf_main: RDE EVALUATE STRING  */
#line 794 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2970 "parse.c"
    break;

  case 74: /* conf_main: NEXTHOP QUALIFY VIA STRING  */
#line 807 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 2988 "parse.c"
    break;

  case 75: /* conf_main: RTABLE NUMBER  */
#line 820 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3009 "parse.c"
    break;

  case 76: /* conf_main: CONNECTRETRY NUMBER  */
#line 836 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			if ((yyvsp[0].v.number) > USHRT_MAX || (yyvsp[0].v.number) < 1) {
				yyerror("invalid connect-retry");
				YYERROR;
			}
			conf->connectretry = (yyvsp[0].v.number);
		}
#line 3021 "parse.c"
    break;

  case 77: /* conf_main: SOCKET STRING restricted  */
#line 843 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3040 "parse.c"
    break;

  case 78: /* $@6: %empty  */
#line 859 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if ((currib = add_rib((yyvsp[0].v.string))) == NULL) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 3052 "parse.c"
    break;

  case 79: /* rib: RDE RIB STRING $@6 ribopts  */
#line 865 "../../../openbgpd-portable/src/bgpd/parse.y"
                          {
			currib = NULL;
		}
#line 3060 "parse.c"
    break;

  case 81: /* ribopts: RTABLE NUMBER fibupdate  */
#line 870 "../../../openbgpd-portable/src/bgpd/parse.y"
                                          {
			if ((yyvsp[-1].v.number) > RT_TABLEID_MAX) {
				yyerror("rtable %llu too big: max %u", (yyvsp[-1].v.number),
				    RT_TABLEID_MAX);
				YYERROR;
			}
			if (rib_add_fib(currib, (yyvsp[-1].v.number)) == -1)
				YYERROR;
		}
#line 3074 "parse.c"
    break;

  case 82: /* ribopts: yesno EVALUATE  */
#line 879 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if ((yyvsp[-1].v.number)) {
				yyerror("bad rde rib definition");
				YYERROR;
			}
			currib->flags |= F_RIB_NOEVALUATE;
		}
#line 3086 "parse.c"
    break;

  case 84: /* fibupdate: FIBUPDATE yesno  */
#line 889 "../../../openbgpd-portable/src/bgpd/parse.y"
                                  {
			if ((yyvsp[0].v.number) == 0)
				currib->flags |= F_RIB_NOFIBSYNC;
			else
				currib->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3097 "parse.c"
    break;

  case 85: /* mrtdump: DUMP STRING inout STRING optnumber  */
#line 897 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3130 "parse.c"
    break;

  case 86: /* network: NETWORK prefix filter_set  */
#line 927 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3156 "parse.c"
    break;

  case 87: /* network: NETWORK PREFIXSET STRING filter_set  */
#line 948 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3190 "parse.c"
    break;

  case 88: /* network: NETWORK family RTLABEL STRING filter_set  */
#line 977 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3214 "parse.c"
    break;

  case 89: /* network: NETWORK family PRIORITY NUMBER filter_set  */
#line 996 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3243 "parse.c"
    break;

  case 90: /* network: NETWORK family nettype filter_set  */
#line 1020 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3266 "parse.c"
    break;

  case 91: /* inout: IN  */
#line 1040 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 3272 "parse.c"
    break;

  case 92: /* inout: OUT  */
#line 1041 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 3278 "parse.c"
    break;

  case 93: /* restricted: RESTRICTED  */
#line 1044 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 3284 "parse.c"
    break;

  case 94: /* restricted: %empty  */
#line 1045 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 3290 "parse.c"
    break;

  case 95: /* address: STRING  */
#line 1048 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3314 "parse.c"
    break;

  case 96: /* prefix: STRING '/' NUMBER  */
#line 1069 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3337 "parse.c"
    break;

  case 97: /* prefix: NUMBER '/' NUMBER  */
#line 1087 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3360 "parse.c"
    break;

  case 98: /* addrspec: address  */
#line 1107 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			memcpy(&(yyval.v.prefix).prefix, &(yyvsp[0].v.addr), sizeof(struct bgpd_addr));
			if ((yyval.v.prefix).prefix.aid == AID_INET)
				(yyval.v.prefix).len = 32;
			else
				(yyval.v.prefix).len = 128;
		}
#line 3372 "parse.c"
    break;

  case 100: /* optnumber: %empty  */
#line 1117 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0; }
#line 3378 "parse.c"
    break;

  case 102: /* $@7: %empty  */
#line 1121 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3421 "parse.c"
    break;

  case 103: /* l3vpn: VPN STRING ON STRING $@7 '{' l3vpnopts_l '}'  */
#line 1158 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			/* insert into list */
			SIMPLEQ_INSERT_TAIL(&conf->l3vpns, curvpn, entry);
			curvpn = NULL;
			netconf = &conf->networks;
		}
#line 3432 "parse.c"
    break;

  case 108: /* l3vpnopts: RD STRING  */
#line 1172 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3455 "parse.c"
    break;

  case 109: /* l3vpnopts: EXPORTTRGT STRING STRING  */
#line 1190 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3478 "parse.c"
    break;

  case 110: /* l3vpnopts: IMPORTTRGT STRING STRING  */
#line 1208 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3501 "parse.c"
    break;

  case 111: /* l3vpnopts: FIBUPDATE yesno  */
#line 1226 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if ((yyvsp[0].v.number) == 0)
				curvpn->flags |= F_RIB_NOFIBSYNC;
			else
				curvpn->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3512 "parse.c"
    break;

  case 113: /* $@8: %empty  */
#line 1235 "../../../openbgpd-portable/src/bgpd/parse.y"
                  {	curpeer = new_peer(); }
#line 3518 "parse.c"
    break;

  case 114: /* $@9: %empty  */
#line 1236 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3537 "parse.c"
    break;

  case 115: /* neighbor: $@8 NEIGHBOR addrspec $@9 peeropts_h  */
#line 1250 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3560 "parse.c"
    break;

  case 116: /* $@10: %empty  */
#line 1270 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3583 "parse.c"
    break;

  case 117: /* group: GROUP string $@10 '{' groupopts_l '}'  */
#line 1287 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3601 "parse.c"
    break;

  case 130: /* peeropts: REMOTEAS as4number  */
#line 1320 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.remote_as = (yyvsp[0].v.number);
		}
#line 3609 "parse.c"
    break;

  case 131: /* peeropts: LOCALAS as4number  */
#line 1323 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.local_as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				curpeer->conf.local_short_as = AS_TRANS;
			else
				curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3621 "parse.c"
    break;

  case 132: /* peeropts: LOCALAS as4number asnumber  */
#line 1330 "../../../openbgpd-portable/src/bgpd/parse.y"
                                             {
			curpeer->conf.local_as = (yyvsp[-1].v.number);
			curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3630 "parse.c"
    break;

  case 133: /* peeropts: DESCR string  */
#line 1334 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3646 "parse.c"
    break;

  case 134: /* peeropts: LOCALADDR address  */
#line 1345 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3664 "parse.c"
    break;

  case 135: /* peeropts: yesno LOCALADDR  */
#line 1358 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3679 "parse.c"
    break;

  case 136: /* peeropts: MULTIHOP NUMBER  */
#line 1368 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 2 || (yyvsp[0].v.number) > 255) {
				yyerror("invalid multihop distance %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			curpeer->conf.distance = (yyvsp[0].v.number);
		}
#line 3691 "parse.c"
    break;

  case 137: /* peeropts: PASSIVE  */
#line 1375 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.passive = 1;
		}
#line 3699 "parse.c"
    break;

  case 138: /* peeropts: DOWN  */
#line 1378 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.down = 1;
		}
#line 3707 "parse.c"
    break;

  case 139: /* peeropts: DOWN STRING  */
#line 1381 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3723 "parse.c"
    break;

  case 140: /* peeropts: RIB STRING  */
#line 1392 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3744 "parse.c"
    break;

  case 141: /* peeropts: HOLDTIME NUMBER  */
#line 1408 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.holdtime = (yyvsp[0].v.number);
		}
#line 3757 "parse.c"
    break;

  case 142: /* peeropts: HOLDTIME YMIN NUMBER  */
#line 1416 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.min_holdtime = (yyvsp[0].v.number);
		}
#line 3770 "parse.c"
    break;

  case 143: /* peeropts: ANNOUNCE family safi  */
#line 1424 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3794 "parse.c"
    break;

  case 144: /* peeropts: ANNOUNCE CAPABILITIES yesno  */
#line 1443 "../../../openbgpd-portable/src/bgpd/parse.y"
                                              {
			curpeer->conf.announce_capa = (yyvsp[0].v.number);
		}
#line 3802 "parse.c"
    break;

  case 145: /* peeropts: ANNOUNCE REFRESH yesno  */
#line 1446 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.refresh = (yyvsp[0].v.number);
		}
#line 3810 "parse.c"
    break;

  case 146: /* peeropts: ANNOUNCE ENHANCED REFRESH yesno  */
#line 1449 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                  {
			curpeer->conf.capabilities.enhanced_rr = (yyvsp[0].v.number);
		}
#line 3818 "parse.c"
    break;

  case 147: /* peeropts: ANNOUNCE RESTART yesno  */
#line 1452 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.grestart.restart = (yyvsp[0].v.number);
		}
#line 3826 "parse.c"
    break;

  case 148: /* peeropts: ANNOUNCE AS4BYTE yesno  */
#line 1455 "../../../openbgpd-portable/src/bgpd/parse.y"
                                         {
			curpeer->conf.capabilities.as4byte = (yyvsp[0].v.number);
		}
#line 3834 "parse.c"
    break;

  case 149: /* peeropts: EXPORT NONE  */
#line 1458 "../../../openbgpd-portable/src/bgpd/parse.y"
                              {
			curpeer->conf.export_type = EXPORT_NONE;
		}
#line 3842 "parse.c"
    break;

  case 150: /* peeropts: EXPORT DEFAULTROUTE  */
#line 1461 "../../../openbgpd-portable/src/bgpd/parse.y"
                                      {
			curpeer->conf.export_type = EXPORT_DEFAULT_ROUTE;
		}
#line 3850 "parse.c"
    break;

  case 151: /* peeropts: ENFORCE NEIGHBORAS yesno  */
#line 1464 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_as = ENFORCE_AS_OFF;
		}
#line 3861 "parse.c"
    break;

  case 152: /* peeropts: ENFORCE LOCALAS yesno  */
#line 1470 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_local_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_local_as = ENFORCE_AS_OFF;
		}
#line 3872 "parse.c"
    break;

  case 153: /* peeropts: ASOVERRIDE yesno  */
#line 1476 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3892 "parse.c"
    break;

  case 154: /* peeropts: MAXPREFIX NUMBER restart  */
#line 1491 "../../../openbgpd-portable/src/bgpd/parse.y"
                                           {
			if ((yyvsp[-1].v.number) < 0 || (yyvsp[-1].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_prefix = (yyvsp[-1].v.number);
			curpeer->conf.max_prefix_restart = (yyvsp[0].v.number);
		}
#line 3905 "parse.c"
    break;

  case 155: /* peeropts: MAXPREFIX NUMBER OUT restart  */
#line 1499 "../../../openbgpd-portable/src/bgpd/parse.y"
                                               {
			if ((yyvsp[-2].v.number) < 0 || (yyvsp[-2].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_out_prefix = (yyvsp[-2].v.number);
			curpeer->conf.max_out_prefix_restart = (yyvsp[0].v.number);
		}
#line 3918 "parse.c"
    break;

  case 156: /* peeropts: TCP MD5SIG PASSWORD string  */
#line 1507 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3941 "parse.c"
    break;

  case 157: /* peeropts: TCP MD5SIG KEY string  */
#line 1525 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3962 "parse.c"
    break;

  case 158: /* peeropts: IPSEC espah IKE  */
#line 1541 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 3977 "parse.c"
    break;

  case 159: /* peeropts: IPSEC espah inout SPI NUMBER STRING STRING encspec  */
#line 1551 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4075 "parse.c"
    break;

  case 160: /* peeropts: TTLSECURITY yesno  */
#line 1644 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			curpeer->conf.ttlsec = (yyvsp[0].v.number);
		}
#line 4083 "parse.c"
    break;

  case 161: /* peeropts: SET filter_set_opt  */
#line 1647 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			struct filter_rule	*r;

			r = get_rule((yyvsp[0].v.filter_set)->type);
			if (merge_filterset(&r->set, (yyvsp[0].v.filter_set)) == -1)
				YYERROR;
		}
#line 4095 "parse.c"
    break;

  case 162: /* peeropts: SET '{' optnl filter_set_l optnl '}'  */
#line 1654 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4112 "parse.c"
    break;

  case 164: /* peeropts: REFLECTOR  */
#line 1667 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4127 "parse.c"
    break;

  case 165: /* peeropts: REFLECTOR address  */
#line 1677 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4148 "parse.c"
    break;

  case 166: /* peeropts: DEPEND ON STRING  */
#line 1693 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4165 "parse.c"
    break;

  case 167: /* peeropts: DEMOTE STRING  */
#line 1705 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4194 "parse.c"
    break;

  case 168: /* peeropts: TRANSPARENT yesno  */
#line 1729 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_TRANS_AS;
			else
				curpeer->conf.flags &= ~PEERFLAG_TRANS_AS;
		}
#line 4205 "parse.c"
    break;

  case 169: /* peeropts: LOG STRING  */
#line 1735 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4221 "parse.c"
    break;

  case 170: /* peeropts: REJECT ASSET yesno  */
#line 1746 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_NO_AS_SET;
			else
				curpeer->conf.flags &= ~PEERFLAG_NO_AS_SET;
		}
#line 4232 "parse.c"
    break;

  case 171: /* peeropts: RDE EVALUATE STRING  */
#line 1752 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4250 "parse.c"
    break;

  case 172: /* restart: %empty  */
#line 1767 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.number) = 0; }
#line 4256 "parse.c"
    break;

  case 173: /* restart: RESTART NUMBER  */
#line 1768 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("restart out of range. 1 to %u minutes",
				    USHRT_MAX);
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 4269 "parse.c"
    break;

  case 174: /* family: IPV4  */
#line 1778 "../../../openbgpd-portable/src/bgpd/parse.y"
                        { (yyval.v.number) = AFI_IPv4; }
#line 4275 "parse.c"
    break;

  case 175: /* family: IPV6  */
#line 1779 "../../../openbgpd-portable/src/bgpd/parse.y"
                        { (yyval.v.number) = AFI_IPv6; }
#line 4281 "parse.c"
    break;

  case 176: /* safi: NONE  */
#line 1782 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_NONE; }
#line 4287 "parse.c"
    break;

  case 177: /* safi: UNICAST  */
#line 1783 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_UNICAST; }
#line 4293 "parse.c"
    break;

  case 178: /* safi: VPN  */
#line 1784 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = SAFI_MPLSVPN; }
#line 4299 "parse.c"
    break;

  case 179: /* nettype: STATIC  */
#line 1787 "../../../openbgpd-portable/src/bgpd/parse.y"
                         { (yyval.v.number) = 1; }
#line 4305 "parse.c"
    break;

  case 180: /* nettype: CONNECTED  */
#line 1788 "../../../openbgpd-portable/src/bgpd/parse.y"
                            { (yyval.v.number) = 0; }
#line 4311 "parse.c"
    break;

  case 181: /* espah: ESP  */
#line 1791 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 1; }
#line 4317 "parse.c"
    break;

  case 182: /* espah: AH  */
#line 1792 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.number) = 0; }
#line 4323 "parse.c"
    break;

  case 183: /* encspec: %empty  */
#line 1795 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			bzero(&(yyval.v.encspec), sizeof((yyval.v.encspec)));
		}
#line 4331 "parse.c"
    break;

  case 184: /* encspec: STRING STRING  */
#line 1798 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4367 "parse.c"
    break;

  case 185: /* filterrule: action quick filter_rib_h direction filter_peer_h filter_match_h filter_set  */
#line 1833 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4395 "parse.c"
    break;

  case 186: /* action: ALLOW  */
#line 1858 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_ALLOW; }
#line 4401 "parse.c"
    break;

  case 187: /* action: DENY  */
#line 1859 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_DENY; }
#line 4407 "parse.c"
    break;

  case 188: /* action: MATCH  */
#line 1860 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = ACTION_NONE; }
#line 4413 "parse.c"
    break;

  case 189: /* quick: %empty  */
#line 1863 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 0; }
#line 4419 "parse.c"
    break;

  case 190: /* quick: QUICK  */
#line 1864 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 1; }
#line 4425 "parse.c"
    break;

  case 191: /* direction: FROM  */
#line 1867 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = DIR_IN; }
#line 4431 "parse.c"
    break;

  case 192: /* direction: TO  */
#line 1868 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = DIR_OUT; }
#line 4437 "parse.c"
    break;

  case 193: /* filter_rib_h: %empty  */
#line 1871 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = NULL; }
#line 4443 "parse.c"
    break;

  case 194: /* filter_rib_h: RIB filter_rib  */
#line 1872 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4449 "parse.c"
    break;

  case 195: /* filter_rib_h: RIB '{' optnl filter_rib_l optnl '}'  */
#line 1873 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_rib) = (yyvsp[-2].v.filter_rib); }
#line 4455 "parse.c"
    break;

  case 196: /* filter_rib_l: filter_rib  */
#line 1875 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4461 "parse.c"
    break;

  case 197: /* filter_rib_l: filter_rib_l comma filter_rib  */
#line 1876 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			(yyvsp[0].v.filter_rib)->next = (yyvsp[-2].v.filter_rib);
			(yyval.v.filter_rib) = (yyvsp[0].v.filter_rib);
		}
#line 4470 "parse.c"
    break;

  case 198: /* filter_rib: STRING  */
#line 1882 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4495 "parse.c"
    break;

  case 200: /* filter_peer_h: '{' optnl filter_peer_l optnl '}'  */
#line 1905 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_peers) = (yyvsp[-2].v.filter_peers); }
#line 4501 "parse.c"
    break;

  case 201: /* filter_peer_l: filter_peer  */
#line 1908 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_peers) = (yyvsp[0].v.filter_peers); }
#line 4507 "parse.c"
    break;

  case 202: /* filter_peer_l: filter_peer_l comma filter_peer  */
#line 1909 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyvsp[0].v.filter_peers)->next = (yyvsp[-2].v.filter_peers);
			(yyval.v.filter_peers) = (yyvsp[0].v.filter_peers);
		}
#line 4516 "parse.c"
    break;

  case 203: /* filter_peer: ANY  */
#line 1915 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.peerid = (yyval.v.filter_peers)->p.groupid = 0;
			(yyval.v.filter_peers)->next = NULL;
		}
#line 4528 "parse.c"
    break;

  case 204: /* filter_peer: address  */
#line 1922 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4553 "parse.c"
    break;

  case 205: /* filter_peer: AS as4number  */
#line 1942 "../../../openbgpd-portable/src/bgpd/parse.y"
                                {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.groupid = (yyval.v.filter_peers)->p.peerid = 0;
			(yyval.v.filter_peers)->p.remote_as = (yyvsp[0].v.number);
		}
#line 4565 "parse.c"
    break;

  case 206: /* filter_peer: GROUP STRING  */
#line 1949 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4591 "parse.c"
    break;

  case 207: /* filter_peer: EBGP  */
#line 1970 "../../../openbgpd-portable/src/bgpd/parse.y"
                       {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ebgp = 1;
		}
#line 4602 "parse.c"
    break;

  case 208: /* filter_peer: IBGP  */
#line 1976 "../../../openbgpd-portable/src/bgpd/parse.y"
                       {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ibgp = 1;
		}
#line 4613 "parse.c"
    break;

  case 209: /* filter_prefix_h: IPV4 prefixlenop  */
#line 1984 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4633 "parse.c"
    break;

  case 210: /* filter_prefix_h: IPV6 prefixlenop  */
#line 1999 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4653 "parse.c"
    break;

  case 211: /* filter_prefix_h: PREFIX filter_prefix  */
#line 2014 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4659 "parse.c"
    break;

  case 212: /* filter_prefix_h: PREFIX '{' filter_prefix_m '}'  */
#line 2015 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4665 "parse.c"
    break;

  case 214: /* filter_prefix_m: '{' filter_prefix_l '}'  */
#line 2019 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4671 "parse.c"
    break;

  case 215: /* filter_prefix_m: '{' filter_prefix_l '}' filter_prefix_m  */
#line 2021 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_prefix_l  *p;

			/* merge, both can be lists */
			for (p = (yyvsp[-2].v.filter_prefix); p != NULL && p->next != NULL; p = p->next)
				;       /* nothing */
			if (p != NULL)
				p->next = (yyvsp[0].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[-2].v.filter_prefix);
		}
#line 4686 "parse.c"
    break;

  case 216: /* filter_prefix_l: filter_prefix  */
#line 2032 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4692 "parse.c"
    break;

  case 217: /* filter_prefix_l: filter_prefix_l comma filter_prefix  */
#line 2033 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyvsp[0].v.filter_prefix)->next = (yyvsp[-2].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix);
		}
#line 4701 "parse.c"
    break;

  case 218: /* filter_prefix: prefix prefixlenop  */
#line 2039 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4719 "parse.c"
    break;

  case 220: /* filter_as_h: '{' filter_as_t_l '}'  */
#line 2055 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4725 "parse.c"
    break;

  case 222: /* filter_as_t_l: filter_as_t_l comma filter_as_t  */
#line 2059 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4740 "parse.c"
    break;

  case 223: /* filter_as_t: filter_as_type filter_as  */
#line 2071 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as)->a.type = (yyvsp[-1].v.u8);
		}
#line 4749 "parse.c"
    break;

  case 224: /* filter_as_t: filter_as_type '{' filter_as_l_h '}'  */
#line 2075 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			struct filter_as_l	*a;

			(yyval.v.filter_as) = (yyvsp[-1].v.filter_as);
			for (a = (yyval.v.filter_as); a != NULL; a = a->next)
				a->a.type = (yyvsp[-3].v.u8);
		}
#line 4761 "parse.c"
    break;

  case 225: /* filter_as_t: filter_as_type ASSET STRING  */
#line 2082 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4787 "parse.c"
    break;

  case 227: /* filter_as_l_h: '{' filter_as_l '}'  */
#line 2106 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4793 "parse.c"
    break;

  case 228: /* filter_as_l_h: '{' filter_as_l '}' filter_as_l_h  */
#line 2108 "../../../openbgpd-portable/src/bgpd/parse.y"
                {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4808 "parse.c"
    break;

  case 230: /* filter_as_l: filter_as_l comma filter_as  */
#line 2121 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			(yyvsp[0].v.filter_as)->next = (yyvsp[-2].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
		}
#line 4817 "parse.c"
    break;

  case 231: /* filter_as: as4number_any  */
#line 2127 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.op = OP_EQ;
		}
#line 4830 "parse.c"
    break;

  case 232: /* filter_as: NEIGHBORAS  */
#line 2135 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.flags = AS_FLAG_NEIGHBORAS;
		}
#line 4841 "parse.c"
    break;

  case 233: /* filter_as: equalityop as4number_any  */
#line 2141 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.op = (yyvsp[-1].v.u8);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
		}
#line 4854 "parse.c"
    break;

  case 234: /* filter_as: as4number_any binaryop as4number_any  */
#line 2149 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4871 "parse.c"
    break;

  case 235: /* filter_match_h: %empty  */
#line 2163 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			bzero(&(yyval.v.filter_match), sizeof((yyval.v.filter_match)));
		}
#line 4879 "parse.c"
    break;

  case 236: /* $@11: %empty  */
#line 2166 "../../../openbgpd-portable/src/bgpd/parse.y"
                  {
			bzero(&fmopts, sizeof(fmopts));
		}
#line 4887 "parse.c"
    break;

  case 237: /* filter_match_h: $@11 filter_match  */
#line 2169 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			memcpy(&(yyval.v.filter_match), &fmopts, sizeof((yyval.v.filter_match)));
		}
#line 4895 "parse.c"
    break;

  case 240: /* filter_elm: filter_prefix_h  */
#line 2178 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4913 "parse.c"
    break;

  case 241: /* filter_elm: filter_as_h  */
#line 2191 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.as_l != NULL) {
				yyerror("AS filters already specified");
				YYERROR;
			}
			fmopts.as_l = (yyvsp[0].v.filter_as);
		}
#line 4925 "parse.c"
    break;

  case 242: /* filter_elm: MAXASLEN NUMBER  */
#line 2198 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4942 "parse.c"
    break;

  case 243: /* filter_elm: MAXASSEQ NUMBER  */
#line 2210 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4959 "parse.c"
    break;

  case 244: /* filter_elm: community STRING  */
#line 2222 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 4982 "parse.c"
    break;

  case 245: /* filter_elm: EXTCOMMUNITY STRING STRING  */
#line 2240 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5009 "parse.c"
    break;

  case 246: /* filter_elm: EXTCOMMUNITY OVS STRING  */
#line 2262 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5033 "parse.c"
    break;

  case 247: /* filter_elm: NEXTHOP address  */
#line 2281 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.addr = (yyvsp[0].v.addr);
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_ADDR;
		}
#line 5046 "parse.c"
    break;

  case 248: /* filter_elm: NEXTHOP NEIGHBOR  */
#line 2289 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_NEIGHBOR;
		}
#line 5058 "parse.c"
    break;

  case 249: /* filter_elm: PREFIXSET STRING prefixlenop  */
#line 2296 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5112 "parse.c"
    break;

  case 250: /* filter_elm: ORIGINSET STRING  */
#line 2345 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5137 "parse.c"
    break;

  case 251: /* filter_elm: OVS validity  */
#line 2365 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (fmopts.m.ovs.is_set) {
				yyerror("ovs filter already specified");
				YYERROR;
			}
			fmopts.m.ovs.validity = (yyvsp[0].v.number);
			fmopts.m.ovs.is_set = 1;
		}
#line 5150 "parse.c"
    break;

  case 252: /* prefixlenop: %empty  */
#line 2375 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                { bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen))); }
#line 5156 "parse.c"
    break;

  case 253: /* prefixlenop: LONGER  */
#line 2376 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen)));
			(yyval.v.prefixlen).op = OP_RANGE;
			(yyval.v.prefixlen).len_min = -1;
			(yyval.v.prefixlen).len_max = -1;
		}
#line 5167 "parse.c"
    break;

  case 254: /* prefixlenop: MAXLEN NUMBER  */
#line 2382 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5183 "parse.c"
    break;

  case 255: /* prefixlenop: PREFIXLEN unaryop NUMBER  */
#line 2393 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5231 "parse.c"
    break;

  case 256: /* prefixlenop: PREFIXLEN NUMBER binaryop NUMBER  */
#line 2436 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5250 "parse.c"
    break;

  case 257: /* filter_as_type: AS  */
#line 2452 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_ALL; }
#line 5256 "parse.c"
    break;

  case 258: /* filter_as_type: SOURCEAS  */
#line 2453 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_SOURCE; }
#line 5262 "parse.c"
    break;

  case 259: /* filter_as_type: TRANSITAS  */
#line 2454 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_TRANSIT; }
#line 5268 "parse.c"
    break;

  case 260: /* filter_as_type: PEERAS  */
#line 2455 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = AS_PEER; }
#line 5274 "parse.c"
    break;

  case 261: /* filter_set: %empty  */
#line 2458 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                { (yyval.v.filter_set_head) = NULL; }
#line 5280 "parse.c"
    break;

  case 262: /* filter_set: SET filter_set_opt  */
#line 2459 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                                {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5292 "parse.c"
    break;

  case 263: /* filter_set: SET '{' optnl filter_set_l optnl '}'  */
#line 2466 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        { (yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head); }
#line 5298 "parse.c"
    break;

  case 264: /* filter_set_l: filter_set_l comma filter_set_opt  */
#line 2469 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                        {
			(yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head);
			if (merge_filterset((yyval.v.filter_set_head), (yyvsp[0].v.filter_set)) == 1)
				YYERROR;
		}
#line 5308 "parse.c"
    break;

  case 265: /* filter_set_l: filter_set_opt  */
#line 2474 "../../../openbgpd-portable/src/bgpd/parse.y"
                                 {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5320 "parse.c"
    break;

  case 266: /* community: COMMUNITY  */
#line 2483 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.u8) = COMMUNITY_TYPE_BASIC; }
#line 5326 "parse.c"
    break;

  case 267: /* community: LARGECOMMUNITY  */
#line 2484 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        { (yyval.v.u8) = COMMUNITY_TYPE_LARGE; }
#line 5332 "parse.c"
    break;

  case 268: /* delete: %empty  */
#line 2487 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 0; }
#line 5338 "parse.c"
    break;

  case 269: /* delete: DELETE  */
#line 2488 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = 1; }
#line 5344 "parse.c"
    break;

  case 270: /* filter_set_opt: LOCALPREF NUMBER  */
#line 2491 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5364 "parse.c"
    break;

  case 271: /* filter_set_opt: LOCALPREF '+' NUMBER  */
#line 2506 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5379 "parse.c"
    break;

  case 272: /* filter_set_opt: LOCALPREF '-' NUMBER  */
#line 2516 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5394 "parse.c"
    break;

  case 273: /* filter_set_opt: MED NUMBER  */
#line 2526 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5414 "parse.c"
    break;

  case 274: /* filter_set_opt: MED '+' NUMBER  */
#line 2541 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5429 "parse.c"
    break;

  case 275: /* filter_set_opt: MED '-' NUMBER  */
#line 2551 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5444 "parse.c"
    break;

  case 276: /* filter_set_opt: METRIC NUMBER  */
#line 2561 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5464 "parse.c"
    break;

  case 277: /* filter_set_opt: METRIC '+' NUMBER  */
#line 2576 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5479 "parse.c"
    break;

  case 278: /* filter_set_opt: METRIC '-' NUMBER  */
#line 2586 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5494 "parse.c"
    break;

  case 279: /* filter_set_opt: WEIGHT NUMBER  */
#line 2596 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5514 "parse.c"
    break;

  case 280: /* filter_set_opt: WEIGHT '+' NUMBER  */
#line 2611 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5529 "parse.c"
    break;

  case 281: /* filter_set_opt: WEIGHT '-' NUMBER  */
#line 2621 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5544 "parse.c"
    break;

  case 282: /* filter_set_opt: NEXTHOP address  */
#line 2631 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP;
			memcpy(&(yyval.v.filter_set)->action.nexthop, &(yyvsp[0].v.addr),
			    sizeof((yyval.v.filter_set)->action.nexthop));
		}
#line 5556 "parse.c"
    break;

  case 283: /* filter_set_opt: NEXTHOP BLACKHOLE  */
#line 2638 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_BLACKHOLE;
		}
#line 5566 "parse.c"
    break;

  case 284: /* filter_set_opt: NEXTHOP REJECT  */
#line 2643 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_REJECT;
		}
#line 5576 "parse.c"
    break;

  case 285: /* filter_set_opt: NEXTHOP NOMODIFY  */
#line 2648 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_NOMODIFY;
		}
#line 5586 "parse.c"
    break;

  case 286: /* filter_set_opt: NEXTHOP SELF  */
#line 2653 "../../../openbgpd-portable/src/bgpd/parse.y"
                                        {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_SELF;
		}
#line 5596 "parse.c"
    break;

  case 287: /* filter_set_opt: PREPEND_SELF NUMBER  */
#line 2658 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5611 "parse.c"
    break;

  case 288: /* filter_set_opt: PREPEND_PEER NUMBER  */
#line 2668 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5626 "parse.c"
    break;

  case 289: /* filter_set_opt: ASOVERRIDE  */
#line 2678 "../../../openbgpd-portable/src/bgpd/parse.y"
                                                {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_AS_OVERRIDE;
		}
#line 5636 "parse.c"
    break;

  case 290: /* filter_set_opt: PFTABLE STRING  */
#line 2683 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5668 "parse.c"
    break;

  case 291: /* filter_set_opt: RTLABEL STRING  */
#line 2710 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5687 "parse.c"
    break;

  case 292: /* filter_set_opt: community delete STRING  */
#line 2724 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5720 "parse.c"
    break;

  case 293: /* filter_set_opt: EXTCOMMUNITY delete STRING STRING  */
#line 2752 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5743 "parse.c"
    break;

  case 294: /* filter_set_opt: EXTCOMMUNITY delete OVS STRING  */
#line 2770 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5764 "parse.c"
    break;

  case 295: /* filter_set_opt: ORIGIN origincode  */
#line 2786 "../../../openbgpd-portable/src/bgpd/parse.y"
                                    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_ORIGIN;
			(yyval.v.filter_set)->action.origin = (yyvsp[0].v.number);
		}
#line 5775 "parse.c"
    break;

  case 296: /* origincode: STRING  */
#line 2794 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5794 "parse.c"
    break;

  case 297: /* validity: STRING  */
#line 2809 "../../../openbgpd-portable/src/bgpd/parse.y"
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
#line 5813 "parse.c"
    break;

  case 304: /* unaryop: '='  */
#line 2834 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_EQ; }
#line 5819 "parse.c"
    break;

  case 305: /* unaryop: NE  */
#line 2835 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_NE; }
#line 5825 "parse.c"
    break;

  case 306: /* unaryop: LE  */
#line 2836 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_LE; }
#line 5831 "parse.c"
    break;

  case 307: /* unaryop: '<'  */
#line 2837 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_LT; }
#line 5837 "parse.c"
    break;

  case 308: /* unaryop: GE  */
#line 2838 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_GE; }
#line 5843 "parse.c"
    break;

  case 309: /* unaryop: '>'  */
#line 2839 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_GT; }
#line 5849 "parse.c"
    break;

  case 310: /* equalityop: '='  */
#line 2842 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_EQ; }
#line 5855 "parse.c"
    break;

  case 311: /* equalityop: NE  */
#line 2843 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_NE; }
#line 5861 "parse.c"
    break;

  case 312: /* binaryop: '-'  */
#line 2846 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_RANGE; }
#line 5867 "parse.c"
    break;

  case 313: /* binaryop: XRANGE  */
#line 2847 "../../../openbgpd-portable/src/bgpd/parse.y"
                                { (yyval.v.u8) = OP_XRANGE; }
#line 5873 "parse.c"
    break;


#line 5877 "parse.c"

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

#line 2850 "../../../openbgpd-portable/src/bgpd/parse.y"


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
add_roa_set(struct prefixset_item *npsi, u_int32_t as, u_int8_t max)
{
	struct roa *roa, *r;

	if ((roa = calloc(1, sizeof(*roa))) == NULL)
		fatal("add_roa_set");

	roa->aid = npsi->p.addr.aid;
	roa->prefixlen = npsi->p.len;
	roa->maxlen = max;
	roa->asnum = as;
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
	if (r != NULL)
		/* just ignore duplicates */
		free(roa);
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
