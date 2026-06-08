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
void err_fun(double *nom_x, double *delta_x, double *out_1942165964233553274) {
   out_1942165964233553274[0] = delta_x[0] + nom_x[0];
   out_1942165964233553274[1] = delta_x[1] + nom_x[1];
   out_1942165964233553274[2] = delta_x[2] + nom_x[2];
   out_1942165964233553274[3] = delta_x[3] + nom_x[3];
   out_1942165964233553274[4] = delta_x[4] + nom_x[4];
   out_1942165964233553274[5] = delta_x[5] + nom_x[5];
   out_1942165964233553274[6] = delta_x[6] + nom_x[6];
   out_1942165964233553274[7] = delta_x[7] + nom_x[7];
   out_1942165964233553274[8] = delta_x[8] + nom_x[8];
   out_1942165964233553274[9] = delta_x[9] + nom_x[9];
   out_1942165964233553274[10] = delta_x[10] + nom_x[10];
   out_1942165964233553274[11] = delta_x[11] + nom_x[11];
   out_1942165964233553274[12] = delta_x[12] + nom_x[12];
   out_1942165964233553274[13] = delta_x[13] + nom_x[13];
   out_1942165964233553274[14] = delta_x[14] + nom_x[14];
   out_1942165964233553274[15] = delta_x[15] + nom_x[15];
   out_1942165964233553274[16] = delta_x[16] + nom_x[16];
   out_1942165964233553274[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2238116153961167505) {
   out_2238116153961167505[0] = -nom_x[0] + true_x[0];
   out_2238116153961167505[1] = -nom_x[1] + true_x[1];
   out_2238116153961167505[2] = -nom_x[2] + true_x[2];
   out_2238116153961167505[3] = -nom_x[3] + true_x[3];
   out_2238116153961167505[4] = -nom_x[4] + true_x[4];
   out_2238116153961167505[5] = -nom_x[5] + true_x[5];
   out_2238116153961167505[6] = -nom_x[6] + true_x[6];
   out_2238116153961167505[7] = -nom_x[7] + true_x[7];
   out_2238116153961167505[8] = -nom_x[8] + true_x[8];
   out_2238116153961167505[9] = -nom_x[9] + true_x[9];
   out_2238116153961167505[10] = -nom_x[10] + true_x[10];
   out_2238116153961167505[11] = -nom_x[11] + true_x[11];
   out_2238116153961167505[12] = -nom_x[12] + true_x[12];
   out_2238116153961167505[13] = -nom_x[13] + true_x[13];
   out_2238116153961167505[14] = -nom_x[14] + true_x[14];
   out_2238116153961167505[15] = -nom_x[15] + true_x[15];
   out_2238116153961167505[16] = -nom_x[16] + true_x[16];
   out_2238116153961167505[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4990084456757481789) {
   out_4990084456757481789[0] = 1.0;
   out_4990084456757481789[1] = 0.0;
   out_4990084456757481789[2] = 0.0;
   out_4990084456757481789[3] = 0.0;
   out_4990084456757481789[4] = 0.0;
   out_4990084456757481789[5] = 0.0;
   out_4990084456757481789[6] = 0.0;
   out_4990084456757481789[7] = 0.0;
   out_4990084456757481789[8] = 0.0;
   out_4990084456757481789[9] = 0.0;
   out_4990084456757481789[10] = 0.0;
   out_4990084456757481789[11] = 0.0;
   out_4990084456757481789[12] = 0.0;
   out_4990084456757481789[13] = 0.0;
   out_4990084456757481789[14] = 0.0;
   out_4990084456757481789[15] = 0.0;
   out_4990084456757481789[16] = 0.0;
   out_4990084456757481789[17] = 0.0;
   out_4990084456757481789[18] = 0.0;
   out_4990084456757481789[19] = 1.0;
   out_4990084456757481789[20] = 0.0;
   out_4990084456757481789[21] = 0.0;
   out_4990084456757481789[22] = 0.0;
   out_4990084456757481789[23] = 0.0;
   out_4990084456757481789[24] = 0.0;
   out_4990084456757481789[25] = 0.0;
   out_4990084456757481789[26] = 0.0;
   out_4990084456757481789[27] = 0.0;
   out_4990084456757481789[28] = 0.0;
   out_4990084456757481789[29] = 0.0;
   out_4990084456757481789[30] = 0.0;
   out_4990084456757481789[31] = 0.0;
   out_4990084456757481789[32] = 0.0;
   out_4990084456757481789[33] = 0.0;
   out_4990084456757481789[34] = 0.0;
   out_4990084456757481789[35] = 0.0;
   out_4990084456757481789[36] = 0.0;
   out_4990084456757481789[37] = 0.0;
   out_4990084456757481789[38] = 1.0;
   out_4990084456757481789[39] = 0.0;
   out_4990084456757481789[40] = 0.0;
   out_4990084456757481789[41] = 0.0;
   out_4990084456757481789[42] = 0.0;
   out_4990084456757481789[43] = 0.0;
   out_4990084456757481789[44] = 0.0;
   out_4990084456757481789[45] = 0.0;
   out_4990084456757481789[46] = 0.0;
   out_4990084456757481789[47] = 0.0;
   out_4990084456757481789[48] = 0.0;
   out_4990084456757481789[49] = 0.0;
   out_4990084456757481789[50] = 0.0;
   out_4990084456757481789[51] = 0.0;
   out_4990084456757481789[52] = 0.0;
   out_4990084456757481789[53] = 0.0;
   out_4990084456757481789[54] = 0.0;
   out_4990084456757481789[55] = 0.0;
   out_4990084456757481789[56] = 0.0;
   out_4990084456757481789[57] = 1.0;
   out_4990084456757481789[58] = 0.0;
   out_4990084456757481789[59] = 0.0;
   out_4990084456757481789[60] = 0.0;
   out_4990084456757481789[61] = 0.0;
   out_4990084456757481789[62] = 0.0;
   out_4990084456757481789[63] = 0.0;
   out_4990084456757481789[64] = 0.0;
   out_4990084456757481789[65] = 0.0;
   out_4990084456757481789[66] = 0.0;
   out_4990084456757481789[67] = 0.0;
   out_4990084456757481789[68] = 0.0;
   out_4990084456757481789[69] = 0.0;
   out_4990084456757481789[70] = 0.0;
   out_4990084456757481789[71] = 0.0;
   out_4990084456757481789[72] = 0.0;
   out_4990084456757481789[73] = 0.0;
   out_4990084456757481789[74] = 0.0;
   out_4990084456757481789[75] = 0.0;
   out_4990084456757481789[76] = 1.0;
   out_4990084456757481789[77] = 0.0;
   out_4990084456757481789[78] = 0.0;
   out_4990084456757481789[79] = 0.0;
   out_4990084456757481789[80] = 0.0;
   out_4990084456757481789[81] = 0.0;
   out_4990084456757481789[82] = 0.0;
   out_4990084456757481789[83] = 0.0;
   out_4990084456757481789[84] = 0.0;
   out_4990084456757481789[85] = 0.0;
   out_4990084456757481789[86] = 0.0;
   out_4990084456757481789[87] = 0.0;
   out_4990084456757481789[88] = 0.0;
   out_4990084456757481789[89] = 0.0;
   out_4990084456757481789[90] = 0.0;
   out_4990084456757481789[91] = 0.0;
   out_4990084456757481789[92] = 0.0;
   out_4990084456757481789[93] = 0.0;
   out_4990084456757481789[94] = 0.0;
   out_4990084456757481789[95] = 1.0;
   out_4990084456757481789[96] = 0.0;
   out_4990084456757481789[97] = 0.0;
   out_4990084456757481789[98] = 0.0;
   out_4990084456757481789[99] = 0.0;
   out_4990084456757481789[100] = 0.0;
   out_4990084456757481789[101] = 0.0;
   out_4990084456757481789[102] = 0.0;
   out_4990084456757481789[103] = 0.0;
   out_4990084456757481789[104] = 0.0;
   out_4990084456757481789[105] = 0.0;
   out_4990084456757481789[106] = 0.0;
   out_4990084456757481789[107] = 0.0;
   out_4990084456757481789[108] = 0.0;
   out_4990084456757481789[109] = 0.0;
   out_4990084456757481789[110] = 0.0;
   out_4990084456757481789[111] = 0.0;
   out_4990084456757481789[112] = 0.0;
   out_4990084456757481789[113] = 0.0;
   out_4990084456757481789[114] = 1.0;
   out_4990084456757481789[115] = 0.0;
   out_4990084456757481789[116] = 0.0;
   out_4990084456757481789[117] = 0.0;
   out_4990084456757481789[118] = 0.0;
   out_4990084456757481789[119] = 0.0;
   out_4990084456757481789[120] = 0.0;
   out_4990084456757481789[121] = 0.0;
   out_4990084456757481789[122] = 0.0;
   out_4990084456757481789[123] = 0.0;
   out_4990084456757481789[124] = 0.0;
   out_4990084456757481789[125] = 0.0;
   out_4990084456757481789[126] = 0.0;
   out_4990084456757481789[127] = 0.0;
   out_4990084456757481789[128] = 0.0;
   out_4990084456757481789[129] = 0.0;
   out_4990084456757481789[130] = 0.0;
   out_4990084456757481789[131] = 0.0;
   out_4990084456757481789[132] = 0.0;
   out_4990084456757481789[133] = 1.0;
   out_4990084456757481789[134] = 0.0;
   out_4990084456757481789[135] = 0.0;
   out_4990084456757481789[136] = 0.0;
   out_4990084456757481789[137] = 0.0;
   out_4990084456757481789[138] = 0.0;
   out_4990084456757481789[139] = 0.0;
   out_4990084456757481789[140] = 0.0;
   out_4990084456757481789[141] = 0.0;
   out_4990084456757481789[142] = 0.0;
   out_4990084456757481789[143] = 0.0;
   out_4990084456757481789[144] = 0.0;
   out_4990084456757481789[145] = 0.0;
   out_4990084456757481789[146] = 0.0;
   out_4990084456757481789[147] = 0.0;
   out_4990084456757481789[148] = 0.0;
   out_4990084456757481789[149] = 0.0;
   out_4990084456757481789[150] = 0.0;
   out_4990084456757481789[151] = 0.0;
   out_4990084456757481789[152] = 1.0;
   out_4990084456757481789[153] = 0.0;
   out_4990084456757481789[154] = 0.0;
   out_4990084456757481789[155] = 0.0;
   out_4990084456757481789[156] = 0.0;
   out_4990084456757481789[157] = 0.0;
   out_4990084456757481789[158] = 0.0;
   out_4990084456757481789[159] = 0.0;
   out_4990084456757481789[160] = 0.0;
   out_4990084456757481789[161] = 0.0;
   out_4990084456757481789[162] = 0.0;
   out_4990084456757481789[163] = 0.0;
   out_4990084456757481789[164] = 0.0;
   out_4990084456757481789[165] = 0.0;
   out_4990084456757481789[166] = 0.0;
   out_4990084456757481789[167] = 0.0;
   out_4990084456757481789[168] = 0.0;
   out_4990084456757481789[169] = 0.0;
   out_4990084456757481789[170] = 0.0;
   out_4990084456757481789[171] = 1.0;
   out_4990084456757481789[172] = 0.0;
   out_4990084456757481789[173] = 0.0;
   out_4990084456757481789[174] = 0.0;
   out_4990084456757481789[175] = 0.0;
   out_4990084456757481789[176] = 0.0;
   out_4990084456757481789[177] = 0.0;
   out_4990084456757481789[178] = 0.0;
   out_4990084456757481789[179] = 0.0;
   out_4990084456757481789[180] = 0.0;
   out_4990084456757481789[181] = 0.0;
   out_4990084456757481789[182] = 0.0;
   out_4990084456757481789[183] = 0.0;
   out_4990084456757481789[184] = 0.0;
   out_4990084456757481789[185] = 0.0;
   out_4990084456757481789[186] = 0.0;
   out_4990084456757481789[187] = 0.0;
   out_4990084456757481789[188] = 0.0;
   out_4990084456757481789[189] = 0.0;
   out_4990084456757481789[190] = 1.0;
   out_4990084456757481789[191] = 0.0;
   out_4990084456757481789[192] = 0.0;
   out_4990084456757481789[193] = 0.0;
   out_4990084456757481789[194] = 0.0;
   out_4990084456757481789[195] = 0.0;
   out_4990084456757481789[196] = 0.0;
   out_4990084456757481789[197] = 0.0;
   out_4990084456757481789[198] = 0.0;
   out_4990084456757481789[199] = 0.0;
   out_4990084456757481789[200] = 0.0;
   out_4990084456757481789[201] = 0.0;
   out_4990084456757481789[202] = 0.0;
   out_4990084456757481789[203] = 0.0;
   out_4990084456757481789[204] = 0.0;
   out_4990084456757481789[205] = 0.0;
   out_4990084456757481789[206] = 0.0;
   out_4990084456757481789[207] = 0.0;
   out_4990084456757481789[208] = 0.0;
   out_4990084456757481789[209] = 1.0;
   out_4990084456757481789[210] = 0.0;
   out_4990084456757481789[211] = 0.0;
   out_4990084456757481789[212] = 0.0;
   out_4990084456757481789[213] = 0.0;
   out_4990084456757481789[214] = 0.0;
   out_4990084456757481789[215] = 0.0;
   out_4990084456757481789[216] = 0.0;
   out_4990084456757481789[217] = 0.0;
   out_4990084456757481789[218] = 0.0;
   out_4990084456757481789[219] = 0.0;
   out_4990084456757481789[220] = 0.0;
   out_4990084456757481789[221] = 0.0;
   out_4990084456757481789[222] = 0.0;
   out_4990084456757481789[223] = 0.0;
   out_4990084456757481789[224] = 0.0;
   out_4990084456757481789[225] = 0.0;
   out_4990084456757481789[226] = 0.0;
   out_4990084456757481789[227] = 0.0;
   out_4990084456757481789[228] = 1.0;
   out_4990084456757481789[229] = 0.0;
   out_4990084456757481789[230] = 0.0;
   out_4990084456757481789[231] = 0.0;
   out_4990084456757481789[232] = 0.0;
   out_4990084456757481789[233] = 0.0;
   out_4990084456757481789[234] = 0.0;
   out_4990084456757481789[235] = 0.0;
   out_4990084456757481789[236] = 0.0;
   out_4990084456757481789[237] = 0.0;
   out_4990084456757481789[238] = 0.0;
   out_4990084456757481789[239] = 0.0;
   out_4990084456757481789[240] = 0.0;
   out_4990084456757481789[241] = 0.0;
   out_4990084456757481789[242] = 0.0;
   out_4990084456757481789[243] = 0.0;
   out_4990084456757481789[244] = 0.0;
   out_4990084456757481789[245] = 0.0;
   out_4990084456757481789[246] = 0.0;
   out_4990084456757481789[247] = 1.0;
   out_4990084456757481789[248] = 0.0;
   out_4990084456757481789[249] = 0.0;
   out_4990084456757481789[250] = 0.0;
   out_4990084456757481789[251] = 0.0;
   out_4990084456757481789[252] = 0.0;
   out_4990084456757481789[253] = 0.0;
   out_4990084456757481789[254] = 0.0;
   out_4990084456757481789[255] = 0.0;
   out_4990084456757481789[256] = 0.0;
   out_4990084456757481789[257] = 0.0;
   out_4990084456757481789[258] = 0.0;
   out_4990084456757481789[259] = 0.0;
   out_4990084456757481789[260] = 0.0;
   out_4990084456757481789[261] = 0.0;
   out_4990084456757481789[262] = 0.0;
   out_4990084456757481789[263] = 0.0;
   out_4990084456757481789[264] = 0.0;
   out_4990084456757481789[265] = 0.0;
   out_4990084456757481789[266] = 1.0;
   out_4990084456757481789[267] = 0.0;
   out_4990084456757481789[268] = 0.0;
   out_4990084456757481789[269] = 0.0;
   out_4990084456757481789[270] = 0.0;
   out_4990084456757481789[271] = 0.0;
   out_4990084456757481789[272] = 0.0;
   out_4990084456757481789[273] = 0.0;
   out_4990084456757481789[274] = 0.0;
   out_4990084456757481789[275] = 0.0;
   out_4990084456757481789[276] = 0.0;
   out_4990084456757481789[277] = 0.0;
   out_4990084456757481789[278] = 0.0;
   out_4990084456757481789[279] = 0.0;
   out_4990084456757481789[280] = 0.0;
   out_4990084456757481789[281] = 0.0;
   out_4990084456757481789[282] = 0.0;
   out_4990084456757481789[283] = 0.0;
   out_4990084456757481789[284] = 0.0;
   out_4990084456757481789[285] = 1.0;
   out_4990084456757481789[286] = 0.0;
   out_4990084456757481789[287] = 0.0;
   out_4990084456757481789[288] = 0.0;
   out_4990084456757481789[289] = 0.0;
   out_4990084456757481789[290] = 0.0;
   out_4990084456757481789[291] = 0.0;
   out_4990084456757481789[292] = 0.0;
   out_4990084456757481789[293] = 0.0;
   out_4990084456757481789[294] = 0.0;
   out_4990084456757481789[295] = 0.0;
   out_4990084456757481789[296] = 0.0;
   out_4990084456757481789[297] = 0.0;
   out_4990084456757481789[298] = 0.0;
   out_4990084456757481789[299] = 0.0;
   out_4990084456757481789[300] = 0.0;
   out_4990084456757481789[301] = 0.0;
   out_4990084456757481789[302] = 0.0;
   out_4990084456757481789[303] = 0.0;
   out_4990084456757481789[304] = 1.0;
   out_4990084456757481789[305] = 0.0;
   out_4990084456757481789[306] = 0.0;
   out_4990084456757481789[307] = 0.0;
   out_4990084456757481789[308] = 0.0;
   out_4990084456757481789[309] = 0.0;
   out_4990084456757481789[310] = 0.0;
   out_4990084456757481789[311] = 0.0;
   out_4990084456757481789[312] = 0.0;
   out_4990084456757481789[313] = 0.0;
   out_4990084456757481789[314] = 0.0;
   out_4990084456757481789[315] = 0.0;
   out_4990084456757481789[316] = 0.0;
   out_4990084456757481789[317] = 0.0;
   out_4990084456757481789[318] = 0.0;
   out_4990084456757481789[319] = 0.0;
   out_4990084456757481789[320] = 0.0;
   out_4990084456757481789[321] = 0.0;
   out_4990084456757481789[322] = 0.0;
   out_4990084456757481789[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6296202895308932040) {
   out_6296202895308932040[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6296202895308932040[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6296202895308932040[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6296202895308932040[3] = dt*state[12] + state[3];
   out_6296202895308932040[4] = dt*state[13] + state[4];
   out_6296202895308932040[5] = dt*state[14] + state[5];
   out_6296202895308932040[6] = state[6];
   out_6296202895308932040[7] = state[7];
   out_6296202895308932040[8] = state[8];
   out_6296202895308932040[9] = state[9];
   out_6296202895308932040[10] = state[10];
   out_6296202895308932040[11] = state[11];
   out_6296202895308932040[12] = state[12];
   out_6296202895308932040[13] = state[13];
   out_6296202895308932040[14] = state[14];
   out_6296202895308932040[15] = state[15];
   out_6296202895308932040[16] = state[16];
   out_6296202895308932040[17] = state[17];
}
void F_fun(double *state, double dt, double *out_909355394007943716) {
   out_909355394007943716[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_909355394007943716[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_909355394007943716[2] = 0;
   out_909355394007943716[3] = 0;
   out_909355394007943716[4] = 0;
   out_909355394007943716[5] = 0;
   out_909355394007943716[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_909355394007943716[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_909355394007943716[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_909355394007943716[9] = 0;
   out_909355394007943716[10] = 0;
   out_909355394007943716[11] = 0;
   out_909355394007943716[12] = 0;
   out_909355394007943716[13] = 0;
   out_909355394007943716[14] = 0;
   out_909355394007943716[15] = 0;
   out_909355394007943716[16] = 0;
   out_909355394007943716[17] = 0;
   out_909355394007943716[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_909355394007943716[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_909355394007943716[20] = 0;
   out_909355394007943716[21] = 0;
   out_909355394007943716[22] = 0;
   out_909355394007943716[23] = 0;
   out_909355394007943716[24] = 0;
   out_909355394007943716[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_909355394007943716[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_909355394007943716[27] = 0;
   out_909355394007943716[28] = 0;
   out_909355394007943716[29] = 0;
   out_909355394007943716[30] = 0;
   out_909355394007943716[31] = 0;
   out_909355394007943716[32] = 0;
   out_909355394007943716[33] = 0;
   out_909355394007943716[34] = 0;
   out_909355394007943716[35] = 0;
   out_909355394007943716[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_909355394007943716[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_909355394007943716[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_909355394007943716[39] = 0;
   out_909355394007943716[40] = 0;
   out_909355394007943716[41] = 0;
   out_909355394007943716[42] = 0;
   out_909355394007943716[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_909355394007943716[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_909355394007943716[45] = 0;
   out_909355394007943716[46] = 0;
   out_909355394007943716[47] = 0;
   out_909355394007943716[48] = 0;
   out_909355394007943716[49] = 0;
   out_909355394007943716[50] = 0;
   out_909355394007943716[51] = 0;
   out_909355394007943716[52] = 0;
   out_909355394007943716[53] = 0;
   out_909355394007943716[54] = 0;
   out_909355394007943716[55] = 0;
   out_909355394007943716[56] = 0;
   out_909355394007943716[57] = 1;
   out_909355394007943716[58] = 0;
   out_909355394007943716[59] = 0;
   out_909355394007943716[60] = 0;
   out_909355394007943716[61] = 0;
   out_909355394007943716[62] = 0;
   out_909355394007943716[63] = 0;
   out_909355394007943716[64] = 0;
   out_909355394007943716[65] = 0;
   out_909355394007943716[66] = dt;
   out_909355394007943716[67] = 0;
   out_909355394007943716[68] = 0;
   out_909355394007943716[69] = 0;
   out_909355394007943716[70] = 0;
   out_909355394007943716[71] = 0;
   out_909355394007943716[72] = 0;
   out_909355394007943716[73] = 0;
   out_909355394007943716[74] = 0;
   out_909355394007943716[75] = 0;
   out_909355394007943716[76] = 1;
   out_909355394007943716[77] = 0;
   out_909355394007943716[78] = 0;
   out_909355394007943716[79] = 0;
   out_909355394007943716[80] = 0;
   out_909355394007943716[81] = 0;
   out_909355394007943716[82] = 0;
   out_909355394007943716[83] = 0;
   out_909355394007943716[84] = 0;
   out_909355394007943716[85] = dt;
   out_909355394007943716[86] = 0;
   out_909355394007943716[87] = 0;
   out_909355394007943716[88] = 0;
   out_909355394007943716[89] = 0;
   out_909355394007943716[90] = 0;
   out_909355394007943716[91] = 0;
   out_909355394007943716[92] = 0;
   out_909355394007943716[93] = 0;
   out_909355394007943716[94] = 0;
   out_909355394007943716[95] = 1;
   out_909355394007943716[96] = 0;
   out_909355394007943716[97] = 0;
   out_909355394007943716[98] = 0;
   out_909355394007943716[99] = 0;
   out_909355394007943716[100] = 0;
   out_909355394007943716[101] = 0;
   out_909355394007943716[102] = 0;
   out_909355394007943716[103] = 0;
   out_909355394007943716[104] = dt;
   out_909355394007943716[105] = 0;
   out_909355394007943716[106] = 0;
   out_909355394007943716[107] = 0;
   out_909355394007943716[108] = 0;
   out_909355394007943716[109] = 0;
   out_909355394007943716[110] = 0;
   out_909355394007943716[111] = 0;
   out_909355394007943716[112] = 0;
   out_909355394007943716[113] = 0;
   out_909355394007943716[114] = 1;
   out_909355394007943716[115] = 0;
   out_909355394007943716[116] = 0;
   out_909355394007943716[117] = 0;
   out_909355394007943716[118] = 0;
   out_909355394007943716[119] = 0;
   out_909355394007943716[120] = 0;
   out_909355394007943716[121] = 0;
   out_909355394007943716[122] = 0;
   out_909355394007943716[123] = 0;
   out_909355394007943716[124] = 0;
   out_909355394007943716[125] = 0;
   out_909355394007943716[126] = 0;
   out_909355394007943716[127] = 0;
   out_909355394007943716[128] = 0;
   out_909355394007943716[129] = 0;
   out_909355394007943716[130] = 0;
   out_909355394007943716[131] = 0;
   out_909355394007943716[132] = 0;
   out_909355394007943716[133] = 1;
   out_909355394007943716[134] = 0;
   out_909355394007943716[135] = 0;
   out_909355394007943716[136] = 0;
   out_909355394007943716[137] = 0;
   out_909355394007943716[138] = 0;
   out_909355394007943716[139] = 0;
   out_909355394007943716[140] = 0;
   out_909355394007943716[141] = 0;
   out_909355394007943716[142] = 0;
   out_909355394007943716[143] = 0;
   out_909355394007943716[144] = 0;
   out_909355394007943716[145] = 0;
   out_909355394007943716[146] = 0;
   out_909355394007943716[147] = 0;
   out_909355394007943716[148] = 0;
   out_909355394007943716[149] = 0;
   out_909355394007943716[150] = 0;
   out_909355394007943716[151] = 0;
   out_909355394007943716[152] = 1;
   out_909355394007943716[153] = 0;
   out_909355394007943716[154] = 0;
   out_909355394007943716[155] = 0;
   out_909355394007943716[156] = 0;
   out_909355394007943716[157] = 0;
   out_909355394007943716[158] = 0;
   out_909355394007943716[159] = 0;
   out_909355394007943716[160] = 0;
   out_909355394007943716[161] = 0;
   out_909355394007943716[162] = 0;
   out_909355394007943716[163] = 0;
   out_909355394007943716[164] = 0;
   out_909355394007943716[165] = 0;
   out_909355394007943716[166] = 0;
   out_909355394007943716[167] = 0;
   out_909355394007943716[168] = 0;
   out_909355394007943716[169] = 0;
   out_909355394007943716[170] = 0;
   out_909355394007943716[171] = 1;
   out_909355394007943716[172] = 0;
   out_909355394007943716[173] = 0;
   out_909355394007943716[174] = 0;
   out_909355394007943716[175] = 0;
   out_909355394007943716[176] = 0;
   out_909355394007943716[177] = 0;
   out_909355394007943716[178] = 0;
   out_909355394007943716[179] = 0;
   out_909355394007943716[180] = 0;
   out_909355394007943716[181] = 0;
   out_909355394007943716[182] = 0;
   out_909355394007943716[183] = 0;
   out_909355394007943716[184] = 0;
   out_909355394007943716[185] = 0;
   out_909355394007943716[186] = 0;
   out_909355394007943716[187] = 0;
   out_909355394007943716[188] = 0;
   out_909355394007943716[189] = 0;
   out_909355394007943716[190] = 1;
   out_909355394007943716[191] = 0;
   out_909355394007943716[192] = 0;
   out_909355394007943716[193] = 0;
   out_909355394007943716[194] = 0;
   out_909355394007943716[195] = 0;
   out_909355394007943716[196] = 0;
   out_909355394007943716[197] = 0;
   out_909355394007943716[198] = 0;
   out_909355394007943716[199] = 0;
   out_909355394007943716[200] = 0;
   out_909355394007943716[201] = 0;
   out_909355394007943716[202] = 0;
   out_909355394007943716[203] = 0;
   out_909355394007943716[204] = 0;
   out_909355394007943716[205] = 0;
   out_909355394007943716[206] = 0;
   out_909355394007943716[207] = 0;
   out_909355394007943716[208] = 0;
   out_909355394007943716[209] = 1;
   out_909355394007943716[210] = 0;
   out_909355394007943716[211] = 0;
   out_909355394007943716[212] = 0;
   out_909355394007943716[213] = 0;
   out_909355394007943716[214] = 0;
   out_909355394007943716[215] = 0;
   out_909355394007943716[216] = 0;
   out_909355394007943716[217] = 0;
   out_909355394007943716[218] = 0;
   out_909355394007943716[219] = 0;
   out_909355394007943716[220] = 0;
   out_909355394007943716[221] = 0;
   out_909355394007943716[222] = 0;
   out_909355394007943716[223] = 0;
   out_909355394007943716[224] = 0;
   out_909355394007943716[225] = 0;
   out_909355394007943716[226] = 0;
   out_909355394007943716[227] = 0;
   out_909355394007943716[228] = 1;
   out_909355394007943716[229] = 0;
   out_909355394007943716[230] = 0;
   out_909355394007943716[231] = 0;
   out_909355394007943716[232] = 0;
   out_909355394007943716[233] = 0;
   out_909355394007943716[234] = 0;
   out_909355394007943716[235] = 0;
   out_909355394007943716[236] = 0;
   out_909355394007943716[237] = 0;
   out_909355394007943716[238] = 0;
   out_909355394007943716[239] = 0;
   out_909355394007943716[240] = 0;
   out_909355394007943716[241] = 0;
   out_909355394007943716[242] = 0;
   out_909355394007943716[243] = 0;
   out_909355394007943716[244] = 0;
   out_909355394007943716[245] = 0;
   out_909355394007943716[246] = 0;
   out_909355394007943716[247] = 1;
   out_909355394007943716[248] = 0;
   out_909355394007943716[249] = 0;
   out_909355394007943716[250] = 0;
   out_909355394007943716[251] = 0;
   out_909355394007943716[252] = 0;
   out_909355394007943716[253] = 0;
   out_909355394007943716[254] = 0;
   out_909355394007943716[255] = 0;
   out_909355394007943716[256] = 0;
   out_909355394007943716[257] = 0;
   out_909355394007943716[258] = 0;
   out_909355394007943716[259] = 0;
   out_909355394007943716[260] = 0;
   out_909355394007943716[261] = 0;
   out_909355394007943716[262] = 0;
   out_909355394007943716[263] = 0;
   out_909355394007943716[264] = 0;
   out_909355394007943716[265] = 0;
   out_909355394007943716[266] = 1;
   out_909355394007943716[267] = 0;
   out_909355394007943716[268] = 0;
   out_909355394007943716[269] = 0;
   out_909355394007943716[270] = 0;
   out_909355394007943716[271] = 0;
   out_909355394007943716[272] = 0;
   out_909355394007943716[273] = 0;
   out_909355394007943716[274] = 0;
   out_909355394007943716[275] = 0;
   out_909355394007943716[276] = 0;
   out_909355394007943716[277] = 0;
   out_909355394007943716[278] = 0;
   out_909355394007943716[279] = 0;
   out_909355394007943716[280] = 0;
   out_909355394007943716[281] = 0;
   out_909355394007943716[282] = 0;
   out_909355394007943716[283] = 0;
   out_909355394007943716[284] = 0;
   out_909355394007943716[285] = 1;
   out_909355394007943716[286] = 0;
   out_909355394007943716[287] = 0;
   out_909355394007943716[288] = 0;
   out_909355394007943716[289] = 0;
   out_909355394007943716[290] = 0;
   out_909355394007943716[291] = 0;
   out_909355394007943716[292] = 0;
   out_909355394007943716[293] = 0;
   out_909355394007943716[294] = 0;
   out_909355394007943716[295] = 0;
   out_909355394007943716[296] = 0;
   out_909355394007943716[297] = 0;
   out_909355394007943716[298] = 0;
   out_909355394007943716[299] = 0;
   out_909355394007943716[300] = 0;
   out_909355394007943716[301] = 0;
   out_909355394007943716[302] = 0;
   out_909355394007943716[303] = 0;
   out_909355394007943716[304] = 1;
   out_909355394007943716[305] = 0;
   out_909355394007943716[306] = 0;
   out_909355394007943716[307] = 0;
   out_909355394007943716[308] = 0;
   out_909355394007943716[309] = 0;
   out_909355394007943716[310] = 0;
   out_909355394007943716[311] = 0;
   out_909355394007943716[312] = 0;
   out_909355394007943716[313] = 0;
   out_909355394007943716[314] = 0;
   out_909355394007943716[315] = 0;
   out_909355394007943716[316] = 0;
   out_909355394007943716[317] = 0;
   out_909355394007943716[318] = 0;
   out_909355394007943716[319] = 0;
   out_909355394007943716[320] = 0;
   out_909355394007943716[321] = 0;
   out_909355394007943716[322] = 0;
   out_909355394007943716[323] = 1;
}
void h_4(double *state, double *unused, double *out_6818977063477642683) {
   out_6818977063477642683[0] = state[6] + state[9];
   out_6818977063477642683[1] = state[7] + state[10];
   out_6818977063477642683[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3954277209300339553) {
   out_3954277209300339553[0] = 0;
   out_3954277209300339553[1] = 0;
   out_3954277209300339553[2] = 0;
   out_3954277209300339553[3] = 0;
   out_3954277209300339553[4] = 0;
   out_3954277209300339553[5] = 0;
   out_3954277209300339553[6] = 1;
   out_3954277209300339553[7] = 0;
   out_3954277209300339553[8] = 0;
   out_3954277209300339553[9] = 1;
   out_3954277209300339553[10] = 0;
   out_3954277209300339553[11] = 0;
   out_3954277209300339553[12] = 0;
   out_3954277209300339553[13] = 0;
   out_3954277209300339553[14] = 0;
   out_3954277209300339553[15] = 0;
   out_3954277209300339553[16] = 0;
   out_3954277209300339553[17] = 0;
   out_3954277209300339553[18] = 0;
   out_3954277209300339553[19] = 0;
   out_3954277209300339553[20] = 0;
   out_3954277209300339553[21] = 0;
   out_3954277209300339553[22] = 0;
   out_3954277209300339553[23] = 0;
   out_3954277209300339553[24] = 0;
   out_3954277209300339553[25] = 1;
   out_3954277209300339553[26] = 0;
   out_3954277209300339553[27] = 0;
   out_3954277209300339553[28] = 1;
   out_3954277209300339553[29] = 0;
   out_3954277209300339553[30] = 0;
   out_3954277209300339553[31] = 0;
   out_3954277209300339553[32] = 0;
   out_3954277209300339553[33] = 0;
   out_3954277209300339553[34] = 0;
   out_3954277209300339553[35] = 0;
   out_3954277209300339553[36] = 0;
   out_3954277209300339553[37] = 0;
   out_3954277209300339553[38] = 0;
   out_3954277209300339553[39] = 0;
   out_3954277209300339553[40] = 0;
   out_3954277209300339553[41] = 0;
   out_3954277209300339553[42] = 0;
   out_3954277209300339553[43] = 0;
   out_3954277209300339553[44] = 1;
   out_3954277209300339553[45] = 0;
   out_3954277209300339553[46] = 0;
   out_3954277209300339553[47] = 1;
   out_3954277209300339553[48] = 0;
   out_3954277209300339553[49] = 0;
   out_3954277209300339553[50] = 0;
   out_3954277209300339553[51] = 0;
   out_3954277209300339553[52] = 0;
   out_3954277209300339553[53] = 0;
}
void h_10(double *state, double *unused, double *out_3834013708689822319) {
   out_3834013708689822319[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_3834013708689822319[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_3834013708689822319[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3533519720904001040) {
   out_3533519720904001040[0] = 0;
   out_3533519720904001040[1] = 9.8100000000000005*cos(state[1]);
   out_3533519720904001040[2] = 0;
   out_3533519720904001040[3] = 0;
   out_3533519720904001040[4] = -state[8];
   out_3533519720904001040[5] = state[7];
   out_3533519720904001040[6] = 0;
   out_3533519720904001040[7] = state[5];
   out_3533519720904001040[8] = -state[4];
   out_3533519720904001040[9] = 0;
   out_3533519720904001040[10] = 0;
   out_3533519720904001040[11] = 0;
   out_3533519720904001040[12] = 1;
   out_3533519720904001040[13] = 0;
   out_3533519720904001040[14] = 0;
   out_3533519720904001040[15] = 1;
   out_3533519720904001040[16] = 0;
   out_3533519720904001040[17] = 0;
   out_3533519720904001040[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3533519720904001040[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3533519720904001040[20] = 0;
   out_3533519720904001040[21] = state[8];
   out_3533519720904001040[22] = 0;
   out_3533519720904001040[23] = -state[6];
   out_3533519720904001040[24] = -state[5];
   out_3533519720904001040[25] = 0;
   out_3533519720904001040[26] = state[3];
   out_3533519720904001040[27] = 0;
   out_3533519720904001040[28] = 0;
   out_3533519720904001040[29] = 0;
   out_3533519720904001040[30] = 0;
   out_3533519720904001040[31] = 1;
   out_3533519720904001040[32] = 0;
   out_3533519720904001040[33] = 0;
   out_3533519720904001040[34] = 1;
   out_3533519720904001040[35] = 0;
   out_3533519720904001040[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3533519720904001040[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3533519720904001040[38] = 0;
   out_3533519720904001040[39] = -state[7];
   out_3533519720904001040[40] = state[6];
   out_3533519720904001040[41] = 0;
   out_3533519720904001040[42] = state[4];
   out_3533519720904001040[43] = -state[3];
   out_3533519720904001040[44] = 0;
   out_3533519720904001040[45] = 0;
   out_3533519720904001040[46] = 0;
   out_3533519720904001040[47] = 0;
   out_3533519720904001040[48] = 0;
   out_3533519720904001040[49] = 0;
   out_3533519720904001040[50] = 1;
   out_3533519720904001040[51] = 0;
   out_3533519720904001040[52] = 0;
   out_3533519720904001040[53] = 1;
}
void h_13(double *state, double *unused, double *out_3025354993842492520) {
   out_3025354993842492520[0] = state[3];
   out_3025354993842492520[1] = state[4];
   out_3025354993842492520[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3389675289618495449) {
   out_3389675289618495449[0] = 0;
   out_3389675289618495449[1] = 0;
   out_3389675289618495449[2] = 0;
   out_3389675289618495449[3] = 1;
   out_3389675289618495449[4] = 0;
   out_3389675289618495449[5] = 0;
   out_3389675289618495449[6] = 0;
   out_3389675289618495449[7] = 0;
   out_3389675289618495449[8] = 0;
   out_3389675289618495449[9] = 0;
   out_3389675289618495449[10] = 0;
   out_3389675289618495449[11] = 0;
   out_3389675289618495449[12] = 0;
   out_3389675289618495449[13] = 0;
   out_3389675289618495449[14] = 0;
   out_3389675289618495449[15] = 0;
   out_3389675289618495449[16] = 0;
   out_3389675289618495449[17] = 0;
   out_3389675289618495449[18] = 0;
   out_3389675289618495449[19] = 0;
   out_3389675289618495449[20] = 0;
   out_3389675289618495449[21] = 0;
   out_3389675289618495449[22] = 1;
   out_3389675289618495449[23] = 0;
   out_3389675289618495449[24] = 0;
   out_3389675289618495449[25] = 0;
   out_3389675289618495449[26] = 0;
   out_3389675289618495449[27] = 0;
   out_3389675289618495449[28] = 0;
   out_3389675289618495449[29] = 0;
   out_3389675289618495449[30] = 0;
   out_3389675289618495449[31] = 0;
   out_3389675289618495449[32] = 0;
   out_3389675289618495449[33] = 0;
   out_3389675289618495449[34] = 0;
   out_3389675289618495449[35] = 0;
   out_3389675289618495449[36] = 0;
   out_3389675289618495449[37] = 0;
   out_3389675289618495449[38] = 0;
   out_3389675289618495449[39] = 0;
   out_3389675289618495449[40] = 0;
   out_3389675289618495449[41] = 1;
   out_3389675289618495449[42] = 0;
   out_3389675289618495449[43] = 0;
   out_3389675289618495449[44] = 0;
   out_3389675289618495449[45] = 0;
   out_3389675289618495449[46] = 0;
   out_3389675289618495449[47] = 0;
   out_3389675289618495449[48] = 0;
   out_3389675289618495449[49] = 0;
   out_3389675289618495449[50] = 0;
   out_3389675289618495449[51] = 0;
   out_3389675289618495449[52] = 0;
   out_3389675289618495449[53] = 0;
}
void h_14(double *state, double *unused, double *out_278507277292912803) {
   out_278507277292912803[0] = state[6];
   out_278507277292912803[1] = state[7];
   out_278507277292912803[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7037065641595711849) {
   out_7037065641595711849[0] = 0;
   out_7037065641595711849[1] = 0;
   out_7037065641595711849[2] = 0;
   out_7037065641595711849[3] = 0;
   out_7037065641595711849[4] = 0;
   out_7037065641595711849[5] = 0;
   out_7037065641595711849[6] = 1;
   out_7037065641595711849[7] = 0;
   out_7037065641595711849[8] = 0;
   out_7037065641595711849[9] = 0;
   out_7037065641595711849[10] = 0;
   out_7037065641595711849[11] = 0;
   out_7037065641595711849[12] = 0;
   out_7037065641595711849[13] = 0;
   out_7037065641595711849[14] = 0;
   out_7037065641595711849[15] = 0;
   out_7037065641595711849[16] = 0;
   out_7037065641595711849[17] = 0;
   out_7037065641595711849[18] = 0;
   out_7037065641595711849[19] = 0;
   out_7037065641595711849[20] = 0;
   out_7037065641595711849[21] = 0;
   out_7037065641595711849[22] = 0;
   out_7037065641595711849[23] = 0;
   out_7037065641595711849[24] = 0;
   out_7037065641595711849[25] = 1;
   out_7037065641595711849[26] = 0;
   out_7037065641595711849[27] = 0;
   out_7037065641595711849[28] = 0;
   out_7037065641595711849[29] = 0;
   out_7037065641595711849[30] = 0;
   out_7037065641595711849[31] = 0;
   out_7037065641595711849[32] = 0;
   out_7037065641595711849[33] = 0;
   out_7037065641595711849[34] = 0;
   out_7037065641595711849[35] = 0;
   out_7037065641595711849[36] = 0;
   out_7037065641595711849[37] = 0;
   out_7037065641595711849[38] = 0;
   out_7037065641595711849[39] = 0;
   out_7037065641595711849[40] = 0;
   out_7037065641595711849[41] = 0;
   out_7037065641595711849[42] = 0;
   out_7037065641595711849[43] = 0;
   out_7037065641595711849[44] = 1;
   out_7037065641595711849[45] = 0;
   out_7037065641595711849[46] = 0;
   out_7037065641595711849[47] = 0;
   out_7037065641595711849[48] = 0;
   out_7037065641595711849[49] = 0;
   out_7037065641595711849[50] = 0;
   out_7037065641595711849[51] = 0;
   out_7037065641595711849[52] = 0;
   out_7037065641595711849[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_1942165964233553274) {
  err_fun(nom_x, delta_x, out_1942165964233553274);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2238116153961167505) {
  inv_err_fun(nom_x, true_x, out_2238116153961167505);
}
void pose_H_mod_fun(double *state, double *out_4990084456757481789) {
  H_mod_fun(state, out_4990084456757481789);
}
void pose_f_fun(double *state, double dt, double *out_6296202895308932040) {
  f_fun(state,  dt, out_6296202895308932040);
}
void pose_F_fun(double *state, double dt, double *out_909355394007943716) {
  F_fun(state,  dt, out_909355394007943716);
}
void pose_h_4(double *state, double *unused, double *out_6818977063477642683) {
  h_4(state, unused, out_6818977063477642683);
}
void pose_H_4(double *state, double *unused, double *out_3954277209300339553) {
  H_4(state, unused, out_3954277209300339553);
}
void pose_h_10(double *state, double *unused, double *out_3834013708689822319) {
  h_10(state, unused, out_3834013708689822319);
}
void pose_H_10(double *state, double *unused, double *out_3533519720904001040) {
  H_10(state, unused, out_3533519720904001040);
}
void pose_h_13(double *state, double *unused, double *out_3025354993842492520) {
  h_13(state, unused, out_3025354993842492520);
}
void pose_H_13(double *state, double *unused, double *out_3389675289618495449) {
  H_13(state, unused, out_3389675289618495449);
}
void pose_h_14(double *state, double *unused, double *out_278507277292912803) {
  h_14(state, unused, out_278507277292912803);
}
void pose_H_14(double *state, double *unused, double *out_7037065641595711849) {
  H_14(state, unused, out_7037065641595711849);
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
