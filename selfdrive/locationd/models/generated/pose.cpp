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
void err_fun(double *nom_x, double *delta_x, double *out_3328634486354213070) {
   out_3328634486354213070[0] = delta_x[0] + nom_x[0];
   out_3328634486354213070[1] = delta_x[1] + nom_x[1];
   out_3328634486354213070[2] = delta_x[2] + nom_x[2];
   out_3328634486354213070[3] = delta_x[3] + nom_x[3];
   out_3328634486354213070[4] = delta_x[4] + nom_x[4];
   out_3328634486354213070[5] = delta_x[5] + nom_x[5];
   out_3328634486354213070[6] = delta_x[6] + nom_x[6];
   out_3328634486354213070[7] = delta_x[7] + nom_x[7];
   out_3328634486354213070[8] = delta_x[8] + nom_x[8];
   out_3328634486354213070[9] = delta_x[9] + nom_x[9];
   out_3328634486354213070[10] = delta_x[10] + nom_x[10];
   out_3328634486354213070[11] = delta_x[11] + nom_x[11];
   out_3328634486354213070[12] = delta_x[12] + nom_x[12];
   out_3328634486354213070[13] = delta_x[13] + nom_x[13];
   out_3328634486354213070[14] = delta_x[14] + nom_x[14];
   out_3328634486354213070[15] = delta_x[15] + nom_x[15];
   out_3328634486354213070[16] = delta_x[16] + nom_x[16];
   out_3328634486354213070[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2068367058924519839) {
   out_2068367058924519839[0] = -nom_x[0] + true_x[0];
   out_2068367058924519839[1] = -nom_x[1] + true_x[1];
   out_2068367058924519839[2] = -nom_x[2] + true_x[2];
   out_2068367058924519839[3] = -nom_x[3] + true_x[3];
   out_2068367058924519839[4] = -nom_x[4] + true_x[4];
   out_2068367058924519839[5] = -nom_x[5] + true_x[5];
   out_2068367058924519839[6] = -nom_x[6] + true_x[6];
   out_2068367058924519839[7] = -nom_x[7] + true_x[7];
   out_2068367058924519839[8] = -nom_x[8] + true_x[8];
   out_2068367058924519839[9] = -nom_x[9] + true_x[9];
   out_2068367058924519839[10] = -nom_x[10] + true_x[10];
   out_2068367058924519839[11] = -nom_x[11] + true_x[11];
   out_2068367058924519839[12] = -nom_x[12] + true_x[12];
   out_2068367058924519839[13] = -nom_x[13] + true_x[13];
   out_2068367058924519839[14] = -nom_x[14] + true_x[14];
   out_2068367058924519839[15] = -nom_x[15] + true_x[15];
   out_2068367058924519839[16] = -nom_x[16] + true_x[16];
   out_2068367058924519839[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5273281981643743211) {
   out_5273281981643743211[0] = 1.0;
   out_5273281981643743211[1] = 0.0;
   out_5273281981643743211[2] = 0.0;
   out_5273281981643743211[3] = 0.0;
   out_5273281981643743211[4] = 0.0;
   out_5273281981643743211[5] = 0.0;
   out_5273281981643743211[6] = 0.0;
   out_5273281981643743211[7] = 0.0;
   out_5273281981643743211[8] = 0.0;
   out_5273281981643743211[9] = 0.0;
   out_5273281981643743211[10] = 0.0;
   out_5273281981643743211[11] = 0.0;
   out_5273281981643743211[12] = 0.0;
   out_5273281981643743211[13] = 0.0;
   out_5273281981643743211[14] = 0.0;
   out_5273281981643743211[15] = 0.0;
   out_5273281981643743211[16] = 0.0;
   out_5273281981643743211[17] = 0.0;
   out_5273281981643743211[18] = 0.0;
   out_5273281981643743211[19] = 1.0;
   out_5273281981643743211[20] = 0.0;
   out_5273281981643743211[21] = 0.0;
   out_5273281981643743211[22] = 0.0;
   out_5273281981643743211[23] = 0.0;
   out_5273281981643743211[24] = 0.0;
   out_5273281981643743211[25] = 0.0;
   out_5273281981643743211[26] = 0.0;
   out_5273281981643743211[27] = 0.0;
   out_5273281981643743211[28] = 0.0;
   out_5273281981643743211[29] = 0.0;
   out_5273281981643743211[30] = 0.0;
   out_5273281981643743211[31] = 0.0;
   out_5273281981643743211[32] = 0.0;
   out_5273281981643743211[33] = 0.0;
   out_5273281981643743211[34] = 0.0;
   out_5273281981643743211[35] = 0.0;
   out_5273281981643743211[36] = 0.0;
   out_5273281981643743211[37] = 0.0;
   out_5273281981643743211[38] = 1.0;
   out_5273281981643743211[39] = 0.0;
   out_5273281981643743211[40] = 0.0;
   out_5273281981643743211[41] = 0.0;
   out_5273281981643743211[42] = 0.0;
   out_5273281981643743211[43] = 0.0;
   out_5273281981643743211[44] = 0.0;
   out_5273281981643743211[45] = 0.0;
   out_5273281981643743211[46] = 0.0;
   out_5273281981643743211[47] = 0.0;
   out_5273281981643743211[48] = 0.0;
   out_5273281981643743211[49] = 0.0;
   out_5273281981643743211[50] = 0.0;
   out_5273281981643743211[51] = 0.0;
   out_5273281981643743211[52] = 0.0;
   out_5273281981643743211[53] = 0.0;
   out_5273281981643743211[54] = 0.0;
   out_5273281981643743211[55] = 0.0;
   out_5273281981643743211[56] = 0.0;
   out_5273281981643743211[57] = 1.0;
   out_5273281981643743211[58] = 0.0;
   out_5273281981643743211[59] = 0.0;
   out_5273281981643743211[60] = 0.0;
   out_5273281981643743211[61] = 0.0;
   out_5273281981643743211[62] = 0.0;
   out_5273281981643743211[63] = 0.0;
   out_5273281981643743211[64] = 0.0;
   out_5273281981643743211[65] = 0.0;
   out_5273281981643743211[66] = 0.0;
   out_5273281981643743211[67] = 0.0;
   out_5273281981643743211[68] = 0.0;
   out_5273281981643743211[69] = 0.0;
   out_5273281981643743211[70] = 0.0;
   out_5273281981643743211[71] = 0.0;
   out_5273281981643743211[72] = 0.0;
   out_5273281981643743211[73] = 0.0;
   out_5273281981643743211[74] = 0.0;
   out_5273281981643743211[75] = 0.0;
   out_5273281981643743211[76] = 1.0;
   out_5273281981643743211[77] = 0.0;
   out_5273281981643743211[78] = 0.0;
   out_5273281981643743211[79] = 0.0;
   out_5273281981643743211[80] = 0.0;
   out_5273281981643743211[81] = 0.0;
   out_5273281981643743211[82] = 0.0;
   out_5273281981643743211[83] = 0.0;
   out_5273281981643743211[84] = 0.0;
   out_5273281981643743211[85] = 0.0;
   out_5273281981643743211[86] = 0.0;
   out_5273281981643743211[87] = 0.0;
   out_5273281981643743211[88] = 0.0;
   out_5273281981643743211[89] = 0.0;
   out_5273281981643743211[90] = 0.0;
   out_5273281981643743211[91] = 0.0;
   out_5273281981643743211[92] = 0.0;
   out_5273281981643743211[93] = 0.0;
   out_5273281981643743211[94] = 0.0;
   out_5273281981643743211[95] = 1.0;
   out_5273281981643743211[96] = 0.0;
   out_5273281981643743211[97] = 0.0;
   out_5273281981643743211[98] = 0.0;
   out_5273281981643743211[99] = 0.0;
   out_5273281981643743211[100] = 0.0;
   out_5273281981643743211[101] = 0.0;
   out_5273281981643743211[102] = 0.0;
   out_5273281981643743211[103] = 0.0;
   out_5273281981643743211[104] = 0.0;
   out_5273281981643743211[105] = 0.0;
   out_5273281981643743211[106] = 0.0;
   out_5273281981643743211[107] = 0.0;
   out_5273281981643743211[108] = 0.0;
   out_5273281981643743211[109] = 0.0;
   out_5273281981643743211[110] = 0.0;
   out_5273281981643743211[111] = 0.0;
   out_5273281981643743211[112] = 0.0;
   out_5273281981643743211[113] = 0.0;
   out_5273281981643743211[114] = 1.0;
   out_5273281981643743211[115] = 0.0;
   out_5273281981643743211[116] = 0.0;
   out_5273281981643743211[117] = 0.0;
   out_5273281981643743211[118] = 0.0;
   out_5273281981643743211[119] = 0.0;
   out_5273281981643743211[120] = 0.0;
   out_5273281981643743211[121] = 0.0;
   out_5273281981643743211[122] = 0.0;
   out_5273281981643743211[123] = 0.0;
   out_5273281981643743211[124] = 0.0;
   out_5273281981643743211[125] = 0.0;
   out_5273281981643743211[126] = 0.0;
   out_5273281981643743211[127] = 0.0;
   out_5273281981643743211[128] = 0.0;
   out_5273281981643743211[129] = 0.0;
   out_5273281981643743211[130] = 0.0;
   out_5273281981643743211[131] = 0.0;
   out_5273281981643743211[132] = 0.0;
   out_5273281981643743211[133] = 1.0;
   out_5273281981643743211[134] = 0.0;
   out_5273281981643743211[135] = 0.0;
   out_5273281981643743211[136] = 0.0;
   out_5273281981643743211[137] = 0.0;
   out_5273281981643743211[138] = 0.0;
   out_5273281981643743211[139] = 0.0;
   out_5273281981643743211[140] = 0.0;
   out_5273281981643743211[141] = 0.0;
   out_5273281981643743211[142] = 0.0;
   out_5273281981643743211[143] = 0.0;
   out_5273281981643743211[144] = 0.0;
   out_5273281981643743211[145] = 0.0;
   out_5273281981643743211[146] = 0.0;
   out_5273281981643743211[147] = 0.0;
   out_5273281981643743211[148] = 0.0;
   out_5273281981643743211[149] = 0.0;
   out_5273281981643743211[150] = 0.0;
   out_5273281981643743211[151] = 0.0;
   out_5273281981643743211[152] = 1.0;
   out_5273281981643743211[153] = 0.0;
   out_5273281981643743211[154] = 0.0;
   out_5273281981643743211[155] = 0.0;
   out_5273281981643743211[156] = 0.0;
   out_5273281981643743211[157] = 0.0;
   out_5273281981643743211[158] = 0.0;
   out_5273281981643743211[159] = 0.0;
   out_5273281981643743211[160] = 0.0;
   out_5273281981643743211[161] = 0.0;
   out_5273281981643743211[162] = 0.0;
   out_5273281981643743211[163] = 0.0;
   out_5273281981643743211[164] = 0.0;
   out_5273281981643743211[165] = 0.0;
   out_5273281981643743211[166] = 0.0;
   out_5273281981643743211[167] = 0.0;
   out_5273281981643743211[168] = 0.0;
   out_5273281981643743211[169] = 0.0;
   out_5273281981643743211[170] = 0.0;
   out_5273281981643743211[171] = 1.0;
   out_5273281981643743211[172] = 0.0;
   out_5273281981643743211[173] = 0.0;
   out_5273281981643743211[174] = 0.0;
   out_5273281981643743211[175] = 0.0;
   out_5273281981643743211[176] = 0.0;
   out_5273281981643743211[177] = 0.0;
   out_5273281981643743211[178] = 0.0;
   out_5273281981643743211[179] = 0.0;
   out_5273281981643743211[180] = 0.0;
   out_5273281981643743211[181] = 0.0;
   out_5273281981643743211[182] = 0.0;
   out_5273281981643743211[183] = 0.0;
   out_5273281981643743211[184] = 0.0;
   out_5273281981643743211[185] = 0.0;
   out_5273281981643743211[186] = 0.0;
   out_5273281981643743211[187] = 0.0;
   out_5273281981643743211[188] = 0.0;
   out_5273281981643743211[189] = 0.0;
   out_5273281981643743211[190] = 1.0;
   out_5273281981643743211[191] = 0.0;
   out_5273281981643743211[192] = 0.0;
   out_5273281981643743211[193] = 0.0;
   out_5273281981643743211[194] = 0.0;
   out_5273281981643743211[195] = 0.0;
   out_5273281981643743211[196] = 0.0;
   out_5273281981643743211[197] = 0.0;
   out_5273281981643743211[198] = 0.0;
   out_5273281981643743211[199] = 0.0;
   out_5273281981643743211[200] = 0.0;
   out_5273281981643743211[201] = 0.0;
   out_5273281981643743211[202] = 0.0;
   out_5273281981643743211[203] = 0.0;
   out_5273281981643743211[204] = 0.0;
   out_5273281981643743211[205] = 0.0;
   out_5273281981643743211[206] = 0.0;
   out_5273281981643743211[207] = 0.0;
   out_5273281981643743211[208] = 0.0;
   out_5273281981643743211[209] = 1.0;
   out_5273281981643743211[210] = 0.0;
   out_5273281981643743211[211] = 0.0;
   out_5273281981643743211[212] = 0.0;
   out_5273281981643743211[213] = 0.0;
   out_5273281981643743211[214] = 0.0;
   out_5273281981643743211[215] = 0.0;
   out_5273281981643743211[216] = 0.0;
   out_5273281981643743211[217] = 0.0;
   out_5273281981643743211[218] = 0.0;
   out_5273281981643743211[219] = 0.0;
   out_5273281981643743211[220] = 0.0;
   out_5273281981643743211[221] = 0.0;
   out_5273281981643743211[222] = 0.0;
   out_5273281981643743211[223] = 0.0;
   out_5273281981643743211[224] = 0.0;
   out_5273281981643743211[225] = 0.0;
   out_5273281981643743211[226] = 0.0;
   out_5273281981643743211[227] = 0.0;
   out_5273281981643743211[228] = 1.0;
   out_5273281981643743211[229] = 0.0;
   out_5273281981643743211[230] = 0.0;
   out_5273281981643743211[231] = 0.0;
   out_5273281981643743211[232] = 0.0;
   out_5273281981643743211[233] = 0.0;
   out_5273281981643743211[234] = 0.0;
   out_5273281981643743211[235] = 0.0;
   out_5273281981643743211[236] = 0.0;
   out_5273281981643743211[237] = 0.0;
   out_5273281981643743211[238] = 0.0;
   out_5273281981643743211[239] = 0.0;
   out_5273281981643743211[240] = 0.0;
   out_5273281981643743211[241] = 0.0;
   out_5273281981643743211[242] = 0.0;
   out_5273281981643743211[243] = 0.0;
   out_5273281981643743211[244] = 0.0;
   out_5273281981643743211[245] = 0.0;
   out_5273281981643743211[246] = 0.0;
   out_5273281981643743211[247] = 1.0;
   out_5273281981643743211[248] = 0.0;
   out_5273281981643743211[249] = 0.0;
   out_5273281981643743211[250] = 0.0;
   out_5273281981643743211[251] = 0.0;
   out_5273281981643743211[252] = 0.0;
   out_5273281981643743211[253] = 0.0;
   out_5273281981643743211[254] = 0.0;
   out_5273281981643743211[255] = 0.0;
   out_5273281981643743211[256] = 0.0;
   out_5273281981643743211[257] = 0.0;
   out_5273281981643743211[258] = 0.0;
   out_5273281981643743211[259] = 0.0;
   out_5273281981643743211[260] = 0.0;
   out_5273281981643743211[261] = 0.0;
   out_5273281981643743211[262] = 0.0;
   out_5273281981643743211[263] = 0.0;
   out_5273281981643743211[264] = 0.0;
   out_5273281981643743211[265] = 0.0;
   out_5273281981643743211[266] = 1.0;
   out_5273281981643743211[267] = 0.0;
   out_5273281981643743211[268] = 0.0;
   out_5273281981643743211[269] = 0.0;
   out_5273281981643743211[270] = 0.0;
   out_5273281981643743211[271] = 0.0;
   out_5273281981643743211[272] = 0.0;
   out_5273281981643743211[273] = 0.0;
   out_5273281981643743211[274] = 0.0;
   out_5273281981643743211[275] = 0.0;
   out_5273281981643743211[276] = 0.0;
   out_5273281981643743211[277] = 0.0;
   out_5273281981643743211[278] = 0.0;
   out_5273281981643743211[279] = 0.0;
   out_5273281981643743211[280] = 0.0;
   out_5273281981643743211[281] = 0.0;
   out_5273281981643743211[282] = 0.0;
   out_5273281981643743211[283] = 0.0;
   out_5273281981643743211[284] = 0.0;
   out_5273281981643743211[285] = 1.0;
   out_5273281981643743211[286] = 0.0;
   out_5273281981643743211[287] = 0.0;
   out_5273281981643743211[288] = 0.0;
   out_5273281981643743211[289] = 0.0;
   out_5273281981643743211[290] = 0.0;
   out_5273281981643743211[291] = 0.0;
   out_5273281981643743211[292] = 0.0;
   out_5273281981643743211[293] = 0.0;
   out_5273281981643743211[294] = 0.0;
   out_5273281981643743211[295] = 0.0;
   out_5273281981643743211[296] = 0.0;
   out_5273281981643743211[297] = 0.0;
   out_5273281981643743211[298] = 0.0;
   out_5273281981643743211[299] = 0.0;
   out_5273281981643743211[300] = 0.0;
   out_5273281981643743211[301] = 0.0;
   out_5273281981643743211[302] = 0.0;
   out_5273281981643743211[303] = 0.0;
   out_5273281981643743211[304] = 1.0;
   out_5273281981643743211[305] = 0.0;
   out_5273281981643743211[306] = 0.0;
   out_5273281981643743211[307] = 0.0;
   out_5273281981643743211[308] = 0.0;
   out_5273281981643743211[309] = 0.0;
   out_5273281981643743211[310] = 0.0;
   out_5273281981643743211[311] = 0.0;
   out_5273281981643743211[312] = 0.0;
   out_5273281981643743211[313] = 0.0;
   out_5273281981643743211[314] = 0.0;
   out_5273281981643743211[315] = 0.0;
   out_5273281981643743211[316] = 0.0;
   out_5273281981643743211[317] = 0.0;
   out_5273281981643743211[318] = 0.0;
   out_5273281981643743211[319] = 0.0;
   out_5273281981643743211[320] = 0.0;
   out_5273281981643743211[321] = 0.0;
   out_5273281981643743211[322] = 0.0;
   out_5273281981643743211[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3798976948542527989) {
   out_3798976948542527989[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3798976948542527989[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3798976948542527989[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3798976948542527989[3] = dt*state[12] + state[3];
   out_3798976948542527989[4] = dt*state[13] + state[4];
   out_3798976948542527989[5] = dt*state[14] + state[5];
   out_3798976948542527989[6] = state[6];
   out_3798976948542527989[7] = state[7];
   out_3798976948542527989[8] = state[8];
   out_3798976948542527989[9] = state[9];
   out_3798976948542527989[10] = state[10];
   out_3798976948542527989[11] = state[11];
   out_3798976948542527989[12] = state[12];
   out_3798976948542527989[13] = state[13];
   out_3798976948542527989[14] = state[14];
   out_3798976948542527989[15] = state[15];
   out_3798976948542527989[16] = state[16];
   out_3798976948542527989[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5376087696404799721) {
   out_5376087696404799721[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5376087696404799721[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5376087696404799721[2] = 0;
   out_5376087696404799721[3] = 0;
   out_5376087696404799721[4] = 0;
   out_5376087696404799721[5] = 0;
   out_5376087696404799721[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5376087696404799721[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5376087696404799721[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5376087696404799721[9] = 0;
   out_5376087696404799721[10] = 0;
   out_5376087696404799721[11] = 0;
   out_5376087696404799721[12] = 0;
   out_5376087696404799721[13] = 0;
   out_5376087696404799721[14] = 0;
   out_5376087696404799721[15] = 0;
   out_5376087696404799721[16] = 0;
   out_5376087696404799721[17] = 0;
   out_5376087696404799721[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5376087696404799721[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5376087696404799721[20] = 0;
   out_5376087696404799721[21] = 0;
   out_5376087696404799721[22] = 0;
   out_5376087696404799721[23] = 0;
   out_5376087696404799721[24] = 0;
   out_5376087696404799721[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5376087696404799721[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5376087696404799721[27] = 0;
   out_5376087696404799721[28] = 0;
   out_5376087696404799721[29] = 0;
   out_5376087696404799721[30] = 0;
   out_5376087696404799721[31] = 0;
   out_5376087696404799721[32] = 0;
   out_5376087696404799721[33] = 0;
   out_5376087696404799721[34] = 0;
   out_5376087696404799721[35] = 0;
   out_5376087696404799721[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5376087696404799721[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5376087696404799721[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5376087696404799721[39] = 0;
   out_5376087696404799721[40] = 0;
   out_5376087696404799721[41] = 0;
   out_5376087696404799721[42] = 0;
   out_5376087696404799721[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5376087696404799721[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5376087696404799721[45] = 0;
   out_5376087696404799721[46] = 0;
   out_5376087696404799721[47] = 0;
   out_5376087696404799721[48] = 0;
   out_5376087696404799721[49] = 0;
   out_5376087696404799721[50] = 0;
   out_5376087696404799721[51] = 0;
   out_5376087696404799721[52] = 0;
   out_5376087696404799721[53] = 0;
   out_5376087696404799721[54] = 0;
   out_5376087696404799721[55] = 0;
   out_5376087696404799721[56] = 0;
   out_5376087696404799721[57] = 1;
   out_5376087696404799721[58] = 0;
   out_5376087696404799721[59] = 0;
   out_5376087696404799721[60] = 0;
   out_5376087696404799721[61] = 0;
   out_5376087696404799721[62] = 0;
   out_5376087696404799721[63] = 0;
   out_5376087696404799721[64] = 0;
   out_5376087696404799721[65] = 0;
   out_5376087696404799721[66] = dt;
   out_5376087696404799721[67] = 0;
   out_5376087696404799721[68] = 0;
   out_5376087696404799721[69] = 0;
   out_5376087696404799721[70] = 0;
   out_5376087696404799721[71] = 0;
   out_5376087696404799721[72] = 0;
   out_5376087696404799721[73] = 0;
   out_5376087696404799721[74] = 0;
   out_5376087696404799721[75] = 0;
   out_5376087696404799721[76] = 1;
   out_5376087696404799721[77] = 0;
   out_5376087696404799721[78] = 0;
   out_5376087696404799721[79] = 0;
   out_5376087696404799721[80] = 0;
   out_5376087696404799721[81] = 0;
   out_5376087696404799721[82] = 0;
   out_5376087696404799721[83] = 0;
   out_5376087696404799721[84] = 0;
   out_5376087696404799721[85] = dt;
   out_5376087696404799721[86] = 0;
   out_5376087696404799721[87] = 0;
   out_5376087696404799721[88] = 0;
   out_5376087696404799721[89] = 0;
   out_5376087696404799721[90] = 0;
   out_5376087696404799721[91] = 0;
   out_5376087696404799721[92] = 0;
   out_5376087696404799721[93] = 0;
   out_5376087696404799721[94] = 0;
   out_5376087696404799721[95] = 1;
   out_5376087696404799721[96] = 0;
   out_5376087696404799721[97] = 0;
   out_5376087696404799721[98] = 0;
   out_5376087696404799721[99] = 0;
   out_5376087696404799721[100] = 0;
   out_5376087696404799721[101] = 0;
   out_5376087696404799721[102] = 0;
   out_5376087696404799721[103] = 0;
   out_5376087696404799721[104] = dt;
   out_5376087696404799721[105] = 0;
   out_5376087696404799721[106] = 0;
   out_5376087696404799721[107] = 0;
   out_5376087696404799721[108] = 0;
   out_5376087696404799721[109] = 0;
   out_5376087696404799721[110] = 0;
   out_5376087696404799721[111] = 0;
   out_5376087696404799721[112] = 0;
   out_5376087696404799721[113] = 0;
   out_5376087696404799721[114] = 1;
   out_5376087696404799721[115] = 0;
   out_5376087696404799721[116] = 0;
   out_5376087696404799721[117] = 0;
   out_5376087696404799721[118] = 0;
   out_5376087696404799721[119] = 0;
   out_5376087696404799721[120] = 0;
   out_5376087696404799721[121] = 0;
   out_5376087696404799721[122] = 0;
   out_5376087696404799721[123] = 0;
   out_5376087696404799721[124] = 0;
   out_5376087696404799721[125] = 0;
   out_5376087696404799721[126] = 0;
   out_5376087696404799721[127] = 0;
   out_5376087696404799721[128] = 0;
   out_5376087696404799721[129] = 0;
   out_5376087696404799721[130] = 0;
   out_5376087696404799721[131] = 0;
   out_5376087696404799721[132] = 0;
   out_5376087696404799721[133] = 1;
   out_5376087696404799721[134] = 0;
   out_5376087696404799721[135] = 0;
   out_5376087696404799721[136] = 0;
   out_5376087696404799721[137] = 0;
   out_5376087696404799721[138] = 0;
   out_5376087696404799721[139] = 0;
   out_5376087696404799721[140] = 0;
   out_5376087696404799721[141] = 0;
   out_5376087696404799721[142] = 0;
   out_5376087696404799721[143] = 0;
   out_5376087696404799721[144] = 0;
   out_5376087696404799721[145] = 0;
   out_5376087696404799721[146] = 0;
   out_5376087696404799721[147] = 0;
   out_5376087696404799721[148] = 0;
   out_5376087696404799721[149] = 0;
   out_5376087696404799721[150] = 0;
   out_5376087696404799721[151] = 0;
   out_5376087696404799721[152] = 1;
   out_5376087696404799721[153] = 0;
   out_5376087696404799721[154] = 0;
   out_5376087696404799721[155] = 0;
   out_5376087696404799721[156] = 0;
   out_5376087696404799721[157] = 0;
   out_5376087696404799721[158] = 0;
   out_5376087696404799721[159] = 0;
   out_5376087696404799721[160] = 0;
   out_5376087696404799721[161] = 0;
   out_5376087696404799721[162] = 0;
   out_5376087696404799721[163] = 0;
   out_5376087696404799721[164] = 0;
   out_5376087696404799721[165] = 0;
   out_5376087696404799721[166] = 0;
   out_5376087696404799721[167] = 0;
   out_5376087696404799721[168] = 0;
   out_5376087696404799721[169] = 0;
   out_5376087696404799721[170] = 0;
   out_5376087696404799721[171] = 1;
   out_5376087696404799721[172] = 0;
   out_5376087696404799721[173] = 0;
   out_5376087696404799721[174] = 0;
   out_5376087696404799721[175] = 0;
   out_5376087696404799721[176] = 0;
   out_5376087696404799721[177] = 0;
   out_5376087696404799721[178] = 0;
   out_5376087696404799721[179] = 0;
   out_5376087696404799721[180] = 0;
   out_5376087696404799721[181] = 0;
   out_5376087696404799721[182] = 0;
   out_5376087696404799721[183] = 0;
   out_5376087696404799721[184] = 0;
   out_5376087696404799721[185] = 0;
   out_5376087696404799721[186] = 0;
   out_5376087696404799721[187] = 0;
   out_5376087696404799721[188] = 0;
   out_5376087696404799721[189] = 0;
   out_5376087696404799721[190] = 1;
   out_5376087696404799721[191] = 0;
   out_5376087696404799721[192] = 0;
   out_5376087696404799721[193] = 0;
   out_5376087696404799721[194] = 0;
   out_5376087696404799721[195] = 0;
   out_5376087696404799721[196] = 0;
   out_5376087696404799721[197] = 0;
   out_5376087696404799721[198] = 0;
   out_5376087696404799721[199] = 0;
   out_5376087696404799721[200] = 0;
   out_5376087696404799721[201] = 0;
   out_5376087696404799721[202] = 0;
   out_5376087696404799721[203] = 0;
   out_5376087696404799721[204] = 0;
   out_5376087696404799721[205] = 0;
   out_5376087696404799721[206] = 0;
   out_5376087696404799721[207] = 0;
   out_5376087696404799721[208] = 0;
   out_5376087696404799721[209] = 1;
   out_5376087696404799721[210] = 0;
   out_5376087696404799721[211] = 0;
   out_5376087696404799721[212] = 0;
   out_5376087696404799721[213] = 0;
   out_5376087696404799721[214] = 0;
   out_5376087696404799721[215] = 0;
   out_5376087696404799721[216] = 0;
   out_5376087696404799721[217] = 0;
   out_5376087696404799721[218] = 0;
   out_5376087696404799721[219] = 0;
   out_5376087696404799721[220] = 0;
   out_5376087696404799721[221] = 0;
   out_5376087696404799721[222] = 0;
   out_5376087696404799721[223] = 0;
   out_5376087696404799721[224] = 0;
   out_5376087696404799721[225] = 0;
   out_5376087696404799721[226] = 0;
   out_5376087696404799721[227] = 0;
   out_5376087696404799721[228] = 1;
   out_5376087696404799721[229] = 0;
   out_5376087696404799721[230] = 0;
   out_5376087696404799721[231] = 0;
   out_5376087696404799721[232] = 0;
   out_5376087696404799721[233] = 0;
   out_5376087696404799721[234] = 0;
   out_5376087696404799721[235] = 0;
   out_5376087696404799721[236] = 0;
   out_5376087696404799721[237] = 0;
   out_5376087696404799721[238] = 0;
   out_5376087696404799721[239] = 0;
   out_5376087696404799721[240] = 0;
   out_5376087696404799721[241] = 0;
   out_5376087696404799721[242] = 0;
   out_5376087696404799721[243] = 0;
   out_5376087696404799721[244] = 0;
   out_5376087696404799721[245] = 0;
   out_5376087696404799721[246] = 0;
   out_5376087696404799721[247] = 1;
   out_5376087696404799721[248] = 0;
   out_5376087696404799721[249] = 0;
   out_5376087696404799721[250] = 0;
   out_5376087696404799721[251] = 0;
   out_5376087696404799721[252] = 0;
   out_5376087696404799721[253] = 0;
   out_5376087696404799721[254] = 0;
   out_5376087696404799721[255] = 0;
   out_5376087696404799721[256] = 0;
   out_5376087696404799721[257] = 0;
   out_5376087696404799721[258] = 0;
   out_5376087696404799721[259] = 0;
   out_5376087696404799721[260] = 0;
   out_5376087696404799721[261] = 0;
   out_5376087696404799721[262] = 0;
   out_5376087696404799721[263] = 0;
   out_5376087696404799721[264] = 0;
   out_5376087696404799721[265] = 0;
   out_5376087696404799721[266] = 1;
   out_5376087696404799721[267] = 0;
   out_5376087696404799721[268] = 0;
   out_5376087696404799721[269] = 0;
   out_5376087696404799721[270] = 0;
   out_5376087696404799721[271] = 0;
   out_5376087696404799721[272] = 0;
   out_5376087696404799721[273] = 0;
   out_5376087696404799721[274] = 0;
   out_5376087696404799721[275] = 0;
   out_5376087696404799721[276] = 0;
   out_5376087696404799721[277] = 0;
   out_5376087696404799721[278] = 0;
   out_5376087696404799721[279] = 0;
   out_5376087696404799721[280] = 0;
   out_5376087696404799721[281] = 0;
   out_5376087696404799721[282] = 0;
   out_5376087696404799721[283] = 0;
   out_5376087696404799721[284] = 0;
   out_5376087696404799721[285] = 1;
   out_5376087696404799721[286] = 0;
   out_5376087696404799721[287] = 0;
   out_5376087696404799721[288] = 0;
   out_5376087696404799721[289] = 0;
   out_5376087696404799721[290] = 0;
   out_5376087696404799721[291] = 0;
   out_5376087696404799721[292] = 0;
   out_5376087696404799721[293] = 0;
   out_5376087696404799721[294] = 0;
   out_5376087696404799721[295] = 0;
   out_5376087696404799721[296] = 0;
   out_5376087696404799721[297] = 0;
   out_5376087696404799721[298] = 0;
   out_5376087696404799721[299] = 0;
   out_5376087696404799721[300] = 0;
   out_5376087696404799721[301] = 0;
   out_5376087696404799721[302] = 0;
   out_5376087696404799721[303] = 0;
   out_5376087696404799721[304] = 1;
   out_5376087696404799721[305] = 0;
   out_5376087696404799721[306] = 0;
   out_5376087696404799721[307] = 0;
   out_5376087696404799721[308] = 0;
   out_5376087696404799721[309] = 0;
   out_5376087696404799721[310] = 0;
   out_5376087696404799721[311] = 0;
   out_5376087696404799721[312] = 0;
   out_5376087696404799721[313] = 0;
   out_5376087696404799721[314] = 0;
   out_5376087696404799721[315] = 0;
   out_5376087696404799721[316] = 0;
   out_5376087696404799721[317] = 0;
   out_5376087696404799721[318] = 0;
   out_5376087696404799721[319] = 0;
   out_5376087696404799721[320] = 0;
   out_5376087696404799721[321] = 0;
   out_5376087696404799721[322] = 0;
   out_5376087696404799721[323] = 1;
}
void h_4(double *state, double *unused, double *out_6100547545538860384) {
   out_6100547545538860384[0] = state[6] + state[9];
   out_6100547545538860384[1] = state[7] + state[10];
   out_6100547545538860384[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_9045089191487650783) {
   out_9045089191487650783[0] = 0;
   out_9045089191487650783[1] = 0;
   out_9045089191487650783[2] = 0;
   out_9045089191487650783[3] = 0;
   out_9045089191487650783[4] = 0;
   out_9045089191487650783[5] = 0;
   out_9045089191487650783[6] = 1;
   out_9045089191487650783[7] = 0;
   out_9045089191487650783[8] = 0;
   out_9045089191487650783[9] = 1;
   out_9045089191487650783[10] = 0;
   out_9045089191487650783[11] = 0;
   out_9045089191487650783[12] = 0;
   out_9045089191487650783[13] = 0;
   out_9045089191487650783[14] = 0;
   out_9045089191487650783[15] = 0;
   out_9045089191487650783[16] = 0;
   out_9045089191487650783[17] = 0;
   out_9045089191487650783[18] = 0;
   out_9045089191487650783[19] = 0;
   out_9045089191487650783[20] = 0;
   out_9045089191487650783[21] = 0;
   out_9045089191487650783[22] = 0;
   out_9045089191487650783[23] = 0;
   out_9045089191487650783[24] = 0;
   out_9045089191487650783[25] = 1;
   out_9045089191487650783[26] = 0;
   out_9045089191487650783[27] = 0;
   out_9045089191487650783[28] = 1;
   out_9045089191487650783[29] = 0;
   out_9045089191487650783[30] = 0;
   out_9045089191487650783[31] = 0;
   out_9045089191487650783[32] = 0;
   out_9045089191487650783[33] = 0;
   out_9045089191487650783[34] = 0;
   out_9045089191487650783[35] = 0;
   out_9045089191487650783[36] = 0;
   out_9045089191487650783[37] = 0;
   out_9045089191487650783[38] = 0;
   out_9045089191487650783[39] = 0;
   out_9045089191487650783[40] = 0;
   out_9045089191487650783[41] = 0;
   out_9045089191487650783[42] = 0;
   out_9045089191487650783[43] = 0;
   out_9045089191487650783[44] = 1;
   out_9045089191487650783[45] = 0;
   out_9045089191487650783[46] = 0;
   out_9045089191487650783[47] = 1;
   out_9045089191487650783[48] = 0;
   out_9045089191487650783[49] = 0;
   out_9045089191487650783[50] = 0;
   out_9045089191487650783[51] = 0;
   out_9045089191487650783[52] = 0;
   out_9045089191487650783[53] = 0;
}
void h_10(double *state, double *unused, double *out_7661539883733460450) {
   out_7661539883733460450[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7661539883733460450[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7661539883733460450[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2752907549792722588) {
   out_2752907549792722588[0] = 0;
   out_2752907549792722588[1] = 9.8100000000000005*cos(state[1]);
   out_2752907549792722588[2] = 0;
   out_2752907549792722588[3] = 0;
   out_2752907549792722588[4] = -state[8];
   out_2752907549792722588[5] = state[7];
   out_2752907549792722588[6] = 0;
   out_2752907549792722588[7] = state[5];
   out_2752907549792722588[8] = -state[4];
   out_2752907549792722588[9] = 0;
   out_2752907549792722588[10] = 0;
   out_2752907549792722588[11] = 0;
   out_2752907549792722588[12] = 1;
   out_2752907549792722588[13] = 0;
   out_2752907549792722588[14] = 0;
   out_2752907549792722588[15] = 1;
   out_2752907549792722588[16] = 0;
   out_2752907549792722588[17] = 0;
   out_2752907549792722588[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2752907549792722588[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2752907549792722588[20] = 0;
   out_2752907549792722588[21] = state[8];
   out_2752907549792722588[22] = 0;
   out_2752907549792722588[23] = -state[6];
   out_2752907549792722588[24] = -state[5];
   out_2752907549792722588[25] = 0;
   out_2752907549792722588[26] = state[3];
   out_2752907549792722588[27] = 0;
   out_2752907549792722588[28] = 0;
   out_2752907549792722588[29] = 0;
   out_2752907549792722588[30] = 0;
   out_2752907549792722588[31] = 1;
   out_2752907549792722588[32] = 0;
   out_2752907549792722588[33] = 0;
   out_2752907549792722588[34] = 1;
   out_2752907549792722588[35] = 0;
   out_2752907549792722588[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2752907549792722588[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2752907549792722588[38] = 0;
   out_2752907549792722588[39] = -state[7];
   out_2752907549792722588[40] = state[6];
   out_2752907549792722588[41] = 0;
   out_2752907549792722588[42] = state[4];
   out_2752907549792722588[43] = -state[3];
   out_2752907549792722588[44] = 0;
   out_2752907549792722588[45] = 0;
   out_2752907549792722588[46] = 0;
   out_2752907549792722588[47] = 0;
   out_2752907549792722588[48] = 0;
   out_2752907549792722588[49] = 0;
   out_2752907549792722588[50] = 1;
   out_2752907549792722588[51] = 0;
   out_2752907549792722588[52] = 0;
   out_2752907549792722588[53] = 1;
}
void h_13(double *state, double *unused, double *out_4247381704481051963) {
   out_4247381704481051963[0] = state[3];
   out_4247381704481051963[1] = state[4];
   out_4247381704481051963[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1791023673905199904) {
   out_1791023673905199904[0] = 0;
   out_1791023673905199904[1] = 0;
   out_1791023673905199904[2] = 0;
   out_1791023673905199904[3] = 1;
   out_1791023673905199904[4] = 0;
   out_1791023673905199904[5] = 0;
   out_1791023673905199904[6] = 0;
   out_1791023673905199904[7] = 0;
   out_1791023673905199904[8] = 0;
   out_1791023673905199904[9] = 0;
   out_1791023673905199904[10] = 0;
   out_1791023673905199904[11] = 0;
   out_1791023673905199904[12] = 0;
   out_1791023673905199904[13] = 0;
   out_1791023673905199904[14] = 0;
   out_1791023673905199904[15] = 0;
   out_1791023673905199904[16] = 0;
   out_1791023673905199904[17] = 0;
   out_1791023673905199904[18] = 0;
   out_1791023673905199904[19] = 0;
   out_1791023673905199904[20] = 0;
   out_1791023673905199904[21] = 0;
   out_1791023673905199904[22] = 1;
   out_1791023673905199904[23] = 0;
   out_1791023673905199904[24] = 0;
   out_1791023673905199904[25] = 0;
   out_1791023673905199904[26] = 0;
   out_1791023673905199904[27] = 0;
   out_1791023673905199904[28] = 0;
   out_1791023673905199904[29] = 0;
   out_1791023673905199904[30] = 0;
   out_1791023673905199904[31] = 0;
   out_1791023673905199904[32] = 0;
   out_1791023673905199904[33] = 0;
   out_1791023673905199904[34] = 0;
   out_1791023673905199904[35] = 0;
   out_1791023673905199904[36] = 0;
   out_1791023673905199904[37] = 0;
   out_1791023673905199904[38] = 0;
   out_1791023673905199904[39] = 0;
   out_1791023673905199904[40] = 0;
   out_1791023673905199904[41] = 1;
   out_1791023673905199904[42] = 0;
   out_1791023673905199904[43] = 0;
   out_1791023673905199904[44] = 0;
   out_1791023673905199904[45] = 0;
   out_1791023673905199904[46] = 0;
   out_1791023673905199904[47] = 0;
   out_1791023673905199904[48] = 0;
   out_1791023673905199904[49] = 0;
   out_1791023673905199904[50] = 0;
   out_1791023673905199904[51] = 0;
   out_1791023673905199904[52] = 0;
   out_1791023673905199904[53] = 0;
}
void h_14(double *state, double *unused, double *out_7786063953392294783) {
   out_7786063953392294783[0] = state[6];
   out_7786063953392294783[1] = state[7];
   out_7786063953392294783[2] = state[8];
}
void H_14(double *state, double *unused, double *out_5438414025882416304) {
   out_5438414025882416304[0] = 0;
   out_5438414025882416304[1] = 0;
   out_5438414025882416304[2] = 0;
   out_5438414025882416304[3] = 0;
   out_5438414025882416304[4] = 0;
   out_5438414025882416304[5] = 0;
   out_5438414025882416304[6] = 1;
   out_5438414025882416304[7] = 0;
   out_5438414025882416304[8] = 0;
   out_5438414025882416304[9] = 0;
   out_5438414025882416304[10] = 0;
   out_5438414025882416304[11] = 0;
   out_5438414025882416304[12] = 0;
   out_5438414025882416304[13] = 0;
   out_5438414025882416304[14] = 0;
   out_5438414025882416304[15] = 0;
   out_5438414025882416304[16] = 0;
   out_5438414025882416304[17] = 0;
   out_5438414025882416304[18] = 0;
   out_5438414025882416304[19] = 0;
   out_5438414025882416304[20] = 0;
   out_5438414025882416304[21] = 0;
   out_5438414025882416304[22] = 0;
   out_5438414025882416304[23] = 0;
   out_5438414025882416304[24] = 0;
   out_5438414025882416304[25] = 1;
   out_5438414025882416304[26] = 0;
   out_5438414025882416304[27] = 0;
   out_5438414025882416304[28] = 0;
   out_5438414025882416304[29] = 0;
   out_5438414025882416304[30] = 0;
   out_5438414025882416304[31] = 0;
   out_5438414025882416304[32] = 0;
   out_5438414025882416304[33] = 0;
   out_5438414025882416304[34] = 0;
   out_5438414025882416304[35] = 0;
   out_5438414025882416304[36] = 0;
   out_5438414025882416304[37] = 0;
   out_5438414025882416304[38] = 0;
   out_5438414025882416304[39] = 0;
   out_5438414025882416304[40] = 0;
   out_5438414025882416304[41] = 0;
   out_5438414025882416304[42] = 0;
   out_5438414025882416304[43] = 0;
   out_5438414025882416304[44] = 1;
   out_5438414025882416304[45] = 0;
   out_5438414025882416304[46] = 0;
   out_5438414025882416304[47] = 0;
   out_5438414025882416304[48] = 0;
   out_5438414025882416304[49] = 0;
   out_5438414025882416304[50] = 0;
   out_5438414025882416304[51] = 0;
   out_5438414025882416304[52] = 0;
   out_5438414025882416304[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_3328634486354213070) {
  err_fun(nom_x, delta_x, out_3328634486354213070);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2068367058924519839) {
  inv_err_fun(nom_x, true_x, out_2068367058924519839);
}
void pose_H_mod_fun(double *state, double *out_5273281981643743211) {
  H_mod_fun(state, out_5273281981643743211);
}
void pose_f_fun(double *state, double dt, double *out_3798976948542527989) {
  f_fun(state,  dt, out_3798976948542527989);
}
void pose_F_fun(double *state, double dt, double *out_5376087696404799721) {
  F_fun(state,  dt, out_5376087696404799721);
}
void pose_h_4(double *state, double *unused, double *out_6100547545538860384) {
  h_4(state, unused, out_6100547545538860384);
}
void pose_H_4(double *state, double *unused, double *out_9045089191487650783) {
  H_4(state, unused, out_9045089191487650783);
}
void pose_h_10(double *state, double *unused, double *out_7661539883733460450) {
  h_10(state, unused, out_7661539883733460450);
}
void pose_H_10(double *state, double *unused, double *out_2752907549792722588) {
  H_10(state, unused, out_2752907549792722588);
}
void pose_h_13(double *state, double *unused, double *out_4247381704481051963) {
  h_13(state, unused, out_4247381704481051963);
}
void pose_H_13(double *state, double *unused, double *out_1791023673905199904) {
  H_13(state, unused, out_1791023673905199904);
}
void pose_h_14(double *state, double *unused, double *out_7786063953392294783) {
  h_14(state, unused, out_7786063953392294783);
}
void pose_H_14(double *state, double *unused, double *out_5438414025882416304) {
  H_14(state, unused, out_5438414025882416304);
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
