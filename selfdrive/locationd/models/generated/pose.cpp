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
void err_fun(double *nom_x, double *delta_x, double *out_8743902382867857614) {
   out_8743902382867857614[0] = delta_x[0] + nom_x[0];
   out_8743902382867857614[1] = delta_x[1] + nom_x[1];
   out_8743902382867857614[2] = delta_x[2] + nom_x[2];
   out_8743902382867857614[3] = delta_x[3] + nom_x[3];
   out_8743902382867857614[4] = delta_x[4] + nom_x[4];
   out_8743902382867857614[5] = delta_x[5] + nom_x[5];
   out_8743902382867857614[6] = delta_x[6] + nom_x[6];
   out_8743902382867857614[7] = delta_x[7] + nom_x[7];
   out_8743902382867857614[8] = delta_x[8] + nom_x[8];
   out_8743902382867857614[9] = delta_x[9] + nom_x[9];
   out_8743902382867857614[10] = delta_x[10] + nom_x[10];
   out_8743902382867857614[11] = delta_x[11] + nom_x[11];
   out_8743902382867857614[12] = delta_x[12] + nom_x[12];
   out_8743902382867857614[13] = delta_x[13] + nom_x[13];
   out_8743902382867857614[14] = delta_x[14] + nom_x[14];
   out_8743902382867857614[15] = delta_x[15] + nom_x[15];
   out_8743902382867857614[16] = delta_x[16] + nom_x[16];
   out_8743902382867857614[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3636694381902544351) {
   out_3636694381902544351[0] = -nom_x[0] + true_x[0];
   out_3636694381902544351[1] = -nom_x[1] + true_x[1];
   out_3636694381902544351[2] = -nom_x[2] + true_x[2];
   out_3636694381902544351[3] = -nom_x[3] + true_x[3];
   out_3636694381902544351[4] = -nom_x[4] + true_x[4];
   out_3636694381902544351[5] = -nom_x[5] + true_x[5];
   out_3636694381902544351[6] = -nom_x[6] + true_x[6];
   out_3636694381902544351[7] = -nom_x[7] + true_x[7];
   out_3636694381902544351[8] = -nom_x[8] + true_x[8];
   out_3636694381902544351[9] = -nom_x[9] + true_x[9];
   out_3636694381902544351[10] = -nom_x[10] + true_x[10];
   out_3636694381902544351[11] = -nom_x[11] + true_x[11];
   out_3636694381902544351[12] = -nom_x[12] + true_x[12];
   out_3636694381902544351[13] = -nom_x[13] + true_x[13];
   out_3636694381902544351[14] = -nom_x[14] + true_x[14];
   out_3636694381902544351[15] = -nom_x[15] + true_x[15];
   out_3636694381902544351[16] = -nom_x[16] + true_x[16];
   out_3636694381902544351[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_2152190311268096506) {
   out_2152190311268096506[0] = 1.0;
   out_2152190311268096506[1] = 0.0;
   out_2152190311268096506[2] = 0.0;
   out_2152190311268096506[3] = 0.0;
   out_2152190311268096506[4] = 0.0;
   out_2152190311268096506[5] = 0.0;
   out_2152190311268096506[6] = 0.0;
   out_2152190311268096506[7] = 0.0;
   out_2152190311268096506[8] = 0.0;
   out_2152190311268096506[9] = 0.0;
   out_2152190311268096506[10] = 0.0;
   out_2152190311268096506[11] = 0.0;
   out_2152190311268096506[12] = 0.0;
   out_2152190311268096506[13] = 0.0;
   out_2152190311268096506[14] = 0.0;
   out_2152190311268096506[15] = 0.0;
   out_2152190311268096506[16] = 0.0;
   out_2152190311268096506[17] = 0.0;
   out_2152190311268096506[18] = 0.0;
   out_2152190311268096506[19] = 1.0;
   out_2152190311268096506[20] = 0.0;
   out_2152190311268096506[21] = 0.0;
   out_2152190311268096506[22] = 0.0;
   out_2152190311268096506[23] = 0.0;
   out_2152190311268096506[24] = 0.0;
   out_2152190311268096506[25] = 0.0;
   out_2152190311268096506[26] = 0.0;
   out_2152190311268096506[27] = 0.0;
   out_2152190311268096506[28] = 0.0;
   out_2152190311268096506[29] = 0.0;
   out_2152190311268096506[30] = 0.0;
   out_2152190311268096506[31] = 0.0;
   out_2152190311268096506[32] = 0.0;
   out_2152190311268096506[33] = 0.0;
   out_2152190311268096506[34] = 0.0;
   out_2152190311268096506[35] = 0.0;
   out_2152190311268096506[36] = 0.0;
   out_2152190311268096506[37] = 0.0;
   out_2152190311268096506[38] = 1.0;
   out_2152190311268096506[39] = 0.0;
   out_2152190311268096506[40] = 0.0;
   out_2152190311268096506[41] = 0.0;
   out_2152190311268096506[42] = 0.0;
   out_2152190311268096506[43] = 0.0;
   out_2152190311268096506[44] = 0.0;
   out_2152190311268096506[45] = 0.0;
   out_2152190311268096506[46] = 0.0;
   out_2152190311268096506[47] = 0.0;
   out_2152190311268096506[48] = 0.0;
   out_2152190311268096506[49] = 0.0;
   out_2152190311268096506[50] = 0.0;
   out_2152190311268096506[51] = 0.0;
   out_2152190311268096506[52] = 0.0;
   out_2152190311268096506[53] = 0.0;
   out_2152190311268096506[54] = 0.0;
   out_2152190311268096506[55] = 0.0;
   out_2152190311268096506[56] = 0.0;
   out_2152190311268096506[57] = 1.0;
   out_2152190311268096506[58] = 0.0;
   out_2152190311268096506[59] = 0.0;
   out_2152190311268096506[60] = 0.0;
   out_2152190311268096506[61] = 0.0;
   out_2152190311268096506[62] = 0.0;
   out_2152190311268096506[63] = 0.0;
   out_2152190311268096506[64] = 0.0;
   out_2152190311268096506[65] = 0.0;
   out_2152190311268096506[66] = 0.0;
   out_2152190311268096506[67] = 0.0;
   out_2152190311268096506[68] = 0.0;
   out_2152190311268096506[69] = 0.0;
   out_2152190311268096506[70] = 0.0;
   out_2152190311268096506[71] = 0.0;
   out_2152190311268096506[72] = 0.0;
   out_2152190311268096506[73] = 0.0;
   out_2152190311268096506[74] = 0.0;
   out_2152190311268096506[75] = 0.0;
   out_2152190311268096506[76] = 1.0;
   out_2152190311268096506[77] = 0.0;
   out_2152190311268096506[78] = 0.0;
   out_2152190311268096506[79] = 0.0;
   out_2152190311268096506[80] = 0.0;
   out_2152190311268096506[81] = 0.0;
   out_2152190311268096506[82] = 0.0;
   out_2152190311268096506[83] = 0.0;
   out_2152190311268096506[84] = 0.0;
   out_2152190311268096506[85] = 0.0;
   out_2152190311268096506[86] = 0.0;
   out_2152190311268096506[87] = 0.0;
   out_2152190311268096506[88] = 0.0;
   out_2152190311268096506[89] = 0.0;
   out_2152190311268096506[90] = 0.0;
   out_2152190311268096506[91] = 0.0;
   out_2152190311268096506[92] = 0.0;
   out_2152190311268096506[93] = 0.0;
   out_2152190311268096506[94] = 0.0;
   out_2152190311268096506[95] = 1.0;
   out_2152190311268096506[96] = 0.0;
   out_2152190311268096506[97] = 0.0;
   out_2152190311268096506[98] = 0.0;
   out_2152190311268096506[99] = 0.0;
   out_2152190311268096506[100] = 0.0;
   out_2152190311268096506[101] = 0.0;
   out_2152190311268096506[102] = 0.0;
   out_2152190311268096506[103] = 0.0;
   out_2152190311268096506[104] = 0.0;
   out_2152190311268096506[105] = 0.0;
   out_2152190311268096506[106] = 0.0;
   out_2152190311268096506[107] = 0.0;
   out_2152190311268096506[108] = 0.0;
   out_2152190311268096506[109] = 0.0;
   out_2152190311268096506[110] = 0.0;
   out_2152190311268096506[111] = 0.0;
   out_2152190311268096506[112] = 0.0;
   out_2152190311268096506[113] = 0.0;
   out_2152190311268096506[114] = 1.0;
   out_2152190311268096506[115] = 0.0;
   out_2152190311268096506[116] = 0.0;
   out_2152190311268096506[117] = 0.0;
   out_2152190311268096506[118] = 0.0;
   out_2152190311268096506[119] = 0.0;
   out_2152190311268096506[120] = 0.0;
   out_2152190311268096506[121] = 0.0;
   out_2152190311268096506[122] = 0.0;
   out_2152190311268096506[123] = 0.0;
   out_2152190311268096506[124] = 0.0;
   out_2152190311268096506[125] = 0.0;
   out_2152190311268096506[126] = 0.0;
   out_2152190311268096506[127] = 0.0;
   out_2152190311268096506[128] = 0.0;
   out_2152190311268096506[129] = 0.0;
   out_2152190311268096506[130] = 0.0;
   out_2152190311268096506[131] = 0.0;
   out_2152190311268096506[132] = 0.0;
   out_2152190311268096506[133] = 1.0;
   out_2152190311268096506[134] = 0.0;
   out_2152190311268096506[135] = 0.0;
   out_2152190311268096506[136] = 0.0;
   out_2152190311268096506[137] = 0.0;
   out_2152190311268096506[138] = 0.0;
   out_2152190311268096506[139] = 0.0;
   out_2152190311268096506[140] = 0.0;
   out_2152190311268096506[141] = 0.0;
   out_2152190311268096506[142] = 0.0;
   out_2152190311268096506[143] = 0.0;
   out_2152190311268096506[144] = 0.0;
   out_2152190311268096506[145] = 0.0;
   out_2152190311268096506[146] = 0.0;
   out_2152190311268096506[147] = 0.0;
   out_2152190311268096506[148] = 0.0;
   out_2152190311268096506[149] = 0.0;
   out_2152190311268096506[150] = 0.0;
   out_2152190311268096506[151] = 0.0;
   out_2152190311268096506[152] = 1.0;
   out_2152190311268096506[153] = 0.0;
   out_2152190311268096506[154] = 0.0;
   out_2152190311268096506[155] = 0.0;
   out_2152190311268096506[156] = 0.0;
   out_2152190311268096506[157] = 0.0;
   out_2152190311268096506[158] = 0.0;
   out_2152190311268096506[159] = 0.0;
   out_2152190311268096506[160] = 0.0;
   out_2152190311268096506[161] = 0.0;
   out_2152190311268096506[162] = 0.0;
   out_2152190311268096506[163] = 0.0;
   out_2152190311268096506[164] = 0.0;
   out_2152190311268096506[165] = 0.0;
   out_2152190311268096506[166] = 0.0;
   out_2152190311268096506[167] = 0.0;
   out_2152190311268096506[168] = 0.0;
   out_2152190311268096506[169] = 0.0;
   out_2152190311268096506[170] = 0.0;
   out_2152190311268096506[171] = 1.0;
   out_2152190311268096506[172] = 0.0;
   out_2152190311268096506[173] = 0.0;
   out_2152190311268096506[174] = 0.0;
   out_2152190311268096506[175] = 0.0;
   out_2152190311268096506[176] = 0.0;
   out_2152190311268096506[177] = 0.0;
   out_2152190311268096506[178] = 0.0;
   out_2152190311268096506[179] = 0.0;
   out_2152190311268096506[180] = 0.0;
   out_2152190311268096506[181] = 0.0;
   out_2152190311268096506[182] = 0.0;
   out_2152190311268096506[183] = 0.0;
   out_2152190311268096506[184] = 0.0;
   out_2152190311268096506[185] = 0.0;
   out_2152190311268096506[186] = 0.0;
   out_2152190311268096506[187] = 0.0;
   out_2152190311268096506[188] = 0.0;
   out_2152190311268096506[189] = 0.0;
   out_2152190311268096506[190] = 1.0;
   out_2152190311268096506[191] = 0.0;
   out_2152190311268096506[192] = 0.0;
   out_2152190311268096506[193] = 0.0;
   out_2152190311268096506[194] = 0.0;
   out_2152190311268096506[195] = 0.0;
   out_2152190311268096506[196] = 0.0;
   out_2152190311268096506[197] = 0.0;
   out_2152190311268096506[198] = 0.0;
   out_2152190311268096506[199] = 0.0;
   out_2152190311268096506[200] = 0.0;
   out_2152190311268096506[201] = 0.0;
   out_2152190311268096506[202] = 0.0;
   out_2152190311268096506[203] = 0.0;
   out_2152190311268096506[204] = 0.0;
   out_2152190311268096506[205] = 0.0;
   out_2152190311268096506[206] = 0.0;
   out_2152190311268096506[207] = 0.0;
   out_2152190311268096506[208] = 0.0;
   out_2152190311268096506[209] = 1.0;
   out_2152190311268096506[210] = 0.0;
   out_2152190311268096506[211] = 0.0;
   out_2152190311268096506[212] = 0.0;
   out_2152190311268096506[213] = 0.0;
   out_2152190311268096506[214] = 0.0;
   out_2152190311268096506[215] = 0.0;
   out_2152190311268096506[216] = 0.0;
   out_2152190311268096506[217] = 0.0;
   out_2152190311268096506[218] = 0.0;
   out_2152190311268096506[219] = 0.0;
   out_2152190311268096506[220] = 0.0;
   out_2152190311268096506[221] = 0.0;
   out_2152190311268096506[222] = 0.0;
   out_2152190311268096506[223] = 0.0;
   out_2152190311268096506[224] = 0.0;
   out_2152190311268096506[225] = 0.0;
   out_2152190311268096506[226] = 0.0;
   out_2152190311268096506[227] = 0.0;
   out_2152190311268096506[228] = 1.0;
   out_2152190311268096506[229] = 0.0;
   out_2152190311268096506[230] = 0.0;
   out_2152190311268096506[231] = 0.0;
   out_2152190311268096506[232] = 0.0;
   out_2152190311268096506[233] = 0.0;
   out_2152190311268096506[234] = 0.0;
   out_2152190311268096506[235] = 0.0;
   out_2152190311268096506[236] = 0.0;
   out_2152190311268096506[237] = 0.0;
   out_2152190311268096506[238] = 0.0;
   out_2152190311268096506[239] = 0.0;
   out_2152190311268096506[240] = 0.0;
   out_2152190311268096506[241] = 0.0;
   out_2152190311268096506[242] = 0.0;
   out_2152190311268096506[243] = 0.0;
   out_2152190311268096506[244] = 0.0;
   out_2152190311268096506[245] = 0.0;
   out_2152190311268096506[246] = 0.0;
   out_2152190311268096506[247] = 1.0;
   out_2152190311268096506[248] = 0.0;
   out_2152190311268096506[249] = 0.0;
   out_2152190311268096506[250] = 0.0;
   out_2152190311268096506[251] = 0.0;
   out_2152190311268096506[252] = 0.0;
   out_2152190311268096506[253] = 0.0;
   out_2152190311268096506[254] = 0.0;
   out_2152190311268096506[255] = 0.0;
   out_2152190311268096506[256] = 0.0;
   out_2152190311268096506[257] = 0.0;
   out_2152190311268096506[258] = 0.0;
   out_2152190311268096506[259] = 0.0;
   out_2152190311268096506[260] = 0.0;
   out_2152190311268096506[261] = 0.0;
   out_2152190311268096506[262] = 0.0;
   out_2152190311268096506[263] = 0.0;
   out_2152190311268096506[264] = 0.0;
   out_2152190311268096506[265] = 0.0;
   out_2152190311268096506[266] = 1.0;
   out_2152190311268096506[267] = 0.0;
   out_2152190311268096506[268] = 0.0;
   out_2152190311268096506[269] = 0.0;
   out_2152190311268096506[270] = 0.0;
   out_2152190311268096506[271] = 0.0;
   out_2152190311268096506[272] = 0.0;
   out_2152190311268096506[273] = 0.0;
   out_2152190311268096506[274] = 0.0;
   out_2152190311268096506[275] = 0.0;
   out_2152190311268096506[276] = 0.0;
   out_2152190311268096506[277] = 0.0;
   out_2152190311268096506[278] = 0.0;
   out_2152190311268096506[279] = 0.0;
   out_2152190311268096506[280] = 0.0;
   out_2152190311268096506[281] = 0.0;
   out_2152190311268096506[282] = 0.0;
   out_2152190311268096506[283] = 0.0;
   out_2152190311268096506[284] = 0.0;
   out_2152190311268096506[285] = 1.0;
   out_2152190311268096506[286] = 0.0;
   out_2152190311268096506[287] = 0.0;
   out_2152190311268096506[288] = 0.0;
   out_2152190311268096506[289] = 0.0;
   out_2152190311268096506[290] = 0.0;
   out_2152190311268096506[291] = 0.0;
   out_2152190311268096506[292] = 0.0;
   out_2152190311268096506[293] = 0.0;
   out_2152190311268096506[294] = 0.0;
   out_2152190311268096506[295] = 0.0;
   out_2152190311268096506[296] = 0.0;
   out_2152190311268096506[297] = 0.0;
   out_2152190311268096506[298] = 0.0;
   out_2152190311268096506[299] = 0.0;
   out_2152190311268096506[300] = 0.0;
   out_2152190311268096506[301] = 0.0;
   out_2152190311268096506[302] = 0.0;
   out_2152190311268096506[303] = 0.0;
   out_2152190311268096506[304] = 1.0;
   out_2152190311268096506[305] = 0.0;
   out_2152190311268096506[306] = 0.0;
   out_2152190311268096506[307] = 0.0;
   out_2152190311268096506[308] = 0.0;
   out_2152190311268096506[309] = 0.0;
   out_2152190311268096506[310] = 0.0;
   out_2152190311268096506[311] = 0.0;
   out_2152190311268096506[312] = 0.0;
   out_2152190311268096506[313] = 0.0;
   out_2152190311268096506[314] = 0.0;
   out_2152190311268096506[315] = 0.0;
   out_2152190311268096506[316] = 0.0;
   out_2152190311268096506[317] = 0.0;
   out_2152190311268096506[318] = 0.0;
   out_2152190311268096506[319] = 0.0;
   out_2152190311268096506[320] = 0.0;
   out_2152190311268096506[321] = 0.0;
   out_2152190311268096506[322] = 0.0;
   out_2152190311268096506[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5042547316032857663) {
   out_5042547316032857663[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5042547316032857663[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5042547316032857663[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5042547316032857663[3] = dt*state[12] + state[3];
   out_5042547316032857663[4] = dt*state[13] + state[4];
   out_5042547316032857663[5] = dt*state[14] + state[5];
   out_5042547316032857663[6] = state[6];
   out_5042547316032857663[7] = state[7];
   out_5042547316032857663[8] = state[8];
   out_5042547316032857663[9] = state[9];
   out_5042547316032857663[10] = state[10];
   out_5042547316032857663[11] = state[11];
   out_5042547316032857663[12] = state[12];
   out_5042547316032857663[13] = state[13];
   out_5042547316032857663[14] = state[14];
   out_5042547316032857663[15] = state[15];
   out_5042547316032857663[16] = state[16];
   out_5042547316032857663[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6708996175305477877) {
   out_6708996175305477877[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6708996175305477877[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6708996175305477877[2] = 0;
   out_6708996175305477877[3] = 0;
   out_6708996175305477877[4] = 0;
   out_6708996175305477877[5] = 0;
   out_6708996175305477877[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6708996175305477877[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6708996175305477877[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6708996175305477877[9] = 0;
   out_6708996175305477877[10] = 0;
   out_6708996175305477877[11] = 0;
   out_6708996175305477877[12] = 0;
   out_6708996175305477877[13] = 0;
   out_6708996175305477877[14] = 0;
   out_6708996175305477877[15] = 0;
   out_6708996175305477877[16] = 0;
   out_6708996175305477877[17] = 0;
   out_6708996175305477877[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6708996175305477877[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6708996175305477877[20] = 0;
   out_6708996175305477877[21] = 0;
   out_6708996175305477877[22] = 0;
   out_6708996175305477877[23] = 0;
   out_6708996175305477877[24] = 0;
   out_6708996175305477877[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6708996175305477877[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6708996175305477877[27] = 0;
   out_6708996175305477877[28] = 0;
   out_6708996175305477877[29] = 0;
   out_6708996175305477877[30] = 0;
   out_6708996175305477877[31] = 0;
   out_6708996175305477877[32] = 0;
   out_6708996175305477877[33] = 0;
   out_6708996175305477877[34] = 0;
   out_6708996175305477877[35] = 0;
   out_6708996175305477877[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6708996175305477877[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6708996175305477877[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6708996175305477877[39] = 0;
   out_6708996175305477877[40] = 0;
   out_6708996175305477877[41] = 0;
   out_6708996175305477877[42] = 0;
   out_6708996175305477877[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6708996175305477877[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6708996175305477877[45] = 0;
   out_6708996175305477877[46] = 0;
   out_6708996175305477877[47] = 0;
   out_6708996175305477877[48] = 0;
   out_6708996175305477877[49] = 0;
   out_6708996175305477877[50] = 0;
   out_6708996175305477877[51] = 0;
   out_6708996175305477877[52] = 0;
   out_6708996175305477877[53] = 0;
   out_6708996175305477877[54] = 0;
   out_6708996175305477877[55] = 0;
   out_6708996175305477877[56] = 0;
   out_6708996175305477877[57] = 1;
   out_6708996175305477877[58] = 0;
   out_6708996175305477877[59] = 0;
   out_6708996175305477877[60] = 0;
   out_6708996175305477877[61] = 0;
   out_6708996175305477877[62] = 0;
   out_6708996175305477877[63] = 0;
   out_6708996175305477877[64] = 0;
   out_6708996175305477877[65] = 0;
   out_6708996175305477877[66] = dt;
   out_6708996175305477877[67] = 0;
   out_6708996175305477877[68] = 0;
   out_6708996175305477877[69] = 0;
   out_6708996175305477877[70] = 0;
   out_6708996175305477877[71] = 0;
   out_6708996175305477877[72] = 0;
   out_6708996175305477877[73] = 0;
   out_6708996175305477877[74] = 0;
   out_6708996175305477877[75] = 0;
   out_6708996175305477877[76] = 1;
   out_6708996175305477877[77] = 0;
   out_6708996175305477877[78] = 0;
   out_6708996175305477877[79] = 0;
   out_6708996175305477877[80] = 0;
   out_6708996175305477877[81] = 0;
   out_6708996175305477877[82] = 0;
   out_6708996175305477877[83] = 0;
   out_6708996175305477877[84] = 0;
   out_6708996175305477877[85] = dt;
   out_6708996175305477877[86] = 0;
   out_6708996175305477877[87] = 0;
   out_6708996175305477877[88] = 0;
   out_6708996175305477877[89] = 0;
   out_6708996175305477877[90] = 0;
   out_6708996175305477877[91] = 0;
   out_6708996175305477877[92] = 0;
   out_6708996175305477877[93] = 0;
   out_6708996175305477877[94] = 0;
   out_6708996175305477877[95] = 1;
   out_6708996175305477877[96] = 0;
   out_6708996175305477877[97] = 0;
   out_6708996175305477877[98] = 0;
   out_6708996175305477877[99] = 0;
   out_6708996175305477877[100] = 0;
   out_6708996175305477877[101] = 0;
   out_6708996175305477877[102] = 0;
   out_6708996175305477877[103] = 0;
   out_6708996175305477877[104] = dt;
   out_6708996175305477877[105] = 0;
   out_6708996175305477877[106] = 0;
   out_6708996175305477877[107] = 0;
   out_6708996175305477877[108] = 0;
   out_6708996175305477877[109] = 0;
   out_6708996175305477877[110] = 0;
   out_6708996175305477877[111] = 0;
   out_6708996175305477877[112] = 0;
   out_6708996175305477877[113] = 0;
   out_6708996175305477877[114] = 1;
   out_6708996175305477877[115] = 0;
   out_6708996175305477877[116] = 0;
   out_6708996175305477877[117] = 0;
   out_6708996175305477877[118] = 0;
   out_6708996175305477877[119] = 0;
   out_6708996175305477877[120] = 0;
   out_6708996175305477877[121] = 0;
   out_6708996175305477877[122] = 0;
   out_6708996175305477877[123] = 0;
   out_6708996175305477877[124] = 0;
   out_6708996175305477877[125] = 0;
   out_6708996175305477877[126] = 0;
   out_6708996175305477877[127] = 0;
   out_6708996175305477877[128] = 0;
   out_6708996175305477877[129] = 0;
   out_6708996175305477877[130] = 0;
   out_6708996175305477877[131] = 0;
   out_6708996175305477877[132] = 0;
   out_6708996175305477877[133] = 1;
   out_6708996175305477877[134] = 0;
   out_6708996175305477877[135] = 0;
   out_6708996175305477877[136] = 0;
   out_6708996175305477877[137] = 0;
   out_6708996175305477877[138] = 0;
   out_6708996175305477877[139] = 0;
   out_6708996175305477877[140] = 0;
   out_6708996175305477877[141] = 0;
   out_6708996175305477877[142] = 0;
   out_6708996175305477877[143] = 0;
   out_6708996175305477877[144] = 0;
   out_6708996175305477877[145] = 0;
   out_6708996175305477877[146] = 0;
   out_6708996175305477877[147] = 0;
   out_6708996175305477877[148] = 0;
   out_6708996175305477877[149] = 0;
   out_6708996175305477877[150] = 0;
   out_6708996175305477877[151] = 0;
   out_6708996175305477877[152] = 1;
   out_6708996175305477877[153] = 0;
   out_6708996175305477877[154] = 0;
   out_6708996175305477877[155] = 0;
   out_6708996175305477877[156] = 0;
   out_6708996175305477877[157] = 0;
   out_6708996175305477877[158] = 0;
   out_6708996175305477877[159] = 0;
   out_6708996175305477877[160] = 0;
   out_6708996175305477877[161] = 0;
   out_6708996175305477877[162] = 0;
   out_6708996175305477877[163] = 0;
   out_6708996175305477877[164] = 0;
   out_6708996175305477877[165] = 0;
   out_6708996175305477877[166] = 0;
   out_6708996175305477877[167] = 0;
   out_6708996175305477877[168] = 0;
   out_6708996175305477877[169] = 0;
   out_6708996175305477877[170] = 0;
   out_6708996175305477877[171] = 1;
   out_6708996175305477877[172] = 0;
   out_6708996175305477877[173] = 0;
   out_6708996175305477877[174] = 0;
   out_6708996175305477877[175] = 0;
   out_6708996175305477877[176] = 0;
   out_6708996175305477877[177] = 0;
   out_6708996175305477877[178] = 0;
   out_6708996175305477877[179] = 0;
   out_6708996175305477877[180] = 0;
   out_6708996175305477877[181] = 0;
   out_6708996175305477877[182] = 0;
   out_6708996175305477877[183] = 0;
   out_6708996175305477877[184] = 0;
   out_6708996175305477877[185] = 0;
   out_6708996175305477877[186] = 0;
   out_6708996175305477877[187] = 0;
   out_6708996175305477877[188] = 0;
   out_6708996175305477877[189] = 0;
   out_6708996175305477877[190] = 1;
   out_6708996175305477877[191] = 0;
   out_6708996175305477877[192] = 0;
   out_6708996175305477877[193] = 0;
   out_6708996175305477877[194] = 0;
   out_6708996175305477877[195] = 0;
   out_6708996175305477877[196] = 0;
   out_6708996175305477877[197] = 0;
   out_6708996175305477877[198] = 0;
   out_6708996175305477877[199] = 0;
   out_6708996175305477877[200] = 0;
   out_6708996175305477877[201] = 0;
   out_6708996175305477877[202] = 0;
   out_6708996175305477877[203] = 0;
   out_6708996175305477877[204] = 0;
   out_6708996175305477877[205] = 0;
   out_6708996175305477877[206] = 0;
   out_6708996175305477877[207] = 0;
   out_6708996175305477877[208] = 0;
   out_6708996175305477877[209] = 1;
   out_6708996175305477877[210] = 0;
   out_6708996175305477877[211] = 0;
   out_6708996175305477877[212] = 0;
   out_6708996175305477877[213] = 0;
   out_6708996175305477877[214] = 0;
   out_6708996175305477877[215] = 0;
   out_6708996175305477877[216] = 0;
   out_6708996175305477877[217] = 0;
   out_6708996175305477877[218] = 0;
   out_6708996175305477877[219] = 0;
   out_6708996175305477877[220] = 0;
   out_6708996175305477877[221] = 0;
   out_6708996175305477877[222] = 0;
   out_6708996175305477877[223] = 0;
   out_6708996175305477877[224] = 0;
   out_6708996175305477877[225] = 0;
   out_6708996175305477877[226] = 0;
   out_6708996175305477877[227] = 0;
   out_6708996175305477877[228] = 1;
   out_6708996175305477877[229] = 0;
   out_6708996175305477877[230] = 0;
   out_6708996175305477877[231] = 0;
   out_6708996175305477877[232] = 0;
   out_6708996175305477877[233] = 0;
   out_6708996175305477877[234] = 0;
   out_6708996175305477877[235] = 0;
   out_6708996175305477877[236] = 0;
   out_6708996175305477877[237] = 0;
   out_6708996175305477877[238] = 0;
   out_6708996175305477877[239] = 0;
   out_6708996175305477877[240] = 0;
   out_6708996175305477877[241] = 0;
   out_6708996175305477877[242] = 0;
   out_6708996175305477877[243] = 0;
   out_6708996175305477877[244] = 0;
   out_6708996175305477877[245] = 0;
   out_6708996175305477877[246] = 0;
   out_6708996175305477877[247] = 1;
   out_6708996175305477877[248] = 0;
   out_6708996175305477877[249] = 0;
   out_6708996175305477877[250] = 0;
   out_6708996175305477877[251] = 0;
   out_6708996175305477877[252] = 0;
   out_6708996175305477877[253] = 0;
   out_6708996175305477877[254] = 0;
   out_6708996175305477877[255] = 0;
   out_6708996175305477877[256] = 0;
   out_6708996175305477877[257] = 0;
   out_6708996175305477877[258] = 0;
   out_6708996175305477877[259] = 0;
   out_6708996175305477877[260] = 0;
   out_6708996175305477877[261] = 0;
   out_6708996175305477877[262] = 0;
   out_6708996175305477877[263] = 0;
   out_6708996175305477877[264] = 0;
   out_6708996175305477877[265] = 0;
   out_6708996175305477877[266] = 1;
   out_6708996175305477877[267] = 0;
   out_6708996175305477877[268] = 0;
   out_6708996175305477877[269] = 0;
   out_6708996175305477877[270] = 0;
   out_6708996175305477877[271] = 0;
   out_6708996175305477877[272] = 0;
   out_6708996175305477877[273] = 0;
   out_6708996175305477877[274] = 0;
   out_6708996175305477877[275] = 0;
   out_6708996175305477877[276] = 0;
   out_6708996175305477877[277] = 0;
   out_6708996175305477877[278] = 0;
   out_6708996175305477877[279] = 0;
   out_6708996175305477877[280] = 0;
   out_6708996175305477877[281] = 0;
   out_6708996175305477877[282] = 0;
   out_6708996175305477877[283] = 0;
   out_6708996175305477877[284] = 0;
   out_6708996175305477877[285] = 1;
   out_6708996175305477877[286] = 0;
   out_6708996175305477877[287] = 0;
   out_6708996175305477877[288] = 0;
   out_6708996175305477877[289] = 0;
   out_6708996175305477877[290] = 0;
   out_6708996175305477877[291] = 0;
   out_6708996175305477877[292] = 0;
   out_6708996175305477877[293] = 0;
   out_6708996175305477877[294] = 0;
   out_6708996175305477877[295] = 0;
   out_6708996175305477877[296] = 0;
   out_6708996175305477877[297] = 0;
   out_6708996175305477877[298] = 0;
   out_6708996175305477877[299] = 0;
   out_6708996175305477877[300] = 0;
   out_6708996175305477877[301] = 0;
   out_6708996175305477877[302] = 0;
   out_6708996175305477877[303] = 0;
   out_6708996175305477877[304] = 1;
   out_6708996175305477877[305] = 0;
   out_6708996175305477877[306] = 0;
   out_6708996175305477877[307] = 0;
   out_6708996175305477877[308] = 0;
   out_6708996175305477877[309] = 0;
   out_6708996175305477877[310] = 0;
   out_6708996175305477877[311] = 0;
   out_6708996175305477877[312] = 0;
   out_6708996175305477877[313] = 0;
   out_6708996175305477877[314] = 0;
   out_6708996175305477877[315] = 0;
   out_6708996175305477877[316] = 0;
   out_6708996175305477877[317] = 0;
   out_6708996175305477877[318] = 0;
   out_6708996175305477877[319] = 0;
   out_6708996175305477877[320] = 0;
   out_6708996175305477877[321] = 0;
   out_6708996175305477877[322] = 0;
   out_6708996175305477877[323] = 1;
}
void h_4(double *state, double *unused, double *out_3603221658780671100) {
   out_3603221658780671100[0] = state[6] + state[9];
   out_3603221658780671100[1] = state[7] + state[10];
   out_3603221658780671100[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7556357530358465972) {
   out_7556357530358465972[0] = 0;
   out_7556357530358465972[1] = 0;
   out_7556357530358465972[2] = 0;
   out_7556357530358465972[3] = 0;
   out_7556357530358465972[4] = 0;
   out_7556357530358465972[5] = 0;
   out_7556357530358465972[6] = 1;
   out_7556357530358465972[7] = 0;
   out_7556357530358465972[8] = 0;
   out_7556357530358465972[9] = 1;
   out_7556357530358465972[10] = 0;
   out_7556357530358465972[11] = 0;
   out_7556357530358465972[12] = 0;
   out_7556357530358465972[13] = 0;
   out_7556357530358465972[14] = 0;
   out_7556357530358465972[15] = 0;
   out_7556357530358465972[16] = 0;
   out_7556357530358465972[17] = 0;
   out_7556357530358465972[18] = 0;
   out_7556357530358465972[19] = 0;
   out_7556357530358465972[20] = 0;
   out_7556357530358465972[21] = 0;
   out_7556357530358465972[22] = 0;
   out_7556357530358465972[23] = 0;
   out_7556357530358465972[24] = 0;
   out_7556357530358465972[25] = 1;
   out_7556357530358465972[26] = 0;
   out_7556357530358465972[27] = 0;
   out_7556357530358465972[28] = 1;
   out_7556357530358465972[29] = 0;
   out_7556357530358465972[30] = 0;
   out_7556357530358465972[31] = 0;
   out_7556357530358465972[32] = 0;
   out_7556357530358465972[33] = 0;
   out_7556357530358465972[34] = 0;
   out_7556357530358465972[35] = 0;
   out_7556357530358465972[36] = 0;
   out_7556357530358465972[37] = 0;
   out_7556357530358465972[38] = 0;
   out_7556357530358465972[39] = 0;
   out_7556357530358465972[40] = 0;
   out_7556357530358465972[41] = 0;
   out_7556357530358465972[42] = 0;
   out_7556357530358465972[43] = 0;
   out_7556357530358465972[44] = 1;
   out_7556357530358465972[45] = 0;
   out_7556357530358465972[46] = 0;
   out_7556357530358465972[47] = 1;
   out_7556357530358465972[48] = 0;
   out_7556357530358465972[49] = 0;
   out_7556357530358465972[50] = 0;
   out_7556357530358465972[51] = 0;
   out_7556357530358465972[52] = 0;
   out_7556357530358465972[53] = 0;
}
void h_10(double *state, double *unused, double *out_8258563454346399047) {
   out_8258563454346399047[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8258563454346399047[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8258563454346399047[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2735534763065741146) {
   out_2735534763065741146[0] = 0;
   out_2735534763065741146[1] = 9.8100000000000005*cos(state[1]);
   out_2735534763065741146[2] = 0;
   out_2735534763065741146[3] = 0;
   out_2735534763065741146[4] = -state[8];
   out_2735534763065741146[5] = state[7];
   out_2735534763065741146[6] = 0;
   out_2735534763065741146[7] = state[5];
   out_2735534763065741146[8] = -state[4];
   out_2735534763065741146[9] = 0;
   out_2735534763065741146[10] = 0;
   out_2735534763065741146[11] = 0;
   out_2735534763065741146[12] = 1;
   out_2735534763065741146[13] = 0;
   out_2735534763065741146[14] = 0;
   out_2735534763065741146[15] = 1;
   out_2735534763065741146[16] = 0;
   out_2735534763065741146[17] = 0;
   out_2735534763065741146[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2735534763065741146[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2735534763065741146[20] = 0;
   out_2735534763065741146[21] = state[8];
   out_2735534763065741146[22] = 0;
   out_2735534763065741146[23] = -state[6];
   out_2735534763065741146[24] = -state[5];
   out_2735534763065741146[25] = 0;
   out_2735534763065741146[26] = state[3];
   out_2735534763065741146[27] = 0;
   out_2735534763065741146[28] = 0;
   out_2735534763065741146[29] = 0;
   out_2735534763065741146[30] = 0;
   out_2735534763065741146[31] = 1;
   out_2735534763065741146[32] = 0;
   out_2735534763065741146[33] = 0;
   out_2735534763065741146[34] = 1;
   out_2735534763065741146[35] = 0;
   out_2735534763065741146[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2735534763065741146[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2735534763065741146[38] = 0;
   out_2735534763065741146[39] = -state[7];
   out_2735534763065741146[40] = state[6];
   out_2735534763065741146[41] = 0;
   out_2735534763065741146[42] = state[4];
   out_2735534763065741146[43] = -state[3];
   out_2735534763065741146[44] = 0;
   out_2735534763065741146[45] = 0;
   out_2735534763065741146[46] = 0;
   out_2735534763065741146[47] = 0;
   out_2735534763065741146[48] = 0;
   out_2735534763065741146[49] = 0;
   out_2735534763065741146[50] = 1;
   out_2735534763065741146[51] = 0;
   out_2735534763065741146[52] = 0;
   out_2735534763065741146[53] = 1;
}
void h_13(double *state, double *unused, double *out_7576910815427407655) {
   out_7576910815427407655[0] = state[3];
   out_7576910815427407655[1] = state[4];
   out_7576910815427407655[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4344083705026133171) {
   out_4344083705026133171[0] = 0;
   out_4344083705026133171[1] = 0;
   out_4344083705026133171[2] = 0;
   out_4344083705026133171[3] = 1;
   out_4344083705026133171[4] = 0;
   out_4344083705026133171[5] = 0;
   out_4344083705026133171[6] = 0;
   out_4344083705026133171[7] = 0;
   out_4344083705026133171[8] = 0;
   out_4344083705026133171[9] = 0;
   out_4344083705026133171[10] = 0;
   out_4344083705026133171[11] = 0;
   out_4344083705026133171[12] = 0;
   out_4344083705026133171[13] = 0;
   out_4344083705026133171[14] = 0;
   out_4344083705026133171[15] = 0;
   out_4344083705026133171[16] = 0;
   out_4344083705026133171[17] = 0;
   out_4344083705026133171[18] = 0;
   out_4344083705026133171[19] = 0;
   out_4344083705026133171[20] = 0;
   out_4344083705026133171[21] = 0;
   out_4344083705026133171[22] = 1;
   out_4344083705026133171[23] = 0;
   out_4344083705026133171[24] = 0;
   out_4344083705026133171[25] = 0;
   out_4344083705026133171[26] = 0;
   out_4344083705026133171[27] = 0;
   out_4344083705026133171[28] = 0;
   out_4344083705026133171[29] = 0;
   out_4344083705026133171[30] = 0;
   out_4344083705026133171[31] = 0;
   out_4344083705026133171[32] = 0;
   out_4344083705026133171[33] = 0;
   out_4344083705026133171[34] = 0;
   out_4344083705026133171[35] = 0;
   out_4344083705026133171[36] = 0;
   out_4344083705026133171[37] = 0;
   out_4344083705026133171[38] = 0;
   out_4344083705026133171[39] = 0;
   out_4344083705026133171[40] = 0;
   out_4344083705026133171[41] = 1;
   out_4344083705026133171[42] = 0;
   out_4344083705026133171[43] = 0;
   out_4344083705026133171[44] = 0;
   out_4344083705026133171[45] = 0;
   out_4344083705026133171[46] = 0;
   out_4344083705026133171[47] = 0;
   out_4344083705026133171[48] = 0;
   out_4344083705026133171[49] = 0;
   out_4344083705026133171[50] = 0;
   out_4344083705026133171[51] = 0;
   out_4344083705026133171[52] = 0;
   out_4344083705026133171[53] = 0;
}
void h_14(double *state, double *unused, double *out_984451843965455601) {
   out_984451843965455601[0] = state[6];
   out_984451843965455601[1] = state[7];
   out_984451843965455601[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7807598111055713348) {
   out_7807598111055713348[0] = 0;
   out_7807598111055713348[1] = 0;
   out_7807598111055713348[2] = 0;
   out_7807598111055713348[3] = 0;
   out_7807598111055713348[4] = 0;
   out_7807598111055713348[5] = 0;
   out_7807598111055713348[6] = 1;
   out_7807598111055713348[7] = 0;
   out_7807598111055713348[8] = 0;
   out_7807598111055713348[9] = 0;
   out_7807598111055713348[10] = 0;
   out_7807598111055713348[11] = 0;
   out_7807598111055713348[12] = 0;
   out_7807598111055713348[13] = 0;
   out_7807598111055713348[14] = 0;
   out_7807598111055713348[15] = 0;
   out_7807598111055713348[16] = 0;
   out_7807598111055713348[17] = 0;
   out_7807598111055713348[18] = 0;
   out_7807598111055713348[19] = 0;
   out_7807598111055713348[20] = 0;
   out_7807598111055713348[21] = 0;
   out_7807598111055713348[22] = 0;
   out_7807598111055713348[23] = 0;
   out_7807598111055713348[24] = 0;
   out_7807598111055713348[25] = 1;
   out_7807598111055713348[26] = 0;
   out_7807598111055713348[27] = 0;
   out_7807598111055713348[28] = 0;
   out_7807598111055713348[29] = 0;
   out_7807598111055713348[30] = 0;
   out_7807598111055713348[31] = 0;
   out_7807598111055713348[32] = 0;
   out_7807598111055713348[33] = 0;
   out_7807598111055713348[34] = 0;
   out_7807598111055713348[35] = 0;
   out_7807598111055713348[36] = 0;
   out_7807598111055713348[37] = 0;
   out_7807598111055713348[38] = 0;
   out_7807598111055713348[39] = 0;
   out_7807598111055713348[40] = 0;
   out_7807598111055713348[41] = 0;
   out_7807598111055713348[42] = 0;
   out_7807598111055713348[43] = 0;
   out_7807598111055713348[44] = 1;
   out_7807598111055713348[45] = 0;
   out_7807598111055713348[46] = 0;
   out_7807598111055713348[47] = 0;
   out_7807598111055713348[48] = 0;
   out_7807598111055713348[49] = 0;
   out_7807598111055713348[50] = 0;
   out_7807598111055713348[51] = 0;
   out_7807598111055713348[52] = 0;
   out_7807598111055713348[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_8743902382867857614) {
  err_fun(nom_x, delta_x, out_8743902382867857614);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3636694381902544351) {
  inv_err_fun(nom_x, true_x, out_3636694381902544351);
}
void pose_H_mod_fun(double *state, double *out_2152190311268096506) {
  H_mod_fun(state, out_2152190311268096506);
}
void pose_f_fun(double *state, double dt, double *out_5042547316032857663) {
  f_fun(state,  dt, out_5042547316032857663);
}
void pose_F_fun(double *state, double dt, double *out_6708996175305477877) {
  F_fun(state,  dt, out_6708996175305477877);
}
void pose_h_4(double *state, double *unused, double *out_3603221658780671100) {
  h_4(state, unused, out_3603221658780671100);
}
void pose_H_4(double *state, double *unused, double *out_7556357530358465972) {
  H_4(state, unused, out_7556357530358465972);
}
void pose_h_10(double *state, double *unused, double *out_8258563454346399047) {
  h_10(state, unused, out_8258563454346399047);
}
void pose_H_10(double *state, double *unused, double *out_2735534763065741146) {
  H_10(state, unused, out_2735534763065741146);
}
void pose_h_13(double *state, double *unused, double *out_7576910815427407655) {
  h_13(state, unused, out_7576910815427407655);
}
void pose_H_13(double *state, double *unused, double *out_4344083705026133171) {
  H_13(state, unused, out_4344083705026133171);
}
void pose_h_14(double *state, double *unused, double *out_984451843965455601) {
  h_14(state, unused, out_984451843965455601);
}
void pose_H_14(double *state, double *unused, double *out_7807598111055713348) {
  H_14(state, unused, out_7807598111055713348);
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
