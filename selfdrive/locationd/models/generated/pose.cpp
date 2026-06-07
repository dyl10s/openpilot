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
void err_fun(double *nom_x, double *delta_x, double *out_4833077353004324467) {
   out_4833077353004324467[0] = delta_x[0] + nom_x[0];
   out_4833077353004324467[1] = delta_x[1] + nom_x[1];
   out_4833077353004324467[2] = delta_x[2] + nom_x[2];
   out_4833077353004324467[3] = delta_x[3] + nom_x[3];
   out_4833077353004324467[4] = delta_x[4] + nom_x[4];
   out_4833077353004324467[5] = delta_x[5] + nom_x[5];
   out_4833077353004324467[6] = delta_x[6] + nom_x[6];
   out_4833077353004324467[7] = delta_x[7] + nom_x[7];
   out_4833077353004324467[8] = delta_x[8] + nom_x[8];
   out_4833077353004324467[9] = delta_x[9] + nom_x[9];
   out_4833077353004324467[10] = delta_x[10] + nom_x[10];
   out_4833077353004324467[11] = delta_x[11] + nom_x[11];
   out_4833077353004324467[12] = delta_x[12] + nom_x[12];
   out_4833077353004324467[13] = delta_x[13] + nom_x[13];
   out_4833077353004324467[14] = delta_x[14] + nom_x[14];
   out_4833077353004324467[15] = delta_x[15] + nom_x[15];
   out_4833077353004324467[16] = delta_x[16] + nom_x[16];
   out_4833077353004324467[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4980437301453189923) {
   out_4980437301453189923[0] = -nom_x[0] + true_x[0];
   out_4980437301453189923[1] = -nom_x[1] + true_x[1];
   out_4980437301453189923[2] = -nom_x[2] + true_x[2];
   out_4980437301453189923[3] = -nom_x[3] + true_x[3];
   out_4980437301453189923[4] = -nom_x[4] + true_x[4];
   out_4980437301453189923[5] = -nom_x[5] + true_x[5];
   out_4980437301453189923[6] = -nom_x[6] + true_x[6];
   out_4980437301453189923[7] = -nom_x[7] + true_x[7];
   out_4980437301453189923[8] = -nom_x[8] + true_x[8];
   out_4980437301453189923[9] = -nom_x[9] + true_x[9];
   out_4980437301453189923[10] = -nom_x[10] + true_x[10];
   out_4980437301453189923[11] = -nom_x[11] + true_x[11];
   out_4980437301453189923[12] = -nom_x[12] + true_x[12];
   out_4980437301453189923[13] = -nom_x[13] + true_x[13];
   out_4980437301453189923[14] = -nom_x[14] + true_x[14];
   out_4980437301453189923[15] = -nom_x[15] + true_x[15];
   out_4980437301453189923[16] = -nom_x[16] + true_x[16];
   out_4980437301453189923[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4718726566615345673) {
   out_4718726566615345673[0] = 1.0;
   out_4718726566615345673[1] = 0.0;
   out_4718726566615345673[2] = 0.0;
   out_4718726566615345673[3] = 0.0;
   out_4718726566615345673[4] = 0.0;
   out_4718726566615345673[5] = 0.0;
   out_4718726566615345673[6] = 0.0;
   out_4718726566615345673[7] = 0.0;
   out_4718726566615345673[8] = 0.0;
   out_4718726566615345673[9] = 0.0;
   out_4718726566615345673[10] = 0.0;
   out_4718726566615345673[11] = 0.0;
   out_4718726566615345673[12] = 0.0;
   out_4718726566615345673[13] = 0.0;
   out_4718726566615345673[14] = 0.0;
   out_4718726566615345673[15] = 0.0;
   out_4718726566615345673[16] = 0.0;
   out_4718726566615345673[17] = 0.0;
   out_4718726566615345673[18] = 0.0;
   out_4718726566615345673[19] = 1.0;
   out_4718726566615345673[20] = 0.0;
   out_4718726566615345673[21] = 0.0;
   out_4718726566615345673[22] = 0.0;
   out_4718726566615345673[23] = 0.0;
   out_4718726566615345673[24] = 0.0;
   out_4718726566615345673[25] = 0.0;
   out_4718726566615345673[26] = 0.0;
   out_4718726566615345673[27] = 0.0;
   out_4718726566615345673[28] = 0.0;
   out_4718726566615345673[29] = 0.0;
   out_4718726566615345673[30] = 0.0;
   out_4718726566615345673[31] = 0.0;
   out_4718726566615345673[32] = 0.0;
   out_4718726566615345673[33] = 0.0;
   out_4718726566615345673[34] = 0.0;
   out_4718726566615345673[35] = 0.0;
   out_4718726566615345673[36] = 0.0;
   out_4718726566615345673[37] = 0.0;
   out_4718726566615345673[38] = 1.0;
   out_4718726566615345673[39] = 0.0;
   out_4718726566615345673[40] = 0.0;
   out_4718726566615345673[41] = 0.0;
   out_4718726566615345673[42] = 0.0;
   out_4718726566615345673[43] = 0.0;
   out_4718726566615345673[44] = 0.0;
   out_4718726566615345673[45] = 0.0;
   out_4718726566615345673[46] = 0.0;
   out_4718726566615345673[47] = 0.0;
   out_4718726566615345673[48] = 0.0;
   out_4718726566615345673[49] = 0.0;
   out_4718726566615345673[50] = 0.0;
   out_4718726566615345673[51] = 0.0;
   out_4718726566615345673[52] = 0.0;
   out_4718726566615345673[53] = 0.0;
   out_4718726566615345673[54] = 0.0;
   out_4718726566615345673[55] = 0.0;
   out_4718726566615345673[56] = 0.0;
   out_4718726566615345673[57] = 1.0;
   out_4718726566615345673[58] = 0.0;
   out_4718726566615345673[59] = 0.0;
   out_4718726566615345673[60] = 0.0;
   out_4718726566615345673[61] = 0.0;
   out_4718726566615345673[62] = 0.0;
   out_4718726566615345673[63] = 0.0;
   out_4718726566615345673[64] = 0.0;
   out_4718726566615345673[65] = 0.0;
   out_4718726566615345673[66] = 0.0;
   out_4718726566615345673[67] = 0.0;
   out_4718726566615345673[68] = 0.0;
   out_4718726566615345673[69] = 0.0;
   out_4718726566615345673[70] = 0.0;
   out_4718726566615345673[71] = 0.0;
   out_4718726566615345673[72] = 0.0;
   out_4718726566615345673[73] = 0.0;
   out_4718726566615345673[74] = 0.0;
   out_4718726566615345673[75] = 0.0;
   out_4718726566615345673[76] = 1.0;
   out_4718726566615345673[77] = 0.0;
   out_4718726566615345673[78] = 0.0;
   out_4718726566615345673[79] = 0.0;
   out_4718726566615345673[80] = 0.0;
   out_4718726566615345673[81] = 0.0;
   out_4718726566615345673[82] = 0.0;
   out_4718726566615345673[83] = 0.0;
   out_4718726566615345673[84] = 0.0;
   out_4718726566615345673[85] = 0.0;
   out_4718726566615345673[86] = 0.0;
   out_4718726566615345673[87] = 0.0;
   out_4718726566615345673[88] = 0.0;
   out_4718726566615345673[89] = 0.0;
   out_4718726566615345673[90] = 0.0;
   out_4718726566615345673[91] = 0.0;
   out_4718726566615345673[92] = 0.0;
   out_4718726566615345673[93] = 0.0;
   out_4718726566615345673[94] = 0.0;
   out_4718726566615345673[95] = 1.0;
   out_4718726566615345673[96] = 0.0;
   out_4718726566615345673[97] = 0.0;
   out_4718726566615345673[98] = 0.0;
   out_4718726566615345673[99] = 0.0;
   out_4718726566615345673[100] = 0.0;
   out_4718726566615345673[101] = 0.0;
   out_4718726566615345673[102] = 0.0;
   out_4718726566615345673[103] = 0.0;
   out_4718726566615345673[104] = 0.0;
   out_4718726566615345673[105] = 0.0;
   out_4718726566615345673[106] = 0.0;
   out_4718726566615345673[107] = 0.0;
   out_4718726566615345673[108] = 0.0;
   out_4718726566615345673[109] = 0.0;
   out_4718726566615345673[110] = 0.0;
   out_4718726566615345673[111] = 0.0;
   out_4718726566615345673[112] = 0.0;
   out_4718726566615345673[113] = 0.0;
   out_4718726566615345673[114] = 1.0;
   out_4718726566615345673[115] = 0.0;
   out_4718726566615345673[116] = 0.0;
   out_4718726566615345673[117] = 0.0;
   out_4718726566615345673[118] = 0.0;
   out_4718726566615345673[119] = 0.0;
   out_4718726566615345673[120] = 0.0;
   out_4718726566615345673[121] = 0.0;
   out_4718726566615345673[122] = 0.0;
   out_4718726566615345673[123] = 0.0;
   out_4718726566615345673[124] = 0.0;
   out_4718726566615345673[125] = 0.0;
   out_4718726566615345673[126] = 0.0;
   out_4718726566615345673[127] = 0.0;
   out_4718726566615345673[128] = 0.0;
   out_4718726566615345673[129] = 0.0;
   out_4718726566615345673[130] = 0.0;
   out_4718726566615345673[131] = 0.0;
   out_4718726566615345673[132] = 0.0;
   out_4718726566615345673[133] = 1.0;
   out_4718726566615345673[134] = 0.0;
   out_4718726566615345673[135] = 0.0;
   out_4718726566615345673[136] = 0.0;
   out_4718726566615345673[137] = 0.0;
   out_4718726566615345673[138] = 0.0;
   out_4718726566615345673[139] = 0.0;
   out_4718726566615345673[140] = 0.0;
   out_4718726566615345673[141] = 0.0;
   out_4718726566615345673[142] = 0.0;
   out_4718726566615345673[143] = 0.0;
   out_4718726566615345673[144] = 0.0;
   out_4718726566615345673[145] = 0.0;
   out_4718726566615345673[146] = 0.0;
   out_4718726566615345673[147] = 0.0;
   out_4718726566615345673[148] = 0.0;
   out_4718726566615345673[149] = 0.0;
   out_4718726566615345673[150] = 0.0;
   out_4718726566615345673[151] = 0.0;
   out_4718726566615345673[152] = 1.0;
   out_4718726566615345673[153] = 0.0;
   out_4718726566615345673[154] = 0.0;
   out_4718726566615345673[155] = 0.0;
   out_4718726566615345673[156] = 0.0;
   out_4718726566615345673[157] = 0.0;
   out_4718726566615345673[158] = 0.0;
   out_4718726566615345673[159] = 0.0;
   out_4718726566615345673[160] = 0.0;
   out_4718726566615345673[161] = 0.0;
   out_4718726566615345673[162] = 0.0;
   out_4718726566615345673[163] = 0.0;
   out_4718726566615345673[164] = 0.0;
   out_4718726566615345673[165] = 0.0;
   out_4718726566615345673[166] = 0.0;
   out_4718726566615345673[167] = 0.0;
   out_4718726566615345673[168] = 0.0;
   out_4718726566615345673[169] = 0.0;
   out_4718726566615345673[170] = 0.0;
   out_4718726566615345673[171] = 1.0;
   out_4718726566615345673[172] = 0.0;
   out_4718726566615345673[173] = 0.0;
   out_4718726566615345673[174] = 0.0;
   out_4718726566615345673[175] = 0.0;
   out_4718726566615345673[176] = 0.0;
   out_4718726566615345673[177] = 0.0;
   out_4718726566615345673[178] = 0.0;
   out_4718726566615345673[179] = 0.0;
   out_4718726566615345673[180] = 0.0;
   out_4718726566615345673[181] = 0.0;
   out_4718726566615345673[182] = 0.0;
   out_4718726566615345673[183] = 0.0;
   out_4718726566615345673[184] = 0.0;
   out_4718726566615345673[185] = 0.0;
   out_4718726566615345673[186] = 0.0;
   out_4718726566615345673[187] = 0.0;
   out_4718726566615345673[188] = 0.0;
   out_4718726566615345673[189] = 0.0;
   out_4718726566615345673[190] = 1.0;
   out_4718726566615345673[191] = 0.0;
   out_4718726566615345673[192] = 0.0;
   out_4718726566615345673[193] = 0.0;
   out_4718726566615345673[194] = 0.0;
   out_4718726566615345673[195] = 0.0;
   out_4718726566615345673[196] = 0.0;
   out_4718726566615345673[197] = 0.0;
   out_4718726566615345673[198] = 0.0;
   out_4718726566615345673[199] = 0.0;
   out_4718726566615345673[200] = 0.0;
   out_4718726566615345673[201] = 0.0;
   out_4718726566615345673[202] = 0.0;
   out_4718726566615345673[203] = 0.0;
   out_4718726566615345673[204] = 0.0;
   out_4718726566615345673[205] = 0.0;
   out_4718726566615345673[206] = 0.0;
   out_4718726566615345673[207] = 0.0;
   out_4718726566615345673[208] = 0.0;
   out_4718726566615345673[209] = 1.0;
   out_4718726566615345673[210] = 0.0;
   out_4718726566615345673[211] = 0.0;
   out_4718726566615345673[212] = 0.0;
   out_4718726566615345673[213] = 0.0;
   out_4718726566615345673[214] = 0.0;
   out_4718726566615345673[215] = 0.0;
   out_4718726566615345673[216] = 0.0;
   out_4718726566615345673[217] = 0.0;
   out_4718726566615345673[218] = 0.0;
   out_4718726566615345673[219] = 0.0;
   out_4718726566615345673[220] = 0.0;
   out_4718726566615345673[221] = 0.0;
   out_4718726566615345673[222] = 0.0;
   out_4718726566615345673[223] = 0.0;
   out_4718726566615345673[224] = 0.0;
   out_4718726566615345673[225] = 0.0;
   out_4718726566615345673[226] = 0.0;
   out_4718726566615345673[227] = 0.0;
   out_4718726566615345673[228] = 1.0;
   out_4718726566615345673[229] = 0.0;
   out_4718726566615345673[230] = 0.0;
   out_4718726566615345673[231] = 0.0;
   out_4718726566615345673[232] = 0.0;
   out_4718726566615345673[233] = 0.0;
   out_4718726566615345673[234] = 0.0;
   out_4718726566615345673[235] = 0.0;
   out_4718726566615345673[236] = 0.0;
   out_4718726566615345673[237] = 0.0;
   out_4718726566615345673[238] = 0.0;
   out_4718726566615345673[239] = 0.0;
   out_4718726566615345673[240] = 0.0;
   out_4718726566615345673[241] = 0.0;
   out_4718726566615345673[242] = 0.0;
   out_4718726566615345673[243] = 0.0;
   out_4718726566615345673[244] = 0.0;
   out_4718726566615345673[245] = 0.0;
   out_4718726566615345673[246] = 0.0;
   out_4718726566615345673[247] = 1.0;
   out_4718726566615345673[248] = 0.0;
   out_4718726566615345673[249] = 0.0;
   out_4718726566615345673[250] = 0.0;
   out_4718726566615345673[251] = 0.0;
   out_4718726566615345673[252] = 0.0;
   out_4718726566615345673[253] = 0.0;
   out_4718726566615345673[254] = 0.0;
   out_4718726566615345673[255] = 0.0;
   out_4718726566615345673[256] = 0.0;
   out_4718726566615345673[257] = 0.0;
   out_4718726566615345673[258] = 0.0;
   out_4718726566615345673[259] = 0.0;
   out_4718726566615345673[260] = 0.0;
   out_4718726566615345673[261] = 0.0;
   out_4718726566615345673[262] = 0.0;
   out_4718726566615345673[263] = 0.0;
   out_4718726566615345673[264] = 0.0;
   out_4718726566615345673[265] = 0.0;
   out_4718726566615345673[266] = 1.0;
   out_4718726566615345673[267] = 0.0;
   out_4718726566615345673[268] = 0.0;
   out_4718726566615345673[269] = 0.0;
   out_4718726566615345673[270] = 0.0;
   out_4718726566615345673[271] = 0.0;
   out_4718726566615345673[272] = 0.0;
   out_4718726566615345673[273] = 0.0;
   out_4718726566615345673[274] = 0.0;
   out_4718726566615345673[275] = 0.0;
   out_4718726566615345673[276] = 0.0;
   out_4718726566615345673[277] = 0.0;
   out_4718726566615345673[278] = 0.0;
   out_4718726566615345673[279] = 0.0;
   out_4718726566615345673[280] = 0.0;
   out_4718726566615345673[281] = 0.0;
   out_4718726566615345673[282] = 0.0;
   out_4718726566615345673[283] = 0.0;
   out_4718726566615345673[284] = 0.0;
   out_4718726566615345673[285] = 1.0;
   out_4718726566615345673[286] = 0.0;
   out_4718726566615345673[287] = 0.0;
   out_4718726566615345673[288] = 0.0;
   out_4718726566615345673[289] = 0.0;
   out_4718726566615345673[290] = 0.0;
   out_4718726566615345673[291] = 0.0;
   out_4718726566615345673[292] = 0.0;
   out_4718726566615345673[293] = 0.0;
   out_4718726566615345673[294] = 0.0;
   out_4718726566615345673[295] = 0.0;
   out_4718726566615345673[296] = 0.0;
   out_4718726566615345673[297] = 0.0;
   out_4718726566615345673[298] = 0.0;
   out_4718726566615345673[299] = 0.0;
   out_4718726566615345673[300] = 0.0;
   out_4718726566615345673[301] = 0.0;
   out_4718726566615345673[302] = 0.0;
   out_4718726566615345673[303] = 0.0;
   out_4718726566615345673[304] = 1.0;
   out_4718726566615345673[305] = 0.0;
   out_4718726566615345673[306] = 0.0;
   out_4718726566615345673[307] = 0.0;
   out_4718726566615345673[308] = 0.0;
   out_4718726566615345673[309] = 0.0;
   out_4718726566615345673[310] = 0.0;
   out_4718726566615345673[311] = 0.0;
   out_4718726566615345673[312] = 0.0;
   out_4718726566615345673[313] = 0.0;
   out_4718726566615345673[314] = 0.0;
   out_4718726566615345673[315] = 0.0;
   out_4718726566615345673[316] = 0.0;
   out_4718726566615345673[317] = 0.0;
   out_4718726566615345673[318] = 0.0;
   out_4718726566615345673[319] = 0.0;
   out_4718726566615345673[320] = 0.0;
   out_4718726566615345673[321] = 0.0;
   out_4718726566615345673[322] = 0.0;
   out_4718726566615345673[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2093259032196707743) {
   out_2093259032196707743[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2093259032196707743[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2093259032196707743[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2093259032196707743[3] = dt*state[12] + state[3];
   out_2093259032196707743[4] = dt*state[13] + state[4];
   out_2093259032196707743[5] = dt*state[14] + state[5];
   out_2093259032196707743[6] = state[6];
   out_2093259032196707743[7] = state[7];
   out_2093259032196707743[8] = state[8];
   out_2093259032196707743[9] = state[9];
   out_2093259032196707743[10] = state[10];
   out_2093259032196707743[11] = state[11];
   out_2093259032196707743[12] = state[12];
   out_2093259032196707743[13] = state[13];
   out_2093259032196707743[14] = state[14];
   out_2093259032196707743[15] = state[15];
   out_2093259032196707743[16] = state[16];
   out_2093259032196707743[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7597852127146355968) {
   out_7597852127146355968[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7597852127146355968[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7597852127146355968[2] = 0;
   out_7597852127146355968[3] = 0;
   out_7597852127146355968[4] = 0;
   out_7597852127146355968[5] = 0;
   out_7597852127146355968[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7597852127146355968[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7597852127146355968[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7597852127146355968[9] = 0;
   out_7597852127146355968[10] = 0;
   out_7597852127146355968[11] = 0;
   out_7597852127146355968[12] = 0;
   out_7597852127146355968[13] = 0;
   out_7597852127146355968[14] = 0;
   out_7597852127146355968[15] = 0;
   out_7597852127146355968[16] = 0;
   out_7597852127146355968[17] = 0;
   out_7597852127146355968[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7597852127146355968[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7597852127146355968[20] = 0;
   out_7597852127146355968[21] = 0;
   out_7597852127146355968[22] = 0;
   out_7597852127146355968[23] = 0;
   out_7597852127146355968[24] = 0;
   out_7597852127146355968[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7597852127146355968[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7597852127146355968[27] = 0;
   out_7597852127146355968[28] = 0;
   out_7597852127146355968[29] = 0;
   out_7597852127146355968[30] = 0;
   out_7597852127146355968[31] = 0;
   out_7597852127146355968[32] = 0;
   out_7597852127146355968[33] = 0;
   out_7597852127146355968[34] = 0;
   out_7597852127146355968[35] = 0;
   out_7597852127146355968[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7597852127146355968[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7597852127146355968[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7597852127146355968[39] = 0;
   out_7597852127146355968[40] = 0;
   out_7597852127146355968[41] = 0;
   out_7597852127146355968[42] = 0;
   out_7597852127146355968[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7597852127146355968[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7597852127146355968[45] = 0;
   out_7597852127146355968[46] = 0;
   out_7597852127146355968[47] = 0;
   out_7597852127146355968[48] = 0;
   out_7597852127146355968[49] = 0;
   out_7597852127146355968[50] = 0;
   out_7597852127146355968[51] = 0;
   out_7597852127146355968[52] = 0;
   out_7597852127146355968[53] = 0;
   out_7597852127146355968[54] = 0;
   out_7597852127146355968[55] = 0;
   out_7597852127146355968[56] = 0;
   out_7597852127146355968[57] = 1;
   out_7597852127146355968[58] = 0;
   out_7597852127146355968[59] = 0;
   out_7597852127146355968[60] = 0;
   out_7597852127146355968[61] = 0;
   out_7597852127146355968[62] = 0;
   out_7597852127146355968[63] = 0;
   out_7597852127146355968[64] = 0;
   out_7597852127146355968[65] = 0;
   out_7597852127146355968[66] = dt;
   out_7597852127146355968[67] = 0;
   out_7597852127146355968[68] = 0;
   out_7597852127146355968[69] = 0;
   out_7597852127146355968[70] = 0;
   out_7597852127146355968[71] = 0;
   out_7597852127146355968[72] = 0;
   out_7597852127146355968[73] = 0;
   out_7597852127146355968[74] = 0;
   out_7597852127146355968[75] = 0;
   out_7597852127146355968[76] = 1;
   out_7597852127146355968[77] = 0;
   out_7597852127146355968[78] = 0;
   out_7597852127146355968[79] = 0;
   out_7597852127146355968[80] = 0;
   out_7597852127146355968[81] = 0;
   out_7597852127146355968[82] = 0;
   out_7597852127146355968[83] = 0;
   out_7597852127146355968[84] = 0;
   out_7597852127146355968[85] = dt;
   out_7597852127146355968[86] = 0;
   out_7597852127146355968[87] = 0;
   out_7597852127146355968[88] = 0;
   out_7597852127146355968[89] = 0;
   out_7597852127146355968[90] = 0;
   out_7597852127146355968[91] = 0;
   out_7597852127146355968[92] = 0;
   out_7597852127146355968[93] = 0;
   out_7597852127146355968[94] = 0;
   out_7597852127146355968[95] = 1;
   out_7597852127146355968[96] = 0;
   out_7597852127146355968[97] = 0;
   out_7597852127146355968[98] = 0;
   out_7597852127146355968[99] = 0;
   out_7597852127146355968[100] = 0;
   out_7597852127146355968[101] = 0;
   out_7597852127146355968[102] = 0;
   out_7597852127146355968[103] = 0;
   out_7597852127146355968[104] = dt;
   out_7597852127146355968[105] = 0;
   out_7597852127146355968[106] = 0;
   out_7597852127146355968[107] = 0;
   out_7597852127146355968[108] = 0;
   out_7597852127146355968[109] = 0;
   out_7597852127146355968[110] = 0;
   out_7597852127146355968[111] = 0;
   out_7597852127146355968[112] = 0;
   out_7597852127146355968[113] = 0;
   out_7597852127146355968[114] = 1;
   out_7597852127146355968[115] = 0;
   out_7597852127146355968[116] = 0;
   out_7597852127146355968[117] = 0;
   out_7597852127146355968[118] = 0;
   out_7597852127146355968[119] = 0;
   out_7597852127146355968[120] = 0;
   out_7597852127146355968[121] = 0;
   out_7597852127146355968[122] = 0;
   out_7597852127146355968[123] = 0;
   out_7597852127146355968[124] = 0;
   out_7597852127146355968[125] = 0;
   out_7597852127146355968[126] = 0;
   out_7597852127146355968[127] = 0;
   out_7597852127146355968[128] = 0;
   out_7597852127146355968[129] = 0;
   out_7597852127146355968[130] = 0;
   out_7597852127146355968[131] = 0;
   out_7597852127146355968[132] = 0;
   out_7597852127146355968[133] = 1;
   out_7597852127146355968[134] = 0;
   out_7597852127146355968[135] = 0;
   out_7597852127146355968[136] = 0;
   out_7597852127146355968[137] = 0;
   out_7597852127146355968[138] = 0;
   out_7597852127146355968[139] = 0;
   out_7597852127146355968[140] = 0;
   out_7597852127146355968[141] = 0;
   out_7597852127146355968[142] = 0;
   out_7597852127146355968[143] = 0;
   out_7597852127146355968[144] = 0;
   out_7597852127146355968[145] = 0;
   out_7597852127146355968[146] = 0;
   out_7597852127146355968[147] = 0;
   out_7597852127146355968[148] = 0;
   out_7597852127146355968[149] = 0;
   out_7597852127146355968[150] = 0;
   out_7597852127146355968[151] = 0;
   out_7597852127146355968[152] = 1;
   out_7597852127146355968[153] = 0;
   out_7597852127146355968[154] = 0;
   out_7597852127146355968[155] = 0;
   out_7597852127146355968[156] = 0;
   out_7597852127146355968[157] = 0;
   out_7597852127146355968[158] = 0;
   out_7597852127146355968[159] = 0;
   out_7597852127146355968[160] = 0;
   out_7597852127146355968[161] = 0;
   out_7597852127146355968[162] = 0;
   out_7597852127146355968[163] = 0;
   out_7597852127146355968[164] = 0;
   out_7597852127146355968[165] = 0;
   out_7597852127146355968[166] = 0;
   out_7597852127146355968[167] = 0;
   out_7597852127146355968[168] = 0;
   out_7597852127146355968[169] = 0;
   out_7597852127146355968[170] = 0;
   out_7597852127146355968[171] = 1;
   out_7597852127146355968[172] = 0;
   out_7597852127146355968[173] = 0;
   out_7597852127146355968[174] = 0;
   out_7597852127146355968[175] = 0;
   out_7597852127146355968[176] = 0;
   out_7597852127146355968[177] = 0;
   out_7597852127146355968[178] = 0;
   out_7597852127146355968[179] = 0;
   out_7597852127146355968[180] = 0;
   out_7597852127146355968[181] = 0;
   out_7597852127146355968[182] = 0;
   out_7597852127146355968[183] = 0;
   out_7597852127146355968[184] = 0;
   out_7597852127146355968[185] = 0;
   out_7597852127146355968[186] = 0;
   out_7597852127146355968[187] = 0;
   out_7597852127146355968[188] = 0;
   out_7597852127146355968[189] = 0;
   out_7597852127146355968[190] = 1;
   out_7597852127146355968[191] = 0;
   out_7597852127146355968[192] = 0;
   out_7597852127146355968[193] = 0;
   out_7597852127146355968[194] = 0;
   out_7597852127146355968[195] = 0;
   out_7597852127146355968[196] = 0;
   out_7597852127146355968[197] = 0;
   out_7597852127146355968[198] = 0;
   out_7597852127146355968[199] = 0;
   out_7597852127146355968[200] = 0;
   out_7597852127146355968[201] = 0;
   out_7597852127146355968[202] = 0;
   out_7597852127146355968[203] = 0;
   out_7597852127146355968[204] = 0;
   out_7597852127146355968[205] = 0;
   out_7597852127146355968[206] = 0;
   out_7597852127146355968[207] = 0;
   out_7597852127146355968[208] = 0;
   out_7597852127146355968[209] = 1;
   out_7597852127146355968[210] = 0;
   out_7597852127146355968[211] = 0;
   out_7597852127146355968[212] = 0;
   out_7597852127146355968[213] = 0;
   out_7597852127146355968[214] = 0;
   out_7597852127146355968[215] = 0;
   out_7597852127146355968[216] = 0;
   out_7597852127146355968[217] = 0;
   out_7597852127146355968[218] = 0;
   out_7597852127146355968[219] = 0;
   out_7597852127146355968[220] = 0;
   out_7597852127146355968[221] = 0;
   out_7597852127146355968[222] = 0;
   out_7597852127146355968[223] = 0;
   out_7597852127146355968[224] = 0;
   out_7597852127146355968[225] = 0;
   out_7597852127146355968[226] = 0;
   out_7597852127146355968[227] = 0;
   out_7597852127146355968[228] = 1;
   out_7597852127146355968[229] = 0;
   out_7597852127146355968[230] = 0;
   out_7597852127146355968[231] = 0;
   out_7597852127146355968[232] = 0;
   out_7597852127146355968[233] = 0;
   out_7597852127146355968[234] = 0;
   out_7597852127146355968[235] = 0;
   out_7597852127146355968[236] = 0;
   out_7597852127146355968[237] = 0;
   out_7597852127146355968[238] = 0;
   out_7597852127146355968[239] = 0;
   out_7597852127146355968[240] = 0;
   out_7597852127146355968[241] = 0;
   out_7597852127146355968[242] = 0;
   out_7597852127146355968[243] = 0;
   out_7597852127146355968[244] = 0;
   out_7597852127146355968[245] = 0;
   out_7597852127146355968[246] = 0;
   out_7597852127146355968[247] = 1;
   out_7597852127146355968[248] = 0;
   out_7597852127146355968[249] = 0;
   out_7597852127146355968[250] = 0;
   out_7597852127146355968[251] = 0;
   out_7597852127146355968[252] = 0;
   out_7597852127146355968[253] = 0;
   out_7597852127146355968[254] = 0;
   out_7597852127146355968[255] = 0;
   out_7597852127146355968[256] = 0;
   out_7597852127146355968[257] = 0;
   out_7597852127146355968[258] = 0;
   out_7597852127146355968[259] = 0;
   out_7597852127146355968[260] = 0;
   out_7597852127146355968[261] = 0;
   out_7597852127146355968[262] = 0;
   out_7597852127146355968[263] = 0;
   out_7597852127146355968[264] = 0;
   out_7597852127146355968[265] = 0;
   out_7597852127146355968[266] = 1;
   out_7597852127146355968[267] = 0;
   out_7597852127146355968[268] = 0;
   out_7597852127146355968[269] = 0;
   out_7597852127146355968[270] = 0;
   out_7597852127146355968[271] = 0;
   out_7597852127146355968[272] = 0;
   out_7597852127146355968[273] = 0;
   out_7597852127146355968[274] = 0;
   out_7597852127146355968[275] = 0;
   out_7597852127146355968[276] = 0;
   out_7597852127146355968[277] = 0;
   out_7597852127146355968[278] = 0;
   out_7597852127146355968[279] = 0;
   out_7597852127146355968[280] = 0;
   out_7597852127146355968[281] = 0;
   out_7597852127146355968[282] = 0;
   out_7597852127146355968[283] = 0;
   out_7597852127146355968[284] = 0;
   out_7597852127146355968[285] = 1;
   out_7597852127146355968[286] = 0;
   out_7597852127146355968[287] = 0;
   out_7597852127146355968[288] = 0;
   out_7597852127146355968[289] = 0;
   out_7597852127146355968[290] = 0;
   out_7597852127146355968[291] = 0;
   out_7597852127146355968[292] = 0;
   out_7597852127146355968[293] = 0;
   out_7597852127146355968[294] = 0;
   out_7597852127146355968[295] = 0;
   out_7597852127146355968[296] = 0;
   out_7597852127146355968[297] = 0;
   out_7597852127146355968[298] = 0;
   out_7597852127146355968[299] = 0;
   out_7597852127146355968[300] = 0;
   out_7597852127146355968[301] = 0;
   out_7597852127146355968[302] = 0;
   out_7597852127146355968[303] = 0;
   out_7597852127146355968[304] = 1;
   out_7597852127146355968[305] = 0;
   out_7597852127146355968[306] = 0;
   out_7597852127146355968[307] = 0;
   out_7597852127146355968[308] = 0;
   out_7597852127146355968[309] = 0;
   out_7597852127146355968[310] = 0;
   out_7597852127146355968[311] = 0;
   out_7597852127146355968[312] = 0;
   out_7597852127146355968[313] = 0;
   out_7597852127146355968[314] = 0;
   out_7597852127146355968[315] = 0;
   out_7597852127146355968[316] = 0;
   out_7597852127146355968[317] = 0;
   out_7597852127146355968[318] = 0;
   out_7597852127146355968[319] = 0;
   out_7597852127146355968[320] = 0;
   out_7597852127146355968[321] = 0;
   out_7597852127146355968[322] = 0;
   out_7597852127146355968[323] = 1;
}
void h_4(double *state, double *unused, double *out_89080864518885864) {
   out_89080864518885864[0] = state[6] + state[9];
   out_89080864518885864[1] = state[7] + state[10];
   out_89080864518885864[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_946919356771438101) {
   out_946919356771438101[0] = 0;
   out_946919356771438101[1] = 0;
   out_946919356771438101[2] = 0;
   out_946919356771438101[3] = 0;
   out_946919356771438101[4] = 0;
   out_946919356771438101[5] = 0;
   out_946919356771438101[6] = 1;
   out_946919356771438101[7] = 0;
   out_946919356771438101[8] = 0;
   out_946919356771438101[9] = 1;
   out_946919356771438101[10] = 0;
   out_946919356771438101[11] = 0;
   out_946919356771438101[12] = 0;
   out_946919356771438101[13] = 0;
   out_946919356771438101[14] = 0;
   out_946919356771438101[15] = 0;
   out_946919356771438101[16] = 0;
   out_946919356771438101[17] = 0;
   out_946919356771438101[18] = 0;
   out_946919356771438101[19] = 0;
   out_946919356771438101[20] = 0;
   out_946919356771438101[21] = 0;
   out_946919356771438101[22] = 0;
   out_946919356771438101[23] = 0;
   out_946919356771438101[24] = 0;
   out_946919356771438101[25] = 1;
   out_946919356771438101[26] = 0;
   out_946919356771438101[27] = 0;
   out_946919356771438101[28] = 1;
   out_946919356771438101[29] = 0;
   out_946919356771438101[30] = 0;
   out_946919356771438101[31] = 0;
   out_946919356771438101[32] = 0;
   out_946919356771438101[33] = 0;
   out_946919356771438101[34] = 0;
   out_946919356771438101[35] = 0;
   out_946919356771438101[36] = 0;
   out_946919356771438101[37] = 0;
   out_946919356771438101[38] = 0;
   out_946919356771438101[39] = 0;
   out_946919356771438101[40] = 0;
   out_946919356771438101[41] = 0;
   out_946919356771438101[42] = 0;
   out_946919356771438101[43] = 0;
   out_946919356771438101[44] = 1;
   out_946919356771438101[45] = 0;
   out_946919356771438101[46] = 0;
   out_946919356771438101[47] = 1;
   out_946919356771438101[48] = 0;
   out_946919356771438101[49] = 0;
   out_946919356771438101[50] = 0;
   out_946919356771438101[51] = 0;
   out_946919356771438101[52] = 0;
   out_946919356771438101[53] = 0;
}
void h_10(double *state, double *unused, double *out_2699740651616676276) {
   out_2699740651616676276[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2699740651616676276[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2699740651616676276[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8679455089612648559) {
   out_8679455089612648559[0] = 0;
   out_8679455089612648559[1] = 9.8100000000000005*cos(state[1]);
   out_8679455089612648559[2] = 0;
   out_8679455089612648559[3] = 0;
   out_8679455089612648559[4] = -state[8];
   out_8679455089612648559[5] = state[7];
   out_8679455089612648559[6] = 0;
   out_8679455089612648559[7] = state[5];
   out_8679455089612648559[8] = -state[4];
   out_8679455089612648559[9] = 0;
   out_8679455089612648559[10] = 0;
   out_8679455089612648559[11] = 0;
   out_8679455089612648559[12] = 1;
   out_8679455089612648559[13] = 0;
   out_8679455089612648559[14] = 0;
   out_8679455089612648559[15] = 1;
   out_8679455089612648559[16] = 0;
   out_8679455089612648559[17] = 0;
   out_8679455089612648559[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8679455089612648559[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8679455089612648559[20] = 0;
   out_8679455089612648559[21] = state[8];
   out_8679455089612648559[22] = 0;
   out_8679455089612648559[23] = -state[6];
   out_8679455089612648559[24] = -state[5];
   out_8679455089612648559[25] = 0;
   out_8679455089612648559[26] = state[3];
   out_8679455089612648559[27] = 0;
   out_8679455089612648559[28] = 0;
   out_8679455089612648559[29] = 0;
   out_8679455089612648559[30] = 0;
   out_8679455089612648559[31] = 1;
   out_8679455089612648559[32] = 0;
   out_8679455089612648559[33] = 0;
   out_8679455089612648559[34] = 1;
   out_8679455089612648559[35] = 0;
   out_8679455089612648559[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8679455089612648559[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8679455089612648559[38] = 0;
   out_8679455089612648559[39] = -state[7];
   out_8679455089612648559[40] = state[6];
   out_8679455089612648559[41] = 0;
   out_8679455089612648559[42] = state[4];
   out_8679455089612648559[43] = -state[3];
   out_8679455089612648559[44] = 0;
   out_8679455089612648559[45] = 0;
   out_8679455089612648559[46] = 0;
   out_8679455089612648559[47] = 0;
   out_8679455089612648559[48] = 0;
   out_8679455089612648559[49] = 0;
   out_8679455089612648559[50] = 1;
   out_8679455089612648559[51] = 0;
   out_8679455089612648559[52] = 0;
   out_8679455089612648559[53] = 1;
}
void h_13(double *state, double *unused, double *out_622335723485041042) {
   out_622335723485041042[0] = state[3];
   out_622335723485041042[1] = state[4];
   out_622335723485041042[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2265354468560894700) {
   out_2265354468560894700[0] = 0;
   out_2265354468560894700[1] = 0;
   out_2265354468560894700[2] = 0;
   out_2265354468560894700[3] = 1;
   out_2265354468560894700[4] = 0;
   out_2265354468560894700[5] = 0;
   out_2265354468560894700[6] = 0;
   out_2265354468560894700[7] = 0;
   out_2265354468560894700[8] = 0;
   out_2265354468560894700[9] = 0;
   out_2265354468560894700[10] = 0;
   out_2265354468560894700[11] = 0;
   out_2265354468560894700[12] = 0;
   out_2265354468560894700[13] = 0;
   out_2265354468560894700[14] = 0;
   out_2265354468560894700[15] = 0;
   out_2265354468560894700[16] = 0;
   out_2265354468560894700[17] = 0;
   out_2265354468560894700[18] = 0;
   out_2265354468560894700[19] = 0;
   out_2265354468560894700[20] = 0;
   out_2265354468560894700[21] = 0;
   out_2265354468560894700[22] = 1;
   out_2265354468560894700[23] = 0;
   out_2265354468560894700[24] = 0;
   out_2265354468560894700[25] = 0;
   out_2265354468560894700[26] = 0;
   out_2265354468560894700[27] = 0;
   out_2265354468560894700[28] = 0;
   out_2265354468560894700[29] = 0;
   out_2265354468560894700[30] = 0;
   out_2265354468560894700[31] = 0;
   out_2265354468560894700[32] = 0;
   out_2265354468560894700[33] = 0;
   out_2265354468560894700[34] = 0;
   out_2265354468560894700[35] = 0;
   out_2265354468560894700[36] = 0;
   out_2265354468560894700[37] = 0;
   out_2265354468560894700[38] = 0;
   out_2265354468560894700[39] = 0;
   out_2265354468560894700[40] = 0;
   out_2265354468560894700[41] = 1;
   out_2265354468560894700[42] = 0;
   out_2265354468560894700[43] = 0;
   out_2265354468560894700[44] = 0;
   out_2265354468560894700[45] = 0;
   out_2265354468560894700[46] = 0;
   out_2265354468560894700[47] = 0;
   out_2265354468560894700[48] = 0;
   out_2265354468560894700[49] = 0;
   out_2265354468560894700[50] = 0;
   out_2265354468560894700[51] = 0;
   out_2265354468560894700[52] = 0;
   out_2265354468560894700[53] = 0;
}
void h_14(double *state, double *unused, double *out_299516174209740344) {
   out_299516174209740344[0] = state[6];
   out_299516174209740344[1] = state[7];
   out_299516174209740344[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3016321499568046428) {
   out_3016321499568046428[0] = 0;
   out_3016321499568046428[1] = 0;
   out_3016321499568046428[2] = 0;
   out_3016321499568046428[3] = 0;
   out_3016321499568046428[4] = 0;
   out_3016321499568046428[5] = 0;
   out_3016321499568046428[6] = 1;
   out_3016321499568046428[7] = 0;
   out_3016321499568046428[8] = 0;
   out_3016321499568046428[9] = 0;
   out_3016321499568046428[10] = 0;
   out_3016321499568046428[11] = 0;
   out_3016321499568046428[12] = 0;
   out_3016321499568046428[13] = 0;
   out_3016321499568046428[14] = 0;
   out_3016321499568046428[15] = 0;
   out_3016321499568046428[16] = 0;
   out_3016321499568046428[17] = 0;
   out_3016321499568046428[18] = 0;
   out_3016321499568046428[19] = 0;
   out_3016321499568046428[20] = 0;
   out_3016321499568046428[21] = 0;
   out_3016321499568046428[22] = 0;
   out_3016321499568046428[23] = 0;
   out_3016321499568046428[24] = 0;
   out_3016321499568046428[25] = 1;
   out_3016321499568046428[26] = 0;
   out_3016321499568046428[27] = 0;
   out_3016321499568046428[28] = 0;
   out_3016321499568046428[29] = 0;
   out_3016321499568046428[30] = 0;
   out_3016321499568046428[31] = 0;
   out_3016321499568046428[32] = 0;
   out_3016321499568046428[33] = 0;
   out_3016321499568046428[34] = 0;
   out_3016321499568046428[35] = 0;
   out_3016321499568046428[36] = 0;
   out_3016321499568046428[37] = 0;
   out_3016321499568046428[38] = 0;
   out_3016321499568046428[39] = 0;
   out_3016321499568046428[40] = 0;
   out_3016321499568046428[41] = 0;
   out_3016321499568046428[42] = 0;
   out_3016321499568046428[43] = 0;
   out_3016321499568046428[44] = 1;
   out_3016321499568046428[45] = 0;
   out_3016321499568046428[46] = 0;
   out_3016321499568046428[47] = 0;
   out_3016321499568046428[48] = 0;
   out_3016321499568046428[49] = 0;
   out_3016321499568046428[50] = 0;
   out_3016321499568046428[51] = 0;
   out_3016321499568046428[52] = 0;
   out_3016321499568046428[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_4833077353004324467) {
  err_fun(nom_x, delta_x, out_4833077353004324467);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4980437301453189923) {
  inv_err_fun(nom_x, true_x, out_4980437301453189923);
}
void pose_H_mod_fun(double *state, double *out_4718726566615345673) {
  H_mod_fun(state, out_4718726566615345673);
}
void pose_f_fun(double *state, double dt, double *out_2093259032196707743) {
  f_fun(state,  dt, out_2093259032196707743);
}
void pose_F_fun(double *state, double dt, double *out_7597852127146355968) {
  F_fun(state,  dt, out_7597852127146355968);
}
void pose_h_4(double *state, double *unused, double *out_89080864518885864) {
  h_4(state, unused, out_89080864518885864);
}
void pose_H_4(double *state, double *unused, double *out_946919356771438101) {
  H_4(state, unused, out_946919356771438101);
}
void pose_h_10(double *state, double *unused, double *out_2699740651616676276) {
  h_10(state, unused, out_2699740651616676276);
}
void pose_H_10(double *state, double *unused, double *out_8679455089612648559) {
  H_10(state, unused, out_8679455089612648559);
}
void pose_h_13(double *state, double *unused, double *out_622335723485041042) {
  h_13(state, unused, out_622335723485041042);
}
void pose_H_13(double *state, double *unused, double *out_2265354468560894700) {
  H_13(state, unused, out_2265354468560894700);
}
void pose_h_14(double *state, double *unused, double *out_299516174209740344) {
  h_14(state, unused, out_299516174209740344);
}
void pose_H_14(double *state, double *unused, double *out_3016321499568046428) {
  H_14(state, unused, out_3016321499568046428);
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
