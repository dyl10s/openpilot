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
void err_fun(double *nom_x, double *delta_x, double *out_5896214411466158685) {
   out_5896214411466158685[0] = delta_x[0] + nom_x[0];
   out_5896214411466158685[1] = delta_x[1] + nom_x[1];
   out_5896214411466158685[2] = delta_x[2] + nom_x[2];
   out_5896214411466158685[3] = delta_x[3] + nom_x[3];
   out_5896214411466158685[4] = delta_x[4] + nom_x[4];
   out_5896214411466158685[5] = delta_x[5] + nom_x[5];
   out_5896214411466158685[6] = delta_x[6] + nom_x[6];
   out_5896214411466158685[7] = delta_x[7] + nom_x[7];
   out_5896214411466158685[8] = delta_x[8] + nom_x[8];
   out_5896214411466158685[9] = delta_x[9] + nom_x[9];
   out_5896214411466158685[10] = delta_x[10] + nom_x[10];
   out_5896214411466158685[11] = delta_x[11] + nom_x[11];
   out_5896214411466158685[12] = delta_x[12] + nom_x[12];
   out_5896214411466158685[13] = delta_x[13] + nom_x[13];
   out_5896214411466158685[14] = delta_x[14] + nom_x[14];
   out_5896214411466158685[15] = delta_x[15] + nom_x[15];
   out_5896214411466158685[16] = delta_x[16] + nom_x[16];
   out_5896214411466158685[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2659108696170388183) {
   out_2659108696170388183[0] = -nom_x[0] + true_x[0];
   out_2659108696170388183[1] = -nom_x[1] + true_x[1];
   out_2659108696170388183[2] = -nom_x[2] + true_x[2];
   out_2659108696170388183[3] = -nom_x[3] + true_x[3];
   out_2659108696170388183[4] = -nom_x[4] + true_x[4];
   out_2659108696170388183[5] = -nom_x[5] + true_x[5];
   out_2659108696170388183[6] = -nom_x[6] + true_x[6];
   out_2659108696170388183[7] = -nom_x[7] + true_x[7];
   out_2659108696170388183[8] = -nom_x[8] + true_x[8];
   out_2659108696170388183[9] = -nom_x[9] + true_x[9];
   out_2659108696170388183[10] = -nom_x[10] + true_x[10];
   out_2659108696170388183[11] = -nom_x[11] + true_x[11];
   out_2659108696170388183[12] = -nom_x[12] + true_x[12];
   out_2659108696170388183[13] = -nom_x[13] + true_x[13];
   out_2659108696170388183[14] = -nom_x[14] + true_x[14];
   out_2659108696170388183[15] = -nom_x[15] + true_x[15];
   out_2659108696170388183[16] = -nom_x[16] + true_x[16];
   out_2659108696170388183[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7168960818524543120) {
   out_7168960818524543120[0] = 1.0;
   out_7168960818524543120[1] = 0.0;
   out_7168960818524543120[2] = 0.0;
   out_7168960818524543120[3] = 0.0;
   out_7168960818524543120[4] = 0.0;
   out_7168960818524543120[5] = 0.0;
   out_7168960818524543120[6] = 0.0;
   out_7168960818524543120[7] = 0.0;
   out_7168960818524543120[8] = 0.0;
   out_7168960818524543120[9] = 0.0;
   out_7168960818524543120[10] = 0.0;
   out_7168960818524543120[11] = 0.0;
   out_7168960818524543120[12] = 0.0;
   out_7168960818524543120[13] = 0.0;
   out_7168960818524543120[14] = 0.0;
   out_7168960818524543120[15] = 0.0;
   out_7168960818524543120[16] = 0.0;
   out_7168960818524543120[17] = 0.0;
   out_7168960818524543120[18] = 0.0;
   out_7168960818524543120[19] = 1.0;
   out_7168960818524543120[20] = 0.0;
   out_7168960818524543120[21] = 0.0;
   out_7168960818524543120[22] = 0.0;
   out_7168960818524543120[23] = 0.0;
   out_7168960818524543120[24] = 0.0;
   out_7168960818524543120[25] = 0.0;
   out_7168960818524543120[26] = 0.0;
   out_7168960818524543120[27] = 0.0;
   out_7168960818524543120[28] = 0.0;
   out_7168960818524543120[29] = 0.0;
   out_7168960818524543120[30] = 0.0;
   out_7168960818524543120[31] = 0.0;
   out_7168960818524543120[32] = 0.0;
   out_7168960818524543120[33] = 0.0;
   out_7168960818524543120[34] = 0.0;
   out_7168960818524543120[35] = 0.0;
   out_7168960818524543120[36] = 0.0;
   out_7168960818524543120[37] = 0.0;
   out_7168960818524543120[38] = 1.0;
   out_7168960818524543120[39] = 0.0;
   out_7168960818524543120[40] = 0.0;
   out_7168960818524543120[41] = 0.0;
   out_7168960818524543120[42] = 0.0;
   out_7168960818524543120[43] = 0.0;
   out_7168960818524543120[44] = 0.0;
   out_7168960818524543120[45] = 0.0;
   out_7168960818524543120[46] = 0.0;
   out_7168960818524543120[47] = 0.0;
   out_7168960818524543120[48] = 0.0;
   out_7168960818524543120[49] = 0.0;
   out_7168960818524543120[50] = 0.0;
   out_7168960818524543120[51] = 0.0;
   out_7168960818524543120[52] = 0.0;
   out_7168960818524543120[53] = 0.0;
   out_7168960818524543120[54] = 0.0;
   out_7168960818524543120[55] = 0.0;
   out_7168960818524543120[56] = 0.0;
   out_7168960818524543120[57] = 1.0;
   out_7168960818524543120[58] = 0.0;
   out_7168960818524543120[59] = 0.0;
   out_7168960818524543120[60] = 0.0;
   out_7168960818524543120[61] = 0.0;
   out_7168960818524543120[62] = 0.0;
   out_7168960818524543120[63] = 0.0;
   out_7168960818524543120[64] = 0.0;
   out_7168960818524543120[65] = 0.0;
   out_7168960818524543120[66] = 0.0;
   out_7168960818524543120[67] = 0.0;
   out_7168960818524543120[68] = 0.0;
   out_7168960818524543120[69] = 0.0;
   out_7168960818524543120[70] = 0.0;
   out_7168960818524543120[71] = 0.0;
   out_7168960818524543120[72] = 0.0;
   out_7168960818524543120[73] = 0.0;
   out_7168960818524543120[74] = 0.0;
   out_7168960818524543120[75] = 0.0;
   out_7168960818524543120[76] = 1.0;
   out_7168960818524543120[77] = 0.0;
   out_7168960818524543120[78] = 0.0;
   out_7168960818524543120[79] = 0.0;
   out_7168960818524543120[80] = 0.0;
   out_7168960818524543120[81] = 0.0;
   out_7168960818524543120[82] = 0.0;
   out_7168960818524543120[83] = 0.0;
   out_7168960818524543120[84] = 0.0;
   out_7168960818524543120[85] = 0.0;
   out_7168960818524543120[86] = 0.0;
   out_7168960818524543120[87] = 0.0;
   out_7168960818524543120[88] = 0.0;
   out_7168960818524543120[89] = 0.0;
   out_7168960818524543120[90] = 0.0;
   out_7168960818524543120[91] = 0.0;
   out_7168960818524543120[92] = 0.0;
   out_7168960818524543120[93] = 0.0;
   out_7168960818524543120[94] = 0.0;
   out_7168960818524543120[95] = 1.0;
   out_7168960818524543120[96] = 0.0;
   out_7168960818524543120[97] = 0.0;
   out_7168960818524543120[98] = 0.0;
   out_7168960818524543120[99] = 0.0;
   out_7168960818524543120[100] = 0.0;
   out_7168960818524543120[101] = 0.0;
   out_7168960818524543120[102] = 0.0;
   out_7168960818524543120[103] = 0.0;
   out_7168960818524543120[104] = 0.0;
   out_7168960818524543120[105] = 0.0;
   out_7168960818524543120[106] = 0.0;
   out_7168960818524543120[107] = 0.0;
   out_7168960818524543120[108] = 0.0;
   out_7168960818524543120[109] = 0.0;
   out_7168960818524543120[110] = 0.0;
   out_7168960818524543120[111] = 0.0;
   out_7168960818524543120[112] = 0.0;
   out_7168960818524543120[113] = 0.0;
   out_7168960818524543120[114] = 1.0;
   out_7168960818524543120[115] = 0.0;
   out_7168960818524543120[116] = 0.0;
   out_7168960818524543120[117] = 0.0;
   out_7168960818524543120[118] = 0.0;
   out_7168960818524543120[119] = 0.0;
   out_7168960818524543120[120] = 0.0;
   out_7168960818524543120[121] = 0.0;
   out_7168960818524543120[122] = 0.0;
   out_7168960818524543120[123] = 0.0;
   out_7168960818524543120[124] = 0.0;
   out_7168960818524543120[125] = 0.0;
   out_7168960818524543120[126] = 0.0;
   out_7168960818524543120[127] = 0.0;
   out_7168960818524543120[128] = 0.0;
   out_7168960818524543120[129] = 0.0;
   out_7168960818524543120[130] = 0.0;
   out_7168960818524543120[131] = 0.0;
   out_7168960818524543120[132] = 0.0;
   out_7168960818524543120[133] = 1.0;
   out_7168960818524543120[134] = 0.0;
   out_7168960818524543120[135] = 0.0;
   out_7168960818524543120[136] = 0.0;
   out_7168960818524543120[137] = 0.0;
   out_7168960818524543120[138] = 0.0;
   out_7168960818524543120[139] = 0.0;
   out_7168960818524543120[140] = 0.0;
   out_7168960818524543120[141] = 0.0;
   out_7168960818524543120[142] = 0.0;
   out_7168960818524543120[143] = 0.0;
   out_7168960818524543120[144] = 0.0;
   out_7168960818524543120[145] = 0.0;
   out_7168960818524543120[146] = 0.0;
   out_7168960818524543120[147] = 0.0;
   out_7168960818524543120[148] = 0.0;
   out_7168960818524543120[149] = 0.0;
   out_7168960818524543120[150] = 0.0;
   out_7168960818524543120[151] = 0.0;
   out_7168960818524543120[152] = 1.0;
   out_7168960818524543120[153] = 0.0;
   out_7168960818524543120[154] = 0.0;
   out_7168960818524543120[155] = 0.0;
   out_7168960818524543120[156] = 0.0;
   out_7168960818524543120[157] = 0.0;
   out_7168960818524543120[158] = 0.0;
   out_7168960818524543120[159] = 0.0;
   out_7168960818524543120[160] = 0.0;
   out_7168960818524543120[161] = 0.0;
   out_7168960818524543120[162] = 0.0;
   out_7168960818524543120[163] = 0.0;
   out_7168960818524543120[164] = 0.0;
   out_7168960818524543120[165] = 0.0;
   out_7168960818524543120[166] = 0.0;
   out_7168960818524543120[167] = 0.0;
   out_7168960818524543120[168] = 0.0;
   out_7168960818524543120[169] = 0.0;
   out_7168960818524543120[170] = 0.0;
   out_7168960818524543120[171] = 1.0;
   out_7168960818524543120[172] = 0.0;
   out_7168960818524543120[173] = 0.0;
   out_7168960818524543120[174] = 0.0;
   out_7168960818524543120[175] = 0.0;
   out_7168960818524543120[176] = 0.0;
   out_7168960818524543120[177] = 0.0;
   out_7168960818524543120[178] = 0.0;
   out_7168960818524543120[179] = 0.0;
   out_7168960818524543120[180] = 0.0;
   out_7168960818524543120[181] = 0.0;
   out_7168960818524543120[182] = 0.0;
   out_7168960818524543120[183] = 0.0;
   out_7168960818524543120[184] = 0.0;
   out_7168960818524543120[185] = 0.0;
   out_7168960818524543120[186] = 0.0;
   out_7168960818524543120[187] = 0.0;
   out_7168960818524543120[188] = 0.0;
   out_7168960818524543120[189] = 0.0;
   out_7168960818524543120[190] = 1.0;
   out_7168960818524543120[191] = 0.0;
   out_7168960818524543120[192] = 0.0;
   out_7168960818524543120[193] = 0.0;
   out_7168960818524543120[194] = 0.0;
   out_7168960818524543120[195] = 0.0;
   out_7168960818524543120[196] = 0.0;
   out_7168960818524543120[197] = 0.0;
   out_7168960818524543120[198] = 0.0;
   out_7168960818524543120[199] = 0.0;
   out_7168960818524543120[200] = 0.0;
   out_7168960818524543120[201] = 0.0;
   out_7168960818524543120[202] = 0.0;
   out_7168960818524543120[203] = 0.0;
   out_7168960818524543120[204] = 0.0;
   out_7168960818524543120[205] = 0.0;
   out_7168960818524543120[206] = 0.0;
   out_7168960818524543120[207] = 0.0;
   out_7168960818524543120[208] = 0.0;
   out_7168960818524543120[209] = 1.0;
   out_7168960818524543120[210] = 0.0;
   out_7168960818524543120[211] = 0.0;
   out_7168960818524543120[212] = 0.0;
   out_7168960818524543120[213] = 0.0;
   out_7168960818524543120[214] = 0.0;
   out_7168960818524543120[215] = 0.0;
   out_7168960818524543120[216] = 0.0;
   out_7168960818524543120[217] = 0.0;
   out_7168960818524543120[218] = 0.0;
   out_7168960818524543120[219] = 0.0;
   out_7168960818524543120[220] = 0.0;
   out_7168960818524543120[221] = 0.0;
   out_7168960818524543120[222] = 0.0;
   out_7168960818524543120[223] = 0.0;
   out_7168960818524543120[224] = 0.0;
   out_7168960818524543120[225] = 0.0;
   out_7168960818524543120[226] = 0.0;
   out_7168960818524543120[227] = 0.0;
   out_7168960818524543120[228] = 1.0;
   out_7168960818524543120[229] = 0.0;
   out_7168960818524543120[230] = 0.0;
   out_7168960818524543120[231] = 0.0;
   out_7168960818524543120[232] = 0.0;
   out_7168960818524543120[233] = 0.0;
   out_7168960818524543120[234] = 0.0;
   out_7168960818524543120[235] = 0.0;
   out_7168960818524543120[236] = 0.0;
   out_7168960818524543120[237] = 0.0;
   out_7168960818524543120[238] = 0.0;
   out_7168960818524543120[239] = 0.0;
   out_7168960818524543120[240] = 0.0;
   out_7168960818524543120[241] = 0.0;
   out_7168960818524543120[242] = 0.0;
   out_7168960818524543120[243] = 0.0;
   out_7168960818524543120[244] = 0.0;
   out_7168960818524543120[245] = 0.0;
   out_7168960818524543120[246] = 0.0;
   out_7168960818524543120[247] = 1.0;
   out_7168960818524543120[248] = 0.0;
   out_7168960818524543120[249] = 0.0;
   out_7168960818524543120[250] = 0.0;
   out_7168960818524543120[251] = 0.0;
   out_7168960818524543120[252] = 0.0;
   out_7168960818524543120[253] = 0.0;
   out_7168960818524543120[254] = 0.0;
   out_7168960818524543120[255] = 0.0;
   out_7168960818524543120[256] = 0.0;
   out_7168960818524543120[257] = 0.0;
   out_7168960818524543120[258] = 0.0;
   out_7168960818524543120[259] = 0.0;
   out_7168960818524543120[260] = 0.0;
   out_7168960818524543120[261] = 0.0;
   out_7168960818524543120[262] = 0.0;
   out_7168960818524543120[263] = 0.0;
   out_7168960818524543120[264] = 0.0;
   out_7168960818524543120[265] = 0.0;
   out_7168960818524543120[266] = 1.0;
   out_7168960818524543120[267] = 0.0;
   out_7168960818524543120[268] = 0.0;
   out_7168960818524543120[269] = 0.0;
   out_7168960818524543120[270] = 0.0;
   out_7168960818524543120[271] = 0.0;
   out_7168960818524543120[272] = 0.0;
   out_7168960818524543120[273] = 0.0;
   out_7168960818524543120[274] = 0.0;
   out_7168960818524543120[275] = 0.0;
   out_7168960818524543120[276] = 0.0;
   out_7168960818524543120[277] = 0.0;
   out_7168960818524543120[278] = 0.0;
   out_7168960818524543120[279] = 0.0;
   out_7168960818524543120[280] = 0.0;
   out_7168960818524543120[281] = 0.0;
   out_7168960818524543120[282] = 0.0;
   out_7168960818524543120[283] = 0.0;
   out_7168960818524543120[284] = 0.0;
   out_7168960818524543120[285] = 1.0;
   out_7168960818524543120[286] = 0.0;
   out_7168960818524543120[287] = 0.0;
   out_7168960818524543120[288] = 0.0;
   out_7168960818524543120[289] = 0.0;
   out_7168960818524543120[290] = 0.0;
   out_7168960818524543120[291] = 0.0;
   out_7168960818524543120[292] = 0.0;
   out_7168960818524543120[293] = 0.0;
   out_7168960818524543120[294] = 0.0;
   out_7168960818524543120[295] = 0.0;
   out_7168960818524543120[296] = 0.0;
   out_7168960818524543120[297] = 0.0;
   out_7168960818524543120[298] = 0.0;
   out_7168960818524543120[299] = 0.0;
   out_7168960818524543120[300] = 0.0;
   out_7168960818524543120[301] = 0.0;
   out_7168960818524543120[302] = 0.0;
   out_7168960818524543120[303] = 0.0;
   out_7168960818524543120[304] = 1.0;
   out_7168960818524543120[305] = 0.0;
   out_7168960818524543120[306] = 0.0;
   out_7168960818524543120[307] = 0.0;
   out_7168960818524543120[308] = 0.0;
   out_7168960818524543120[309] = 0.0;
   out_7168960818524543120[310] = 0.0;
   out_7168960818524543120[311] = 0.0;
   out_7168960818524543120[312] = 0.0;
   out_7168960818524543120[313] = 0.0;
   out_7168960818524543120[314] = 0.0;
   out_7168960818524543120[315] = 0.0;
   out_7168960818524543120[316] = 0.0;
   out_7168960818524543120[317] = 0.0;
   out_7168960818524543120[318] = 0.0;
   out_7168960818524543120[319] = 0.0;
   out_7168960818524543120[320] = 0.0;
   out_7168960818524543120[321] = 0.0;
   out_7168960818524543120[322] = 0.0;
   out_7168960818524543120[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5063918395653700509) {
   out_5063918395653700509[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5063918395653700509[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5063918395653700509[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5063918395653700509[3] = dt*state[12] + state[3];
   out_5063918395653700509[4] = dt*state[13] + state[4];
   out_5063918395653700509[5] = dt*state[14] + state[5];
   out_5063918395653700509[6] = state[6];
   out_5063918395653700509[7] = state[7];
   out_5063918395653700509[8] = state[8];
   out_5063918395653700509[9] = state[9];
   out_5063918395653700509[10] = state[10];
   out_5063918395653700509[11] = state[11];
   out_5063918395653700509[12] = state[12];
   out_5063918395653700509[13] = state[13];
   out_5063918395653700509[14] = state[14];
   out_5063918395653700509[15] = state[15];
   out_5063918395653700509[16] = state[16];
   out_5063918395653700509[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4470005302657516726) {
   out_4470005302657516726[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4470005302657516726[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4470005302657516726[2] = 0;
   out_4470005302657516726[3] = 0;
   out_4470005302657516726[4] = 0;
   out_4470005302657516726[5] = 0;
   out_4470005302657516726[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4470005302657516726[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4470005302657516726[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4470005302657516726[9] = 0;
   out_4470005302657516726[10] = 0;
   out_4470005302657516726[11] = 0;
   out_4470005302657516726[12] = 0;
   out_4470005302657516726[13] = 0;
   out_4470005302657516726[14] = 0;
   out_4470005302657516726[15] = 0;
   out_4470005302657516726[16] = 0;
   out_4470005302657516726[17] = 0;
   out_4470005302657516726[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4470005302657516726[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4470005302657516726[20] = 0;
   out_4470005302657516726[21] = 0;
   out_4470005302657516726[22] = 0;
   out_4470005302657516726[23] = 0;
   out_4470005302657516726[24] = 0;
   out_4470005302657516726[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4470005302657516726[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4470005302657516726[27] = 0;
   out_4470005302657516726[28] = 0;
   out_4470005302657516726[29] = 0;
   out_4470005302657516726[30] = 0;
   out_4470005302657516726[31] = 0;
   out_4470005302657516726[32] = 0;
   out_4470005302657516726[33] = 0;
   out_4470005302657516726[34] = 0;
   out_4470005302657516726[35] = 0;
   out_4470005302657516726[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4470005302657516726[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4470005302657516726[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4470005302657516726[39] = 0;
   out_4470005302657516726[40] = 0;
   out_4470005302657516726[41] = 0;
   out_4470005302657516726[42] = 0;
   out_4470005302657516726[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4470005302657516726[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4470005302657516726[45] = 0;
   out_4470005302657516726[46] = 0;
   out_4470005302657516726[47] = 0;
   out_4470005302657516726[48] = 0;
   out_4470005302657516726[49] = 0;
   out_4470005302657516726[50] = 0;
   out_4470005302657516726[51] = 0;
   out_4470005302657516726[52] = 0;
   out_4470005302657516726[53] = 0;
   out_4470005302657516726[54] = 0;
   out_4470005302657516726[55] = 0;
   out_4470005302657516726[56] = 0;
   out_4470005302657516726[57] = 1;
   out_4470005302657516726[58] = 0;
   out_4470005302657516726[59] = 0;
   out_4470005302657516726[60] = 0;
   out_4470005302657516726[61] = 0;
   out_4470005302657516726[62] = 0;
   out_4470005302657516726[63] = 0;
   out_4470005302657516726[64] = 0;
   out_4470005302657516726[65] = 0;
   out_4470005302657516726[66] = dt;
   out_4470005302657516726[67] = 0;
   out_4470005302657516726[68] = 0;
   out_4470005302657516726[69] = 0;
   out_4470005302657516726[70] = 0;
   out_4470005302657516726[71] = 0;
   out_4470005302657516726[72] = 0;
   out_4470005302657516726[73] = 0;
   out_4470005302657516726[74] = 0;
   out_4470005302657516726[75] = 0;
   out_4470005302657516726[76] = 1;
   out_4470005302657516726[77] = 0;
   out_4470005302657516726[78] = 0;
   out_4470005302657516726[79] = 0;
   out_4470005302657516726[80] = 0;
   out_4470005302657516726[81] = 0;
   out_4470005302657516726[82] = 0;
   out_4470005302657516726[83] = 0;
   out_4470005302657516726[84] = 0;
   out_4470005302657516726[85] = dt;
   out_4470005302657516726[86] = 0;
   out_4470005302657516726[87] = 0;
   out_4470005302657516726[88] = 0;
   out_4470005302657516726[89] = 0;
   out_4470005302657516726[90] = 0;
   out_4470005302657516726[91] = 0;
   out_4470005302657516726[92] = 0;
   out_4470005302657516726[93] = 0;
   out_4470005302657516726[94] = 0;
   out_4470005302657516726[95] = 1;
   out_4470005302657516726[96] = 0;
   out_4470005302657516726[97] = 0;
   out_4470005302657516726[98] = 0;
   out_4470005302657516726[99] = 0;
   out_4470005302657516726[100] = 0;
   out_4470005302657516726[101] = 0;
   out_4470005302657516726[102] = 0;
   out_4470005302657516726[103] = 0;
   out_4470005302657516726[104] = dt;
   out_4470005302657516726[105] = 0;
   out_4470005302657516726[106] = 0;
   out_4470005302657516726[107] = 0;
   out_4470005302657516726[108] = 0;
   out_4470005302657516726[109] = 0;
   out_4470005302657516726[110] = 0;
   out_4470005302657516726[111] = 0;
   out_4470005302657516726[112] = 0;
   out_4470005302657516726[113] = 0;
   out_4470005302657516726[114] = 1;
   out_4470005302657516726[115] = 0;
   out_4470005302657516726[116] = 0;
   out_4470005302657516726[117] = 0;
   out_4470005302657516726[118] = 0;
   out_4470005302657516726[119] = 0;
   out_4470005302657516726[120] = 0;
   out_4470005302657516726[121] = 0;
   out_4470005302657516726[122] = 0;
   out_4470005302657516726[123] = 0;
   out_4470005302657516726[124] = 0;
   out_4470005302657516726[125] = 0;
   out_4470005302657516726[126] = 0;
   out_4470005302657516726[127] = 0;
   out_4470005302657516726[128] = 0;
   out_4470005302657516726[129] = 0;
   out_4470005302657516726[130] = 0;
   out_4470005302657516726[131] = 0;
   out_4470005302657516726[132] = 0;
   out_4470005302657516726[133] = 1;
   out_4470005302657516726[134] = 0;
   out_4470005302657516726[135] = 0;
   out_4470005302657516726[136] = 0;
   out_4470005302657516726[137] = 0;
   out_4470005302657516726[138] = 0;
   out_4470005302657516726[139] = 0;
   out_4470005302657516726[140] = 0;
   out_4470005302657516726[141] = 0;
   out_4470005302657516726[142] = 0;
   out_4470005302657516726[143] = 0;
   out_4470005302657516726[144] = 0;
   out_4470005302657516726[145] = 0;
   out_4470005302657516726[146] = 0;
   out_4470005302657516726[147] = 0;
   out_4470005302657516726[148] = 0;
   out_4470005302657516726[149] = 0;
   out_4470005302657516726[150] = 0;
   out_4470005302657516726[151] = 0;
   out_4470005302657516726[152] = 1;
   out_4470005302657516726[153] = 0;
   out_4470005302657516726[154] = 0;
   out_4470005302657516726[155] = 0;
   out_4470005302657516726[156] = 0;
   out_4470005302657516726[157] = 0;
   out_4470005302657516726[158] = 0;
   out_4470005302657516726[159] = 0;
   out_4470005302657516726[160] = 0;
   out_4470005302657516726[161] = 0;
   out_4470005302657516726[162] = 0;
   out_4470005302657516726[163] = 0;
   out_4470005302657516726[164] = 0;
   out_4470005302657516726[165] = 0;
   out_4470005302657516726[166] = 0;
   out_4470005302657516726[167] = 0;
   out_4470005302657516726[168] = 0;
   out_4470005302657516726[169] = 0;
   out_4470005302657516726[170] = 0;
   out_4470005302657516726[171] = 1;
   out_4470005302657516726[172] = 0;
   out_4470005302657516726[173] = 0;
   out_4470005302657516726[174] = 0;
   out_4470005302657516726[175] = 0;
   out_4470005302657516726[176] = 0;
   out_4470005302657516726[177] = 0;
   out_4470005302657516726[178] = 0;
   out_4470005302657516726[179] = 0;
   out_4470005302657516726[180] = 0;
   out_4470005302657516726[181] = 0;
   out_4470005302657516726[182] = 0;
   out_4470005302657516726[183] = 0;
   out_4470005302657516726[184] = 0;
   out_4470005302657516726[185] = 0;
   out_4470005302657516726[186] = 0;
   out_4470005302657516726[187] = 0;
   out_4470005302657516726[188] = 0;
   out_4470005302657516726[189] = 0;
   out_4470005302657516726[190] = 1;
   out_4470005302657516726[191] = 0;
   out_4470005302657516726[192] = 0;
   out_4470005302657516726[193] = 0;
   out_4470005302657516726[194] = 0;
   out_4470005302657516726[195] = 0;
   out_4470005302657516726[196] = 0;
   out_4470005302657516726[197] = 0;
   out_4470005302657516726[198] = 0;
   out_4470005302657516726[199] = 0;
   out_4470005302657516726[200] = 0;
   out_4470005302657516726[201] = 0;
   out_4470005302657516726[202] = 0;
   out_4470005302657516726[203] = 0;
   out_4470005302657516726[204] = 0;
   out_4470005302657516726[205] = 0;
   out_4470005302657516726[206] = 0;
   out_4470005302657516726[207] = 0;
   out_4470005302657516726[208] = 0;
   out_4470005302657516726[209] = 1;
   out_4470005302657516726[210] = 0;
   out_4470005302657516726[211] = 0;
   out_4470005302657516726[212] = 0;
   out_4470005302657516726[213] = 0;
   out_4470005302657516726[214] = 0;
   out_4470005302657516726[215] = 0;
   out_4470005302657516726[216] = 0;
   out_4470005302657516726[217] = 0;
   out_4470005302657516726[218] = 0;
   out_4470005302657516726[219] = 0;
   out_4470005302657516726[220] = 0;
   out_4470005302657516726[221] = 0;
   out_4470005302657516726[222] = 0;
   out_4470005302657516726[223] = 0;
   out_4470005302657516726[224] = 0;
   out_4470005302657516726[225] = 0;
   out_4470005302657516726[226] = 0;
   out_4470005302657516726[227] = 0;
   out_4470005302657516726[228] = 1;
   out_4470005302657516726[229] = 0;
   out_4470005302657516726[230] = 0;
   out_4470005302657516726[231] = 0;
   out_4470005302657516726[232] = 0;
   out_4470005302657516726[233] = 0;
   out_4470005302657516726[234] = 0;
   out_4470005302657516726[235] = 0;
   out_4470005302657516726[236] = 0;
   out_4470005302657516726[237] = 0;
   out_4470005302657516726[238] = 0;
   out_4470005302657516726[239] = 0;
   out_4470005302657516726[240] = 0;
   out_4470005302657516726[241] = 0;
   out_4470005302657516726[242] = 0;
   out_4470005302657516726[243] = 0;
   out_4470005302657516726[244] = 0;
   out_4470005302657516726[245] = 0;
   out_4470005302657516726[246] = 0;
   out_4470005302657516726[247] = 1;
   out_4470005302657516726[248] = 0;
   out_4470005302657516726[249] = 0;
   out_4470005302657516726[250] = 0;
   out_4470005302657516726[251] = 0;
   out_4470005302657516726[252] = 0;
   out_4470005302657516726[253] = 0;
   out_4470005302657516726[254] = 0;
   out_4470005302657516726[255] = 0;
   out_4470005302657516726[256] = 0;
   out_4470005302657516726[257] = 0;
   out_4470005302657516726[258] = 0;
   out_4470005302657516726[259] = 0;
   out_4470005302657516726[260] = 0;
   out_4470005302657516726[261] = 0;
   out_4470005302657516726[262] = 0;
   out_4470005302657516726[263] = 0;
   out_4470005302657516726[264] = 0;
   out_4470005302657516726[265] = 0;
   out_4470005302657516726[266] = 1;
   out_4470005302657516726[267] = 0;
   out_4470005302657516726[268] = 0;
   out_4470005302657516726[269] = 0;
   out_4470005302657516726[270] = 0;
   out_4470005302657516726[271] = 0;
   out_4470005302657516726[272] = 0;
   out_4470005302657516726[273] = 0;
   out_4470005302657516726[274] = 0;
   out_4470005302657516726[275] = 0;
   out_4470005302657516726[276] = 0;
   out_4470005302657516726[277] = 0;
   out_4470005302657516726[278] = 0;
   out_4470005302657516726[279] = 0;
   out_4470005302657516726[280] = 0;
   out_4470005302657516726[281] = 0;
   out_4470005302657516726[282] = 0;
   out_4470005302657516726[283] = 0;
   out_4470005302657516726[284] = 0;
   out_4470005302657516726[285] = 1;
   out_4470005302657516726[286] = 0;
   out_4470005302657516726[287] = 0;
   out_4470005302657516726[288] = 0;
   out_4470005302657516726[289] = 0;
   out_4470005302657516726[290] = 0;
   out_4470005302657516726[291] = 0;
   out_4470005302657516726[292] = 0;
   out_4470005302657516726[293] = 0;
   out_4470005302657516726[294] = 0;
   out_4470005302657516726[295] = 0;
   out_4470005302657516726[296] = 0;
   out_4470005302657516726[297] = 0;
   out_4470005302657516726[298] = 0;
   out_4470005302657516726[299] = 0;
   out_4470005302657516726[300] = 0;
   out_4470005302657516726[301] = 0;
   out_4470005302657516726[302] = 0;
   out_4470005302657516726[303] = 0;
   out_4470005302657516726[304] = 1;
   out_4470005302657516726[305] = 0;
   out_4470005302657516726[306] = 0;
   out_4470005302657516726[307] = 0;
   out_4470005302657516726[308] = 0;
   out_4470005302657516726[309] = 0;
   out_4470005302657516726[310] = 0;
   out_4470005302657516726[311] = 0;
   out_4470005302657516726[312] = 0;
   out_4470005302657516726[313] = 0;
   out_4470005302657516726[314] = 0;
   out_4470005302657516726[315] = 0;
   out_4470005302657516726[316] = 0;
   out_4470005302657516726[317] = 0;
   out_4470005302657516726[318] = 0;
   out_4470005302657516726[319] = 0;
   out_4470005302657516726[320] = 0;
   out_4470005302657516726[321] = 0;
   out_4470005302657516726[322] = 0;
   out_4470005302657516726[323] = 1;
}
void h_4(double *state, double *unused, double *out_6574127459206923931) {
   out_6574127459206923931[0] = state[6] + state[9];
   out_6574127459206923931[1] = state[7] + state[10];
   out_6574127459206923931[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8003561176394059243) {
   out_8003561176394059243[0] = 0;
   out_8003561176394059243[1] = 0;
   out_8003561176394059243[2] = 0;
   out_8003561176394059243[3] = 0;
   out_8003561176394059243[4] = 0;
   out_8003561176394059243[5] = 0;
   out_8003561176394059243[6] = 1;
   out_8003561176394059243[7] = 0;
   out_8003561176394059243[8] = 0;
   out_8003561176394059243[9] = 1;
   out_8003561176394059243[10] = 0;
   out_8003561176394059243[11] = 0;
   out_8003561176394059243[12] = 0;
   out_8003561176394059243[13] = 0;
   out_8003561176394059243[14] = 0;
   out_8003561176394059243[15] = 0;
   out_8003561176394059243[16] = 0;
   out_8003561176394059243[17] = 0;
   out_8003561176394059243[18] = 0;
   out_8003561176394059243[19] = 0;
   out_8003561176394059243[20] = 0;
   out_8003561176394059243[21] = 0;
   out_8003561176394059243[22] = 0;
   out_8003561176394059243[23] = 0;
   out_8003561176394059243[24] = 0;
   out_8003561176394059243[25] = 1;
   out_8003561176394059243[26] = 0;
   out_8003561176394059243[27] = 0;
   out_8003561176394059243[28] = 1;
   out_8003561176394059243[29] = 0;
   out_8003561176394059243[30] = 0;
   out_8003561176394059243[31] = 0;
   out_8003561176394059243[32] = 0;
   out_8003561176394059243[33] = 0;
   out_8003561176394059243[34] = 0;
   out_8003561176394059243[35] = 0;
   out_8003561176394059243[36] = 0;
   out_8003561176394059243[37] = 0;
   out_8003561176394059243[38] = 0;
   out_8003561176394059243[39] = 0;
   out_8003561176394059243[40] = 0;
   out_8003561176394059243[41] = 0;
   out_8003561176394059243[42] = 0;
   out_8003561176394059243[43] = 0;
   out_8003561176394059243[44] = 1;
   out_8003561176394059243[45] = 0;
   out_8003561176394059243[46] = 0;
   out_8003561176394059243[47] = 1;
   out_8003561176394059243[48] = 0;
   out_8003561176394059243[49] = 0;
   out_8003561176394059243[50] = 0;
   out_8003561176394059243[51] = 0;
   out_8003561176394059243[52] = 0;
   out_8003561176394059243[53] = 0;
}
void h_10(double *state, double *unused, double *out_5886867664906462198) {
   out_5886867664906462198[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5886867664906462198[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5886867664906462198[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6245929205097449476) {
   out_6245929205097449476[0] = 0;
   out_6245929205097449476[1] = 9.8100000000000005*cos(state[1]);
   out_6245929205097449476[2] = 0;
   out_6245929205097449476[3] = 0;
   out_6245929205097449476[4] = -state[8];
   out_6245929205097449476[5] = state[7];
   out_6245929205097449476[6] = 0;
   out_6245929205097449476[7] = state[5];
   out_6245929205097449476[8] = -state[4];
   out_6245929205097449476[9] = 0;
   out_6245929205097449476[10] = 0;
   out_6245929205097449476[11] = 0;
   out_6245929205097449476[12] = 1;
   out_6245929205097449476[13] = 0;
   out_6245929205097449476[14] = 0;
   out_6245929205097449476[15] = 1;
   out_6245929205097449476[16] = 0;
   out_6245929205097449476[17] = 0;
   out_6245929205097449476[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6245929205097449476[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6245929205097449476[20] = 0;
   out_6245929205097449476[21] = state[8];
   out_6245929205097449476[22] = 0;
   out_6245929205097449476[23] = -state[6];
   out_6245929205097449476[24] = -state[5];
   out_6245929205097449476[25] = 0;
   out_6245929205097449476[26] = state[3];
   out_6245929205097449476[27] = 0;
   out_6245929205097449476[28] = 0;
   out_6245929205097449476[29] = 0;
   out_6245929205097449476[30] = 0;
   out_6245929205097449476[31] = 1;
   out_6245929205097449476[32] = 0;
   out_6245929205097449476[33] = 0;
   out_6245929205097449476[34] = 1;
   out_6245929205097449476[35] = 0;
   out_6245929205097449476[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6245929205097449476[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6245929205097449476[38] = 0;
   out_6245929205097449476[39] = -state[7];
   out_6245929205097449476[40] = state[6];
   out_6245929205097449476[41] = 0;
   out_6245929205097449476[42] = state[4];
   out_6245929205097449476[43] = -state[3];
   out_6245929205097449476[44] = 0;
   out_6245929205097449476[45] = 0;
   out_6245929205097449476[46] = 0;
   out_6245929205097449476[47] = 0;
   out_6245929205097449476[48] = 0;
   out_6245929205097449476[49] = 0;
   out_6245929205097449476[50] = 1;
   out_6245929205097449476[51] = 0;
   out_6245929205097449476[52] = 0;
   out_6245929205097449476[53] = 1;
}
void h_13(double *state, double *unused, double *out_3309926433150949848) {
   out_3309926433150949848[0] = state[3];
   out_3309926433150949848[1] = state[4];
   out_3309926433150949848[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2832551688998791444) {
   out_2832551688998791444[0] = 0;
   out_2832551688998791444[1] = 0;
   out_2832551688998791444[2] = 0;
   out_2832551688998791444[3] = 1;
   out_2832551688998791444[4] = 0;
   out_2832551688998791444[5] = 0;
   out_2832551688998791444[6] = 0;
   out_2832551688998791444[7] = 0;
   out_2832551688998791444[8] = 0;
   out_2832551688998791444[9] = 0;
   out_2832551688998791444[10] = 0;
   out_2832551688998791444[11] = 0;
   out_2832551688998791444[12] = 0;
   out_2832551688998791444[13] = 0;
   out_2832551688998791444[14] = 0;
   out_2832551688998791444[15] = 0;
   out_2832551688998791444[16] = 0;
   out_2832551688998791444[17] = 0;
   out_2832551688998791444[18] = 0;
   out_2832551688998791444[19] = 0;
   out_2832551688998791444[20] = 0;
   out_2832551688998791444[21] = 0;
   out_2832551688998791444[22] = 1;
   out_2832551688998791444[23] = 0;
   out_2832551688998791444[24] = 0;
   out_2832551688998791444[25] = 0;
   out_2832551688998791444[26] = 0;
   out_2832551688998791444[27] = 0;
   out_2832551688998791444[28] = 0;
   out_2832551688998791444[29] = 0;
   out_2832551688998791444[30] = 0;
   out_2832551688998791444[31] = 0;
   out_2832551688998791444[32] = 0;
   out_2832551688998791444[33] = 0;
   out_2832551688998791444[34] = 0;
   out_2832551688998791444[35] = 0;
   out_2832551688998791444[36] = 0;
   out_2832551688998791444[37] = 0;
   out_2832551688998791444[38] = 0;
   out_2832551688998791444[39] = 0;
   out_2832551688998791444[40] = 0;
   out_2832551688998791444[41] = 1;
   out_2832551688998791444[42] = 0;
   out_2832551688998791444[43] = 0;
   out_2832551688998791444[44] = 0;
   out_2832551688998791444[45] = 0;
   out_2832551688998791444[46] = 0;
   out_2832551688998791444[47] = 0;
   out_2832551688998791444[48] = 0;
   out_2832551688998791444[49] = 0;
   out_2832551688998791444[50] = 0;
   out_2832551688998791444[51] = 0;
   out_2832551688998791444[52] = 0;
   out_2832551688998791444[53] = 0;
}
void h_14(double *state, double *unused, double *out_8057772104425340564) {
   out_8057772104425340564[0] = state[6];
   out_8057772104425340564[1] = state[7];
   out_8057772104425340564[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6479942040976007844) {
   out_6479942040976007844[0] = 0;
   out_6479942040976007844[1] = 0;
   out_6479942040976007844[2] = 0;
   out_6479942040976007844[3] = 0;
   out_6479942040976007844[4] = 0;
   out_6479942040976007844[5] = 0;
   out_6479942040976007844[6] = 1;
   out_6479942040976007844[7] = 0;
   out_6479942040976007844[8] = 0;
   out_6479942040976007844[9] = 0;
   out_6479942040976007844[10] = 0;
   out_6479942040976007844[11] = 0;
   out_6479942040976007844[12] = 0;
   out_6479942040976007844[13] = 0;
   out_6479942040976007844[14] = 0;
   out_6479942040976007844[15] = 0;
   out_6479942040976007844[16] = 0;
   out_6479942040976007844[17] = 0;
   out_6479942040976007844[18] = 0;
   out_6479942040976007844[19] = 0;
   out_6479942040976007844[20] = 0;
   out_6479942040976007844[21] = 0;
   out_6479942040976007844[22] = 0;
   out_6479942040976007844[23] = 0;
   out_6479942040976007844[24] = 0;
   out_6479942040976007844[25] = 1;
   out_6479942040976007844[26] = 0;
   out_6479942040976007844[27] = 0;
   out_6479942040976007844[28] = 0;
   out_6479942040976007844[29] = 0;
   out_6479942040976007844[30] = 0;
   out_6479942040976007844[31] = 0;
   out_6479942040976007844[32] = 0;
   out_6479942040976007844[33] = 0;
   out_6479942040976007844[34] = 0;
   out_6479942040976007844[35] = 0;
   out_6479942040976007844[36] = 0;
   out_6479942040976007844[37] = 0;
   out_6479942040976007844[38] = 0;
   out_6479942040976007844[39] = 0;
   out_6479942040976007844[40] = 0;
   out_6479942040976007844[41] = 0;
   out_6479942040976007844[42] = 0;
   out_6479942040976007844[43] = 0;
   out_6479942040976007844[44] = 1;
   out_6479942040976007844[45] = 0;
   out_6479942040976007844[46] = 0;
   out_6479942040976007844[47] = 0;
   out_6479942040976007844[48] = 0;
   out_6479942040976007844[49] = 0;
   out_6479942040976007844[50] = 0;
   out_6479942040976007844[51] = 0;
   out_6479942040976007844[52] = 0;
   out_6479942040976007844[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_5896214411466158685) {
  err_fun(nom_x, delta_x, out_5896214411466158685);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2659108696170388183) {
  inv_err_fun(nom_x, true_x, out_2659108696170388183);
}
void pose_H_mod_fun(double *state, double *out_7168960818524543120) {
  H_mod_fun(state, out_7168960818524543120);
}
void pose_f_fun(double *state, double dt, double *out_5063918395653700509) {
  f_fun(state,  dt, out_5063918395653700509);
}
void pose_F_fun(double *state, double dt, double *out_4470005302657516726) {
  F_fun(state,  dt, out_4470005302657516726);
}
void pose_h_4(double *state, double *unused, double *out_6574127459206923931) {
  h_4(state, unused, out_6574127459206923931);
}
void pose_H_4(double *state, double *unused, double *out_8003561176394059243) {
  H_4(state, unused, out_8003561176394059243);
}
void pose_h_10(double *state, double *unused, double *out_5886867664906462198) {
  h_10(state, unused, out_5886867664906462198);
}
void pose_H_10(double *state, double *unused, double *out_6245929205097449476) {
  H_10(state, unused, out_6245929205097449476);
}
void pose_h_13(double *state, double *unused, double *out_3309926433150949848) {
  h_13(state, unused, out_3309926433150949848);
}
void pose_H_13(double *state, double *unused, double *out_2832551688998791444) {
  H_13(state, unused, out_2832551688998791444);
}
void pose_h_14(double *state, double *unused, double *out_8057772104425340564) {
  h_14(state, unused, out_8057772104425340564);
}
void pose_H_14(double *state, double *unused, double *out_6479942040976007844) {
  H_14(state, unused, out_6479942040976007844);
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
