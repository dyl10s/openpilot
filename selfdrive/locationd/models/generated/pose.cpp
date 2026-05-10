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
void err_fun(double *nom_x, double *delta_x, double *out_2383575066684203465) {
   out_2383575066684203465[0] = delta_x[0] + nom_x[0];
   out_2383575066684203465[1] = delta_x[1] + nom_x[1];
   out_2383575066684203465[2] = delta_x[2] + nom_x[2];
   out_2383575066684203465[3] = delta_x[3] + nom_x[3];
   out_2383575066684203465[4] = delta_x[4] + nom_x[4];
   out_2383575066684203465[5] = delta_x[5] + nom_x[5];
   out_2383575066684203465[6] = delta_x[6] + nom_x[6];
   out_2383575066684203465[7] = delta_x[7] + nom_x[7];
   out_2383575066684203465[8] = delta_x[8] + nom_x[8];
   out_2383575066684203465[9] = delta_x[9] + nom_x[9];
   out_2383575066684203465[10] = delta_x[10] + nom_x[10];
   out_2383575066684203465[11] = delta_x[11] + nom_x[11];
   out_2383575066684203465[12] = delta_x[12] + nom_x[12];
   out_2383575066684203465[13] = delta_x[13] + nom_x[13];
   out_2383575066684203465[14] = delta_x[14] + nom_x[14];
   out_2383575066684203465[15] = delta_x[15] + nom_x[15];
   out_2383575066684203465[16] = delta_x[16] + nom_x[16];
   out_2383575066684203465[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2531792213831641268) {
   out_2531792213831641268[0] = -nom_x[0] + true_x[0];
   out_2531792213831641268[1] = -nom_x[1] + true_x[1];
   out_2531792213831641268[2] = -nom_x[2] + true_x[2];
   out_2531792213831641268[3] = -nom_x[3] + true_x[3];
   out_2531792213831641268[4] = -nom_x[4] + true_x[4];
   out_2531792213831641268[5] = -nom_x[5] + true_x[5];
   out_2531792213831641268[6] = -nom_x[6] + true_x[6];
   out_2531792213831641268[7] = -nom_x[7] + true_x[7];
   out_2531792213831641268[8] = -nom_x[8] + true_x[8];
   out_2531792213831641268[9] = -nom_x[9] + true_x[9];
   out_2531792213831641268[10] = -nom_x[10] + true_x[10];
   out_2531792213831641268[11] = -nom_x[11] + true_x[11];
   out_2531792213831641268[12] = -nom_x[12] + true_x[12];
   out_2531792213831641268[13] = -nom_x[13] + true_x[13];
   out_2531792213831641268[14] = -nom_x[14] + true_x[14];
   out_2531792213831641268[15] = -nom_x[15] + true_x[15];
   out_2531792213831641268[16] = -nom_x[16] + true_x[16];
   out_2531792213831641268[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5270168453751144292) {
   out_5270168453751144292[0] = 1.0;
   out_5270168453751144292[1] = 0.0;
   out_5270168453751144292[2] = 0.0;
   out_5270168453751144292[3] = 0.0;
   out_5270168453751144292[4] = 0.0;
   out_5270168453751144292[5] = 0.0;
   out_5270168453751144292[6] = 0.0;
   out_5270168453751144292[7] = 0.0;
   out_5270168453751144292[8] = 0.0;
   out_5270168453751144292[9] = 0.0;
   out_5270168453751144292[10] = 0.0;
   out_5270168453751144292[11] = 0.0;
   out_5270168453751144292[12] = 0.0;
   out_5270168453751144292[13] = 0.0;
   out_5270168453751144292[14] = 0.0;
   out_5270168453751144292[15] = 0.0;
   out_5270168453751144292[16] = 0.0;
   out_5270168453751144292[17] = 0.0;
   out_5270168453751144292[18] = 0.0;
   out_5270168453751144292[19] = 1.0;
   out_5270168453751144292[20] = 0.0;
   out_5270168453751144292[21] = 0.0;
   out_5270168453751144292[22] = 0.0;
   out_5270168453751144292[23] = 0.0;
   out_5270168453751144292[24] = 0.0;
   out_5270168453751144292[25] = 0.0;
   out_5270168453751144292[26] = 0.0;
   out_5270168453751144292[27] = 0.0;
   out_5270168453751144292[28] = 0.0;
   out_5270168453751144292[29] = 0.0;
   out_5270168453751144292[30] = 0.0;
   out_5270168453751144292[31] = 0.0;
   out_5270168453751144292[32] = 0.0;
   out_5270168453751144292[33] = 0.0;
   out_5270168453751144292[34] = 0.0;
   out_5270168453751144292[35] = 0.0;
   out_5270168453751144292[36] = 0.0;
   out_5270168453751144292[37] = 0.0;
   out_5270168453751144292[38] = 1.0;
   out_5270168453751144292[39] = 0.0;
   out_5270168453751144292[40] = 0.0;
   out_5270168453751144292[41] = 0.0;
   out_5270168453751144292[42] = 0.0;
   out_5270168453751144292[43] = 0.0;
   out_5270168453751144292[44] = 0.0;
   out_5270168453751144292[45] = 0.0;
   out_5270168453751144292[46] = 0.0;
   out_5270168453751144292[47] = 0.0;
   out_5270168453751144292[48] = 0.0;
   out_5270168453751144292[49] = 0.0;
   out_5270168453751144292[50] = 0.0;
   out_5270168453751144292[51] = 0.0;
   out_5270168453751144292[52] = 0.0;
   out_5270168453751144292[53] = 0.0;
   out_5270168453751144292[54] = 0.0;
   out_5270168453751144292[55] = 0.0;
   out_5270168453751144292[56] = 0.0;
   out_5270168453751144292[57] = 1.0;
   out_5270168453751144292[58] = 0.0;
   out_5270168453751144292[59] = 0.0;
   out_5270168453751144292[60] = 0.0;
   out_5270168453751144292[61] = 0.0;
   out_5270168453751144292[62] = 0.0;
   out_5270168453751144292[63] = 0.0;
   out_5270168453751144292[64] = 0.0;
   out_5270168453751144292[65] = 0.0;
   out_5270168453751144292[66] = 0.0;
   out_5270168453751144292[67] = 0.0;
   out_5270168453751144292[68] = 0.0;
   out_5270168453751144292[69] = 0.0;
   out_5270168453751144292[70] = 0.0;
   out_5270168453751144292[71] = 0.0;
   out_5270168453751144292[72] = 0.0;
   out_5270168453751144292[73] = 0.0;
   out_5270168453751144292[74] = 0.0;
   out_5270168453751144292[75] = 0.0;
   out_5270168453751144292[76] = 1.0;
   out_5270168453751144292[77] = 0.0;
   out_5270168453751144292[78] = 0.0;
   out_5270168453751144292[79] = 0.0;
   out_5270168453751144292[80] = 0.0;
   out_5270168453751144292[81] = 0.0;
   out_5270168453751144292[82] = 0.0;
   out_5270168453751144292[83] = 0.0;
   out_5270168453751144292[84] = 0.0;
   out_5270168453751144292[85] = 0.0;
   out_5270168453751144292[86] = 0.0;
   out_5270168453751144292[87] = 0.0;
   out_5270168453751144292[88] = 0.0;
   out_5270168453751144292[89] = 0.0;
   out_5270168453751144292[90] = 0.0;
   out_5270168453751144292[91] = 0.0;
   out_5270168453751144292[92] = 0.0;
   out_5270168453751144292[93] = 0.0;
   out_5270168453751144292[94] = 0.0;
   out_5270168453751144292[95] = 1.0;
   out_5270168453751144292[96] = 0.0;
   out_5270168453751144292[97] = 0.0;
   out_5270168453751144292[98] = 0.0;
   out_5270168453751144292[99] = 0.0;
   out_5270168453751144292[100] = 0.0;
   out_5270168453751144292[101] = 0.0;
   out_5270168453751144292[102] = 0.0;
   out_5270168453751144292[103] = 0.0;
   out_5270168453751144292[104] = 0.0;
   out_5270168453751144292[105] = 0.0;
   out_5270168453751144292[106] = 0.0;
   out_5270168453751144292[107] = 0.0;
   out_5270168453751144292[108] = 0.0;
   out_5270168453751144292[109] = 0.0;
   out_5270168453751144292[110] = 0.0;
   out_5270168453751144292[111] = 0.0;
   out_5270168453751144292[112] = 0.0;
   out_5270168453751144292[113] = 0.0;
   out_5270168453751144292[114] = 1.0;
   out_5270168453751144292[115] = 0.0;
   out_5270168453751144292[116] = 0.0;
   out_5270168453751144292[117] = 0.0;
   out_5270168453751144292[118] = 0.0;
   out_5270168453751144292[119] = 0.0;
   out_5270168453751144292[120] = 0.0;
   out_5270168453751144292[121] = 0.0;
   out_5270168453751144292[122] = 0.0;
   out_5270168453751144292[123] = 0.0;
   out_5270168453751144292[124] = 0.0;
   out_5270168453751144292[125] = 0.0;
   out_5270168453751144292[126] = 0.0;
   out_5270168453751144292[127] = 0.0;
   out_5270168453751144292[128] = 0.0;
   out_5270168453751144292[129] = 0.0;
   out_5270168453751144292[130] = 0.0;
   out_5270168453751144292[131] = 0.0;
   out_5270168453751144292[132] = 0.0;
   out_5270168453751144292[133] = 1.0;
   out_5270168453751144292[134] = 0.0;
   out_5270168453751144292[135] = 0.0;
   out_5270168453751144292[136] = 0.0;
   out_5270168453751144292[137] = 0.0;
   out_5270168453751144292[138] = 0.0;
   out_5270168453751144292[139] = 0.0;
   out_5270168453751144292[140] = 0.0;
   out_5270168453751144292[141] = 0.0;
   out_5270168453751144292[142] = 0.0;
   out_5270168453751144292[143] = 0.0;
   out_5270168453751144292[144] = 0.0;
   out_5270168453751144292[145] = 0.0;
   out_5270168453751144292[146] = 0.0;
   out_5270168453751144292[147] = 0.0;
   out_5270168453751144292[148] = 0.0;
   out_5270168453751144292[149] = 0.0;
   out_5270168453751144292[150] = 0.0;
   out_5270168453751144292[151] = 0.0;
   out_5270168453751144292[152] = 1.0;
   out_5270168453751144292[153] = 0.0;
   out_5270168453751144292[154] = 0.0;
   out_5270168453751144292[155] = 0.0;
   out_5270168453751144292[156] = 0.0;
   out_5270168453751144292[157] = 0.0;
   out_5270168453751144292[158] = 0.0;
   out_5270168453751144292[159] = 0.0;
   out_5270168453751144292[160] = 0.0;
   out_5270168453751144292[161] = 0.0;
   out_5270168453751144292[162] = 0.0;
   out_5270168453751144292[163] = 0.0;
   out_5270168453751144292[164] = 0.0;
   out_5270168453751144292[165] = 0.0;
   out_5270168453751144292[166] = 0.0;
   out_5270168453751144292[167] = 0.0;
   out_5270168453751144292[168] = 0.0;
   out_5270168453751144292[169] = 0.0;
   out_5270168453751144292[170] = 0.0;
   out_5270168453751144292[171] = 1.0;
   out_5270168453751144292[172] = 0.0;
   out_5270168453751144292[173] = 0.0;
   out_5270168453751144292[174] = 0.0;
   out_5270168453751144292[175] = 0.0;
   out_5270168453751144292[176] = 0.0;
   out_5270168453751144292[177] = 0.0;
   out_5270168453751144292[178] = 0.0;
   out_5270168453751144292[179] = 0.0;
   out_5270168453751144292[180] = 0.0;
   out_5270168453751144292[181] = 0.0;
   out_5270168453751144292[182] = 0.0;
   out_5270168453751144292[183] = 0.0;
   out_5270168453751144292[184] = 0.0;
   out_5270168453751144292[185] = 0.0;
   out_5270168453751144292[186] = 0.0;
   out_5270168453751144292[187] = 0.0;
   out_5270168453751144292[188] = 0.0;
   out_5270168453751144292[189] = 0.0;
   out_5270168453751144292[190] = 1.0;
   out_5270168453751144292[191] = 0.0;
   out_5270168453751144292[192] = 0.0;
   out_5270168453751144292[193] = 0.0;
   out_5270168453751144292[194] = 0.0;
   out_5270168453751144292[195] = 0.0;
   out_5270168453751144292[196] = 0.0;
   out_5270168453751144292[197] = 0.0;
   out_5270168453751144292[198] = 0.0;
   out_5270168453751144292[199] = 0.0;
   out_5270168453751144292[200] = 0.0;
   out_5270168453751144292[201] = 0.0;
   out_5270168453751144292[202] = 0.0;
   out_5270168453751144292[203] = 0.0;
   out_5270168453751144292[204] = 0.0;
   out_5270168453751144292[205] = 0.0;
   out_5270168453751144292[206] = 0.0;
   out_5270168453751144292[207] = 0.0;
   out_5270168453751144292[208] = 0.0;
   out_5270168453751144292[209] = 1.0;
   out_5270168453751144292[210] = 0.0;
   out_5270168453751144292[211] = 0.0;
   out_5270168453751144292[212] = 0.0;
   out_5270168453751144292[213] = 0.0;
   out_5270168453751144292[214] = 0.0;
   out_5270168453751144292[215] = 0.0;
   out_5270168453751144292[216] = 0.0;
   out_5270168453751144292[217] = 0.0;
   out_5270168453751144292[218] = 0.0;
   out_5270168453751144292[219] = 0.0;
   out_5270168453751144292[220] = 0.0;
   out_5270168453751144292[221] = 0.0;
   out_5270168453751144292[222] = 0.0;
   out_5270168453751144292[223] = 0.0;
   out_5270168453751144292[224] = 0.0;
   out_5270168453751144292[225] = 0.0;
   out_5270168453751144292[226] = 0.0;
   out_5270168453751144292[227] = 0.0;
   out_5270168453751144292[228] = 1.0;
   out_5270168453751144292[229] = 0.0;
   out_5270168453751144292[230] = 0.0;
   out_5270168453751144292[231] = 0.0;
   out_5270168453751144292[232] = 0.0;
   out_5270168453751144292[233] = 0.0;
   out_5270168453751144292[234] = 0.0;
   out_5270168453751144292[235] = 0.0;
   out_5270168453751144292[236] = 0.0;
   out_5270168453751144292[237] = 0.0;
   out_5270168453751144292[238] = 0.0;
   out_5270168453751144292[239] = 0.0;
   out_5270168453751144292[240] = 0.0;
   out_5270168453751144292[241] = 0.0;
   out_5270168453751144292[242] = 0.0;
   out_5270168453751144292[243] = 0.0;
   out_5270168453751144292[244] = 0.0;
   out_5270168453751144292[245] = 0.0;
   out_5270168453751144292[246] = 0.0;
   out_5270168453751144292[247] = 1.0;
   out_5270168453751144292[248] = 0.0;
   out_5270168453751144292[249] = 0.0;
   out_5270168453751144292[250] = 0.0;
   out_5270168453751144292[251] = 0.0;
   out_5270168453751144292[252] = 0.0;
   out_5270168453751144292[253] = 0.0;
   out_5270168453751144292[254] = 0.0;
   out_5270168453751144292[255] = 0.0;
   out_5270168453751144292[256] = 0.0;
   out_5270168453751144292[257] = 0.0;
   out_5270168453751144292[258] = 0.0;
   out_5270168453751144292[259] = 0.0;
   out_5270168453751144292[260] = 0.0;
   out_5270168453751144292[261] = 0.0;
   out_5270168453751144292[262] = 0.0;
   out_5270168453751144292[263] = 0.0;
   out_5270168453751144292[264] = 0.0;
   out_5270168453751144292[265] = 0.0;
   out_5270168453751144292[266] = 1.0;
   out_5270168453751144292[267] = 0.0;
   out_5270168453751144292[268] = 0.0;
   out_5270168453751144292[269] = 0.0;
   out_5270168453751144292[270] = 0.0;
   out_5270168453751144292[271] = 0.0;
   out_5270168453751144292[272] = 0.0;
   out_5270168453751144292[273] = 0.0;
   out_5270168453751144292[274] = 0.0;
   out_5270168453751144292[275] = 0.0;
   out_5270168453751144292[276] = 0.0;
   out_5270168453751144292[277] = 0.0;
   out_5270168453751144292[278] = 0.0;
   out_5270168453751144292[279] = 0.0;
   out_5270168453751144292[280] = 0.0;
   out_5270168453751144292[281] = 0.0;
   out_5270168453751144292[282] = 0.0;
   out_5270168453751144292[283] = 0.0;
   out_5270168453751144292[284] = 0.0;
   out_5270168453751144292[285] = 1.0;
   out_5270168453751144292[286] = 0.0;
   out_5270168453751144292[287] = 0.0;
   out_5270168453751144292[288] = 0.0;
   out_5270168453751144292[289] = 0.0;
   out_5270168453751144292[290] = 0.0;
   out_5270168453751144292[291] = 0.0;
   out_5270168453751144292[292] = 0.0;
   out_5270168453751144292[293] = 0.0;
   out_5270168453751144292[294] = 0.0;
   out_5270168453751144292[295] = 0.0;
   out_5270168453751144292[296] = 0.0;
   out_5270168453751144292[297] = 0.0;
   out_5270168453751144292[298] = 0.0;
   out_5270168453751144292[299] = 0.0;
   out_5270168453751144292[300] = 0.0;
   out_5270168453751144292[301] = 0.0;
   out_5270168453751144292[302] = 0.0;
   out_5270168453751144292[303] = 0.0;
   out_5270168453751144292[304] = 1.0;
   out_5270168453751144292[305] = 0.0;
   out_5270168453751144292[306] = 0.0;
   out_5270168453751144292[307] = 0.0;
   out_5270168453751144292[308] = 0.0;
   out_5270168453751144292[309] = 0.0;
   out_5270168453751144292[310] = 0.0;
   out_5270168453751144292[311] = 0.0;
   out_5270168453751144292[312] = 0.0;
   out_5270168453751144292[313] = 0.0;
   out_5270168453751144292[314] = 0.0;
   out_5270168453751144292[315] = 0.0;
   out_5270168453751144292[316] = 0.0;
   out_5270168453751144292[317] = 0.0;
   out_5270168453751144292[318] = 0.0;
   out_5270168453751144292[319] = 0.0;
   out_5270168453751144292[320] = 0.0;
   out_5270168453751144292[321] = 0.0;
   out_5270168453751144292[322] = 0.0;
   out_5270168453751144292[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5870118476100851027) {
   out_5870118476100851027[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5870118476100851027[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5870118476100851027[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5870118476100851027[3] = dt*state[12] + state[3];
   out_5870118476100851027[4] = dt*state[13] + state[4];
   out_5870118476100851027[5] = dt*state[14] + state[5];
   out_5870118476100851027[6] = state[6];
   out_5870118476100851027[7] = state[7];
   out_5870118476100851027[8] = state[8];
   out_5870118476100851027[9] = state[9];
   out_5870118476100851027[10] = state[10];
   out_5870118476100851027[11] = state[11];
   out_5870118476100851027[12] = state[12];
   out_5870118476100851027[13] = state[13];
   out_5870118476100851027[14] = state[14];
   out_5870118476100851027[15] = state[15];
   out_5870118476100851027[16] = state[16];
   out_5870118476100851027[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6643036112755764466) {
   out_6643036112755764466[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6643036112755764466[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6643036112755764466[2] = 0;
   out_6643036112755764466[3] = 0;
   out_6643036112755764466[4] = 0;
   out_6643036112755764466[5] = 0;
   out_6643036112755764466[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6643036112755764466[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6643036112755764466[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6643036112755764466[9] = 0;
   out_6643036112755764466[10] = 0;
   out_6643036112755764466[11] = 0;
   out_6643036112755764466[12] = 0;
   out_6643036112755764466[13] = 0;
   out_6643036112755764466[14] = 0;
   out_6643036112755764466[15] = 0;
   out_6643036112755764466[16] = 0;
   out_6643036112755764466[17] = 0;
   out_6643036112755764466[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6643036112755764466[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6643036112755764466[20] = 0;
   out_6643036112755764466[21] = 0;
   out_6643036112755764466[22] = 0;
   out_6643036112755764466[23] = 0;
   out_6643036112755764466[24] = 0;
   out_6643036112755764466[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6643036112755764466[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6643036112755764466[27] = 0;
   out_6643036112755764466[28] = 0;
   out_6643036112755764466[29] = 0;
   out_6643036112755764466[30] = 0;
   out_6643036112755764466[31] = 0;
   out_6643036112755764466[32] = 0;
   out_6643036112755764466[33] = 0;
   out_6643036112755764466[34] = 0;
   out_6643036112755764466[35] = 0;
   out_6643036112755764466[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6643036112755764466[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6643036112755764466[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6643036112755764466[39] = 0;
   out_6643036112755764466[40] = 0;
   out_6643036112755764466[41] = 0;
   out_6643036112755764466[42] = 0;
   out_6643036112755764466[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6643036112755764466[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6643036112755764466[45] = 0;
   out_6643036112755764466[46] = 0;
   out_6643036112755764466[47] = 0;
   out_6643036112755764466[48] = 0;
   out_6643036112755764466[49] = 0;
   out_6643036112755764466[50] = 0;
   out_6643036112755764466[51] = 0;
   out_6643036112755764466[52] = 0;
   out_6643036112755764466[53] = 0;
   out_6643036112755764466[54] = 0;
   out_6643036112755764466[55] = 0;
   out_6643036112755764466[56] = 0;
   out_6643036112755764466[57] = 1;
   out_6643036112755764466[58] = 0;
   out_6643036112755764466[59] = 0;
   out_6643036112755764466[60] = 0;
   out_6643036112755764466[61] = 0;
   out_6643036112755764466[62] = 0;
   out_6643036112755764466[63] = 0;
   out_6643036112755764466[64] = 0;
   out_6643036112755764466[65] = 0;
   out_6643036112755764466[66] = dt;
   out_6643036112755764466[67] = 0;
   out_6643036112755764466[68] = 0;
   out_6643036112755764466[69] = 0;
   out_6643036112755764466[70] = 0;
   out_6643036112755764466[71] = 0;
   out_6643036112755764466[72] = 0;
   out_6643036112755764466[73] = 0;
   out_6643036112755764466[74] = 0;
   out_6643036112755764466[75] = 0;
   out_6643036112755764466[76] = 1;
   out_6643036112755764466[77] = 0;
   out_6643036112755764466[78] = 0;
   out_6643036112755764466[79] = 0;
   out_6643036112755764466[80] = 0;
   out_6643036112755764466[81] = 0;
   out_6643036112755764466[82] = 0;
   out_6643036112755764466[83] = 0;
   out_6643036112755764466[84] = 0;
   out_6643036112755764466[85] = dt;
   out_6643036112755764466[86] = 0;
   out_6643036112755764466[87] = 0;
   out_6643036112755764466[88] = 0;
   out_6643036112755764466[89] = 0;
   out_6643036112755764466[90] = 0;
   out_6643036112755764466[91] = 0;
   out_6643036112755764466[92] = 0;
   out_6643036112755764466[93] = 0;
   out_6643036112755764466[94] = 0;
   out_6643036112755764466[95] = 1;
   out_6643036112755764466[96] = 0;
   out_6643036112755764466[97] = 0;
   out_6643036112755764466[98] = 0;
   out_6643036112755764466[99] = 0;
   out_6643036112755764466[100] = 0;
   out_6643036112755764466[101] = 0;
   out_6643036112755764466[102] = 0;
   out_6643036112755764466[103] = 0;
   out_6643036112755764466[104] = dt;
   out_6643036112755764466[105] = 0;
   out_6643036112755764466[106] = 0;
   out_6643036112755764466[107] = 0;
   out_6643036112755764466[108] = 0;
   out_6643036112755764466[109] = 0;
   out_6643036112755764466[110] = 0;
   out_6643036112755764466[111] = 0;
   out_6643036112755764466[112] = 0;
   out_6643036112755764466[113] = 0;
   out_6643036112755764466[114] = 1;
   out_6643036112755764466[115] = 0;
   out_6643036112755764466[116] = 0;
   out_6643036112755764466[117] = 0;
   out_6643036112755764466[118] = 0;
   out_6643036112755764466[119] = 0;
   out_6643036112755764466[120] = 0;
   out_6643036112755764466[121] = 0;
   out_6643036112755764466[122] = 0;
   out_6643036112755764466[123] = 0;
   out_6643036112755764466[124] = 0;
   out_6643036112755764466[125] = 0;
   out_6643036112755764466[126] = 0;
   out_6643036112755764466[127] = 0;
   out_6643036112755764466[128] = 0;
   out_6643036112755764466[129] = 0;
   out_6643036112755764466[130] = 0;
   out_6643036112755764466[131] = 0;
   out_6643036112755764466[132] = 0;
   out_6643036112755764466[133] = 1;
   out_6643036112755764466[134] = 0;
   out_6643036112755764466[135] = 0;
   out_6643036112755764466[136] = 0;
   out_6643036112755764466[137] = 0;
   out_6643036112755764466[138] = 0;
   out_6643036112755764466[139] = 0;
   out_6643036112755764466[140] = 0;
   out_6643036112755764466[141] = 0;
   out_6643036112755764466[142] = 0;
   out_6643036112755764466[143] = 0;
   out_6643036112755764466[144] = 0;
   out_6643036112755764466[145] = 0;
   out_6643036112755764466[146] = 0;
   out_6643036112755764466[147] = 0;
   out_6643036112755764466[148] = 0;
   out_6643036112755764466[149] = 0;
   out_6643036112755764466[150] = 0;
   out_6643036112755764466[151] = 0;
   out_6643036112755764466[152] = 1;
   out_6643036112755764466[153] = 0;
   out_6643036112755764466[154] = 0;
   out_6643036112755764466[155] = 0;
   out_6643036112755764466[156] = 0;
   out_6643036112755764466[157] = 0;
   out_6643036112755764466[158] = 0;
   out_6643036112755764466[159] = 0;
   out_6643036112755764466[160] = 0;
   out_6643036112755764466[161] = 0;
   out_6643036112755764466[162] = 0;
   out_6643036112755764466[163] = 0;
   out_6643036112755764466[164] = 0;
   out_6643036112755764466[165] = 0;
   out_6643036112755764466[166] = 0;
   out_6643036112755764466[167] = 0;
   out_6643036112755764466[168] = 0;
   out_6643036112755764466[169] = 0;
   out_6643036112755764466[170] = 0;
   out_6643036112755764466[171] = 1;
   out_6643036112755764466[172] = 0;
   out_6643036112755764466[173] = 0;
   out_6643036112755764466[174] = 0;
   out_6643036112755764466[175] = 0;
   out_6643036112755764466[176] = 0;
   out_6643036112755764466[177] = 0;
   out_6643036112755764466[178] = 0;
   out_6643036112755764466[179] = 0;
   out_6643036112755764466[180] = 0;
   out_6643036112755764466[181] = 0;
   out_6643036112755764466[182] = 0;
   out_6643036112755764466[183] = 0;
   out_6643036112755764466[184] = 0;
   out_6643036112755764466[185] = 0;
   out_6643036112755764466[186] = 0;
   out_6643036112755764466[187] = 0;
   out_6643036112755764466[188] = 0;
   out_6643036112755764466[189] = 0;
   out_6643036112755764466[190] = 1;
   out_6643036112755764466[191] = 0;
   out_6643036112755764466[192] = 0;
   out_6643036112755764466[193] = 0;
   out_6643036112755764466[194] = 0;
   out_6643036112755764466[195] = 0;
   out_6643036112755764466[196] = 0;
   out_6643036112755764466[197] = 0;
   out_6643036112755764466[198] = 0;
   out_6643036112755764466[199] = 0;
   out_6643036112755764466[200] = 0;
   out_6643036112755764466[201] = 0;
   out_6643036112755764466[202] = 0;
   out_6643036112755764466[203] = 0;
   out_6643036112755764466[204] = 0;
   out_6643036112755764466[205] = 0;
   out_6643036112755764466[206] = 0;
   out_6643036112755764466[207] = 0;
   out_6643036112755764466[208] = 0;
   out_6643036112755764466[209] = 1;
   out_6643036112755764466[210] = 0;
   out_6643036112755764466[211] = 0;
   out_6643036112755764466[212] = 0;
   out_6643036112755764466[213] = 0;
   out_6643036112755764466[214] = 0;
   out_6643036112755764466[215] = 0;
   out_6643036112755764466[216] = 0;
   out_6643036112755764466[217] = 0;
   out_6643036112755764466[218] = 0;
   out_6643036112755764466[219] = 0;
   out_6643036112755764466[220] = 0;
   out_6643036112755764466[221] = 0;
   out_6643036112755764466[222] = 0;
   out_6643036112755764466[223] = 0;
   out_6643036112755764466[224] = 0;
   out_6643036112755764466[225] = 0;
   out_6643036112755764466[226] = 0;
   out_6643036112755764466[227] = 0;
   out_6643036112755764466[228] = 1;
   out_6643036112755764466[229] = 0;
   out_6643036112755764466[230] = 0;
   out_6643036112755764466[231] = 0;
   out_6643036112755764466[232] = 0;
   out_6643036112755764466[233] = 0;
   out_6643036112755764466[234] = 0;
   out_6643036112755764466[235] = 0;
   out_6643036112755764466[236] = 0;
   out_6643036112755764466[237] = 0;
   out_6643036112755764466[238] = 0;
   out_6643036112755764466[239] = 0;
   out_6643036112755764466[240] = 0;
   out_6643036112755764466[241] = 0;
   out_6643036112755764466[242] = 0;
   out_6643036112755764466[243] = 0;
   out_6643036112755764466[244] = 0;
   out_6643036112755764466[245] = 0;
   out_6643036112755764466[246] = 0;
   out_6643036112755764466[247] = 1;
   out_6643036112755764466[248] = 0;
   out_6643036112755764466[249] = 0;
   out_6643036112755764466[250] = 0;
   out_6643036112755764466[251] = 0;
   out_6643036112755764466[252] = 0;
   out_6643036112755764466[253] = 0;
   out_6643036112755764466[254] = 0;
   out_6643036112755764466[255] = 0;
   out_6643036112755764466[256] = 0;
   out_6643036112755764466[257] = 0;
   out_6643036112755764466[258] = 0;
   out_6643036112755764466[259] = 0;
   out_6643036112755764466[260] = 0;
   out_6643036112755764466[261] = 0;
   out_6643036112755764466[262] = 0;
   out_6643036112755764466[263] = 0;
   out_6643036112755764466[264] = 0;
   out_6643036112755764466[265] = 0;
   out_6643036112755764466[266] = 1;
   out_6643036112755764466[267] = 0;
   out_6643036112755764466[268] = 0;
   out_6643036112755764466[269] = 0;
   out_6643036112755764466[270] = 0;
   out_6643036112755764466[271] = 0;
   out_6643036112755764466[272] = 0;
   out_6643036112755764466[273] = 0;
   out_6643036112755764466[274] = 0;
   out_6643036112755764466[275] = 0;
   out_6643036112755764466[276] = 0;
   out_6643036112755764466[277] = 0;
   out_6643036112755764466[278] = 0;
   out_6643036112755764466[279] = 0;
   out_6643036112755764466[280] = 0;
   out_6643036112755764466[281] = 0;
   out_6643036112755764466[282] = 0;
   out_6643036112755764466[283] = 0;
   out_6643036112755764466[284] = 0;
   out_6643036112755764466[285] = 1;
   out_6643036112755764466[286] = 0;
   out_6643036112755764466[287] = 0;
   out_6643036112755764466[288] = 0;
   out_6643036112755764466[289] = 0;
   out_6643036112755764466[290] = 0;
   out_6643036112755764466[291] = 0;
   out_6643036112755764466[292] = 0;
   out_6643036112755764466[293] = 0;
   out_6643036112755764466[294] = 0;
   out_6643036112755764466[295] = 0;
   out_6643036112755764466[296] = 0;
   out_6643036112755764466[297] = 0;
   out_6643036112755764466[298] = 0;
   out_6643036112755764466[299] = 0;
   out_6643036112755764466[300] = 0;
   out_6643036112755764466[301] = 0;
   out_6643036112755764466[302] = 0;
   out_6643036112755764466[303] = 0;
   out_6643036112755764466[304] = 1;
   out_6643036112755764466[305] = 0;
   out_6643036112755764466[306] = 0;
   out_6643036112755764466[307] = 0;
   out_6643036112755764466[308] = 0;
   out_6643036112755764466[309] = 0;
   out_6643036112755764466[310] = 0;
   out_6643036112755764466[311] = 0;
   out_6643036112755764466[312] = 0;
   out_6643036112755764466[313] = 0;
   out_6643036112755764466[314] = 0;
   out_6643036112755764466[315] = 0;
   out_6643036112755764466[316] = 0;
   out_6643036112755764466[317] = 0;
   out_6643036112755764466[318] = 0;
   out_6643036112755764466[319] = 0;
   out_6643036112755764466[320] = 0;
   out_6643036112755764466[321] = 0;
   out_6643036112755764466[322] = 0;
   out_6643036112755764466[323] = 1;
}
void h_4(double *state, double *unused, double *out_3825151169355500496) {
   out_3825151169355500496[0] = state[6] + state[9];
   out_3825151169355500496[1] = state[7] + state[10];
   out_3825151169355500496[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4438379387875418186) {
   out_4438379387875418186[0] = 0;
   out_4438379387875418186[1] = 0;
   out_4438379387875418186[2] = 0;
   out_4438379387875418186[3] = 0;
   out_4438379387875418186[4] = 0;
   out_4438379387875418186[5] = 0;
   out_4438379387875418186[6] = 1;
   out_4438379387875418186[7] = 0;
   out_4438379387875418186[8] = 0;
   out_4438379387875418186[9] = 1;
   out_4438379387875418186[10] = 0;
   out_4438379387875418186[11] = 0;
   out_4438379387875418186[12] = 0;
   out_4438379387875418186[13] = 0;
   out_4438379387875418186[14] = 0;
   out_4438379387875418186[15] = 0;
   out_4438379387875418186[16] = 0;
   out_4438379387875418186[17] = 0;
   out_4438379387875418186[18] = 0;
   out_4438379387875418186[19] = 0;
   out_4438379387875418186[20] = 0;
   out_4438379387875418186[21] = 0;
   out_4438379387875418186[22] = 0;
   out_4438379387875418186[23] = 0;
   out_4438379387875418186[24] = 0;
   out_4438379387875418186[25] = 1;
   out_4438379387875418186[26] = 0;
   out_4438379387875418186[27] = 0;
   out_4438379387875418186[28] = 1;
   out_4438379387875418186[29] = 0;
   out_4438379387875418186[30] = 0;
   out_4438379387875418186[31] = 0;
   out_4438379387875418186[32] = 0;
   out_4438379387875418186[33] = 0;
   out_4438379387875418186[34] = 0;
   out_4438379387875418186[35] = 0;
   out_4438379387875418186[36] = 0;
   out_4438379387875418186[37] = 0;
   out_4438379387875418186[38] = 0;
   out_4438379387875418186[39] = 0;
   out_4438379387875418186[40] = 0;
   out_4438379387875418186[41] = 0;
   out_4438379387875418186[42] = 0;
   out_4438379387875418186[43] = 0;
   out_4438379387875418186[44] = 1;
   out_4438379387875418186[45] = 0;
   out_4438379387875418186[46] = 0;
   out_4438379387875418186[47] = 1;
   out_4438379387875418186[48] = 0;
   out_4438379387875418186[49] = 0;
   out_4438379387875418186[50] = 0;
   out_4438379387875418186[51] = 0;
   out_4438379387875418186[52] = 0;
   out_4438379387875418186[53] = 0;
}
void h_10(double *state, double *unused, double *out_6180343716098328505) {
   out_6180343716098328505[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6180343716098328505[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6180343716098328505[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6436902649839043686) {
   out_6436902649839043686[0] = 0;
   out_6436902649839043686[1] = 9.8100000000000005*cos(state[1]);
   out_6436902649839043686[2] = 0;
   out_6436902649839043686[3] = 0;
   out_6436902649839043686[4] = -state[8];
   out_6436902649839043686[5] = state[7];
   out_6436902649839043686[6] = 0;
   out_6436902649839043686[7] = state[5];
   out_6436902649839043686[8] = -state[4];
   out_6436902649839043686[9] = 0;
   out_6436902649839043686[10] = 0;
   out_6436902649839043686[11] = 0;
   out_6436902649839043686[12] = 1;
   out_6436902649839043686[13] = 0;
   out_6436902649839043686[14] = 0;
   out_6436902649839043686[15] = 1;
   out_6436902649839043686[16] = 0;
   out_6436902649839043686[17] = 0;
   out_6436902649839043686[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6436902649839043686[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6436902649839043686[20] = 0;
   out_6436902649839043686[21] = state[8];
   out_6436902649839043686[22] = 0;
   out_6436902649839043686[23] = -state[6];
   out_6436902649839043686[24] = -state[5];
   out_6436902649839043686[25] = 0;
   out_6436902649839043686[26] = state[3];
   out_6436902649839043686[27] = 0;
   out_6436902649839043686[28] = 0;
   out_6436902649839043686[29] = 0;
   out_6436902649839043686[30] = 0;
   out_6436902649839043686[31] = 1;
   out_6436902649839043686[32] = 0;
   out_6436902649839043686[33] = 0;
   out_6436902649839043686[34] = 1;
   out_6436902649839043686[35] = 0;
   out_6436902649839043686[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6436902649839043686[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6436902649839043686[38] = 0;
   out_6436902649839043686[39] = -state[7];
   out_6436902649839043686[40] = state[6];
   out_6436902649839043686[41] = 0;
   out_6436902649839043686[42] = state[4];
   out_6436902649839043686[43] = -state[3];
   out_6436902649839043686[44] = 0;
   out_6436902649839043686[45] = 0;
   out_6436902649839043686[46] = 0;
   out_6436902649839043686[47] = 0;
   out_6436902649839043686[48] = 0;
   out_6436902649839043686[49] = 0;
   out_6436902649839043686[50] = 1;
   out_6436902649839043686[51] = 0;
   out_6436902649839043686[52] = 0;
   out_6436902649839043686[53] = 1;
}
void h_13(double *state, double *unused, double *out_5615804281251360017) {
   out_5615804281251360017[0] = state[3];
   out_5615804281251360017[1] = state[4];
   out_5615804281251360017[2] = state[5];
}
void H_13(double *state, double *unused, double *out_8272134851177942210) {
   out_8272134851177942210[0] = 0;
   out_8272134851177942210[1] = 0;
   out_8272134851177942210[2] = 0;
   out_8272134851177942210[3] = 1;
   out_8272134851177942210[4] = 0;
   out_8272134851177942210[5] = 0;
   out_8272134851177942210[6] = 0;
   out_8272134851177942210[7] = 0;
   out_8272134851177942210[8] = 0;
   out_8272134851177942210[9] = 0;
   out_8272134851177942210[10] = 0;
   out_8272134851177942210[11] = 0;
   out_8272134851177942210[12] = 0;
   out_8272134851177942210[13] = 0;
   out_8272134851177942210[14] = 0;
   out_8272134851177942210[15] = 0;
   out_8272134851177942210[16] = 0;
   out_8272134851177942210[17] = 0;
   out_8272134851177942210[18] = 0;
   out_8272134851177942210[19] = 0;
   out_8272134851177942210[20] = 0;
   out_8272134851177942210[21] = 0;
   out_8272134851177942210[22] = 1;
   out_8272134851177942210[23] = 0;
   out_8272134851177942210[24] = 0;
   out_8272134851177942210[25] = 0;
   out_8272134851177942210[26] = 0;
   out_8272134851177942210[27] = 0;
   out_8272134851177942210[28] = 0;
   out_8272134851177942210[29] = 0;
   out_8272134851177942210[30] = 0;
   out_8272134851177942210[31] = 0;
   out_8272134851177942210[32] = 0;
   out_8272134851177942210[33] = 0;
   out_8272134851177942210[34] = 0;
   out_8272134851177942210[35] = 0;
   out_8272134851177942210[36] = 0;
   out_8272134851177942210[37] = 0;
   out_8272134851177942210[38] = 0;
   out_8272134851177942210[39] = 0;
   out_8272134851177942210[40] = 0;
   out_8272134851177942210[41] = 1;
   out_8272134851177942210[42] = 0;
   out_8272134851177942210[43] = 0;
   out_8272134851177942210[44] = 0;
   out_8272134851177942210[45] = 0;
   out_8272134851177942210[46] = 0;
   out_8272134851177942210[47] = 0;
   out_8272134851177942210[48] = 0;
   out_8272134851177942210[49] = 0;
   out_8272134851177942210[50] = 0;
   out_8272134851177942210[51] = 0;
   out_8272134851177942210[52] = 0;
   out_8272134851177942210[53] = 0;
}
void h_14(double *state, double *unused, double *out_1282457731118130678) {
   out_1282457731118130678[0] = state[6];
   out_1282457731118130678[1] = state[7];
   out_1282457731118130678[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7521167820170790482) {
   out_7521167820170790482[0] = 0;
   out_7521167820170790482[1] = 0;
   out_7521167820170790482[2] = 0;
   out_7521167820170790482[3] = 0;
   out_7521167820170790482[4] = 0;
   out_7521167820170790482[5] = 0;
   out_7521167820170790482[6] = 1;
   out_7521167820170790482[7] = 0;
   out_7521167820170790482[8] = 0;
   out_7521167820170790482[9] = 0;
   out_7521167820170790482[10] = 0;
   out_7521167820170790482[11] = 0;
   out_7521167820170790482[12] = 0;
   out_7521167820170790482[13] = 0;
   out_7521167820170790482[14] = 0;
   out_7521167820170790482[15] = 0;
   out_7521167820170790482[16] = 0;
   out_7521167820170790482[17] = 0;
   out_7521167820170790482[18] = 0;
   out_7521167820170790482[19] = 0;
   out_7521167820170790482[20] = 0;
   out_7521167820170790482[21] = 0;
   out_7521167820170790482[22] = 0;
   out_7521167820170790482[23] = 0;
   out_7521167820170790482[24] = 0;
   out_7521167820170790482[25] = 1;
   out_7521167820170790482[26] = 0;
   out_7521167820170790482[27] = 0;
   out_7521167820170790482[28] = 0;
   out_7521167820170790482[29] = 0;
   out_7521167820170790482[30] = 0;
   out_7521167820170790482[31] = 0;
   out_7521167820170790482[32] = 0;
   out_7521167820170790482[33] = 0;
   out_7521167820170790482[34] = 0;
   out_7521167820170790482[35] = 0;
   out_7521167820170790482[36] = 0;
   out_7521167820170790482[37] = 0;
   out_7521167820170790482[38] = 0;
   out_7521167820170790482[39] = 0;
   out_7521167820170790482[40] = 0;
   out_7521167820170790482[41] = 0;
   out_7521167820170790482[42] = 0;
   out_7521167820170790482[43] = 0;
   out_7521167820170790482[44] = 1;
   out_7521167820170790482[45] = 0;
   out_7521167820170790482[46] = 0;
   out_7521167820170790482[47] = 0;
   out_7521167820170790482[48] = 0;
   out_7521167820170790482[49] = 0;
   out_7521167820170790482[50] = 0;
   out_7521167820170790482[51] = 0;
   out_7521167820170790482[52] = 0;
   out_7521167820170790482[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_2383575066684203465) {
  err_fun(nom_x, delta_x, out_2383575066684203465);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2531792213831641268) {
  inv_err_fun(nom_x, true_x, out_2531792213831641268);
}
void pose_H_mod_fun(double *state, double *out_5270168453751144292) {
  H_mod_fun(state, out_5270168453751144292);
}
void pose_f_fun(double *state, double dt, double *out_5870118476100851027) {
  f_fun(state,  dt, out_5870118476100851027);
}
void pose_F_fun(double *state, double dt, double *out_6643036112755764466) {
  F_fun(state,  dt, out_6643036112755764466);
}
void pose_h_4(double *state, double *unused, double *out_3825151169355500496) {
  h_4(state, unused, out_3825151169355500496);
}
void pose_H_4(double *state, double *unused, double *out_4438379387875418186) {
  H_4(state, unused, out_4438379387875418186);
}
void pose_h_10(double *state, double *unused, double *out_6180343716098328505) {
  h_10(state, unused, out_6180343716098328505);
}
void pose_H_10(double *state, double *unused, double *out_6436902649839043686) {
  H_10(state, unused, out_6436902649839043686);
}
void pose_h_13(double *state, double *unused, double *out_5615804281251360017) {
  h_13(state, unused, out_5615804281251360017);
}
void pose_H_13(double *state, double *unused, double *out_8272134851177942210) {
  H_13(state, unused, out_8272134851177942210);
}
void pose_h_14(double *state, double *unused, double *out_1282457731118130678) {
  h_14(state, unused, out_1282457731118130678);
}
void pose_H_14(double *state, double *unused, double *out_7521167820170790482) {
  H_14(state, unused, out_7521167820170790482);
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
