#include <stdint.h>
#include "params.h"
#include "consts.h"
#include "poly.h"

__attribute__((aligned(64)))
const int32_t qdata[] = {
#define _8XQ 0
  Q, Q, Q, Q, Q, Q, Q, Q,

#define _8XQINV 8
  QINV, QINV, QINV, QINV, QINV, QINV, QINV, QINV,

#define _8XDIV 16
  DIV, DIV, DIV, DIV, DIV, DIV, DIV, DIV,

#define _PMASK 24
  7, 6, 5, 4, 3, 2, 1, 0,

#define _ZETAS 32
   175040315,  331967329,  456276144,  454844763,  159980059, -478416174, -416659981, -320115552,
   238916051, -526806357,   39916768,  416926366,  397736216,   24955502,  304385919, -220562147,
  -312057843,  428266697,  382814741,   43923579, -113026495,  528865927,  -72521175, -472785220,
  -484244295, -405963773,  -95373355, -231657752,  419693733,  354932988,  210173399,  167562464,
   473515325, -173011427, -192724796, -390110669,  115572728,  -17391882, -171627748, -495644362,
   405439465,   40340982,  129757077,  160093967,  411895201,  263048769,  429963517, -384800154,
    15135544, -405343018, -212266845, -235262439,  285486254,  457308136, -364668038, -365165724,
  -293385227,  441800469, -418935751, -311687394, -422161617, -310379038,  262878662,  454568304,
  -250688461, -257602554,  197375900,  403767085,  382333025, -527643241, -205954134,  107243165,
   281152895, -317922323, -529131691, -227675423,  266434172,  386284822, -383005382,  254142543,
  -425720413, -141999989, -295055895,   81037018,  338701692,   78331885,  -65754902,  134085298,
   400841409,  -21467763,  -71151847,   -2164837,    6508487,   76696199, -293884740,  251502129,
   250304896,  -88835585,  405957924, -166638639,  463379170,  431164203, -206594448, -204978956,
  -340279225,  231165312,  265778546,  330774173,  299880748,  468083183, -414882508,  108190920,
   394320170, -100651400, -274409332,   88131428, -454290819,  182506441,  -70451475, -230436531,
    93990932, -432488013, -479196700,    7765600,  -94141852, -213056140, -525337670,          0,

#define ZETAS_QINV 160
   -413472965, -2125632671,   -34457424,  -527933093, -1309337061,   784593618,  1056327155, -1620349792,
  -1786146349,  1799721643,  1440814304, -1018049890,   -65734376, -1422603666, -1876914305, -1488028387,
    765091853,   749393097,   -14333419,   613038203,   575101505,  -912139641,  1683057193,  1589763772,
  -1241054023,   400129027, -1717258283, -1378799896,  -342358875,  2031606012,  1138949591,  1031589088,
   -248691395,  -299626979,  -141344572, -1316265421,   113475576,   -87122186, -1573573860, -1488121546,
   -405896215, -1170240010, -2045775979, -1513695473,  -284097119,   145870401, -1114326787,   313027174,
   -842599624,   992933078,  1977946275,  1784557081,  1136405678,   -85854232,  -668230790,  -137624732,
   -564704267,   917067541,  -672428999, -1981544674,  1938969391,  1695022562,  1724069318, -1059575440,
   1641729075, -1598206970,  -365709412,  -725287123, -1739722655,  1458097559,    39936938,  1624794781,
  -2034365057,  1019274221,   -37087403,  2113008353,  -372148612, -1956758250, -1642869446,  -262018993,
   1026295203,   968179851,  -435302935, -1606646054,  -903860868, -1000390675,   532457706,  1925577394,
   1122523841,  1961651597,  -131707111,   508229531,  2139049927,  1856916103, -1586778948,  1203871281,
   1961580928,   581990911,  -859673308,  -447394863,   119970530, -2040591573,  1836031600,   127419636,
    752074823,  1137134976,  1704949106, -1372899683,  1452265772,  -475897361,  2081776948,  2039667912,
    -64431830, -1277153672,  1372903564,   584107876,  -287305091,   436523977, -1216282899,  -143142579,
   -974508012,   755286451,   184551908,  -101286304,    66290276,   152896884,  1335360442,           0,
};

__attribute__((aligned(64)))
const uint8_t rejidx[256][8] = {
  { 0,  0,  0,  0,  0,  0,  0,  0},
  { 0,  0,  0,  0,  0,  0,  0,  0},
  { 1,  0,  0,  0,  0,  0,  0,  0},
  { 0,  1,  0,  0,  0,  0,  0,  0},
  { 2,  0,  0,  0,  0,  0,  0,  0},
  { 0,  2,  0,  0,  0,  0,  0,  0},
  { 1,  2,  0,  0,  0,  0,  0,  0},
  { 0,  1,  2,  0,  0,  0,  0,  0},
  { 3,  0,  0,  0,  0,  0,  0,  0},
  { 0,  3,  0,  0,  0,  0,  0,  0},
  { 1,  3,  0,  0,  0,  0,  0,  0},
  { 0,  1,  3,  0,  0,  0,  0,  0},
  { 2,  3,  0,  0,  0,  0,  0,  0},
  { 0,  2,  3,  0,  0,  0,  0,  0},
  { 1,  2,  3,  0,  0,  0,  0,  0},
  { 0,  1,  2,  3,  0,  0,  0,  0},
  { 4,  0,  0,  0,  0,  0,  0,  0},
  { 0,  4,  0,  0,  0,  0,  0,  0},
  { 1,  4,  0,  0,  0,  0,  0,  0},
  { 0,  1,  4,  0,  0,  0,  0,  0},
  { 2,  4,  0,  0,  0,  0,  0,  0},
  { 0,  2,  4,  0,  0,  0,  0,  0},
  { 1,  2,  4,  0,  0,  0,  0,  0},
  { 0,  1,  2,  4,  0,  0,  0,  0},
  { 3,  4,  0,  0,  0,  0,  0,  0},
  { 0,  3,  4,  0,  0,  0,  0,  0},
  { 1,  3,  4,  0,  0,  0,  0,  0},
  { 0,  1,  3,  4,  0,  0,  0,  0},
  { 2,  3,  4,  0,  0,  0,  0,  0},
  { 0,  2,  3,  4,  0,  0,  0,  0},
  { 1,  2,  3,  4,  0,  0,  0,  0},
  { 0,  1,  2,  3,  4,  0,  0,  0},
  { 5,  0,  0,  0,  0,  0,  0,  0},
  { 0,  5,  0,  0,  0,  0,  0,  0},
  { 1,  5,  0,  0,  0,  0,  0,  0},
  { 0,  1,  5,  0,  0,  0,  0,  0},
  { 2,  5,  0,  0,  0,  0,  0,  0},
  { 0,  2,  5,  0,  0,  0,  0,  0},
  { 1,  2,  5,  0,  0,  0,  0,  0},
  { 0,  1,  2,  5,  0,  0,  0,  0},
  { 3,  5,  0,  0,  0,  0,  0,  0},
  { 0,  3,  5,  0,  0,  0,  0,  0},
  { 1,  3,  5,  0,  0,  0,  0,  0},
  { 0,  1,  3,  5,  0,  0,  0,  0},
  { 2,  3,  5,  0,  0,  0,  0,  0},
  { 0,  2,  3,  5,  0,  0,  0,  0},
  { 1,  2,  3,  5,  0,  0,  0,  0},
  { 0,  1,  2,  3,  5,  0,  0,  0},
  { 4,  5,  0,  0,  0,  0,  0,  0},
  { 0,  4,  5,  0,  0,  0,  0,  0},
  { 1,  4,  5,  0,  0,  0,  0,  0},
  { 0,  1,  4,  5,  0,  0,  0,  0},
  { 2,  4,  5,  0,  0,  0,  0,  0},
  { 0,  2,  4,  5,  0,  0,  0,  0},
  { 1,  2,  4,  5,  0,  0,  0,  0},
  { 0,  1,  2,  4,  5,  0,  0,  0},
  { 3,  4,  5,  0,  0,  0,  0,  0},
  { 0,  3,  4,  5,  0,  0,  0,  0},
  { 1,  3,  4,  5,  0,  0,  0,  0},
  { 0,  1,  3,  4,  5,  0,  0,  0},
  { 2,  3,  4,  5,  0,  0,  0,  0},
  { 0,  2,  3,  4,  5,  0,  0,  0},
  { 1,  2,  3,  4,  5,  0,  0,  0},
  { 0,  1,  2,  3,  4,  5,  0,  0},
  { 6,  0,  0,  0,  0,  0,  0,  0},
  { 0,  6,  0,  0,  0,  0,  0,  0},
  { 1,  6,  0,  0,  0,  0,  0,  0},
  { 0,  1,  6,  0,  0,  0,  0,  0},
  { 2,  6,  0,  0,  0,  0,  0,  0},
  { 0,  2,  6,  0,  0,  0,  0,  0},
  { 1,  2,  6,  0,  0,  0,  0,  0},
  { 0,  1,  2,  6,  0,  0,  0,  0},
  { 3,  6,  0,  0,  0,  0,  0,  0},
  { 0,  3,  6,  0,  0,  0,  0,  0},
  { 1,  3,  6,  0,  0,  0,  0,  0},
  { 0,  1,  3,  6,  0,  0,  0,  0},
  { 2,  3,  6,  0,  0,  0,  0,  0},
  { 0,  2,  3,  6,  0,  0,  0,  0},
  { 1,  2,  3,  6,  0,  0,  0,  0},
  { 0,  1,  2,  3,  6,  0,  0,  0},
  { 4,  6,  0,  0,  0,  0,  0,  0},
  { 0,  4,  6,  0,  0,  0,  0,  0},
  { 1,  4,  6,  0,  0,  0,  0,  0},
  { 0,  1,  4,  6,  0,  0,  0,  0},
  { 2,  4,  6,  0,  0,  0,  0,  0},
  { 0,  2,  4,  6,  0,  0,  0,  0},
  { 1,  2,  4,  6,  0,  0,  0,  0},
  { 0,  1,  2,  4,  6,  0,  0,  0},
  { 3,  4,  6,  0,  0,  0,  0,  0},
  { 0,  3,  4,  6,  0,  0,  0,  0},
  { 1,  3,  4,  6,  0,  0,  0,  0},
  { 0,  1,  3,  4,  6,  0,  0,  0},
  { 2,  3,  4,  6,  0,  0,  0,  0},
  { 0,  2,  3,  4,  6,  0,  0,  0},
  { 1,  2,  3,  4,  6,  0,  0,  0},
  { 0,  1,  2,  3,  4,  6,  0,  0},
  { 5,  6,  0,  0,  0,  0,  0,  0},
  { 0,  5,  6,  0,  0,  0,  0,  0},
  { 1,  5,  6,  0,  0,  0,  0,  0},
  { 0,  1,  5,  6,  0,  0,  0,  0},
  { 2,  5,  6,  0,  0,  0,  0,  0},
  { 0,  2,  5,  6,  0,  0,  0,  0},
  { 1,  2,  5,  6,  0,  0,  0,  0},
  { 0,  1,  2,  5,  6,  0,  0,  0},
  { 3,  5,  6,  0,  0,  0,  0,  0},
  { 0,  3,  5,  6,  0,  0,  0,  0},
  { 1,  3,  5,  6,  0,  0,  0,  0},
  { 0,  1,  3,  5,  6,  0,  0,  0},
  { 2,  3,  5,  6,  0,  0,  0,  0},
  { 0,  2,  3,  5,  6,  0,  0,  0},
  { 1,  2,  3,  5,  6,  0,  0,  0},
  { 0,  1,  2,  3,  5,  6,  0,  0},
  { 4,  5,  6,  0,  0,  0,  0,  0},
  { 0,  4,  5,  6,  0,  0,  0,  0},
  { 1,  4,  5,  6,  0,  0,  0,  0},
  { 0,  1,  4,  5,  6,  0,  0,  0},
  { 2,  4,  5,  6,  0,  0,  0,  0},
  { 0,  2,  4,  5,  6,  0,  0,  0},
  { 1,  2,  4,  5,  6,  0,  0,  0},
  { 0,  1,  2,  4,  5,  6,  0,  0},
  { 3,  4,  5,  6,  0,  0,  0,  0},
  { 0,  3,  4,  5,  6,  0,  0,  0},
  { 1,  3,  4,  5,  6,  0,  0,  0},
  { 0,  1,  3,  4,  5,  6,  0,  0},
  { 2,  3,  4,  5,  6,  0,  0,  0},
  { 0,  2,  3,  4,  5,  6,  0,  0},
  { 1,  2,  3,  4,  5,  6,  0,  0},
  { 0,  1,  2,  3,  4,  5,  6,  0},
  { 7,  0,  0,  0,  0,  0,  0,  0},
  { 0,  7,  0,  0,  0,  0,  0,  0},
  { 1,  7,  0,  0,  0,  0,  0,  0},
  { 0,  1,  7,  0,  0,  0,  0,  0},
  { 2,  7,  0,  0,  0,  0,  0,  0},
  { 0,  2,  7,  0,  0,  0,  0,  0},
  { 1,  2,  7,  0,  0,  0,  0,  0},
  { 0,  1,  2,  7,  0,  0,  0,  0},
  { 3,  7,  0,  0,  0,  0,  0,  0},
  { 0,  3,  7,  0,  0,  0,  0,  0},
  { 1,  3,  7,  0,  0,  0,  0,  0},
  { 0,  1,  3,  7,  0,  0,  0,  0},
  { 2,  3,  7,  0,  0,  0,  0,  0},
  { 0,  2,  3,  7,  0,  0,  0,  0},
  { 1,  2,  3,  7,  0,  0,  0,  0},
  { 0,  1,  2,  3,  7,  0,  0,  0},
  { 4,  7,  0,  0,  0,  0,  0,  0},
  { 0,  4,  7,  0,  0,  0,  0,  0},
  { 1,  4,  7,  0,  0,  0,  0,  0},
  { 0,  1,  4,  7,  0,  0,  0,  0},
  { 2,  4,  7,  0,  0,  0,  0,  0},
  { 0,  2,  4,  7,  0,  0,  0,  0},
  { 1,  2,  4,  7,  0,  0,  0,  0},
  { 0,  1,  2,  4,  7,  0,  0,  0},
  { 3,  4,  7,  0,  0,  0,  0,  0},
  { 0,  3,  4,  7,  0,  0,  0,  0},
  { 1,  3,  4,  7,  0,  0,  0,  0},
  { 0,  1,  3,  4,  7,  0,  0,  0},
  { 2,  3,  4,  7,  0,  0,  0,  0},
  { 0,  2,  3,  4,  7,  0,  0,  0},
  { 1,  2,  3,  4,  7,  0,  0,  0},
  { 0,  1,  2,  3,  4,  7,  0,  0},
  { 5,  7,  0,  0,  0,  0,  0,  0},
  { 0,  5,  7,  0,  0,  0,  0,  0},
  { 1,  5,  7,  0,  0,  0,  0,  0},
  { 0,  1,  5,  7,  0,  0,  0,  0},
  { 2,  5,  7,  0,  0,  0,  0,  0},
  { 0,  2,  5,  7,  0,  0,  0,  0},
  { 1,  2,  5,  7,  0,  0,  0,  0},
  { 0,  1,  2,  5,  7,  0,  0,  0},
  { 3,  5,  7,  0,  0,  0,  0,  0},
  { 0,  3,  5,  7,  0,  0,  0,  0},
  { 1,  3,  5,  7,  0,  0,  0,  0},
  { 0,  1,  3,  5,  7,  0,  0,  0},
  { 2,  3,  5,  7,  0,  0,  0,  0},
  { 0,  2,  3,  5,  7,  0,  0,  0},
  { 1,  2,  3,  5,  7,  0,  0,  0},
  { 0,  1,  2,  3,  5,  7,  0,  0},
  { 4,  5,  7,  0,  0,  0,  0,  0},
  { 0,  4,  5,  7,  0,  0,  0,  0},
  { 1,  4,  5,  7,  0,  0,  0,  0},
  { 0,  1,  4,  5,  7,  0,  0,  0},
  { 2,  4,  5,  7,  0,  0,  0,  0},
  { 0,  2,  4,  5,  7,  0,  0,  0},
  { 1,  2,  4,  5,  7,  0,  0,  0},
  { 0,  1,  2,  4,  5,  7,  0,  0},
  { 3,  4,  5,  7,  0,  0,  0,  0},
  { 0,  3,  4,  5,  7,  0,  0,  0},
  { 1,  3,  4,  5,  7,  0,  0,  0},
  { 0,  1,  3,  4,  5,  7,  0,  0},
  { 2,  3,  4,  5,  7,  0,  0,  0},
  { 0,  2,  3,  4,  5,  7,  0,  0},
  { 1,  2,  3,  4,  5,  7,  0,  0},
  { 0,  1,  2,  3,  4,  5,  7,  0},
  { 6,  7,  0,  0,  0,  0,  0,  0},
  { 0,  6,  7,  0,  0,  0,  0,  0},
  { 1,  6,  7,  0,  0,  0,  0,  0},
  { 0,  1,  6,  7,  0,  0,  0,  0},
  { 2,  6,  7,  0,  0,  0,  0,  0},
  { 0,  2,  6,  7,  0,  0,  0,  0},
  { 1,  2,  6,  7,  0,  0,  0,  0},
  { 0,  1,  2,  6,  7,  0,  0,  0},
  { 3,  6,  7,  0,  0,  0,  0,  0},
  { 0,  3,  6,  7,  0,  0,  0,  0},
  { 1,  3,  6,  7,  0,  0,  0,  0},
  { 0,  1,  3,  6,  7,  0,  0,  0},
  { 2,  3,  6,  7,  0,  0,  0,  0},
  { 0,  2,  3,  6,  7,  0,  0,  0},
  { 1,  2,  3,  6,  7,  0,  0,  0},
  { 0,  1,  2,  3,  6,  7,  0,  0},
  { 4,  6,  7,  0,  0,  0,  0,  0},
  { 0,  4,  6,  7,  0,  0,  0,  0},
  { 1,  4,  6,  7,  0,  0,  0,  0},
  { 0,  1,  4,  6,  7,  0,  0,  0},
  { 2,  4,  6,  7,  0,  0,  0,  0},
  { 0,  2,  4,  6,  7,  0,  0,  0},
  { 1,  2,  4,  6,  7,  0,  0,  0},
  { 0,  1,  2,  4,  6,  7,  0,  0},
  { 3,  4,  6,  7,  0,  0,  0,  0},
  { 0,  3,  4,  6,  7,  0,  0,  0},
  { 1,  3,  4,  6,  7,  0,  0,  0},
  { 0,  1,  3,  4,  6,  7,  0,  0},
  { 2,  3,  4,  6,  7,  0,  0,  0},
  { 0,  2,  3,  4,  6,  7,  0,  0},
  { 1,  2,  3,  4,  6,  7,  0,  0},
  { 0,  1,  2,  3,  4,  6,  7,  0},
  { 5,  6,  7,  0,  0,  0,  0,  0},
  { 0,  5,  6,  7,  0,  0,  0,  0},
  { 1,  5,  6,  7,  0,  0,  0,  0},
  { 0,  1,  5,  6,  7,  0,  0,  0},
  { 2,  5,  6,  7,  0,  0,  0,  0},
  { 0,  2,  5,  6,  7,  0,  0,  0},
  { 1,  2,  5,  6,  7,  0,  0,  0},
  { 0,  1,  2,  5,  6,  7,  0,  0},
  { 3,  5,  6,  7,  0,  0,  0,  0},
  { 0,  3,  5,  6,  7,  0,  0,  0},
  { 1,  3,  5,  6,  7,  0,  0,  0},
  { 0,  1,  3,  5,  6,  7,  0,  0},
  { 2,  3,  5,  6,  7,  0,  0,  0},
  { 0,  2,  3,  5,  6,  7,  0,  0},
  { 1,  2,  3,  5,  6,  7,  0,  0},
  { 0,  1,  2,  3,  5,  6,  7,  0},
  { 4,  5,  6,  7,  0,  0,  0,  0},
  { 0,  4,  5,  6,  7,  0,  0,  0},
  { 1,  4,  5,  6,  7,  0,  0,  0},
  { 0,  1,  4,  5,  6,  7,  0,  0},
  { 2,  4,  5,  6,  7,  0,  0,  0},
  { 0,  2,  4,  5,  6,  7,  0,  0},
  { 1,  2,  4,  5,  6,  7,  0,  0},
  { 0,  1,  2,  4,  5,  6,  7,  0},
  { 3,  4,  5,  6,  7,  0,  0,  0},
  { 0,  3,  4,  5,  6,  7,  0,  0},
  { 1,  3,  4,  5,  6,  7,  0,  0},
  { 0,  1,  3,  4,  5,  6,  7,  0},
  { 2,  3,  4,  5,  6,  7,  0,  0},
  { 0,  2,  3,  4,  5,  6,  7,  0},
  { 1,  2,  3,  4,  5,  6,  7,  0},
  { 0,  1,  2,  3,  4,  5,  6,  7}
};

const poly nttx = {{382814741, 43923579, -113026495, 528865927, -72521175, -472785220, -484244295, -405963773, -382814741, -43923579, 113026495, -528865927, 72521175, 472785220, 484244295, 405963773, -95373355, -231657752, 419693733, 354932988, 210173399, 167562464, 473515325, -173011427, 95373355, 231657752, -419693733, -354932988, -210173399, -167562464, -473515325, 173011427, -405343018, -212266845, -235262439, 285486254, 457308136, -364668038, -365165724, -293385227, 405343018, 212266845, 235262439, -285486254, -457308136, 364668038, 365165724, 293385227, 441800469, -418935751, -311687394, -422161617, -310379038, 262878662, 454568304, -250688461, -441800469, 418935751, 311687394, 422161617, 310379038, -262878662, -454568304, 250688461, -425720413, -141999989, -295055895, 81037018, 338701692, 78331885, -65754902, 134085298, 425720413, 141999989, 295055895, -81037018, -338701692, -78331885, 65754902, -134085298, 400841409, -21467763, -71151847, -2164837, 6508487, 76696199, -293884740, 251502129, -400841409, 21467763, 71151847, 2164837, -6508487, -76696199, 293884740, -251502129, 108190920, 394320170, -100651400, -274409332, 88131428, -454290819, 182506441, -70451475, -108190920, -394320170, 100651400, 274409332, -88131428, 454290819, -182506441, 70451475, -230436531, 93990932, -432488013, -479196700, 7765600, -94141852, -213056140, -525337670, 230436531, -93990932, 432488013, 479196700, -7765600, 94141852, 213056140, 525337670}};

const poly nttx2 = {{39916768, 416926366, 397736216, 24955502, 304385919, -220562147, -312057843, 428266697, 39916768, 416926366, 397736216, 24955502, 304385919, -220562147, -312057843, 428266697, -39916768, -416926366, -397736216, -24955502, -304385919, 220562147, 312057843, -428266697, -39916768, -416926366, -397736216, -24955502, -304385919, 220562147, 312057843, -428266697, 40340982, 129757077, 160093967, 411895201, 263048769, 429963517, -384800154, 15135544, 40340982, 129757077, 160093967, 411895201, 263048769, 429963517, -384800154, 15135544, -40340982, -129757077, -160093967, -411895201, -263048769, -429963517, 384800154, -15135544, -40340982, -129757077, -160093967, -411895201, -263048769, -429963517, 384800154, -15135544, 281152895, -317922323, -529131691, -227675423, 266434172, 386284822, -383005382, 254142543, 281152895, -317922323, -529131691, -227675423, 266434172, 386284822, -383005382, 254142543, -281152895, 317922323, 529131691, 227675423, -266434172, -386284822, 383005382, -254142543, -281152895, 317922323, 529131691, 227675423, -266434172, -386284822, 383005382, -254142543, -204978956, -340279225, 231165312, 265778546, 330774173, 299880748, 468083183, -414882508, -204978956, -340279225, 231165312, 265778546, 330774173, 299880748, 468083183, -414882508, 204978956, 340279225, -231165312, -265778546, -330774173, -299880748, -468083183, 414882508, 204978956, 340279225, -231165312, -265778546, -330774173, -299880748, -468083183, 414882508}};

const poly nttx3 = {{-425720413, -21467763, 81037018, 295055895, -65754902, 251502129, 6508487, -78331885, 425720413, 21467763, -81037018, -295055895, 65754902, -251502129, -6508487, 78331885, -400841409, -141999989, 2164837, -71151847, 293884740, 134085298, 338701692, 76696199, 400841409, 141999989, -2164837, 71151847, -293884740, -134085298, -338701692, -76696199, 88131428, -94141852, -70451475, -182506441, 394320170, -108190920, -432488013, 274409332, -88131428, 94141852, 70451475, 182506441, -394320170, 108190920, 432488013, -274409332, -7765600, -454290819, 525337670, -213056140, -93990932, -230436531, -100651400, -479196700, 7765600, 454290819, -525337670, 213056140, 93990932, 230436531, 100651400, 479196700, -72521175, 167562464, -405963773, 484244295, 43923579, -382814741, 419693733, -528865927, 72521175, -167562464, 405963773, -484244295, -43923579, 382814741, -419693733, 528865927, -210173399, -472785220, 173011427, 473515325, 231657752, -95373355, -113026495, 354932988, 210173399, 472785220, -173011427, -473515325, -231657752, 95373355, 113026495, -354932988, -235262439, -422161617, 441800469, 212266845, -364668038, -457308136, 454568304, 293385227, 235262439, 422161617, -441800469, -212266845, 364668038, 457308136, -454568304, -293385227, 311687394, 285486254, -405343018, -418935751, -262878662, -310379038, -365165724, -250688461, -311687394, -285486254, 405343018, 418935751, 262878662, 310379038, 365165724, 250688461}};

const poly nttx64 = {{175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, 175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315, -175040315}};

const poly twist = {{1048572, 382814741, 39916768, -425720413, -416659981, -405343018, 281152895, 108190920, 159980059, -72521175, 40340982, 338701692, 382333025, 457308136, -204978956, 88131428, 454844763, -113026495, 304385919, -295055895, -17391882, -235262439, 266434172, -100651400, 197375900, -484244295, 263048769, -65754902, -166638639, -365165724, 330774173, 182506441, 331967329, 43923579, 397736216, -141999989, 238916051, -212266845, -529131691, 394320170, -390110669, -472785220, 160093967, 78331885, -205954134, -364668038, 231165312, -454290819, -257602554, 528865927, -312057843, 81037018, -495644362, 285486254, -383005382, -274409332, -88835585, -405963773, -384800154, 134085298, 431164203, -293385227, 468083183, -70451475, 175040315, -95373355, 416926366, 400841409, -320115552, 441800469, -317922323, -230436531, -478416174, 210173399, 129757077, 6508487, -527643241, -310379038, -340279225, 7765600, -192724796, 419693733, -220562147, -71151847, -171627748, -311687394, 386284822, -432488013, 403767085, 473515325, 429963517, -293884740, 463379170, 454568304, 299880748, -213056140, 456276144, -231657752, 24955502, -21467763, -526806357, -418935751, -227675423, 93990932, 115572728, 167562464, 411895201, 76696199, 107243165, 262878662, 265778546, -94141852, 250304896, 354932988, 428266697, -2164837, 405439465, -422161617, 254142543, -479196700, 405957924, -173011427, 15135544, 251502129, -206594448, -250688461, -414882508, -525337670}};

const poly invtwist = {{1048572, 525337670, 414882508, 250688461, 206594448, -251502129, -15135544, 173011427, -405957924, 479196700, -254142543, 422161617, -405439465, 2164837, -428266697, -354932988, -250304896, 94141852, -265778546, -262878662, -107243165, -76696199, -411895201, -167562464, -115572728, -93990932, 227675423, 418935751, 526806357, 21467763, -24955502, 231657752, -456276144, 213056140, -299880748, -454568304, -463379170, 293884740, -429963517, -473515325, -403767085, 432488013, -386284822, 311687394, 171627748, 71151847, 220562147, -419693733, 192724796, -7765600, 340279225, 310379038, 527643241, -6508487, -129757077, -210173399, 478416174, 230436531, 317922323, -441800469, 320115552, -400841409, -416926366, 95373355, -175040315, 70451475, -468083183, 293385227, -431164203, -134085298, 384800154, 405963773, 88835585, 274409332, 383005382, -285486254, 495644362, -81037018, 312057843, -528865927, 257602554, 454290819, -231165312, 364668038, 205954134, -78331885, -160093967, 472785220, 390110669, -394320170, 529131691, 212266845, -238916051, 141999989, -397736216, -43923579, -331967329, -182506441, -330774173, 365165724, 166638639, 65754902, -263048769, 484244295, -197375900, 100651400, -266434172, 235262439, 17391882, 295055895, -304385919, 113026495, -454844763, -88131428, 204978956, -457308136, -382333025, -338701692, -40340982, 72521175, -159980059, -108190920, -281152895, 405343018, 416659981, 425720413, -39916768, -382814741}};
