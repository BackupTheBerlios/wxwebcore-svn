/* ANSI-C code produced by gperf version 3.0.1 */
/* Command-line: gperf -a -L ANSI-C -D -E -C -l -o -t -k '*' -NfindTag -Hhash_tag -Wwordlist_tag htmltags.gperf  */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "htmltags.gperf"

/* This file is automatically generated from htmltags.in by maketags, do not edit */
/* Copyright 1999 Lars Knoll */
#include "htmltags.h"
#line 6 "htmltags.gperf"
struct tags {
    const char *name;
    int id;
};
/* maximum key range = 365, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash_tag (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
       60,  55,  50,  45,  40,   5, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366,  15,  10,  35,
       10,   5,  10,  10,  50,  40, 115,  30,   5,  15,
       30,  55,   5,  85,  20,   0,   0,  65,  55,  35,
       95,  70, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366, 366, 366, 366,
      366, 366, 366, 366, 366, 366, 366
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[9]];
      /*FALLTHROUGH*/
      case 9:
        hval += asso_values[(unsigned char)str[8]];
      /*FALLTHROUGH*/
      case 8:
        hval += asso_values[(unsigned char)str[7]];
      /*FALLTHROUGH*/
      case 7:
        hval += asso_values[(unsigned char)str[6]];
      /*FALLTHROUGH*/
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]+1];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

#ifdef __GNUC__
__inline
#endif
const struct tags *
findTag (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 105,
      MIN_WORD_LENGTH = 1,
      MAX_WORD_LENGTH = 10,
      MIN_HASH_VALUE = 1,
      MAX_HASH_VALUE = 365
    };

  static const unsigned char lengthtable[] =
    {
       1,  2,  1,  2,  1,  2,  3,  1,  2,  2,  3,  4,  3,  4,
       5,  2,  4,  5,  1,  2,  4,  3,  4,  5,  2,  3,  4,  2,
       8,  4,  5,  6,  7,  3,  5,  1,  2,  3,  4,  5,  2,  3,
       5,  6,  2,  3,  6,  2,  3,  4,  1,  7,  3,  4,  2,  3,
       2,  3,  4,  2,  5,  6,  2,  8,  6,  2,  5,  6,  2,  4,
       5,  8,  5,  3,  4,  3,  4,  8,  3,  5,  6,  6,  7,  8,
       4,  6,  6,  8,  5,  5,  7,  3,  4,  6,  7,  8,  7,  9,
       7,  7,  6,  6,  6,  8, 10
    };
  static const struct tags wordlist_tag[] =
    {
#line 87 "htmltags.gperf"
      {"s", ID_S},
#line 106 "htmltags.gperf"
      {"tr", ID_TR},
#line 82 "htmltags.gperf"
      {"p", ID_P},
#line 100 "htmltags.gperf"
      {"td", ID_TD},
#line 17 "htmltags.gperf"
      {"b", ID_B},
#line 24 "htmltags.gperf"
      {"br", ID_BR},
#line 85 "htmltags.gperf"
      {"pre", ID_PRE},
#line 11 "htmltags.gperf"
      {"a", ID_A},
#line 33 "htmltags.gperf"
      {"dd", ID_DD},
#line 38 "htmltags.gperf"
      {"dl", ID_DL},
#line 34 "htmltags.gperf"
      {"del", ID_DEL},
#line 18 "htmltags.gperf"
      {"base", ID_BASE},
#line 69 "htmltags.gperf"
      {"map", ID_MAP},
#line 88 "htmltags.gperf"
      {"samp", ID_SAMP},
#line 98 "htmltags.gperf"
      {"table", ID_TABLE},
#line 40 "htmltags.gperf"
      {"em", ID_EM},
#line 16 "htmltags.gperf"
      {"area", ID_AREA},
#line 64 "htmltags.gperf"
      {"label", ID_LABEL},
#line 56 "htmltags.gperf"
      {"i", ID_I},
#line 103 "htmltags.gperf"
      {"th", ID_TH},
#line 72 "htmltags.gperf"
      {"meta", ID_META},
#line 31 "htmltags.gperf"
      {"col", ID_COL},
#line 43 "htmltags.gperf"
      {"font", ID_FONT},
#line 45 "htmltags.gperf"
      {"frame", ID_FRAME},
#line 54 "htmltags.gperf"
      {"hr", ID_HR},
#line 35 "htmltags.gperf"
      {"dfn", ID_DFN},
#line 44 "htmltags.gperf"
      {"form", ID_FORM},
#line 52 "htmltags.gperf"
      {"h6", ID_H6},
#line 46 "htmltags.gperf"
      {"frameset", ID_FRAMESET},
#line 30 "htmltags.gperf"
      {"code", ID_CODE},
#line 91 "htmltags.gperf"
      {"small", ID_SMALL},
#line 90 "htmltags.gperf"
      {"select", ID_SELECT},
#line 14 "htmltags.gperf"
      {"address", ID_ADDRESS},
#line 97 "htmltags.gperf"
      {"sup", ID_SUP},
#line 41 "htmltags.gperf"
      {"embed", ID_EMBED},
#line 108 "htmltags.gperf"
      {"u", ID_U},
#line 107 "htmltags.gperf"
      {"tt", ID_TT},
#line 96 "htmltags.gperf"
      {"sub", ID_SUB},
#line 73 "htmltags.gperf"
      {"nobr", ID_NOBR},
#line 83 "htmltags.gperf"
      {"param", ID_PARAM},
#line 79 "htmltags.gperf"
      {"ol", ID_OL},
#line 20 "htmltags.gperf"
      {"bdo", ID_BDO},
#line 104 "htmltags.gperf"
      {"thead", ID_THEAD},
#line 66 "htmltags.gperf"
      {"legend", ID_LEGEND},
#line 39 "htmltags.gperf"
      {"dt", ID_DT},
#line 62 "htmltags.gperf"
      {"kbd", ID_KBD},
#line 89 "htmltags.gperf"
      {"script", ID_SCRIPT},
#line 109 "htmltags.gperf"
      {"ul", ID_UL},
#line 58 "htmltags.gperf"
      {"img", ID_IMG},
#line 12 "htmltags.gperf"
      {"abbr", ID_ABBR},
#line 86 "htmltags.gperf"
      {"q", ID_Q},
#line 74 "htmltags.gperf"
      {"noembed", ID_NOEMBED},
#line 110 "htmltags.gperf"
      {"var", ID_VAR},
#line 53 "htmltags.gperf"
      {"head", ID_HEAD},
#line 51 "htmltags.gperf"
      {"h5", ID_H5},
#line 111 "htmltags.gperf"
      {"wbr", ID_WBR},
#line 50 "htmltags.gperf"
      {"h4", ID_H4},
#line 60 "htmltags.gperf"
      {"ins", ID_INS},
#line 23 "htmltags.gperf"
      {"body", ID_BODY},
#line 49 "htmltags.gperf"
      {"h3", ID_H3},
#line 114 "htmltags.gperf"
      {"image", ID_IMG},
#line 28 "htmltags.gperf"
      {"center", ID_CENTER},
#line 48 "htmltags.gperf"
      {"h2", ID_H2},
#line 75 "htmltags.gperf"
      {"noframes", ID_NOFRAMES},
#line 57 "htmltags.gperf"
      {"iframe", ID_IFRAME},
#line 47 "htmltags.gperf"
      {"h1", ID_H1},
#line 65 "htmltags.gperf"
      {"layer", ID_LAYER},
#line 15 "htmltags.gperf"
      {"applet", ID_APPLET},
#line 67 "htmltags.gperf"
      {"li", ID_LI},
#line 71 "htmltags.gperf"
      {"menu", ID_MENU},
#line 102 "htmltags.gperf"
      {"tfoot", ID_TFOOT},
#line 19 "htmltags.gperf"
      {"basefont", ID_BASEFONT},
#line 105 "htmltags.gperf"
      {"title", ID_TITLE},
#line 112 "htmltags.gperf"
      {"xmp", ID_XMP},
#line 92 "htmltags.gperf"
      {"span", ID_SPAN},
#line 21 "htmltags.gperf"
      {"big", ID_BIG},
#line 55 "htmltags.gperf"
      {"html", ID_HTML},
#line 76 "htmltags.gperf"
      {"noscript", ID_NOSCRIPT},
#line 36 "htmltags.gperf"
      {"dir", ID_DIR},
#line 95 "htmltags.gperf"
      {"style", ID_STYLE},
#line 26 "htmltags.gperf"
      {"canvas", ID_CANVAS},
#line 25 "htmltags.gperf"
      {"button", ID_BUTTON},
#line 77 "htmltags.gperf"
      {"nolayer", ID_NOLAYER},
#line 42 "htmltags.gperf"
      {"fieldset", ID_FIELDSET},
#line 29 "htmltags.gperf"
      {"cite", ID_CITE},
#line 63 "htmltags.gperf"
      {"keygen", ID_KEYGEN},
#line 93 "htmltags.gperf"
      {"strike", ID_STRIKE},
#line 101 "htmltags.gperf"
      {"textarea", ID_TEXTAREA},
#line 59 "htmltags.gperf"
      {"input", ID_INPUT},
#line 99 "htmltags.gperf"
      {"tbody", ID_TBODY},
#line 27 "htmltags.gperf"
      {"caption", ID_CAPTION},
#line 37 "htmltags.gperf"
      {"div", ID_DIV},
#line 68 "htmltags.gperf"
      {"link", ID_LINK},
#line 94 "htmltags.gperf"
      {"strong", ID_STRONG},
#line 115 "htmltags.gperf"
      {"listing", ID_PRE},
#line 32 "htmltags.gperf"
      {"colgroup", ID_COLGROUP},
#line 70 "htmltags.gperf"
      {"marquee", ID_MARQUEE},
#line 84 "htmltags.gperf"
      {"plaintext", ID_PLAINTEXT},
#line 13 "htmltags.gperf"
      {"acronym", ID_ACRONYM},
#line 61 "htmltags.gperf"
      {"isindex", ID_ISINDEX},
#line 113 "htmltags.gperf"
      {"anchor", ID_A},
#line 78 "htmltags.gperf"
      {"object", ID_OBJECT},
#line 81 "htmltags.gperf"
      {"option", ID_OPTION},
#line 80 "htmltags.gperf"
      {"optgroup", ID_OPTGROUP},
#line 22 "htmltags.gperf"
      {"blockquote", ID_BLOCKQUOTE}
    };

  static const signed char lookup[] =
    {
       -1,   0,   1,  -1,  -1,  -1,   2,   3,  -1,  -1,
       -1,   4,   5,   6,  -1,  -1,   7,   8,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,   9,  10,  11,
       -1,  -1,  -1,  12,  13,  14,  -1,  15,  -1,  16,
       17,  18,  19,  -1,  20,  -1,  -1,  -1,  21,  22,
       23,  -1,  24,  25,  26,  -1,  -1,  27,  28,  29,
       30,  31,  32,  33,  -1,  34,  35,  36,  37,  38,
       39,  -1,  40,  41,  -1,  42,  43,  44,  45,  -1,
       -1,  46,  47,  48,  49,  -1,  50,  51,  52,  53,
       -1,  -1,  54,  55,  -1,  -1,  -1,  56,  57,  58,
       -1,  -1,  59,  -1,  -1,  60,  61,  62,  63,  -1,
       -1,  64,  65,  -1,  -1,  66,  -1,  -1,  -1,  -1,
       -1,  67,  68,  -1,  69,  70,  -1,  -1,  71,  -1,
       72,  -1,  -1,  73,  74,  -1,  -1,  -1,  75,  76,
       -1,  -1,  -1,  77,  -1,  -1,  -1,  -1,  78,  -1,
       79,  80,  -1,  -1,  -1,  -1,  81,  82,  83,  84,
       -1,  85,  -1,  -1,  -1,  -1,  86,  -1,  87,  -1,
       88,  -1,  -1,  -1,  -1,  89,  -1,  -1,  -1,  -1,
       -1,  -1,  90,  91,  92,  -1,  93,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  94,  95,  -1,
       -1,  -1,  96,  -1,  97,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  98,  -1,  -1,  -1,  -1,  99,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 100,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 101,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 102,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 103,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 104
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash_tag (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              if (len == lengthtable[index])
                {
                  register const char *s = wordlist_tag[index].name;

                  if (*str == *s && !memcmp (str + 1, s + 1, len - 1))
                    return &wordlist_tag[index];
                }
            }
        }
    }
  return 0;
}
#line 116 "htmltags.gperf"

#line 426 "htmltags.c"

using DOM::DOMString;

static const char * const openTagNames[] = {
    0,
    "A",
    "ABBR",
    "ACRONYM",
    "ADDRESS",
    "APPLET",
    "AREA",
    "B",
    "BASE",
    "BASEFONT",
    "BDO",
    "BIG",
    "BLOCKQUOTE",
    "BODY",
    "BR",
    "BUTTON",
    "CANVAS",
    "CAPTION",
    "CENTER",
    "CITE",
    "CODE",
    "COL",
    "COLGROUP",
    "DD",
    "DEL",
    "DFN",
    "DIR",
    "DIV",
    "DL",
    "DT",
    "EM",
    "EMBED",
    "FIELDSET",
    "FONT",
    "FORM",
    "FRAME",
    "FRAMESET",
    "H1",
    "H2",
    "H3",
    "H4",
    "H5",
    "H6",
    "HEAD",
    "HR",
    "HTML",
    "I",
    "IFRAME",
    "IMG",
    "INPUT",
    "INS",
    "ISINDEX",
    "KBD",
    "KEYGEN",
    "LABEL",
    "LAYER",
    "LEGEND",
    "LI",
    "LINK",
    "MAP",
    "MARQUEE",
    "MENU",
    "META",
    "NOBR",
    "NOEMBED",
    "NOFRAMES",
    "NOSCRIPT",
    "NOLAYER",
    "OBJECT",
    "OL",
    "OPTGROUP",
    "OPTION",
    "P",
    "PARAM",
    "PLAINTEXT",
    "PRE",
    "Q",
    "S",
    "SAMP",
    "SCRIPT",
    "SELECT",
    "SMALL",
    "SPAN",
    "STRIKE",
    "STRONG",
    "STYLE",
    "SUB",
    "SUP",
    "TABLE",
    "TBODY",
    "TD",
    "TEXTAREA",
    "TFOOT",
    "TH",
    "THEAD",
    "TITLE",
    "TR",
    "TT",
    "U",
    "UL",
    "VAR",
    "WBR",
    "XMP",
    "TEXT",
    "COMMENT"
};

static const char * const closeTagNames[] = {
    0,
    "/A",
    "/ABBR",
    "/ACRONYM",
    "/ADDRESS",
    "/APPLET",
    "/AREA",
    "/B",
    "/BASE",
    "/BASEFONT",
    "/BDO",
    "/BIG",
    "/BLOCKQUOTE",
    "/BODY",
    "/BR",
    "/BUTTON",
    "/CANVAS",
    "/CAPTION",
    "/CENTER",
    "/CITE",
    "/CODE",
    "/COL",
    "/COLGROUP",
    "/DD",
    "/DEL",
    "/DFN",
    "/DIR",
    "/DIV",
    "/DL",
    "/DT",
    "/EM",
    "/EMBED",
    "/FIELDSET",
    "/FONT",
    "/FORM",
    "/FRAME",
    "/FRAMESET",
    "/H1",
    "/H2",
    "/H3",
    "/H4",
    "/H5",
    "/H6",
    "/HEAD",
    "/HR",
    "/HTML",
    "/I",
    "/IFRAME",
    "/IMG",
    "/INPUT",
    "/INS",
    "/ISINDEX",
    "/KBD",
    "/KEYGEN",
    "/LABEL",
    "/LAYER",
    "/LEGEND",
    "/LI",
    "/LINK",
    "/MAP",
    "/MARQUEE",
    "/MENU",
    "/META",
    "/NOBR",
    "/NOEMBED",
    "/NOFRAMES",
    "/NOSCRIPT",
    "/NOLAYER",
    "/OBJECT",
    "/OL",
    "/OPTGROUP",
    "/OPTION",
    "/P",
    "/PARAM",
    "/PLAINTEXT",
    "/PRE",
    "/Q",
    "/S",
    "/SAMP",
    "/SCRIPT",
    "/SELECT",
    "/SMALL",
    "/SPAN",
    "/STRIKE",
    "/STRONG",
    "/STYLE",
    "/SUB",
    "/SUP",
    "/TABLE",
    "/TBODY",
    "/TD",
    "/TEXTAREA",
    "/TFOOT",
    "/TH",
    "/THEAD",
    "/TITLE",
    "/TR",
    "/TT",
    "/U",
    "/UL",
    "/VAR",
    "/WBR",
    "/XMP",
};

DOMString getTagName(unsigned short id)
{
    if (id > ID_CLOSE_TAG) {
        int index = id - ID_CLOSE_TAG;
        if (index >= ID_TEXT)
            return DOMString();
        return closeTagNames[index];
    }
    if (id > ID_LAST_TAG)
        return DOMString();
    return openTagNames[id];
}
