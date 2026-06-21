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
void err_fun(double *nom_x, double *delta_x, double *out_8885367235752958450) {
   out_8885367235752958450[0] = delta_x[0] + nom_x[0];
   out_8885367235752958450[1] = delta_x[1] + nom_x[1];
   out_8885367235752958450[2] = delta_x[2] + nom_x[2];
   out_8885367235752958450[3] = delta_x[3] + nom_x[3];
   out_8885367235752958450[4] = delta_x[4] + nom_x[4];
   out_8885367235752958450[5] = delta_x[5] + nom_x[5];
   out_8885367235752958450[6] = delta_x[6] + nom_x[6];
   out_8885367235752958450[7] = delta_x[7] + nom_x[7];
   out_8885367235752958450[8] = delta_x[8] + nom_x[8];
   out_8885367235752958450[9] = delta_x[9] + nom_x[9];
   out_8885367235752958450[10] = delta_x[10] + nom_x[10];
   out_8885367235752958450[11] = delta_x[11] + nom_x[11];
   out_8885367235752958450[12] = delta_x[12] + nom_x[12];
   out_8885367235752958450[13] = delta_x[13] + nom_x[13];
   out_8885367235752958450[14] = delta_x[14] + nom_x[14];
   out_8885367235752958450[15] = delta_x[15] + nom_x[15];
   out_8885367235752958450[16] = delta_x[16] + nom_x[16];
   out_8885367235752958450[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4135735359507688267) {
   out_4135735359507688267[0] = -nom_x[0] + true_x[0];
   out_4135735359507688267[1] = -nom_x[1] + true_x[1];
   out_4135735359507688267[2] = -nom_x[2] + true_x[2];
   out_4135735359507688267[3] = -nom_x[3] + true_x[3];
   out_4135735359507688267[4] = -nom_x[4] + true_x[4];
   out_4135735359507688267[5] = -nom_x[5] + true_x[5];
   out_4135735359507688267[6] = -nom_x[6] + true_x[6];
   out_4135735359507688267[7] = -nom_x[7] + true_x[7];
   out_4135735359507688267[8] = -nom_x[8] + true_x[8];
   out_4135735359507688267[9] = -nom_x[9] + true_x[9];
   out_4135735359507688267[10] = -nom_x[10] + true_x[10];
   out_4135735359507688267[11] = -nom_x[11] + true_x[11];
   out_4135735359507688267[12] = -nom_x[12] + true_x[12];
   out_4135735359507688267[13] = -nom_x[13] + true_x[13];
   out_4135735359507688267[14] = -nom_x[14] + true_x[14];
   out_4135735359507688267[15] = -nom_x[15] + true_x[15];
   out_4135735359507688267[16] = -nom_x[16] + true_x[16];
   out_4135735359507688267[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_2496917717950831316) {
   out_2496917717950831316[0] = 1.0;
   out_2496917717950831316[1] = 0.0;
   out_2496917717950831316[2] = 0.0;
   out_2496917717950831316[3] = 0.0;
   out_2496917717950831316[4] = 0.0;
   out_2496917717950831316[5] = 0.0;
   out_2496917717950831316[6] = 0.0;
   out_2496917717950831316[7] = 0.0;
   out_2496917717950831316[8] = 0.0;
   out_2496917717950831316[9] = 0.0;
   out_2496917717950831316[10] = 0.0;
   out_2496917717950831316[11] = 0.0;
   out_2496917717950831316[12] = 0.0;
   out_2496917717950831316[13] = 0.0;
   out_2496917717950831316[14] = 0.0;
   out_2496917717950831316[15] = 0.0;
   out_2496917717950831316[16] = 0.0;
   out_2496917717950831316[17] = 0.0;
   out_2496917717950831316[18] = 0.0;
   out_2496917717950831316[19] = 1.0;
   out_2496917717950831316[20] = 0.0;
   out_2496917717950831316[21] = 0.0;
   out_2496917717950831316[22] = 0.0;
   out_2496917717950831316[23] = 0.0;
   out_2496917717950831316[24] = 0.0;
   out_2496917717950831316[25] = 0.0;
   out_2496917717950831316[26] = 0.0;
   out_2496917717950831316[27] = 0.0;
   out_2496917717950831316[28] = 0.0;
   out_2496917717950831316[29] = 0.0;
   out_2496917717950831316[30] = 0.0;
   out_2496917717950831316[31] = 0.0;
   out_2496917717950831316[32] = 0.0;
   out_2496917717950831316[33] = 0.0;
   out_2496917717950831316[34] = 0.0;
   out_2496917717950831316[35] = 0.0;
   out_2496917717950831316[36] = 0.0;
   out_2496917717950831316[37] = 0.0;
   out_2496917717950831316[38] = 1.0;
   out_2496917717950831316[39] = 0.0;
   out_2496917717950831316[40] = 0.0;
   out_2496917717950831316[41] = 0.0;
   out_2496917717950831316[42] = 0.0;
   out_2496917717950831316[43] = 0.0;
   out_2496917717950831316[44] = 0.0;
   out_2496917717950831316[45] = 0.0;
   out_2496917717950831316[46] = 0.0;
   out_2496917717950831316[47] = 0.0;
   out_2496917717950831316[48] = 0.0;
   out_2496917717950831316[49] = 0.0;
   out_2496917717950831316[50] = 0.0;
   out_2496917717950831316[51] = 0.0;
   out_2496917717950831316[52] = 0.0;
   out_2496917717950831316[53] = 0.0;
   out_2496917717950831316[54] = 0.0;
   out_2496917717950831316[55] = 0.0;
   out_2496917717950831316[56] = 0.0;
   out_2496917717950831316[57] = 1.0;
   out_2496917717950831316[58] = 0.0;
   out_2496917717950831316[59] = 0.0;
   out_2496917717950831316[60] = 0.0;
   out_2496917717950831316[61] = 0.0;
   out_2496917717950831316[62] = 0.0;
   out_2496917717950831316[63] = 0.0;
   out_2496917717950831316[64] = 0.0;
   out_2496917717950831316[65] = 0.0;
   out_2496917717950831316[66] = 0.0;
   out_2496917717950831316[67] = 0.0;
   out_2496917717950831316[68] = 0.0;
   out_2496917717950831316[69] = 0.0;
   out_2496917717950831316[70] = 0.0;
   out_2496917717950831316[71] = 0.0;
   out_2496917717950831316[72] = 0.0;
   out_2496917717950831316[73] = 0.0;
   out_2496917717950831316[74] = 0.0;
   out_2496917717950831316[75] = 0.0;
   out_2496917717950831316[76] = 1.0;
   out_2496917717950831316[77] = 0.0;
   out_2496917717950831316[78] = 0.0;
   out_2496917717950831316[79] = 0.0;
   out_2496917717950831316[80] = 0.0;
   out_2496917717950831316[81] = 0.0;
   out_2496917717950831316[82] = 0.0;
   out_2496917717950831316[83] = 0.0;
   out_2496917717950831316[84] = 0.0;
   out_2496917717950831316[85] = 0.0;
   out_2496917717950831316[86] = 0.0;
   out_2496917717950831316[87] = 0.0;
   out_2496917717950831316[88] = 0.0;
   out_2496917717950831316[89] = 0.0;
   out_2496917717950831316[90] = 0.0;
   out_2496917717950831316[91] = 0.0;
   out_2496917717950831316[92] = 0.0;
   out_2496917717950831316[93] = 0.0;
   out_2496917717950831316[94] = 0.0;
   out_2496917717950831316[95] = 1.0;
   out_2496917717950831316[96] = 0.0;
   out_2496917717950831316[97] = 0.0;
   out_2496917717950831316[98] = 0.0;
   out_2496917717950831316[99] = 0.0;
   out_2496917717950831316[100] = 0.0;
   out_2496917717950831316[101] = 0.0;
   out_2496917717950831316[102] = 0.0;
   out_2496917717950831316[103] = 0.0;
   out_2496917717950831316[104] = 0.0;
   out_2496917717950831316[105] = 0.0;
   out_2496917717950831316[106] = 0.0;
   out_2496917717950831316[107] = 0.0;
   out_2496917717950831316[108] = 0.0;
   out_2496917717950831316[109] = 0.0;
   out_2496917717950831316[110] = 0.0;
   out_2496917717950831316[111] = 0.0;
   out_2496917717950831316[112] = 0.0;
   out_2496917717950831316[113] = 0.0;
   out_2496917717950831316[114] = 1.0;
   out_2496917717950831316[115] = 0.0;
   out_2496917717950831316[116] = 0.0;
   out_2496917717950831316[117] = 0.0;
   out_2496917717950831316[118] = 0.0;
   out_2496917717950831316[119] = 0.0;
   out_2496917717950831316[120] = 0.0;
   out_2496917717950831316[121] = 0.0;
   out_2496917717950831316[122] = 0.0;
   out_2496917717950831316[123] = 0.0;
   out_2496917717950831316[124] = 0.0;
   out_2496917717950831316[125] = 0.0;
   out_2496917717950831316[126] = 0.0;
   out_2496917717950831316[127] = 0.0;
   out_2496917717950831316[128] = 0.0;
   out_2496917717950831316[129] = 0.0;
   out_2496917717950831316[130] = 0.0;
   out_2496917717950831316[131] = 0.0;
   out_2496917717950831316[132] = 0.0;
   out_2496917717950831316[133] = 1.0;
   out_2496917717950831316[134] = 0.0;
   out_2496917717950831316[135] = 0.0;
   out_2496917717950831316[136] = 0.0;
   out_2496917717950831316[137] = 0.0;
   out_2496917717950831316[138] = 0.0;
   out_2496917717950831316[139] = 0.0;
   out_2496917717950831316[140] = 0.0;
   out_2496917717950831316[141] = 0.0;
   out_2496917717950831316[142] = 0.0;
   out_2496917717950831316[143] = 0.0;
   out_2496917717950831316[144] = 0.0;
   out_2496917717950831316[145] = 0.0;
   out_2496917717950831316[146] = 0.0;
   out_2496917717950831316[147] = 0.0;
   out_2496917717950831316[148] = 0.0;
   out_2496917717950831316[149] = 0.0;
   out_2496917717950831316[150] = 0.0;
   out_2496917717950831316[151] = 0.0;
   out_2496917717950831316[152] = 1.0;
   out_2496917717950831316[153] = 0.0;
   out_2496917717950831316[154] = 0.0;
   out_2496917717950831316[155] = 0.0;
   out_2496917717950831316[156] = 0.0;
   out_2496917717950831316[157] = 0.0;
   out_2496917717950831316[158] = 0.0;
   out_2496917717950831316[159] = 0.0;
   out_2496917717950831316[160] = 0.0;
   out_2496917717950831316[161] = 0.0;
   out_2496917717950831316[162] = 0.0;
   out_2496917717950831316[163] = 0.0;
   out_2496917717950831316[164] = 0.0;
   out_2496917717950831316[165] = 0.0;
   out_2496917717950831316[166] = 0.0;
   out_2496917717950831316[167] = 0.0;
   out_2496917717950831316[168] = 0.0;
   out_2496917717950831316[169] = 0.0;
   out_2496917717950831316[170] = 0.0;
   out_2496917717950831316[171] = 1.0;
   out_2496917717950831316[172] = 0.0;
   out_2496917717950831316[173] = 0.0;
   out_2496917717950831316[174] = 0.0;
   out_2496917717950831316[175] = 0.0;
   out_2496917717950831316[176] = 0.0;
   out_2496917717950831316[177] = 0.0;
   out_2496917717950831316[178] = 0.0;
   out_2496917717950831316[179] = 0.0;
   out_2496917717950831316[180] = 0.0;
   out_2496917717950831316[181] = 0.0;
   out_2496917717950831316[182] = 0.0;
   out_2496917717950831316[183] = 0.0;
   out_2496917717950831316[184] = 0.0;
   out_2496917717950831316[185] = 0.0;
   out_2496917717950831316[186] = 0.0;
   out_2496917717950831316[187] = 0.0;
   out_2496917717950831316[188] = 0.0;
   out_2496917717950831316[189] = 0.0;
   out_2496917717950831316[190] = 1.0;
   out_2496917717950831316[191] = 0.0;
   out_2496917717950831316[192] = 0.0;
   out_2496917717950831316[193] = 0.0;
   out_2496917717950831316[194] = 0.0;
   out_2496917717950831316[195] = 0.0;
   out_2496917717950831316[196] = 0.0;
   out_2496917717950831316[197] = 0.0;
   out_2496917717950831316[198] = 0.0;
   out_2496917717950831316[199] = 0.0;
   out_2496917717950831316[200] = 0.0;
   out_2496917717950831316[201] = 0.0;
   out_2496917717950831316[202] = 0.0;
   out_2496917717950831316[203] = 0.0;
   out_2496917717950831316[204] = 0.0;
   out_2496917717950831316[205] = 0.0;
   out_2496917717950831316[206] = 0.0;
   out_2496917717950831316[207] = 0.0;
   out_2496917717950831316[208] = 0.0;
   out_2496917717950831316[209] = 1.0;
   out_2496917717950831316[210] = 0.0;
   out_2496917717950831316[211] = 0.0;
   out_2496917717950831316[212] = 0.0;
   out_2496917717950831316[213] = 0.0;
   out_2496917717950831316[214] = 0.0;
   out_2496917717950831316[215] = 0.0;
   out_2496917717950831316[216] = 0.0;
   out_2496917717950831316[217] = 0.0;
   out_2496917717950831316[218] = 0.0;
   out_2496917717950831316[219] = 0.0;
   out_2496917717950831316[220] = 0.0;
   out_2496917717950831316[221] = 0.0;
   out_2496917717950831316[222] = 0.0;
   out_2496917717950831316[223] = 0.0;
   out_2496917717950831316[224] = 0.0;
   out_2496917717950831316[225] = 0.0;
   out_2496917717950831316[226] = 0.0;
   out_2496917717950831316[227] = 0.0;
   out_2496917717950831316[228] = 1.0;
   out_2496917717950831316[229] = 0.0;
   out_2496917717950831316[230] = 0.0;
   out_2496917717950831316[231] = 0.0;
   out_2496917717950831316[232] = 0.0;
   out_2496917717950831316[233] = 0.0;
   out_2496917717950831316[234] = 0.0;
   out_2496917717950831316[235] = 0.0;
   out_2496917717950831316[236] = 0.0;
   out_2496917717950831316[237] = 0.0;
   out_2496917717950831316[238] = 0.0;
   out_2496917717950831316[239] = 0.0;
   out_2496917717950831316[240] = 0.0;
   out_2496917717950831316[241] = 0.0;
   out_2496917717950831316[242] = 0.0;
   out_2496917717950831316[243] = 0.0;
   out_2496917717950831316[244] = 0.0;
   out_2496917717950831316[245] = 0.0;
   out_2496917717950831316[246] = 0.0;
   out_2496917717950831316[247] = 1.0;
   out_2496917717950831316[248] = 0.0;
   out_2496917717950831316[249] = 0.0;
   out_2496917717950831316[250] = 0.0;
   out_2496917717950831316[251] = 0.0;
   out_2496917717950831316[252] = 0.0;
   out_2496917717950831316[253] = 0.0;
   out_2496917717950831316[254] = 0.0;
   out_2496917717950831316[255] = 0.0;
   out_2496917717950831316[256] = 0.0;
   out_2496917717950831316[257] = 0.0;
   out_2496917717950831316[258] = 0.0;
   out_2496917717950831316[259] = 0.0;
   out_2496917717950831316[260] = 0.0;
   out_2496917717950831316[261] = 0.0;
   out_2496917717950831316[262] = 0.0;
   out_2496917717950831316[263] = 0.0;
   out_2496917717950831316[264] = 0.0;
   out_2496917717950831316[265] = 0.0;
   out_2496917717950831316[266] = 1.0;
   out_2496917717950831316[267] = 0.0;
   out_2496917717950831316[268] = 0.0;
   out_2496917717950831316[269] = 0.0;
   out_2496917717950831316[270] = 0.0;
   out_2496917717950831316[271] = 0.0;
   out_2496917717950831316[272] = 0.0;
   out_2496917717950831316[273] = 0.0;
   out_2496917717950831316[274] = 0.0;
   out_2496917717950831316[275] = 0.0;
   out_2496917717950831316[276] = 0.0;
   out_2496917717950831316[277] = 0.0;
   out_2496917717950831316[278] = 0.0;
   out_2496917717950831316[279] = 0.0;
   out_2496917717950831316[280] = 0.0;
   out_2496917717950831316[281] = 0.0;
   out_2496917717950831316[282] = 0.0;
   out_2496917717950831316[283] = 0.0;
   out_2496917717950831316[284] = 0.0;
   out_2496917717950831316[285] = 1.0;
   out_2496917717950831316[286] = 0.0;
   out_2496917717950831316[287] = 0.0;
   out_2496917717950831316[288] = 0.0;
   out_2496917717950831316[289] = 0.0;
   out_2496917717950831316[290] = 0.0;
   out_2496917717950831316[291] = 0.0;
   out_2496917717950831316[292] = 0.0;
   out_2496917717950831316[293] = 0.0;
   out_2496917717950831316[294] = 0.0;
   out_2496917717950831316[295] = 0.0;
   out_2496917717950831316[296] = 0.0;
   out_2496917717950831316[297] = 0.0;
   out_2496917717950831316[298] = 0.0;
   out_2496917717950831316[299] = 0.0;
   out_2496917717950831316[300] = 0.0;
   out_2496917717950831316[301] = 0.0;
   out_2496917717950831316[302] = 0.0;
   out_2496917717950831316[303] = 0.0;
   out_2496917717950831316[304] = 1.0;
   out_2496917717950831316[305] = 0.0;
   out_2496917717950831316[306] = 0.0;
   out_2496917717950831316[307] = 0.0;
   out_2496917717950831316[308] = 0.0;
   out_2496917717950831316[309] = 0.0;
   out_2496917717950831316[310] = 0.0;
   out_2496917717950831316[311] = 0.0;
   out_2496917717950831316[312] = 0.0;
   out_2496917717950831316[313] = 0.0;
   out_2496917717950831316[314] = 0.0;
   out_2496917717950831316[315] = 0.0;
   out_2496917717950831316[316] = 0.0;
   out_2496917717950831316[317] = 0.0;
   out_2496917717950831316[318] = 0.0;
   out_2496917717950831316[319] = 0.0;
   out_2496917717950831316[320] = 0.0;
   out_2496917717950831316[321] = 0.0;
   out_2496917717950831316[322] = 0.0;
   out_2496917717950831316[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6905768897951283532) {
   out_6905768897951283532[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6905768897951283532[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6905768897951283532[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6905768897951283532[3] = dt*state[12] + state[3];
   out_6905768897951283532[4] = dt*state[13] + state[4];
   out_6905768897951283532[5] = dt*state[14] + state[5];
   out_6905768897951283532[6] = state[6];
   out_6905768897951283532[7] = state[7];
   out_6905768897951283532[8] = state[8];
   out_6905768897951283532[9] = state[9];
   out_6905768897951283532[10] = state[10];
   out_6905768897951283532[11] = state[11];
   out_6905768897951283532[12] = state[12];
   out_6905768897951283532[13] = state[13];
   out_6905768897951283532[14] = state[14];
   out_6905768897951283532[15] = state[15];
   out_6905768897951283532[16] = state[16];
   out_6905768897951283532[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5307423376078500036) {
   out_5307423376078500036[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5307423376078500036[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5307423376078500036[2] = 0;
   out_5307423376078500036[3] = 0;
   out_5307423376078500036[4] = 0;
   out_5307423376078500036[5] = 0;
   out_5307423376078500036[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5307423376078500036[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5307423376078500036[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5307423376078500036[9] = 0;
   out_5307423376078500036[10] = 0;
   out_5307423376078500036[11] = 0;
   out_5307423376078500036[12] = 0;
   out_5307423376078500036[13] = 0;
   out_5307423376078500036[14] = 0;
   out_5307423376078500036[15] = 0;
   out_5307423376078500036[16] = 0;
   out_5307423376078500036[17] = 0;
   out_5307423376078500036[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5307423376078500036[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5307423376078500036[20] = 0;
   out_5307423376078500036[21] = 0;
   out_5307423376078500036[22] = 0;
   out_5307423376078500036[23] = 0;
   out_5307423376078500036[24] = 0;
   out_5307423376078500036[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5307423376078500036[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5307423376078500036[27] = 0;
   out_5307423376078500036[28] = 0;
   out_5307423376078500036[29] = 0;
   out_5307423376078500036[30] = 0;
   out_5307423376078500036[31] = 0;
   out_5307423376078500036[32] = 0;
   out_5307423376078500036[33] = 0;
   out_5307423376078500036[34] = 0;
   out_5307423376078500036[35] = 0;
   out_5307423376078500036[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5307423376078500036[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5307423376078500036[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5307423376078500036[39] = 0;
   out_5307423376078500036[40] = 0;
   out_5307423376078500036[41] = 0;
   out_5307423376078500036[42] = 0;
   out_5307423376078500036[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5307423376078500036[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5307423376078500036[45] = 0;
   out_5307423376078500036[46] = 0;
   out_5307423376078500036[47] = 0;
   out_5307423376078500036[48] = 0;
   out_5307423376078500036[49] = 0;
   out_5307423376078500036[50] = 0;
   out_5307423376078500036[51] = 0;
   out_5307423376078500036[52] = 0;
   out_5307423376078500036[53] = 0;
   out_5307423376078500036[54] = 0;
   out_5307423376078500036[55] = 0;
   out_5307423376078500036[56] = 0;
   out_5307423376078500036[57] = 1;
   out_5307423376078500036[58] = 0;
   out_5307423376078500036[59] = 0;
   out_5307423376078500036[60] = 0;
   out_5307423376078500036[61] = 0;
   out_5307423376078500036[62] = 0;
   out_5307423376078500036[63] = 0;
   out_5307423376078500036[64] = 0;
   out_5307423376078500036[65] = 0;
   out_5307423376078500036[66] = dt;
   out_5307423376078500036[67] = 0;
   out_5307423376078500036[68] = 0;
   out_5307423376078500036[69] = 0;
   out_5307423376078500036[70] = 0;
   out_5307423376078500036[71] = 0;
   out_5307423376078500036[72] = 0;
   out_5307423376078500036[73] = 0;
   out_5307423376078500036[74] = 0;
   out_5307423376078500036[75] = 0;
   out_5307423376078500036[76] = 1;
   out_5307423376078500036[77] = 0;
   out_5307423376078500036[78] = 0;
   out_5307423376078500036[79] = 0;
   out_5307423376078500036[80] = 0;
   out_5307423376078500036[81] = 0;
   out_5307423376078500036[82] = 0;
   out_5307423376078500036[83] = 0;
   out_5307423376078500036[84] = 0;
   out_5307423376078500036[85] = dt;
   out_5307423376078500036[86] = 0;
   out_5307423376078500036[87] = 0;
   out_5307423376078500036[88] = 0;
   out_5307423376078500036[89] = 0;
   out_5307423376078500036[90] = 0;
   out_5307423376078500036[91] = 0;
   out_5307423376078500036[92] = 0;
   out_5307423376078500036[93] = 0;
   out_5307423376078500036[94] = 0;
   out_5307423376078500036[95] = 1;
   out_5307423376078500036[96] = 0;
   out_5307423376078500036[97] = 0;
   out_5307423376078500036[98] = 0;
   out_5307423376078500036[99] = 0;
   out_5307423376078500036[100] = 0;
   out_5307423376078500036[101] = 0;
   out_5307423376078500036[102] = 0;
   out_5307423376078500036[103] = 0;
   out_5307423376078500036[104] = dt;
   out_5307423376078500036[105] = 0;
   out_5307423376078500036[106] = 0;
   out_5307423376078500036[107] = 0;
   out_5307423376078500036[108] = 0;
   out_5307423376078500036[109] = 0;
   out_5307423376078500036[110] = 0;
   out_5307423376078500036[111] = 0;
   out_5307423376078500036[112] = 0;
   out_5307423376078500036[113] = 0;
   out_5307423376078500036[114] = 1;
   out_5307423376078500036[115] = 0;
   out_5307423376078500036[116] = 0;
   out_5307423376078500036[117] = 0;
   out_5307423376078500036[118] = 0;
   out_5307423376078500036[119] = 0;
   out_5307423376078500036[120] = 0;
   out_5307423376078500036[121] = 0;
   out_5307423376078500036[122] = 0;
   out_5307423376078500036[123] = 0;
   out_5307423376078500036[124] = 0;
   out_5307423376078500036[125] = 0;
   out_5307423376078500036[126] = 0;
   out_5307423376078500036[127] = 0;
   out_5307423376078500036[128] = 0;
   out_5307423376078500036[129] = 0;
   out_5307423376078500036[130] = 0;
   out_5307423376078500036[131] = 0;
   out_5307423376078500036[132] = 0;
   out_5307423376078500036[133] = 1;
   out_5307423376078500036[134] = 0;
   out_5307423376078500036[135] = 0;
   out_5307423376078500036[136] = 0;
   out_5307423376078500036[137] = 0;
   out_5307423376078500036[138] = 0;
   out_5307423376078500036[139] = 0;
   out_5307423376078500036[140] = 0;
   out_5307423376078500036[141] = 0;
   out_5307423376078500036[142] = 0;
   out_5307423376078500036[143] = 0;
   out_5307423376078500036[144] = 0;
   out_5307423376078500036[145] = 0;
   out_5307423376078500036[146] = 0;
   out_5307423376078500036[147] = 0;
   out_5307423376078500036[148] = 0;
   out_5307423376078500036[149] = 0;
   out_5307423376078500036[150] = 0;
   out_5307423376078500036[151] = 0;
   out_5307423376078500036[152] = 1;
   out_5307423376078500036[153] = 0;
   out_5307423376078500036[154] = 0;
   out_5307423376078500036[155] = 0;
   out_5307423376078500036[156] = 0;
   out_5307423376078500036[157] = 0;
   out_5307423376078500036[158] = 0;
   out_5307423376078500036[159] = 0;
   out_5307423376078500036[160] = 0;
   out_5307423376078500036[161] = 0;
   out_5307423376078500036[162] = 0;
   out_5307423376078500036[163] = 0;
   out_5307423376078500036[164] = 0;
   out_5307423376078500036[165] = 0;
   out_5307423376078500036[166] = 0;
   out_5307423376078500036[167] = 0;
   out_5307423376078500036[168] = 0;
   out_5307423376078500036[169] = 0;
   out_5307423376078500036[170] = 0;
   out_5307423376078500036[171] = 1;
   out_5307423376078500036[172] = 0;
   out_5307423376078500036[173] = 0;
   out_5307423376078500036[174] = 0;
   out_5307423376078500036[175] = 0;
   out_5307423376078500036[176] = 0;
   out_5307423376078500036[177] = 0;
   out_5307423376078500036[178] = 0;
   out_5307423376078500036[179] = 0;
   out_5307423376078500036[180] = 0;
   out_5307423376078500036[181] = 0;
   out_5307423376078500036[182] = 0;
   out_5307423376078500036[183] = 0;
   out_5307423376078500036[184] = 0;
   out_5307423376078500036[185] = 0;
   out_5307423376078500036[186] = 0;
   out_5307423376078500036[187] = 0;
   out_5307423376078500036[188] = 0;
   out_5307423376078500036[189] = 0;
   out_5307423376078500036[190] = 1;
   out_5307423376078500036[191] = 0;
   out_5307423376078500036[192] = 0;
   out_5307423376078500036[193] = 0;
   out_5307423376078500036[194] = 0;
   out_5307423376078500036[195] = 0;
   out_5307423376078500036[196] = 0;
   out_5307423376078500036[197] = 0;
   out_5307423376078500036[198] = 0;
   out_5307423376078500036[199] = 0;
   out_5307423376078500036[200] = 0;
   out_5307423376078500036[201] = 0;
   out_5307423376078500036[202] = 0;
   out_5307423376078500036[203] = 0;
   out_5307423376078500036[204] = 0;
   out_5307423376078500036[205] = 0;
   out_5307423376078500036[206] = 0;
   out_5307423376078500036[207] = 0;
   out_5307423376078500036[208] = 0;
   out_5307423376078500036[209] = 1;
   out_5307423376078500036[210] = 0;
   out_5307423376078500036[211] = 0;
   out_5307423376078500036[212] = 0;
   out_5307423376078500036[213] = 0;
   out_5307423376078500036[214] = 0;
   out_5307423376078500036[215] = 0;
   out_5307423376078500036[216] = 0;
   out_5307423376078500036[217] = 0;
   out_5307423376078500036[218] = 0;
   out_5307423376078500036[219] = 0;
   out_5307423376078500036[220] = 0;
   out_5307423376078500036[221] = 0;
   out_5307423376078500036[222] = 0;
   out_5307423376078500036[223] = 0;
   out_5307423376078500036[224] = 0;
   out_5307423376078500036[225] = 0;
   out_5307423376078500036[226] = 0;
   out_5307423376078500036[227] = 0;
   out_5307423376078500036[228] = 1;
   out_5307423376078500036[229] = 0;
   out_5307423376078500036[230] = 0;
   out_5307423376078500036[231] = 0;
   out_5307423376078500036[232] = 0;
   out_5307423376078500036[233] = 0;
   out_5307423376078500036[234] = 0;
   out_5307423376078500036[235] = 0;
   out_5307423376078500036[236] = 0;
   out_5307423376078500036[237] = 0;
   out_5307423376078500036[238] = 0;
   out_5307423376078500036[239] = 0;
   out_5307423376078500036[240] = 0;
   out_5307423376078500036[241] = 0;
   out_5307423376078500036[242] = 0;
   out_5307423376078500036[243] = 0;
   out_5307423376078500036[244] = 0;
   out_5307423376078500036[245] = 0;
   out_5307423376078500036[246] = 0;
   out_5307423376078500036[247] = 1;
   out_5307423376078500036[248] = 0;
   out_5307423376078500036[249] = 0;
   out_5307423376078500036[250] = 0;
   out_5307423376078500036[251] = 0;
   out_5307423376078500036[252] = 0;
   out_5307423376078500036[253] = 0;
   out_5307423376078500036[254] = 0;
   out_5307423376078500036[255] = 0;
   out_5307423376078500036[256] = 0;
   out_5307423376078500036[257] = 0;
   out_5307423376078500036[258] = 0;
   out_5307423376078500036[259] = 0;
   out_5307423376078500036[260] = 0;
   out_5307423376078500036[261] = 0;
   out_5307423376078500036[262] = 0;
   out_5307423376078500036[263] = 0;
   out_5307423376078500036[264] = 0;
   out_5307423376078500036[265] = 0;
   out_5307423376078500036[266] = 1;
   out_5307423376078500036[267] = 0;
   out_5307423376078500036[268] = 0;
   out_5307423376078500036[269] = 0;
   out_5307423376078500036[270] = 0;
   out_5307423376078500036[271] = 0;
   out_5307423376078500036[272] = 0;
   out_5307423376078500036[273] = 0;
   out_5307423376078500036[274] = 0;
   out_5307423376078500036[275] = 0;
   out_5307423376078500036[276] = 0;
   out_5307423376078500036[277] = 0;
   out_5307423376078500036[278] = 0;
   out_5307423376078500036[279] = 0;
   out_5307423376078500036[280] = 0;
   out_5307423376078500036[281] = 0;
   out_5307423376078500036[282] = 0;
   out_5307423376078500036[283] = 0;
   out_5307423376078500036[284] = 0;
   out_5307423376078500036[285] = 1;
   out_5307423376078500036[286] = 0;
   out_5307423376078500036[287] = 0;
   out_5307423376078500036[288] = 0;
   out_5307423376078500036[289] = 0;
   out_5307423376078500036[290] = 0;
   out_5307423376078500036[291] = 0;
   out_5307423376078500036[292] = 0;
   out_5307423376078500036[293] = 0;
   out_5307423376078500036[294] = 0;
   out_5307423376078500036[295] = 0;
   out_5307423376078500036[296] = 0;
   out_5307423376078500036[297] = 0;
   out_5307423376078500036[298] = 0;
   out_5307423376078500036[299] = 0;
   out_5307423376078500036[300] = 0;
   out_5307423376078500036[301] = 0;
   out_5307423376078500036[302] = 0;
   out_5307423376078500036[303] = 0;
   out_5307423376078500036[304] = 1;
   out_5307423376078500036[305] = 0;
   out_5307423376078500036[306] = 0;
   out_5307423376078500036[307] = 0;
   out_5307423376078500036[308] = 0;
   out_5307423376078500036[309] = 0;
   out_5307423376078500036[310] = 0;
   out_5307423376078500036[311] = 0;
   out_5307423376078500036[312] = 0;
   out_5307423376078500036[313] = 0;
   out_5307423376078500036[314] = 0;
   out_5307423376078500036[315] = 0;
   out_5307423376078500036[316] = 0;
   out_5307423376078500036[317] = 0;
   out_5307423376078500036[318] = 0;
   out_5307423376078500036[319] = 0;
   out_5307423376078500036[320] = 0;
   out_5307423376078500036[321] = 0;
   out_5307423376078500036[322] = 0;
   out_5307423376078500036[323] = 1;
}
void h_4(double *state, double *unused, double *out_1079193932347421775) {
   out_1079193932347421775[0] = state[6] + state[9];
   out_1079193932347421775[1] = state[7] + state[10];
   out_1079193932347421775[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_1742756715896118709) {
   out_1742756715896118709[0] = 0;
   out_1742756715896118709[1] = 0;
   out_1742756715896118709[2] = 0;
   out_1742756715896118709[3] = 0;
   out_1742756715896118709[4] = 0;
   out_1742756715896118709[5] = 0;
   out_1742756715896118709[6] = 1;
   out_1742756715896118709[7] = 0;
   out_1742756715896118709[8] = 0;
   out_1742756715896118709[9] = 1;
   out_1742756715896118709[10] = 0;
   out_1742756715896118709[11] = 0;
   out_1742756715896118709[12] = 0;
   out_1742756715896118709[13] = 0;
   out_1742756715896118709[14] = 0;
   out_1742756715896118709[15] = 0;
   out_1742756715896118709[16] = 0;
   out_1742756715896118709[17] = 0;
   out_1742756715896118709[18] = 0;
   out_1742756715896118709[19] = 0;
   out_1742756715896118709[20] = 0;
   out_1742756715896118709[21] = 0;
   out_1742756715896118709[22] = 0;
   out_1742756715896118709[23] = 0;
   out_1742756715896118709[24] = 0;
   out_1742756715896118709[25] = 1;
   out_1742756715896118709[26] = 0;
   out_1742756715896118709[27] = 0;
   out_1742756715896118709[28] = 1;
   out_1742756715896118709[29] = 0;
   out_1742756715896118709[30] = 0;
   out_1742756715896118709[31] = 0;
   out_1742756715896118709[32] = 0;
   out_1742756715896118709[33] = 0;
   out_1742756715896118709[34] = 0;
   out_1742756715896118709[35] = 0;
   out_1742756715896118709[36] = 0;
   out_1742756715896118709[37] = 0;
   out_1742756715896118709[38] = 0;
   out_1742756715896118709[39] = 0;
   out_1742756715896118709[40] = 0;
   out_1742756715896118709[41] = 0;
   out_1742756715896118709[42] = 0;
   out_1742756715896118709[43] = 0;
   out_1742756715896118709[44] = 1;
   out_1742756715896118709[45] = 0;
   out_1742756715896118709[46] = 0;
   out_1742756715896118709[47] = 1;
   out_1742756715896118709[48] = 0;
   out_1742756715896118709[49] = 0;
   out_1742756715896118709[50] = 0;
   out_1742756715896118709[51] = 0;
   out_1742756715896118709[52] = 0;
   out_1742756715896118709[53] = 0;
}
void h_10(double *state, double *unused, double *out_6922910997507784152) {
   out_6922910997507784152[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6922910997507784152[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6922910997507784152[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_283934102184360827) {
   out_283934102184360827[0] = 0;
   out_283934102184360827[1] = 9.8100000000000005*cos(state[1]);
   out_283934102184360827[2] = 0;
   out_283934102184360827[3] = 0;
   out_283934102184360827[4] = -state[8];
   out_283934102184360827[5] = state[7];
   out_283934102184360827[6] = 0;
   out_283934102184360827[7] = state[5];
   out_283934102184360827[8] = -state[4];
   out_283934102184360827[9] = 0;
   out_283934102184360827[10] = 0;
   out_283934102184360827[11] = 0;
   out_283934102184360827[12] = 1;
   out_283934102184360827[13] = 0;
   out_283934102184360827[14] = 0;
   out_283934102184360827[15] = 1;
   out_283934102184360827[16] = 0;
   out_283934102184360827[17] = 0;
   out_283934102184360827[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_283934102184360827[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_283934102184360827[20] = 0;
   out_283934102184360827[21] = state[8];
   out_283934102184360827[22] = 0;
   out_283934102184360827[23] = -state[6];
   out_283934102184360827[24] = -state[5];
   out_283934102184360827[25] = 0;
   out_283934102184360827[26] = state[3];
   out_283934102184360827[27] = 0;
   out_283934102184360827[28] = 0;
   out_283934102184360827[29] = 0;
   out_283934102184360827[30] = 0;
   out_283934102184360827[31] = 1;
   out_283934102184360827[32] = 0;
   out_283934102184360827[33] = 0;
   out_283934102184360827[34] = 1;
   out_283934102184360827[35] = 0;
   out_283934102184360827[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_283934102184360827[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_283934102184360827[38] = 0;
   out_283934102184360827[39] = -state[7];
   out_283934102184360827[40] = state[6];
   out_283934102184360827[41] = 0;
   out_283934102184360827[42] = state[4];
   out_283934102184360827[43] = -state[3];
   out_283934102184360827[44] = 0;
   out_283934102184360827[45] = 0;
   out_283934102184360827[46] = 0;
   out_283934102184360827[47] = 0;
   out_283934102184360827[48] = 0;
   out_283934102184360827[49] = 0;
   out_283934102184360827[50] = 1;
   out_283934102184360827[51] = 0;
   out_283934102184360827[52] = 0;
   out_283934102184360827[53] = 1;
}
void h_13(double *state, double *unused, double *out_6392911292944498098) {
   out_6392911292944498098[0] = state[3];
   out_6392911292944498098[1] = state[4];
   out_6392911292944498098[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1469517109436214092) {
   out_1469517109436214092[0] = 0;
   out_1469517109436214092[1] = 0;
   out_1469517109436214092[2] = 0;
   out_1469517109436214092[3] = 1;
   out_1469517109436214092[4] = 0;
   out_1469517109436214092[5] = 0;
   out_1469517109436214092[6] = 0;
   out_1469517109436214092[7] = 0;
   out_1469517109436214092[8] = 0;
   out_1469517109436214092[9] = 0;
   out_1469517109436214092[10] = 0;
   out_1469517109436214092[11] = 0;
   out_1469517109436214092[12] = 0;
   out_1469517109436214092[13] = 0;
   out_1469517109436214092[14] = 0;
   out_1469517109436214092[15] = 0;
   out_1469517109436214092[16] = 0;
   out_1469517109436214092[17] = 0;
   out_1469517109436214092[18] = 0;
   out_1469517109436214092[19] = 0;
   out_1469517109436214092[20] = 0;
   out_1469517109436214092[21] = 0;
   out_1469517109436214092[22] = 1;
   out_1469517109436214092[23] = 0;
   out_1469517109436214092[24] = 0;
   out_1469517109436214092[25] = 0;
   out_1469517109436214092[26] = 0;
   out_1469517109436214092[27] = 0;
   out_1469517109436214092[28] = 0;
   out_1469517109436214092[29] = 0;
   out_1469517109436214092[30] = 0;
   out_1469517109436214092[31] = 0;
   out_1469517109436214092[32] = 0;
   out_1469517109436214092[33] = 0;
   out_1469517109436214092[34] = 0;
   out_1469517109436214092[35] = 0;
   out_1469517109436214092[36] = 0;
   out_1469517109436214092[37] = 0;
   out_1469517109436214092[38] = 0;
   out_1469517109436214092[39] = 0;
   out_1469517109436214092[40] = 0;
   out_1469517109436214092[41] = 1;
   out_1469517109436214092[42] = 0;
   out_1469517109436214092[43] = 0;
   out_1469517109436214092[44] = 0;
   out_1469517109436214092[45] = 0;
   out_1469517109436214092[46] = 0;
   out_1469517109436214092[47] = 0;
   out_1469517109436214092[48] = 0;
   out_1469517109436214092[49] = 0;
   out_1469517109436214092[50] = 0;
   out_1469517109436214092[51] = 0;
   out_1469517109436214092[52] = 0;
   out_1469517109436214092[53] = 0;
}
void h_14(double *state, double *unused, double *out_2710339252461203529) {
   out_2710339252461203529[0] = state[6];
   out_2710339252461203529[1] = state[7];
   out_2710339252461203529[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2220484140443365820) {
   out_2220484140443365820[0] = 0;
   out_2220484140443365820[1] = 0;
   out_2220484140443365820[2] = 0;
   out_2220484140443365820[3] = 0;
   out_2220484140443365820[4] = 0;
   out_2220484140443365820[5] = 0;
   out_2220484140443365820[6] = 1;
   out_2220484140443365820[7] = 0;
   out_2220484140443365820[8] = 0;
   out_2220484140443365820[9] = 0;
   out_2220484140443365820[10] = 0;
   out_2220484140443365820[11] = 0;
   out_2220484140443365820[12] = 0;
   out_2220484140443365820[13] = 0;
   out_2220484140443365820[14] = 0;
   out_2220484140443365820[15] = 0;
   out_2220484140443365820[16] = 0;
   out_2220484140443365820[17] = 0;
   out_2220484140443365820[18] = 0;
   out_2220484140443365820[19] = 0;
   out_2220484140443365820[20] = 0;
   out_2220484140443365820[21] = 0;
   out_2220484140443365820[22] = 0;
   out_2220484140443365820[23] = 0;
   out_2220484140443365820[24] = 0;
   out_2220484140443365820[25] = 1;
   out_2220484140443365820[26] = 0;
   out_2220484140443365820[27] = 0;
   out_2220484140443365820[28] = 0;
   out_2220484140443365820[29] = 0;
   out_2220484140443365820[30] = 0;
   out_2220484140443365820[31] = 0;
   out_2220484140443365820[32] = 0;
   out_2220484140443365820[33] = 0;
   out_2220484140443365820[34] = 0;
   out_2220484140443365820[35] = 0;
   out_2220484140443365820[36] = 0;
   out_2220484140443365820[37] = 0;
   out_2220484140443365820[38] = 0;
   out_2220484140443365820[39] = 0;
   out_2220484140443365820[40] = 0;
   out_2220484140443365820[41] = 0;
   out_2220484140443365820[42] = 0;
   out_2220484140443365820[43] = 0;
   out_2220484140443365820[44] = 1;
   out_2220484140443365820[45] = 0;
   out_2220484140443365820[46] = 0;
   out_2220484140443365820[47] = 0;
   out_2220484140443365820[48] = 0;
   out_2220484140443365820[49] = 0;
   out_2220484140443365820[50] = 0;
   out_2220484140443365820[51] = 0;
   out_2220484140443365820[52] = 0;
   out_2220484140443365820[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_8885367235752958450) {
  err_fun(nom_x, delta_x, out_8885367235752958450);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4135735359507688267) {
  inv_err_fun(nom_x, true_x, out_4135735359507688267);
}
void pose_H_mod_fun(double *state, double *out_2496917717950831316) {
  H_mod_fun(state, out_2496917717950831316);
}
void pose_f_fun(double *state, double dt, double *out_6905768897951283532) {
  f_fun(state,  dt, out_6905768897951283532);
}
void pose_F_fun(double *state, double dt, double *out_5307423376078500036) {
  F_fun(state,  dt, out_5307423376078500036);
}
void pose_h_4(double *state, double *unused, double *out_1079193932347421775) {
  h_4(state, unused, out_1079193932347421775);
}
void pose_H_4(double *state, double *unused, double *out_1742756715896118709) {
  H_4(state, unused, out_1742756715896118709);
}
void pose_h_10(double *state, double *unused, double *out_6922910997507784152) {
  h_10(state, unused, out_6922910997507784152);
}
void pose_H_10(double *state, double *unused, double *out_283934102184360827) {
  H_10(state, unused, out_283934102184360827);
}
void pose_h_13(double *state, double *unused, double *out_6392911292944498098) {
  h_13(state, unused, out_6392911292944498098);
}
void pose_H_13(double *state, double *unused, double *out_1469517109436214092) {
  H_13(state, unused, out_1469517109436214092);
}
void pose_h_14(double *state, double *unused, double *out_2710339252461203529) {
  h_14(state, unused, out_2710339252461203529);
}
void pose_H_14(double *state, double *unused, double *out_2220484140443365820) {
  H_14(state, unused, out_2220484140443365820);
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
