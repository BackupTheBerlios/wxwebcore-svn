/* ANSI-C code produced by gperf version 3.0.1 */
/* Command-line: gperf -c -a -L ANSI-C -D -E -C -o -t -k '*' -NfindAttr -Hhash_attr -Wwordlist_attr -s 2 htmlattrs.gperf  */

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

#line 1 "htmlattrs.gperf"

/* This file is automatically generated from
#htmlattrs.in by makeattrs, do not edit */
/* Copyright 1999 Lars Knoll */
#include "htmlattrs.h"
#line 7 "htmlattrs.gperf"
struct attrs {
    const char *name;
    int id;
};
/* maximum key range = 705, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash_attr (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708,  10,  10, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708,  10,  25,   5,
        0,   5,  60,  40, 140,  30, 135, 210,  15,  35,
       90,   0,   0,   0,   0,   0,   0,  85, 150, 225,
       70,  10,  20, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708, 708, 708, 708,
      708, 708, 708, 708, 708, 708, 708
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[14]];
      /*FALLTHROUGH*/
      case 14:
        hval += asso_values[(unsigned char)str[13]];
      /*FALLTHROUGH*/
      case 13:
        hval += asso_values[(unsigned char)str[12]];
      /*FALLTHROUGH*/
      case 12:
        hval += asso_values[(unsigned char)str[11]];
      /*FALLTHROUGH*/
      case 11:
        hval += asso_values[(unsigned char)str[10]];
      /*FALLTHROUGH*/
      case 10:
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
const struct attrs *
findAttr (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 182,
      MIN_WORD_LENGTH = 2,
      MAX_WORD_LENGTH = 15,
      MIN_HASH_VALUE = 3,
      MAX_HASH_VALUE = 707
    };

  static const struct attrs wordlist_attr[] =
    {
#line 178 "htmlattrs.gperf"
      {"top", ATTR_TOP},
#line 118 "htmlattrs.gperf"
      {"ondrop", ATTR_ONDROP},
#line 168 "htmlattrs.gperf"
      {"src", ATTR_SRC},
#line 160 "htmlattrs.gperf"
      {"scope", ATTR_SCOPE},
#line 52 "htmlattrs.gperf"
      {"coords", ATTR_COORDS},
#line 119 "htmlattrs.gperf"
      {"onerror", ATTR_ONERROR},
#line 42 "htmlattrs.gperf"
      {"code", ATTR_CODE},
#line 133 "htmlattrs.gperf"
      {"onreset", ATTR_ONRESET},
#line 84 "htmlattrs.gperf"
      {"loop", ATTR_LOOP},
#line 109 "htmlattrs.gperf"
      {"oncopy", ATTR_ONCOPY},
#line 132 "htmlattrs.gperf"
      {"onpaste", ATTR_ONPASTE},
#line 46 "htmlattrs.gperf"
      {"cols", ATTR_COLS},
#line 45 "htmlattrs.gperf"
      {"color", ATTR_COLOR},
#line 14 "htmlattrs.gperf"
      {"accept", ATTR_ACCEPT},
#line 181 "htmlattrs.gperf"
      {"type", ATTR_TYPE},
#line 125 "htmlattrs.gperf"
      {"onload", ATTR_ONLOAD},
#line 60 "htmlattrs.gperf"
      {"enctype", ATTR_ENCTYPE},
#line 44 "htmlattrs.gperf"
      {"codetype", ATTR_CODETYPE},
#line 28 "htmlattrs.gperf"
      {"border", ATTR_BORDER},
#line 73 "htmlattrs.gperf"
      {"id", ATTR_ID},
#line 137 "htmlattrs.gperf"
      {"onselect", ATTR_ONSELECT},
#line 53 "htmlattrs.gperf"
      {"data", ATTR_DATA},
#line 151 "htmlattrs.gperf"
      {"prompt", ATTR_PROMPT},
#line 101 "htmlattrs.gperf"
      {"onabort", ATTR_ONABORT},
#line 135 "htmlattrs.gperf"
      {"onscroll", ATTR_ONSCROLL},
#line 12 "htmlattrs.gperf"
      {"abbr", ATTR_ABBR},
#line 19 "htmlattrs.gperf"
      {"alt", ATTR_ALT},
#line 32 "htmlattrs.gperf"
      {"char", ATTR_CHAR},
#line 165 "htmlattrs.gperf"
      {"shape", ATTR_SHAPE},
#line 138 "htmlattrs.gperf"
      {"onselectstart", ATTR_ONSELECTSTART},
#line 23 "htmlattrs.gperf"
      {"axis", ATTR_AXIS},
#line 39 "htmlattrs.gperf"
      {"class", ATTR_CLASS},
#line 112 "htmlattrs.gperf"
      {"ondrag", ATTR_ONDRAG},
#line 35 "htmlattrs.gperf"
      {"charset", ATTR_CHARSET},
#line 43 "htmlattrs.gperf"
      {"codebase", ATTR_CODEBASE},
#line 41 "htmlattrs.gperf"
      {"clear", ATTR_CLEAR},
#line 29 "htmlattrs.gperf"
      {"bordercolor", ATTR_BORDERCOLOR},
#line 48 "htmlattrs.gperf"
      {"compact", ATTR_COMPACT},
#line 62 "htmlattrs.gperf"
      {"for", ATTR_FOR},
#line 134 "htmlattrs.gperf"
      {"onresize", ATTR_ONRESIZE},
#line 117 "htmlattrs.gperf"
      {"ondragstart", ATTR_ONDRAGSTART},
#line 175 "htmlattrs.gperf"
      {"target", ATTR_TARGET},
#line 153 "htmlattrs.gperf"
      {"rel", ATTR_REL},
#line 75 "htmlattrs.gperf"
      {"ismap", ATTR_ISMAP},
#line 162 "htmlattrs.gperf"
      {"scrolldelay", ATTR_SCROLLDELAY},
#line 49 "htmlattrs.gperf"
      {"composite", ATTR_COMPOSITE},
#line 143 "htmlattrs.gperf"
      {"pagey", ATTR_PAGEY},
#line 40 "htmlattrs.gperf"
      {"classid", ATTR_CLASSID},
#line 77 "htmlattrs.gperf"
      {"label", ATTR_LABEL},
#line 110 "htmlattrs.gperf"
      {"oncut", ATTR_ONCUT},
#line 164 "htmlattrs.gperf"
      {"selected", ATTR_SELECTED},
#line 61 "htmlattrs.gperf"
      {"face", ATTR_FACE},
#line 170 "htmlattrs.gperf"
      {"start", ATTR_START},
#line 55 "htmlattrs.gperf"
      {"declare", ATTR_DECLARE},
#line 167 "htmlattrs.gperf"
      {"span", ATTR_SPAN},
#line 54 "htmlattrs.gperf"
      {"datetime", ATTR_DATETIME},
#line 180 "htmlattrs.gperf"
      {"truespeed", ATTR_TRUESPEED},
#line 174 "htmlattrs.gperf"
      {"tableborder", ATTR_TABLEBORDER},
#line 89 "htmlattrs.gperf"
      {"mayscript", ATTR_MAYSCRIPT},
#line 63 "htmlattrs.gperf"
      {"frame", ATTR_FRAME},
#line 150 "htmlattrs.gperf"
      {"profile", ATTR_PROFILE},
#line 171 "htmlattrs.gperf"
      {"style", ATTR_STYLE},
#line 102 "htmlattrs.gperf"
      {"onbeforecopy", ATTR_ONBEFORECOPY},
#line 104 "htmlattrs.gperf"
      {"onbeforepaste", ATTR_ONBEFOREPASTE},
#line 47 "htmlattrs.gperf"
      {"colspan", ATTR_COLSPAN},
#line 56 "htmlattrs.gperf"
      {"defer", ATTR_DEFER},
#line 105 "htmlattrs.gperf"
      {"onblur", ATTR_ONBLUR},
#line 87 "htmlattrs.gperf"
      {"max", ATTR_MAX},
#line 176 "htmlattrs.gperf"
      {"text", ATTR_TEXT},
#line 37 "htmlattrs.gperf"
      {"cellborder", ATTR_CELLBORDER},
#line 16 "htmlattrs.gperf"
      {"action", ATTR_ACTION},
#line 57 "htmlattrs.gperf"
      {"dir", ATTR_DIR},
#line 80 "htmlattrs.gperf"
      {"left", ATTR_LEFT},
#line 90 "htmlattrs.gperf"
      {"media", ATTR_MEDIA},
#line 183 "htmlattrs.gperf"
      {"usemap", ATTR_USEMAP},
#line 142 "htmlattrs.gperf"
      {"pagex", ATTR_PAGEX},
#line 38 "htmlattrs.gperf"
      {"cite", ATTR_CITE},
#line 64 "htmlattrs.gperf"
      {"frameborder", ATTR_FRAMEBORDER},
#line 113 "htmlattrs.gperf"
      {"ondragend", ATTR_ONDRAGEND},
#line 100 "htmlattrs.gperf"
      {"object", ATTR_OBJECT},
#line 120 "htmlattrs.gperf"
      {"onfocus", ATTR_ONFOCUS},
#line 96 "htmlattrs.gperf"
      {"noresize", ATTR_NORESIZE},
#line 94 "htmlattrs.gperf"
      {"name", ATTR_NAME},
#line 177 "htmlattrs.gperf"
      {"title", ATTR_TITLE},
#line 114 "htmlattrs.gperf"
      {"ondragenter", ATTR_ONDRAGENTER},
#line 83 "htmlattrs.gperf"
      {"longdesc", ATTR_LONGDESC},
#line 166 "htmlattrs.gperf"
      {"size", ATTR_SIZE},
#line 70 "htmlattrs.gperf"
      {"hspace", ATTR_HSPACE},
#line 154 "htmlattrs.gperf"
      {"results", ATTR_RESULTS},
#line 136 "htmlattrs.gperf"
      {"onsearch", ATTR_ONSEARCH},
#line 149 "htmlattrs.gperf"
      {"precision", ATTR_PRECISION},
#line 145 "htmlattrs.gperf"
      {"plain", ATTR_PLAIN},
#line 34 "htmlattrs.gperf"
      {"charoff", ATTR_CHAROFF},
#line 78 "htmlattrs.gperf"
      {"lang", ATTR_LANG},
#line 158 "htmlattrs.gperf"
      {"rules", ATTR_RULES},
#line 190 "htmlattrs.gperf"
      {"vspace", ATTR_VSPACE},
#line 139 "htmlattrs.gperf"
      {"onsubmit", ATTR_ONSUBMIT},
#line 159 "htmlattrs.gperf"
      {"scheme", ATTR_SCHEME},
#line 26 "htmlattrs.gperf"
      {"bgcolor", ATTR_BGCOLOR},
#line 152 "htmlattrs.gperf"
      {"readonly", ATTR_READONLY},
#line 103 "htmlattrs.gperf"
      {"onbeforecut", ATTR_ONBEFORECUT},
#line 50 "htmlattrs.gperf"
      {"content", ATTR_CONTENT},
#line 59 "htmlattrs.gperf"
      {"disabled", ATTR_DISABLED},
#line 163 "htmlattrs.gperf"
      {"scrolling", ATTR_SCROLLING},
#line 13 "htmlattrs.gperf"
      {"accept-charset", ATTR_ACCEPT_CHARSET},
#line 74 "htmlattrs.gperf"
      {"incremental", ATTR_INCREMENTAL},
#line 140 "htmlattrs.gperf"
      {"onunload", ATTR_ONUNLOAD},
#line 68 "htmlattrs.gperf"
      {"href", ATTR_HREF},
#line 17 "htmlattrs.gperf"
      {"align", ATTR_ALIGN},
#line 121 "htmlattrs.gperf"
      {"oninput", ATTR_ONINPUT},
#line 155 "htmlattrs.gperf"
      {"rev", ATTR_REV},
#line 179 "htmlattrs.gperf"
      {"topmargin", ATTR_TOPMARGIN},
#line 116 "htmlattrs.gperf"
      {"ondragover", ATTR_ONDRAGOVER},
#line 27 "htmlattrs.gperf"
      {"bgproperties", ATTR_BGPROPERTIES},
#line 130 "htmlattrs.gperf"
      {"onmouseup", ATTR_ONMOUSEUP},
#line 128 "htmlattrs.gperf"
      {"onmouseout", ATTR_ONMOUSEOUT},
#line 65 "htmlattrs.gperf"
      {"headers", ATTR_HEADERS},
#line 33 "htmlattrs.gperf"
      {"challenge", ATTR_CHALLENGE},
#line 144 "htmlattrs.gperf"
      {"placeholder", ATTR_PLACEHOLDER},
#line 169 "htmlattrs.gperf"
      {"standby", ATTR_STANDBY},
#line 156 "htmlattrs.gperf"
      {"rows", ATTR_ROWS},
#line 193 "htmlattrs.gperf"
      {"z-index", ATTR_Z_INDEX},
#line 21 "htmlattrs.gperf"
      {"autocomplete", ATTR_AUTOCOMPLETE},
#line 192 "htmlattrs.gperf"
      {"wrap", ATTR_WRAP},
#line 123 "htmlattrs.gperf"
      {"onkeypress", ATTR_ONKEYPRESS},
#line 91 "htmlattrs.gperf"
      {"method", ATTR_METHOD},
#line 141 "htmlattrs.gperf"
      {"oversrc", ATTR_OVERSRC},
#line 115 "htmlattrs.gperf"
      {"ondragleave", ATTR_ONDRAGLEAVE},
#line 172 "htmlattrs.gperf"
      {"summary", ATTR_SUMMARY},
#line 98 "htmlattrs.gperf"
      {"noshade", ATTR_NOSHADE},
#line 173 "htmlattrs.gperf"
      {"tabindex", ATTR_TABINDEX},
#line 15 "htmlattrs.gperf"
      {"accesskey", ATTR_ACCESSKEY},
#line 93 "htmlattrs.gperf"
      {"multiple", ATTR_MULTIPLE},
#line 97 "htmlattrs.gperf"
      {"nosave", ATTR_NOSAVE},
#line 161 "htmlattrs.gperf"
      {"scrollamount", ATTR_SCROLLAMOUNT},
#line 92 "htmlattrs.gperf"
      {"min", ATTR_MIN},
#line 36 "htmlattrs.gperf"
      {"checked", ATTR_CHECKED},
#line 107 "htmlattrs.gperf"
      {"onclick", ATTR_ONCLICK},
#line 58 "htmlattrs.gperf"
      {"direction", ATTR_DIRECTION},
#line 30 "htmlattrs.gperf"
      {"cellpadding", ATTR_CELLPADDING},
#line 71 "htmlattrs.gperf"
      {"html", ATTR_HTML},
#line 31 "htmlattrs.gperf"
      {"cellspacing", ATTR_CELLSPACING},
#line 185 "htmlattrs.gperf"
      {"value", ATTR_VALUE},
#line 129 "htmlattrs.gperf"
      {"onmouseover", ATTR_ONMOUSEOVER},
#line 51 "htmlattrs.gperf"
      {"contenteditable", ATTR_CONTENTEDITABLE},
#line 106 "htmlattrs.gperf"
      {"onchange", ATTR_ONCHANGE},
#line 95 "htmlattrs.gperf"
      {"nohref", ATTR_NOHREF},
#line 76 "htmlattrs.gperf"
      {"keytype", ATTR_KEYTYPE},
#line 186 "htmlattrs.gperf"
      {"valuetype", ATTR_VALUETYPE},
#line 111 "htmlattrs.gperf"
      {"ondblclick", ATTR_ONDBLCLICK},
#line 124 "htmlattrs.gperf"
      {"onkeyup", ATTR_ONKEYUP},
#line 79 "htmlattrs.gperf"
      {"language", ATTR_LANGUAGE},
#line 127 "htmlattrs.gperf"
      {"onmousemove", ATTR_ONMOUSEMOVE},
#line 99 "htmlattrs.gperf"
      {"nowrap", ATTR_NOWRAP},
#line 157 "htmlattrs.gperf"
      {"rowspan", ATTR_ROWSPAN},
#line 22 "htmlattrs.gperf"
      {"autosave", ATTR_AUTOSAVE},
#line 187 "htmlattrs.gperf"
      {"version", ATTR_VERSION},
#line 146 "htmlattrs.gperf"
      {"pluginpage", ATTR_PLUGINPAGE},
#line 147 "htmlattrs.gperf"
      {"pluginspage", ATTR_PLUGINSPAGE},
#line 20 "htmlattrs.gperf"
      {"archive", ATTR_ARCHIVE},
#line 81 "htmlattrs.gperf"
      {"leftmargin", ATTR_LEFTMARGIN},
#line 184 "htmlattrs.gperf"
      {"valign", ATTR_VALIGN},
#line 69 "htmlattrs.gperf"
      {"hreflang", ATTR_HREFLANG},
#line 67 "htmlattrs.gperf"
      {"hidden", ATTR_HIDDEN},
#line 18 "htmlattrs.gperf"
      {"alink", ATTR_ALINK},
#line 148 "htmlattrs.gperf"
      {"pluginurl", ATTR_PLUGINURL},
#line 108 "htmlattrs.gperf"
      {"oncontextmenu", ATTR_ONCONTEXTMENU},
#line 66 "htmlattrs.gperf"
      {"height", ATTR_HEIGHT},
#line 25 "htmlattrs.gperf"
      {"behavior", ATTR_BEHAVIOR},
#line 88 "htmlattrs.gperf"
      {"maxlength", ATTR_MAXLENGTH},
#line 188 "htmlattrs.gperf"
      {"visibility", ATTR_VISIBILITY},
#line 126 "htmlattrs.gperf"
      {"onmousedown", ATTR_ONMOUSEDOWN},
#line 82 "htmlattrs.gperf"
      {"link", ATTR_LINK},
#line 24 "htmlattrs.gperf"
      {"background", ATTR_BACKGROUND},
#line 191 "htmlattrs.gperf"
      {"width", ATTR_WIDTH},
#line 72 "htmlattrs.gperf"
      {"http-equiv", ATTR_HTTP_EQUIV},
#line 189 "htmlattrs.gperf"
      {"vlink", ATTR_VLINK},
#line 131 "htmlattrs.gperf"
      {"onmousewheel", ATTR_ONMOUSEWHEEL},
#line 122 "htmlattrs.gperf"
      {"onkeydown", ATTR_ONKEYDOWN},
#line 85 "htmlattrs.gperf"
      {"marginheight", ATTR_MARGINHEIGHT},
#line 86 "htmlattrs.gperf"
      {"marginwidth", ATTR_MARGINWIDTH},
#line 182 "htmlattrs.gperf"
      {"unknown", ATTR_UNKNOWN}
    };

  static const short lookup[] =
    {
       -1,  -1,  -1,   0,  -1,  -1,   1,  -1,   2,  -1,
        3,   4,   5,  -1,   6,  -1,  -1,   7,  -1,   8,
       -1,   9,  10,  -1,  11,  12,  13,  -1,  -1,  14,
       -1,  15,  16,  17,  -1,  -1,  18,  19,  20,  21,
       -1,  22,  23,  24,  25,  -1,  -1,  -1,  26,  27,
       28,  -1,  -1,  29,  30,  31,  32,  33,  34,  -1,
       35,  36,  37,  38,  -1,  -1,  -1,  -1,  39,  -1,
       -1,  40,  -1,  -1,  -1,  -1,  41,  -1,  42,  -1,
       43,  44,  -1,  -1,  45,  46,  -1,  47,  -1,  -1,
       48,  -1,  -1,  -1,  -1,  49,  -1,  -1,  50,  51,
       52,  -1,  53,  -1,  54,  -1,  -1,  -1,  55,  56,
       -1,  57,  -1,  -1,  58,  59,  -1,  60,  -1,  -1,
       61,  -1,  62,  63,  -1,  -1,  -1,  64,  -1,  -1,
       65,  66,  -1,  67,  68,  69,  70,  -1,  71,  72,
       73,  74,  -1,  -1,  -1,  75,  -1,  -1,  -1,  76,
       -1,  77,  -1,  -1,  78,  -1,  79,  80,  81,  82,
       83,  84,  -1,  85,  86,  -1,  87,  88,  89,  90,
       91,  -1,  92,  -1,  93,  94,  95,  -1,  -1,  -1,
       -1,  -1,  -1,  96,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  97,  98,  99,  -1,  -1, 100, 101, 102, 103,
       -1,  -1,  -1,  -1, 104,  -1, 105,  -1, 106, 107,
      108,  -1, 109, 110, 111, 112,  -1, 113,  -1, 114,
      115,  -1, 116,  -1, 117,  -1, 118, 119,  -1, 120,
       -1,  -1, 121,  -1,  -1,  -1,  -1, 122,  -1, 123,
      124, 125, 126,  -1,  -1,  -1, 127, 128,  -1,  -1,
       -1,  -1, 129, 130, 131,  -1,  -1,  -1, 132,  -1,
       -1, 133, 134, 135,  -1,  -1,  -1, 136,  -1,  -1,
       -1,  -1, 137,  -1, 138,  -1, 139,  -1,  -1, 140,
       -1, 141,  -1,  -1,  -1, 142,  -1,  -1,  -1,  -1,
       -1, 143,  -1,  -1,  -1, 144,  -1,  -1, 145,  -1,
       -1, 146, 147,  -1, 148,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 149,  -1, 150, 151,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 152,  -1,  -1,  -1,
       -1, 153, 154, 155,  -1,  -1,  -1, 156,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 157, 158, 159,  -1,  -1,
      160,  -1,  -1,  -1,  -1,  -1, 161,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 162,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 163,  -1,  -1,  -1,
      164,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 165,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 166,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 167,  -1,  -1,  -1,
       -1,  -1,  -1, 168,  -1,  -1,  -1,  -1,  -1, 169,
       -1,  -1,  -1,  -1,  -1, 170,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 171,  -1,  -1, 172,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      173,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 174,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 175,  -1,  -1,  -1,  -1,
      176,  -1,  -1,  -1,  -1,  -1,  -1, 177,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 178,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 179,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 180,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 181
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash_attr (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist_attr[index].name;

              if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
                return &wordlist_attr[index];
            }
        }
    }
  return 0;
}
#line 194 "htmlattrs.gperf"



static const char * const attrList[] = {
    "ABBR",
    "ACCEPT-CHARSET",
    "ACCEPT",
    "ACCESSKEY",
    "ACTION",
    "ALIGN",
    "ALINK",
    "ALT",
    "ARCHIVE",
    "AUTOCOMPLETE",
    "AUTOSAVE",
    "AXIS",
    "BACKGROUND",
    "BEHAVIOR",
    "BGCOLOR",
    "BGPROPERTIES",
    "BORDER",
    "BORDERCOLOR",
    "CELLPADDING",
    "CELLSPACING",
    "CHAR",
    "CHALLENGE",
    "CHAROFF",
    "CHARSET",
    "CHECKED",
    "CELLBORDER",
    "CITE",
    "CLASS",
    "CLASSID",
    "CLEAR",
    "CODE",
    "CODEBASE",
    "CODETYPE",
    "COLOR",
    "COLS",
    "COLSPAN",
    "COMPACT",
    "COMPOSITE",
    "CONTENT",
    "CONTENTEDITABLE",
    "COORDS",
    "DATA",
    "DATETIME",
    "DECLARE",
    "DEFER",
    "DIR",
    "DIRECTION",
    "DISABLED",
    "ENCTYPE",
    "FACE",
    "FOR",
    "FRAME",
    "FRAMEBORDER",
    "HEADERS",
    "HEIGHT",
    "HIDDEN",
    "HREF",
    "HREFLANG",
    "HSPACE",
    "HTML",
    "HTTP-EQUIV",
    "ID",
    "INCREMENTAL",
    "ISMAP",
    "KEYTYPE",
    "LABEL",
    "LANG",
    "LANGUAGE",
    "LEFT",
    "LEFTMARGIN",
    "LINK",
    "LONGDESC",
    "LOOP",
    "MARGINHEIGHT",
    "MARGINWIDTH",
    "MAX",
    "MAXLENGTH",
    "MAYSCRIPT",
    "MEDIA",
    "METHOD",
    "MIN",
    "MULTIPLE",
    "NAME",
    "NOHREF",
    "NORESIZE",
    "NOSAVE",
    "NOSHADE",
    "NOWRAP",
    "OBJECT",
    "ONABORT",
    "ONBEFORECOPY",
    "ONBEFORECUT",
    "ONBEFOREPASTE",
    "ONBLUR",
    "ONCHANGE",
    "ONCLICK",
    "ONCONTEXTMENU",
    "ONCOPY",
    "ONCUT",
    "ONDBLCLICK",
    "ONDRAG",
    "ONDRAGEND",
    "ONDRAGENTER",
    "ONDRAGLEAVE",
    "ONDRAGOVER",
    "ONDRAGSTART",
    "ONDROP",
    "ONERROR",
    "ONFOCUS",
    "ONINPUT",
    "ONKEYDOWN",
    "ONKEYPRESS",
    "ONKEYUP",
    "ONLOAD",
    "ONMOUSEDOWN",
    "ONMOUSEMOVE",
    "ONMOUSEOUT",
    "ONMOUSEOVER",
    "ONMOUSEUP",
    "ONMOUSEWHEEL",
    "ONPASTE",
    "ONRESET",
    "ONRESIZE",
    "ONSCROLL",
    "ONSEARCH",
    "ONSELECT",
    "ONSELECTSTART",
    "ONSUBMIT",
    "ONUNLOAD",
    "OVERSRC",
    "PAGEX",
    "PAGEY",
    "PLACEHOLDER",
    "PLAIN",
    "PLUGINPAGE",
    "PLUGINSPAGE",
    "PLUGINURL",
    "PRECISION",
    "PROFILE",
    "PROMPT",
    "READONLY",
    "REL",
    "RESULTS",
    "REV",
    "ROWS",
    "ROWSPAN",
    "RULES",
    "SCHEME",
    "SCOPE",
    "SCROLLAMOUNT",
    "SCROLLDELAY",
    "SCROLLING",
    "SELECTED",
    "SHAPE",
    "SIZE",
    "SPAN",
    "SRC",
    "STANDBY",
    "START",
    "STYLE",
    "SUMMARY",
    "TABINDEX",
    "TABLEBORDER",
    "TARGET",
    "TEXT",
    "TITLE",
    "TOP",
    "TOPMARGIN",
    "TRUESPEED",
    "TYPE",
    "UNKNOWN",
    "USEMAP",
    "VALIGN",
    "VALUE",
    "VALUETYPE",
    "VERSION",
    "VISIBILITY",
    "VLINK",
    "VSPACE",
    "WIDTH",
    "WRAP",
    "Z-INDEX",
    0
};
DOM::DOMString getAttrName(unsigned short id)
{
    return attrList[id-1];
}
