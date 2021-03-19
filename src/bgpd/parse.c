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
#line 25 "parse.y" /* yacc.c:337  */

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
static struct peer		*curpeer;
static struct peer		*curgroup;
static struct rde_rib		*currib;
static struct l3vpn		*curvpn;
static struct prefixset		*curpset, *curoset;
static struct prefixset_tree	*curpsitree;
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


#line 242 "parse.c" /* yacc.c:337  */
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
    GROUP = 280,
    NEIGHBOR = 281,
    NETWORK = 282,
    EBGP = 283,
    IBGP = 284,
    LOCALAS = 285,
    REMOTEAS = 286,
    DESCR = 287,
    LOCALADDR = 288,
    MULTIHOP = 289,
    PASSIVE = 290,
    MAXPREFIX = 291,
    RESTART = 292,
    ANNOUNCE = 293,
    CAPABILITIES = 294,
    REFRESH = 295,
    AS4BYTE = 296,
    CONNECTRETRY = 297,
    DEMOTE = 298,
    ENFORCE = 299,
    NEIGHBORAS = 300,
    ASOVERRIDE = 301,
    REFLECTOR = 302,
    DEPEND = 303,
    DOWN = 304,
    DUMP = 305,
    IN = 306,
    OUT = 307,
    SOCKET = 308,
    RESTRICTED = 309,
    LOG = 310,
    TRANSPARENT = 311,
    TCP = 312,
    MD5SIG = 313,
    PASSWORD = 314,
    KEY = 315,
    TTLSECURITY = 316,
    ALLOW = 317,
    DENY = 318,
    MATCH = 319,
    QUICK = 320,
    FROM = 321,
    TO = 322,
    ANY = 323,
    CONNECTED = 324,
    STATIC = 325,
    COMMUNITY = 326,
    EXTCOMMUNITY = 327,
    LARGECOMMUNITY = 328,
    DELETE = 329,
    PREFIX = 330,
    PREFIXLEN = 331,
    PREFIXSET = 332,
    ROASET = 333,
    ORIGINSET = 334,
    OVS = 335,
    ASSET = 336,
    SOURCEAS = 337,
    TRANSITAS = 338,
    PEERAS = 339,
    MAXASLEN = 340,
    MAXASSEQ = 341,
    SET = 342,
    LOCALPREF = 343,
    MED = 344,
    METRIC = 345,
    NEXTHOP = 346,
    REJECT = 347,
    BLACKHOLE = 348,
    NOMODIFY = 349,
    SELF = 350,
    PREPEND_SELF = 351,
    PREPEND_PEER = 352,
    PFTABLE = 353,
    WEIGHT = 354,
    RTLABEL = 355,
    ORIGIN = 356,
    PRIORITY = 357,
    ERROR = 358,
    INCLUDE = 359,
    IPSEC = 360,
    ESP = 361,
    AH = 362,
    SPI = 363,
    IKE = 364,
    IPV4 = 365,
    IPV6 = 366,
    QUALIFY = 367,
    VIA = 368,
    NE = 369,
    LE = 370,
    GE = 371,
    XRANGE = 372,
    LONGER = 373,
    MAXLEN = 374,
    STRING = 375,
    NUMBER = 376
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
#define GROUP 280
#define NEIGHBOR 281
#define NETWORK 282
#define EBGP 283
#define IBGP 284
#define LOCALAS 285
#define REMOTEAS 286
#define DESCR 287
#define LOCALADDR 288
#define MULTIHOP 289
#define PASSIVE 290
#define MAXPREFIX 291
#define RESTART 292
#define ANNOUNCE 293
#define CAPABILITIES 294
#define REFRESH 295
#define AS4BYTE 296
#define CONNECTRETRY 297
#define DEMOTE 298
#define ENFORCE 299
#define NEIGHBORAS 300
#define ASOVERRIDE 301
#define REFLECTOR 302
#define DEPEND 303
#define DOWN 304
#define DUMP 305
#define IN 306
#define OUT 307
#define SOCKET 308
#define RESTRICTED 309
#define LOG 310
#define TRANSPARENT 311
#define TCP 312
#define MD5SIG 313
#define PASSWORD 314
#define KEY 315
#define TTLSECURITY 316
#define ALLOW 317
#define DENY 318
#define MATCH 319
#define QUICK 320
#define FROM 321
#define TO 322
#define ANY 323
#define CONNECTED 324
#define STATIC 325
#define COMMUNITY 326
#define EXTCOMMUNITY 327
#define LARGECOMMUNITY 328
#define DELETE 329
#define PREFIX 330
#define PREFIXLEN 331
#define PREFIXSET 332
#define ROASET 333
#define ORIGINSET 334
#define OVS 335
#define ASSET 336
#define SOURCEAS 337
#define TRANSITAS 338
#define PEERAS 339
#define MAXASLEN 340
#define MAXASSEQ 341
#define SET 342
#define LOCALPREF 343
#define MED 344
#define METRIC 345
#define NEXTHOP 346
#define REJECT 347
#define BLACKHOLE 348
#define NOMODIFY 349
#define SELF 350
#define PREPEND_SELF 351
#define PREPEND_PEER 352
#define PFTABLE 353
#define WEIGHT 354
#define RTLABEL 355
#define ORIGIN 356
#define PRIORITY 357
#define ERROR 358
#define INCLUDE 359
#define IPSEC 360
#define ESP 361
#define AH 362
#define SPI 363
#define IKE 364
#define IPV4 365
#define IPV6 366
#define QUALIFY 367
#define VIA 368
#define NE 369
#define LE 370
#define GE 371
#define XRANGE 372
#define LONGER 373
#define MAXLEN 374
#define STRING 375
#define NUMBER 376

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
#define YYLAST   668

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  132
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  299
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  550

#define YYUNDEFTOK  2
#define YYMAXUTOK   376

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     122,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   127,   129,   128,     2,   126,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     130,   123,   131,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   124,     2,   125,     2,     2,     2,     2,
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
     115,   116,   117,   118,   119,   120,   121
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   247,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   264,   275,   307,
     317,   344,   349,   355,   358,   373,   393,   408,   408,   422,
     430,   431,   433,   433,   443,   453,   467,   483,   500,   500,
     505,   508,   508,   520,   532,   541,   552,   559,   563,   570,
     578,   586,   600,   607,   618,   624,   633,   634,   662,   694,
     695,   705,   715,   728,   741,   757,   764,   780,   780,   790,
     791,   800,   809,   810,   818,   848,   869,   898,   917,   941,
     961,   962,   965,   966,   969,   990,  1008,  1028,  1035,  1038,
    1039,  1042,  1042,  1087,  1088,  1089,  1090,  1093,  1111,  1129,
    1147,  1153,  1156,  1157,  1156,  1189,  1189,  1219,  1220,  1221,
    1222,  1223,  1226,  1227,  1228,  1231,  1232,  1233,  1234,  1237,
    1240,  1247,  1251,  1262,  1275,  1285,  1292,  1295,  1298,  1309,
    1325,  1333,  1341,  1360,  1363,  1366,  1369,  1372,  1375,  1378,
    1384,  1390,  1405,  1413,  1421,  1439,  1455,  1465,  1558,  1561,
    1568,  1580,  1581,  1591,  1607,  1619,  1643,  1649,  1662,  1663,
    1673,  1674,  1677,  1678,  1679,  1682,  1683,  1686,  1687,  1690,
    1693,  1726,  1753,  1754,  1755,  1758,  1759,  1762,  1763,  1766,
    1767,  1768,  1770,  1771,  1777,  1799,  1800,  1803,  1804,  1810,
    1817,  1837,  1844,  1865,  1871,  1879,  1894,  1909,  1910,  1913,
    1914,  1915,  1927,  1928,  1934,  1949,  1950,  1953,  1954,  1966,
    1970,  1977,  2000,  2001,  2002,  2015,  2016,  2022,  2030,  2036,
    2044,  2058,  2061,  2061,  2069,  2070,  2073,  2086,  2093,  2105,
    2117,  2135,  2157,  2176,  2184,  2191,  2240,  2260,  2270,  2271,
    2277,  2288,  2331,  2347,  2348,  2349,  2350,  2353,  2354,  2361,
    2364,  2369,  2378,  2379,  2382,  2383,  2386,  2401,  2411,  2421,
    2436,  2446,  2456,  2471,  2481,  2491,  2506,  2516,  2526,  2533,
    2538,  2543,  2548,  2553,  2563,  2573,  2578,  2605,  2619,  2647,
    2665,  2681,  2689,  2704,  2719,  2720,  2723,  2724,  2725,  2726,
    2729,  2730,  2731,  2732,  2733,  2734,  2737,  2738,  2741,  2742
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
  "RIB", "EVALUATE", "IGNORE", "COMPARE", "GROUP", "NEIGHBOR", "NETWORK",
  "EBGP", "IBGP", "LOCALAS", "REMOTEAS", "DESCR", "LOCALADDR", "MULTIHOP",
  "PASSIVE", "MAXPREFIX", "RESTART", "ANNOUNCE", "CAPABILITIES", "REFRESH",
  "AS4BYTE", "CONNECTRETRY", "DEMOTE", "ENFORCE", "NEIGHBORAS",
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
  "roa_set", "$@3", "origin_set", "$@4", "roa_set_l", "conf_main", "rib",
  "$@5", "ribopts", "fibupdate", "mrtdump", "network", "inout",
  "restricted", "address", "prefix", "addrspec", "optnumber", "l3vpn",
  "$@6", "l3vpnopts_l", "l3vpnopts", "neighbor", "$@7", "$@8", "group",
  "$@9", "groupopts_l", "peeropts_h", "peeropts_l", "peeropts", "restart",
  "family", "safi", "nettype", "espah", "encspec", "filterrule", "action",
  "quick", "direction", "filter_rib_h", "filter_rib_l", "filter_rib",
  "filter_peer_h", "filter_peer_l", "filter_peer", "filter_prefix_h",
  "filter_prefix_m", "filter_prefix_l", "filter_prefix", "filter_as_h",
  "filter_as_t_l", "filter_as_t", "filter_as_l_h", "filter_as_l",
  "filter_as", "filter_match_h", "$@10", "filter_match", "filter_elm",
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
     375,   376,    10,    61,   123,   125,    47,    43,    45,    44,
      60,    62
};
# endif

#define YYPACT_NINF -390

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-390)))

#define YYTABLE_NINF -287

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -390,   466,  -390,   -42,    47,   -23,    19,    92,    -6,    -2,
       4,     7,     6,    13,   -45,    73,     8,    77,    79,    -6,
    -390,  -390,  -390,    85,    15,    91,   116,    95,   120,   101,
    -390,   126,   131,   134,   139,   162,   181,   183,   187,  -390,
    -390,   191,   193,   216,   202,   203,   254,  -390,  -390,  -390,
    -390,   160,  -390,  -390,   211,  -390,   -23,  -390,  -390,  -390,
    -390,   318,   215,   313,   212,  -390,   218,   219,  -390,  -390,
     217,   226,   255,   104,  -390,   224,   -17,   300,  -390,  -390,
     233,   238,   242,   243,   256,  -390,    13,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,   125,  -390,  -390,
    -390,   347,  -390,  -390,  -390,   258,  -390,   259,  -390,  -390,
    -390,   250,   255,   260,   261,   197,  -390,  -390,  -390,   264,
     262,   255,   265,  -390,  -390,   267,   270,  -390,  -390,   238,
     238,   268,   238,   238,   271,   218,   217,  -390,  -390,  -390,
      31,   192,  -390,    51,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,   301,  -390,    87,   105,   110,    96,   273,   274,   272,
     123,   276,   278,   238,   301,  -390,   255,   255,  -390,   280,
    -390,  -390,   267,   279,  -390,  -390,   157,   281,   282,  -390,
     277,  -390,   238,  -390,  -390,  -390,    18,   284,    -6,   288,
     358,  -390,  -390,   315,  -390,   -31,  -390,   289,   290,  -390,
     291,   292,  -390,   294,   295,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,   296,   297,  -390,  -390,  -390,   558,
     302,  -390,  -390,   267,  -390,  -390,   157,   304,   -68,   -34,
    -390,   157,  -390,   171,   546,  -390,   303,    47,   305,  -390,
    -390,  -390,   238,  -390,   -43,  -390,  -390,  -390,   378,  -390,
     299,    20,   145,   306,    47,    47,    13,   -23,   317,  -390,
     322,   161,   307,    60,    -6,   -23,   416,   319,   329,   331,
      -6,   394,    -6,   526,   205,  -390,  -390,   423,  -390,   335,
     336,   340,   341,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,   -68,  -390,  -390,  -390,   -68,  -390,   171,   238,   342,
     337,   157,   159,  -390,   344,  -390,   -68,  -390,  -390,  -390,
     -68,  -390,   338,   -21,  -390,  -390,  -390,    30,   255,    38,
      21,  -390,  -390,   351,  -390,  -390,  -390,  -390,   160,  -390,
     218,  -390,  -390,    54,    -6,    -6,    -6,    -6,   165,  -390,
      -6,    -6,  -390,  -390,   348,  -390,   266,  -390,  -390,   263,
    -390,   238,  -390,  -390,  -390,    36,  -390,  -390,  -390,  -390,
    -390,   349,   558,   353,   157,  -390,   354,   238,  -390,   399,
    -390,  -390,  -390,   -50,  -390,  -390,  -390,   361,  -390,   359,
     362,   171,   398,  -390,   363,   303,   -68,  -390,  -390,  -390,
     -28,    72,   369,   370,   374,  -390,  -390,  -390,   375,   376,
      24,   -34,   -34,    48,  -390,  -390,  -390,    38,  -390,    89,
     379,   380,    -6,   381,   384,   385,  -390,  -390,  -390,   387,
    -390,  -390,   377,   446,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,    13,    13,   558,  -390,
     392,  -390,  -390,  -390,  -390,  -390,   171,  -390,  -390,   386,
    -390,  -390,  -390,  -390,   388,  -390,  -390,   389,  -390,  -390,
     390,    30,   393,   404,    98,   -34,  -390,   -34,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,   -52,  -390,  -390,
    -390,   405,  -390,  -390,    62,   -50,  -390,   171,  -390,  -390,
    -390,  -390,   407,   411,  -390,  -390,  -390,   218,   218,   -68,
     391,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,   157,
     408,   154,  -390,  -390,  -390,   238,  -390,    48,  -390,   107,
     409,   177,  -390,   171,  -390,  -390,  -390,   410,   412,   179,
    -390,   157,  -390,  -390,   185,  -390,   107,  -390,  -390,   417,
      98,  -390,    62,  -390,   418,  -390,  -390,   419,  -390,  -390
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      56,     0,     0,     0,     0,     0,   175,    16,    18,    17,
      19,    46,    84,    48,     0,    49,     0,    24,    53,    52,
      64,     0,     0,     0,     0,    23,   105,     0,   160,   161,
       0,     0,   247,     0,    65,     0,     0,    83,    55,    54,
       0,   284,     0,     0,     0,    26,     0,     4,     5,     6,
       7,     8,     9,    11,    10,    12,    13,     0,    14,    15,
     176,   179,    47,    50,    51,     0,    67,     0,    60,    61,
      22,     0,   247,     0,     0,     0,    75,   166,   165,     0,
       0,   247,     0,    80,    81,    89,     0,    82,    66,   284,
     284,    38,   284,   284,     0,    25,    84,    87,    88,   103,
       0,     0,    91,    72,    62,   107,    76,    85,    86,   275,
     252,   254,   253,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,   254,   248,   247,   247,    79,     0,
      90,    57,    89,    32,   285,    40,     0,    41,    27,    63,
     114,   184,   284,   180,   177,   178,     0,     0,     0,     0,
       0,    68,    69,     0,   255,     0,   256,     0,     0,   259,
       0,     0,   262,     0,     0,   270,   269,   271,   272,   268,
     273,   274,   276,   265,     0,     0,   277,   282,   281,     0,
       0,    77,    78,    89,    74,    34,     0,     0,   286,   238,
      43,     0,    29,     0,     0,   104,     0,     0,     0,   193,
     194,   189,   284,   190,   222,   185,    93,    73,    72,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,     0,     0,     0,     0,   152,     0,   127,     0,     0,
       0,     0,     0,     0,     0,   108,   106,     0,   151,     0,
       0,     0,     0,   257,   258,   260,   261,   263,   264,   266,
     267,   286,   251,   278,    58,   286,    35,     0,   284,   287,
       0,     0,     0,   239,     0,    37,   286,    20,    21,    30,
     286,   115,     0,   284,   182,   191,   192,     0,   247,     0,
       0,    70,   111,     0,   130,   137,   138,   129,   120,   119,
     122,   123,   125,   158,     0,     0,     0,     0,     0,   155,
       0,     0,   141,   153,     0,   128,     0,   157,   156,     0,
     148,   284,   149,   167,   168,     0,   124,   110,   109,   280,
     279,     0,     0,     0,     0,    44,   288,   284,    39,     0,
     291,   292,   294,     0,   290,   293,   295,     0,   240,     0,
       0,     0,     0,   113,     0,     0,   286,   187,   171,   243,
       0,     0,     0,     0,     0,   244,   245,   246,     0,     0,
       0,   238,   238,     0,   226,   227,   205,   223,   224,     0,
       0,     0,     0,     0,     0,     0,    94,    92,   101,     0,
     131,   121,     0,   158,   142,   135,   133,   134,   136,   162,
     163,   164,   132,   140,   139,   154,     0,     0,     0,   146,
       0,   249,   250,    33,    36,   289,     0,   299,   298,     0,
     241,    42,    28,    31,     0,   116,   112,     0,   181,   183,
       0,     0,     0,     0,     0,   238,   197,   238,   236,   283,
     237,   228,   229,   234,   233,   195,   196,   286,   207,   225,
     218,     0,   297,   296,     0,   217,   209,     0,   230,    96,
     100,    97,     0,     0,    95,   159,   143,   144,   145,   286,
       0,    45,   242,   118,   117,   186,   188,   232,   231,     0,
       0,   286,   202,   204,   235,   284,   206,     0,   211,     0,
       0,   286,   215,     0,   219,    98,    99,     0,     0,   286,
     198,     0,   288,   208,   286,   210,     0,   220,   150,     0,
     200,   203,   213,   216,   169,   201,   214,     0,   147,   170
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -390,  -390,    12,  -173,  -223,   -81,    -7,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -208,  -390,  -390,  -390,  -390,
     275,  -390,  -390,  -390,  -390,   293,   513,   220,   194,  -390,
      -3,   -14,  -390,  -127,  -390,  -390,  -390,  -390,   343,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -219,   119,   285,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -225,
    -390,  -390,  -300,  -390,    10,    39,  -372,  -390,  -390,  -363,
      11,    33,  -389,  -390,  -390,  -390,   147,  -330,  -390,   -98,
     117,  -295,   395,  -107,  -390,  -390,  -126,  -282,  -390,  -390,
      71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   308,    51,   485,    66,   277,    31,    32,    33,
     233,   310,    34,   226,   295,   227,    35,   176,    36,   231,
     228,    37,    38,   143,   191,   192,   278,    40,   126,   128,
     243,   229,   139,   171,    41,   187,   320,   419,    42,    43,
     180,    44,   111,   193,   235,   382,   280,   424,    73,   432,
     121,   355,   548,    45,    46,   101,   186,   141,   313,   183,
     244,   386,   245,   404,   510,   511,   512,   405,   477,   406,
     520,   521,   522,   318,   319,   407,   408,   305,   409,   116,
     291,   164,   195,   292,   218,   470,   131,   301,   377,   487,
     449
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,    58,    53,   173,   174,   135,   177,   178,   165,   362,
     309,   314,    79,   364,   146,   312,    50,   387,   296,   466,
     486,   237,   411,   168,   410,    54,   323,    62,   381,    75,
     412,   385,    67,   237,   123,   124,   413,   219,   414,   415,
     478,   389,   302,   238,  -221,   224,   239,   240,    14,   281,
     473,   389,   462,   104,   298,   238,   236,  -284,   239,   240,
     188,   299,   189,   102,   315,    68,    69,   447,   221,   222,
     515,   475,   476,   516,   365,    70,    71,   299,   448,  -221,
      47,   328,   329,   138,   303,   304,   241,   123,   124,   282,
     340,   422,   463,   369,   137,    63,   294,    52,   241,  -286,
      56,   298,   300,   125,   461,   341,   423,   480,   299,   150,
     390,   152,   410,   391,    57,   392,   317,   393,   394,    59,
     395,   396,   397,   398,   399,    60,    64,    61,    76,   400,
     395,   396,   397,    65,   480,   513,   190,   514,    52,    81,
      55,   324,   242,   416,    52,   439,   417,   543,   401,   402,
      52,   181,   480,   209,   533,   182,   444,   325,   453,   541,
     459,   506,   403,   457,   326,   361,   352,    48,    49,   363,
     481,    57,   366,   117,   118,   330,   482,   429,   430,   431,
     379,   247,   307,    49,   380,   483,   519,   384,   205,   206,
     207,   208,    70,    71,    74,   517,   464,    77,   334,    78,
     335,   336,   337,   482,   119,    80,   120,    84,   196,   307,
      49,    82,   483,   484,   197,   198,    52,   362,    70,    71,
     388,   482,   509,   501,    86,   438,   199,   307,    49,   531,
     483,   202,   200,   201,   108,   109,    83,   203,   204,   536,
      85,   445,    97,   149,   213,   136,    71,   531,    87,    50,
     214,   215,   536,    88,   331,   442,    89,   342,   184,   185,
     460,    90,   343,   348,   524,   350,    50,    50,   150,   151,
     152,    68,    69,   370,   371,   372,   515,    70,    71,  -199,
     373,    49,   374,   299,    91,   153,   154,   155,   156,   375,
     376,   307,    49,   157,   158,   159,   160,   161,   162,   515,
     537,   515,  -212,    92,   540,    93,   299,   515,   299,    94,
     542,   353,   354,    95,   299,    96,   250,   123,   124,   100,
     251,   163,   436,   437,    98,    99,   105,   425,   426,   427,
     428,   252,   103,   433,   434,   106,   253,   107,   110,   112,
     421,  -102,   115,   113,   122,   254,   255,   256,   257,   258,
     259,   260,   114,   261,   127,   497,   498,   129,   262,   263,
     130,   264,   265,   266,   267,   268,   132,   133,   140,   134,
     269,   270,   271,   527,   145,   194,   272,   465,   142,   144,
     249,   147,   148,   167,   166,   169,   297,   188,   170,   532,
     172,   179,   212,   175,   210,   211,   216,   474,   217,   454,
     223,   234,   273,   251,   225,   490,   230,   232,   246,   248,
     283,   284,   285,   286,   252,   287,   288,   289,   290,   253,
     274,   322,   293,   181,   344,   316,   327,   339,   254,   255,
     256,   257,   258,   259,   260,    57,   261,   275,   332,   345,
     276,   262,   263,   333,   264,   265,   266,   267,   268,   346,
     465,   347,   349,   269,   270,   271,   356,   357,   358,   272,
     359,   360,   368,   383,   367,   378,     2,     3,   435,     4,
       5,     6,   420,     7,   441,     8,     9,    10,   443,  -285,
      11,   446,   450,   422,   451,   273,    12,   452,   458,   467,
     468,    13,  -102,    14,   469,   465,   471,   472,   495,   488,
     500,   491,   489,   274,   492,   493,   306,   502,    15,   494,
     503,   504,   528,   507,    39,   505,    16,   465,    57,    17,
     455,    18,    19,   456,   508,   518,   465,   525,    20,    21,
      22,   526,   539,   530,   535,   538,   279,   544,   547,   549,
     418,   321,   496,    23,    24,    25,   338,    26,   529,   440,
     545,   251,   534,   546,   479,   499,   523,    27,     0,   220,
       0,     0,   252,     0,     0,     0,     0,   253,     0,     0,
      28,     0,   149,     0,     0,     0,   254,   255,   256,   257,
     258,   259,   260,     0,   261,     0,    29,     0,    30,   262,
     263,     0,   264,   265,   266,   267,   268,   150,   151,   152,
       0,   269,   270,   271,   149,     0,     0,   272,     0,     0,
       0,     0,     0,     0,   153,   154,   155,   156,     0,     0,
       0,     0,   157,   158,   159,   160,   161,   162,     0,   150,
     151,   152,     0,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     351,   274,     0,     0,   157,   158,   159,   160,   161,   162,
       0,     0,     0,     0,     0,     0,    57,     0,   311
};

static const yytype_int16 yycheck[] =
{
      14,     8,     5,   129,   130,    86,   132,   133,   115,   291,
     233,   236,    19,   295,   112,   234,     4,   317,   226,   391,
     409,     3,     1,   121,   319,     6,     6,    21,   310,    21,
       9,   313,    77,     3,    51,    52,    15,   163,    17,    18,
     403,     3,    76,    25,    87,   172,    28,    29,    27,    80,
      26,     3,    80,    56,   122,    25,   182,   125,    28,    29,
       9,   129,    11,    51,   237,   110,   111,   117,   166,   167,
     122,   401,   402,   125,   297,   120,   121,   129,   128,   122,
     122,   254,   255,    97,   118,   119,    68,    51,    52,   120,
      30,    37,   120,   301,    97,    89,   223,   120,    68,   120,
       8,   122,   228,   120,   386,    45,    52,    45,   129,    71,
      72,    73,   407,    75,   120,    77,   242,    79,    80,   121,
      82,    83,    84,    85,    86,   121,   120,   120,   120,    91,
      82,    83,    84,   120,    45,   465,   143,   467,   120,   124,
     121,   121,   124,   122,   120,   109,   125,   536,   110,   111,
     120,   120,    45,   156,   517,   124,   364,    12,   381,   531,
     385,   461,   124,   382,    19,   291,   273,   120,   121,   295,
      81,   120,   298,    69,    70,   256,   114,    12,    13,    14,
     306,   188,   120,   121,   310,   123,   124,   313,    92,    93,
      94,    95,   120,   121,   121,   477,   124,   120,    37,   120,
      39,    40,    41,   114,   100,   120,   102,   112,   121,   120,
     121,   120,   123,   124,   127,   128,   120,   499,   120,   121,
     318,   114,   124,   446,   123,   351,   121,   120,   121,   511,
     123,   121,   127,   128,    22,    23,   120,   127,   128,   521,
     120,   367,    26,    46,   121,   120,   121,   529,   122,   237,
     127,   128,   534,   122,   257,   362,   122,   264,    66,    67,
     386,   122,   265,   270,   487,   272,   254,   255,    71,    72,
      73,   110,   111,   114,   115,   116,   122,   120,   121,   125,
     121,   121,   123,   129,   122,    88,    89,    90,    91,   130,
     131,   120,   121,    96,    97,    98,    99,   100,   101,   122,
     523,   122,   125,   122,   125,   122,   129,   122,   129,   122,
     125,   106,   107,   122,   129,   122,     1,    51,    52,    65,
       5,   124,    59,    60,   122,   122,     8,   334,   335,   336,
     337,    16,   121,   340,   341,   120,    21,    24,   120,   120,
     328,    26,    87,   126,   120,    30,    31,    32,    33,    34,
      35,    36,   126,    38,    54,   436,   437,   124,    43,    44,
     122,    46,    47,    48,    49,    50,   124,   124,    21,   113,
      55,    56,    57,   499,   124,    74,    61,   391,   120,   120,
      22,   121,   121,   121,   120,   120,    82,     9,   121,   515,
     120,   120,   120,   125,   121,   121,   120,   400,   120,     1,
     120,   124,    87,     5,   125,   412,   125,   125,   124,   121,
     121,   121,   121,   121,    16,   121,   121,   121,   121,    21,
     105,   122,   120,   120,     8,   120,   120,   120,    30,    31,
      32,    33,    34,    35,    36,   120,    38,   122,   121,   120,
     125,    43,    44,   121,    46,    47,    48,    49,    50,   120,
     464,   120,    58,    55,    56,    57,    33,   122,   122,    61,
     120,   120,   125,   125,   122,   121,     0,     1,   120,     3,
       4,     5,   121,     7,   125,     9,    10,    11,   125,   125,
      14,    82,   121,    37,   125,    87,    20,   125,   125,   120,
     120,    25,    26,    27,   120,   509,   121,   121,   121,   120,
     108,   120,   122,   105,   120,   120,   231,   121,    42,   122,
     122,   122,   121,   120,     1,   125,    50,   531,   120,    53,
     122,    55,    56,   125,   120,   120,   540,   120,    62,    63,
      64,   120,   120,   125,   125,   125,   193,   120,   120,   120,
     320,   248,   423,    77,    78,    79,   261,    81,   509,   355,
     540,     5,   519,   542,   407,   438,   485,    91,    -1,   164,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    21,    -1,    -1,
     104,    -1,    46,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    -1,   120,    -1,   122,    43,
      44,    -1,    46,    47,    48,    49,    50,    71,    72,    73,
      -1,    55,    56,    57,    46,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,   100,   101,    -1,    71,
      72,    73,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
     124,   105,    -1,    -1,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   133,     0,     1,     3,     4,     5,     7,     9,    10,
      11,    14,    20,    25,    27,    42,    50,    53,    55,    56,
      62,    63,    64,    77,    78,    79,    81,    91,   104,   120,
     122,   139,   140,   141,   144,   148,   150,   153,   154,   158,
     159,   166,   170,   171,   173,   185,   186,   122,   120,   121,
     134,   135,   120,   162,     6,   121,     8,   120,   138,   121,
     121,   120,    21,    89,   120,   120,   137,    77,   110,   111,
     120,   121,   163,   180,   121,    21,   120,   120,   120,   138,
     120,   124,   120,   120,   112,   120,   123,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,    26,   122,   122,
      65,   187,   134,   121,   162,     8,   120,    24,    22,    23,
     120,   174,   120,   126,   126,    87,   211,    69,    70,   100,
     102,   182,   120,    51,    52,   120,   160,    54,   161,   124,
     122,   218,   124,   124,   113,   137,   120,   162,   163,   164,
      21,   189,   120,   155,   120,   124,   211,   121,   121,    46,
      71,    72,    73,    88,    89,    90,    91,    96,    97,    98,
      99,   100,   101,   124,   213,   215,   120,   121,   211,   120,
     121,   165,   120,   218,   218,   125,   149,   218,   218,   120,
     172,   120,   124,   191,    66,    67,   188,   167,     9,    11,
     138,   156,   157,   175,    74,   214,   121,   127,   128,   121,
     127,   128,   121,   127,   128,    92,    93,    94,    95,   162,
     121,   121,   120,   121,   127,   128,   120,   120,   216,   218,
     214,   211,   211,   120,   165,   125,   145,   147,   152,   163,
     125,   151,   125,   142,   124,   176,   218,     3,    25,    28,
      29,    68,   124,   162,   192,   194,   124,   138,   121,    22,
       1,     5,    16,    21,    30,    31,    32,    33,    34,    35,
      36,    38,    43,    44,    46,    47,    48,    49,    50,    55,
      56,    57,    61,    87,   105,   122,   125,   138,   158,   170,
     178,    80,   120,   121,   121,   121,   121,   121,   121,   121,
     121,   212,   215,   120,   165,   146,   147,    82,   122,   129,
     218,   219,    76,   118,   119,   209,   152,   120,   134,   136,
     143,   122,   178,   190,   191,   135,   120,   218,   205,   206,
     168,   157,   122,     6,   121,    12,    19,   120,   135,   135,
     137,   162,   121,   121,    37,    39,    40,    41,   180,   120,
      30,    45,   138,   162,     8,   120,   120,   120,   138,    58,
     138,   124,   215,   106,   107,   183,    33,   122,   122,   120,
     120,   218,   219,   218,   219,   136,   218,   122,   125,   147,
     114,   115,   116,   121,   123,   130,   131,   220,   121,   218,
     218,   219,   177,   125,   218,   219,   193,   194,   211,     3,
      72,    75,    77,    79,    80,    82,    83,    84,    85,    86,
      91,   110,   111,   124,   195,   199,   201,   207,   208,   210,
     213,     1,     9,    15,    17,    18,   122,   125,   159,   169,
     121,   134,    37,    52,   179,   138,   138,   138,   138,    12,
      13,    14,   181,   138,   138,   120,    59,    60,   218,   109,
     160,   125,   215,   125,   147,   218,    82,   117,   128,   222,
     121,   125,   125,   136,     1,   122,   125,   178,   125,   191,
     218,   219,    80,   120,   124,   163,   198,   120,   120,   120,
     217,   121,   121,    26,   162,   209,   209,   200,   201,   208,
      45,    81,   114,   123,   124,   136,   204,   221,   120,   122,
     138,   120,   120,   120,   122,   121,   179,   137,   137,   212,
     108,   136,   121,   122,   122,   125,   194,   120,   120,   124,
     196,   197,   198,   209,   209,   122,   125,   219,   120,   124,
     202,   203,   204,   222,   136,   120,   120,   218,   121,   197,
     125,   219,   218,   201,   203,   125,   219,   136,   125,   120,
     125,   198,   125,   204,   120,   196,   202,   120,   184,   120
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   132,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   134,   135,   135,
     136,   136,   137,   137,   138,   139,   140,   142,   141,   141,
     143,   143,   145,   144,   144,   146,   146,   147,   149,   148,
     148,   151,   150,   150,   152,   152,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   155,   154,   156,
     156,   156,   157,   157,   158,   159,   159,   159,   159,   159,
     160,   160,   161,   161,   162,   163,   163,   164,   164,   165,
     165,   167,   166,   168,   168,   168,   168,   169,   169,   169,
     169,   169,   171,   172,   170,   174,   173,   175,   175,   175,
     175,   175,   176,   176,   176,   177,   177,   177,   177,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   179,   179,
     180,   180,   181,   181,   181,   182,   182,   183,   183,   184,
     184,   185,   186,   186,   186,   187,   187,   188,   188,   189,
     189,   189,   190,   190,   191,   192,   192,   193,   193,   194,
     194,   194,   194,   194,   194,   195,   195,   195,   195,   196,
     196,   196,   197,   197,   198,   199,   199,   200,   200,   201,
     201,   201,   202,   202,   202,   203,   203,   204,   204,   204,
     204,   205,   206,   205,   207,   207,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   209,   209,
     209,   209,   209,   210,   210,   210,   210,   211,   211,   211,
     212,   212,   213,   213,   214,   214,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   216,   217,   218,   218,   219,   219,   219,   219,
     220,   220,   220,   220,   220,   220,   221,   221,   222,   222
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     2,     1,     1,     3,     2,     0,     8,     5,
       1,     3,     0,     8,     5,     1,     3,     2,     0,     7,
       4,     0,     8,     5,     3,     5,     2,     3,     2,     2,
       3,     3,     2,     2,     2,     2,     1,     4,     6,     1,
       3,     3,     4,     4,     2,     2,     3,     0,     5,     1,
       3,     2,     0,     2,     5,     3,     4,     5,     5,     4,
       1,     1,     1,     0,     1,     3,     3,     1,     1,     0,
       1,     0,     8,     0,     2,     3,     3,     2,     3,     3,
       2,     1,     0,     0,     5,     0,     6,     0,     2,     3,
       3,     3,     4,     3,     0,     0,     2,     3,     3,     2,
       2,     3,     2,     2,     2,     2,     1,     1,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     2,     3,     4,     4,     4,     3,     8,     2,     2,
       6,     1,     1,     2,     3,     2,     2,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     7,     1,     1,     1,     0,     1,     1,     1,     0,
       2,     6,     1,     3,     1,     1,     5,     1,     3,     1,
       1,     2,     2,     1,     1,     2,     2,     2,     4,     1,
       3,     4,     1,     3,     2,     1,     3,     1,     3,     2,
       4,     3,     1,     3,     4,     1,     3,     1,     1,     2,
       3,     0,     0,     2,     1,     2,     1,     1,     2,     2,
       2,     3,     3,     2,     2,     3,     2,     2,     0,     1,
       2,     3,     4,     1,     1,     1,     1,     0,     2,     6,
       3,     1,     1,     1,     0,     1,     2,     3,     3,     2,
       3,     3,     2,     3,     3,     2,     3,     3,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     3,     4,
       4,     2,     1,     1,     0,     2,     0,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
        case 16:
#line 261 "parse.y" /* yacc.c:1652  */
    { file->errors++; }
#line 2051 "parse.c" /* yacc.c:1652  */
    break;

  case 17:
#line 264 "parse.y" /* yacc.c:1652  */
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
#line 2066 "parse.c" /* yacc.c:1652  */
    break;

  case 18:
#line 275 "parse.y" /* yacc.c:1652  */
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
#line 2103 "parse.c" /* yacc.c:1652  */
    break;

  case 19:
#line 307 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == AS_TRANS || (yyvsp[0].v.number) == 0) {
				yyerror("AS %u is reserved and may not be used",
				    (u_int32_t)(yyvsp[0].v.number));
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2116 "parse.c" /* yacc.c:1652  */
    break;

  case 20:
#line 317 "parse.y" /* yacc.c:1652  */
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
#line 2148 "parse.c" /* yacc.c:1652  */
    break;

  case 21:
#line 344 "parse.y" /* yacc.c:1652  */
    {
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 2156 "parse.c" /* yacc.c:1652  */
    break;

  case 22:
#line 349 "parse.y" /* yacc.c:1652  */
    {
			if (asprintf(&(yyval.v.string), "%s %s", (yyvsp[-1].v.string), (yyvsp[0].v.string)) == -1)
				fatal("string: asprintf");
			free((yyvsp[-1].v.string));
			free((yyvsp[0].v.string));
		}
#line 2167 "parse.c" /* yacc.c:1652  */
    break;

  case 24:
#line 358 "parse.y" /* yacc.c:1652  */
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
#line 2185 "parse.c" /* yacc.c:1652  */
    break;

  case 25:
#line 373 "parse.y" /* yacc.c:1652  */
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
#line 2208 "parse.c" /* yacc.c:1652  */
    break;

  case 26:
#line 393 "parse.y" /* yacc.c:1652  */
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
#line 2226 "parse.c" /* yacc.c:1652  */
    break;

  case 27:
#line 408 "parse.y" /* yacc.c:1652  */
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
#line 2243 "parse.c" /* yacc.c:1652  */
    break;

  case 28:
#line 419 "parse.y" /* yacc.c:1652  */
    {
			done_as_set();
		}
#line 2251 "parse.c" /* yacc.c:1652  */
    break;

  case 29:
#line 422 "parse.y" /* yacc.c:1652  */
    {
			if (new_as_set((yyvsp[-3].v.string)) != 0) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
		}
#line 2263 "parse.c" /* yacc.c:1652  */
    break;

  case 30:
#line 430 "parse.y" /* yacc.c:1652  */
    { add_as_set((yyvsp[0].v.number)); }
#line 2269 "parse.c" /* yacc.c:1652  */
    break;

  case 31:
#line 431 "parse.y" /* yacc.c:1652  */
    { add_as_set((yyvsp[0].v.number)); }
#line 2275 "parse.c" /* yacc.c:1652  */
    break;

  case 32:
#line 433 "parse.y" /* yacc.c:1652  */
    {
			if ((curpset = new_prefix_set((yyvsp[-2].v.string), 0)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			free((yyvsp[-2].v.string));
		}
#line 2287 "parse.c" /* yacc.c:1652  */
    break;

  case 33:
#line 439 "parse.y" /* yacc.c:1652  */
    {
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2296 "parse.c" /* yacc.c:1652  */
    break;

  case 34:
#line 443 "parse.y" /* yacc.c:1652  */
    {
			if ((curpset = new_prefix_set((yyvsp[-3].v.string), 0)) == NULL) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
			SIMPLEQ_INSERT_TAIL(&conf->prefixsets, curpset, entry);
			curpset = NULL;
		}
#line 2310 "parse.c" /* yacc.c:1652  */
    break;

  case 35:
#line 453 "parse.y" /* yacc.c:1652  */
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
#line 2329 "parse.c" /* yacc.c:1652  */
    break;

  case 36:
#line 467 "parse.y" /* yacc.c:1652  */
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
#line 2348 "parse.c" /* yacc.c:1652  */
    break;

  case 37:
#line 483 "parse.y" /* yacc.c:1652  */
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
#line 2368 "parse.c" /* yacc.c:1652  */
    break;

  case 38:
#line 500 "parse.y" /* yacc.c:1652  */
    {
			curpsitree = &conf->roa;
		}
#line 2376 "parse.c" /* yacc.c:1652  */
    break;

  case 39:
#line 502 "parse.y" /* yacc.c:1652  */
    {
			curpsitree = NULL;
		}
#line 2384 "parse.c" /* yacc.c:1652  */
    break;

  case 41:
#line 508 "parse.y" /* yacc.c:1652  */
    {
			if ((curoset = new_prefix_set((yyvsp[-2].v.string), 1)) == NULL) {
				free((yyvsp[-2].v.string));
				YYERROR;
			}
			curpsitree = &curoset->psitems;
			free((yyvsp[-2].v.string));
		}
#line 2397 "parse.c" /* yacc.c:1652  */
    break;

  case 42:
#line 515 "parse.y" /* yacc.c:1652  */
    {
			SIMPLEQ_INSERT_TAIL(&conf->originsets, curoset, entry);
			curoset = NULL;
			curpsitree = NULL;
		}
#line 2407 "parse.c" /* yacc.c:1652  */
    break;

  case 43:
#line 520 "parse.y" /* yacc.c:1652  */
    {
			if ((curoset = new_prefix_set((yyvsp[-3].v.string), 1)) == NULL) {
				free((yyvsp[-3].v.string));
				YYERROR;
			}
			free((yyvsp[-3].v.string));
			SIMPLEQ_INSERT_TAIL(&conf->originsets, curoset, entry);
			curoset = NULL;
			curpsitree = NULL;
		}
#line 2422 "parse.c" /* yacc.c:1652  */
    break;

  case 44:
#line 532 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[-2].v.prefixset_item)->p.len_min != (yyvsp[-2].v.prefixset_item)->p.len) {
				yyerror("unsupported prefixlen operation in "
				    "roa-set");
				free((yyvsp[-2].v.prefixset_item));
				YYERROR;
			}
			add_roa_set((yyvsp[-2].v.prefixset_item), (yyvsp[0].v.number), (yyvsp[-2].v.prefixset_item)->p.len_max);
		}
#line 2436 "parse.c" /* yacc.c:1652  */
    break;

  case 45:
#line 541 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[-2].v.prefixset_item)->p.len_min != (yyvsp[-2].v.prefixset_item)->p.len) {
				yyerror("unsupported prefixlen operation in "
				    "roa-set");
				free((yyvsp[-2].v.prefixset_item));
				YYERROR;
			}
			add_roa_set((yyvsp[-2].v.prefixset_item), (yyvsp[0].v.number), (yyvsp[-2].v.prefixset_item)->p.len_max);
		}
#line 2450 "parse.c" /* yacc.c:1652  */
    break;

  case 46:
#line 552 "parse.y" /* yacc.c:1652  */
    {
			conf->as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				conf->short_as = AS_TRANS;
			else
				conf->short_as = (yyvsp[0].v.number);
		}
#line 2462 "parse.c" /* yacc.c:1652  */
    break;

  case 47:
#line 559 "parse.y" /* yacc.c:1652  */
    {
			conf->as = (yyvsp[-1].v.number);
			conf->short_as = (yyvsp[0].v.number);
		}
#line 2471 "parse.c" /* yacc.c:1652  */
    break;

  case 48:
#line 563 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.addr).aid != AID_INET) {
				yyerror("router-id must be an IPv4 address");
				YYERROR;
			}
			conf->bgpid = (yyvsp[0].v.addr).v4.s_addr;
		}
#line 2483 "parse.c" /* yacc.c:1652  */
    break;

  case 49:
#line 570 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->holdtime = (yyvsp[0].v.number);
		}
#line 2496 "parse.c" /* yacc.c:1652  */
    break;

  case 50:
#line 578 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			conf->min_holdtime = (yyvsp[0].v.number);
		}
#line 2509 "parse.c" /* yacc.c:1652  */
    break;

  case 51:
#line 586 "parse.y" /* yacc.c:1652  */
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
#line 2528 "parse.c" /* yacc.c:1652  */
    break;

  case 52:
#line 600 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) <= RTP_NONE || (yyvsp[0].v.number) > RTP_MAX) {
				yyerror("invalid fib-priority");
				YYERROR;
			}
			conf->fib_priority = (yyvsp[0].v.number);
		}
#line 2540 "parse.c" /* yacc.c:1652  */
    break;

  case 53:
#line 607 "parse.y" /* yacc.c:1652  */
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
#line 2556 "parse.c" /* yacc.c:1652  */
    break;

  case 54:
#line 618 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == 1)
				conf->flags |= BGPD_FLAG_DECISION_TRANS_AS;
			else
				conf->flags &= ~BGPD_FLAG_DECISION_TRANS_AS;
		}
#line 2567 "parse.c" /* yacc.c:1652  */
    break;

  case 55:
#line 624 "parse.y" /* yacc.c:1652  */
    {
			if (!strcmp((yyvsp[0].v.string), "updates"))
				conf->log |= BGPD_LOG_UPDATES;
			else {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 2581 "parse.c" /* yacc.c:1652  */
    break;

  case 57:
#line 634 "parse.y" /* yacc.c:1652  */
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
#line 2614 "parse.c" /* yacc.c:1652  */
    break;

  case 58:
#line 662 "parse.y" /* yacc.c:1652  */
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
#line 2651 "parse.c" /* yacc.c:1652  */
    break;

  case 60:
#line 695 "parse.y" /* yacc.c:1652  */
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
#line 2666 "parse.c" /* yacc.c:1652  */
    break;

  case 61:
#line 705 "parse.y" /* yacc.c:1652  */
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
#line 2681 "parse.c" /* yacc.c:1652  */
    break;

  case 62:
#line 715 "parse.y" /* yacc.c:1652  */
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
#line 2699 "parse.c" /* yacc.c:1652  */
    break;

  case 63:
#line 728 "parse.y" /* yacc.c:1652  */
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
#line 2717 "parse.c" /* yacc.c:1652  */
    break;

  case 64:
#line 741 "parse.y" /* yacc.c:1652  */
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
#line 2738 "parse.c" /* yacc.c:1652  */
    break;

  case 65:
#line 757 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) > USHRT_MAX || (yyvsp[0].v.number) < 1) {
				yyerror("invalid connect-retry");
				YYERROR;
			}
			conf->connectretry = (yyvsp[0].v.number);
		}
#line 2750 "parse.c" /* yacc.c:1652  */
    break;

  case 66:
#line 764 "parse.y" /* yacc.c:1652  */
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
#line 2769 "parse.c" /* yacc.c:1652  */
    break;

  case 67:
#line 780 "parse.y" /* yacc.c:1652  */
    {
			if ((currib = add_rib((yyvsp[0].v.string))) == NULL) {
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
		}
#line 2781 "parse.c" /* yacc.c:1652  */
    break;

  case 68:
#line 786 "parse.y" /* yacc.c:1652  */
    {
			currib = NULL;
		}
#line 2789 "parse.c" /* yacc.c:1652  */
    break;

  case 70:
#line 791 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[-1].v.number) > RT_TABLEID_MAX) {
				yyerror("rtable %llu too big: max %u", (yyvsp[-1].v.number),
				    RT_TABLEID_MAX);
				YYERROR;
			}
			if (rib_add_fib(currib, (yyvsp[-1].v.number)) == -1)
				YYERROR;
		}
#line 2803 "parse.c" /* yacc.c:1652  */
    break;

  case 71:
#line 800 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[-1].v.number)) {
				yyerror("bad rde rib definition");
				YYERROR;
			}
			currib->flags |= F_RIB_NOEVALUATE;
		}
#line 2815 "parse.c" /* yacc.c:1652  */
    break;

  case 73:
#line 810 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == 0)
				currib->flags |= F_RIB_NOFIBSYNC;
			else
				currib->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 2826 "parse.c" /* yacc.c:1652  */
    break;

  case 74:
#line 818 "parse.y" /* yacc.c:1652  */
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
#line 2859 "parse.c" /* yacc.c:1652  */
    break;

  case 75:
#line 848 "parse.y" /* yacc.c:1652  */
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
#line 2885 "parse.c" /* yacc.c:1652  */
    break;

  case 76:
#line 869 "parse.y" /* yacc.c:1652  */
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
#line 2919 "parse.c" /* yacc.c:1652  */
    break;

  case 77:
#line 898 "parse.y" /* yacc.c:1652  */
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
#line 2943 "parse.c" /* yacc.c:1652  */
    break;

  case 78:
#line 917 "parse.y" /* yacc.c:1652  */
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
#line 2972 "parse.c" /* yacc.c:1652  */
    break;

  case 79:
#line 941 "parse.y" /* yacc.c:1652  */
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
#line 2995 "parse.c" /* yacc.c:1652  */
    break;

  case 80:
#line 961 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 1; }
#line 3001 "parse.c" /* yacc.c:1652  */
    break;

  case 81:
#line 962 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 3007 "parse.c" /* yacc.c:1652  */
    break;

  case 82:
#line 965 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 1; }
#line 3013 "parse.c" /* yacc.c:1652  */
    break;

  case 83:
#line 966 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 3019 "parse.c" /* yacc.c:1652  */
    break;

  case 84:
#line 969 "parse.y" /* yacc.c:1652  */
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
#line 3043 "parse.c" /* yacc.c:1652  */
    break;

  case 85:
#line 990 "parse.y" /* yacc.c:1652  */
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
#line 3066 "parse.c" /* yacc.c:1652  */
    break;

  case 86:
#line 1008 "parse.y" /* yacc.c:1652  */
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
#line 3089 "parse.c" /* yacc.c:1652  */
    break;

  case 87:
#line 1028 "parse.y" /* yacc.c:1652  */
    {
			memcpy(&(yyval.v.prefix).prefix, &(yyvsp[0].v.addr), sizeof(struct bgpd_addr));
			if ((yyval.v.prefix).prefix.aid == AID_INET)
				(yyval.v.prefix).len = 32;
			else
				(yyval.v.prefix).len = 128;
		}
#line 3101 "parse.c" /* yacc.c:1652  */
    break;

  case 89:
#line 1038 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 3107 "parse.c" /* yacc.c:1652  */
    break;

  case 91:
#line 1042 "parse.y" /* yacc.c:1652  */
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
#line 3150 "parse.c" /* yacc.c:1652  */
    break;

  case 92:
#line 1079 "parse.y" /* yacc.c:1652  */
    {
			/* insert into list */
			SIMPLEQ_INSERT_TAIL(&conf->l3vpns, curvpn, entry);
			curvpn = NULL;
			netconf = &conf->networks;
		}
#line 3161 "parse.c" /* yacc.c:1652  */
    break;

  case 97:
#line 1093 "parse.y" /* yacc.c:1652  */
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
#line 3184 "parse.c" /* yacc.c:1652  */
    break;

  case 98:
#line 1111 "parse.y" /* yacc.c:1652  */
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
#line 3207 "parse.c" /* yacc.c:1652  */
    break;

  case 99:
#line 1129 "parse.y" /* yacc.c:1652  */
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
#line 3230 "parse.c" /* yacc.c:1652  */
    break;

  case 100:
#line 1147 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == 0)
				curvpn->flags |= F_RIB_NOFIBSYNC;
			else
				curvpn->flags &= ~F_RIB_NOFIBSYNC;
		}
#line 3241 "parse.c" /* yacc.c:1652  */
    break;

  case 102:
#line 1156 "parse.y" /* yacc.c:1652  */
    {	curpeer = new_peer(); }
#line 3247 "parse.c" /* yacc.c:1652  */
    break;

  case 103:
#line 1157 "parse.y" /* yacc.c:1652  */
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
#line 3266 "parse.c" /* yacc.c:1652  */
    break;

  case 104:
#line 1171 "parse.y" /* yacc.c:1652  */
    {
			if (curpeer_filter[0] != NULL)
				TAILQ_INSERT_TAIL(peerfilter_l,
				    curpeer_filter[0], entry);
			if (curpeer_filter[1] != NULL)
				TAILQ_INSERT_TAIL(peerfilter_l,
				    curpeer_filter[1], entry);
			curpeer_filter[0] = NULL;
			curpeer_filter[1] = NULL;

			if (neighbor_consistent(curpeer) == -1)
				YYERROR;
			if (RB_INSERT(peer_head, new_peers, curpeer) != NULL)
				fatalx("%s: peer tree is corrupt", __func__);
			curpeer = curgroup;
		}
#line 3287 "parse.c" /* yacc.c:1652  */
    break;

  case 105:
#line 1189 "parse.y" /* yacc.c:1652  */
    {
			curgroup = curpeer = new_group();
			if (strlcpy(curgroup->conf.group, (yyvsp[0].v.string),
			    sizeof(curgroup->conf.group)) >=
			    sizeof(curgroup->conf.group)) {
				yyerror("group name \"%s\" too long: max %zu",
				    (yyvsp[0].v.string), sizeof(curgroup->conf.group) - 1);
				free((yyvsp[0].v.string));
				YYERROR;
			}
			free((yyvsp[0].v.string));
			if (get_id(curgroup)) {
				yyerror("get_id failed");
				YYERROR;
			}
		}
#line 3308 "parse.c" /* yacc.c:1652  */
    break;

  case 106:
#line 1204 "parse.y" /* yacc.c:1652  */
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
#line 3326 "parse.c" /* yacc.c:1652  */
    break;

  case 119:
#line 1237 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.remote_as = (yyvsp[0].v.number);
		}
#line 3334 "parse.c" /* yacc.c:1652  */
    break;

  case 120:
#line 1240 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.local_as = (yyvsp[0].v.number);
			if ((yyvsp[0].v.number) > USHRT_MAX)
				curpeer->conf.local_short_as = AS_TRANS;
			else
				curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3346 "parse.c" /* yacc.c:1652  */
    break;

  case 121:
#line 1247 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.local_as = (yyvsp[-1].v.number);
			curpeer->conf.local_short_as = (yyvsp[0].v.number);
		}
#line 3355 "parse.c" /* yacc.c:1652  */
    break;

  case 122:
#line 1251 "parse.y" /* yacc.c:1652  */
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
#line 3371 "parse.c" /* yacc.c:1652  */
    break;

  case 123:
#line 1262 "parse.y" /* yacc.c:1652  */
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
#line 3389 "parse.c" /* yacc.c:1652  */
    break;

  case 124:
#line 1275 "parse.y" /* yacc.c:1652  */
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
#line 3404 "parse.c" /* yacc.c:1652  */
    break;

  case 125:
#line 1285 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < 2 || (yyvsp[0].v.number) > 255) {
				yyerror("invalid multihop distance %lld", (yyvsp[0].v.number));
				YYERROR;
			}
			curpeer->conf.distance = (yyvsp[0].v.number);
		}
#line 3416 "parse.c" /* yacc.c:1652  */
    break;

  case 126:
#line 1292 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.passive = 1;
		}
#line 3424 "parse.c" /* yacc.c:1652  */
    break;

  case 127:
#line 1295 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.down = 1;
		}
#line 3432 "parse.c" /* yacc.c:1652  */
    break;

  case 128:
#line 1298 "parse.y" /* yacc.c:1652  */
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
#line 3448 "parse.c" /* yacc.c:1652  */
    break;

  case 129:
#line 1309 "parse.y" /* yacc.c:1652  */
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
#line 3469 "parse.c" /* yacc.c:1652  */
    break;

  case 130:
#line 1325 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.holdtime = (yyvsp[0].v.number);
		}
#line 3482 "parse.c" /* yacc.c:1652  */
    break;

  case 131:
#line 1333 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < MIN_HOLDTIME || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("holdtime must be between %u and %u",
				    MIN_HOLDTIME, USHRT_MAX);
				YYERROR;
			}
			curpeer->conf.min_holdtime = (yyvsp[0].v.number);
		}
#line 3495 "parse.c" /* yacc.c:1652  */
    break;

  case 132:
#line 1341 "parse.y" /* yacc.c:1652  */
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
#line 3519 "parse.c" /* yacc.c:1652  */
    break;

  case 133:
#line 1360 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.announce_capa = (yyvsp[0].v.number);
		}
#line 3527 "parse.c" /* yacc.c:1652  */
    break;

  case 134:
#line 1363 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.capabilities.refresh = (yyvsp[0].v.number);
		}
#line 3535 "parse.c" /* yacc.c:1652  */
    break;

  case 135:
#line 1366 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.capabilities.grestart.restart = (yyvsp[0].v.number);
		}
#line 3543 "parse.c" /* yacc.c:1652  */
    break;

  case 136:
#line 1369 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.capabilities.as4byte = (yyvsp[0].v.number);
		}
#line 3551 "parse.c" /* yacc.c:1652  */
    break;

  case 137:
#line 1372 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.export_type = EXPORT_NONE;
		}
#line 3559 "parse.c" /* yacc.c:1652  */
    break;

  case 138:
#line 1375 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.export_type = EXPORT_DEFAULT_ROUTE;
		}
#line 3567 "parse.c" /* yacc.c:1652  */
    break;

  case 139:
#line 1378 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_as = ENFORCE_AS_OFF;
		}
#line 3578 "parse.c" /* yacc.c:1652  */
    break;

  case 140:
#line 1384 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number))
				curpeer->conf.enforce_local_as = ENFORCE_AS_ON;
			else
				curpeer->conf.enforce_local_as = ENFORCE_AS_OFF;
		}
#line 3589 "parse.c" /* yacc.c:1652  */
    break;

  case 141:
#line 1390 "parse.y" /* yacc.c:1652  */
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
#line 3609 "parse.c" /* yacc.c:1652  */
    break;

  case 142:
#line 1405 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[-1].v.number) < 0 || (yyvsp[-1].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_prefix = (yyvsp[-1].v.number);
			curpeer->conf.max_prefix_restart = (yyvsp[0].v.number);
		}
#line 3622 "parse.c" /* yacc.c:1652  */
    break;

  case 143:
#line 1413 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[-2].v.number) < 0 || (yyvsp[-2].v.number) > UINT_MAX) {
				yyerror("bad maximum number of prefixes");
				YYERROR;
			}
			curpeer->conf.max_out_prefix = (yyvsp[-2].v.number);
			curpeer->conf.max_out_prefix_restart = (yyvsp[0].v.number);
		}
#line 3635 "parse.c" /* yacc.c:1652  */
    break;

  case 144:
#line 1421 "parse.y" /* yacc.c:1652  */
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
#line 3658 "parse.c" /* yacc.c:1652  */
    break;

  case 145:
#line 1439 "parse.y" /* yacc.c:1652  */
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
#line 3679 "parse.c" /* yacc.c:1652  */
    break;

  case 146:
#line 1455 "parse.y" /* yacc.c:1652  */
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
#line 3694 "parse.c" /* yacc.c:1652  */
    break;

  case 147:
#line 1465 "parse.y" /* yacc.c:1652  */
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
#line 3792 "parse.c" /* yacc.c:1652  */
    break;

  case 148:
#line 1558 "parse.y" /* yacc.c:1652  */
    {
			curpeer->conf.ttlsec = (yyvsp[0].v.number);
		}
#line 3800 "parse.c" /* yacc.c:1652  */
    break;

  case 149:
#line 1561 "parse.y" /* yacc.c:1652  */
    {
			struct filter_rule	*r;

			r = get_rule((yyvsp[0].v.filter_set)->type);
			if (merge_filterset(&r->set, (yyvsp[0].v.filter_set)) == -1)
				YYERROR;
		}
#line 3812 "parse.c" /* yacc.c:1652  */
    break;

  case 150:
#line 1568 "parse.y" /* yacc.c:1652  */
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
#line 3829 "parse.c" /* yacc.c:1652  */
    break;

  case 152:
#line 1581 "parse.y" /* yacc.c:1652  */
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
#line 3844 "parse.c" /* yacc.c:1652  */
    break;

  case 153:
#line 1591 "parse.y" /* yacc.c:1652  */
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
#line 3865 "parse.c" /* yacc.c:1652  */
    break;

  case 154:
#line 1607 "parse.y" /* yacc.c:1652  */
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
#line 3882 "parse.c" /* yacc.c:1652  */
    break;

  case 155:
#line 1619 "parse.y" /* yacc.c:1652  */
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
#line 3911 "parse.c" /* yacc.c:1652  */
    break;

  case 156:
#line 1643 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) == 1)
				curpeer->conf.flags |= PEERFLAG_TRANS_AS;
			else
				curpeer->conf.flags &= ~PEERFLAG_TRANS_AS;
		}
#line 3922 "parse.c" /* yacc.c:1652  */
    break;

  case 157:
#line 1649 "parse.y" /* yacc.c:1652  */
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
#line 3938 "parse.c" /* yacc.c:1652  */
    break;

  case 158:
#line 1662 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 3944 "parse.c" /* yacc.c:1652  */
    break;

  case 159:
#line 1663 "parse.y" /* yacc.c:1652  */
    {
			if ((yyvsp[0].v.number) < 1 || (yyvsp[0].v.number) > USHRT_MAX) {
				yyerror("restart out of range. 1 to %u minutes",
				    USHRT_MAX);
				YYERROR;
			}
			(yyval.v.number) = (yyvsp[0].v.number);
		}
#line 3957 "parse.c" /* yacc.c:1652  */
    break;

  case 160:
#line 1673 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = AFI_IPv4; }
#line 3963 "parse.c" /* yacc.c:1652  */
    break;

  case 161:
#line 1674 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = AFI_IPv6; }
#line 3969 "parse.c" /* yacc.c:1652  */
    break;

  case 162:
#line 1677 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = SAFI_NONE; }
#line 3975 "parse.c" /* yacc.c:1652  */
    break;

  case 163:
#line 1678 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = SAFI_UNICAST; }
#line 3981 "parse.c" /* yacc.c:1652  */
    break;

  case 164:
#line 1679 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = SAFI_MPLSVPN; }
#line 3987 "parse.c" /* yacc.c:1652  */
    break;

  case 165:
#line 1682 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 1; }
#line 3993 "parse.c" /* yacc.c:1652  */
    break;

  case 166:
#line 1683 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 3999 "parse.c" /* yacc.c:1652  */
    break;

  case 167:
#line 1686 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 1; }
#line 4005 "parse.c" /* yacc.c:1652  */
    break;

  case 168:
#line 1687 "parse.y" /* yacc.c:1652  */
    { (yyval.v.number) = 0; }
#line 4011 "parse.c" /* yacc.c:1652  */
    break;

  case 169:
#line 1690 "parse.y" /* yacc.c:1652  */
    {
			bzero(&(yyval.v.encspec), sizeof((yyval.v.encspec)));
		}
#line 4019 "parse.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1693 "parse.y" /* yacc.c:1652  */
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
#line 4055 "parse.c" /* yacc.c:1652  */
    break;

  case 171:
#line 1728 "parse.y" /* yacc.c:1652  */
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
#line 4083 "parse.c" /* yacc.c:1652  */
    break;

  case 172:
#line 1753 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = ACTION_ALLOW; }
#line 4089 "parse.c" /* yacc.c:1652  */
    break;

  case 173:
#line 1754 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = ACTION_DENY; }
#line 4095 "parse.c" /* yacc.c:1652  */
    break;

  case 174:
#line 1755 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = ACTION_NONE; }
#line 4101 "parse.c" /* yacc.c:1652  */
    break;

  case 175:
#line 1758 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = 0; }
#line 4107 "parse.c" /* yacc.c:1652  */
    break;

  case 176:
#line 1759 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = 1; }
#line 4113 "parse.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1762 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = DIR_IN; }
#line 4119 "parse.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1763 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = DIR_OUT; }
#line 4125 "parse.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1766 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_rib) = NULL; }
#line 4131 "parse.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1767 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4137 "parse.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1768 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_rib) = (yyvsp[-2].v.filter_rib); }
#line 4143 "parse.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1770 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_rib) = (yyvsp[0].v.filter_rib); }
#line 4149 "parse.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1771 "parse.y" /* yacc.c:1652  */
    {
			(yyvsp[0].v.filter_rib)->next = (yyvsp[-2].v.filter_rib);
			(yyval.v.filter_rib) = (yyvsp[0].v.filter_rib);
		}
#line 4158 "parse.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1777 "parse.y" /* yacc.c:1652  */
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
#line 4183 "parse.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1800 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_peers) = (yyvsp[-2].v.filter_peers); }
#line 4189 "parse.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1803 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_peers) = (yyvsp[0].v.filter_peers); }
#line 4195 "parse.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1804 "parse.y" /* yacc.c:1652  */
    {
			(yyvsp[0].v.filter_peers)->next = (yyvsp[-2].v.filter_peers);
			(yyval.v.filter_peers) = (yyvsp[0].v.filter_peers);
		}
#line 4204 "parse.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1810 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.peerid = (yyval.v.filter_peers)->p.groupid = 0;
			(yyval.v.filter_peers)->next = NULL;
		}
#line 4216 "parse.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1817 "parse.y" /* yacc.c:1652  */
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
#line 4241 "parse.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1837 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.groupid = (yyval.v.filter_peers)->p.peerid = 0;
			(yyval.v.filter_peers)->p.remote_as = (yyvsp[0].v.number);
		}
#line 4253 "parse.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1844 "parse.y" /* yacc.c:1652  */
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
#line 4279 "parse.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1865 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ebgp = 1;
		}
#line 4290 "parse.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1871 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_peers) = calloc(1, sizeof(struct filter_peers_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_peers)->p.ibgp = 1;
		}
#line 4301 "parse.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1879 "parse.y" /* yacc.c:1652  */
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
#line 4321 "parse.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1894 "parse.y" /* yacc.c:1652  */
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
#line 4341 "parse.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1909 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4347 "parse.c" /* yacc.c:1652  */
    break;

  case 198:
#line 1910 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4353 "parse.c" /* yacc.c:1652  */
    break;

  case 200:
#line 1914 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_prefix) = (yyvsp[-1].v.filter_prefix); }
#line 4359 "parse.c" /* yacc.c:1652  */
    break;

  case 201:
#line 1916 "parse.y" /* yacc.c:1652  */
    {
			struct filter_prefix_l  *p;

			/* merge, both can be lists */
			for (p = (yyvsp[-2].v.filter_prefix); p != NULL && p->next != NULL; p = p->next)
				;       /* nothing */
			if (p != NULL)
				p->next = (yyvsp[0].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[-2].v.filter_prefix);
		}
#line 4374 "parse.c" /* yacc.c:1652  */
    break;

  case 202:
#line 1927 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix); }
#line 4380 "parse.c" /* yacc.c:1652  */
    break;

  case 203:
#line 1928 "parse.y" /* yacc.c:1652  */
    {
			(yyvsp[0].v.filter_prefix)->next = (yyvsp[-2].v.filter_prefix);
			(yyval.v.filter_prefix) = (yyvsp[0].v.filter_prefix);
		}
#line 4389 "parse.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1934 "parse.y" /* yacc.c:1652  */
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
#line 4407 "parse.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1950 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4413 "parse.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1954 "parse.y" /* yacc.c:1652  */
    {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4428 "parse.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1966 "parse.y" /* yacc.c:1652  */
    {
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as)->a.type = (yyvsp[-1].v.u8);
		}
#line 4437 "parse.c" /* yacc.c:1652  */
    break;

  case 210:
#line 1970 "parse.y" /* yacc.c:1652  */
    {
			struct filter_as_l	*a;

			(yyval.v.filter_as) = (yyvsp[-1].v.filter_as);
			for (a = (yyval.v.filter_as); a != NULL; a = a->next)
				a->a.type = (yyvsp[-3].v.u8);
		}
#line 4449 "parse.c" /* yacc.c:1652  */
    break;

  case 211:
#line 1977 "parse.y" /* yacc.c:1652  */
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
#line 4475 "parse.c" /* yacc.c:1652  */
    break;

  case 213:
#line 2001 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_as) = (yyvsp[-1].v.filter_as); }
#line 4481 "parse.c" /* yacc.c:1652  */
    break;

  case 214:
#line 2003 "parse.y" /* yacc.c:1652  */
    {
			struct filter_as_l	*a;

			/* merge, both can be lists */
			for (a = (yyvsp[-2].v.filter_as); a != NULL && a->next != NULL; a = a->next)
				;	/* nothing */
			if (a != NULL)
				a->next = (yyvsp[0].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[-2].v.filter_as);
		}
#line 4496 "parse.c" /* yacc.c:1652  */
    break;

  case 216:
#line 2016 "parse.y" /* yacc.c:1652  */
    {
			(yyvsp[0].v.filter_as)->next = (yyvsp[-2].v.filter_as);
			(yyval.v.filter_as) = (yyvsp[0].v.filter_as);
		}
#line 4505 "parse.c" /* yacc.c:1652  */
    break;

  case 217:
#line 2022 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.op = OP_EQ;
		}
#line 4518 "parse.c" /* yacc.c:1652  */
    break;

  case 218:
#line 2030 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.flags = AS_FLAG_NEIGHBORAS;
		}
#line 4529 "parse.c" /* yacc.c:1652  */
    break;

  case 219:
#line 2036 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_as) = calloc(1, sizeof(struct filter_as_l))) ==
			    NULL)
				fatal(NULL);
			(yyval.v.filter_as)->a.op = (yyvsp[-1].v.u8);
			(yyval.v.filter_as)->a.as_min = (yyvsp[0].v.number);
			(yyval.v.filter_as)->a.as_max = (yyvsp[0].v.number);
		}
#line 4542 "parse.c" /* yacc.c:1652  */
    break;

  case 220:
#line 2044 "parse.y" /* yacc.c:1652  */
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
#line 4559 "parse.c" /* yacc.c:1652  */
    break;

  case 221:
#line 2058 "parse.y" /* yacc.c:1652  */
    {
			bzero(&(yyval.v.filter_match), sizeof((yyval.v.filter_match)));
		}
#line 4567 "parse.c" /* yacc.c:1652  */
    break;

  case 222:
#line 2061 "parse.y" /* yacc.c:1652  */
    {
			bzero(&fmopts, sizeof(fmopts));
		}
#line 4575 "parse.c" /* yacc.c:1652  */
    break;

  case 223:
#line 2064 "parse.y" /* yacc.c:1652  */
    {
			memcpy(&(yyval.v.filter_match), &fmopts, sizeof((yyval.v.filter_match)));
		}
#line 4583 "parse.c" /* yacc.c:1652  */
    break;

  case 226:
#line 2073 "parse.y" /* yacc.c:1652  */
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
#line 4601 "parse.c" /* yacc.c:1652  */
    break;

  case 227:
#line 2086 "parse.y" /* yacc.c:1652  */
    {
			if (fmopts.as_l != NULL) {
				yyerror("AS filters already specified");
				YYERROR;
			}
			fmopts.as_l = (yyvsp[0].v.filter_as);
		}
#line 4613 "parse.c" /* yacc.c:1652  */
    break;

  case 228:
#line 2093 "parse.y" /* yacc.c:1652  */
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
#line 4630 "parse.c" /* yacc.c:1652  */
    break;

  case 229:
#line 2105 "parse.y" /* yacc.c:1652  */
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
#line 4647 "parse.c" /* yacc.c:1652  */
    break;

  case 230:
#line 2117 "parse.y" /* yacc.c:1652  */
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
#line 4670 "parse.c" /* yacc.c:1652  */
    break;

  case 231:
#line 2135 "parse.y" /* yacc.c:1652  */
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
#line 4697 "parse.c" /* yacc.c:1652  */
    break;

  case 232:
#line 2157 "parse.y" /* yacc.c:1652  */
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
#line 4721 "parse.c" /* yacc.c:1652  */
    break;

  case 233:
#line 2176 "parse.y" /* yacc.c:1652  */
    {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.addr = (yyvsp[0].v.addr);
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_ADDR;
		}
#line 4734 "parse.c" /* yacc.c:1652  */
    break;

  case 234:
#line 2184 "parse.y" /* yacc.c:1652  */
    {
			if (fmopts.m.nexthop.flags) {
				yyerror("nexthop already specified");
				YYERROR;
			}
			fmopts.m.nexthop.flags = FILTER_NEXTHOP_NEIGHBOR;
		}
#line 4746 "parse.c" /* yacc.c:1652  */
    break;

  case 235:
#line 2191 "parse.y" /* yacc.c:1652  */
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
#line 4800 "parse.c" /* yacc.c:1652  */
    break;

  case 236:
#line 2240 "parse.y" /* yacc.c:1652  */
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
#line 4825 "parse.c" /* yacc.c:1652  */
    break;

  case 237:
#line 2260 "parse.y" /* yacc.c:1652  */
    {
			if (fmopts.m.ovs.is_set) {
				yyerror("ovs filter already specified");
				YYERROR;
			}
			fmopts.m.ovs.validity = (yyvsp[0].v.number);
			fmopts.m.ovs.is_set = 1;
		}
#line 4838 "parse.c" /* yacc.c:1652  */
    break;

  case 238:
#line 2270 "parse.y" /* yacc.c:1652  */
    { bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen))); }
#line 4844 "parse.c" /* yacc.c:1652  */
    break;

  case 239:
#line 2271 "parse.y" /* yacc.c:1652  */
    {
			bzero(&(yyval.v.prefixlen), sizeof((yyval.v.prefixlen)));
			(yyval.v.prefixlen).op = OP_RANGE;
			(yyval.v.prefixlen).len_min = -1;
			(yyval.v.prefixlen).len_max = -1;
		}
#line 4855 "parse.c" /* yacc.c:1652  */
    break;

  case 240:
#line 2277 "parse.y" /* yacc.c:1652  */
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
#line 4871 "parse.c" /* yacc.c:1652  */
    break;

  case 241:
#line 2288 "parse.y" /* yacc.c:1652  */
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
#line 4919 "parse.c" /* yacc.c:1652  */
    break;

  case 242:
#line 2331 "parse.y" /* yacc.c:1652  */
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
#line 4938 "parse.c" /* yacc.c:1652  */
    break;

  case 243:
#line 2347 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = AS_ALL; }
#line 4944 "parse.c" /* yacc.c:1652  */
    break;

  case 244:
#line 2348 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = AS_SOURCE; }
#line 4950 "parse.c" /* yacc.c:1652  */
    break;

  case 245:
#line 2349 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = AS_TRANSIT; }
#line 4956 "parse.c" /* yacc.c:1652  */
    break;

  case 246:
#line 2350 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = AS_PEER; }
#line 4962 "parse.c" /* yacc.c:1652  */
    break;

  case 247:
#line 2353 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_set_head) = NULL; }
#line 4968 "parse.c" /* yacc.c:1652  */
    break;

  case 248:
#line 2354 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 4980 "parse.c" /* yacc.c:1652  */
    break;

  case 249:
#line 2361 "parse.y" /* yacc.c:1652  */
    { (yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head); }
#line 4986 "parse.c" /* yacc.c:1652  */
    break;

  case 250:
#line 2364 "parse.y" /* yacc.c:1652  */
    {
			(yyval.v.filter_set_head) = (yyvsp[-2].v.filter_set_head);
			if (merge_filterset((yyval.v.filter_set_head), (yyvsp[0].v.filter_set)) == 1)
				YYERROR;
		}
#line 4996 "parse.c" /* yacc.c:1652  */
    break;

  case 251:
#line 2369 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set_head) = calloc(1, sizeof(struct filter_set_head))) ==
			    NULL)
				fatal(NULL);
			TAILQ_INIT((yyval.v.filter_set_head));
			TAILQ_INSERT_TAIL((yyval.v.filter_set_head), (yyvsp[0].v.filter_set), entry);
		}
#line 5008 "parse.c" /* yacc.c:1652  */
    break;

  case 252:
#line 2378 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = COMMUNITY_TYPE_BASIC; }
#line 5014 "parse.c" /* yacc.c:1652  */
    break;

  case 253:
#line 2379 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = COMMUNITY_TYPE_LARGE; }
#line 5020 "parse.c" /* yacc.c:1652  */
    break;

  case 254:
#line 2382 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = 0; }
#line 5026 "parse.c" /* yacc.c:1652  */
    break;

  case 255:
#line 2383 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = 1; }
#line 5032 "parse.c" /* yacc.c:1652  */
    break;

  case 256:
#line 2386 "parse.y" /* yacc.c:1652  */
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
#line 5052 "parse.c" /* yacc.c:1652  */
    break;

  case 257:
#line 2401 "parse.y" /* yacc.c:1652  */
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
#line 5067 "parse.c" /* yacc.c:1652  */
    break;

  case 258:
#line 2411 "parse.y" /* yacc.c:1652  */
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
#line 5082 "parse.c" /* yacc.c:1652  */
    break;

  case 259:
#line 2421 "parse.y" /* yacc.c:1652  */
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
#line 5102 "parse.c" /* yacc.c:1652  */
    break;

  case 260:
#line 2436 "parse.y" /* yacc.c:1652  */
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
#line 5117 "parse.c" /* yacc.c:1652  */
    break;

  case 261:
#line 2446 "parse.y" /* yacc.c:1652  */
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
#line 5132 "parse.c" /* yacc.c:1652  */
    break;

  case 262:
#line 2456 "parse.y" /* yacc.c:1652  */
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
#line 5152 "parse.c" /* yacc.c:1652  */
    break;

  case 263:
#line 2471 "parse.y" /* yacc.c:1652  */
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
#line 5167 "parse.c" /* yacc.c:1652  */
    break;

  case 264:
#line 2481 "parse.y" /* yacc.c:1652  */
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
#line 5182 "parse.c" /* yacc.c:1652  */
    break;

  case 265:
#line 2491 "parse.y" /* yacc.c:1652  */
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
#line 5202 "parse.c" /* yacc.c:1652  */
    break;

  case 266:
#line 2506 "parse.y" /* yacc.c:1652  */
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
#line 5217 "parse.c" /* yacc.c:1652  */
    break;

  case 267:
#line 2516 "parse.y" /* yacc.c:1652  */
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
#line 5232 "parse.c" /* yacc.c:1652  */
    break;

  case 268:
#line 2526 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP;
			memcpy(&(yyval.v.filter_set)->action.nexthop, &(yyvsp[0].v.addr),
			    sizeof((yyval.v.filter_set)->action.nexthop));
		}
#line 5244 "parse.c" /* yacc.c:1652  */
    break;

  case 269:
#line 2533 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_BLACKHOLE;
		}
#line 5254 "parse.c" /* yacc.c:1652  */
    break;

  case 270:
#line 2538 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_REJECT;
		}
#line 5264 "parse.c" /* yacc.c:1652  */
    break;

  case 271:
#line 2543 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_NOMODIFY;
		}
#line 5274 "parse.c" /* yacc.c:1652  */
    break;

  case 272:
#line 2548 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_NEXTHOP_SELF;
		}
#line 5284 "parse.c" /* yacc.c:1652  */
    break;

  case 273:
#line 2553 "parse.y" /* yacc.c:1652  */
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
#line 5299 "parse.c" /* yacc.c:1652  */
    break;

  case 274:
#line 2563 "parse.y" /* yacc.c:1652  */
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
#line 5314 "parse.c" /* yacc.c:1652  */
    break;

  case 275:
#line 2573 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_AS_OVERRIDE;
		}
#line 5324 "parse.c" /* yacc.c:1652  */
    break;

  case 276:
#line 2578 "parse.y" /* yacc.c:1652  */
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
#line 5356 "parse.c" /* yacc.c:1652  */
    break;

  case 277:
#line 2605 "parse.y" /* yacc.c:1652  */
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
#line 5375 "parse.c" /* yacc.c:1652  */
    break;

  case 278:
#line 2619 "parse.y" /* yacc.c:1652  */
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
#line 5408 "parse.c" /* yacc.c:1652  */
    break;

  case 279:
#line 2647 "parse.y" /* yacc.c:1652  */
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
#line 5431 "parse.c" /* yacc.c:1652  */
    break;

  case 280:
#line 2665 "parse.y" /* yacc.c:1652  */
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
#line 5452 "parse.c" /* yacc.c:1652  */
    break;

  case 281:
#line 2681 "parse.y" /* yacc.c:1652  */
    {
			if (((yyval.v.filter_set) = calloc(1, sizeof(struct filter_set))) == NULL)
				fatal(NULL);
			(yyval.v.filter_set)->type = ACTION_SET_ORIGIN;
			(yyval.v.filter_set)->action.origin = (yyvsp[0].v.number);
		}
#line 5463 "parse.c" /* yacc.c:1652  */
    break;

  case 282:
#line 2689 "parse.y" /* yacc.c:1652  */
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
#line 5482 "parse.c" /* yacc.c:1652  */
    break;

  case 283:
#line 2704 "parse.y" /* yacc.c:1652  */
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
#line 5501 "parse.c" /* yacc.c:1652  */
    break;

  case 290:
#line 2729 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_EQ; }
#line 5507 "parse.c" /* yacc.c:1652  */
    break;

  case 291:
#line 2730 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_NE; }
#line 5513 "parse.c" /* yacc.c:1652  */
    break;

  case 292:
#line 2731 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_LE; }
#line 5519 "parse.c" /* yacc.c:1652  */
    break;

  case 293:
#line 2732 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_LT; }
#line 5525 "parse.c" /* yacc.c:1652  */
    break;

  case 294:
#line 2733 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_GE; }
#line 5531 "parse.c" /* yacc.c:1652  */
    break;

  case 295:
#line 2734 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_GT; }
#line 5537 "parse.c" /* yacc.c:1652  */
    break;

  case 296:
#line 2737 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_EQ; }
#line 5543 "parse.c" /* yacc.c:1652  */
    break;

  case 297:
#line 2738 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_NE; }
#line 5549 "parse.c" /* yacc.c:1652  */
    break;

  case 298:
#line 2741 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_RANGE; }
#line 5555 "parse.c" /* yacc.c:1652  */
    break;

  case 299:
#line 2742 "parse.y" /* yacc.c:1652  */
    { (yyval.v.u8) = OP_XRANGE; }
#line 5561 "parse.c" /* yacc.c:1652  */
    break;


#line 5565 "parse.c" /* yacc.c:1652  */
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
#line 2745 "parse.y" /* yacc.c:1918  */


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
parse_config(char *filename, struct peer_head *ph)
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
		p->conf.local_as = curgroup->conf.local_as;
		p->conf.local_short_as = curgroup->conf.local_short_as;
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
				if (memcmp(&p->conf.remote_addr,
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
				if (memcmp(&s->action.community,
				    &t->action.community,
				    sizeof(s->action.community)) < 0) {
					TAILQ_INSERT_BEFORE(t, s, entry);
					return;
				} else if (memcmp(&s->action.community,
				    &t->action.community,
				    sizeof(s->action.community)) == 0)
					break;
				continue;
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
		type = "roa-set";
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
	return pset;
}

static void
add_roa_set(struct prefixset_item *npsi, u_int32_t as, u_int8_t max)
{
	struct prefixset_item	*psi;
	struct roa_set rs, *rsp;

	/* no prefixlen option in this tree */
	npsi->p.op = OP_NONE;
	npsi->p.len_max = npsi->p.len_min = npsi->p.len;
	psi = RB_INSERT(prefixset_tree, curpsitree, npsi);
	if (psi == NULL)
		psi = npsi;
	else
		free(npsi);

	if (psi->set == NULL)
		if ((psi->set = set_new(1, sizeof(rs))) == NULL)
			fatal("set_new");

	/* merge sets with same key, longer maxlen wins */
	if ((rsp = set_match(psi->set, as)) != NULL) {
		if (rsp->maxlen < max)
			rsp->maxlen = max;
	} else  {
		rs.as = as;
		rs.maxlen = max;
		if (set_add(psi->set, &rs, 1) != 0)
			fatal("as_set_new");
		/* prep data so that set_match works */
		set_prep(psi->set);
	}
}
