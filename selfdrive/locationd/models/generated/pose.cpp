#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7993353667610184364) {
   out_7993353667610184364[0] = delta_x[0] + nom_x[0];
   out_7993353667610184364[1] = delta_x[1] + nom_x[1];
   out_7993353667610184364[2] = delta_x[2] + nom_x[2];
   out_7993353667610184364[3] = delta_x[3] + nom_x[3];
   out_7993353667610184364[4] = delta_x[4] + nom_x[4];
   out_7993353667610184364[5] = delta_x[5] + nom_x[5];
   out_7993353667610184364[6] = delta_x[6] + nom_x[6];
   out_7993353667610184364[7] = delta_x[7] + nom_x[7];
   out_7993353667610184364[8] = delta_x[8] + nom_x[8];
   out_7993353667610184364[9] = delta_x[9] + nom_x[9];
   out_7993353667610184364[10] = delta_x[10] + nom_x[10];
   out_7993353667610184364[11] = delta_x[11] + nom_x[11];
   out_7993353667610184364[12] = delta_x[12] + nom_x[12];
   out_7993353667610184364[13] = delta_x[13] + nom_x[13];
   out_7993353667610184364[14] = delta_x[14] + nom_x[14];
   out_7993353667610184364[15] = delta_x[15] + nom_x[15];
   out_7993353667610184364[16] = delta_x[16] + nom_x[16];
   out_7993353667610184364[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_533608207331381553) {
   out_533608207331381553[0] = -nom_x[0] + true_x[0];
   out_533608207331381553[1] = -nom_x[1] + true_x[1];
   out_533608207331381553[2] = -nom_x[2] + true_x[2];
   out_533608207331381553[3] = -nom_x[3] + true_x[3];
   out_533608207331381553[4] = -nom_x[4] + true_x[4];
   out_533608207331381553[5] = -nom_x[5] + true_x[5];
   out_533608207331381553[6] = -nom_x[6] + true_x[6];
   out_533608207331381553[7] = -nom_x[7] + true_x[7];
   out_533608207331381553[8] = -nom_x[8] + true_x[8];
   out_533608207331381553[9] = -nom_x[9] + true_x[9];
   out_533608207331381553[10] = -nom_x[10] + true_x[10];
   out_533608207331381553[11] = -nom_x[11] + true_x[11];
   out_533608207331381553[12] = -nom_x[12] + true_x[12];
   out_533608207331381553[13] = -nom_x[13] + true_x[13];
   out_533608207331381553[14] = -nom_x[14] + true_x[14];
   out_533608207331381553[15] = -nom_x[15] + true_x[15];
   out_533608207331381553[16] = -nom_x[16] + true_x[16];
   out_533608207331381553[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5230913290931847385) {
   out_5230913290931847385[0] = 1.0;
   out_5230913290931847385[1] = 0.0;
   out_5230913290931847385[2] = 0.0;
   out_5230913290931847385[3] = 0.0;
   out_5230913290931847385[4] = 0.0;
   out_5230913290931847385[5] = 0.0;
   out_5230913290931847385[6] = 0.0;
   out_5230913290931847385[7] = 0.0;
   out_5230913290931847385[8] = 0.0;
   out_5230913290931847385[9] = 0.0;
   out_5230913290931847385[10] = 0.0;
   out_5230913290931847385[11] = 0.0;
   out_5230913290931847385[12] = 0.0;
   out_5230913290931847385[13] = 0.0;
   out_5230913290931847385[14] = 0.0;
   out_5230913290931847385[15] = 0.0;
   out_5230913290931847385[16] = 0.0;
   out_5230913290931847385[17] = 0.0;
   out_5230913290931847385[18] = 0.0;
   out_5230913290931847385[19] = 1.0;
   out_5230913290931847385[20] = 0.0;
   out_5230913290931847385[21] = 0.0;
   out_5230913290931847385[22] = 0.0;
   out_5230913290931847385[23] = 0.0;
   out_5230913290931847385[24] = 0.0;
   out_5230913290931847385[25] = 0.0;
   out_5230913290931847385[26] = 0.0;
   out_5230913290931847385[27] = 0.0;
   out_5230913290931847385[28] = 0.0;
   out_5230913290931847385[29] = 0.0;
   out_5230913290931847385[30] = 0.0;
   out_5230913290931847385[31] = 0.0;
   out_5230913290931847385[32] = 0.0;
   out_5230913290931847385[33] = 0.0;
   out_5230913290931847385[34] = 0.0;
   out_5230913290931847385[35] = 0.0;
   out_5230913290931847385[36] = 0.0;
   out_5230913290931847385[37] = 0.0;
   out_5230913290931847385[38] = 1.0;
   out_5230913290931847385[39] = 0.0;
   out_5230913290931847385[40] = 0.0;
   out_5230913290931847385[41] = 0.0;
   out_5230913290931847385[42] = 0.0;
   out_5230913290931847385[43] = 0.0;
   out_5230913290931847385[44] = 0.0;
   out_5230913290931847385[45] = 0.0;
   out_5230913290931847385[46] = 0.0;
   out_5230913290931847385[47] = 0.0;
   out_5230913290931847385[48] = 0.0;
   out_5230913290931847385[49] = 0.0;
   out_5230913290931847385[50] = 0.0;
   out_5230913290931847385[51] = 0.0;
   out_5230913290931847385[52] = 0.0;
   out_5230913290931847385[53] = 0.0;
   out_5230913290931847385[54] = 0.0;
   out_5230913290931847385[55] = 0.0;
   out_5230913290931847385[56] = 0.0;
   out_5230913290931847385[57] = 1.0;
   out_5230913290931847385[58] = 0.0;
   out_5230913290931847385[59] = 0.0;
   out_5230913290931847385[60] = 0.0;
   out_5230913290931847385[61] = 0.0;
   out_5230913290931847385[62] = 0.0;
   out_5230913290931847385[63] = 0.0;
   out_5230913290931847385[64] = 0.0;
   out_5230913290931847385[65] = 0.0;
   out_5230913290931847385[66] = 0.0;
   out_5230913290931847385[67] = 0.0;
   out_5230913290931847385[68] = 0.0;
   out_5230913290931847385[69] = 0.0;
   out_5230913290931847385[70] = 0.0;
   out_5230913290931847385[71] = 0.0;
   out_5230913290931847385[72] = 0.0;
   out_5230913290931847385[73] = 0.0;
   out_5230913290931847385[74] = 0.0;
   out_5230913290931847385[75] = 0.0;
   out_5230913290931847385[76] = 1.0;
   out_5230913290931847385[77] = 0.0;
   out_5230913290931847385[78] = 0.0;
   out_5230913290931847385[79] = 0.0;
   out_5230913290931847385[80] = 0.0;
   out_5230913290931847385[81] = 0.0;
   out_5230913290931847385[82] = 0.0;
   out_5230913290931847385[83] = 0.0;
   out_5230913290931847385[84] = 0.0;
   out_5230913290931847385[85] = 0.0;
   out_5230913290931847385[86] = 0.0;
   out_5230913290931847385[87] = 0.0;
   out_5230913290931847385[88] = 0.0;
   out_5230913290931847385[89] = 0.0;
   out_5230913290931847385[90] = 0.0;
   out_5230913290931847385[91] = 0.0;
   out_5230913290931847385[92] = 0.0;
   out_5230913290931847385[93] = 0.0;
   out_5230913290931847385[94] = 0.0;
   out_5230913290931847385[95] = 1.0;
   out_5230913290931847385[96] = 0.0;
   out_5230913290931847385[97] = 0.0;
   out_5230913290931847385[98] = 0.0;
   out_5230913290931847385[99] = 0.0;
   out_5230913290931847385[100] = 0.0;
   out_5230913290931847385[101] = 0.0;
   out_5230913290931847385[102] = 0.0;
   out_5230913290931847385[103] = 0.0;
   out_5230913290931847385[104] = 0.0;
   out_5230913290931847385[105] = 0.0;
   out_5230913290931847385[106] = 0.0;
   out_5230913290931847385[107] = 0.0;
   out_5230913290931847385[108] = 0.0;
   out_5230913290931847385[109] = 0.0;
   out_5230913290931847385[110] = 0.0;
   out_5230913290931847385[111] = 0.0;
   out_5230913290931847385[112] = 0.0;
   out_5230913290931847385[113] = 0.0;
   out_5230913290931847385[114] = 1.0;
   out_5230913290931847385[115] = 0.0;
   out_5230913290931847385[116] = 0.0;
   out_5230913290931847385[117] = 0.0;
   out_5230913290931847385[118] = 0.0;
   out_5230913290931847385[119] = 0.0;
   out_5230913290931847385[120] = 0.0;
   out_5230913290931847385[121] = 0.0;
   out_5230913290931847385[122] = 0.0;
   out_5230913290931847385[123] = 0.0;
   out_5230913290931847385[124] = 0.0;
   out_5230913290931847385[125] = 0.0;
   out_5230913290931847385[126] = 0.0;
   out_5230913290931847385[127] = 0.0;
   out_5230913290931847385[128] = 0.0;
   out_5230913290931847385[129] = 0.0;
   out_5230913290931847385[130] = 0.0;
   out_5230913290931847385[131] = 0.0;
   out_5230913290931847385[132] = 0.0;
   out_5230913290931847385[133] = 1.0;
   out_5230913290931847385[134] = 0.0;
   out_5230913290931847385[135] = 0.0;
   out_5230913290931847385[136] = 0.0;
   out_5230913290931847385[137] = 0.0;
   out_5230913290931847385[138] = 0.0;
   out_5230913290931847385[139] = 0.0;
   out_5230913290931847385[140] = 0.0;
   out_5230913290931847385[141] = 0.0;
   out_5230913290931847385[142] = 0.0;
   out_5230913290931847385[143] = 0.0;
   out_5230913290931847385[144] = 0.0;
   out_5230913290931847385[145] = 0.0;
   out_5230913290931847385[146] = 0.0;
   out_5230913290931847385[147] = 0.0;
   out_5230913290931847385[148] = 0.0;
   out_5230913290931847385[149] = 0.0;
   out_5230913290931847385[150] = 0.0;
   out_5230913290931847385[151] = 0.0;
   out_5230913290931847385[152] = 1.0;
   out_5230913290931847385[153] = 0.0;
   out_5230913290931847385[154] = 0.0;
   out_5230913290931847385[155] = 0.0;
   out_5230913290931847385[156] = 0.0;
   out_5230913290931847385[157] = 0.0;
   out_5230913290931847385[158] = 0.0;
   out_5230913290931847385[159] = 0.0;
   out_5230913290931847385[160] = 0.0;
   out_5230913290931847385[161] = 0.0;
   out_5230913290931847385[162] = 0.0;
   out_5230913290931847385[163] = 0.0;
   out_5230913290931847385[164] = 0.0;
   out_5230913290931847385[165] = 0.0;
   out_5230913290931847385[166] = 0.0;
   out_5230913290931847385[167] = 0.0;
   out_5230913290931847385[168] = 0.0;
   out_5230913290931847385[169] = 0.0;
   out_5230913290931847385[170] = 0.0;
   out_5230913290931847385[171] = 1.0;
   out_5230913290931847385[172] = 0.0;
   out_5230913290931847385[173] = 0.0;
   out_5230913290931847385[174] = 0.0;
   out_5230913290931847385[175] = 0.0;
   out_5230913290931847385[176] = 0.0;
   out_5230913290931847385[177] = 0.0;
   out_5230913290931847385[178] = 0.0;
   out_5230913290931847385[179] = 0.0;
   out_5230913290931847385[180] = 0.0;
   out_5230913290931847385[181] = 0.0;
   out_5230913290931847385[182] = 0.0;
   out_5230913290931847385[183] = 0.0;
   out_5230913290931847385[184] = 0.0;
   out_5230913290931847385[185] = 0.0;
   out_5230913290931847385[186] = 0.0;
   out_5230913290931847385[187] = 0.0;
   out_5230913290931847385[188] = 0.0;
   out_5230913290931847385[189] = 0.0;
   out_5230913290931847385[190] = 1.0;
   out_5230913290931847385[191] = 0.0;
   out_5230913290931847385[192] = 0.0;
   out_5230913290931847385[193] = 0.0;
   out_5230913290931847385[194] = 0.0;
   out_5230913290931847385[195] = 0.0;
   out_5230913290931847385[196] = 0.0;
   out_5230913290931847385[197] = 0.0;
   out_5230913290931847385[198] = 0.0;
   out_5230913290931847385[199] = 0.0;
   out_5230913290931847385[200] = 0.0;
   out_5230913290931847385[201] = 0.0;
   out_5230913290931847385[202] = 0.0;
   out_5230913290931847385[203] = 0.0;
   out_5230913290931847385[204] = 0.0;
   out_5230913290931847385[205] = 0.0;
   out_5230913290931847385[206] = 0.0;
   out_5230913290931847385[207] = 0.0;
   out_5230913290931847385[208] = 0.0;
   out_5230913290931847385[209] = 1.0;
   out_5230913290931847385[210] = 0.0;
   out_5230913290931847385[211] = 0.0;
   out_5230913290931847385[212] = 0.0;
   out_5230913290931847385[213] = 0.0;
   out_5230913290931847385[214] = 0.0;
   out_5230913290931847385[215] = 0.0;
   out_5230913290931847385[216] = 0.0;
   out_5230913290931847385[217] = 0.0;
   out_5230913290931847385[218] = 0.0;
   out_5230913290931847385[219] = 0.0;
   out_5230913290931847385[220] = 0.0;
   out_5230913290931847385[221] = 0.0;
   out_5230913290931847385[222] = 0.0;
   out_5230913290931847385[223] = 0.0;
   out_5230913290931847385[224] = 0.0;
   out_5230913290931847385[225] = 0.0;
   out_5230913290931847385[226] = 0.0;
   out_5230913290931847385[227] = 0.0;
   out_5230913290931847385[228] = 1.0;
   out_5230913290931847385[229] = 0.0;
   out_5230913290931847385[230] = 0.0;
   out_5230913290931847385[231] = 0.0;
   out_5230913290931847385[232] = 0.0;
   out_5230913290931847385[233] = 0.0;
   out_5230913290931847385[234] = 0.0;
   out_5230913290931847385[235] = 0.0;
   out_5230913290931847385[236] = 0.0;
   out_5230913290931847385[237] = 0.0;
   out_5230913290931847385[238] = 0.0;
   out_5230913290931847385[239] = 0.0;
   out_5230913290931847385[240] = 0.0;
   out_5230913290931847385[241] = 0.0;
   out_5230913290931847385[242] = 0.0;
   out_5230913290931847385[243] = 0.0;
   out_5230913290931847385[244] = 0.0;
   out_5230913290931847385[245] = 0.0;
   out_5230913290931847385[246] = 0.0;
   out_5230913290931847385[247] = 1.0;
   out_5230913290931847385[248] = 0.0;
   out_5230913290931847385[249] = 0.0;
   out_5230913290931847385[250] = 0.0;
   out_5230913290931847385[251] = 0.0;
   out_5230913290931847385[252] = 0.0;
   out_5230913290931847385[253] = 0.0;
   out_5230913290931847385[254] = 0.0;
   out_5230913290931847385[255] = 0.0;
   out_5230913290931847385[256] = 0.0;
   out_5230913290931847385[257] = 0.0;
   out_5230913290931847385[258] = 0.0;
   out_5230913290931847385[259] = 0.0;
   out_5230913290931847385[260] = 0.0;
   out_5230913290931847385[261] = 0.0;
   out_5230913290931847385[262] = 0.0;
   out_5230913290931847385[263] = 0.0;
   out_5230913290931847385[264] = 0.0;
   out_5230913290931847385[265] = 0.0;
   out_5230913290931847385[266] = 1.0;
   out_5230913290931847385[267] = 0.0;
   out_5230913290931847385[268] = 0.0;
   out_5230913290931847385[269] = 0.0;
   out_5230913290931847385[270] = 0.0;
   out_5230913290931847385[271] = 0.0;
   out_5230913290931847385[272] = 0.0;
   out_5230913290931847385[273] = 0.0;
   out_5230913290931847385[274] = 0.0;
   out_5230913290931847385[275] = 0.0;
   out_5230913290931847385[276] = 0.0;
   out_5230913290931847385[277] = 0.0;
   out_5230913290931847385[278] = 0.0;
   out_5230913290931847385[279] = 0.0;
   out_5230913290931847385[280] = 0.0;
   out_5230913290931847385[281] = 0.0;
   out_5230913290931847385[282] = 0.0;
   out_5230913290931847385[283] = 0.0;
   out_5230913290931847385[284] = 0.0;
   out_5230913290931847385[285] = 1.0;
   out_5230913290931847385[286] = 0.0;
   out_5230913290931847385[287] = 0.0;
   out_5230913290931847385[288] = 0.0;
   out_5230913290931847385[289] = 0.0;
   out_5230913290931847385[290] = 0.0;
   out_5230913290931847385[291] = 0.0;
   out_5230913290931847385[292] = 0.0;
   out_5230913290931847385[293] = 0.0;
   out_5230913290931847385[294] = 0.0;
   out_5230913290931847385[295] = 0.0;
   out_5230913290931847385[296] = 0.0;
   out_5230913290931847385[297] = 0.0;
   out_5230913290931847385[298] = 0.0;
   out_5230913290931847385[299] = 0.0;
   out_5230913290931847385[300] = 0.0;
   out_5230913290931847385[301] = 0.0;
   out_5230913290931847385[302] = 0.0;
   out_5230913290931847385[303] = 0.0;
   out_5230913290931847385[304] = 1.0;
   out_5230913290931847385[305] = 0.0;
   out_5230913290931847385[306] = 0.0;
   out_5230913290931847385[307] = 0.0;
   out_5230913290931847385[308] = 0.0;
   out_5230913290931847385[309] = 0.0;
   out_5230913290931847385[310] = 0.0;
   out_5230913290931847385[311] = 0.0;
   out_5230913290931847385[312] = 0.0;
   out_5230913290931847385[313] = 0.0;
   out_5230913290931847385[314] = 0.0;
   out_5230913290931847385[315] = 0.0;
   out_5230913290931847385[316] = 0.0;
   out_5230913290931847385[317] = 0.0;
   out_5230913290931847385[318] = 0.0;
   out_5230913290931847385[319] = 0.0;
   out_5230913290931847385[320] = 0.0;
   out_5230913290931847385[321] = 0.0;
   out_5230913290931847385[322] = 0.0;
   out_5230913290931847385[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_60436790132025778) {
   out_60436790132025778[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_60436790132025778[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_60436790132025778[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_60436790132025778[3] = dt*state[12] + state[3];
   out_60436790132025778[4] = dt*state[13] + state[4];
   out_60436790132025778[5] = dt*state[14] + state[5];
   out_60436790132025778[6] = state[6];
   out_60436790132025778[7] = state[7];
   out_60436790132025778[8] = state[8];
   out_60436790132025778[9] = state[9];
   out_60436790132025778[10] = state[10];
   out_60436790132025778[11] = state[11];
   out_60436790132025778[12] = state[12];
   out_60436790132025778[13] = state[13];
   out_60436790132025778[14] = state[14];
   out_60436790132025778[15] = state[15];
   out_60436790132025778[16] = state[16];
   out_60436790132025778[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8562706762949720732) {
   out_8562706762949720732[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8562706762949720732[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8562706762949720732[2] = 0;
   out_8562706762949720732[3] = 0;
   out_8562706762949720732[4] = 0;
   out_8562706762949720732[5] = 0;
   out_8562706762949720732[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8562706762949720732[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8562706762949720732[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8562706762949720732[9] = 0;
   out_8562706762949720732[10] = 0;
   out_8562706762949720732[11] = 0;
   out_8562706762949720732[12] = 0;
   out_8562706762949720732[13] = 0;
   out_8562706762949720732[14] = 0;
   out_8562706762949720732[15] = 0;
   out_8562706762949720732[16] = 0;
   out_8562706762949720732[17] = 0;
   out_8562706762949720732[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8562706762949720732[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8562706762949720732[20] = 0;
   out_8562706762949720732[21] = 0;
   out_8562706762949720732[22] = 0;
   out_8562706762949720732[23] = 0;
   out_8562706762949720732[24] = 0;
   out_8562706762949720732[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8562706762949720732[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8562706762949720732[27] = 0;
   out_8562706762949720732[28] = 0;
   out_8562706762949720732[29] = 0;
   out_8562706762949720732[30] = 0;
   out_8562706762949720732[31] = 0;
   out_8562706762949720732[32] = 0;
   out_8562706762949720732[33] = 0;
   out_8562706762949720732[34] = 0;
   out_8562706762949720732[35] = 0;
   out_8562706762949720732[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8562706762949720732[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8562706762949720732[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8562706762949720732[39] = 0;
   out_8562706762949720732[40] = 0;
   out_8562706762949720732[41] = 0;
   out_8562706762949720732[42] = 0;
   out_8562706762949720732[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8562706762949720732[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8562706762949720732[45] = 0;
   out_8562706762949720732[46] = 0;
   out_8562706762949720732[47] = 0;
   out_8562706762949720732[48] = 0;
   out_8562706762949720732[49] = 0;
   out_8562706762949720732[50] = 0;
   out_8562706762949720732[51] = 0;
   out_8562706762949720732[52] = 0;
   out_8562706762949720732[53] = 0;
   out_8562706762949720732[54] = 0;
   out_8562706762949720732[55] = 0;
   out_8562706762949720732[56] = 0;
   out_8562706762949720732[57] = 1;
   out_8562706762949720732[58] = 0;
   out_8562706762949720732[59] = 0;
   out_8562706762949720732[60] = 0;
   out_8562706762949720732[61] = 0;
   out_8562706762949720732[62] = 0;
   out_8562706762949720732[63] = 0;
   out_8562706762949720732[64] = 0;
   out_8562706762949720732[65] = 0;
   out_8562706762949720732[66] = dt;
   out_8562706762949720732[67] = 0;
   out_8562706762949720732[68] = 0;
   out_8562706762949720732[69] = 0;
   out_8562706762949720732[70] = 0;
   out_8562706762949720732[71] = 0;
   out_8562706762949720732[72] = 0;
   out_8562706762949720732[73] = 0;
   out_8562706762949720732[74] = 0;
   out_8562706762949720732[75] = 0;
   out_8562706762949720732[76] = 1;
   out_8562706762949720732[77] = 0;
   out_8562706762949720732[78] = 0;
   out_8562706762949720732[79] = 0;
   out_8562706762949720732[80] = 0;
   out_8562706762949720732[81] = 0;
   out_8562706762949720732[82] = 0;
   out_8562706762949720732[83] = 0;
   out_8562706762949720732[84] = 0;
   out_8562706762949720732[85] = dt;
   out_8562706762949720732[86] = 0;
   out_8562706762949720732[87] = 0;
   out_8562706762949720732[88] = 0;
   out_8562706762949720732[89] = 0;
   out_8562706762949720732[90] = 0;
   out_8562706762949720732[91] = 0;
   out_8562706762949720732[92] = 0;
   out_8562706762949720732[93] = 0;
   out_8562706762949720732[94] = 0;
   out_8562706762949720732[95] = 1;
   out_8562706762949720732[96] = 0;
   out_8562706762949720732[97] = 0;
   out_8562706762949720732[98] = 0;
   out_8562706762949720732[99] = 0;
   out_8562706762949720732[100] = 0;
   out_8562706762949720732[101] = 0;
   out_8562706762949720732[102] = 0;
   out_8562706762949720732[103] = 0;
   out_8562706762949720732[104] = dt;
   out_8562706762949720732[105] = 0;
   out_8562706762949720732[106] = 0;
   out_8562706762949720732[107] = 0;
   out_8562706762949720732[108] = 0;
   out_8562706762949720732[109] = 0;
   out_8562706762949720732[110] = 0;
   out_8562706762949720732[111] = 0;
   out_8562706762949720732[112] = 0;
   out_8562706762949720732[113] = 0;
   out_8562706762949720732[114] = 1;
   out_8562706762949720732[115] = 0;
   out_8562706762949720732[116] = 0;
   out_8562706762949720732[117] = 0;
   out_8562706762949720732[118] = 0;
   out_8562706762949720732[119] = 0;
   out_8562706762949720732[120] = 0;
   out_8562706762949720732[121] = 0;
   out_8562706762949720732[122] = 0;
   out_8562706762949720732[123] = 0;
   out_8562706762949720732[124] = 0;
   out_8562706762949720732[125] = 0;
   out_8562706762949720732[126] = 0;
   out_8562706762949720732[127] = 0;
   out_8562706762949720732[128] = 0;
   out_8562706762949720732[129] = 0;
   out_8562706762949720732[130] = 0;
   out_8562706762949720732[131] = 0;
   out_8562706762949720732[132] = 0;
   out_8562706762949720732[133] = 1;
   out_8562706762949720732[134] = 0;
   out_8562706762949720732[135] = 0;
   out_8562706762949720732[136] = 0;
   out_8562706762949720732[137] = 0;
   out_8562706762949720732[138] = 0;
   out_8562706762949720732[139] = 0;
   out_8562706762949720732[140] = 0;
   out_8562706762949720732[141] = 0;
   out_8562706762949720732[142] = 0;
   out_8562706762949720732[143] = 0;
   out_8562706762949720732[144] = 0;
   out_8562706762949720732[145] = 0;
   out_8562706762949720732[146] = 0;
   out_8562706762949720732[147] = 0;
   out_8562706762949720732[148] = 0;
   out_8562706762949720732[149] = 0;
   out_8562706762949720732[150] = 0;
   out_8562706762949720732[151] = 0;
   out_8562706762949720732[152] = 1;
   out_8562706762949720732[153] = 0;
   out_8562706762949720732[154] = 0;
   out_8562706762949720732[155] = 0;
   out_8562706762949720732[156] = 0;
   out_8562706762949720732[157] = 0;
   out_8562706762949720732[158] = 0;
   out_8562706762949720732[159] = 0;
   out_8562706762949720732[160] = 0;
   out_8562706762949720732[161] = 0;
   out_8562706762949720732[162] = 0;
   out_8562706762949720732[163] = 0;
   out_8562706762949720732[164] = 0;
   out_8562706762949720732[165] = 0;
   out_8562706762949720732[166] = 0;
   out_8562706762949720732[167] = 0;
   out_8562706762949720732[168] = 0;
   out_8562706762949720732[169] = 0;
   out_8562706762949720732[170] = 0;
   out_8562706762949720732[171] = 1;
   out_8562706762949720732[172] = 0;
   out_8562706762949720732[173] = 0;
   out_8562706762949720732[174] = 0;
   out_8562706762949720732[175] = 0;
   out_8562706762949720732[176] = 0;
   out_8562706762949720732[177] = 0;
   out_8562706762949720732[178] = 0;
   out_8562706762949720732[179] = 0;
   out_8562706762949720732[180] = 0;
   out_8562706762949720732[181] = 0;
   out_8562706762949720732[182] = 0;
   out_8562706762949720732[183] = 0;
   out_8562706762949720732[184] = 0;
   out_8562706762949720732[185] = 0;
   out_8562706762949720732[186] = 0;
   out_8562706762949720732[187] = 0;
   out_8562706762949720732[188] = 0;
   out_8562706762949720732[189] = 0;
   out_8562706762949720732[190] = 1;
   out_8562706762949720732[191] = 0;
   out_8562706762949720732[192] = 0;
   out_8562706762949720732[193] = 0;
   out_8562706762949720732[194] = 0;
   out_8562706762949720732[195] = 0;
   out_8562706762949720732[196] = 0;
   out_8562706762949720732[197] = 0;
   out_8562706762949720732[198] = 0;
   out_8562706762949720732[199] = 0;
   out_8562706762949720732[200] = 0;
   out_8562706762949720732[201] = 0;
   out_8562706762949720732[202] = 0;
   out_8562706762949720732[203] = 0;
   out_8562706762949720732[204] = 0;
   out_8562706762949720732[205] = 0;
   out_8562706762949720732[206] = 0;
   out_8562706762949720732[207] = 0;
   out_8562706762949720732[208] = 0;
   out_8562706762949720732[209] = 1;
   out_8562706762949720732[210] = 0;
   out_8562706762949720732[211] = 0;
   out_8562706762949720732[212] = 0;
   out_8562706762949720732[213] = 0;
   out_8562706762949720732[214] = 0;
   out_8562706762949720732[215] = 0;
   out_8562706762949720732[216] = 0;
   out_8562706762949720732[217] = 0;
   out_8562706762949720732[218] = 0;
   out_8562706762949720732[219] = 0;
   out_8562706762949720732[220] = 0;
   out_8562706762949720732[221] = 0;
   out_8562706762949720732[222] = 0;
   out_8562706762949720732[223] = 0;
   out_8562706762949720732[224] = 0;
   out_8562706762949720732[225] = 0;
   out_8562706762949720732[226] = 0;
   out_8562706762949720732[227] = 0;
   out_8562706762949720732[228] = 1;
   out_8562706762949720732[229] = 0;
   out_8562706762949720732[230] = 0;
   out_8562706762949720732[231] = 0;
   out_8562706762949720732[232] = 0;
   out_8562706762949720732[233] = 0;
   out_8562706762949720732[234] = 0;
   out_8562706762949720732[235] = 0;
   out_8562706762949720732[236] = 0;
   out_8562706762949720732[237] = 0;
   out_8562706762949720732[238] = 0;
   out_8562706762949720732[239] = 0;
   out_8562706762949720732[240] = 0;
   out_8562706762949720732[241] = 0;
   out_8562706762949720732[242] = 0;
   out_8562706762949720732[243] = 0;
   out_8562706762949720732[244] = 0;
   out_8562706762949720732[245] = 0;
   out_8562706762949720732[246] = 0;
   out_8562706762949720732[247] = 1;
   out_8562706762949720732[248] = 0;
   out_8562706762949720732[249] = 0;
   out_8562706762949720732[250] = 0;
   out_8562706762949720732[251] = 0;
   out_8562706762949720732[252] = 0;
   out_8562706762949720732[253] = 0;
   out_8562706762949720732[254] = 0;
   out_8562706762949720732[255] = 0;
   out_8562706762949720732[256] = 0;
   out_8562706762949720732[257] = 0;
   out_8562706762949720732[258] = 0;
   out_8562706762949720732[259] = 0;
   out_8562706762949720732[260] = 0;
   out_8562706762949720732[261] = 0;
   out_8562706762949720732[262] = 0;
   out_8562706762949720732[263] = 0;
   out_8562706762949720732[264] = 0;
   out_8562706762949720732[265] = 0;
   out_8562706762949720732[266] = 1;
   out_8562706762949720732[267] = 0;
   out_8562706762949720732[268] = 0;
   out_8562706762949720732[269] = 0;
   out_8562706762949720732[270] = 0;
   out_8562706762949720732[271] = 0;
   out_8562706762949720732[272] = 0;
   out_8562706762949720732[273] = 0;
   out_8562706762949720732[274] = 0;
   out_8562706762949720732[275] = 0;
   out_8562706762949720732[276] = 0;
   out_8562706762949720732[277] = 0;
   out_8562706762949720732[278] = 0;
   out_8562706762949720732[279] = 0;
   out_8562706762949720732[280] = 0;
   out_8562706762949720732[281] = 0;
   out_8562706762949720732[282] = 0;
   out_8562706762949720732[283] = 0;
   out_8562706762949720732[284] = 0;
   out_8562706762949720732[285] = 1;
   out_8562706762949720732[286] = 0;
   out_8562706762949720732[287] = 0;
   out_8562706762949720732[288] = 0;
   out_8562706762949720732[289] = 0;
   out_8562706762949720732[290] = 0;
   out_8562706762949720732[291] = 0;
   out_8562706762949720732[292] = 0;
   out_8562706762949720732[293] = 0;
   out_8562706762949720732[294] = 0;
   out_8562706762949720732[295] = 0;
   out_8562706762949720732[296] = 0;
   out_8562706762949720732[297] = 0;
   out_8562706762949720732[298] = 0;
   out_8562706762949720732[299] = 0;
   out_8562706762949720732[300] = 0;
   out_8562706762949720732[301] = 0;
   out_8562706762949720732[302] = 0;
   out_8562706762949720732[303] = 0;
   out_8562706762949720732[304] = 1;
   out_8562706762949720732[305] = 0;
   out_8562706762949720732[306] = 0;
   out_8562706762949720732[307] = 0;
   out_8562706762949720732[308] = 0;
   out_8562706762949720732[309] = 0;
   out_8562706762949720732[310] = 0;
   out_8562706762949720732[311] = 0;
   out_8562706762949720732[312] = 0;
   out_8562706762949720732[313] = 0;
   out_8562706762949720732[314] = 0;
   out_8562706762949720732[315] = 0;
   out_8562706762949720732[316] = 0;
   out_8562706762949720732[317] = 0;
   out_8562706762949720732[318] = 0;
   out_8562706762949720732[319] = 0;
   out_8562706762949720732[320] = 0;
   out_8562706762949720732[321] = 0;
   out_8562706762949720732[322] = 0;
   out_8562706762949720732[323] = 1;
}
void h_4(double *state, double *unused, double *out_493571647291527942) {
   out_493571647291527942[0] = state[6] + state[9];
   out_493571647291527942[1] = state[7] + state[10];
   out_493571647291527942[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6428860772814745489) {
   out_6428860772814745489[0] = 0;
   out_6428860772814745489[1] = 0;
   out_6428860772814745489[2] = 0;
   out_6428860772814745489[3] = 0;
   out_6428860772814745489[4] = 0;
   out_6428860772814745489[5] = 0;
   out_6428860772814745489[6] = 1;
   out_6428860772814745489[7] = 0;
   out_6428860772814745489[8] = 0;
   out_6428860772814745489[9] = 1;
   out_6428860772814745489[10] = 0;
   out_6428860772814745489[11] = 0;
   out_6428860772814745489[12] = 0;
   out_6428860772814745489[13] = 0;
   out_6428860772814745489[14] = 0;
   out_6428860772814745489[15] = 0;
   out_6428860772814745489[16] = 0;
   out_6428860772814745489[17] = 0;
   out_6428860772814745489[18] = 0;
   out_6428860772814745489[19] = 0;
   out_6428860772814745489[20] = 0;
   out_6428860772814745489[21] = 0;
   out_6428860772814745489[22] = 0;
   out_6428860772814745489[23] = 0;
   out_6428860772814745489[24] = 0;
   out_6428860772814745489[25] = 1;
   out_6428860772814745489[26] = 0;
   out_6428860772814745489[27] = 0;
   out_6428860772814745489[28] = 1;
   out_6428860772814745489[29] = 0;
   out_6428860772814745489[30] = 0;
   out_6428860772814745489[31] = 0;
   out_6428860772814745489[32] = 0;
   out_6428860772814745489[33] = 0;
   out_6428860772814745489[34] = 0;
   out_6428860772814745489[35] = 0;
   out_6428860772814745489[36] = 0;
   out_6428860772814745489[37] = 0;
   out_6428860772814745489[38] = 0;
   out_6428860772814745489[39] = 0;
   out_6428860772814745489[40] = 0;
   out_6428860772814745489[41] = 0;
   out_6428860772814745489[42] = 0;
   out_6428860772814745489[43] = 0;
   out_6428860772814745489[44] = 1;
   out_6428860772814745489[45] = 0;
   out_6428860772814745489[46] = 0;
   out_6428860772814745489[47] = 1;
   out_6428860772814745489[48] = 0;
   out_6428860772814745489[49] = 0;
   out_6428860772814745489[50] = 0;
   out_6428860772814745489[51] = 0;
   out_6428860772814745489[52] = 0;
   out_6428860772814745489[53] = 0;
}
void h_10(double *state, double *unused, double *out_7477536671061017990) {
   out_7477536671061017990[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7477536671061017990[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7477536671061017990[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3483601252945400253) {
   out_3483601252945400253[0] = 0;
   out_3483601252945400253[1] = 9.8100000000000005*cos(state[1]);
   out_3483601252945400253[2] = 0;
   out_3483601252945400253[3] = 0;
   out_3483601252945400253[4] = -state[8];
   out_3483601252945400253[5] = state[7];
   out_3483601252945400253[6] = 0;
   out_3483601252945400253[7] = state[5];
   out_3483601252945400253[8] = -state[4];
   out_3483601252945400253[9] = 0;
   out_3483601252945400253[10] = 0;
   out_3483601252945400253[11] = 0;
   out_3483601252945400253[12] = 1;
   out_3483601252945400253[13] = 0;
   out_3483601252945400253[14] = 0;
   out_3483601252945400253[15] = 1;
   out_3483601252945400253[16] = 0;
   out_3483601252945400253[17] = 0;
   out_3483601252945400253[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3483601252945400253[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3483601252945400253[20] = 0;
   out_3483601252945400253[21] = state[8];
   out_3483601252945400253[22] = 0;
   out_3483601252945400253[23] = -state[6];
   out_3483601252945400253[24] = -state[5];
   out_3483601252945400253[25] = 0;
   out_3483601252945400253[26] = state[3];
   out_3483601252945400253[27] = 0;
   out_3483601252945400253[28] = 0;
   out_3483601252945400253[29] = 0;
   out_3483601252945400253[30] = 0;
   out_3483601252945400253[31] = 1;
   out_3483601252945400253[32] = 0;
   out_3483601252945400253[33] = 0;
   out_3483601252945400253[34] = 1;
   out_3483601252945400253[35] = 0;
   out_3483601252945400253[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3483601252945400253[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3483601252945400253[38] = 0;
   out_3483601252945400253[39] = -state[7];
   out_3483601252945400253[40] = state[6];
   out_3483601252945400253[41] = 0;
   out_3483601252945400253[42] = state[4];
   out_3483601252945400253[43] = -state[3];
   out_3483601252945400253[44] = 0;
   out_3483601252945400253[45] = 0;
   out_3483601252945400253[46] = 0;
   out_3483601252945400253[47] = 0;
   out_3483601252945400253[48] = 0;
   out_3483601252945400253[49] = 0;
   out_3483601252945400253[50] = 1;
   out_3483601252945400253[51] = 0;
   out_3483601252945400253[52] = 0;
   out_3483601252945400253[53] = 1;
}
void h_13(double *state, double *unused, double *out_2889929992082413223) {
   out_2889929992082413223[0] = state[3];
   out_2889929992082413223[1] = state[4];
   out_2889929992082413223[2] = state[5];
}
void H_13(double *state, double *unused, double *out_8805609475562473326) {
   out_8805609475562473326[0] = 0;
   out_8805609475562473326[1] = 0;
   out_8805609475562473326[2] = 0;
   out_8805609475562473326[3] = 1;
   out_8805609475562473326[4] = 0;
   out_8805609475562473326[5] = 0;
   out_8805609475562473326[6] = 0;
   out_8805609475562473326[7] = 0;
   out_8805609475562473326[8] = 0;
   out_8805609475562473326[9] = 0;
   out_8805609475562473326[10] = 0;
   out_8805609475562473326[11] = 0;
   out_8805609475562473326[12] = 0;
   out_8805609475562473326[13] = 0;
   out_8805609475562473326[14] = 0;
   out_8805609475562473326[15] = 0;
   out_8805609475562473326[16] = 0;
   out_8805609475562473326[17] = 0;
   out_8805609475562473326[18] = 0;
   out_8805609475562473326[19] = 0;
   out_8805609475562473326[20] = 0;
   out_8805609475562473326[21] = 0;
   out_8805609475562473326[22] = 1;
   out_8805609475562473326[23] = 0;
   out_8805609475562473326[24] = 0;
   out_8805609475562473326[25] = 0;
   out_8805609475562473326[26] = 0;
   out_8805609475562473326[27] = 0;
   out_8805609475562473326[28] = 0;
   out_8805609475562473326[29] = 0;
   out_8805609475562473326[30] = 0;
   out_8805609475562473326[31] = 0;
   out_8805609475562473326[32] = 0;
   out_8805609475562473326[33] = 0;
   out_8805609475562473326[34] = 0;
   out_8805609475562473326[35] = 0;
   out_8805609475562473326[36] = 0;
   out_8805609475562473326[37] = 0;
   out_8805609475562473326[38] = 0;
   out_8805609475562473326[39] = 0;
   out_8805609475562473326[40] = 0;
   out_8805609475562473326[41] = 1;
   out_8805609475562473326[42] = 0;
   out_8805609475562473326[43] = 0;
   out_8805609475562473326[44] = 0;
   out_8805609475562473326[45] = 0;
   out_8805609475562473326[46] = 0;
   out_8805609475562473326[47] = 0;
   out_8805609475562473326[48] = 0;
   out_8805609475562473326[49] = 0;
   out_8805609475562473326[50] = 0;
   out_8805609475562473326[51] = 0;
   out_8805609475562473326[52] = 0;
   out_8805609475562473326[53] = 0;
}
void h_14(double *state, double *unused, double *out_207203314381018955) {
   out_207203314381018955[0] = state[6];
   out_207203314381018955[1] = state[7];
   out_207203314381018955[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3346072340519373193) {
   out_3346072340519373193[0] = 0;
   out_3346072340519373193[1] = 0;
   out_3346072340519373193[2] = 0;
   out_3346072340519373193[3] = 0;
   out_3346072340519373193[4] = 0;
   out_3346072340519373193[5] = 0;
   out_3346072340519373193[6] = 1;
   out_3346072340519373193[7] = 0;
   out_3346072340519373193[8] = 0;
   out_3346072340519373193[9] = 0;
   out_3346072340519373193[10] = 0;
   out_3346072340519373193[11] = 0;
   out_3346072340519373193[12] = 0;
   out_3346072340519373193[13] = 0;
   out_3346072340519373193[14] = 0;
   out_3346072340519373193[15] = 0;
   out_3346072340519373193[16] = 0;
   out_3346072340519373193[17] = 0;
   out_3346072340519373193[18] = 0;
   out_3346072340519373193[19] = 0;
   out_3346072340519373193[20] = 0;
   out_3346072340519373193[21] = 0;
   out_3346072340519373193[22] = 0;
   out_3346072340519373193[23] = 0;
   out_3346072340519373193[24] = 0;
   out_3346072340519373193[25] = 1;
   out_3346072340519373193[26] = 0;
   out_3346072340519373193[27] = 0;
   out_3346072340519373193[28] = 0;
   out_3346072340519373193[29] = 0;
   out_3346072340519373193[30] = 0;
   out_3346072340519373193[31] = 0;
   out_3346072340519373193[32] = 0;
   out_3346072340519373193[33] = 0;
   out_3346072340519373193[34] = 0;
   out_3346072340519373193[35] = 0;
   out_3346072340519373193[36] = 0;
   out_3346072340519373193[37] = 0;
   out_3346072340519373193[38] = 0;
   out_3346072340519373193[39] = 0;
   out_3346072340519373193[40] = 0;
   out_3346072340519373193[41] = 0;
   out_3346072340519373193[42] = 0;
   out_3346072340519373193[43] = 0;
   out_3346072340519373193[44] = 1;
   out_3346072340519373193[45] = 0;
   out_3346072340519373193[46] = 0;
   out_3346072340519373193[47] = 0;
   out_3346072340519373193[48] = 0;
   out_3346072340519373193[49] = 0;
   out_3346072340519373193[50] = 0;
   out_3346072340519373193[51] = 0;
   out_3346072340519373193[52] = 0;
   out_3346072340519373193[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_7993353667610184364) {
  err_fun(nom_x, delta_x, out_7993353667610184364);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_533608207331381553) {
  inv_err_fun(nom_x, true_x, out_533608207331381553);
}
void pose_H_mod_fun(double *state, double *out_5230913290931847385) {
  H_mod_fun(state, out_5230913290931847385);
}
void pose_f_fun(double *state, double dt, double *out_60436790132025778) {
  f_fun(state,  dt, out_60436790132025778);
}
void pose_F_fun(double *state, double dt, double *out_8562706762949720732) {
  F_fun(state,  dt, out_8562706762949720732);
}
void pose_h_4(double *state, double *unused, double *out_493571647291527942) {
  h_4(state, unused, out_493571647291527942);
}
void pose_H_4(double *state, double *unused, double *out_6428860772814745489) {
  H_4(state, unused, out_6428860772814745489);
}
void pose_h_10(double *state, double *unused, double *out_7477536671061017990) {
  h_10(state, unused, out_7477536671061017990);
}
void pose_H_10(double *state, double *unused, double *out_3483601252945400253) {
  H_10(state, unused, out_3483601252945400253);
}
void pose_h_13(double *state, double *unused, double *out_2889929992082413223) {
  h_13(state, unused, out_2889929992082413223);
}
void pose_H_13(double *state, double *unused, double *out_8805609475562473326) {
  H_13(state, unused, out_8805609475562473326);
}
void pose_h_14(double *state, double *unused, double *out_207203314381018955) {
  h_14(state, unused, out_207203314381018955);
}
void pose_H_14(double *state, double *unused, double *out_3346072340519373193) {
  H_14(state, unused, out_3346072340519373193);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
