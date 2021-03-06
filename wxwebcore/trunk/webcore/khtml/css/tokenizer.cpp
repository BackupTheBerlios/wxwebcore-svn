/*
 * This file is part of the DOM implementation for KDE.
 *
 * Copyright (C) 2003 Lars Knoll (knoll@kde.org)
 *
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/* This file is mostly data generated by flex. Unfortunately flex
   can't handle 16bit strings directly, so we just copy the part of
   the code we need and modify it to our needs.

   Most of the defines below are to make sure we can easily use the
   flex generated code, using as little editing as possible.

   The flex syntax to generate the lexer are more or less directly
   copied from the CSS2.1 specs, with some fixes for comments and
   the important symbol.

   To regenerate, run flex on tokenizer.flex. After this, copy the
   data tables and the YY_DECL method over to this file. Remove the
   init code from YY_DECL and change the YY_END_OF_BUFFER to only call
   yyterminate().

*/

// --------- begin generated code -------------------

#define YY_NUM_RULES 48
#define YY_END_OF_BUFFER 49
static yyconst short int yy_accept[317] =
    {   0,
        0,    0,   49,   47,    2,    2,   47,   47,   47,   47,
       47,   47,   47,   47,   47,   41,   47,   47,   47,   47,
       11,   11,   47,   47,    2,    0,    0,    0,   10,    0,
       12,    0,    8,    0,    0,    9,    0,    0,   11,   41,
        0,   40,    0,    0,   41,    0,   39,   39,   39,   39,
       39,   39,   39,   39,   39,   39,   39,   39,   36,    0,
        0,    0,    0,    0,    0,    0,    0,   11,   11,    7,
       44,   11,    0,    0,   11,    6,    5,    0,    0,    0,
       10,    0,    0,   12,   12,    0,    0,   10,    0,    0,
        4,    0,    0,   39,   39,   39,    0,   39,   27,   39,

       23,   25,   39,   37,   29,   39,   28,   35,   31,   30,
       26,   39,    0,    0,    0,    0,    0,    0,    0,    0,
       11,   11,   11,   45,   45,   11,    0,    0,    0,   12,
        0,    0,    0,    1,   39,   39,   39,   39,   32,   39,
       38,   33,    3,    0,    0,    0,    0,    0,    0,    0,
       11,   11,    0,   45,   45,   45,   44,    0,    0,   12,
        0,    0,    0,   39,   39,   39,   34,    0,    0,    0,
        0,    0,    0,   14,   11,   11,   46,   45,   45,   45,
       45,    0,    0,    0,    0,   43,    0,    0,    0,   12,
        0,   39,   39,   24,    0,    0,    0,    0,   15,    0,

       11,   11,   46,   45,   45,   45,   45,   45,    0,    0,
        0,    0,    0,    0,    0,    0,    0,   43,    0,    0,
        0,    0,   12,    0,   39,   39,    0,    0,    0,   13,
        0,   11,   11,   46,   45,   45,   45,   45,   45,   45,
        0,   42,    0,    0,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,   12,    0,   39,   39,    0,
       17,    0,    0,   11,   46,   45,   45,   45,   45,   45,
       45,   45,    0,   42,    0,    0,    0,   42,    0,    0,
        0,    0,   39,    0,    0,    0,    0,    0,   46,    0,
        0,    0,   22,    0,    0,    0,   16,   18,   46,    0,

        0,    0,    0,    0,    0,    0,    0,    0,    0,   19,
        0,    0,    0,   20,   21,    0
    } ;

static yyconst int yy_ec[256] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
        1,    4,    5,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    6,    7,    8,    9,   10,   11,   12,   13,   14,
       15,   16,   17,   12,   18,   19,   20,   21,   21,   21,
       21,   21,   21,   21,   21,   21,   21,   12,   12,   22,
       23,   24,   25,   26,   30,   31,   32,   33,   34,   35,
       36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
       46,   47,   48,   49,   50,   51,   39,   52,   39,   53,
       12,   27,   12,   28,   29,   12,   30,   31,   32,   33,

       34,   35,   36,   37,   38,   39,   40,   41,   42,   43,
       44,   45,   46,   47,   48,   49,   50,   51,   39,   52,
       39,   53,   12,   54,   12,   55,    1,   56,   56,   56,
       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,

       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
       56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
       56,   56,   56,   56,   56
    } ;

static yyconst int yy_meta[57] =
    {   0,
        1,    2,    3,    3,    3,    4,    4,    4,    4,    4,
        4,    4,    4,    5,    4,    4,    4,    6,    4,    4,
        7,    4,    4,    4,    8,    4,    9,    4,    9,   10,
       10,   10,   10,   10,   10,    9,    9,    9,    9,    9,
        9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
        9,    9,    9,    4,    4,    9
    } ;

static yyconst short int yy_base[345] =
    {   0,
        0,    0,  775, 1649,   55,   60,   65,   64,  741,  744,
       60,  743,   56,  744,  748,   93,  749,   57,   75,  731,
       63,   71,  730,  729,   76,  148,  709,   86, 1649,  185,
      715,  126, 1649,   88,  219, 1649,  717,  134,   70,   98,
      724,  728,  711,  709,    0,  141,  150,  701,  121,   59,
      143,  151,  154,  153,  155,  157,  176,  164,  700,  708,
      685,  674,  666,  667,  674,  677,  676,  183,  253, 1649,
     1649,  186,  260,  275,  200, 1649, 1649,  660,  234,  175,
      203,  309,  343,  677,  377,  235,  216,  218,  411,  445,
     1649,  674,  219,  662,  479,  659,  328,  217,  658,  233,

      657,  656,  174,  642,  641,  220,  621,  620,  617,  616,
      615,  237,  623,  595,  600,  586,  583,  594,  571,  576,
      430,  251,  513,  208,  573,  252,  545,  274,  505,  520,
      262,  528,  572, 1649,  535,  560,  569,  270,  559,  244,
      558,  557, 1649,  534,  534,  531,  535,  540,  543,  542,
      561,  576,  584,  298,  539,  532,  618,  495,  604,  619,
      625,  517,  252,  640,  646,  276,  505,  489,  482,  511,
      481,  497,  477, 1649,  661,  667,  682,  301,  499,  498,
      497,  716,  742,  294,  307, 1649,  768,  472,  702,  728,
      775,  783,  790,  480,  464,  470,  468,  453, 1649,  449,

      798,  805,  813,  304,  466,  465,  464,  463,  350,  323,
      382,  847,  311,  881,  915,  941,  967,  993, 1019, 1053,
      457,  832,  866,  901,  927,  953,  468,  387,  404, 1649,
      396,  979, 1060, 1068,  307,  400,  380,  376,  370,  347,
      387, 1649,  391,  392,  425, 1102, 1136,  393,  344, 1115,
     1170, 1204, 1189,  326, 1211, 1219, 1226,  465, 1234,  388,
     1649,  336,  335,  451, 1241,  348, 1649, 1649, 1649, 1649,
     1649, 1649,  493,  395,  466, 1249, 1283,  410,  446, 1269,
     1284,  288,  660,  301,  283,  298,  293,  265, 1290, 1305,
     1311, 1326, 1649,  266,  235,  195, 1649, 1649, 1649, 1332,

     1347, 1353,  193,  175,   71, 1368, 1374, 1389,   68, 1649,
       42, 1395, 1410, 1649, 1649, 1649, 1444, 1449, 1458, 1463,
     1470, 1476, 1485, 1492, 1501, 1511, 1513, 1520, 1525, 1532,
     1542, 1549, 1554, 1564, 1569, 1578, 1583, 1592, 1601, 1610,
     1615, 1624, 1633, 1638
    } ;

static yyconst short int yy_def[345] =
    {   0,
      316,    1,  316,  316,  316,  316,  316,  317,  318,  316,
      319,  316,  320,  316,  316,  316,  316,  316,  321,  316,
      322,  322,  316,  316,  316,  316,  316,  317,  316,  323,
      318,  324,  316,  319,  325,  316,  316,  321,  322,   16,
      326,  316,  327,  316,   16,  328,  329,  329,  329,  329,
      329,  329,  329,  329,  329,  329,  329,  329,  329,  316,
      316,  316,  316,  316,  316,  316,  316,  322,  322,  316,
      316,  322,  330,  316,  322,  316,  316,  316,  317,  317,
      317,  317,  323,  318,  318,  319,  319,  319,  319,  325,
      316,  326,  331,  329,  329,  329,  332,  329,  329,  329,

      329,  329,  329,  329,  329,  329,  329,  329,  329,  329,
      329,  329,  316,  316,  316,  316,  316,  316,  316,  316,
       69,  322,   69,  333,  316,  322,  316,  317,   82,   85,
      319,   89,  334,  316,   95,  329,   95,  329,  329,  329,
      329,  329,  316,  316,  316,  316,  316,  316,  316,  316,
       69,  123,  316,  335,  316,  316,  336,  316,   82,   85,
       89,  334,  331,   95,  137,  329,  329,  316,  316,  316,
      316,  316,  316,  316,   69,  123,  316,  337,  316,  316,
      316,  336,  336,  338,  339,  316,  340,  316,   82,   85,
       89,   95,  137,  329,  316,  316,  316,  316,  316,  316,

       69,  123,  316,  341,  316,  316,  316,  316,  316,  338,
      316,  342,  339,  343,  336,  336,  336,  336,  336,  340,
      316,   82,   85,   89,   95,  137,  316,  316,  316,  316,
      316,   69,  123,  316,  344,  316,  316,  316,  316,  316,
      316,  316,  338,  338,  338,  338,  342,  339,  339,  339,
      339,  343,  219,  316,   82,   85,   89,  329,  137,  316,
      316,  316,  316,  232,  316,  316,  316,  316,  316,  316,
      316,  316,  338,  338,  338,  246,  339,  339,  339,  251,
      219,  316,  329,  316,  316,  316,  316,  316,  316,  246,
      251,  219,  316,  316,  316,  316,  316,  316,  316,  246,

      251,  219,  316,  316,  316,  246,  251,  219,  316,  316,
      316,  246,  251,  316,  316,    0,  316,  316,  316,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,
      316,  316,  316,  316
    } ;

static yyconst short int yy_nxt[1706] =
    {   0,
        4,    5,    6,    5,    5,    5,    7,    8,    9,   10,
        4,    4,   11,    4,    4,   12,    4,   13,   14,   15,
       16,   17,    4,    4,    4,   18,   19,   20,   21,   21,
       21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
       21,   21,   21,   21,   21,   21,   21,   21,   21,   22,
       21,   21,   21,   23,   24,   21,   25,   25,   25,   25,
       25,   25,   25,   25,   25,   25,   26,   26,   26,   26,
       26,   29,   29,   37,   61,  315,   71,   25,   25,   25,
       25,   25,   38,   71,   71,   97,   35,   74,   62,   73,
       30,   63,  100,   29,   64,   69,   73,   73,   65,   66,

       29,   67,   27,   42,   69,   69,   69,   69,   69,   69,
       43,   44,   30,   45,   35,  314,  316,   75,   40,   46,
      311,   47,   48,   48,   49,   50,   51,   48,   52,   53,
       54,   48,   55,   48,   56,   48,   48,   57,   48,   58,
       59,   48,   48,   48,   48,   48,   85,   97,   48,   26,
       26,   26,   26,   26,   69,   85,   85,   85,   85,   85,
       85,   95,   99,   69,   69,   69,   69,   69,   69,   97,
       95,   95,   95,   95,   95,   95,   97,   97,   98,   97,
       97,   97,   29,   97,  101,   27,   28,   28,   28,   79,
       97,  106,   81,  112,  102,  105,   71,  103,  107,   71,

       97,   30,   97,  140,  108,   82,  104,  109,  310,   73,
       29,   83,   73,   71,   82,   82,   82,   82,   82,   82,
       34,   34,   34,   86,  110,  153,   73,  111,   29,   30,
       29,   88,  155,  309,   93,  305,   28,   34,  134,   89,
      126,   29,   35,   97,   35,   90,   97,   29,   89,   89,
       89,   89,   89,   89,   68,   68,   68,   68,   68,   97,
       30,   35,  138,   97,   71,  157,   71,  163,  139,  142,
       97,  134,  141,  121,   29,  304,  167,   73,   73,   73,
      123,   29,  121,  121,  121,  121,  121,  121,   35,  123,
      123,  123,  123,  123,  123,  124,   97,  303,  298,  125,

       30,  211,   97,  166,  124,  124,  124,  124,  124,  124,
       80,  128,  128,  128,   80,  153,   29,  194,  153,  211,
      212,  153,  179,  211,  153,  205,  297,  296,  236,  129,
      211,  267,  295,  214,  294,   30,  293,  214,  129,  129,
      129,  129,  129,  129,   28,   28,   28,   79,  137,  212,
       81,  209,  209,  209,  209,  209,  211,  137,  137,  137,
      137,  137,  137,   82,  186,  153,  288,  287,  282,   83,
      214,  272,   82,   82,   82,   82,   82,   82,   84,   84,
       84,   84,   84,  241,  241,  241,  241,  241,  241,  241,
      241,  241,  241,  210,  271,  213,  242,  130,  211,  211,

      270,  242,  211,   32,  269,  211,  130,  130,  130,  130,
      130,  130,   87,  131,  131,  131,   87,  212,  212,  214,
      284,  212,  211,   29,  268,  263,  273,  241,  241,  241,
      273,  132,  211,  262,  285,  261,  214,   35,  286,  274,
      132,  132,  132,  132,  132,  132,   34,   34,   34,   86,
      151,  212,  122,  122,  122,  122,  122,   88,  211,  151,
      151,  151,  151,  151,  151,   89,   94,   94,   94,   94,
       94,   90,  214,  211,   89,   89,   89,   89,   89,   89,
       94,   94,   94,   94,   94,  260,  254,  240,  239,  238,
      237,   97,  212,  231,  273,  241,  241,  241,  273,  135,

      211,  230,  229,  228,  227,   97,   97,  274,  135,  135,
      135,  135,  135,  135,  122,  122,  122,  122,  122,  212,
      221,  208,  207,  206,  200,  159,  199,  198,  197,  196,
      195,   97,  163,  152,  159,  159,  159,  159,  159,  159,
      160,  188,  152,  152,  152,  152,  152,  152,  161,  160,
      160,  160,  160,  160,  160,  164,  181,  161,  161,  161,
      161,  161,  161,  180,  164,  164,  164,  164,  164,  164,
      136,  136,  136,  136,  136,  174,  173,  172,  171,  170,
      169,  175,  168,   97,   97,   97,   97,  163,  158,  165,
      175,  175,  175,  175,  175,  175,  176,  156,  165,  165,

      165,  165,  165,  165,  177,  176,  176,  176,  176,  176,
      176,  150,  149,  177,  177,  177,  177,  177,  177,  182,
      182,  182,  182,  182,  189,  184,  148,  147,  146,  145,
      185,  144,  186,  189,  189,  189,  189,  189,  189,  190,
      143,   97,   97,   97,  187,  191,   97,   97,  190,  190,
      190,  190,  190,  190,  191,  191,  191,  191,  191,  191,
      192,  136,  136,  136,  136,  136,  193,   97,   97,  192,
      192,  192,  192,  192,  192,  193,  193,  193,  193,  193,
      193,  201,   97,   97,   97,   97,   97,  202,   97,   93,
      201,  201,  201,  201,  201,  201,  202,  202,  202,  202,

      202,  202,  203,   32,  127,  120,  119,  118,  117,  116,
      115,  203,  203,  203,  203,  203,  203,  182,  182,  182,
      182,  182,  222,  184,  114,  113,   97,   97,  185,   40,
      186,  222,  222,  222,  222,  222,  222,   46,   42,   93,
       91,   32,  187,  209,  209,  209,  209,  209,  223,  316,
       78,   77,   76,   70,  316,   60,  186,  223,  223,  223,
      223,  223,  223,   41,   40,   36,   33,   32,  187,  209,
      209,  209,  209,  215,  316,  217,  316,  316,  316,  316,
      217,  217,  218,  316,  316,  316,  316,  316,  219,  316,
      316,  316,  316,  316,  220,  224,  316,  219,  219,  219,

      219,  219,  219,  225,  224,  224,  224,  224,  224,  224,
      226,  316,  225,  225,  225,  225,  225,  225,  232,  226,
      226,  226,  226,  226,  226,  233,  316,  232,  232,  232,
      232,  232,  232,  234,  233,  233,  233,  233,  233,  233,
      316,  316,  234,  234,  234,  234,  234,  234,  210,  210,
      210,  243,  255,  316,  245,  316,  316,  316,  316,  316,
      316,  255,  255,  255,  255,  255,  255,  246,  316,  316,
      316,  316,  316,  247,  316,  316,  246,  246,  246,  246,
      246,  246,  213,  213,  213,  248,  256,  316,  316,  316,
      316,  316,  316,  250,  316,  256,  256,  256,  256,  256,

      256,  251,  316,  316,  316,  316,  316,  252,  316,  316,
      251,  251,  251,  251,  251,  251,  209,  209,  209,  209,
      209,  257,  316,  316,  316,  316,  316,  316,  316,  186,
      257,  257,  257,  257,  257,  257,  316,  316,  316,  316,
      316,  187,  209,  209,  209,  209,  209,  258,  316,  316,
      316,  316,  316,  316,  316,  186,  258,  258,  258,  258,
      258,  258,  316,  316,  316,  316,  316,  187,  209,  209,
      209,  209,  209,  259,  316,  316,  316,  316,  316,  316,
      316,  186,  259,  259,  259,  259,  259,  259,  316,  316,
      316,  316,  316,  187,  209,  209,  209,  209,  209,   72,

      316,  316,  316,  316,  316,  316,  316,  186,   72,   72,
       72,   72,   72,   72,  316,  316,  316,  316,  316,  187,
      215,  215,  215,  215,  215,  316,  316,  316,  316,  316,
      316,  316,  316,  186,  316,  316,  316,  316,  316,  253,
      316,  316,  316,  316,  316,  187,  316,  316,  253,  253,
      253,  253,  253,  253,  209,  209,  209,  209,  215,  316,
      217,  316,  316,  316,  316,  217,  217,  218,  316,  316,
      316,  316,  316,  219,  316,  316,  316,  316,  316,  220,
      264,  316,  219,  219,  219,  219,  219,  219,  265,  264,
      264,  264,  264,  264,  264,  316,  316,  265,  265,  265,

      265,  265,  265,  244,  275,  275,  275,  244,  316,  211,
      316,  316,  316,  316,  316,  316,  277,  241,  241,  241,
      277,  316,  276,  316,  316,  316,  316,  211,  212,  278,
      316,  276,  276,  276,  276,  276,  276,  210,  210,  210,
      243,  214,  316,  245,  316,  316,  316,  316,  316,  316,
      316,  316,  316,  316,  316,  316,  246,  316,  316,  316,
      316,  316,  247,  316,  316,  246,  246,  246,  246,  246,
      246,  249,  279,  279,  279,  249,  316,  316,  316,  316,
      316,  316,  211,  316,  316,  316,  316,  316,  316,  316,
      280,  316,  316,  316,  316,  316,  214,  316,  316,  280,

      280,  280,  280,  280,  280,  213,  213,  213,  248,  281,
      316,  316,  316,  316,  316,  316,  250,  316,  281,  281,
      281,  281,  281,  281,  251,  316,  316,  316,  316,  316,
      252,   28,  316,  251,  251,  251,  251,  251,  251,   31,
       28,   28,   28,   28,   28,   28,   34,  316,   31,   31,
       31,   31,   31,   31,  283,   34,   34,   34,   34,   34,
       34,  289,  316,  283,  283,  283,  283,  283,  283,  290,
      289,  289,  289,  289,  289,  289,  316,  316,  290,  290,
      290,  290,  290,  290,  277,  241,  241,  241,  277,  291,
      316,  316,  316,  316,  316,  211,  316,  278,  291,  291,

      291,  291,  291,  291,  292,  316,  316,  316,  316,  214,
      299,  316,  316,  292,  292,  292,  292,  292,  292,  299,
      299,  299,  299,  299,  299,  300,  316,  316,  316,  316,
      316,  301,  316,  316,  300,  300,  300,  300,  300,  300,
      301,  301,  301,  301,  301,  301,  302,  316,  316,  316,
      316,  316,  306,  316,  316,  302,  302,  302,  302,  302,
      302,  306,  306,  306,  306,  306,  306,  307,  316,  316,
      316,  316,  316,  308,  316,  316,  307,  307,  307,  307,
      307,  307,  308,  308,  308,  308,  308,  308,  312,  316,
      316,  316,  316,  316,  313,  316,  316,  312,  312,  312,

      312,  312,  312,  313,  313,  313,  313,  313,  313,  183,
      316,  316,  316,  316,  316,  210,  316,  316,  183,  183,
      183,  183,  183,  183,  210,  210,  210,  210,  210,  210,
      213,  316,  316,  316,  316,  316,  316,  316,  316,  213,
      213,  213,  213,  213,  213,   28,  316,   28,   28,   28,
       28,   28,   28,   28,   31,   31,  316,   31,   31,   34,
      316,   34,   34,   34,   34,   34,   34,   34,   39,  316,
      316,   39,   39,   68,   68,   68,   68,   68,   68,   68,
       72,   72,   72,  316,   72,   72,   80,   80,   80,   80,
       80,   80,   80,   80,   80,   84,   84,   84,   84,   84,

       84,   84,   87,   87,   87,   87,   87,   87,   87,   87,
       87,   92,   92,   92,   92,   92,   92,   92,   92,   92,
       92,   48,   48,   94,   94,   94,   94,   94,   94,   94,
       96,   96,  316,   96,   96,  122,  122,  122,  122,  122,
      122,  122,  133,  133,  133,  133,  133,  133,  133,  133,
      133,  133,  136,  136,  136,  136,  136,  136,  136,  154,
      154,  154,  316,  154,  162,  162,  162,  162,  162,  162,
      162,  162,  162,  162,  178,  178,  178,  316,  178,  183,
      183,  183,  316,  183,  183,  183,  183,  183,  204,  204,
      204,  316,  204,  210,  316,  210,  210,  210,  210,  210,

      210,  210,  213,  316,  213,  213,  213,  213,  213,  213,
      213,  216,  216,  216,  216,  216,  216,  216,  216,  216,
      235,  235,  235,  316,  235,  244,  244,  244,  244,  244,
      244,  244,  244,  244,  249,  249,  249,  249,  249,  249,
      249,  249,  249,  266,  266,  266,  316,  266,    3,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,

      316,  316,  316,  316,  316
    } ;

static yyconst short int yy_chk[1706] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    5,    5,    5,    5,
        5,    6,    6,    6,    6,    6,    7,    7,    7,    7,
        7,    8,   11,   13,   18,  311,   21,   25,   25,   25,
       25,   25,   13,   39,   22,   50,   11,   22,   18,   21,
        8,   18,   50,   28,   18,   19,   39,   22,   18,   18,

       34,   18,    7,   16,   19,   19,   19,   19,   19,   19,
       16,   16,   28,   16,   34,  309,   40,   22,   40,   16,
      305,   16,   16,   16,   16,   16,   16,   16,   16,   16,
       16,   16,   16,   16,   16,   16,   16,   16,   16,   16,
       16,   16,   16,   16,   16,   16,   32,   49,   16,   26,
       26,   26,   26,   26,   38,   32,   32,   32,   32,   32,
       32,   46,   49,   38,   38,   38,   38,   38,   38,   51,
       46,   46,   46,   46,   46,   46,   47,   52,   47,   54,
       53,   55,   80,   56,   51,   26,   30,   30,   30,   30,
       58,   55,   30,   58,   51,   54,   68,   52,   56,   72,

      103,   80,   57,  103,   56,   30,   53,   57,  304,   68,
       81,   30,   72,   75,   30,   30,   30,   30,   30,   30,
       35,   35,   35,   35,   57,  124,   75,   57,   87,   81,
       88,   35,  124,  303,   93,  296,   79,   86,   93,   35,
       75,   79,   87,   98,   88,   35,  106,   86,   35,   35,
       35,   35,   35,   35,   69,   69,   69,   69,   69,  100,
       79,   86,   98,  112,  122,  126,   69,  163,  100,  112,
      140,  163,  106,   69,  131,  295,  140,  122,  126,   69,
       73,  128,   69,   69,   69,   69,   69,   69,  131,   73,
       73,   73,   73,   73,   73,   74,  138,  294,  288,   74,

      128,  184,  166,  138,   74,   74,   74,   74,   74,   74,
       82,   82,   82,   82,   82,  154,   82,  166,  178,  185,
      184,  204,  154,  213,  235,  178,  287,  286,  204,   82,
      210,  235,  285,  185,  284,   82,  282,  213,   82,   82,
       82,   82,   82,   82,   83,   83,   83,   83,   97,  210,
       83,  209,  209,  209,  209,  209,  249,   97,   97,   97,
       97,   97,   97,   83,  209,  266,  263,  262,  254,   83,
      249,  240,   83,   83,   83,   83,   83,   83,   85,   85,
       85,   85,   85,  211,  211,  211,  211,  211,  241,  241,
      241,  241,  241,  243,  239,  248,  211,   85,  243,  244,

      238,  241,  274,   85,  237,  248,   85,   85,   85,   85,
       85,   85,   89,   89,   89,   89,   89,  243,  244,  248,
      260,  274,  278,   89,  236,  231,  245,  245,  245,  245,
      245,   89,  245,  229,  260,  228,  278,   89,  260,  245,
       89,   89,   89,   89,   89,   89,   90,   90,   90,   90,
      121,  245,  264,  264,  264,  264,  264,   90,  279,  121,
      121,  121,  121,  121,  121,   90,  258,  258,  258,  258,
      258,   90,  279,  275,   90,   90,   90,   90,   90,   90,
       95,   95,   95,   95,   95,  227,  221,  208,  207,  206,
      205,  258,  275,  200,  273,  273,  273,  273,  273,   95,

      273,  198,  197,  196,  195,   95,  194,  273,   95,   95,
       95,   95,   95,   95,  123,  123,  123,  123,  123,  273,
      188,  181,  180,  179,  173,  129,  172,  171,  170,  169,
      168,  167,  162,  123,  129,  129,  129,  129,  129,  129,
      130,  158,  123,  123,  123,  123,  123,  123,  132,  130,
      130,  130,  130,  130,  130,  135,  156,  132,  132,  132,
      132,  132,  132,  155,  135,  135,  135,  135,  135,  135,
      137,  137,  137,  137,  137,  150,  149,  148,  147,  146,
      145,  151,  144,  142,  141,  139,  136,  133,  127,  137,
      151,  151,  151,  151,  151,  151,  152,  125,  137,  137,

      137,  137,  137,  137,  153,  152,  152,  152,  152,  152,
      152,  120,  119,  153,  153,  153,  153,  153,  153,  157,
      157,  157,  157,  157,  159,  157,  118,  117,  116,  115,
      157,  114,  157,  159,  159,  159,  159,  159,  159,  160,
      113,  111,  110,  109,  157,  161,  108,  107,  160,  160,
      160,  160,  160,  160,  161,  161,  161,  161,  161,  161,
      164,  283,  283,  283,  283,  283,  165,  105,  104,  164,
      164,  164,  164,  164,  164,  165,  165,  165,  165,  165,
      165,  175,  102,  101,   99,   96,  283,  176,   94,   92,
      175,  175,  175,  175,  175,  175,  176,  176,  176,  176,

      176,  176,  177,   84,   78,   67,   66,   65,   64,   63,
       62,  177,  177,  177,  177,  177,  177,  182,  182,  182,
      182,  182,  189,  182,   61,   60,   59,   48,  182,   44,
      182,  189,  189,  189,  189,  189,  189,   43,   42,   41,
       37,   31,  182,  183,  183,  183,  183,  183,  190,  183,
       27,   24,   23,   20,  183,   17,  183,  190,  190,  190,
      190,  190,  190,   15,   14,   12,   10,    9,  183,  187,
      187,  187,  187,  187,    3,  187,    0,    0,    0,    0,
      187,  187,  187,    0,    0,    0,    0,    0,  187,    0,
        0,    0,    0,    0,  187,  191,    0,  187,  187,  187,

      187,  187,  187,  192,  191,  191,  191,  191,  191,  191,
      193,    0,  192,  192,  192,  192,  192,  192,  201,  193,
      193,  193,  193,  193,  193,  202,    0,  201,  201,  201,
      201,  201,  201,  203,  202,  202,  202,  202,  202,  202,
        0,    0,  203,  203,  203,  203,  203,  203,  212,  212,
      212,  212,  222,    0,  212,    0,    0,    0,    0,    0,
        0,  222,  222,  222,  222,  222,  222,  212,    0,    0,
        0,    0,    0,  212,    0,    0,  212,  212,  212,  212,
      212,  212,  214,  214,  214,  214,  223,    0,    0,    0,
        0,    0,    0,  214,    0,  223,  223,  223,  223,  223,

      223,  214,    0,    0,    0,    0,    0,  214,    0,    0,
      214,  214,  214,  214,  214,  214,  215,  215,  215,  215,
      215,  224,  215,    0,    0,    0,    0,  215,    0,  215,
      224,  224,  224,  224,  224,  224,    0,    0,    0,    0,
        0,  215,  216,  216,  216,  216,  216,  225,  216,    0,
        0,    0,    0,  216,    0,  216,  225,  225,  225,  225,
      225,  225,    0,    0,    0,    0,    0,  216,  217,  217,
      217,  217,  217,  226,  217,    0,    0,    0,    0,  217,
        0,  217,  226,  226,  226,  226,  226,  226,    0,    0,
        0,    0,    0,  217,  218,  218,  218,  218,  218,  232,

      218,    0,    0,    0,    0,  218,    0,  218,  232,  232,
      232,  232,  232,  232,    0,    0,    0,    0,    0,  218,
      219,  219,  219,  219,  219,    0,  219,    0,    0,    0,
        0,  219,    0,  219,    0,    0,    0,    0,    0,  219,
        0,    0,    0,    0,    0,  219,    0,    0,  219,  219,
      219,  219,  219,  219,  220,  220,  220,  220,  220,    0,
      220,    0,    0,    0,    0,  220,  220,  220,    0,    0,
        0,    0,    0,  220,    0,    0,    0,    0,    0,  220,
      233,    0,  220,  220,  220,  220,  220,  220,  234,  233,
      233,  233,  233,  233,  233,    0,    0,  234,  234,  234,

      234,  234,  234,  246,  246,  246,  246,  246,    0,  246,
        0,    0,    0,    0,    0,    0,  250,  250,  250,  250,
      250,    0,  246,    0,    0,    0,    0,  250,  246,  250,
        0,  246,  246,  246,  246,  246,  246,  247,  247,  247,
      247,  250,    0,  247,    0,    0,    0,    0,    0,    0,
        0,    0,    0,    0,    0,    0,  247,    0,    0,    0,
        0,    0,  247,    0,    0,  247,  247,  247,  247,  247,
      247,  251,  251,  251,  251,  251,    0,    0,    0,    0,
        0,    0,  251,    0,    0,    0,    0,    0,    0,    0,
      251,    0,    0,    0,    0,    0,  251,    0,    0,  251,

      251,  251,  251,  251,  251,  252,  252,  252,  252,  253,
        0,    0,    0,    0,    0,    0,  252,    0,  253,  253,
      253,  253,  253,  253,  252,    0,    0,    0,    0,    0,
      252,  255,    0,  252,  252,  252,  252,  252,  252,  256,
      255,  255,  255,  255,  255,  255,  257,    0,  256,  256,
      256,  256,  256,  256,  259,  257,  257,  257,  257,  257,
      257,  265,    0,  259,  259,  259,  259,  259,  259,  276,
      265,  265,  265,  265,  265,  265,    0,    0,  276,  276,
      276,  276,  276,  276,  277,  277,  277,  277,  277,  280,
        0,    0,    0,    0,    0,  277,    0,  277,  280,  280,

      280,  280,  280,  280,  281,    0,    0,    0,    0,  277,
      289,    0,    0,  281,  281,  281,  281,  281,  281,  289,
      289,  289,  289,  289,  289,  290,    0,    0,    0,    0,
        0,  291,    0,    0,  290,  290,  290,  290,  290,  290,
      291,  291,  291,  291,  291,  291,  292,    0,    0,    0,
        0,    0,  300,    0,    0,  292,  292,  292,  292,  292,
      292,  300,  300,  300,  300,  300,  300,  301,    0,    0,
        0,    0,    0,  302,    0,    0,  301,  301,  301,  301,
      301,  301,  302,  302,  302,  302,  302,  302,  306,    0,
        0,    0,    0,    0,  307,    0,    0,  306,  306,  306,

      306,  306,  306,  307,  307,  307,  307,  307,  307,  308,
        0,    0,    0,    0,    0,  312,    0,    0,  308,  308,
      308,  308,  308,  308,  312,  312,  312,  312,  312,  312,
      313,    0,    0,    0,    0,    0,    0,    0,    0,  313,
      313,  313,  313,  313,  313,  317,    0,  317,  317,  317,
      317,  317,  317,  317,  318,  318,    0,  318,  318,  319,
        0,  319,  319,  319,  319,  319,  319,  319,  320,    0,
        0,  320,  320,  321,  321,  321,  321,  321,  321,  321,
      322,  322,  322,    0,  322,  322,  323,  323,  323,  323,
      323,  323,  323,  323,  323,  324,  324,  324,  324,  324,

      324,  324,  325,  325,  325,  325,  325,  325,  325,  325,
      325,  326,  326,  326,  326,  326,  326,  326,  326,  326,
      326,  327,  327,  328,  328,  328,  328,  328,  328,  328,
      329,  329,    0,  329,  329,  330,  330,  330,  330,  330,
      330,  330,  331,  331,  331,  331,  331,  331,  331,  331,
      331,  331,  332,  332,  332,  332,  332,  332,  332,  333,
      333,  333,    0,  333,  334,  334,  334,  334,  334,  334,
      334,  334,  334,  334,  335,  335,  335,    0,  335,  336,
      336,  336,    0,  336,  336,  336,  336,  336,  337,  337,
      337,    0,  337,  338,    0,  338,  338,  338,  338,  338,

      338,  338,  339,    0,  339,  339,  339,  339,  339,  339,
      339,  340,  340,  340,  340,  340,  340,  340,  340,  340,
      341,  341,  341,    0,  341,  342,  342,  342,  342,  342,
      342,  342,  342,  342,  343,  343,  343,  343,  343,  343,
      343,  343,  343,  344,  344,  344,    0,  344,  316,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,
      316,  316,  316,  316,  316,  316,  316,  316,  316,  316,

      316,  316,  316,  316,  316
    } ;

YY_DECL
	{
	register yy_state_type yy_current_state;
	register unsigned short *yy_cp, *yy_bp;
	register int yy_act;
	while ( 1 )		/* loops until end-of-file is reached */
		{
		yy_cp = yy_c_buf_p;

		/* Support of yytext. */
		*yy_cp = yy_hold_char;

		/* yy_bp points to the position in yy_ch_buf of the start of
		 * the current run.
		 */
		yy_bp = yy_cp;

		yy_current_state = yy_start;
		do
			{
			register YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
			if ( yy_accept[yy_current_state] )
				{
				yy_last_accepting_state = yy_current_state;
				yy_last_accepting_cpos = yy_cp;
				}
			while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
				{
				yy_current_state = (int) yy_def[yy_current_state];
				if ( yy_current_state >= 317 )
					yy_c = yy_meta[(unsigned int) yy_c];
				}
			yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
			++yy_cp;
			}
		while ( yy_base[yy_current_state] != 1649 );

yy_find_action:
		yy_act = yy_accept[yy_current_state];
		if ( yy_act == 0 )
			{ /* have to back up */
			yy_cp = yy_last_accepting_cpos;
			yy_current_state = yy_last_accepting_state;
			yy_act = yy_accept[yy_current_state];
			}

		YY_DO_BEFORE_ACTION;




		switch ( yy_act )
	{ /* beginning of action switch */
			case 0: /* must back up */
			/* undo the effects of YY_DO_BEFORE_ACTION */
			*yy_cp = yy_hold_char;
			yy_cp = yy_last_accepting_cpos;
			yy_current_state = yy_last_accepting_state;
			goto yy_find_action;

case 1:
YY_RULE_SETUP
#line 25 "tokenizer.flex"
/* ignore comments */
	YY_BREAK
case 2:
YY_RULE_SETUP
#line 27 "tokenizer.flex"
{yyTok = WHITESPACE; return yyTok;}
	YY_BREAK
case 3:
YY_RULE_SETUP
#line 29 "tokenizer.flex"
{yyTok = SGML_CD; return yyTok;}
	YY_BREAK
case 4:
YY_RULE_SETUP
#line 30 "tokenizer.flex"
{yyTok = SGML_CD; return yyTok;}
	YY_BREAK
case 5:
YY_RULE_SETUP
#line 31 "tokenizer.flex"
{yyTok = INCLUDES; return yyTok;}
	YY_BREAK
case 6:
YY_RULE_SETUP
#line 32 "tokenizer.flex"
{yyTok = DASHMATCH; return yyTok;}
	YY_BREAK
case 7:
YY_RULE_SETUP
#line 33 "tokenizer.flex"
{yyTok = BEGINSWITH; return yyTok;}
	YY_BREAK
case 8:
YY_RULE_SETUP
#line 34 "tokenizer.flex"
{yyTok = ENDSWITH; return yyTok;}
	YY_BREAK
case 9:
YY_RULE_SETUP
#line 35 "tokenizer.flex"
{yyTok = CONTAINS; return yyTok;}
	YY_BREAK
case 10:
YY_RULE_SETUP
#line 37 "tokenizer.flex"
{yyTok = STRING; return yyTok;}
	YY_BREAK
case 11:
YY_RULE_SETUP
#line 39 "tokenizer.flex"
{yyTok = IDENT; return yyTok;}
	YY_BREAK
case 12:
YY_RULE_SETUP
#line 41 "tokenizer.flex"
{yyTok = HASH; return yyTok;}
	YY_BREAK
case 13:
YY_RULE_SETUP
#line 43 "tokenizer.flex"
{yyTok = IMPORT_SYM; return yyTok;}
	YY_BREAK
case 14:
YY_RULE_SETUP
#line 44 "tokenizer.flex"
{yyTok = PAGE_SYM; return yyTok;}
	YY_BREAK
case 15:
YY_RULE_SETUP
#line 45 "tokenizer.flex"
{yyTok = MEDIA_SYM; return yyTok;}
	YY_BREAK
case 16:
YY_RULE_SETUP
#line 46 "tokenizer.flex"
{yyTok = FONT_FACE_SYM; return yyTok;}
	YY_BREAK
case 17:
YY_RULE_SETUP
#line 47 "tokenizer.flex"
{yyTok = CHARSET_SYM; return yyTok;}
	YY_BREAK
case 18:
YY_RULE_SETUP
#line 48 "tokenizer.flex"
{yyTok = NAMESPACE_SYM; return yyTok; }
	YY_BREAK
case 19:
YY_RULE_SETUP
#line 49 "tokenizer.flex"
{yyTok = KHTML_RULE_SYM; return yyTok; }
	YY_BREAK
case 20:
YY_RULE_SETUP
#line 50 "tokenizer.flex"
{yyTok = KHTML_DECLS_SYM; return yyTok; }
	YY_BREAK
case 21:
YY_RULE_SETUP
#line 51 "tokenizer.flex"
{yyTok = KHTML_VALUE_SYM; return yyTok; }
	YY_BREAK
case 22:
YY_RULE_SETUP
#line 53 "tokenizer.flex"
{yyTok = IMPORTANT_SYM; return yyTok;}
	YY_BREAK
case 23:
YY_RULE_SETUP
#line 55 "tokenizer.flex"
{yyTok = EMS; return yyTok;}
	YY_BREAK
case 24:
YY_RULE_SETUP
#line 56 "tokenizer.flex"
{yyTok = QEMS; return yyTok;} /* quirky ems */
	YY_BREAK
case 25:
YY_RULE_SETUP
#line 57 "tokenizer.flex"
{yyTok = EXS; return yyTok;}
	YY_BREAK
case 26:
YY_RULE_SETUP
#line 58 "tokenizer.flex"
{yyTok = PXS; return yyTok;}
	YY_BREAK
case 27:
YY_RULE_SETUP
#line 59 "tokenizer.flex"
{yyTok = CMS; return yyTok;}
	YY_BREAK
case 28:
YY_RULE_SETUP
#line 60 "tokenizer.flex"
{yyTok = MMS; return yyTok;}
	YY_BREAK
case 29:
YY_RULE_SETUP
#line 61 "tokenizer.flex"
{yyTok = INS; return yyTok;}
	YY_BREAK
case 30:
YY_RULE_SETUP
#line 62 "tokenizer.flex"
{yyTok = PTS; return yyTok;}
	YY_BREAK
case 31:
YY_RULE_SETUP
#line 63 "tokenizer.flex"
{yyTok = PCS; return yyTok;}
	YY_BREAK
case 32:
YY_RULE_SETUP
#line 64 "tokenizer.flex"
{yyTok = DEGS; return yyTok;}
	YY_BREAK
case 33:
YY_RULE_SETUP
#line 65 "tokenizer.flex"
{yyTok = RADS; return yyTok;}
	YY_BREAK
case 34:
YY_RULE_SETUP
#line 66 "tokenizer.flex"
{yyTok = GRADS; return yyTok;}
	YY_BREAK
case 35:
YY_RULE_SETUP
#line 67 "tokenizer.flex"
{yyTok = MSECS; return yyTok;}
	YY_BREAK
case 36:
YY_RULE_SETUP
#line 68 "tokenizer.flex"
{yyTok = SECS; return yyTok;}
	YY_BREAK
case 37:
YY_RULE_SETUP
#line 69 "tokenizer.flex"
{yyTok = HERZ; return yyTok;}
	YY_BREAK
case 38:
YY_RULE_SETUP
#line 70 "tokenizer.flex"
{yyTok = KHERZ; return yyTok;}
	YY_BREAK
case 39:
YY_RULE_SETUP
#line 71 "tokenizer.flex"
{yyTok = DIMEN; return yyTok;}
	YY_BREAK
case 40:
YY_RULE_SETUP
#line 72 "tokenizer.flex"
{yyTok = PERCENTAGE; return yyTok;}
	YY_BREAK
case 41:
YY_RULE_SETUP
#line 73 "tokenizer.flex"
{yyTok = NUMBER; return yyTok;}
	YY_BREAK
case 42:
YY_RULE_SETUP
#line 75 "tokenizer.flex"
{yyTok = URI; return yyTok;}
	YY_BREAK
case 43:
YY_RULE_SETUP
#line 76 "tokenizer.flex"
{yyTok = URI; return yyTok;}
	YY_BREAK
case 44:
YY_RULE_SETUP
#line 77 "tokenizer.flex"
{yyTok = FUNCTION; return yyTok;}
	YY_BREAK
case 45:
YY_RULE_SETUP
#line 79 "tokenizer.flex"
{yyTok = UNICODERANGE; return yyTok;}
	YY_BREAK
case 46:
YY_RULE_SETUP
#line 80 "tokenizer.flex"
{yyTok = UNICODERANGE; return yyTok;}
	YY_BREAK
case 47:
YY_RULE_SETUP
#line 82 "tokenizer.flex"
{yyTok = *yytext; return yyTok;}
	YY_BREAK
case 48:
YY_RULE_SETUP
#line 84 "tokenizer.flex"
ECHO;
	YY_BREAK
#line 1330 "lex.yy.c"
case YY_STATE_EOF(INITIAL):
case YY_END_OF_BUFFER:
	yyterminate();

	default:
		YY_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	} /* end of action switch */
		} /* end of scanning one token */
	} /* end of yylex */
