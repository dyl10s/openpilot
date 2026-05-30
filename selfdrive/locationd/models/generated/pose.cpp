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
void err_fun(double *nom_x, double *delta_x, double *out_2755267697534836281) {
   out_2755267697534836281[0] = delta_x[0] + nom_x[0];
   out_2755267697534836281[1] = delta_x[1] + nom_x[1];
   out_2755267697534836281[2] = delta_x[2] + nom_x[2];
   out_2755267697534836281[3] = delta_x[3] + nom_x[3];
   out_2755267697534836281[4] = delta_x[4] + nom_x[4];
   out_2755267697534836281[5] = delta_x[5] + nom_x[5];
   out_2755267697534836281[6] = delta_x[6] + nom_x[6];
   out_2755267697534836281[7] = delta_x[7] + nom_x[7];
   out_2755267697534836281[8] = delta_x[8] + nom_x[8];
   out_2755267697534836281[9] = delta_x[9] + nom_x[9];
   out_2755267697534836281[10] = delta_x[10] + nom_x[10];
   out_2755267697534836281[11] = delta_x[11] + nom_x[11];
   out_2755267697534836281[12] = delta_x[12] + nom_x[12];
   out_2755267697534836281[13] = delta_x[13] + nom_x[13];
   out_2755267697534836281[14] = delta_x[14] + nom_x[14];
   out_2755267697534836281[15] = delta_x[15] + nom_x[15];
   out_2755267697534836281[16] = delta_x[16] + nom_x[16];
   out_2755267697534836281[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4688414877314135206) {
   out_4688414877314135206[0] = -nom_x[0] + true_x[0];
   out_4688414877314135206[1] = -nom_x[1] + true_x[1];
   out_4688414877314135206[2] = -nom_x[2] + true_x[2];
   out_4688414877314135206[3] = -nom_x[3] + true_x[3];
   out_4688414877314135206[4] = -nom_x[4] + true_x[4];
   out_4688414877314135206[5] = -nom_x[5] + true_x[5];
   out_4688414877314135206[6] = -nom_x[6] + true_x[6];
   out_4688414877314135206[7] = -nom_x[7] + true_x[7];
   out_4688414877314135206[8] = -nom_x[8] + true_x[8];
   out_4688414877314135206[9] = -nom_x[9] + true_x[9];
   out_4688414877314135206[10] = -nom_x[10] + true_x[10];
   out_4688414877314135206[11] = -nom_x[11] + true_x[11];
   out_4688414877314135206[12] = -nom_x[12] + true_x[12];
   out_4688414877314135206[13] = -nom_x[13] + true_x[13];
   out_4688414877314135206[14] = -nom_x[14] + true_x[14];
   out_4688414877314135206[15] = -nom_x[15] + true_x[15];
   out_4688414877314135206[16] = -nom_x[16] + true_x[16];
   out_4688414877314135206[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7837152669402150713) {
   out_7837152669402150713[0] = 1.0;
   out_7837152669402150713[1] = 0.0;
   out_7837152669402150713[2] = 0.0;
   out_7837152669402150713[3] = 0.0;
   out_7837152669402150713[4] = 0.0;
   out_7837152669402150713[5] = 0.0;
   out_7837152669402150713[6] = 0.0;
   out_7837152669402150713[7] = 0.0;
   out_7837152669402150713[8] = 0.0;
   out_7837152669402150713[9] = 0.0;
   out_7837152669402150713[10] = 0.0;
   out_7837152669402150713[11] = 0.0;
   out_7837152669402150713[12] = 0.0;
   out_7837152669402150713[13] = 0.0;
   out_7837152669402150713[14] = 0.0;
   out_7837152669402150713[15] = 0.0;
   out_7837152669402150713[16] = 0.0;
   out_7837152669402150713[17] = 0.0;
   out_7837152669402150713[18] = 0.0;
   out_7837152669402150713[19] = 1.0;
   out_7837152669402150713[20] = 0.0;
   out_7837152669402150713[21] = 0.0;
   out_7837152669402150713[22] = 0.0;
   out_7837152669402150713[23] = 0.0;
   out_7837152669402150713[24] = 0.0;
   out_7837152669402150713[25] = 0.0;
   out_7837152669402150713[26] = 0.0;
   out_7837152669402150713[27] = 0.0;
   out_7837152669402150713[28] = 0.0;
   out_7837152669402150713[29] = 0.0;
   out_7837152669402150713[30] = 0.0;
   out_7837152669402150713[31] = 0.0;
   out_7837152669402150713[32] = 0.0;
   out_7837152669402150713[33] = 0.0;
   out_7837152669402150713[34] = 0.0;
   out_7837152669402150713[35] = 0.0;
   out_7837152669402150713[36] = 0.0;
   out_7837152669402150713[37] = 0.0;
   out_7837152669402150713[38] = 1.0;
   out_7837152669402150713[39] = 0.0;
   out_7837152669402150713[40] = 0.0;
   out_7837152669402150713[41] = 0.0;
   out_7837152669402150713[42] = 0.0;
   out_7837152669402150713[43] = 0.0;
   out_7837152669402150713[44] = 0.0;
   out_7837152669402150713[45] = 0.0;
   out_7837152669402150713[46] = 0.0;
   out_7837152669402150713[47] = 0.0;
   out_7837152669402150713[48] = 0.0;
   out_7837152669402150713[49] = 0.0;
   out_7837152669402150713[50] = 0.0;
   out_7837152669402150713[51] = 0.0;
   out_7837152669402150713[52] = 0.0;
   out_7837152669402150713[53] = 0.0;
   out_7837152669402150713[54] = 0.0;
   out_7837152669402150713[55] = 0.0;
   out_7837152669402150713[56] = 0.0;
   out_7837152669402150713[57] = 1.0;
   out_7837152669402150713[58] = 0.0;
   out_7837152669402150713[59] = 0.0;
   out_7837152669402150713[60] = 0.0;
   out_7837152669402150713[61] = 0.0;
   out_7837152669402150713[62] = 0.0;
   out_7837152669402150713[63] = 0.0;
   out_7837152669402150713[64] = 0.0;
   out_7837152669402150713[65] = 0.0;
   out_7837152669402150713[66] = 0.0;
   out_7837152669402150713[67] = 0.0;
   out_7837152669402150713[68] = 0.0;
   out_7837152669402150713[69] = 0.0;
   out_7837152669402150713[70] = 0.0;
   out_7837152669402150713[71] = 0.0;
   out_7837152669402150713[72] = 0.0;
   out_7837152669402150713[73] = 0.0;
   out_7837152669402150713[74] = 0.0;
   out_7837152669402150713[75] = 0.0;
   out_7837152669402150713[76] = 1.0;
   out_7837152669402150713[77] = 0.0;
   out_7837152669402150713[78] = 0.0;
   out_7837152669402150713[79] = 0.0;
   out_7837152669402150713[80] = 0.0;
   out_7837152669402150713[81] = 0.0;
   out_7837152669402150713[82] = 0.0;
   out_7837152669402150713[83] = 0.0;
   out_7837152669402150713[84] = 0.0;
   out_7837152669402150713[85] = 0.0;
   out_7837152669402150713[86] = 0.0;
   out_7837152669402150713[87] = 0.0;
   out_7837152669402150713[88] = 0.0;
   out_7837152669402150713[89] = 0.0;
   out_7837152669402150713[90] = 0.0;
   out_7837152669402150713[91] = 0.0;
   out_7837152669402150713[92] = 0.0;
   out_7837152669402150713[93] = 0.0;
   out_7837152669402150713[94] = 0.0;
   out_7837152669402150713[95] = 1.0;
   out_7837152669402150713[96] = 0.0;
   out_7837152669402150713[97] = 0.0;
   out_7837152669402150713[98] = 0.0;
   out_7837152669402150713[99] = 0.0;
   out_7837152669402150713[100] = 0.0;
   out_7837152669402150713[101] = 0.0;
   out_7837152669402150713[102] = 0.0;
   out_7837152669402150713[103] = 0.0;
   out_7837152669402150713[104] = 0.0;
   out_7837152669402150713[105] = 0.0;
   out_7837152669402150713[106] = 0.0;
   out_7837152669402150713[107] = 0.0;
   out_7837152669402150713[108] = 0.0;
   out_7837152669402150713[109] = 0.0;
   out_7837152669402150713[110] = 0.0;
   out_7837152669402150713[111] = 0.0;
   out_7837152669402150713[112] = 0.0;
   out_7837152669402150713[113] = 0.0;
   out_7837152669402150713[114] = 1.0;
   out_7837152669402150713[115] = 0.0;
   out_7837152669402150713[116] = 0.0;
   out_7837152669402150713[117] = 0.0;
   out_7837152669402150713[118] = 0.0;
   out_7837152669402150713[119] = 0.0;
   out_7837152669402150713[120] = 0.0;
   out_7837152669402150713[121] = 0.0;
   out_7837152669402150713[122] = 0.0;
   out_7837152669402150713[123] = 0.0;
   out_7837152669402150713[124] = 0.0;
   out_7837152669402150713[125] = 0.0;
   out_7837152669402150713[126] = 0.0;
   out_7837152669402150713[127] = 0.0;
   out_7837152669402150713[128] = 0.0;
   out_7837152669402150713[129] = 0.0;
   out_7837152669402150713[130] = 0.0;
   out_7837152669402150713[131] = 0.0;
   out_7837152669402150713[132] = 0.0;
   out_7837152669402150713[133] = 1.0;
   out_7837152669402150713[134] = 0.0;
   out_7837152669402150713[135] = 0.0;
   out_7837152669402150713[136] = 0.0;
   out_7837152669402150713[137] = 0.0;
   out_7837152669402150713[138] = 0.0;
   out_7837152669402150713[139] = 0.0;
   out_7837152669402150713[140] = 0.0;
   out_7837152669402150713[141] = 0.0;
   out_7837152669402150713[142] = 0.0;
   out_7837152669402150713[143] = 0.0;
   out_7837152669402150713[144] = 0.0;
   out_7837152669402150713[145] = 0.0;
   out_7837152669402150713[146] = 0.0;
   out_7837152669402150713[147] = 0.0;
   out_7837152669402150713[148] = 0.0;
   out_7837152669402150713[149] = 0.0;
   out_7837152669402150713[150] = 0.0;
   out_7837152669402150713[151] = 0.0;
   out_7837152669402150713[152] = 1.0;
   out_7837152669402150713[153] = 0.0;
   out_7837152669402150713[154] = 0.0;
   out_7837152669402150713[155] = 0.0;
   out_7837152669402150713[156] = 0.0;
   out_7837152669402150713[157] = 0.0;
   out_7837152669402150713[158] = 0.0;
   out_7837152669402150713[159] = 0.0;
   out_7837152669402150713[160] = 0.0;
   out_7837152669402150713[161] = 0.0;
   out_7837152669402150713[162] = 0.0;
   out_7837152669402150713[163] = 0.0;
   out_7837152669402150713[164] = 0.0;
   out_7837152669402150713[165] = 0.0;
   out_7837152669402150713[166] = 0.0;
   out_7837152669402150713[167] = 0.0;
   out_7837152669402150713[168] = 0.0;
   out_7837152669402150713[169] = 0.0;
   out_7837152669402150713[170] = 0.0;
   out_7837152669402150713[171] = 1.0;
   out_7837152669402150713[172] = 0.0;
   out_7837152669402150713[173] = 0.0;
   out_7837152669402150713[174] = 0.0;
   out_7837152669402150713[175] = 0.0;
   out_7837152669402150713[176] = 0.0;
   out_7837152669402150713[177] = 0.0;
   out_7837152669402150713[178] = 0.0;
   out_7837152669402150713[179] = 0.0;
   out_7837152669402150713[180] = 0.0;
   out_7837152669402150713[181] = 0.0;
   out_7837152669402150713[182] = 0.0;
   out_7837152669402150713[183] = 0.0;
   out_7837152669402150713[184] = 0.0;
   out_7837152669402150713[185] = 0.0;
   out_7837152669402150713[186] = 0.0;
   out_7837152669402150713[187] = 0.0;
   out_7837152669402150713[188] = 0.0;
   out_7837152669402150713[189] = 0.0;
   out_7837152669402150713[190] = 1.0;
   out_7837152669402150713[191] = 0.0;
   out_7837152669402150713[192] = 0.0;
   out_7837152669402150713[193] = 0.0;
   out_7837152669402150713[194] = 0.0;
   out_7837152669402150713[195] = 0.0;
   out_7837152669402150713[196] = 0.0;
   out_7837152669402150713[197] = 0.0;
   out_7837152669402150713[198] = 0.0;
   out_7837152669402150713[199] = 0.0;
   out_7837152669402150713[200] = 0.0;
   out_7837152669402150713[201] = 0.0;
   out_7837152669402150713[202] = 0.0;
   out_7837152669402150713[203] = 0.0;
   out_7837152669402150713[204] = 0.0;
   out_7837152669402150713[205] = 0.0;
   out_7837152669402150713[206] = 0.0;
   out_7837152669402150713[207] = 0.0;
   out_7837152669402150713[208] = 0.0;
   out_7837152669402150713[209] = 1.0;
   out_7837152669402150713[210] = 0.0;
   out_7837152669402150713[211] = 0.0;
   out_7837152669402150713[212] = 0.0;
   out_7837152669402150713[213] = 0.0;
   out_7837152669402150713[214] = 0.0;
   out_7837152669402150713[215] = 0.0;
   out_7837152669402150713[216] = 0.0;
   out_7837152669402150713[217] = 0.0;
   out_7837152669402150713[218] = 0.0;
   out_7837152669402150713[219] = 0.0;
   out_7837152669402150713[220] = 0.0;
   out_7837152669402150713[221] = 0.0;
   out_7837152669402150713[222] = 0.0;
   out_7837152669402150713[223] = 0.0;
   out_7837152669402150713[224] = 0.0;
   out_7837152669402150713[225] = 0.0;
   out_7837152669402150713[226] = 0.0;
   out_7837152669402150713[227] = 0.0;
   out_7837152669402150713[228] = 1.0;
   out_7837152669402150713[229] = 0.0;
   out_7837152669402150713[230] = 0.0;
   out_7837152669402150713[231] = 0.0;
   out_7837152669402150713[232] = 0.0;
   out_7837152669402150713[233] = 0.0;
   out_7837152669402150713[234] = 0.0;
   out_7837152669402150713[235] = 0.0;
   out_7837152669402150713[236] = 0.0;
   out_7837152669402150713[237] = 0.0;
   out_7837152669402150713[238] = 0.0;
   out_7837152669402150713[239] = 0.0;
   out_7837152669402150713[240] = 0.0;
   out_7837152669402150713[241] = 0.0;
   out_7837152669402150713[242] = 0.0;
   out_7837152669402150713[243] = 0.0;
   out_7837152669402150713[244] = 0.0;
   out_7837152669402150713[245] = 0.0;
   out_7837152669402150713[246] = 0.0;
   out_7837152669402150713[247] = 1.0;
   out_7837152669402150713[248] = 0.0;
   out_7837152669402150713[249] = 0.0;
   out_7837152669402150713[250] = 0.0;
   out_7837152669402150713[251] = 0.0;
   out_7837152669402150713[252] = 0.0;
   out_7837152669402150713[253] = 0.0;
   out_7837152669402150713[254] = 0.0;
   out_7837152669402150713[255] = 0.0;
   out_7837152669402150713[256] = 0.0;
   out_7837152669402150713[257] = 0.0;
   out_7837152669402150713[258] = 0.0;
   out_7837152669402150713[259] = 0.0;
   out_7837152669402150713[260] = 0.0;
   out_7837152669402150713[261] = 0.0;
   out_7837152669402150713[262] = 0.0;
   out_7837152669402150713[263] = 0.0;
   out_7837152669402150713[264] = 0.0;
   out_7837152669402150713[265] = 0.0;
   out_7837152669402150713[266] = 1.0;
   out_7837152669402150713[267] = 0.0;
   out_7837152669402150713[268] = 0.0;
   out_7837152669402150713[269] = 0.0;
   out_7837152669402150713[270] = 0.0;
   out_7837152669402150713[271] = 0.0;
   out_7837152669402150713[272] = 0.0;
   out_7837152669402150713[273] = 0.0;
   out_7837152669402150713[274] = 0.0;
   out_7837152669402150713[275] = 0.0;
   out_7837152669402150713[276] = 0.0;
   out_7837152669402150713[277] = 0.0;
   out_7837152669402150713[278] = 0.0;
   out_7837152669402150713[279] = 0.0;
   out_7837152669402150713[280] = 0.0;
   out_7837152669402150713[281] = 0.0;
   out_7837152669402150713[282] = 0.0;
   out_7837152669402150713[283] = 0.0;
   out_7837152669402150713[284] = 0.0;
   out_7837152669402150713[285] = 1.0;
   out_7837152669402150713[286] = 0.0;
   out_7837152669402150713[287] = 0.0;
   out_7837152669402150713[288] = 0.0;
   out_7837152669402150713[289] = 0.0;
   out_7837152669402150713[290] = 0.0;
   out_7837152669402150713[291] = 0.0;
   out_7837152669402150713[292] = 0.0;
   out_7837152669402150713[293] = 0.0;
   out_7837152669402150713[294] = 0.0;
   out_7837152669402150713[295] = 0.0;
   out_7837152669402150713[296] = 0.0;
   out_7837152669402150713[297] = 0.0;
   out_7837152669402150713[298] = 0.0;
   out_7837152669402150713[299] = 0.0;
   out_7837152669402150713[300] = 0.0;
   out_7837152669402150713[301] = 0.0;
   out_7837152669402150713[302] = 0.0;
   out_7837152669402150713[303] = 0.0;
   out_7837152669402150713[304] = 1.0;
   out_7837152669402150713[305] = 0.0;
   out_7837152669402150713[306] = 0.0;
   out_7837152669402150713[307] = 0.0;
   out_7837152669402150713[308] = 0.0;
   out_7837152669402150713[309] = 0.0;
   out_7837152669402150713[310] = 0.0;
   out_7837152669402150713[311] = 0.0;
   out_7837152669402150713[312] = 0.0;
   out_7837152669402150713[313] = 0.0;
   out_7837152669402150713[314] = 0.0;
   out_7837152669402150713[315] = 0.0;
   out_7837152669402150713[316] = 0.0;
   out_7837152669402150713[317] = 0.0;
   out_7837152669402150713[318] = 0.0;
   out_7837152669402150713[319] = 0.0;
   out_7837152669402150713[320] = 0.0;
   out_7837152669402150713[321] = 0.0;
   out_7837152669402150713[322] = 0.0;
   out_7837152669402150713[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_8293850048606202954) {
   out_8293850048606202954[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_8293850048606202954[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_8293850048606202954[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_8293850048606202954[3] = dt*state[12] + state[3];
   out_8293850048606202954[4] = dt*state[13] + state[4];
   out_8293850048606202954[5] = dt*state[14] + state[5];
   out_8293850048606202954[6] = state[6];
   out_8293850048606202954[7] = state[7];
   out_8293850048606202954[8] = state[8];
   out_8293850048606202954[9] = state[9];
   out_8293850048606202954[10] = state[10];
   out_8293850048606202954[11] = state[11];
   out_8293850048606202954[12] = state[12];
   out_8293850048606202954[13] = state[13];
   out_8293850048606202954[14] = state[14];
   out_8293850048606202954[15] = state[15];
   out_8293850048606202954[16] = state[16];
   out_8293850048606202954[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1277983044864762150) {
   out_1277983044864762150[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1277983044864762150[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1277983044864762150[2] = 0;
   out_1277983044864762150[3] = 0;
   out_1277983044864762150[4] = 0;
   out_1277983044864762150[5] = 0;
   out_1277983044864762150[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1277983044864762150[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1277983044864762150[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1277983044864762150[9] = 0;
   out_1277983044864762150[10] = 0;
   out_1277983044864762150[11] = 0;
   out_1277983044864762150[12] = 0;
   out_1277983044864762150[13] = 0;
   out_1277983044864762150[14] = 0;
   out_1277983044864762150[15] = 0;
   out_1277983044864762150[16] = 0;
   out_1277983044864762150[17] = 0;
   out_1277983044864762150[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1277983044864762150[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1277983044864762150[20] = 0;
   out_1277983044864762150[21] = 0;
   out_1277983044864762150[22] = 0;
   out_1277983044864762150[23] = 0;
   out_1277983044864762150[24] = 0;
   out_1277983044864762150[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1277983044864762150[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1277983044864762150[27] = 0;
   out_1277983044864762150[28] = 0;
   out_1277983044864762150[29] = 0;
   out_1277983044864762150[30] = 0;
   out_1277983044864762150[31] = 0;
   out_1277983044864762150[32] = 0;
   out_1277983044864762150[33] = 0;
   out_1277983044864762150[34] = 0;
   out_1277983044864762150[35] = 0;
   out_1277983044864762150[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1277983044864762150[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1277983044864762150[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1277983044864762150[39] = 0;
   out_1277983044864762150[40] = 0;
   out_1277983044864762150[41] = 0;
   out_1277983044864762150[42] = 0;
   out_1277983044864762150[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1277983044864762150[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1277983044864762150[45] = 0;
   out_1277983044864762150[46] = 0;
   out_1277983044864762150[47] = 0;
   out_1277983044864762150[48] = 0;
   out_1277983044864762150[49] = 0;
   out_1277983044864762150[50] = 0;
   out_1277983044864762150[51] = 0;
   out_1277983044864762150[52] = 0;
   out_1277983044864762150[53] = 0;
   out_1277983044864762150[54] = 0;
   out_1277983044864762150[55] = 0;
   out_1277983044864762150[56] = 0;
   out_1277983044864762150[57] = 1;
   out_1277983044864762150[58] = 0;
   out_1277983044864762150[59] = 0;
   out_1277983044864762150[60] = 0;
   out_1277983044864762150[61] = 0;
   out_1277983044864762150[62] = 0;
   out_1277983044864762150[63] = 0;
   out_1277983044864762150[64] = 0;
   out_1277983044864762150[65] = 0;
   out_1277983044864762150[66] = dt;
   out_1277983044864762150[67] = 0;
   out_1277983044864762150[68] = 0;
   out_1277983044864762150[69] = 0;
   out_1277983044864762150[70] = 0;
   out_1277983044864762150[71] = 0;
   out_1277983044864762150[72] = 0;
   out_1277983044864762150[73] = 0;
   out_1277983044864762150[74] = 0;
   out_1277983044864762150[75] = 0;
   out_1277983044864762150[76] = 1;
   out_1277983044864762150[77] = 0;
   out_1277983044864762150[78] = 0;
   out_1277983044864762150[79] = 0;
   out_1277983044864762150[80] = 0;
   out_1277983044864762150[81] = 0;
   out_1277983044864762150[82] = 0;
   out_1277983044864762150[83] = 0;
   out_1277983044864762150[84] = 0;
   out_1277983044864762150[85] = dt;
   out_1277983044864762150[86] = 0;
   out_1277983044864762150[87] = 0;
   out_1277983044864762150[88] = 0;
   out_1277983044864762150[89] = 0;
   out_1277983044864762150[90] = 0;
   out_1277983044864762150[91] = 0;
   out_1277983044864762150[92] = 0;
   out_1277983044864762150[93] = 0;
   out_1277983044864762150[94] = 0;
   out_1277983044864762150[95] = 1;
   out_1277983044864762150[96] = 0;
   out_1277983044864762150[97] = 0;
   out_1277983044864762150[98] = 0;
   out_1277983044864762150[99] = 0;
   out_1277983044864762150[100] = 0;
   out_1277983044864762150[101] = 0;
   out_1277983044864762150[102] = 0;
   out_1277983044864762150[103] = 0;
   out_1277983044864762150[104] = dt;
   out_1277983044864762150[105] = 0;
   out_1277983044864762150[106] = 0;
   out_1277983044864762150[107] = 0;
   out_1277983044864762150[108] = 0;
   out_1277983044864762150[109] = 0;
   out_1277983044864762150[110] = 0;
   out_1277983044864762150[111] = 0;
   out_1277983044864762150[112] = 0;
   out_1277983044864762150[113] = 0;
   out_1277983044864762150[114] = 1;
   out_1277983044864762150[115] = 0;
   out_1277983044864762150[116] = 0;
   out_1277983044864762150[117] = 0;
   out_1277983044864762150[118] = 0;
   out_1277983044864762150[119] = 0;
   out_1277983044864762150[120] = 0;
   out_1277983044864762150[121] = 0;
   out_1277983044864762150[122] = 0;
   out_1277983044864762150[123] = 0;
   out_1277983044864762150[124] = 0;
   out_1277983044864762150[125] = 0;
   out_1277983044864762150[126] = 0;
   out_1277983044864762150[127] = 0;
   out_1277983044864762150[128] = 0;
   out_1277983044864762150[129] = 0;
   out_1277983044864762150[130] = 0;
   out_1277983044864762150[131] = 0;
   out_1277983044864762150[132] = 0;
   out_1277983044864762150[133] = 1;
   out_1277983044864762150[134] = 0;
   out_1277983044864762150[135] = 0;
   out_1277983044864762150[136] = 0;
   out_1277983044864762150[137] = 0;
   out_1277983044864762150[138] = 0;
   out_1277983044864762150[139] = 0;
   out_1277983044864762150[140] = 0;
   out_1277983044864762150[141] = 0;
   out_1277983044864762150[142] = 0;
   out_1277983044864762150[143] = 0;
   out_1277983044864762150[144] = 0;
   out_1277983044864762150[145] = 0;
   out_1277983044864762150[146] = 0;
   out_1277983044864762150[147] = 0;
   out_1277983044864762150[148] = 0;
   out_1277983044864762150[149] = 0;
   out_1277983044864762150[150] = 0;
   out_1277983044864762150[151] = 0;
   out_1277983044864762150[152] = 1;
   out_1277983044864762150[153] = 0;
   out_1277983044864762150[154] = 0;
   out_1277983044864762150[155] = 0;
   out_1277983044864762150[156] = 0;
   out_1277983044864762150[157] = 0;
   out_1277983044864762150[158] = 0;
   out_1277983044864762150[159] = 0;
   out_1277983044864762150[160] = 0;
   out_1277983044864762150[161] = 0;
   out_1277983044864762150[162] = 0;
   out_1277983044864762150[163] = 0;
   out_1277983044864762150[164] = 0;
   out_1277983044864762150[165] = 0;
   out_1277983044864762150[166] = 0;
   out_1277983044864762150[167] = 0;
   out_1277983044864762150[168] = 0;
   out_1277983044864762150[169] = 0;
   out_1277983044864762150[170] = 0;
   out_1277983044864762150[171] = 1;
   out_1277983044864762150[172] = 0;
   out_1277983044864762150[173] = 0;
   out_1277983044864762150[174] = 0;
   out_1277983044864762150[175] = 0;
   out_1277983044864762150[176] = 0;
   out_1277983044864762150[177] = 0;
   out_1277983044864762150[178] = 0;
   out_1277983044864762150[179] = 0;
   out_1277983044864762150[180] = 0;
   out_1277983044864762150[181] = 0;
   out_1277983044864762150[182] = 0;
   out_1277983044864762150[183] = 0;
   out_1277983044864762150[184] = 0;
   out_1277983044864762150[185] = 0;
   out_1277983044864762150[186] = 0;
   out_1277983044864762150[187] = 0;
   out_1277983044864762150[188] = 0;
   out_1277983044864762150[189] = 0;
   out_1277983044864762150[190] = 1;
   out_1277983044864762150[191] = 0;
   out_1277983044864762150[192] = 0;
   out_1277983044864762150[193] = 0;
   out_1277983044864762150[194] = 0;
   out_1277983044864762150[195] = 0;
   out_1277983044864762150[196] = 0;
   out_1277983044864762150[197] = 0;
   out_1277983044864762150[198] = 0;
   out_1277983044864762150[199] = 0;
   out_1277983044864762150[200] = 0;
   out_1277983044864762150[201] = 0;
   out_1277983044864762150[202] = 0;
   out_1277983044864762150[203] = 0;
   out_1277983044864762150[204] = 0;
   out_1277983044864762150[205] = 0;
   out_1277983044864762150[206] = 0;
   out_1277983044864762150[207] = 0;
   out_1277983044864762150[208] = 0;
   out_1277983044864762150[209] = 1;
   out_1277983044864762150[210] = 0;
   out_1277983044864762150[211] = 0;
   out_1277983044864762150[212] = 0;
   out_1277983044864762150[213] = 0;
   out_1277983044864762150[214] = 0;
   out_1277983044864762150[215] = 0;
   out_1277983044864762150[216] = 0;
   out_1277983044864762150[217] = 0;
   out_1277983044864762150[218] = 0;
   out_1277983044864762150[219] = 0;
   out_1277983044864762150[220] = 0;
   out_1277983044864762150[221] = 0;
   out_1277983044864762150[222] = 0;
   out_1277983044864762150[223] = 0;
   out_1277983044864762150[224] = 0;
   out_1277983044864762150[225] = 0;
   out_1277983044864762150[226] = 0;
   out_1277983044864762150[227] = 0;
   out_1277983044864762150[228] = 1;
   out_1277983044864762150[229] = 0;
   out_1277983044864762150[230] = 0;
   out_1277983044864762150[231] = 0;
   out_1277983044864762150[232] = 0;
   out_1277983044864762150[233] = 0;
   out_1277983044864762150[234] = 0;
   out_1277983044864762150[235] = 0;
   out_1277983044864762150[236] = 0;
   out_1277983044864762150[237] = 0;
   out_1277983044864762150[238] = 0;
   out_1277983044864762150[239] = 0;
   out_1277983044864762150[240] = 0;
   out_1277983044864762150[241] = 0;
   out_1277983044864762150[242] = 0;
   out_1277983044864762150[243] = 0;
   out_1277983044864762150[244] = 0;
   out_1277983044864762150[245] = 0;
   out_1277983044864762150[246] = 0;
   out_1277983044864762150[247] = 1;
   out_1277983044864762150[248] = 0;
   out_1277983044864762150[249] = 0;
   out_1277983044864762150[250] = 0;
   out_1277983044864762150[251] = 0;
   out_1277983044864762150[252] = 0;
   out_1277983044864762150[253] = 0;
   out_1277983044864762150[254] = 0;
   out_1277983044864762150[255] = 0;
   out_1277983044864762150[256] = 0;
   out_1277983044864762150[257] = 0;
   out_1277983044864762150[258] = 0;
   out_1277983044864762150[259] = 0;
   out_1277983044864762150[260] = 0;
   out_1277983044864762150[261] = 0;
   out_1277983044864762150[262] = 0;
   out_1277983044864762150[263] = 0;
   out_1277983044864762150[264] = 0;
   out_1277983044864762150[265] = 0;
   out_1277983044864762150[266] = 1;
   out_1277983044864762150[267] = 0;
   out_1277983044864762150[268] = 0;
   out_1277983044864762150[269] = 0;
   out_1277983044864762150[270] = 0;
   out_1277983044864762150[271] = 0;
   out_1277983044864762150[272] = 0;
   out_1277983044864762150[273] = 0;
   out_1277983044864762150[274] = 0;
   out_1277983044864762150[275] = 0;
   out_1277983044864762150[276] = 0;
   out_1277983044864762150[277] = 0;
   out_1277983044864762150[278] = 0;
   out_1277983044864762150[279] = 0;
   out_1277983044864762150[280] = 0;
   out_1277983044864762150[281] = 0;
   out_1277983044864762150[282] = 0;
   out_1277983044864762150[283] = 0;
   out_1277983044864762150[284] = 0;
   out_1277983044864762150[285] = 1;
   out_1277983044864762150[286] = 0;
   out_1277983044864762150[287] = 0;
   out_1277983044864762150[288] = 0;
   out_1277983044864762150[289] = 0;
   out_1277983044864762150[290] = 0;
   out_1277983044864762150[291] = 0;
   out_1277983044864762150[292] = 0;
   out_1277983044864762150[293] = 0;
   out_1277983044864762150[294] = 0;
   out_1277983044864762150[295] = 0;
   out_1277983044864762150[296] = 0;
   out_1277983044864762150[297] = 0;
   out_1277983044864762150[298] = 0;
   out_1277983044864762150[299] = 0;
   out_1277983044864762150[300] = 0;
   out_1277983044864762150[301] = 0;
   out_1277983044864762150[302] = 0;
   out_1277983044864762150[303] = 0;
   out_1277983044864762150[304] = 1;
   out_1277983044864762150[305] = 0;
   out_1277983044864762150[306] = 0;
   out_1277983044864762150[307] = 0;
   out_1277983044864762150[308] = 0;
   out_1277983044864762150[309] = 0;
   out_1277983044864762150[310] = 0;
   out_1277983044864762150[311] = 0;
   out_1277983044864762150[312] = 0;
   out_1277983044864762150[313] = 0;
   out_1277983044864762150[314] = 0;
   out_1277983044864762150[315] = 0;
   out_1277983044864762150[316] = 0;
   out_1277983044864762150[317] = 0;
   out_1277983044864762150[318] = 0;
   out_1277983044864762150[319] = 0;
   out_1277983044864762150[320] = 0;
   out_1277983044864762150[321] = 0;
   out_1277983044864762150[322] = 0;
   out_1277983044864762150[323] = 1;
}
void h_4(double *state, double *unused, double *out_6167073772337384283) {
   out_6167073772337384283[0] = state[6] + state[9];
   out_6167073772337384283[1] = state[7] + state[10];
   out_6167073772337384283[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4761509597555442182) {
   out_4761509597555442182[0] = 0;
   out_4761509597555442182[1] = 0;
   out_4761509597555442182[2] = 0;
   out_4761509597555442182[3] = 0;
   out_4761509597555442182[4] = 0;
   out_4761509597555442182[5] = 0;
   out_4761509597555442182[6] = 1;
   out_4761509597555442182[7] = 0;
   out_4761509597555442182[8] = 0;
   out_4761509597555442182[9] = 1;
   out_4761509597555442182[10] = 0;
   out_4761509597555442182[11] = 0;
   out_4761509597555442182[12] = 0;
   out_4761509597555442182[13] = 0;
   out_4761509597555442182[14] = 0;
   out_4761509597555442182[15] = 0;
   out_4761509597555442182[16] = 0;
   out_4761509597555442182[17] = 0;
   out_4761509597555442182[18] = 0;
   out_4761509597555442182[19] = 0;
   out_4761509597555442182[20] = 0;
   out_4761509597555442182[21] = 0;
   out_4761509597555442182[22] = 0;
   out_4761509597555442182[23] = 0;
   out_4761509597555442182[24] = 0;
   out_4761509597555442182[25] = 1;
   out_4761509597555442182[26] = 0;
   out_4761509597555442182[27] = 0;
   out_4761509597555442182[28] = 1;
   out_4761509597555442182[29] = 0;
   out_4761509597555442182[30] = 0;
   out_4761509597555442182[31] = 0;
   out_4761509597555442182[32] = 0;
   out_4761509597555442182[33] = 0;
   out_4761509597555442182[34] = 0;
   out_4761509597555442182[35] = 0;
   out_4761509597555442182[36] = 0;
   out_4761509597555442182[37] = 0;
   out_4761509597555442182[38] = 0;
   out_4761509597555442182[39] = 0;
   out_4761509597555442182[40] = 0;
   out_4761509597555442182[41] = 0;
   out_4761509597555442182[42] = 0;
   out_4761509597555442182[43] = 0;
   out_4761509597555442182[44] = 1;
   out_4761509597555442182[45] = 0;
   out_4761509597555442182[46] = 0;
   out_4761509597555442182[47] = 1;
   out_4761509597555442182[48] = 0;
   out_4761509597555442182[49] = 0;
   out_4761509597555442182[50] = 0;
   out_4761509597555442182[51] = 0;
   out_4761509597555442182[52] = 0;
   out_4761509597555442182[53] = 0;
}
void h_10(double *state, double *unused, double *out_3137948981903642358) {
   out_3137948981903642358[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_3137948981903642358[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_3137948981903642358[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6455930617601822676) {
   out_6455930617601822676[0] = 0;
   out_6455930617601822676[1] = 9.8100000000000005*cos(state[1]);
   out_6455930617601822676[2] = 0;
   out_6455930617601822676[3] = 0;
   out_6455930617601822676[4] = -state[8];
   out_6455930617601822676[5] = state[7];
   out_6455930617601822676[6] = 0;
   out_6455930617601822676[7] = state[5];
   out_6455930617601822676[8] = -state[4];
   out_6455930617601822676[9] = 0;
   out_6455930617601822676[10] = 0;
   out_6455930617601822676[11] = 0;
   out_6455930617601822676[12] = 1;
   out_6455930617601822676[13] = 0;
   out_6455930617601822676[14] = 0;
   out_6455930617601822676[15] = 1;
   out_6455930617601822676[16] = 0;
   out_6455930617601822676[17] = 0;
   out_6455930617601822676[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6455930617601822676[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6455930617601822676[20] = 0;
   out_6455930617601822676[21] = state[8];
   out_6455930617601822676[22] = 0;
   out_6455930617601822676[23] = -state[6];
   out_6455930617601822676[24] = -state[5];
   out_6455930617601822676[25] = 0;
   out_6455930617601822676[26] = state[3];
   out_6455930617601822676[27] = 0;
   out_6455930617601822676[28] = 0;
   out_6455930617601822676[29] = 0;
   out_6455930617601822676[30] = 0;
   out_6455930617601822676[31] = 1;
   out_6455930617601822676[32] = 0;
   out_6455930617601822676[33] = 0;
   out_6455930617601822676[34] = 1;
   out_6455930617601822676[35] = 0;
   out_6455930617601822676[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6455930617601822676[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6455930617601822676[38] = 0;
   out_6455930617601822676[39] = -state[7];
   out_6455930617601822676[40] = state[6];
   out_6455930617601822676[41] = 0;
   out_6455930617601822676[42] = state[4];
   out_6455930617601822676[43] = -state[3];
   out_6455930617601822676[44] = 0;
   out_6455930617601822676[45] = 0;
   out_6455930617601822676[46] = 0;
   out_6455930617601822676[47] = 0;
   out_6455930617601822676[48] = 0;
   out_6455930617601822676[49] = 0;
   out_6455930617601822676[50] = 1;
   out_6455930617601822676[51] = 0;
   out_6455930617601822676[52] = 0;
   out_6455930617601822676[53] = 1;
}
void h_13(double *state, double *unused, double *out_1578870771935541941) {
   out_1578870771935541941[0] = state[3];
   out_1578870771935541941[1] = state[4];
   out_1578870771935541941[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7973783422887774983) {
   out_7973783422887774983[0] = 0;
   out_7973783422887774983[1] = 0;
   out_7973783422887774983[2] = 0;
   out_7973783422887774983[3] = 1;
   out_7973783422887774983[4] = 0;
   out_7973783422887774983[5] = 0;
   out_7973783422887774983[6] = 0;
   out_7973783422887774983[7] = 0;
   out_7973783422887774983[8] = 0;
   out_7973783422887774983[9] = 0;
   out_7973783422887774983[10] = 0;
   out_7973783422887774983[11] = 0;
   out_7973783422887774983[12] = 0;
   out_7973783422887774983[13] = 0;
   out_7973783422887774983[14] = 0;
   out_7973783422887774983[15] = 0;
   out_7973783422887774983[16] = 0;
   out_7973783422887774983[17] = 0;
   out_7973783422887774983[18] = 0;
   out_7973783422887774983[19] = 0;
   out_7973783422887774983[20] = 0;
   out_7973783422887774983[21] = 0;
   out_7973783422887774983[22] = 1;
   out_7973783422887774983[23] = 0;
   out_7973783422887774983[24] = 0;
   out_7973783422887774983[25] = 0;
   out_7973783422887774983[26] = 0;
   out_7973783422887774983[27] = 0;
   out_7973783422887774983[28] = 0;
   out_7973783422887774983[29] = 0;
   out_7973783422887774983[30] = 0;
   out_7973783422887774983[31] = 0;
   out_7973783422887774983[32] = 0;
   out_7973783422887774983[33] = 0;
   out_7973783422887774983[34] = 0;
   out_7973783422887774983[35] = 0;
   out_7973783422887774983[36] = 0;
   out_7973783422887774983[37] = 0;
   out_7973783422887774983[38] = 0;
   out_7973783422887774983[39] = 0;
   out_7973783422887774983[40] = 0;
   out_7973783422887774983[41] = 1;
   out_7973783422887774983[42] = 0;
   out_7973783422887774983[43] = 0;
   out_7973783422887774983[44] = 0;
   out_7973783422887774983[45] = 0;
   out_7973783422887774983[46] = 0;
   out_7973783422887774983[47] = 0;
   out_7973783422887774983[48] = 0;
   out_7973783422887774983[49] = 0;
   out_7973783422887774983[50] = 0;
   out_7973783422887774983[51] = 0;
   out_7973783422887774983[52] = 0;
   out_7973783422887774983[53] = 0;
}
void h_14(double *state, double *unused, double *out_7672211974709550584) {
   out_7672211974709550584[0] = state[6];
   out_7672211974709550584[1] = state[7];
   out_7672211974709550584[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4326393070910558583) {
   out_4326393070910558583[0] = 0;
   out_4326393070910558583[1] = 0;
   out_4326393070910558583[2] = 0;
   out_4326393070910558583[3] = 0;
   out_4326393070910558583[4] = 0;
   out_4326393070910558583[5] = 0;
   out_4326393070910558583[6] = 1;
   out_4326393070910558583[7] = 0;
   out_4326393070910558583[8] = 0;
   out_4326393070910558583[9] = 0;
   out_4326393070910558583[10] = 0;
   out_4326393070910558583[11] = 0;
   out_4326393070910558583[12] = 0;
   out_4326393070910558583[13] = 0;
   out_4326393070910558583[14] = 0;
   out_4326393070910558583[15] = 0;
   out_4326393070910558583[16] = 0;
   out_4326393070910558583[17] = 0;
   out_4326393070910558583[18] = 0;
   out_4326393070910558583[19] = 0;
   out_4326393070910558583[20] = 0;
   out_4326393070910558583[21] = 0;
   out_4326393070910558583[22] = 0;
   out_4326393070910558583[23] = 0;
   out_4326393070910558583[24] = 0;
   out_4326393070910558583[25] = 1;
   out_4326393070910558583[26] = 0;
   out_4326393070910558583[27] = 0;
   out_4326393070910558583[28] = 0;
   out_4326393070910558583[29] = 0;
   out_4326393070910558583[30] = 0;
   out_4326393070910558583[31] = 0;
   out_4326393070910558583[32] = 0;
   out_4326393070910558583[33] = 0;
   out_4326393070910558583[34] = 0;
   out_4326393070910558583[35] = 0;
   out_4326393070910558583[36] = 0;
   out_4326393070910558583[37] = 0;
   out_4326393070910558583[38] = 0;
   out_4326393070910558583[39] = 0;
   out_4326393070910558583[40] = 0;
   out_4326393070910558583[41] = 0;
   out_4326393070910558583[42] = 0;
   out_4326393070910558583[43] = 0;
   out_4326393070910558583[44] = 1;
   out_4326393070910558583[45] = 0;
   out_4326393070910558583[46] = 0;
   out_4326393070910558583[47] = 0;
   out_4326393070910558583[48] = 0;
   out_4326393070910558583[49] = 0;
   out_4326393070910558583[50] = 0;
   out_4326393070910558583[51] = 0;
   out_4326393070910558583[52] = 0;
   out_4326393070910558583[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_2755267697534836281) {
  err_fun(nom_x, delta_x, out_2755267697534836281);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4688414877314135206) {
  inv_err_fun(nom_x, true_x, out_4688414877314135206);
}
void pose_H_mod_fun(double *state, double *out_7837152669402150713) {
  H_mod_fun(state, out_7837152669402150713);
}
void pose_f_fun(double *state, double dt, double *out_8293850048606202954) {
  f_fun(state,  dt, out_8293850048606202954);
}
void pose_F_fun(double *state, double dt, double *out_1277983044864762150) {
  F_fun(state,  dt, out_1277983044864762150);
}
void pose_h_4(double *state, double *unused, double *out_6167073772337384283) {
  h_4(state, unused, out_6167073772337384283);
}
void pose_H_4(double *state, double *unused, double *out_4761509597555442182) {
  H_4(state, unused, out_4761509597555442182);
}
void pose_h_10(double *state, double *unused, double *out_3137948981903642358) {
  h_10(state, unused, out_3137948981903642358);
}
void pose_H_10(double *state, double *unused, double *out_6455930617601822676) {
  H_10(state, unused, out_6455930617601822676);
}
void pose_h_13(double *state, double *unused, double *out_1578870771935541941) {
  h_13(state, unused, out_1578870771935541941);
}
void pose_H_13(double *state, double *unused, double *out_7973783422887774983) {
  H_13(state, unused, out_7973783422887774983);
}
void pose_h_14(double *state, double *unused, double *out_7672211974709550584) {
  h_14(state, unused, out_7672211974709550584);
}
void pose_H_14(double *state, double *unused, double *out_4326393070910558583) {
  H_14(state, unused, out_4326393070910558583);
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
