/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 25 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:337  */

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


#line 246 "parse.c" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AS = 258,
    ROUTERID = 259,
    HOLDTIME = 260,
    YMIN = 261,
    LISTEN = 262,
    ON = 263,
    FIBUPDATE = 264,
    FIBPRIORITY = 265,
    RTABLE = 266,
    NONE = 267,
    UNICAST = 268,
    VPN = 269,
    RD = 270,
    EXPORT = 271,
    EXPORTTRGT = 272,
    IMPORTTRGT = 273,
    DEFAULTROUTE = 274,
    RDE = 275,
    RIB = 276,
    EVALUATE = 277,
    IGNORE = 278,
    COMPARE = 279,
    RTR = 280,
    PORT = 281,
    GROUP = 282,
    NEIGHBOR = 283,
    NETWORK = 284,
    EBGP = 285,
    IBGP = 286,
    LOCALAS = 287,
    REMOTEAS = 288,
    DESCR = 289,
    LOCALADDR = 290,
    MULTIHOP = 291,
    PASSIVE = 292,
    MAXPREFIX = 293,
    RESTART = 294,
    ANNOUNCE = 295,
    CAPABILITIES = 296,
    REFRESH = 297,
    AS4BYTE = 298,
    CONNECTRETRY = 299,
    DEMOTE = 300,
    ENFORCE = 301,
    NEIGHBORAS = 302,
    ASOVERRIDE = 303,
    REFLECTOR = 304,
    DEPEND = 305,
    DOWN = 306,
    DUMP = 307,
    IN = 308,
    OUT = 309,
    SOCKET = 310,
    RESTRICTED = 311,
    LOG = 312,
    TRANSPARENT = 313,
    TCP = 314,
    MD5SIG = 315,
    PASSWORD = 316,
    KEY = 317,
    TTLSECURITY = 318,
    ALLOW = 319,
    DENY = 320,
    MATCH = 321,
    QUICK = 322,
    FROM = 323,
    TO = 324,
    ANY = 325,
    CONNECTED = 326,
    STATIC = 327,
    COMMUNITY = 328,
    EXTCOMMUNITY = 329,
    LARGECOMMUNITY = 330,
    DELETE = 331,
    PREFIX = 332,
    PREFIXLEN = 333,
    PREFIXSET = 334,
    ROASET = 335,
    ORIGINSET = 336,
    OVS = 337,
    ASSET = 338,
    SOURCEAS = 339,
    TRANSITAS = 340,
    PEERAS = 341,
    MAXASLEN = 342,
    MAXASSEQ = 343,
    SET = 344,
    LOCALPREF = 345,
    MED = 346,
    METRIC = 347,
    NEXTHOP = 348,
    REJECT = 349,
    BLACKHOLE = 350,
    NOMODIFY = 351,
    SELF = 352,
    PREPEND_SELF = 353,
    PREPEND_PEER = 354,
    PFTABLE = 355,
    WEIGHT = 356,
    RTLABEL = 357,
    ORIGIN = 358,
    PRIORITY = 359,
    ERROR = 360,
    INCLUDE = 361,
    IPSEC = 362,
    ESP = 363,
    AH = 364,
    SPI = 365,
    IKE = 366,
    IPV4 = 367,
    IPV6 = 368,
    QUALIFY = 369,
    VIA = 370,
    NE = 371,
    LE = 372,
    GE = 373,
    XRANGE = 374,
    LONGER = 375,
    MAXLEN = 376,
    STRING = 377,
    NUMBER = 378
  };
#endif
/* Tokens.  */
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
#define DEMOTE 300
#define ENFORCE 301
#define NEIGHBORAS 302
#define ASOVERRIDE 303
#define REFLECTOR 304
#define DEPEND 305
#define DOWN 306
#define DUMP 307
#define IN 308
#define OUT 309
#define SOCKET 310
#define RESTRICTED 311
#define LOG 312
#define TRANSPARENT 313
#define TCP 314
#define MD5SIG 315
#define PASSWORD 316
#define KEY 317
#define TTLSECURITY 318
#define ALLOW 319
#define DENY 320
#define MATCH 321
#define QUICK 322
#define FROM 323
#define TO 324
#define ANY 325
#define CONNECTED 326
#define STATIC 327
#define COMMUNITY 328
#define EXTCOMMUNITY 329
#define LARGECOMMUNITY 330
#define DELETE 331
#define PREFIX 332
#define PREFIXLEN 333
#define PREFIXSET 334
#define ROASET 335
#define ORIGINSET 336
#define OVS 337
#define ASSET 338
#define SOURCEAS 339
#define TRANSITAS 340
#define PEERAS 341
#define MAXASLEN 342
#define MAXASSEQ 343
#define SET 344
#define LOCALPREF 345
#define MED 346
#define METRIC 347
#define NEXTHOP 348
#define REJECT 349
#define BLACKHOLE 350
#define NOMODIFY 351
#define SELF 352
#define PREPEND_SELF 353
#define PREPEND_PEER 354
#define PFTABLE 355
#define WEIGHT 356
#define RTLABEL 357
#define ORIGIN 358
#define PRIORITY 359
#define ERROR 360
#define INCLUDE 361
#define IPSEC 362
#define ESP 363
#define AH 364
#define SPI 365
#define IKE 366
#define IPV4 367
#define IPV6 368
#define QUALIFY 369
#define VIA 370
#define NE 371
#define LE 372
#define GE 373
#define XRANGE 374
#define LONGER 375
#define MAXLEN 376
#define STRING 377
#define NUMBER 378

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   702

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  134
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  312
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  579

#define YYUNDEFTOK  2
#define YYMAXUTOK   378

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     124,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   129,   131,   130,     2,   128,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     132,   125,   133,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   126,     2,   127,     2,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121,   122,   123
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
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
    1461,  1467,  1473,  1488,  1496,  1504,  1522,  1538,  1548,  1641,
    1644,  1651,  1663,  1664,  1674,  1690,  1702,  1726,  1732,  1743,
    1749,  1764,  1765,  1775,  1776,  1779,  1780,  1781,  1784,  1785,
    1788,  1789,  1792,  1795,  1828,  1855,  1856,  1857,  1860,  1861,
    1864,  1865,  1868,  1869,  1870,  1872,  1873,  1879,  1901,  1902,
    1905,  1906,  1912,  1919,  1939,  1946,  1967,  1973,  1981,  1996,
    2011,  2012,  2015,  2016,  2017,  2029,  2030,  2036,  2051,  2052,
    2055,  2056,  2068,  2072,  2079,  2102,  2103,  2104,  2117,  2118,
    2124,  2132,  2138,  2146,  2160,  2163,  2163,  2171,  2172,  2175,
    2188,  2195,  2207,  2219,  2237,  2259,  2278,  2286,  2293,  2342,
    2362,  2372,  2373,  2379,  2390,  2433,  2449,  2450,  2451,  2452,
    2455,  2456,  2463,  2466,  2471,  2480,  2481,  2484,  2485,  2488,
    2503,  2513,  2523,  2538,  2548,  2558,  2573,  2583,  2593,  2608,
    2618,  2628,  2635,  2640,  2645,  2650,  2655,  2665,  2675,  2680,
    2707,  2721,  2749,  2767,  2783,  2791,  2806,  2821,  2822,  2825,
    2826,  2827,  2828,  2831,  2832,  2833,  2834,  2835,  2836,  2839,
    2840,  2843,  2844
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AS", "ROUTERID", "HOLDTIME", "YMIN",
  "LISTEN", "ON", "FIBUPDATE", "FIBPRIORITY", "RTABLE", "NONE", "UNICAST",
  "VPN", "RD", "EXPORT", "EXPORTTRGT", "IMPORTTRGT", "DEFAULTROUTE", "RDE",
  "RIB", "EVALUATE", "IGNORE", "COMPARE", "RTR", "PORT", "GROUP",
  "NEIGHBOR", "NETWORK", "EBGP", "IBGP", "LOCALAS", "REMOTEAS", "DESCR",
  "LOCALADDR", "MULTIHOP", "PASSIVE", "MAXPREFIX", "RESTART", "ANNOUNCE",
  "CAPABILITIES", "REFRESH", "AS4BYTE", "CONNECTRETRY", "DEMOTE",
  "ENFORCE", "NEIGHBORAS", "ASOVERRIDE", "REFLECTOR", "DEPEND", "DOWN",
  "DUMP", "IN", "OUT", "SOCKET", "RESTRICTED", "LOG", "TRANSPARENT", "TCP",
  "MD5SIG", "PASSWORD", "KEY", "TTLSECURITY", "ALLOW", "DENY", "MATCH",
  "QUICK", "FROM", "TO", "ANY", "CONNECTED", "STATIC", "COMMUNITY",
  "EXTCOMMUNITY", "LARGECOMMUNITY", "DELETE", "PREFIX", "PREFIXLEN",
  "PREFIXSET", "ROASET", "ORIGINSET", "OVS", "ASSET", "SOURCEAS",
  "TRANSITAS", "PEERAS", "MAXASLEN", "MAXASSEQ", "SET", "LOCALPREF", "MED",
  "METRIC", "NEXTHOP", "REJECT", "BLACKHOLE", "NOMODIFY", "SELF",
  "PREPEND_SELF", "PREPEND_PEER", "PFTABLE", "WEIGHT", "RTLABEL", "ORIGIN",
  "PRIORITY", "ERROR", "INCLUDE", "IPSEC", "ESP", "AH", "SPI", "IKE",
  "IPV4", "IPV6", "QUALIFY", "VIA", "NE", "LE", "GE", "XRANGE", "LONGER",
  "MAXLEN", "STRING", "NUMBER", "'\\n'", "'='", "'{'", "'}'", "'/'", "'+'",
  "'-'", "','", "'<'", "'>'", "$accept", "grammar", "asnumber",
  "as4number", "as4number_any", "string", "yesno", "varset", "include",
  "as_set", "$@1", "as_set_l", "prefixset", "$@2", "prefixset_l",
  "prefixset_item", "roa_set", "$@3", "origin_set", "$@4", "roa_set_l",
  "rtr", "$@5", "rtropt_l", "rtropt", "conf_main", "rib", "$@6", "ribopts",
  "fibupdate", "mrtdump", "network", "inout", "restricted", "address",
  "prefix", "addrspec", "optnumber", "l3vpn", "$@7", "l3vpnopts_l",
  "l3vpnopts", "neighbor", "$@8", "$@9", "group", "$@10", "groupopts_l",
  "peeropts_h", "peeropts_l", "peeropts", "restart", "family", "safi",
  "nettype", "espah", "encspec", "filterrule", "action", "quick",
  "direction", "filter_rib_h", "filter_rib_l", "filter_rib",
  "filter_peer_h", "filter_peer_l", "filter_peer", "filter_prefix_h",
  "filter_prefix_m", "filter_prefix_l", "filter_prefix", "filter_as_h",
  "filter_as_t_l", "filter_as_t", "filter_as_l_h", "filter_as_l",
  "filter_as", "filter_match_h", "$@11", "filter_match", "filter_elm",
  "prefixlenop", "filter_as_type", "filter_set", "filter_set_l",
  "community", "delete", "filter_set_opt", "origincode", "validity",
  "optnl", "comma", "unaryop", "equalityop", "binaryop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
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
     375,   376,   377,   378,    10,    61,   123,   125,    47,    43,
      45,    44,    60,    62
};
# endif

#define YYPACT_NINF -413

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-413)))

#define YYTABLE_NINF -300

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -413,   476,  -413,   -81,   -24,   -48,    21,    99,   -10,    -8,
      48,    16,    15,   -48,    52,   109,    58,     5,    61,    63,
     -10,  -413,  -413,  -413,    69,    73,    85,   111,   114,   154,
     122,   130,  -413,   134,   142,   158,   172,   175,   179,   187,
     195,   220,  -413,  -413,   222,   223,   250,   224,   225,   249,
    -413,  -413,  -413,  -413,   211,  -413,  -413,   227,  -413,   -48,
    -413,  -413,  -413,  -413,   337,   233,   234,   335,   201,   236,
    -413,   238,   241,  -413,  -413,   239,   240,   275,    96,  -413,
     247,    -5,   315,  -413,  -413,   246,   251,   248,   254,   258,
     -10,  -413,    52,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,   126,  -413,  -413,  -413,   355,  -413,
    -413,  -413,   259,  -413,  -413,   260,  -413,  -413,   257,  -413,
     261,   275,   262,   263,   536,  -413,  -413,  -413,   266,   267,
     275,   269,  -413,  -413,   274,   270,  -413,  -413,   251,   251,
     268,   251,   251,   276,  -413,   238,   239,  -413,  -413,  -413,
     -51,   221,  -413,    33,  -413,   251,  -413,  -413,  -413,  -413,
    -413,  -413,   308,  -413,   -20,    66,   116,   107,   277,   279,
     283,   124,   284,   285,   251,   308,  -413,   275,   275,  -413,
     288,  -413,  -413,   274,   287,  -413,  -413,   191,   289,   290,
    -413,   292,  -413,   251,  -413,  -413,  -413,    30,   294,   -10,
     280,   367,  -413,  -413,   192,   272,  -413,   -18,  -413,   298,
     302,  -413,   303,   304,  -413,   305,   306,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,  -413,  -413,   309,   310,  -413,  -413,
    -413,   599,   291,  -413,  -413,   274,  -413,  -413,   191,   327,
      82,   -27,  -413,   191,  -413,   203,   556,  -413,   293,   -24,
     312,  -413,  -413,  -413,   251,  -413,   -34,  -413,  -413,  -413,
     422,  -413,   319,   322,   -48,   251,  -413,   321,    22,   106,
     390,   324,   -24,   -24,    52,   -48,   333,  -413,   334,    45,
     325,    38,   -10,   -48,   442,   336,   341,   342,   -10,   399,
     -10,   568,   382,   219,  -413,  -413,   432,  -413,   344,   345,
     348,   349,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
      82,  -413,  -413,  -413,    82,  -413,   203,   251,   350,   346,
     191,   118,  -413,   352,  -413,    82,  -413,  -413,  -413,    82,
    -413,   357,    62,  -413,  -413,  -413,    32,   275,    47,    23,
    -413,  -413,  -413,  -413,    43,  -413,   359,  -413,  -413,  -413,
     366,  -413,   211,  -413,   238,  -413,  -413,    37,   -10,   -10,
     -10,   -10,   256,  -413,   -10,   -10,  -413,  -413,   369,  -413,
     286,  -413,  -413,   281,  -413,   251,  -413,   -10,  -413,  -413,
       0,  -413,  -413,  -413,  -413,  -413,   362,   599,   368,   191,
    -413,   371,   251,  -413,   388,  -413,  -413,  -413,   -38,  -413,
    -413,  -413,   370,  -413,   372,   373,   203,   403,  -413,   375,
     293,    82,  -413,  -413,  -413,   -14,   210,   384,   385,   386,
    -413,  -413,  -413,   389,   391,     1,   -27,   -27,    77,  -413,
    -413,  -413,    47,  -413,    89,   387,   392,   -10,   393,   395,
     396,  -413,  -413,  -413,   397,  -413,  -413,  -413,  -413,  -413,
     401,   455,  -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,    52,    52,   599,  -413,  -413,   409,
    -413,  -413,  -413,  -413,  -413,   203,  -413,  -413,   406,  -413,
    -413,  -413,  -413,   398,  -413,  -413,   402,  -413,  -413,   405,
      32,   413,   414,   215,   -27,  -413,   -27,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,  -413,  -413,   132,  -413,  -413,  -413,
     415,  -413,  -413,    94,   -38,  -413,   203,  -413,  -413,  -413,
    -413,   416,   417,  -413,  -413,  -413,   238,   238,    82,   420,
    -413,  -413,  -413,  -413,  -413,  -413,  -413,  -413,   191,   419,
     140,  -413,  -413,  -413,   251,  -413,    77,  -413,    26,   421,
     160,  -413,   203,  -413,  -413,  -413,   423,   425,   170,  -413,
     191,  -413,  -413,   171,  -413,    26,  -413,  -413,   427,   215,
    -413,    94,  -413,   429,  -413,  -413,   430,  -413,  -413
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   185,   186,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    66,     0,     0,     0,     0,     0,   188,
      17,    19,    18,    20,    55,    95,    57,     0,    58,     0,
      25,    62,    61,    75,     0,     0,     0,     0,     0,    47,
      24,   116,     0,   173,   174,     0,     0,   260,     0,    76,
       0,     0,    94,    65,    63,     0,   297,     0,     0,     0,
       0,    27,     0,     4,     5,     6,     7,     8,     9,    10,
      12,    11,    13,    14,     0,    15,    16,   189,   192,    56,
      59,    60,     0,    78,    73,     0,    70,    71,     0,    23,
       0,   260,     0,     0,     0,    86,   179,   178,     0,     0,
     260,     0,    91,    92,   100,     0,    93,    77,   297,   297,
      39,   297,   297,     0,    64,    26,    95,    98,    99,   114,
       0,     0,   102,    83,    72,   297,   118,    87,    96,    97,
     288,   265,   267,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,   267,   261,   260,   260,    90,
       0,   101,    67,   100,    33,   298,    41,     0,    42,    28,
      74,   125,   197,   297,   193,   190,   191,     0,     0,     0,
       0,     0,    79,    80,     0,     0,   268,     0,   269,     0,
       0,   272,     0,     0,   275,     0,     0,   283,   282,   284,
     285,   281,   286,   287,   289,   278,     0,     0,   290,   295,
     294,     0,     0,    88,    89,   100,    85,    35,     0,     0,
     299,   251,    44,     0,    30,     0,     0,   115,     0,     0,
       0,   206,   207,   202,   297,   203,   235,   198,   104,    84,
      83,    82,     0,     0,     0,   297,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
       0,     0,     0,   163,     0,   138,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   117,     0,   162,     0,     0,
       0,     0,   270,   271,   273,   274,   276,   277,   279,   280,
     299,   264,   291,    68,   299,    36,     0,   297,   300,     0,
       0,     0,   252,     0,    38,   299,    21,    22,    31,   299,
     126,     0,   297,   195,   204,   205,     0,   260,     0,     0,
      81,    54,    52,    53,     0,   122,     0,   141,   148,   149,
       0,   140,   131,   130,   133,   134,   136,   171,     0,     0,
       0,     0,     0,   166,     0,     0,   152,   164,     0,   139,
       0,   168,   167,     0,   159,   297,   160,     0,   180,   181,
       0,   135,   121,   120,   293,   292,     0,     0,     0,     0,
      45,   301,   297,    40,     0,   304,   305,   307,     0,   303,
     306,   308,     0,   253,     0,     0,     0,     0,   124,     0,
       0,   299,   200,   184,   256,     0,     0,     0,     0,     0,
     257,   258,   259,     0,     0,     0,   251,   251,     0,   239,
     240,   218,   236,   237,     0,     0,     0,     0,     0,     0,
       0,   105,   103,   112,     0,    49,    51,   142,   170,   132,
       0,   171,   153,   146,   144,   145,   147,   175,   176,   177,
     143,   151,   150,   165,     0,     0,     0,   169,   157,     0,
     262,   263,    34,    37,   302,     0,   312,   311,     0,   254,
      43,    29,    32,     0,   127,   123,     0,   194,   196,     0,
       0,     0,     0,     0,   251,   210,   251,   249,   296,   250,
     241,   242,   247,   246,   208,   209,   299,   220,   238,   231,
       0,   310,   309,     0,   230,   222,     0,   243,   107,   111,
     108,     0,     0,   106,   172,   154,   155,   156,   299,     0,
      46,   255,   129,   128,   199,   201,   245,   244,     0,     0,
     299,   215,   217,   248,   297,   219,     0,   224,     0,     0,
     299,   228,     0,   232,   109,   110,     0,     0,   299,   211,
       0,   301,   221,   299,   223,     0,   233,   161,     0,   213,
     216,   226,   229,   182,   214,   227,     0,   158,   183
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -413,  -413,    13,  -177,  -237,   -87,    -7,  -413,  -413,  -413,
    -413,  -413,  -413,  -413,  -413,  -223,  -413,  -413,  -413,  -413,
     301,  -413,  -413,  -413,   167,  -413,  -413,  -413,  -413,   253,
     552,   226,   178,  -413,    -3,   -15,  -413,  -153,  -413,  -413,
    -413,  -413,   358,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -227,   113,   295,  -413,  -413,  -413,  -413,  -413,  -413,  -413,
    -413,  -413,  -413,  -234,  -413,  -413,  -313,  -413,    -9,    24,
    -395,  -413,  -413,  -403,    -4,    18,  -412,  -413,  -413,  -413,
     136,  -380,  -413,  -112,   105,  -293,   400,  -113,  -413,  -413,
    -135,  -298,  -413,  -413,    59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   327,    54,   514,    71,   296,    33,    34,    35,
     245,   329,    36,   238,   314,   239,    37,   187,    38,   243,
     240,    39,   118,   265,   266,    40,    41,   153,   202,   203,
     297,    43,   135,   137,   255,   241,   149,   182,    44,   198,
     339,   444,    45,    46,   191,    47,   120,   205,   247,   407,
     299,   452,    78,   460,   130,   380,   577,    48,    49,   108,
     197,   151,   332,   194,   256,   411,   257,   429,   539,   540,
     541,   430,   506,   431,   549,   550,   551,   337,   338,   432,
     433,   324,   434,   125,   310,   175,   207,   311,   230,   499,
     140,   320,   402,   516,   478
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    61,    56,   184,   185,   145,   188,   189,   328,   157,
      69,   176,   387,    84,   333,   315,   389,    53,   179,   331,
     204,   495,   515,   412,   436,   507,    80,    57,   346,   502,
     236,   406,   437,   249,   410,   249,    65,    66,   438,   231,
     439,   440,   199,    50,   200,   435,   504,   505,   132,   133,
     414,   321,    15,   132,   133,  -234,   111,   250,   248,   250,
     251,   252,   251,   252,   300,   233,   234,   109,   491,   262,
     364,   192,   334,   509,    55,   193,   450,   263,   264,   390,
     414,   476,   313,   144,   358,   365,   359,   360,   361,   148,
    -234,   451,   477,   322,   323,   352,   353,   394,    51,    52,
     253,   147,   253,   208,   301,   319,    67,    59,   492,   209,
     210,   468,    60,   490,   542,    62,   543,   134,   348,   336,
     161,   415,   163,    55,   416,   349,   417,    81,   418,   419,
     344,   420,   421,   422,   423,   424,   509,    68,    64,   435,
     425,   509,   511,   562,    58,   347,   201,   441,   326,    52,
     442,   512,    55,   572,    55,    60,   254,    73,    74,   426,
     427,   420,   421,   422,   221,   570,   473,   126,   127,   482,
     445,    63,   510,   428,    70,   386,   488,   535,   376,   388,
     486,    79,   391,    82,  -299,    83,   317,   354,    72,   211,
     404,    85,   259,   318,   405,   212,   213,   409,   128,    86,
     129,   217,   218,   219,   220,   511,   317,    87,   546,  -297,
     511,   326,    52,   318,   512,   513,   326,    52,   262,   512,
     548,    73,    74,   116,   117,   413,   263,   264,    89,    55,
     387,    75,    76,    88,   395,   396,   397,    90,   530,   214,
     466,   398,   560,   399,    91,   215,   216,   225,   146,    76,
     400,   401,   565,   226,   227,    92,   544,   474,    93,   545,
     560,   343,    53,   318,   544,   565,    94,  -212,   457,   458,
     459,   318,   355,   267,   471,   366,   489,   268,   104,   553,
     367,   372,    95,   374,   544,    53,    53,  -225,   269,   195,
     196,   318,   270,   271,   544,   544,    96,   569,   571,    97,
    -113,   318,   318,    98,   272,   273,   274,   275,   276,   277,
     278,    99,   279,    75,    76,   566,   107,   280,   281,   100,
     282,   283,   284,   285,   286,   326,    52,   378,   379,   287,
     288,   289,    75,    76,    52,   290,   493,    75,    76,   132,
     133,   538,   464,   465,   101,   112,   102,   103,   105,   106,
     110,   453,   454,   455,   456,   113,   114,   461,   462,   115,
     119,   291,   -48,   121,   124,   449,   292,   122,   123,   131,
     467,   136,   138,   143,   141,   139,   150,   526,   527,   293,
     142,   152,   154,   155,   206,   158,   159,   156,   177,   261,
     178,   180,   183,   556,    60,   186,   294,   181,   190,   295,
     222,   494,   223,   260,   483,   224,   228,   229,   268,   561,
     235,   316,   350,   312,   237,   192,   242,   244,   246,   269,
     258,   302,   503,   270,   271,   303,   304,   305,   306,   307,
     519,   199,   308,   309,   335,   272,   273,   274,   275,   276,
     277,   278,   341,   279,   342,   345,   351,   363,   280,   281,
     368,   282,   283,   284,   285,   286,   356,   357,   369,   373,
     287,   288,   289,   370,   371,   377,   290,   381,   382,   383,
     384,   385,   475,   393,   392,   403,     2,     3,   494,     4,
       5,     6,   447,     7,   408,     8,     9,    10,   448,   470,
      11,   463,   291,   479,   450,   472,    12,   292,  -298,   480,
     481,    13,   487,    14,  -113,    15,   496,   497,   498,   517,
     293,   446,   500,   340,   501,   520,   518,   521,   522,   529,
      16,   523,   532,   494,   524,    60,   533,   484,    17,   531,
     485,    18,   534,    19,    20,   536,   537,   547,   554,   555,
      21,    22,    23,   557,   325,   494,   559,   568,   564,   573,
     567,   576,   578,    42,   494,    24,    25,    26,   469,    27,
     574,   268,   558,   298,   525,   443,   563,   575,   508,    28,
      29,   528,   269,   552,   362,   232,   270,   271,     0,     0,
       0,     0,    30,     0,   160,     0,     0,     0,   272,   273,
     274,   275,   276,   277,   278,     0,   279,     0,    31,     0,
      32,   280,   281,     0,   282,   283,   284,   285,   286,   161,
     162,   163,     0,   287,   288,   289,   160,     0,     0,   290,
       0,     0,     0,     0,     0,     0,   164,   165,   166,   167,
       0,     0,     0,     0,   168,   169,   170,   171,   172,   173,
       0,   161,   162,   163,     0,   291,     0,   160,     0,     0,
     292,     0,     0,     0,     0,     0,     0,     0,   164,   165,
     166,   167,   174,   293,     0,     0,   168,   169,   170,   171,
     172,   173,   161,   162,   163,     0,     0,     0,    60,     0,
     330,     0,     0,     0,     0,     0,     0,     0,     0,   164,
     165,   166,   167,     0,   375,     0,     0,   168,   169,   170,
     171,   172,   173
};

static const yytype_int16 yycheck[] =
{
      15,     8,     5,   138,   139,    92,   141,   142,   245,   121,
      13,   124,   310,    20,   248,   238,   314,     4,   130,   246,
     155,   416,   434,   336,     1,   428,    21,     6,     6,    28,
     183,   329,     9,     3,   332,     3,    21,    22,    15,   174,
      17,    18,     9,   124,    11,   338,   426,   427,    53,    54,
       3,    78,    29,    53,    54,    89,    59,    27,   193,    27,
      30,    31,    30,    31,    82,   177,   178,    54,    82,    26,
      32,   122,   249,    47,   122,   126,    39,    34,    35,   316,
       3,   119,   235,    90,    39,    47,    41,    42,    43,   104,
     124,    54,   130,   120,   121,   272,   273,   320,   122,   123,
      70,   104,    70,   123,   122,   240,    91,     8,   122,   129,
     130,   111,   122,   411,   494,   123,   496,   122,    12,   254,
      73,    74,    75,   122,    77,    19,    79,   122,    81,    82,
     265,    84,    85,    86,    87,    88,    47,   122,   122,   432,
      93,    47,   116,   546,   123,   123,   153,   124,   122,   123,
     127,   125,   122,   565,   122,   122,   126,   112,   113,   112,
     113,    84,    85,    86,   167,   560,   389,    71,    72,   406,
     127,   123,    83,   126,   122,   310,   410,   490,   291,   314,
     407,   123,   317,   122,   122,   122,   124,   274,    79,   123,
     325,   122,   199,   131,   329,   129,   130,   332,   102,   126,
     104,    94,    95,    96,    97,   116,   124,   122,   506,   127,
     116,   122,   123,   131,   125,   126,   122,   123,    26,   125,
     126,   112,   113,    22,    23,   337,    34,    35,   114,   122,
     528,   122,   123,   122,   116,   117,   118,    83,   475,   123,
     375,   123,   540,   125,   122,   129,   130,   123,   122,   123,
     132,   133,   550,   129,   130,   125,   124,   392,   124,   127,
     558,   264,   249,   131,   124,   563,   124,   127,    12,    13,
      14,   131,   275,     1,   387,   282,   411,     5,    28,   516,
     283,   288,   124,   290,   124,   272,   273,   127,    16,    68,
      69,   131,    20,    21,   124,   124,   124,   127,   127,   124,
      28,   131,   131,   124,    32,    33,    34,    35,    36,    37,
      38,   124,    40,   122,   123,   552,    67,    45,    46,   124,
      48,    49,    50,    51,    52,   122,   123,   108,   109,    57,
      58,    59,   122,   123,   123,    63,   126,   122,   123,    53,
      54,   126,    61,    62,   124,     8,   124,   124,   124,   124,
     123,   358,   359,   360,   361,   122,   122,   364,   365,    24,
     122,    89,   126,   122,    89,   352,    94,   128,   128,   122,
     377,    56,   126,   115,   126,   124,    21,   464,   465,   107,
     126,   122,   122,   126,    76,   123,   123,   126,   122,    22,
     123,   122,   122,   528,   122,   127,   124,   123,   122,   127,
     123,   416,   123,   123,     1,   122,   122,   122,     5,   544,
     122,    84,    22,   122,   127,   122,   127,   127,   126,    16,
     126,   123,   425,    20,    21,   123,   123,   123,   123,   123,
     437,     9,   123,   123,   122,    32,    33,    34,    35,    36,
      37,    38,   123,    40,   122,   124,   122,   122,    45,    46,
       8,    48,    49,    50,    51,    52,   123,   123,   122,    60,
      57,    58,    59,   122,   122,    83,    63,    35,   124,   124,
     122,   122,    84,   127,   124,   123,     0,     1,   493,     3,
       4,     5,   123,     7,   127,     9,    10,    11,   122,   127,
      14,   122,    89,   123,    39,   127,    20,    94,   127,   127,
     127,    25,   127,    27,    28,    29,   122,   122,   122,   122,
     107,   344,   123,   260,   123,   122,   124,   122,   122,   110,
      44,   124,   124,   538,   123,   122,   124,   124,    52,   123,
     127,    55,   127,    57,    58,   122,   122,   122,   122,   122,
      64,    65,    66,   123,   243,   560,   127,   122,   127,   122,
     127,   122,   122,     1,   569,    79,    80,    81,   380,    83,
     569,     5,   538,   205,   451,   339,   548,   571,   432,    93,
      94,   466,    16,   514,   279,   175,    20,    21,    -1,    -1,
      -1,    -1,   106,    -1,    48,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    -1,   122,    -1,
     124,    45,    46,    -1,    48,    49,    50,    51,    52,    73,
      74,    75,    -1,    57,    58,    59,    48,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
      -1,    73,    74,    75,    -1,    89,    -1,    48,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,   126,   107,    -1,    -1,    98,    99,   100,   101,
     102,   103,    73,    74,    75,    -1,    -1,    -1,   122,    -1,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    -1,   126,    -1,    -1,    98,    99,   100,
     101,   102,   103
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   135,     0,     1,     3,     4,     5,     7,     9,    10,
      11,    14,    20,    25,    27,    29,    44,    52,    55,    57,
      58,    64,    65,    66,    79,    80,    81,    83,    93,    94,
     106,   122,   124,   141,   142,   143,   146,   150,   152,   155,
     159,   160,   164,   165,   172,   176,   177,   179,   191,   192,
     124,   122,   123,   136,   137,   122,   168,     6,   123,     8,
     122,   140,   123,   123,   122,    21,    22,    91,   122,   168,
     122,   139,    79,   112,   113,   122,   123,   169,   186,   123,
      21,   122,   122,   122,   140,   122,   126,   122,   122,   114,
      83,   122,   125,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,    28,   124,   124,    67,   193,   136,
     123,   168,     8,   122,   122,    24,    22,    23,   156,   122,
     180,   122,   128,   128,    89,   217,    71,    72,   102,   104,
     188,   122,    53,    54,   122,   166,    56,   167,   126,   124,
     224,   126,   126,   115,   140,   139,   122,   168,   169,   170,
      21,   195,   122,   161,   122,   126,   126,   217,   123,   123,
      48,    73,    74,    75,    90,    91,    92,    93,    98,    99,
     100,   101,   102,   103,   126,   219,   221,   122,   123,   217,
     122,   123,   171,   122,   224,   224,   127,   151,   224,   224,
     122,   178,   122,   126,   197,    68,    69,   194,   173,     9,
      11,   140,   162,   163,   224,   181,    76,   220,   123,   129,
     130,   123,   129,   130,   123,   129,   130,    94,    95,    96,
      97,   168,   123,   123,   122,   123,   129,   130,   122,   122,
     222,   224,   220,   217,   217,   122,   171,   127,   147,   149,
     154,   169,   127,   153,   127,   144,   126,   182,   224,     3,
      27,    30,    31,    70,   126,   168,   198,   200,   126,   140,
     123,    22,    26,    34,    35,   157,   158,     1,     5,    16,
      20,    21,    32,    33,    34,    35,    36,    37,    38,    40,
      45,    46,    48,    49,    50,    51,    52,    57,    58,    59,
      63,    89,    94,   107,   124,   127,   140,   164,   176,   184,
      82,   122,   123,   123,   123,   123,   123,   123,   123,   123,
     218,   221,   122,   171,   148,   149,    84,   124,   131,   224,
     225,    78,   120,   121,   215,   154,   122,   136,   138,   145,
     124,   184,   196,   197,   137,   122,   224,   211,   212,   174,
     163,   123,   122,   168,   224,   124,     6,   123,    12,    19,
      22,   122,   137,   137,   139,   168,   123,   123,    39,    41,
      42,    43,   186,   122,    32,    47,   140,   168,     8,   122,
     122,   122,   140,    60,   140,   126,   221,    83,   108,   109,
     189,    35,   124,   124,   122,   122,   224,   225,   224,   225,
     138,   224,   124,   127,   149,   116,   117,   118,   123,   125,
     132,   133,   226,   123,   224,   224,   225,   183,   127,   224,
     225,   199,   200,   217,     3,    74,    77,    79,    81,    82,
      84,    85,    86,    87,    88,    93,   112,   113,   126,   201,
     205,   207,   213,   214,   216,   219,     1,     9,    15,    17,
      18,   124,   127,   165,   175,   127,   158,   123,   122,   136,
      39,    54,   185,   140,   140,   140,   140,    12,    13,    14,
     187,   140,   140,   122,    61,    62,   224,   140,   111,   166,
     127,   221,   127,   149,   224,    84,   119,   130,   228,   123,
     127,   127,   138,     1,   124,   127,   184,   127,   197,   224,
     225,    82,   122,   126,   169,   204,   122,   122,   122,   223,
     123,   123,    28,   168,   215,   215,   206,   207,   214,    47,
      83,   116,   125,   126,   138,   210,   227,   122,   124,   140,
     122,   122,   122,   124,   123,   185,   139,   139,   218,   110,
     138,   123,   124,   124,   127,   200,   122,   122,   126,   202,
     203,   204,   215,   215,   124,   127,   225,   122,   126,   208,
     209,   210,   228,   138,   122,   122,   224,   123,   203,   127,
     225,   224,   207,   209,   127,   225,   138,   127,   122,   127,
     204,   127,   210,   122,   202,   208,   122,   190,   122
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   134,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   136,   137,
     137,   138,   138,   139,   139,   140,   141,   142,   144,   143,
     143,   145,   145,   147,   146,   146,   148,   148,   149,   151,
     150,   150,   153,   152,   152,   154,   154,   155,   156,   155,
     157,   157,   158,   158,   158,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   161,   160,
     162,   162,   162,   163,   163,   164,   165,   165,   165,   165,
     165,   166,   166,   167,   167,   168,   169,   169,   170,   170,
     171,   171,   173,   172,   174,   174,   174,   174,   175,   175,
     175,   175,   175,   177,   178,   176,   180,   179,   181,   181,
     181,   181,   181,   182,   182,   182,   183,   183,   183,   183,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   185,   185,   186,   186,   187,   187,   187,   188,   188,
     189,   189,   190,   190,   191,   192,   192,   192,   193,   193,
     194,   194,   195,   195,   195,   196,   196,   197,   198,   198,
     199,   199,   200,   200,   200,   200,   200,   200,   201,   201,
     201,   201,   202,   202,   202,   203,   203,   204,   205,   205,
     206,   206,   207,   207,   207,   208,   208,   208,   209,   209,
     210,   210,   210,   210,   211,   212,   211,   213,   213,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   215,   215,   215,   215,   215,   216,   216,   216,   216,
     217,   217,   217,   218,   218,   219,   219,   220,   220,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   222,   223,   224,   224,   225,
     225,   225,   225,   226,   226,   226,   226,   226,   226,   227,
     227,   228,   228
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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
       2,     2,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     2,     3,     4,     4,     4,     3,     8,     2,
       2,     6,     1,     1,     2,     3,     2,     2,     2,     3,
       3,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     7,     1,     1,     1,     0,     1,
       1,     1,     0,     2,     6,     1,     3,     1,     1,     5,
       1,     3,     1,     1,     2,     2,     1,     1,     2,     2,
       2,     4,     1,     3,     4,     1,     3,     2,     1,     3,
       1,     3,     2,     4,     3,     1,     3,     4,     1,     3,
       1,     1,     2,     3,     0,     0,     2,     1,     2,     1,
       1,     2,     2,     2,     3,     3,     2,     2,     3,     2,
       2,     0,     1,     2,     3,     4,     1,     1,     1,     1,
       0,     2,     6,     3,     1,     1,     1,     0,     1,     2,
       3,     3,     2,     3,     3,     2,     3,     3,     2,     3,
       3,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     3,     4,     4,     2,     1,     1,     0,     2,     0,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
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
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 17:
#line 266 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { file->errors++; }
#line 2083 "parse.c" /* yacc.c:1652  */
    break;

  case 18:
#line 269 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2098 "parse.c" /* yacc.c:1652  */
    break;

  case 19:
#line 280 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2135 "parse.c" /* yacc.c:1652  */
    break;

  case 20:
#line 312 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == AS_TRANS || (yyvsp[0].v.number) == 0) {
				yyerror("AS %u is reserved and may not be used",
				    (u_int32_t)(yyvsp[0].v.number));
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2148 "parse.c" /* yacc.c:1652  */
    break;

  case 21:
#line 322 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2180 "parse.c" /* yacc.c:1652  */
    break;

  case 22:
#line 349 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2188 "parse.c" /* yacc.c:1652  */
    break;

  case 23:
#line 354 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (asprintf(&(yyval.v.string), "%s %s", (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1)
				fatal("string: asprintf");
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.string));
		}
#line 2199 "parse.c" /* yacc.c:1652  */
    break;

  case 25:
#line 363 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2217 "parse.c" /* yacc.c:1652  */
    break;

  case 26:
#line 378 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2240 "parse.c" /* yacc.c:1652  */
    break;

  case 27:
#line 398 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2258 "parse.c" /* yacc.c:1652  */
    break;

  case 28:
#line 413 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2275 "parse.c" /* yacc.c:1652  */
    break;

  case 29:
#line 424 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			done_as_set();
		}
#line 2283 "parse.c" /* yacc.c:1652  */
    break;

  case 30:
#line 427 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (new_as_set((yyvsp[-3].v.string)) != 0) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
		}
#line 2295 "parse.c" /* yacc.c:1652  */
    break;

  case 31:
#line 435 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { add_as_set((yyvsp[0].v.number)); }
#line 2301 "parse.c" /* yacc.c:1652  */
    break;

  case 32:
#line 436 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { add_as_set((yyvsp[0].v.number)); }
#line 2307 "parse.c" /* yacc.c:1652  */
    break;

  case 33:
#line 438 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((curpset = new_prefix_set((yyvsp[-2].v.string), 0)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			free((yyvsp[-2].v.string));
		}
#line 2319 "parse.c" /* yacc.c:1652  */
    break;

  case 34:
#line 444 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2328 "parse.c" /* yacc.c:1652  */
    break;

  case 35:
#line 448 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((curpset = new_prefix_set((yyvsp[-3].v.string), 0)) == NULL) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2342 "parse.c" /* yacc.c:1652  */
    break;

  case 36:
#line 458 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2361 "parse.c" /* yacc.c:1652  */
    break;

  case 37:
#line 472 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2380 "parse.c" /* yacc.c:1652  */
    break;

  case 38:
#line 488 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2400 "parse.c" /* yacc.c:1652  */
    break;

  case 39:
#line 505 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curroatree = &conf->roa;
		}
#line 2408 "parse.c" /* yacc.c:1652  */
    break;

  case 40:
#line 507 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curroatree = NULL;
		}
#line 2416 "parse.c" /* yacc.c:1652  */
    break;

  case 42:
#line 513 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((curoset = new_prefix_set((yyvsp[-2].v.string), 1)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			curroatree = &curoset->roaitems;
			free((yyvsp[-2].v.string));
		}
#line 2429 "parse.c" /* yacc.c:1652  */
    break;

  case 43:
#line 520 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			SIMPLEQ_INSERT_TAIL(&conf->originsets, curoset, entry);
			curoset = NULL;
			curroatree = NULL;
		}
#line 2439 "parse.c" /* yacc.c:1652  */
    break;

  case 44:
#line 525 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2454 "parse.c" /* yacc.c:1652  */
    break;

  case 45:
#line 537 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2469 "parse.c" /* yacc.c:1652  */
    break;

  case 46:
#line 547 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2484 "parse.c" /* yacc.c:1652  */
    break;

  case 47:
#line 559 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = 323;
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2498 "parse.c" /* yacc.c:1652  */
    break;

  case 48:
#line 568 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			currtr = get_rtr(&(yyvsp[0].v.addr));
			currtr->remote_port = 323;
		}
#line 2507 "parse.c" /* yacc.c:1652  */
    break;

  case 49:
#line 571 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (insert_rtr(currtr) == -1) {
				free(currtr);
				YYERROR;
			}
			currtr = NULL;
		}
#line 2519 "parse.c" /* yacc.c:1652  */
    break;

  case 52:
#line 583 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2535 "parse.c" /* yacc.c:1652  */
    break;

  case 53:
#line 594 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.addr).aid != currtr->remote_addr.aid) {
				yyerror("Bad address family %s for "
				    "local-addr", aid2str((yyvsp[0].v.addr).aid));
				YYERROR;
			}
			currtr->local_addr = (yyvsp[0].v.addr);
		}
#line 2548 "parse.c" /* yacc.c:1652  */
    break;

  case 54:
#line 602 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("local-port must be between %u and %u",
				    1, USHRT_MAX);
				YYERROR;
			}
			currtr->remote_port = (yyvsp[0].v.number);
		}
#line 2561 "parse.c" /* yacc.c:1652  */
    break;

  case 55:
#line 612 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			conf->as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				conf->short_as = AS_TRANS;
			else
				conf->short_as = (yyvsp[0].v.number);
		}
#line 2573 "parse.c" /* yacc.c:1652  */
    break;

  case 56:
#line 619 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			conf->as = (yyvsp[-1].v.number);
			conf->short_as = (yyvsp[0].v.number);
		}
#line 2582 "parse.c" /* yacc.c:1652  */
    break;

  case 57:
#line 623 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.addr).aid != AID_INET) {
				yyerror("router-id must be an IPv4 address");
				YYERROR;
			}
			conf->bgpid = (yyvsp[0].v.addr).v4.s_addr;
		}
#line 2594 "parse.c" /* yacc.c:1652  */
    break;

  case 58:
#line 630 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->holdtime = (yyvsp[0].v.number);
		}
#line 2607 "parse.c" /* yacc.c:1652  */
    break;

  case 59:
#line 638 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->min_holdtime = (yyvsp[0].v.number);
		}
#line 2620 "parse.c" /* yacc.c:1652  */
    break;

  case 60:
#line 646 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2639 "parse.c" /* yacc.c:1652  */
    break;

  case 61:
#line 660 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) <= RTP_NONE || (yyvsp[0].v.number) > RTP_MAX) {
				yyerror("invalid fib-priority");
				YYERROR;
			}
			conf->fib_priority = (yyvsp[0].v.number);
		}
#line 2651 "parse.c" /* yacc.c:1652  */
    break;

  case 62:
#line 667 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2667 "parse.c" /* yacc.c:1652  */
    break;

  case 63:
#line 678 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_DECISION_TRANS_AS;
			else
				conf->flags &= ~BGPD_FLAG_DECISION_TRANS_AS;
		}
#line 2678 "parse.c" /* yacc.c:1652  */
    break;

  case 64:
#line 684 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_NO_AS_SET;
			else
				conf->flags &= ~BGPD_FLAG_NO_AS_SET;
		}
#line 2689 "parse.c" /* yacc.c:1652  */
    break;

  case 65:
#line 690 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (!strcmp((yyvsp[0].v.string), "updates"))
				conf->log |= BGPD_LOG_UPDATES;
			else {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 2703 "parse.c" /* yacc.c:1652  */
    break;

  case 67:
#line 700 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2736 "parse.c" /* yacc.c:1652  */
    break;

  case 68:
#line 728 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2773 "parse.c" /* yacc.c:1652  */
    break;

  case 70:
#line 761 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2788 "parse.c" /* yacc.c:1652  */
    break;

  case 71:
#line 771 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2803 "parse.c" /* yacc.c:1652  */
    break;

  case 72:
#line 781 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2821 "parse.c" /* yacc.c:1652  */
    break;

  case 73:
#line 794 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2839 "parse.c" /* yacc.c:1652  */
    break;

  case 74:
#line 807 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2857 "parse.c" /* yacc.c:1652  */
    break;

  case 75:
#line 820 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2878 "parse.c" /* yacc.c:1652  */
    break;

  case 76:
#line 836 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) > USHRT_MAX || (yyvsp[0].v.number) < 1) {
				yyerror("invalid connect-retry");
				YYERROR;
			}
			conf->connectretry = (yyvsp[0].v.number);
		}
#line 2890 "parse.c" /* yacc.c:1652  */
    break;

  case 77:
#line 843 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2909 "parse.c" /* yacc.c:1652  */
    break;

  case 78:
#line 859 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((currib = add_rib((yyvsp[0].v.string))) == NULL) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 2921 "parse.c" /* yacc.c:1652  */
    break;

  case 79:
#line 865 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			currib = NULL;
		}
#line 2929 "parse.c" /* yacc.c:1652  */
    break;

  case 81:
#line 870 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[-1].v.number) > RT_TABLEID_MAX) {
				yyerror("rtable %llu too big: max %u", (yyvsp[-1].v.number),
				    RT_TABLEID_MAX);
				YYERROR;
			}
			if (rib_add_fib(currib, (yyvsp[-1].v.number)) == -1)
				YYERROR;
		}
#line 2943 "parse.c" /* yacc.c:1652  */
    break;

  case 82:
#line 879 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[-1].v.number)) {
				yyerror("bad rde rib definition");
				YYERROR;
			}
			currib->flags |= F_RIB_NOEVALUATE;
		}
#line 2955 "parse.c" /* yacc.c:1652  */
    break;

  case 84:
#line 889 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == 0)
				currib->flags |= F_RIB_NOFIBSYNC;
			else
				currib->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 2966 "parse.c" /* yacc.c:1652  */
    break;

  case 85:
#line 897 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 2999 "parse.c" /* yacc.c:1652  */
    break;

  case 86:
#line 927 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3025 "parse.c" /* yacc.c:1652  */
    break;

  case 87:
#line 948 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3059 "parse.c" /* yacc.c:1652  */
    break;

  case 88:
#line 977 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3083 "parse.c" /* yacc.c:1652  */
    break;

  case 89:
#line 996 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3112 "parse.c" /* yacc.c:1652  */
    break;

  case 90:
#line 1020 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3135 "parse.c" /* yacc.c:1652  */
    break;

  case 91:
#line 1040 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 1; }
#line 3141 "parse.c" /* yacc.c:1652  */
    break;

  case 92:
#line 1041 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 3147 "parse.c" /* yacc.c:1652  */
    break;

  case 93:
#line 1044 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 1; }
#line 3153 "parse.c" /* yacc.c:1652  */
    break;

  case 94:
#line 1045 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 3159 "parse.c" /* yacc.c:1652  */
    break;

  case 95:
#line 1048 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3183 "parse.c" /* yacc.c:1652  */
    break;

  case 96:
#line 1069 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3206 "parse.c" /* yacc.c:1652  */
    break;

  case 97:
#line 1087 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3229 "parse.c" /* yacc.c:1652  */
    break;

  case 98:
#line 1107 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			memcpy(&(yyval.v.prefix).prefix, &(yyvsp[0].v.addr), sizeof(struct bgpd_addr));
			if ((yyval.v.prefix).prefix.aid == AID_INET)
				(yyval.v.prefix).len = 32;
			else
				(yyval.v.prefix).len = 128;
		}
#line 3241 "parse.c" /* yacc.c:1652  */
    break;

  case 100:
#line 1117 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 3247 "parse.c" /* yacc.c:1652  */
    break;

  case 102:
#line 1121 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3290 "parse.c" /* yacc.c:1652  */
    break;

  case 103:
#line 1158 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			/* insert into list */
			SIMPLEQ_INSERT_TAIL(&conf->l3vpns, curvpn, entry);
			curvpn = NULL;
			netconf = &conf->networks;
		}
#line 3301 "parse.c" /* yacc.c:1652  */
    break;

  case 108:
#line 1172 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3324 "parse.c" /* yacc.c:1652  */
    break;

  case 109:
#line 1190 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3347 "parse.c" /* yacc.c:1652  */
    break;

  case 110:
#line 1208 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3370 "parse.c" /* yacc.c:1652  */
    break;

  case 111:
#line 1226 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == 0)
				curvpn->flags |= F_RIB_NOFIBSYNC;
			else
				curvpn->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3381 "parse.c" /* yacc.c:1652  */
    break;

  case 113:
#line 1235 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {	curpeer = new_peer(); }
#line 3387 "parse.c" /* yacc.c:1652  */
    break;

  case 114:
#line 1236 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3406 "parse.c" /* yacc.c:1652  */
    break;

  case 115:
#line 1250 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3429 "parse.c" /* yacc.c:1652  */
    break;

  case 116:
#line 1270 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3452 "parse.c" /* yacc.c:1652  */
    break;

  case 117:
#line 1287 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3470 "parse.c" /* yacc.c:1652  */
    break;

  case 130:
#line 1320 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.remote_as = (yyvsp[0].v.number);
		}
#line 3478 "parse.c" /* yacc.c:1652  */
    break;

  case 131:
#line 1323 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.local_as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				curpeer->conf.local_short_as = AS_TRANS;
			else
				curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3490 "parse.c" /* yacc.c:1652  */
    break;

  case 132:
#line 1330 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.local_as = (yyvsp[-1].v.number);
			curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3499 "parse.c" /* yacc.c:1652  */
    break;

  case 133:
#line 1334 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3515 "parse.c" /* yacc.c:1652  */
    break;

  case 134:
#line 1345 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3533 "parse.c" /* yacc.c:1652  */
    break;

  case 135:
#line 1358 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3548 "parse.c" /* yacc.c:1652  */
    break;

  case 136:
#line 1368 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < 2 || (yyvsp[0].v.number) > 255) {
				yyerror("invalid multihop distance %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			curpeer->conf.distance = (yyvsp[0].v.number);
		}
#line 3560 "parse.c" /* yacc.c:1652  */
    break;

  case 137:
#line 1375 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.passive = 1;
		}
#line 3568 "parse.c" /* yacc.c:1652  */
    break;

  case 138:
#line 1378 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.down = 1;
		}
#line 3576 "parse.c" /* yacc.c:1652  */
    break;

  case 139:
#line 1381 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3592 "parse.c" /* yacc.c:1652  */
    break;

  case 140:
#line 1392 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3613 "parse.c" /* yacc.c:1652  */
    break;

  case 141:
#line 1408 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.holdtime = (yyvsp[0].v.number);
		}
#line 3626 "parse.c" /* yacc.c:1652  */
    break;

  case 142:
#line 1416 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.min_holdtime = (yyvsp[0].v.number);
		}
#line 3639 "parse.c" /* yacc.c:1652  */
    break;

  case 143:
#line 1424 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3663 "parse.c" /* yacc.c:1652  */
    break;

  case 144:
#line 1443 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.announce_capa = (yyvsp[0].v.number);
		}
#line 3671 "parse.c" /* yacc.c:1652  */
    break;

  case 145:
#line 1446 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.capabilities.refresh = (yyvsp[0].v.number);
		}
#line 3679 "parse.c" /* yacc.c:1652  */
    break;

  case 146:
#line 1449 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.capabilities.grestart.restart = (yyvsp[0].v.number);
		}
#line 3687 "parse.c" /* yacc.c:1652  */
    break;

  case 147:
#line 1452 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.capabilities.as4byte = (yyvsp[0].v.number);
		}
#line 3695 "parse.c" /* yacc.c:1652  */
    break;

  case 148:
#line 1455 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.export_type = EXPORT_NONE;
		}
#line 3703 "parse.c" /* yacc.c:1652  */
    break;

  case 149:
#line 1458 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.export_type = EXPORT_DEFAULT_ROUTE;
		}
#line 3711 "parse.c" /* yacc.c:1652  */
    break;

  case 150:
#line 1461 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_as = ENFORCE_AS_OFF;
		}
#line 3722 "parse.c" /* yacc.c:1652  */
    break;

  case 151:
#line 1467 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_local_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_local_as = ENFORCE_AS_OFF;
		}
#line 3733 "parse.c" /* yacc.c:1652  */
    break;

  case 152:
#line 1473 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3753 "parse.c" /* yacc.c:1652  */
    break;

  case 153:
#line 1488 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[-1].v.number) < 0 || (yyvsp[-1].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_prefix = (yyvsp[-1].v.number);
			curpeer->conf.max_prefix_restart = (yyvsp[0].v.number);
		}
#line 3766 "parse.c" /* yacc.c:1652  */
    break;

  case 154:
#line 1496 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[-2].v.number) < 0 || (yyvsp[-2].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_out_prefix = (yyvsp[-2].v.number);
			curpeer->conf.max_out_prefix_restart = (yyvsp[0].v.number);
		}
#line 3779 "parse.c" /* yacc.c:1652  */
    break;

  case 155:
#line 1504 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3802 "parse.c" /* yacc.c:1652  */
    break;

  case 156:
#line 1522 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3823 "parse.c" /* yacc.c:1652  */
    break;

  case 157:
#line 1538 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3838 "parse.c" /* yacc.c:1652  */
    break;

  case 158:
#line 1548 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3936 "parse.c" /* yacc.c:1652  */
    break;

  case 159:
#line 1641 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.ttlsec = (yyvsp[0].v.number);
		}
#line 3944 "parse.c" /* yacc.c:1652  */
    break;

  case 160:
#line 1644 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			struct filter_rule	*r;

			r = get_rule((yyvsp[0].v.filter_set)->type);
			if (merge_filterset(&r->set, (yyvsp[0].v.filter_set)) == -1)
				YYERROR;
		}
#line 3956 "parse.c" /* yacc.c:1652  */
    break;

  case 161:
#line 1651 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3973 "parse.c" /* yacc.c:1652  */
    break;

  case 163:
#line 1664 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 3988 "parse.c" /* yacc.c:1652  */
    break;

  case 164:
#line 1674 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4009 "parse.c" /* yacc.c:1652  */
    break;

  case 165:
#line 1690 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4026 "parse.c" /* yacc.c:1652  */
    break;

  case 166:
#line 1702 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4055 "parse.c" /* yacc.c:1652  */
    break;

  case 167:
#line 1726 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_TRANS_AS;
			else
				curpeer->conf.flags &= ~PEERFLAG_TRANS_AS;
		}
#line 4066 "parse.c" /* yacc.c:1652  */
    break;

  case 168:
#line 1732 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4082 "parse.c" /* yacc.c:1652  */
    break;

  case 169:
#line 1743 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_NO_AS_SET;
			else
				curpeer->conf.flags &= ~PEERFLAG_NO_AS_SET;
		}
#line 4093 "parse.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1749 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4111 "parse.c" /* yacc.c:1652  */
    break;

  case 171:
#line 1764 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 4117 "parse.c" /* yacc.c:1652  */
    break;

  case 172:
#line 1765 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("restart out of range. 1 to %u minutes",
				    USHRT_MAX);
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 4130 "parse.c" /* yacc.c:1652  */
    break;

  case 173:
#line 1775 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = AFI_IPv4; }
#line 4136 "parse.c" /* yacc.c:1652  */
    break;

  case 174:
#line 1776 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = AFI_IPv6; }
#line 4142 "parse.c" /* yacc.c:1652  */
    break;

  case 175:
#line 1779 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = SAFI_NONE; }
#line 4148 "parse.c" /* yacc.c:1652  */
    break;

  case 176:
#line 1780 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = SAFI_UNICAST; }
#line 4154 "parse.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1781 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = SAFI_MPLSVPN; }
#line 4160 "parse.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1784 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 1; }
#line 4166 "parse.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1785 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 4172 "parse.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1788 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 1; }
#line 4178 "parse.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1789 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 4184 "parse.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1792 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			bzero(&(yyval.v.encspec), sizeof((yyval.v.encspec)));
		}
#line 4192 "parse.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1795 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4228 "parse.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1830 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4256 "parse.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1855 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = ACTION_ALLOW; }
#line 4262 "parse.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1856 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = ACTION_DENY; }
#line 4268 "parse.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1857 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = ACTION_NONE; }
#line 4274 "parse.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1860 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = 0; }
#line 4280 "parse.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1861 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = 1; }
#line 4286 "parse.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1864 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = DIR_IN; }
#line 4292 "parse.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1865 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = DIR_OUT; }
#line 4298 "parse.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1868 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_rib) = NULL; }
#line 4304 "parse.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1869 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4310 "parse.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1870 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_rib) = (yyvsp[-2].v.filter_rib); }
#line 4316 "parse.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1872 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4322 "parse.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1873 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			(yyvsp[0].v.filter_rib)->next = (yyvsp[-2].v.filter_rib);
			(yyval.v.filter_rib) = (yyvsp[0].v.filter_rib);
		}
#line 4331 "parse.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1879 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4356 "parse.c" /* yacc.c:1652  */
    break;

  case 199:
#line 1902 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_peers) = (yyvsp[-2].v.filter_peers); }
#line 4362 "parse.c" /* yacc.c:1652  */
    break;

  case 200:
#line 1905 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_peers) = (yyvsp[0].v.filter_peers); }
#line 4368 "parse.c" /* yacc.c:1652  */
    break;

  case 201:
#line 1906 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			(yyvsp[0].v.filter_peers)->next = (yyvsp[-2].v.filter_peers);
			(yyval.v.filter_peers) = (yyvsp[0].v.filter_peers);
		}
#line 4377 "parse.c" /* yacc.c:1652  */
    break;

  case 202:
#line 1912 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.peerid = (yyval.v.filter_peers)->p.groupid = 0;
			(yyval.v.filter_peers)->next = NULL;
		}
#line 4389 "parse.c" /* yacc.c:1652  */
    break;

  case 203:
#line 1919 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4414 "parse.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1939 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.groupid = (yyval.v.filter_peers)->p.peerid = 0;
			(yyval.v.filter_peers)->p.remote_as = (yyvsp[0].v.number);
		}
#line 4426 "parse.c" /* yacc.c:1652  */
    break;

  case 205:
#line 1946 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4452 "parse.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1967 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ebgp = 1;
		}
#line 4463 "parse.c" /* yacc.c:1652  */
    break;

  case 207:
#line 1973 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ibgp = 1;
		}
#line 4474 "parse.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1981 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4494 "parse.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1996 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4514 "parse.c" /* yacc.c:1652  */
    break;

  case 210:
#line 2011 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4520 "parse.c" /* yacc.c:1652  */
    break;

  case 211:
#line 2012 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4526 "parse.c" /* yacc.c:1652  */
    break;

  case 213:
#line 2016 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4532 "parse.c" /* yacc.c:1652  */
    break;

  case 214:
#line 2018 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			struct filter_prefix_l  *p;

			/* merge, both can be lists */
			for (p = (yyvsp[-2].v.filter_prefix); p != NULL && p->next != NULL; p = p->next)
				;       /* nothing */
			if (p != NULL)
				p->next = (yyvsp[0].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[-2].v.filter_prefix);
		}
#line 4547 "parse.c" /* yacc.c:1652  */
    break;

  case 215:
#line 2029 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4553 "parse.c" /* yacc.c:1652  */
    break;

  case 216:
#line 2030 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			(yyvsp[0].v.filter_prefix)->next = (yyvsp[-2].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix);
		}
#line 4562 "parse.c" /* yacc.c:1652  */
    break;

  case 217:
#line 2036 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4580 "parse.c" /* yacc.c:1652  */
    break;

  case 219:
#line 2052 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4586 "parse.c" /* yacc.c:1652  */
    break;

  case 221:
#line 2056 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4601 "parse.c" /* yacc.c:1652  */
    break;

  case 222:
#line 2068 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as)->a.type = (yyvsp[-1].v.u8);
		}
#line 4610 "parse.c" /* yacc.c:1652  */
    break;

  case 223:
#line 2072 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			struct filter_as_l	*a;

			(yyval.v.filter_as) = (yyvsp[-1].v.filter_as);
			for (a = (yyval.v.filter_as); a != NULL; a = a->next)
				a->a.type = (yyvsp[-3].v.u8);
		}
#line 4622 "parse.c" /* yacc.c:1652  */
    break;

  case 224:
#line 2079 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4648 "parse.c" /* yacc.c:1652  */
    break;

  case 226:
#line 2103 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4654 "parse.c" /* yacc.c:1652  */
    break;

  case 227:
#line 2105 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4669 "parse.c" /* yacc.c:1652  */
    break;

  case 229:
#line 2118 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			(yyvsp[0].v.filter_as)->next = (yyvsp[-2].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
		}
#line 4678 "parse.c" /* yacc.c:1652  */
    break;

  case 230:
#line 2124 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.op = OP_EQ;
		}
#line 4691 "parse.c" /* yacc.c:1652  */
    break;

  case 231:
#line 2132 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.flags = AS_FLAG_NEIGHBORAS;
		}
#line 4702 "parse.c" /* yacc.c:1652  */
    break;

  case 232:
#line 2138 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.op = (yyvsp[-1].v.u8);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
		}
#line 4715 "parse.c" /* yacc.c:1652  */
    break;

  case 233:
#line 2146 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4732 "parse.c" /* yacc.c:1652  */
    break;

  case 234:
#line 2160 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			bzero(&(yyval.v.filter_match), sizeof((yyval.v.filter_match)));
		}
#line 4740 "parse.c" /* yacc.c:1652  */
    break;

  case 235:
#line 2163 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			bzero(&fmopts, sizeof(fmopts));
		}
#line 4748 "parse.c" /* yacc.c:1652  */
    break;

  case 236:
#line 2166 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			memcpy(&(yyval.v.filter_match), &fmopts, sizeof((yyval.v.filter_match)));
		}
#line 4756 "parse.c" /* yacc.c:1652  */
    break;

  case 239:
#line 2175 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4774 "parse.c" /* yacc.c:1652  */
    break;

  case 240:
#line 2188 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (fmopts.as_l != NULL) {
				yyerror("AS filters already specified");
				YYERROR;
			}
			fmopts.as_l = (yyvsp[0].v.filter_as);
		}
#line 4786 "parse.c" /* yacc.c:1652  */
    break;

  case 241:
#line 2195 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4803 "parse.c" /* yacc.c:1652  */
    break;

  case 242:
#line 2207 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4820 "parse.c" /* yacc.c:1652  */
    break;

  case 243:
#line 2219 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4843 "parse.c" /* yacc.c:1652  */
    break;

  case 244:
#line 2237 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4870 "parse.c" /* yacc.c:1652  */
    break;

  case 245:
#line 2259 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4894 "parse.c" /* yacc.c:1652  */
    break;

  case 246:
#line 2278 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.addr = (yyvsp[0].v.addr);
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_ADDR;
		}
#line 4907 "parse.c" /* yacc.c:1652  */
    break;

  case 247:
#line 2286 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_NEIGHBOR;
		}
#line 4919 "parse.c" /* yacc.c:1652  */
    break;

  case 248:
#line 2293 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4973 "parse.c" /* yacc.c:1652  */
    break;

  case 249:
#line 2342 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 4998 "parse.c" /* yacc.c:1652  */
    break;

  case 250:
#line 2362 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (fmopts.m.ovs.is_set) {
				yyerror("ovs filter already specified");
				YYERROR;
			}
			fmopts.m.ovs.validity = (yyvsp[0].v.number);
			fmopts.m.ovs.is_set = 1;
		}
#line 5011 "parse.c" /* yacc.c:1652  */
    break;

  case 251:
#line 2372 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen))); }
#line 5017 "parse.c" /* yacc.c:1652  */
    break;

  case 252:
#line 2373 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen)));
			(yyval.v.prefixlen).op = OP_RANGE;
			(yyval.v.prefixlen).len_min = -1;
			(yyval.v.prefixlen).len_max = -1;
		}
#line 5028 "parse.c" /* yacc.c:1652  */
    break;

  case 253:
#line 2379 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5044 "parse.c" /* yacc.c:1652  */
    break;

  case 254:
#line 2390 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5092 "parse.c" /* yacc.c:1652  */
    break;

  case 255:
#line 2433 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5111 "parse.c" /* yacc.c:1652  */
    break;

  case 256:
#line 2449 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = AS_ALL; }
#line 5117 "parse.c" /* yacc.c:1652  */
    break;

  case 257:
#line 2450 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = AS_SOURCE; }
#line 5123 "parse.c" /* yacc.c:1652  */
    break;

  case 258:
#line 2451 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = AS_TRANSIT; }
#line 5129 "parse.c" /* yacc.c:1652  */
    break;

  case 259:
#line 2452 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = AS_PEER; }
#line 5135 "parse.c" /* yacc.c:1652  */
    break;

  case 260:
#line 2455 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_set_head) = NULL; }
#line 5141 "parse.c" /* yacc.c:1652  */
    break;

  case 261:
#line 2456 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5153 "parse.c" /* yacc.c:1652  */
    break;

  case 262:
#line 2463 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head); }
#line 5159 "parse.c" /* yacc.c:1652  */
    break;

  case 263:
#line 2466 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			(yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head);
			if (merge_filterset((yyval.v.filter_set_head), (yyvsp[0].v.filter_set)) == 1)
				YYERROR;
		}
#line 5169 "parse.c" /* yacc.c:1652  */
    break;

  case 264:
#line 2471 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5181 "parse.c" /* yacc.c:1652  */
    break;

  case 265:
#line 2480 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = COMMUNITY_TYPE_BASIC; }
#line 5187 "parse.c" /* yacc.c:1652  */
    break;

  case 266:
#line 2481 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = COMMUNITY_TYPE_LARGE; }
#line 5193 "parse.c" /* yacc.c:1652  */
    break;

  case 267:
#line 2484 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = 0; }
#line 5199 "parse.c" /* yacc.c:1652  */
    break;

  case 268:
#line 2485 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = 1; }
#line 5205 "parse.c" /* yacc.c:1652  */
    break;

  case 269:
#line 2488 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5225 "parse.c" /* yacc.c:1652  */
    break;

  case 270:
#line 2503 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5240 "parse.c" /* yacc.c:1652  */
    break;

  case 271:
#line 2513 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5255 "parse.c" /* yacc.c:1652  */
    break;

  case 272:
#line 2523 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5275 "parse.c" /* yacc.c:1652  */
    break;

  case 273:
#line 2538 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5290 "parse.c" /* yacc.c:1652  */
    break;

  case 274:
#line 2548 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5305 "parse.c" /* yacc.c:1652  */
    break;

  case 275:
#line 2558 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5325 "parse.c" /* yacc.c:1652  */
    break;

  case 276:
#line 2573 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5340 "parse.c" /* yacc.c:1652  */
    break;

  case 277:
#line 2583 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5355 "parse.c" /* yacc.c:1652  */
    break;

  case 278:
#line 2593 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5375 "parse.c" /* yacc.c:1652  */
    break;

  case 279:
#line 2608 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5390 "parse.c" /* yacc.c:1652  */
    break;

  case 280:
#line 2618 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5405 "parse.c" /* yacc.c:1652  */
    break;

  case 281:
#line 2628 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP;
			memcpy(&(yyval.v.filter_set)->action.nexthop, &(yyvsp[0].v.addr),
			    sizeof((yyval.v.filter_set)->action.nexthop));
		}
#line 5417 "parse.c" /* yacc.c:1652  */
    break;

  case 282:
#line 2635 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_BLACKHOLE;
		}
#line 5427 "parse.c" /* yacc.c:1652  */
    break;

  case 283:
#line 2640 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_REJECT;
		}
#line 5437 "parse.c" /* yacc.c:1652  */
    break;

  case 284:
#line 2645 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_NOMODIFY;
		}
#line 5447 "parse.c" /* yacc.c:1652  */
    break;

  case 285:
#line 2650 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_SELF;
		}
#line 5457 "parse.c" /* yacc.c:1652  */
    break;

  case 286:
#line 2655 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5472 "parse.c" /* yacc.c:1652  */
    break;

  case 287:
#line 2665 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5487 "parse.c" /* yacc.c:1652  */
    break;

  case 288:
#line 2675 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_AS_OVERRIDE;
		}
#line 5497 "parse.c" /* yacc.c:1652  */
    break;

  case 289:
#line 2680 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5529 "parse.c" /* yacc.c:1652  */
    break;

  case 290:
#line 2707 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5548 "parse.c" /* yacc.c:1652  */
    break;

  case 291:
#line 2721 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5581 "parse.c" /* yacc.c:1652  */
    break;

  case 292:
#line 2749 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5604 "parse.c" /* yacc.c:1652  */
    break;

  case 293:
#line 2767 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5625 "parse.c" /* yacc.c:1652  */
    break;

  case 294:
#line 2783 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_ORIGIN;
			(yyval.v.filter_set)->action.origin = (yyvsp[0].v.number);
		}
#line 5636 "parse.c" /* yacc.c:1652  */
    break;

  case 295:
#line 2791 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5655 "parse.c" /* yacc.c:1652  */
    break;

  case 296:
#line 2806 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
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
#line 5674 "parse.c" /* yacc.c:1652  */
    break;

  case 303:
#line 2831 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_EQ; }
#line 5680 "parse.c" /* yacc.c:1652  */
    break;

  case 304:
#line 2832 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_NE; }
#line 5686 "parse.c" /* yacc.c:1652  */
    break;

  case 305:
#line 2833 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_LE; }
#line 5692 "parse.c" /* yacc.c:1652  */
    break;

  case 306:
#line 2834 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_LT; }
#line 5698 "parse.c" /* yacc.c:1652  */
    break;

  case 307:
#line 2835 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_GE; }
#line 5704 "parse.c" /* yacc.c:1652  */
    break;

  case 308:
#line 2836 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_GT; }
#line 5710 "parse.c" /* yacc.c:1652  */
    break;

  case 309:
#line 2839 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_EQ; }
#line 5716 "parse.c" /* yacc.c:1652  */
    break;

  case 310:
#line 2840 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_NE; }
#line 5722 "parse.c" /* yacc.c:1652  */
    break;

  case 311:
#line 2843 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_RANGE; }
#line 5728 "parse.c" /* yacc.c:1652  */
    break;

  case 312:
#line 2844 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_XRANGE; }
#line 5734 "parse.c" /* yacc.c:1652  */
    break;


#line 5738 "parse.c" /* yacc.c:1652  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2847 "../../../openbgpd-portable/src/bgpd/parse.y" /* yacc.c:1918  */


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
			n->group_id = 0;
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
