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
void err_fun(double *nom_x, double *delta_x, double *out_3667758909157266385) {
   out_3667758909157266385[0] = delta_x[0] + nom_x[0];
   out_3667758909157266385[1] = delta_x[1] + nom_x[1];
   out_3667758909157266385[2] = delta_x[2] + nom_x[2];
   out_3667758909157266385[3] = delta_x[3] + nom_x[3];
   out_3667758909157266385[4] = delta_x[4] + nom_x[4];
   out_3667758909157266385[5] = delta_x[5] + nom_x[5];
   out_3667758909157266385[6] = delta_x[6] + nom_x[6];
   out_3667758909157266385[7] = delta_x[7] + nom_x[7];
   out_3667758909157266385[8] = delta_x[8] + nom_x[8];
   out_3667758909157266385[9] = delta_x[9] + nom_x[9];
   out_3667758909157266385[10] = delta_x[10] + nom_x[10];
   out_3667758909157266385[11] = delta_x[11] + nom_x[11];
   out_3667758909157266385[12] = delta_x[12] + nom_x[12];
   out_3667758909157266385[13] = delta_x[13] + nom_x[13];
   out_3667758909157266385[14] = delta_x[14] + nom_x[14];
   out_3667758909157266385[15] = delta_x[15] + nom_x[15];
   out_3667758909157266385[16] = delta_x[16] + nom_x[16];
   out_3667758909157266385[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3255008687637156165) {
   out_3255008687637156165[0] = -nom_x[0] + true_x[0];
   out_3255008687637156165[1] = -nom_x[1] + true_x[1];
   out_3255008687637156165[2] = -nom_x[2] + true_x[2];
   out_3255008687637156165[3] = -nom_x[3] + true_x[3];
   out_3255008687637156165[4] = -nom_x[4] + true_x[4];
   out_3255008687637156165[5] = -nom_x[5] + true_x[5];
   out_3255008687637156165[6] = -nom_x[6] + true_x[6];
   out_3255008687637156165[7] = -nom_x[7] + true_x[7];
   out_3255008687637156165[8] = -nom_x[8] + true_x[8];
   out_3255008687637156165[9] = -nom_x[9] + true_x[9];
   out_3255008687637156165[10] = -nom_x[10] + true_x[10];
   out_3255008687637156165[11] = -nom_x[11] + true_x[11];
   out_3255008687637156165[12] = -nom_x[12] + true_x[12];
   out_3255008687637156165[13] = -nom_x[13] + true_x[13];
   out_3255008687637156165[14] = -nom_x[14] + true_x[14];
   out_3255008687637156165[15] = -nom_x[15] + true_x[15];
   out_3255008687637156165[16] = -nom_x[16] + true_x[16];
   out_3255008687637156165[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1678148223451849404) {
   out_1678148223451849404[0] = 1.0;
   out_1678148223451849404[1] = 0.0;
   out_1678148223451849404[2] = 0.0;
   out_1678148223451849404[3] = 0.0;
   out_1678148223451849404[4] = 0.0;
   out_1678148223451849404[5] = 0.0;
   out_1678148223451849404[6] = 0.0;
   out_1678148223451849404[7] = 0.0;
   out_1678148223451849404[8] = 0.0;
   out_1678148223451849404[9] = 0.0;
   out_1678148223451849404[10] = 0.0;
   out_1678148223451849404[11] = 0.0;
   out_1678148223451849404[12] = 0.0;
   out_1678148223451849404[13] = 0.0;
   out_1678148223451849404[14] = 0.0;
   out_1678148223451849404[15] = 0.0;
   out_1678148223451849404[16] = 0.0;
   out_1678148223451849404[17] = 0.0;
   out_1678148223451849404[18] = 0.0;
   out_1678148223451849404[19] = 1.0;
   out_1678148223451849404[20] = 0.0;
   out_1678148223451849404[21] = 0.0;
   out_1678148223451849404[22] = 0.0;
   out_1678148223451849404[23] = 0.0;
   out_1678148223451849404[24] = 0.0;
   out_1678148223451849404[25] = 0.0;
   out_1678148223451849404[26] = 0.0;
   out_1678148223451849404[27] = 0.0;
   out_1678148223451849404[28] = 0.0;
   out_1678148223451849404[29] = 0.0;
   out_1678148223451849404[30] = 0.0;
   out_1678148223451849404[31] = 0.0;
   out_1678148223451849404[32] = 0.0;
   out_1678148223451849404[33] = 0.0;
   out_1678148223451849404[34] = 0.0;
   out_1678148223451849404[35] = 0.0;
   out_1678148223451849404[36] = 0.0;
   out_1678148223451849404[37] = 0.0;
   out_1678148223451849404[38] = 1.0;
   out_1678148223451849404[39] = 0.0;
   out_1678148223451849404[40] = 0.0;
   out_1678148223451849404[41] = 0.0;
   out_1678148223451849404[42] = 0.0;
   out_1678148223451849404[43] = 0.0;
   out_1678148223451849404[44] = 0.0;
   out_1678148223451849404[45] = 0.0;
   out_1678148223451849404[46] = 0.0;
   out_1678148223451849404[47] = 0.0;
   out_1678148223451849404[48] = 0.0;
   out_1678148223451849404[49] = 0.0;
   out_1678148223451849404[50] = 0.0;
   out_1678148223451849404[51] = 0.0;
   out_1678148223451849404[52] = 0.0;
   out_1678148223451849404[53] = 0.0;
   out_1678148223451849404[54] = 0.0;
   out_1678148223451849404[55] = 0.0;
   out_1678148223451849404[56] = 0.0;
   out_1678148223451849404[57] = 1.0;
   out_1678148223451849404[58] = 0.0;
   out_1678148223451849404[59] = 0.0;
   out_1678148223451849404[60] = 0.0;
   out_1678148223451849404[61] = 0.0;
   out_1678148223451849404[62] = 0.0;
   out_1678148223451849404[63] = 0.0;
   out_1678148223451849404[64] = 0.0;
   out_1678148223451849404[65] = 0.0;
   out_1678148223451849404[66] = 0.0;
   out_1678148223451849404[67] = 0.0;
   out_1678148223451849404[68] = 0.0;
   out_1678148223451849404[69] = 0.0;
   out_1678148223451849404[70] = 0.0;
   out_1678148223451849404[71] = 0.0;
   out_1678148223451849404[72] = 0.0;
   out_1678148223451849404[73] = 0.0;
   out_1678148223451849404[74] = 0.0;
   out_1678148223451849404[75] = 0.0;
   out_1678148223451849404[76] = 1.0;
   out_1678148223451849404[77] = 0.0;
   out_1678148223451849404[78] = 0.0;
   out_1678148223451849404[79] = 0.0;
   out_1678148223451849404[80] = 0.0;
   out_1678148223451849404[81] = 0.0;
   out_1678148223451849404[82] = 0.0;
   out_1678148223451849404[83] = 0.0;
   out_1678148223451849404[84] = 0.0;
   out_1678148223451849404[85] = 0.0;
   out_1678148223451849404[86] = 0.0;
   out_1678148223451849404[87] = 0.0;
   out_1678148223451849404[88] = 0.0;
   out_1678148223451849404[89] = 0.0;
   out_1678148223451849404[90] = 0.0;
   out_1678148223451849404[91] = 0.0;
   out_1678148223451849404[92] = 0.0;
   out_1678148223451849404[93] = 0.0;
   out_1678148223451849404[94] = 0.0;
   out_1678148223451849404[95] = 1.0;
   out_1678148223451849404[96] = 0.0;
   out_1678148223451849404[97] = 0.0;
   out_1678148223451849404[98] = 0.0;
   out_1678148223451849404[99] = 0.0;
   out_1678148223451849404[100] = 0.0;
   out_1678148223451849404[101] = 0.0;
   out_1678148223451849404[102] = 0.0;
   out_1678148223451849404[103] = 0.0;
   out_1678148223451849404[104] = 0.0;
   out_1678148223451849404[105] = 0.0;
   out_1678148223451849404[106] = 0.0;
   out_1678148223451849404[107] = 0.0;
   out_1678148223451849404[108] = 0.0;
   out_1678148223451849404[109] = 0.0;
   out_1678148223451849404[110] = 0.0;
   out_1678148223451849404[111] = 0.0;
   out_1678148223451849404[112] = 0.0;
   out_1678148223451849404[113] = 0.0;
   out_1678148223451849404[114] = 1.0;
   out_1678148223451849404[115] = 0.0;
   out_1678148223451849404[116] = 0.0;
   out_1678148223451849404[117] = 0.0;
   out_1678148223451849404[118] = 0.0;
   out_1678148223451849404[119] = 0.0;
   out_1678148223451849404[120] = 0.0;
   out_1678148223451849404[121] = 0.0;
   out_1678148223451849404[122] = 0.0;
   out_1678148223451849404[123] = 0.0;
   out_1678148223451849404[124] = 0.0;
   out_1678148223451849404[125] = 0.0;
   out_1678148223451849404[126] = 0.0;
   out_1678148223451849404[127] = 0.0;
   out_1678148223451849404[128] = 0.0;
   out_1678148223451849404[129] = 0.0;
   out_1678148223451849404[130] = 0.0;
   out_1678148223451849404[131] = 0.0;
   out_1678148223451849404[132] = 0.0;
   out_1678148223451849404[133] = 1.0;
   out_1678148223451849404[134] = 0.0;
   out_1678148223451849404[135] = 0.0;
   out_1678148223451849404[136] = 0.0;
   out_1678148223451849404[137] = 0.0;
   out_1678148223451849404[138] = 0.0;
   out_1678148223451849404[139] = 0.0;
   out_1678148223451849404[140] = 0.0;
   out_1678148223451849404[141] = 0.0;
   out_1678148223451849404[142] = 0.0;
   out_1678148223451849404[143] = 0.0;
   out_1678148223451849404[144] = 0.0;
   out_1678148223451849404[145] = 0.0;
   out_1678148223451849404[146] = 0.0;
   out_1678148223451849404[147] = 0.0;
   out_1678148223451849404[148] = 0.0;
   out_1678148223451849404[149] = 0.0;
   out_1678148223451849404[150] = 0.0;
   out_1678148223451849404[151] = 0.0;
   out_1678148223451849404[152] = 1.0;
   out_1678148223451849404[153] = 0.0;
   out_1678148223451849404[154] = 0.0;
   out_1678148223451849404[155] = 0.0;
   out_1678148223451849404[156] = 0.0;
   out_1678148223451849404[157] = 0.0;
   out_1678148223451849404[158] = 0.0;
   out_1678148223451849404[159] = 0.0;
   out_1678148223451849404[160] = 0.0;
   out_1678148223451849404[161] = 0.0;
   out_1678148223451849404[162] = 0.0;
   out_1678148223451849404[163] = 0.0;
   out_1678148223451849404[164] = 0.0;
   out_1678148223451849404[165] = 0.0;
   out_1678148223451849404[166] = 0.0;
   out_1678148223451849404[167] = 0.0;
   out_1678148223451849404[168] = 0.0;
   out_1678148223451849404[169] = 0.0;
   out_1678148223451849404[170] = 0.0;
   out_1678148223451849404[171] = 1.0;
   out_1678148223451849404[172] = 0.0;
   out_1678148223451849404[173] = 0.0;
   out_1678148223451849404[174] = 0.0;
   out_1678148223451849404[175] = 0.0;
   out_1678148223451849404[176] = 0.0;
   out_1678148223451849404[177] = 0.0;
   out_1678148223451849404[178] = 0.0;
   out_1678148223451849404[179] = 0.0;
   out_1678148223451849404[180] = 0.0;
   out_1678148223451849404[181] = 0.0;
   out_1678148223451849404[182] = 0.0;
   out_1678148223451849404[183] = 0.0;
   out_1678148223451849404[184] = 0.0;
   out_1678148223451849404[185] = 0.0;
   out_1678148223451849404[186] = 0.0;
   out_1678148223451849404[187] = 0.0;
   out_1678148223451849404[188] = 0.0;
   out_1678148223451849404[189] = 0.0;
   out_1678148223451849404[190] = 1.0;
   out_1678148223451849404[191] = 0.0;
   out_1678148223451849404[192] = 0.0;
   out_1678148223451849404[193] = 0.0;
   out_1678148223451849404[194] = 0.0;
   out_1678148223451849404[195] = 0.0;
   out_1678148223451849404[196] = 0.0;
   out_1678148223451849404[197] = 0.0;
   out_1678148223451849404[198] = 0.0;
   out_1678148223451849404[199] = 0.0;
   out_1678148223451849404[200] = 0.0;
   out_1678148223451849404[201] = 0.0;
   out_1678148223451849404[202] = 0.0;
   out_1678148223451849404[203] = 0.0;
   out_1678148223451849404[204] = 0.0;
   out_1678148223451849404[205] = 0.0;
   out_1678148223451849404[206] = 0.0;
   out_1678148223451849404[207] = 0.0;
   out_1678148223451849404[208] = 0.0;
   out_1678148223451849404[209] = 1.0;
   out_1678148223451849404[210] = 0.0;
   out_1678148223451849404[211] = 0.0;
   out_1678148223451849404[212] = 0.0;
   out_1678148223451849404[213] = 0.0;
   out_1678148223451849404[214] = 0.0;
   out_1678148223451849404[215] = 0.0;
   out_1678148223451849404[216] = 0.0;
   out_1678148223451849404[217] = 0.0;
   out_1678148223451849404[218] = 0.0;
   out_1678148223451849404[219] = 0.0;
   out_1678148223451849404[220] = 0.0;
   out_1678148223451849404[221] = 0.0;
   out_1678148223451849404[222] = 0.0;
   out_1678148223451849404[223] = 0.0;
   out_1678148223451849404[224] = 0.0;
   out_1678148223451849404[225] = 0.0;
   out_1678148223451849404[226] = 0.0;
   out_1678148223451849404[227] = 0.0;
   out_1678148223451849404[228] = 1.0;
   out_1678148223451849404[229] = 0.0;
   out_1678148223451849404[230] = 0.0;
   out_1678148223451849404[231] = 0.0;
   out_1678148223451849404[232] = 0.0;
   out_1678148223451849404[233] = 0.0;
   out_1678148223451849404[234] = 0.0;
   out_1678148223451849404[235] = 0.0;
   out_1678148223451849404[236] = 0.0;
   out_1678148223451849404[237] = 0.0;
   out_1678148223451849404[238] = 0.0;
   out_1678148223451849404[239] = 0.0;
   out_1678148223451849404[240] = 0.0;
   out_1678148223451849404[241] = 0.0;
   out_1678148223451849404[242] = 0.0;
   out_1678148223451849404[243] = 0.0;
   out_1678148223451849404[244] = 0.0;
   out_1678148223451849404[245] = 0.0;
   out_1678148223451849404[246] = 0.0;
   out_1678148223451849404[247] = 1.0;
   out_1678148223451849404[248] = 0.0;
   out_1678148223451849404[249] = 0.0;
   out_1678148223451849404[250] = 0.0;
   out_1678148223451849404[251] = 0.0;
   out_1678148223451849404[252] = 0.0;
   out_1678148223451849404[253] = 0.0;
   out_1678148223451849404[254] = 0.0;
   out_1678148223451849404[255] = 0.0;
   out_1678148223451849404[256] = 0.0;
   out_1678148223451849404[257] = 0.0;
   out_1678148223451849404[258] = 0.0;
   out_1678148223451849404[259] = 0.0;
   out_1678148223451849404[260] = 0.0;
   out_1678148223451849404[261] = 0.0;
   out_1678148223451849404[262] = 0.0;
   out_1678148223451849404[263] = 0.0;
   out_1678148223451849404[264] = 0.0;
   out_1678148223451849404[265] = 0.0;
   out_1678148223451849404[266] = 1.0;
   out_1678148223451849404[267] = 0.0;
   out_1678148223451849404[268] = 0.0;
   out_1678148223451849404[269] = 0.0;
   out_1678148223451849404[270] = 0.0;
   out_1678148223451849404[271] = 0.0;
   out_1678148223451849404[272] = 0.0;
   out_1678148223451849404[273] = 0.0;
   out_1678148223451849404[274] = 0.0;
   out_1678148223451849404[275] = 0.0;
   out_1678148223451849404[276] = 0.0;
   out_1678148223451849404[277] = 0.0;
   out_1678148223451849404[278] = 0.0;
   out_1678148223451849404[279] = 0.0;
   out_1678148223451849404[280] = 0.0;
   out_1678148223451849404[281] = 0.0;
   out_1678148223451849404[282] = 0.0;
   out_1678148223451849404[283] = 0.0;
   out_1678148223451849404[284] = 0.0;
   out_1678148223451849404[285] = 1.0;
   out_1678148223451849404[286] = 0.0;
   out_1678148223451849404[287] = 0.0;
   out_1678148223451849404[288] = 0.0;
   out_1678148223451849404[289] = 0.0;
   out_1678148223451849404[290] = 0.0;
   out_1678148223451849404[291] = 0.0;
   out_1678148223451849404[292] = 0.0;
   out_1678148223451849404[293] = 0.0;
   out_1678148223451849404[294] = 0.0;
   out_1678148223451849404[295] = 0.0;
   out_1678148223451849404[296] = 0.0;
   out_1678148223451849404[297] = 0.0;
   out_1678148223451849404[298] = 0.0;
   out_1678148223451849404[299] = 0.0;
   out_1678148223451849404[300] = 0.0;
   out_1678148223451849404[301] = 0.0;
   out_1678148223451849404[302] = 0.0;
   out_1678148223451849404[303] = 0.0;
   out_1678148223451849404[304] = 1.0;
   out_1678148223451849404[305] = 0.0;
   out_1678148223451849404[306] = 0.0;
   out_1678148223451849404[307] = 0.0;
   out_1678148223451849404[308] = 0.0;
   out_1678148223451849404[309] = 0.0;
   out_1678148223451849404[310] = 0.0;
   out_1678148223451849404[311] = 0.0;
   out_1678148223451849404[312] = 0.0;
   out_1678148223451849404[313] = 0.0;
   out_1678148223451849404[314] = 0.0;
   out_1678148223451849404[315] = 0.0;
   out_1678148223451849404[316] = 0.0;
   out_1678148223451849404[317] = 0.0;
   out_1678148223451849404[318] = 0.0;
   out_1678148223451849404[319] = 0.0;
   out_1678148223451849404[320] = 0.0;
   out_1678148223451849404[321] = 0.0;
   out_1678148223451849404[322] = 0.0;
   out_1678148223451849404[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4390690219844123460) {
   out_4390690219844123460[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4390690219844123460[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4390690219844123460[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4390690219844123460[3] = dt*state[12] + state[3];
   out_4390690219844123460[4] = dt*state[13] + state[4];
   out_4390690219844123460[5] = dt*state[14] + state[5];
   out_4390690219844123460[6] = state[6];
   out_4390690219844123460[7] = state[7];
   out_4390690219844123460[8] = state[8];
   out_4390690219844123460[9] = state[9];
   out_4390690219844123460[10] = state[10];
   out_4390690219844123460[11] = state[11];
   out_4390690219844123460[12] = state[12];
   out_4390690219844123460[13] = state[13];
   out_4390690219844123460[14] = state[14];
   out_4390690219844123460[15] = state[15];
   out_4390690219844123460[16] = state[16];
   out_4390690219844123460[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5251920544283288288) {
   out_5251920544283288288[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5251920544283288288[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5251920544283288288[2] = 0;
   out_5251920544283288288[3] = 0;
   out_5251920544283288288[4] = 0;
   out_5251920544283288288[5] = 0;
   out_5251920544283288288[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5251920544283288288[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5251920544283288288[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5251920544283288288[9] = 0;
   out_5251920544283288288[10] = 0;
   out_5251920544283288288[11] = 0;
   out_5251920544283288288[12] = 0;
   out_5251920544283288288[13] = 0;
   out_5251920544283288288[14] = 0;
   out_5251920544283288288[15] = 0;
   out_5251920544283288288[16] = 0;
   out_5251920544283288288[17] = 0;
   out_5251920544283288288[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5251920544283288288[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5251920544283288288[20] = 0;
   out_5251920544283288288[21] = 0;
   out_5251920544283288288[22] = 0;
   out_5251920544283288288[23] = 0;
   out_5251920544283288288[24] = 0;
   out_5251920544283288288[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5251920544283288288[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5251920544283288288[27] = 0;
   out_5251920544283288288[28] = 0;
   out_5251920544283288288[29] = 0;
   out_5251920544283288288[30] = 0;
   out_5251920544283288288[31] = 0;
   out_5251920544283288288[32] = 0;
   out_5251920544283288288[33] = 0;
   out_5251920544283288288[34] = 0;
   out_5251920544283288288[35] = 0;
   out_5251920544283288288[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5251920544283288288[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5251920544283288288[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5251920544283288288[39] = 0;
   out_5251920544283288288[40] = 0;
   out_5251920544283288288[41] = 0;
   out_5251920544283288288[42] = 0;
   out_5251920544283288288[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5251920544283288288[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5251920544283288288[45] = 0;
   out_5251920544283288288[46] = 0;
   out_5251920544283288288[47] = 0;
   out_5251920544283288288[48] = 0;
   out_5251920544283288288[49] = 0;
   out_5251920544283288288[50] = 0;
   out_5251920544283288288[51] = 0;
   out_5251920544283288288[52] = 0;
   out_5251920544283288288[53] = 0;
   out_5251920544283288288[54] = 0;
   out_5251920544283288288[55] = 0;
   out_5251920544283288288[56] = 0;
   out_5251920544283288288[57] = 1;
   out_5251920544283288288[58] = 0;
   out_5251920544283288288[59] = 0;
   out_5251920544283288288[60] = 0;
   out_5251920544283288288[61] = 0;
   out_5251920544283288288[62] = 0;
   out_5251920544283288288[63] = 0;
   out_5251920544283288288[64] = 0;
   out_5251920544283288288[65] = 0;
   out_5251920544283288288[66] = dt;
   out_5251920544283288288[67] = 0;
   out_5251920544283288288[68] = 0;
   out_5251920544283288288[69] = 0;
   out_5251920544283288288[70] = 0;
   out_5251920544283288288[71] = 0;
   out_5251920544283288288[72] = 0;
   out_5251920544283288288[73] = 0;
   out_5251920544283288288[74] = 0;
   out_5251920544283288288[75] = 0;
   out_5251920544283288288[76] = 1;
   out_5251920544283288288[77] = 0;
   out_5251920544283288288[78] = 0;
   out_5251920544283288288[79] = 0;
   out_5251920544283288288[80] = 0;
   out_5251920544283288288[81] = 0;
   out_5251920544283288288[82] = 0;
   out_5251920544283288288[83] = 0;
   out_5251920544283288288[84] = 0;
   out_5251920544283288288[85] = dt;
   out_5251920544283288288[86] = 0;
   out_5251920544283288288[87] = 0;
   out_5251920544283288288[88] = 0;
   out_5251920544283288288[89] = 0;
   out_5251920544283288288[90] = 0;
   out_5251920544283288288[91] = 0;
   out_5251920544283288288[92] = 0;
   out_5251920544283288288[93] = 0;
   out_5251920544283288288[94] = 0;
   out_5251920544283288288[95] = 1;
   out_5251920544283288288[96] = 0;
   out_5251920544283288288[97] = 0;
   out_5251920544283288288[98] = 0;
   out_5251920544283288288[99] = 0;
   out_5251920544283288288[100] = 0;
   out_5251920544283288288[101] = 0;
   out_5251920544283288288[102] = 0;
   out_5251920544283288288[103] = 0;
   out_5251920544283288288[104] = dt;
   out_5251920544283288288[105] = 0;
   out_5251920544283288288[106] = 0;
   out_5251920544283288288[107] = 0;
   out_5251920544283288288[108] = 0;
   out_5251920544283288288[109] = 0;
   out_5251920544283288288[110] = 0;
   out_5251920544283288288[111] = 0;
   out_5251920544283288288[112] = 0;
   out_5251920544283288288[113] = 0;
   out_5251920544283288288[114] = 1;
   out_5251920544283288288[115] = 0;
   out_5251920544283288288[116] = 0;
   out_5251920544283288288[117] = 0;
   out_5251920544283288288[118] = 0;
   out_5251920544283288288[119] = 0;
   out_5251920544283288288[120] = 0;
   out_5251920544283288288[121] = 0;
   out_5251920544283288288[122] = 0;
   out_5251920544283288288[123] = 0;
   out_5251920544283288288[124] = 0;
   out_5251920544283288288[125] = 0;
   out_5251920544283288288[126] = 0;
   out_5251920544283288288[127] = 0;
   out_5251920544283288288[128] = 0;
   out_5251920544283288288[129] = 0;
   out_5251920544283288288[130] = 0;
   out_5251920544283288288[131] = 0;
   out_5251920544283288288[132] = 0;
   out_5251920544283288288[133] = 1;
   out_5251920544283288288[134] = 0;
   out_5251920544283288288[135] = 0;
   out_5251920544283288288[136] = 0;
   out_5251920544283288288[137] = 0;
   out_5251920544283288288[138] = 0;
   out_5251920544283288288[139] = 0;
   out_5251920544283288288[140] = 0;
   out_5251920544283288288[141] = 0;
   out_5251920544283288288[142] = 0;
   out_5251920544283288288[143] = 0;
   out_5251920544283288288[144] = 0;
   out_5251920544283288288[145] = 0;
   out_5251920544283288288[146] = 0;
   out_5251920544283288288[147] = 0;
   out_5251920544283288288[148] = 0;
   out_5251920544283288288[149] = 0;
   out_5251920544283288288[150] = 0;
   out_5251920544283288288[151] = 0;
   out_5251920544283288288[152] = 1;
   out_5251920544283288288[153] = 0;
   out_5251920544283288288[154] = 0;
   out_5251920544283288288[155] = 0;
   out_5251920544283288288[156] = 0;
   out_5251920544283288288[157] = 0;
   out_5251920544283288288[158] = 0;
   out_5251920544283288288[159] = 0;
   out_5251920544283288288[160] = 0;
   out_5251920544283288288[161] = 0;
   out_5251920544283288288[162] = 0;
   out_5251920544283288288[163] = 0;
   out_5251920544283288288[164] = 0;
   out_5251920544283288288[165] = 0;
   out_5251920544283288288[166] = 0;
   out_5251920544283288288[167] = 0;
   out_5251920544283288288[168] = 0;
   out_5251920544283288288[169] = 0;
   out_5251920544283288288[170] = 0;
   out_5251920544283288288[171] = 1;
   out_5251920544283288288[172] = 0;
   out_5251920544283288288[173] = 0;
   out_5251920544283288288[174] = 0;
   out_5251920544283288288[175] = 0;
   out_5251920544283288288[176] = 0;
   out_5251920544283288288[177] = 0;
   out_5251920544283288288[178] = 0;
   out_5251920544283288288[179] = 0;
   out_5251920544283288288[180] = 0;
   out_5251920544283288288[181] = 0;
   out_5251920544283288288[182] = 0;
   out_5251920544283288288[183] = 0;
   out_5251920544283288288[184] = 0;
   out_5251920544283288288[185] = 0;
   out_5251920544283288288[186] = 0;
   out_5251920544283288288[187] = 0;
   out_5251920544283288288[188] = 0;
   out_5251920544283288288[189] = 0;
   out_5251920544283288288[190] = 1;
   out_5251920544283288288[191] = 0;
   out_5251920544283288288[192] = 0;
   out_5251920544283288288[193] = 0;
   out_5251920544283288288[194] = 0;
   out_5251920544283288288[195] = 0;
   out_5251920544283288288[196] = 0;
   out_5251920544283288288[197] = 0;
   out_5251920544283288288[198] = 0;
   out_5251920544283288288[199] = 0;
   out_5251920544283288288[200] = 0;
   out_5251920544283288288[201] = 0;
   out_5251920544283288288[202] = 0;
   out_5251920544283288288[203] = 0;
   out_5251920544283288288[204] = 0;
   out_5251920544283288288[205] = 0;
   out_5251920544283288288[206] = 0;
   out_5251920544283288288[207] = 0;
   out_5251920544283288288[208] = 0;
   out_5251920544283288288[209] = 1;
   out_5251920544283288288[210] = 0;
   out_5251920544283288288[211] = 0;
   out_5251920544283288288[212] = 0;
   out_5251920544283288288[213] = 0;
   out_5251920544283288288[214] = 0;
   out_5251920544283288288[215] = 0;
   out_5251920544283288288[216] = 0;
   out_5251920544283288288[217] = 0;
   out_5251920544283288288[218] = 0;
   out_5251920544283288288[219] = 0;
   out_5251920544283288288[220] = 0;
   out_5251920544283288288[221] = 0;
   out_5251920544283288288[222] = 0;
   out_5251920544283288288[223] = 0;
   out_5251920544283288288[224] = 0;
   out_5251920544283288288[225] = 0;
   out_5251920544283288288[226] = 0;
   out_5251920544283288288[227] = 0;
   out_5251920544283288288[228] = 1;
   out_5251920544283288288[229] = 0;
   out_5251920544283288288[230] = 0;
   out_5251920544283288288[231] = 0;
   out_5251920544283288288[232] = 0;
   out_5251920544283288288[233] = 0;
   out_5251920544283288288[234] = 0;
   out_5251920544283288288[235] = 0;
   out_5251920544283288288[236] = 0;
   out_5251920544283288288[237] = 0;
   out_5251920544283288288[238] = 0;
   out_5251920544283288288[239] = 0;
   out_5251920544283288288[240] = 0;
   out_5251920544283288288[241] = 0;
   out_5251920544283288288[242] = 0;
   out_5251920544283288288[243] = 0;
   out_5251920544283288288[244] = 0;
   out_5251920544283288288[245] = 0;
   out_5251920544283288288[246] = 0;
   out_5251920544283288288[247] = 1;
   out_5251920544283288288[248] = 0;
   out_5251920544283288288[249] = 0;
   out_5251920544283288288[250] = 0;
   out_5251920544283288288[251] = 0;
   out_5251920544283288288[252] = 0;
   out_5251920544283288288[253] = 0;
   out_5251920544283288288[254] = 0;
   out_5251920544283288288[255] = 0;
   out_5251920544283288288[256] = 0;
   out_5251920544283288288[257] = 0;
   out_5251920544283288288[258] = 0;
   out_5251920544283288288[259] = 0;
   out_5251920544283288288[260] = 0;
   out_5251920544283288288[261] = 0;
   out_5251920544283288288[262] = 0;
   out_5251920544283288288[263] = 0;
   out_5251920544283288288[264] = 0;
   out_5251920544283288288[265] = 0;
   out_5251920544283288288[266] = 1;
   out_5251920544283288288[267] = 0;
   out_5251920544283288288[268] = 0;
   out_5251920544283288288[269] = 0;
   out_5251920544283288288[270] = 0;
   out_5251920544283288288[271] = 0;
   out_5251920544283288288[272] = 0;
   out_5251920544283288288[273] = 0;
   out_5251920544283288288[274] = 0;
   out_5251920544283288288[275] = 0;
   out_5251920544283288288[276] = 0;
   out_5251920544283288288[277] = 0;
   out_5251920544283288288[278] = 0;
   out_5251920544283288288[279] = 0;
   out_5251920544283288288[280] = 0;
   out_5251920544283288288[281] = 0;
   out_5251920544283288288[282] = 0;
   out_5251920544283288288[283] = 0;
   out_5251920544283288288[284] = 0;
   out_5251920544283288288[285] = 1;
   out_5251920544283288288[286] = 0;
   out_5251920544283288288[287] = 0;
   out_5251920544283288288[288] = 0;
   out_5251920544283288288[289] = 0;
   out_5251920544283288288[290] = 0;
   out_5251920544283288288[291] = 0;
   out_5251920544283288288[292] = 0;
   out_5251920544283288288[293] = 0;
   out_5251920544283288288[294] = 0;
   out_5251920544283288288[295] = 0;
   out_5251920544283288288[296] = 0;
   out_5251920544283288288[297] = 0;
   out_5251920544283288288[298] = 0;
   out_5251920544283288288[299] = 0;
   out_5251920544283288288[300] = 0;
   out_5251920544283288288[301] = 0;
   out_5251920544283288288[302] = 0;
   out_5251920544283288288[303] = 0;
   out_5251920544283288288[304] = 1;
   out_5251920544283288288[305] = 0;
   out_5251920544283288288[306] = 0;
   out_5251920544283288288[307] = 0;
   out_5251920544283288288[308] = 0;
   out_5251920544283288288[309] = 0;
   out_5251920544283288288[310] = 0;
   out_5251920544283288288[311] = 0;
   out_5251920544283288288[312] = 0;
   out_5251920544283288288[313] = 0;
   out_5251920544283288288[314] = 0;
   out_5251920544283288288[315] = 0;
   out_5251920544283288288[316] = 0;
   out_5251920544283288288[317] = 0;
   out_5251920544283288288[318] = 0;
   out_5251920544283288288[319] = 0;
   out_5251920544283288288[320] = 0;
   out_5251920544283288288[321] = 0;
   out_5251920544283288288[322] = 0;
   out_5251920544283288288[323] = 1;
}
void h_4(double *state, double *unused, double *out_2086181486544094617) {
   out_2086181486544094617[0] = state[6] + state[9];
   out_2086181486544094617[1] = state[7] + state[10];
   out_2086181486544094617[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_141550502454447457) {
   out_141550502454447457[0] = 0;
   out_141550502454447457[1] = 0;
   out_141550502454447457[2] = 0;
   out_141550502454447457[3] = 0;
   out_141550502454447457[4] = 0;
   out_141550502454447457[5] = 0;
   out_141550502454447457[6] = 1;
   out_141550502454447457[7] = 0;
   out_141550502454447457[8] = 0;
   out_141550502454447457[9] = 1;
   out_141550502454447457[10] = 0;
   out_141550502454447457[11] = 0;
   out_141550502454447457[12] = 0;
   out_141550502454447457[13] = 0;
   out_141550502454447457[14] = 0;
   out_141550502454447457[15] = 0;
   out_141550502454447457[16] = 0;
   out_141550502454447457[17] = 0;
   out_141550502454447457[18] = 0;
   out_141550502454447457[19] = 0;
   out_141550502454447457[20] = 0;
   out_141550502454447457[21] = 0;
   out_141550502454447457[22] = 0;
   out_141550502454447457[23] = 0;
   out_141550502454447457[24] = 0;
   out_141550502454447457[25] = 1;
   out_141550502454447457[26] = 0;
   out_141550502454447457[27] = 0;
   out_141550502454447457[28] = 1;
   out_141550502454447457[29] = 0;
   out_141550502454447457[30] = 0;
   out_141550502454447457[31] = 0;
   out_141550502454447457[32] = 0;
   out_141550502454447457[33] = 0;
   out_141550502454447457[34] = 0;
   out_141550502454447457[35] = 0;
   out_141550502454447457[36] = 0;
   out_141550502454447457[37] = 0;
   out_141550502454447457[38] = 0;
   out_141550502454447457[39] = 0;
   out_141550502454447457[40] = 0;
   out_141550502454447457[41] = 0;
   out_141550502454447457[42] = 0;
   out_141550502454447457[43] = 0;
   out_141550502454447457[44] = 1;
   out_141550502454447457[45] = 0;
   out_141550502454447457[46] = 0;
   out_141550502454447457[47] = 1;
   out_141550502454447457[48] = 0;
   out_141550502454447457[49] = 0;
   out_141550502454447457[50] = 0;
   out_141550502454447457[51] = 0;
   out_141550502454447457[52] = 0;
   out_141550502454447457[53] = 0;
}
void h_10(double *state, double *unused, double *out_2304974017593414723) {
   out_2304974017593414723[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2304974017593414723[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2304974017593414723[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_521311265061217175) {
   out_521311265061217175[0] = 0;
   out_521311265061217175[1] = 9.8100000000000005*cos(state[1]);
   out_521311265061217175[2] = 0;
   out_521311265061217175[3] = 0;
   out_521311265061217175[4] = -state[8];
   out_521311265061217175[5] = state[7];
   out_521311265061217175[6] = 0;
   out_521311265061217175[7] = state[5];
   out_521311265061217175[8] = -state[4];
   out_521311265061217175[9] = 0;
   out_521311265061217175[10] = 0;
   out_521311265061217175[11] = 0;
   out_521311265061217175[12] = 1;
   out_521311265061217175[13] = 0;
   out_521311265061217175[14] = 0;
   out_521311265061217175[15] = 1;
   out_521311265061217175[16] = 0;
   out_521311265061217175[17] = 0;
   out_521311265061217175[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_521311265061217175[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_521311265061217175[20] = 0;
   out_521311265061217175[21] = state[8];
   out_521311265061217175[22] = 0;
   out_521311265061217175[23] = -state[6];
   out_521311265061217175[24] = -state[5];
   out_521311265061217175[25] = 0;
   out_521311265061217175[26] = state[3];
   out_521311265061217175[27] = 0;
   out_521311265061217175[28] = 0;
   out_521311265061217175[29] = 0;
   out_521311265061217175[30] = 0;
   out_521311265061217175[31] = 1;
   out_521311265061217175[32] = 0;
   out_521311265061217175[33] = 0;
   out_521311265061217175[34] = 1;
   out_521311265061217175[35] = 0;
   out_521311265061217175[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_521311265061217175[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_521311265061217175[38] = 0;
   out_521311265061217175[39] = -state[7];
   out_521311265061217175[40] = state[6];
   out_521311265061217175[41] = 0;
   out_521311265061217175[42] = state[4];
   out_521311265061217175[43] = -state[3];
   out_521311265061217175[44] = 0;
   out_521311265061217175[45] = 0;
   out_521311265061217175[46] = 0;
   out_521311265061217175[47] = 0;
   out_521311265061217175[48] = 0;
   out_521311265061217175[49] = 0;
   out_521311265061217175[50] = 1;
   out_521311265061217175[51] = 0;
   out_521311265061217175[52] = 0;
   out_521311265061217175[53] = 1;
}
void h_13(double *state, double *unused, double *out_6563098082746675966) {
   out_6563098082746675966[0] = state[3];
   out_6563098082746675966[1] = state[4];
   out_6563098082746675966[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3070723322877885344) {
   out_3070723322877885344[0] = 0;
   out_3070723322877885344[1] = 0;
   out_3070723322877885344[2] = 0;
   out_3070723322877885344[3] = 1;
   out_3070723322877885344[4] = 0;
   out_3070723322877885344[5] = 0;
   out_3070723322877885344[6] = 0;
   out_3070723322877885344[7] = 0;
   out_3070723322877885344[8] = 0;
   out_3070723322877885344[9] = 0;
   out_3070723322877885344[10] = 0;
   out_3070723322877885344[11] = 0;
   out_3070723322877885344[12] = 0;
   out_3070723322877885344[13] = 0;
   out_3070723322877885344[14] = 0;
   out_3070723322877885344[15] = 0;
   out_3070723322877885344[16] = 0;
   out_3070723322877885344[17] = 0;
   out_3070723322877885344[18] = 0;
   out_3070723322877885344[19] = 0;
   out_3070723322877885344[20] = 0;
   out_3070723322877885344[21] = 0;
   out_3070723322877885344[22] = 1;
   out_3070723322877885344[23] = 0;
   out_3070723322877885344[24] = 0;
   out_3070723322877885344[25] = 0;
   out_3070723322877885344[26] = 0;
   out_3070723322877885344[27] = 0;
   out_3070723322877885344[28] = 0;
   out_3070723322877885344[29] = 0;
   out_3070723322877885344[30] = 0;
   out_3070723322877885344[31] = 0;
   out_3070723322877885344[32] = 0;
   out_3070723322877885344[33] = 0;
   out_3070723322877885344[34] = 0;
   out_3070723322877885344[35] = 0;
   out_3070723322877885344[36] = 0;
   out_3070723322877885344[37] = 0;
   out_3070723322877885344[38] = 0;
   out_3070723322877885344[39] = 0;
   out_3070723322877885344[40] = 0;
   out_3070723322877885344[41] = 1;
   out_3070723322877885344[42] = 0;
   out_3070723322877885344[43] = 0;
   out_3070723322877885344[44] = 0;
   out_3070723322877885344[45] = 0;
   out_3070723322877885344[46] = 0;
   out_3070723322877885344[47] = 0;
   out_3070723322877885344[48] = 0;
   out_3070723322877885344[49] = 0;
   out_3070723322877885344[50] = 0;
   out_3070723322877885344[51] = 0;
   out_3070723322877885344[52] = 0;
   out_3070723322877885344[53] = 0;
}
void h_14(double *state, double *unused, double *out_4832039927491863335) {
   out_4832039927491863335[0] = state[6];
   out_4832039927491863335[1] = state[7];
   out_4832039927491863335[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3821690353885037072) {
   out_3821690353885037072[0] = 0;
   out_3821690353885037072[1] = 0;
   out_3821690353885037072[2] = 0;
   out_3821690353885037072[3] = 0;
   out_3821690353885037072[4] = 0;
   out_3821690353885037072[5] = 0;
   out_3821690353885037072[6] = 1;
   out_3821690353885037072[7] = 0;
   out_3821690353885037072[8] = 0;
   out_3821690353885037072[9] = 0;
   out_3821690353885037072[10] = 0;
   out_3821690353885037072[11] = 0;
   out_3821690353885037072[12] = 0;
   out_3821690353885037072[13] = 0;
   out_3821690353885037072[14] = 0;
   out_3821690353885037072[15] = 0;
   out_3821690353885037072[16] = 0;
   out_3821690353885037072[17] = 0;
   out_3821690353885037072[18] = 0;
   out_3821690353885037072[19] = 0;
   out_3821690353885037072[20] = 0;
   out_3821690353885037072[21] = 0;
   out_3821690353885037072[22] = 0;
   out_3821690353885037072[23] = 0;
   out_3821690353885037072[24] = 0;
   out_3821690353885037072[25] = 1;
   out_3821690353885037072[26] = 0;
   out_3821690353885037072[27] = 0;
   out_3821690353885037072[28] = 0;
   out_3821690353885037072[29] = 0;
   out_3821690353885037072[30] = 0;
   out_3821690353885037072[31] = 0;
   out_3821690353885037072[32] = 0;
   out_3821690353885037072[33] = 0;
   out_3821690353885037072[34] = 0;
   out_3821690353885037072[35] = 0;
   out_3821690353885037072[36] = 0;
   out_3821690353885037072[37] = 0;
   out_3821690353885037072[38] = 0;
   out_3821690353885037072[39] = 0;
   out_3821690353885037072[40] = 0;
   out_3821690353885037072[41] = 0;
   out_3821690353885037072[42] = 0;
   out_3821690353885037072[43] = 0;
   out_3821690353885037072[44] = 1;
   out_3821690353885037072[45] = 0;
   out_3821690353885037072[46] = 0;
   out_3821690353885037072[47] = 0;
   out_3821690353885037072[48] = 0;
   out_3821690353885037072[49] = 0;
   out_3821690353885037072[50] = 0;
   out_3821690353885037072[51] = 0;
   out_3821690353885037072[52] = 0;
   out_3821690353885037072[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_3667758909157266385) {
  err_fun(nom_x, delta_x, out_3667758909157266385);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3255008687637156165) {
  inv_err_fun(nom_x, true_x, out_3255008687637156165);
}
void pose_H_mod_fun(double *state, double *out_1678148223451849404) {
  H_mod_fun(state, out_1678148223451849404);
}
void pose_f_fun(double *state, double dt, double *out_4390690219844123460) {
  f_fun(state,  dt, out_4390690219844123460);
}
void pose_F_fun(double *state, double dt, double *out_5251920544283288288) {
  F_fun(state,  dt, out_5251920544283288288);
}
void pose_h_4(double *state, double *unused, double *out_2086181486544094617) {
  h_4(state, unused, out_2086181486544094617);
}
void pose_H_4(double *state, double *unused, double *out_141550502454447457) {
  H_4(state, unused, out_141550502454447457);
}
void pose_h_10(double *state, double *unused, double *out_2304974017593414723) {
  h_10(state, unused, out_2304974017593414723);
}
void pose_H_10(double *state, double *unused, double *out_521311265061217175) {
  H_10(state, unused, out_521311265061217175);
}
void pose_h_13(double *state, double *unused, double *out_6563098082746675966) {
  h_13(state, unused, out_6563098082746675966);
}
void pose_H_13(double *state, double *unused, double *out_3070723322877885344) {
  H_13(state, unused, out_3070723322877885344);
}
void pose_h_14(double *state, double *unused, double *out_4832039927491863335) {
  h_14(state, unused, out_4832039927491863335);
}
void pose_H_14(double *state, double *unused, double *out_3821690353885037072) {
  H_14(state, unused, out_3821690353885037072);
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
