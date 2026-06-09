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
void err_fun(double *nom_x, double *delta_x, double *out_3892827861815398533) {
   out_3892827861815398533[0] = delta_x[0] + nom_x[0];
   out_3892827861815398533[1] = delta_x[1] + nom_x[1];
   out_3892827861815398533[2] = delta_x[2] + nom_x[2];
   out_3892827861815398533[3] = delta_x[3] + nom_x[3];
   out_3892827861815398533[4] = delta_x[4] + nom_x[4];
   out_3892827861815398533[5] = delta_x[5] + nom_x[5];
   out_3892827861815398533[6] = delta_x[6] + nom_x[6];
   out_3892827861815398533[7] = delta_x[7] + nom_x[7];
   out_3892827861815398533[8] = delta_x[8] + nom_x[8];
   out_3892827861815398533[9] = delta_x[9] + nom_x[9];
   out_3892827861815398533[10] = delta_x[10] + nom_x[10];
   out_3892827861815398533[11] = delta_x[11] + nom_x[11];
   out_3892827861815398533[12] = delta_x[12] + nom_x[12];
   out_3892827861815398533[13] = delta_x[13] + nom_x[13];
   out_3892827861815398533[14] = delta_x[14] + nom_x[14];
   out_3892827861815398533[15] = delta_x[15] + nom_x[15];
   out_3892827861815398533[16] = delta_x[16] + nom_x[16];
   out_3892827861815398533[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_341451131886162609) {
   out_341451131886162609[0] = -nom_x[0] + true_x[0];
   out_341451131886162609[1] = -nom_x[1] + true_x[1];
   out_341451131886162609[2] = -nom_x[2] + true_x[2];
   out_341451131886162609[3] = -nom_x[3] + true_x[3];
   out_341451131886162609[4] = -nom_x[4] + true_x[4];
   out_341451131886162609[5] = -nom_x[5] + true_x[5];
   out_341451131886162609[6] = -nom_x[6] + true_x[6];
   out_341451131886162609[7] = -nom_x[7] + true_x[7];
   out_341451131886162609[8] = -nom_x[8] + true_x[8];
   out_341451131886162609[9] = -nom_x[9] + true_x[9];
   out_341451131886162609[10] = -nom_x[10] + true_x[10];
   out_341451131886162609[11] = -nom_x[11] + true_x[11];
   out_341451131886162609[12] = -nom_x[12] + true_x[12];
   out_341451131886162609[13] = -nom_x[13] + true_x[13];
   out_341451131886162609[14] = -nom_x[14] + true_x[14];
   out_341451131886162609[15] = -nom_x[15] + true_x[15];
   out_341451131886162609[16] = -nom_x[16] + true_x[16];
   out_341451131886162609[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_328613363132085737) {
   out_328613363132085737[0] = 1.0;
   out_328613363132085737[1] = 0.0;
   out_328613363132085737[2] = 0.0;
   out_328613363132085737[3] = 0.0;
   out_328613363132085737[4] = 0.0;
   out_328613363132085737[5] = 0.0;
   out_328613363132085737[6] = 0.0;
   out_328613363132085737[7] = 0.0;
   out_328613363132085737[8] = 0.0;
   out_328613363132085737[9] = 0.0;
   out_328613363132085737[10] = 0.0;
   out_328613363132085737[11] = 0.0;
   out_328613363132085737[12] = 0.0;
   out_328613363132085737[13] = 0.0;
   out_328613363132085737[14] = 0.0;
   out_328613363132085737[15] = 0.0;
   out_328613363132085737[16] = 0.0;
   out_328613363132085737[17] = 0.0;
   out_328613363132085737[18] = 0.0;
   out_328613363132085737[19] = 1.0;
   out_328613363132085737[20] = 0.0;
   out_328613363132085737[21] = 0.0;
   out_328613363132085737[22] = 0.0;
   out_328613363132085737[23] = 0.0;
   out_328613363132085737[24] = 0.0;
   out_328613363132085737[25] = 0.0;
   out_328613363132085737[26] = 0.0;
   out_328613363132085737[27] = 0.0;
   out_328613363132085737[28] = 0.0;
   out_328613363132085737[29] = 0.0;
   out_328613363132085737[30] = 0.0;
   out_328613363132085737[31] = 0.0;
   out_328613363132085737[32] = 0.0;
   out_328613363132085737[33] = 0.0;
   out_328613363132085737[34] = 0.0;
   out_328613363132085737[35] = 0.0;
   out_328613363132085737[36] = 0.0;
   out_328613363132085737[37] = 0.0;
   out_328613363132085737[38] = 1.0;
   out_328613363132085737[39] = 0.0;
   out_328613363132085737[40] = 0.0;
   out_328613363132085737[41] = 0.0;
   out_328613363132085737[42] = 0.0;
   out_328613363132085737[43] = 0.0;
   out_328613363132085737[44] = 0.0;
   out_328613363132085737[45] = 0.0;
   out_328613363132085737[46] = 0.0;
   out_328613363132085737[47] = 0.0;
   out_328613363132085737[48] = 0.0;
   out_328613363132085737[49] = 0.0;
   out_328613363132085737[50] = 0.0;
   out_328613363132085737[51] = 0.0;
   out_328613363132085737[52] = 0.0;
   out_328613363132085737[53] = 0.0;
   out_328613363132085737[54] = 0.0;
   out_328613363132085737[55] = 0.0;
   out_328613363132085737[56] = 0.0;
   out_328613363132085737[57] = 1.0;
   out_328613363132085737[58] = 0.0;
   out_328613363132085737[59] = 0.0;
   out_328613363132085737[60] = 0.0;
   out_328613363132085737[61] = 0.0;
   out_328613363132085737[62] = 0.0;
   out_328613363132085737[63] = 0.0;
   out_328613363132085737[64] = 0.0;
   out_328613363132085737[65] = 0.0;
   out_328613363132085737[66] = 0.0;
   out_328613363132085737[67] = 0.0;
   out_328613363132085737[68] = 0.0;
   out_328613363132085737[69] = 0.0;
   out_328613363132085737[70] = 0.0;
   out_328613363132085737[71] = 0.0;
   out_328613363132085737[72] = 0.0;
   out_328613363132085737[73] = 0.0;
   out_328613363132085737[74] = 0.0;
   out_328613363132085737[75] = 0.0;
   out_328613363132085737[76] = 1.0;
   out_328613363132085737[77] = 0.0;
   out_328613363132085737[78] = 0.0;
   out_328613363132085737[79] = 0.0;
   out_328613363132085737[80] = 0.0;
   out_328613363132085737[81] = 0.0;
   out_328613363132085737[82] = 0.0;
   out_328613363132085737[83] = 0.0;
   out_328613363132085737[84] = 0.0;
   out_328613363132085737[85] = 0.0;
   out_328613363132085737[86] = 0.0;
   out_328613363132085737[87] = 0.0;
   out_328613363132085737[88] = 0.0;
   out_328613363132085737[89] = 0.0;
   out_328613363132085737[90] = 0.0;
   out_328613363132085737[91] = 0.0;
   out_328613363132085737[92] = 0.0;
   out_328613363132085737[93] = 0.0;
   out_328613363132085737[94] = 0.0;
   out_328613363132085737[95] = 1.0;
   out_328613363132085737[96] = 0.0;
   out_328613363132085737[97] = 0.0;
   out_328613363132085737[98] = 0.0;
   out_328613363132085737[99] = 0.0;
   out_328613363132085737[100] = 0.0;
   out_328613363132085737[101] = 0.0;
   out_328613363132085737[102] = 0.0;
   out_328613363132085737[103] = 0.0;
   out_328613363132085737[104] = 0.0;
   out_328613363132085737[105] = 0.0;
   out_328613363132085737[106] = 0.0;
   out_328613363132085737[107] = 0.0;
   out_328613363132085737[108] = 0.0;
   out_328613363132085737[109] = 0.0;
   out_328613363132085737[110] = 0.0;
   out_328613363132085737[111] = 0.0;
   out_328613363132085737[112] = 0.0;
   out_328613363132085737[113] = 0.0;
   out_328613363132085737[114] = 1.0;
   out_328613363132085737[115] = 0.0;
   out_328613363132085737[116] = 0.0;
   out_328613363132085737[117] = 0.0;
   out_328613363132085737[118] = 0.0;
   out_328613363132085737[119] = 0.0;
   out_328613363132085737[120] = 0.0;
   out_328613363132085737[121] = 0.0;
   out_328613363132085737[122] = 0.0;
   out_328613363132085737[123] = 0.0;
   out_328613363132085737[124] = 0.0;
   out_328613363132085737[125] = 0.0;
   out_328613363132085737[126] = 0.0;
   out_328613363132085737[127] = 0.0;
   out_328613363132085737[128] = 0.0;
   out_328613363132085737[129] = 0.0;
   out_328613363132085737[130] = 0.0;
   out_328613363132085737[131] = 0.0;
   out_328613363132085737[132] = 0.0;
   out_328613363132085737[133] = 1.0;
   out_328613363132085737[134] = 0.0;
   out_328613363132085737[135] = 0.0;
   out_328613363132085737[136] = 0.0;
   out_328613363132085737[137] = 0.0;
   out_328613363132085737[138] = 0.0;
   out_328613363132085737[139] = 0.0;
   out_328613363132085737[140] = 0.0;
   out_328613363132085737[141] = 0.0;
   out_328613363132085737[142] = 0.0;
   out_328613363132085737[143] = 0.0;
   out_328613363132085737[144] = 0.0;
   out_328613363132085737[145] = 0.0;
   out_328613363132085737[146] = 0.0;
   out_328613363132085737[147] = 0.0;
   out_328613363132085737[148] = 0.0;
   out_328613363132085737[149] = 0.0;
   out_328613363132085737[150] = 0.0;
   out_328613363132085737[151] = 0.0;
   out_328613363132085737[152] = 1.0;
   out_328613363132085737[153] = 0.0;
   out_328613363132085737[154] = 0.0;
   out_328613363132085737[155] = 0.0;
   out_328613363132085737[156] = 0.0;
   out_328613363132085737[157] = 0.0;
   out_328613363132085737[158] = 0.0;
   out_328613363132085737[159] = 0.0;
   out_328613363132085737[160] = 0.0;
   out_328613363132085737[161] = 0.0;
   out_328613363132085737[162] = 0.0;
   out_328613363132085737[163] = 0.0;
   out_328613363132085737[164] = 0.0;
   out_328613363132085737[165] = 0.0;
   out_328613363132085737[166] = 0.0;
   out_328613363132085737[167] = 0.0;
   out_328613363132085737[168] = 0.0;
   out_328613363132085737[169] = 0.0;
   out_328613363132085737[170] = 0.0;
   out_328613363132085737[171] = 1.0;
   out_328613363132085737[172] = 0.0;
   out_328613363132085737[173] = 0.0;
   out_328613363132085737[174] = 0.0;
   out_328613363132085737[175] = 0.0;
   out_328613363132085737[176] = 0.0;
   out_328613363132085737[177] = 0.0;
   out_328613363132085737[178] = 0.0;
   out_328613363132085737[179] = 0.0;
   out_328613363132085737[180] = 0.0;
   out_328613363132085737[181] = 0.0;
   out_328613363132085737[182] = 0.0;
   out_328613363132085737[183] = 0.0;
   out_328613363132085737[184] = 0.0;
   out_328613363132085737[185] = 0.0;
   out_328613363132085737[186] = 0.0;
   out_328613363132085737[187] = 0.0;
   out_328613363132085737[188] = 0.0;
   out_328613363132085737[189] = 0.0;
   out_328613363132085737[190] = 1.0;
   out_328613363132085737[191] = 0.0;
   out_328613363132085737[192] = 0.0;
   out_328613363132085737[193] = 0.0;
   out_328613363132085737[194] = 0.0;
   out_328613363132085737[195] = 0.0;
   out_328613363132085737[196] = 0.0;
   out_328613363132085737[197] = 0.0;
   out_328613363132085737[198] = 0.0;
   out_328613363132085737[199] = 0.0;
   out_328613363132085737[200] = 0.0;
   out_328613363132085737[201] = 0.0;
   out_328613363132085737[202] = 0.0;
   out_328613363132085737[203] = 0.0;
   out_328613363132085737[204] = 0.0;
   out_328613363132085737[205] = 0.0;
   out_328613363132085737[206] = 0.0;
   out_328613363132085737[207] = 0.0;
   out_328613363132085737[208] = 0.0;
   out_328613363132085737[209] = 1.0;
   out_328613363132085737[210] = 0.0;
   out_328613363132085737[211] = 0.0;
   out_328613363132085737[212] = 0.0;
   out_328613363132085737[213] = 0.0;
   out_328613363132085737[214] = 0.0;
   out_328613363132085737[215] = 0.0;
   out_328613363132085737[216] = 0.0;
   out_328613363132085737[217] = 0.0;
   out_328613363132085737[218] = 0.0;
   out_328613363132085737[219] = 0.0;
   out_328613363132085737[220] = 0.0;
   out_328613363132085737[221] = 0.0;
   out_328613363132085737[222] = 0.0;
   out_328613363132085737[223] = 0.0;
   out_328613363132085737[224] = 0.0;
   out_328613363132085737[225] = 0.0;
   out_328613363132085737[226] = 0.0;
   out_328613363132085737[227] = 0.0;
   out_328613363132085737[228] = 1.0;
   out_328613363132085737[229] = 0.0;
   out_328613363132085737[230] = 0.0;
   out_328613363132085737[231] = 0.0;
   out_328613363132085737[232] = 0.0;
   out_328613363132085737[233] = 0.0;
   out_328613363132085737[234] = 0.0;
   out_328613363132085737[235] = 0.0;
   out_328613363132085737[236] = 0.0;
   out_328613363132085737[237] = 0.0;
   out_328613363132085737[238] = 0.0;
   out_328613363132085737[239] = 0.0;
   out_328613363132085737[240] = 0.0;
   out_328613363132085737[241] = 0.0;
   out_328613363132085737[242] = 0.0;
   out_328613363132085737[243] = 0.0;
   out_328613363132085737[244] = 0.0;
   out_328613363132085737[245] = 0.0;
   out_328613363132085737[246] = 0.0;
   out_328613363132085737[247] = 1.0;
   out_328613363132085737[248] = 0.0;
   out_328613363132085737[249] = 0.0;
   out_328613363132085737[250] = 0.0;
   out_328613363132085737[251] = 0.0;
   out_328613363132085737[252] = 0.0;
   out_328613363132085737[253] = 0.0;
   out_328613363132085737[254] = 0.0;
   out_328613363132085737[255] = 0.0;
   out_328613363132085737[256] = 0.0;
   out_328613363132085737[257] = 0.0;
   out_328613363132085737[258] = 0.0;
   out_328613363132085737[259] = 0.0;
   out_328613363132085737[260] = 0.0;
   out_328613363132085737[261] = 0.0;
   out_328613363132085737[262] = 0.0;
   out_328613363132085737[263] = 0.0;
   out_328613363132085737[264] = 0.0;
   out_328613363132085737[265] = 0.0;
   out_328613363132085737[266] = 1.0;
   out_328613363132085737[267] = 0.0;
   out_328613363132085737[268] = 0.0;
   out_328613363132085737[269] = 0.0;
   out_328613363132085737[270] = 0.0;
   out_328613363132085737[271] = 0.0;
   out_328613363132085737[272] = 0.0;
   out_328613363132085737[273] = 0.0;
   out_328613363132085737[274] = 0.0;
   out_328613363132085737[275] = 0.0;
   out_328613363132085737[276] = 0.0;
   out_328613363132085737[277] = 0.0;
   out_328613363132085737[278] = 0.0;
   out_328613363132085737[279] = 0.0;
   out_328613363132085737[280] = 0.0;
   out_328613363132085737[281] = 0.0;
   out_328613363132085737[282] = 0.0;
   out_328613363132085737[283] = 0.0;
   out_328613363132085737[284] = 0.0;
   out_328613363132085737[285] = 1.0;
   out_328613363132085737[286] = 0.0;
   out_328613363132085737[287] = 0.0;
   out_328613363132085737[288] = 0.0;
   out_328613363132085737[289] = 0.0;
   out_328613363132085737[290] = 0.0;
   out_328613363132085737[291] = 0.0;
   out_328613363132085737[292] = 0.0;
   out_328613363132085737[293] = 0.0;
   out_328613363132085737[294] = 0.0;
   out_328613363132085737[295] = 0.0;
   out_328613363132085737[296] = 0.0;
   out_328613363132085737[297] = 0.0;
   out_328613363132085737[298] = 0.0;
   out_328613363132085737[299] = 0.0;
   out_328613363132085737[300] = 0.0;
   out_328613363132085737[301] = 0.0;
   out_328613363132085737[302] = 0.0;
   out_328613363132085737[303] = 0.0;
   out_328613363132085737[304] = 1.0;
   out_328613363132085737[305] = 0.0;
   out_328613363132085737[306] = 0.0;
   out_328613363132085737[307] = 0.0;
   out_328613363132085737[308] = 0.0;
   out_328613363132085737[309] = 0.0;
   out_328613363132085737[310] = 0.0;
   out_328613363132085737[311] = 0.0;
   out_328613363132085737[312] = 0.0;
   out_328613363132085737[313] = 0.0;
   out_328613363132085737[314] = 0.0;
   out_328613363132085737[315] = 0.0;
   out_328613363132085737[316] = 0.0;
   out_328613363132085737[317] = 0.0;
   out_328613363132085737[318] = 0.0;
   out_328613363132085737[319] = 0.0;
   out_328613363132085737[320] = 0.0;
   out_328613363132085737[321] = 0.0;
   out_328613363132085737[322] = 0.0;
   out_328613363132085737[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2411932017416861366) {
   out_2411932017416861366[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2411932017416861366[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2411932017416861366[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2411932017416861366[3] = dt*state[12] + state[3];
   out_2411932017416861366[4] = dt*state[13] + state[4];
   out_2411932017416861366[5] = dt*state[14] + state[5];
   out_2411932017416861366[6] = state[6];
   out_2411932017416861366[7] = state[7];
   out_2411932017416861366[8] = state[8];
   out_2411932017416861366[9] = state[9];
   out_2411932017416861366[10] = state[10];
   out_2411932017416861366[11] = state[11];
   out_2411932017416861366[12] = state[12];
   out_2411932017416861366[13] = state[13];
   out_2411932017416861366[14] = state[14];
   out_2411932017416861366[15] = state[15];
   out_2411932017416861366[16] = state[16];
   out_2411932017416861366[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8127227481367081246) {
   out_8127227481367081246[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8127227481367081246[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8127227481367081246[2] = 0;
   out_8127227481367081246[3] = 0;
   out_8127227481367081246[4] = 0;
   out_8127227481367081246[5] = 0;
   out_8127227481367081246[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8127227481367081246[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8127227481367081246[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8127227481367081246[9] = 0;
   out_8127227481367081246[10] = 0;
   out_8127227481367081246[11] = 0;
   out_8127227481367081246[12] = 0;
   out_8127227481367081246[13] = 0;
   out_8127227481367081246[14] = 0;
   out_8127227481367081246[15] = 0;
   out_8127227481367081246[16] = 0;
   out_8127227481367081246[17] = 0;
   out_8127227481367081246[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8127227481367081246[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8127227481367081246[20] = 0;
   out_8127227481367081246[21] = 0;
   out_8127227481367081246[22] = 0;
   out_8127227481367081246[23] = 0;
   out_8127227481367081246[24] = 0;
   out_8127227481367081246[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8127227481367081246[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8127227481367081246[27] = 0;
   out_8127227481367081246[28] = 0;
   out_8127227481367081246[29] = 0;
   out_8127227481367081246[30] = 0;
   out_8127227481367081246[31] = 0;
   out_8127227481367081246[32] = 0;
   out_8127227481367081246[33] = 0;
   out_8127227481367081246[34] = 0;
   out_8127227481367081246[35] = 0;
   out_8127227481367081246[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8127227481367081246[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8127227481367081246[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8127227481367081246[39] = 0;
   out_8127227481367081246[40] = 0;
   out_8127227481367081246[41] = 0;
   out_8127227481367081246[42] = 0;
   out_8127227481367081246[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8127227481367081246[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8127227481367081246[45] = 0;
   out_8127227481367081246[46] = 0;
   out_8127227481367081246[47] = 0;
   out_8127227481367081246[48] = 0;
   out_8127227481367081246[49] = 0;
   out_8127227481367081246[50] = 0;
   out_8127227481367081246[51] = 0;
   out_8127227481367081246[52] = 0;
   out_8127227481367081246[53] = 0;
   out_8127227481367081246[54] = 0;
   out_8127227481367081246[55] = 0;
   out_8127227481367081246[56] = 0;
   out_8127227481367081246[57] = 1;
   out_8127227481367081246[58] = 0;
   out_8127227481367081246[59] = 0;
   out_8127227481367081246[60] = 0;
   out_8127227481367081246[61] = 0;
   out_8127227481367081246[62] = 0;
   out_8127227481367081246[63] = 0;
   out_8127227481367081246[64] = 0;
   out_8127227481367081246[65] = 0;
   out_8127227481367081246[66] = dt;
   out_8127227481367081246[67] = 0;
   out_8127227481367081246[68] = 0;
   out_8127227481367081246[69] = 0;
   out_8127227481367081246[70] = 0;
   out_8127227481367081246[71] = 0;
   out_8127227481367081246[72] = 0;
   out_8127227481367081246[73] = 0;
   out_8127227481367081246[74] = 0;
   out_8127227481367081246[75] = 0;
   out_8127227481367081246[76] = 1;
   out_8127227481367081246[77] = 0;
   out_8127227481367081246[78] = 0;
   out_8127227481367081246[79] = 0;
   out_8127227481367081246[80] = 0;
   out_8127227481367081246[81] = 0;
   out_8127227481367081246[82] = 0;
   out_8127227481367081246[83] = 0;
   out_8127227481367081246[84] = 0;
   out_8127227481367081246[85] = dt;
   out_8127227481367081246[86] = 0;
   out_8127227481367081246[87] = 0;
   out_8127227481367081246[88] = 0;
   out_8127227481367081246[89] = 0;
   out_8127227481367081246[90] = 0;
   out_8127227481367081246[91] = 0;
   out_8127227481367081246[92] = 0;
   out_8127227481367081246[93] = 0;
   out_8127227481367081246[94] = 0;
   out_8127227481367081246[95] = 1;
   out_8127227481367081246[96] = 0;
   out_8127227481367081246[97] = 0;
   out_8127227481367081246[98] = 0;
   out_8127227481367081246[99] = 0;
   out_8127227481367081246[100] = 0;
   out_8127227481367081246[101] = 0;
   out_8127227481367081246[102] = 0;
   out_8127227481367081246[103] = 0;
   out_8127227481367081246[104] = dt;
   out_8127227481367081246[105] = 0;
   out_8127227481367081246[106] = 0;
   out_8127227481367081246[107] = 0;
   out_8127227481367081246[108] = 0;
   out_8127227481367081246[109] = 0;
   out_8127227481367081246[110] = 0;
   out_8127227481367081246[111] = 0;
   out_8127227481367081246[112] = 0;
   out_8127227481367081246[113] = 0;
   out_8127227481367081246[114] = 1;
   out_8127227481367081246[115] = 0;
   out_8127227481367081246[116] = 0;
   out_8127227481367081246[117] = 0;
   out_8127227481367081246[118] = 0;
   out_8127227481367081246[119] = 0;
   out_8127227481367081246[120] = 0;
   out_8127227481367081246[121] = 0;
   out_8127227481367081246[122] = 0;
   out_8127227481367081246[123] = 0;
   out_8127227481367081246[124] = 0;
   out_8127227481367081246[125] = 0;
   out_8127227481367081246[126] = 0;
   out_8127227481367081246[127] = 0;
   out_8127227481367081246[128] = 0;
   out_8127227481367081246[129] = 0;
   out_8127227481367081246[130] = 0;
   out_8127227481367081246[131] = 0;
   out_8127227481367081246[132] = 0;
   out_8127227481367081246[133] = 1;
   out_8127227481367081246[134] = 0;
   out_8127227481367081246[135] = 0;
   out_8127227481367081246[136] = 0;
   out_8127227481367081246[137] = 0;
   out_8127227481367081246[138] = 0;
   out_8127227481367081246[139] = 0;
   out_8127227481367081246[140] = 0;
   out_8127227481367081246[141] = 0;
   out_8127227481367081246[142] = 0;
   out_8127227481367081246[143] = 0;
   out_8127227481367081246[144] = 0;
   out_8127227481367081246[145] = 0;
   out_8127227481367081246[146] = 0;
   out_8127227481367081246[147] = 0;
   out_8127227481367081246[148] = 0;
   out_8127227481367081246[149] = 0;
   out_8127227481367081246[150] = 0;
   out_8127227481367081246[151] = 0;
   out_8127227481367081246[152] = 1;
   out_8127227481367081246[153] = 0;
   out_8127227481367081246[154] = 0;
   out_8127227481367081246[155] = 0;
   out_8127227481367081246[156] = 0;
   out_8127227481367081246[157] = 0;
   out_8127227481367081246[158] = 0;
   out_8127227481367081246[159] = 0;
   out_8127227481367081246[160] = 0;
   out_8127227481367081246[161] = 0;
   out_8127227481367081246[162] = 0;
   out_8127227481367081246[163] = 0;
   out_8127227481367081246[164] = 0;
   out_8127227481367081246[165] = 0;
   out_8127227481367081246[166] = 0;
   out_8127227481367081246[167] = 0;
   out_8127227481367081246[168] = 0;
   out_8127227481367081246[169] = 0;
   out_8127227481367081246[170] = 0;
   out_8127227481367081246[171] = 1;
   out_8127227481367081246[172] = 0;
   out_8127227481367081246[173] = 0;
   out_8127227481367081246[174] = 0;
   out_8127227481367081246[175] = 0;
   out_8127227481367081246[176] = 0;
   out_8127227481367081246[177] = 0;
   out_8127227481367081246[178] = 0;
   out_8127227481367081246[179] = 0;
   out_8127227481367081246[180] = 0;
   out_8127227481367081246[181] = 0;
   out_8127227481367081246[182] = 0;
   out_8127227481367081246[183] = 0;
   out_8127227481367081246[184] = 0;
   out_8127227481367081246[185] = 0;
   out_8127227481367081246[186] = 0;
   out_8127227481367081246[187] = 0;
   out_8127227481367081246[188] = 0;
   out_8127227481367081246[189] = 0;
   out_8127227481367081246[190] = 1;
   out_8127227481367081246[191] = 0;
   out_8127227481367081246[192] = 0;
   out_8127227481367081246[193] = 0;
   out_8127227481367081246[194] = 0;
   out_8127227481367081246[195] = 0;
   out_8127227481367081246[196] = 0;
   out_8127227481367081246[197] = 0;
   out_8127227481367081246[198] = 0;
   out_8127227481367081246[199] = 0;
   out_8127227481367081246[200] = 0;
   out_8127227481367081246[201] = 0;
   out_8127227481367081246[202] = 0;
   out_8127227481367081246[203] = 0;
   out_8127227481367081246[204] = 0;
   out_8127227481367081246[205] = 0;
   out_8127227481367081246[206] = 0;
   out_8127227481367081246[207] = 0;
   out_8127227481367081246[208] = 0;
   out_8127227481367081246[209] = 1;
   out_8127227481367081246[210] = 0;
   out_8127227481367081246[211] = 0;
   out_8127227481367081246[212] = 0;
   out_8127227481367081246[213] = 0;
   out_8127227481367081246[214] = 0;
   out_8127227481367081246[215] = 0;
   out_8127227481367081246[216] = 0;
   out_8127227481367081246[217] = 0;
   out_8127227481367081246[218] = 0;
   out_8127227481367081246[219] = 0;
   out_8127227481367081246[220] = 0;
   out_8127227481367081246[221] = 0;
   out_8127227481367081246[222] = 0;
   out_8127227481367081246[223] = 0;
   out_8127227481367081246[224] = 0;
   out_8127227481367081246[225] = 0;
   out_8127227481367081246[226] = 0;
   out_8127227481367081246[227] = 0;
   out_8127227481367081246[228] = 1;
   out_8127227481367081246[229] = 0;
   out_8127227481367081246[230] = 0;
   out_8127227481367081246[231] = 0;
   out_8127227481367081246[232] = 0;
   out_8127227481367081246[233] = 0;
   out_8127227481367081246[234] = 0;
   out_8127227481367081246[235] = 0;
   out_8127227481367081246[236] = 0;
   out_8127227481367081246[237] = 0;
   out_8127227481367081246[238] = 0;
   out_8127227481367081246[239] = 0;
   out_8127227481367081246[240] = 0;
   out_8127227481367081246[241] = 0;
   out_8127227481367081246[242] = 0;
   out_8127227481367081246[243] = 0;
   out_8127227481367081246[244] = 0;
   out_8127227481367081246[245] = 0;
   out_8127227481367081246[246] = 0;
   out_8127227481367081246[247] = 1;
   out_8127227481367081246[248] = 0;
   out_8127227481367081246[249] = 0;
   out_8127227481367081246[250] = 0;
   out_8127227481367081246[251] = 0;
   out_8127227481367081246[252] = 0;
   out_8127227481367081246[253] = 0;
   out_8127227481367081246[254] = 0;
   out_8127227481367081246[255] = 0;
   out_8127227481367081246[256] = 0;
   out_8127227481367081246[257] = 0;
   out_8127227481367081246[258] = 0;
   out_8127227481367081246[259] = 0;
   out_8127227481367081246[260] = 0;
   out_8127227481367081246[261] = 0;
   out_8127227481367081246[262] = 0;
   out_8127227481367081246[263] = 0;
   out_8127227481367081246[264] = 0;
   out_8127227481367081246[265] = 0;
   out_8127227481367081246[266] = 1;
   out_8127227481367081246[267] = 0;
   out_8127227481367081246[268] = 0;
   out_8127227481367081246[269] = 0;
   out_8127227481367081246[270] = 0;
   out_8127227481367081246[271] = 0;
   out_8127227481367081246[272] = 0;
   out_8127227481367081246[273] = 0;
   out_8127227481367081246[274] = 0;
   out_8127227481367081246[275] = 0;
   out_8127227481367081246[276] = 0;
   out_8127227481367081246[277] = 0;
   out_8127227481367081246[278] = 0;
   out_8127227481367081246[279] = 0;
   out_8127227481367081246[280] = 0;
   out_8127227481367081246[281] = 0;
   out_8127227481367081246[282] = 0;
   out_8127227481367081246[283] = 0;
   out_8127227481367081246[284] = 0;
   out_8127227481367081246[285] = 1;
   out_8127227481367081246[286] = 0;
   out_8127227481367081246[287] = 0;
   out_8127227481367081246[288] = 0;
   out_8127227481367081246[289] = 0;
   out_8127227481367081246[290] = 0;
   out_8127227481367081246[291] = 0;
   out_8127227481367081246[292] = 0;
   out_8127227481367081246[293] = 0;
   out_8127227481367081246[294] = 0;
   out_8127227481367081246[295] = 0;
   out_8127227481367081246[296] = 0;
   out_8127227481367081246[297] = 0;
   out_8127227481367081246[298] = 0;
   out_8127227481367081246[299] = 0;
   out_8127227481367081246[300] = 0;
   out_8127227481367081246[301] = 0;
   out_8127227481367081246[302] = 0;
   out_8127227481367081246[303] = 0;
   out_8127227481367081246[304] = 1;
   out_8127227481367081246[305] = 0;
   out_8127227481367081246[306] = 0;
   out_8127227481367081246[307] = 0;
   out_8127227481367081246[308] = 0;
   out_8127227481367081246[309] = 0;
   out_8127227481367081246[310] = 0;
   out_8127227481367081246[311] = 0;
   out_8127227481367081246[312] = 0;
   out_8127227481367081246[313] = 0;
   out_8127227481367081246[314] = 0;
   out_8127227481367081246[315] = 0;
   out_8127227481367081246[316] = 0;
   out_8127227481367081246[317] = 0;
   out_8127227481367081246[318] = 0;
   out_8127227481367081246[319] = 0;
   out_8127227481367081246[320] = 0;
   out_8127227481367081246[321] = 0;
   out_8127227481367081246[322] = 0;
   out_8127227481367081246[323] = 1;
}
void h_4(double *state, double *unused, double *out_3493540261963132576) {
   out_3493540261963132576[0] = state[6] + state[9];
   out_3493540261963132576[1] = state[7] + state[10];
   out_3493540261963132576[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_425547638922626870) {
   out_425547638922626870[0] = 0;
   out_425547638922626870[1] = 0;
   out_425547638922626870[2] = 0;
   out_425547638922626870[3] = 0;
   out_425547638922626870[4] = 0;
   out_425547638922626870[5] = 0;
   out_425547638922626870[6] = 1;
   out_425547638922626870[7] = 0;
   out_425547638922626870[8] = 0;
   out_425547638922626870[9] = 1;
   out_425547638922626870[10] = 0;
   out_425547638922626870[11] = 0;
   out_425547638922626870[12] = 0;
   out_425547638922626870[13] = 0;
   out_425547638922626870[14] = 0;
   out_425547638922626870[15] = 0;
   out_425547638922626870[16] = 0;
   out_425547638922626870[17] = 0;
   out_425547638922626870[18] = 0;
   out_425547638922626870[19] = 0;
   out_425547638922626870[20] = 0;
   out_425547638922626870[21] = 0;
   out_425547638922626870[22] = 0;
   out_425547638922626870[23] = 0;
   out_425547638922626870[24] = 0;
   out_425547638922626870[25] = 1;
   out_425547638922626870[26] = 0;
   out_425547638922626870[27] = 0;
   out_425547638922626870[28] = 1;
   out_425547638922626870[29] = 0;
   out_425547638922626870[30] = 0;
   out_425547638922626870[31] = 0;
   out_425547638922626870[32] = 0;
   out_425547638922626870[33] = 0;
   out_425547638922626870[34] = 0;
   out_425547638922626870[35] = 0;
   out_425547638922626870[36] = 0;
   out_425547638922626870[37] = 0;
   out_425547638922626870[38] = 0;
   out_425547638922626870[39] = 0;
   out_425547638922626870[40] = 0;
   out_425547638922626870[41] = 0;
   out_425547638922626870[42] = 0;
   out_425547638922626870[43] = 0;
   out_425547638922626870[44] = 1;
   out_425547638922626870[45] = 0;
   out_425547638922626870[46] = 0;
   out_425547638922626870[47] = 1;
   out_425547638922626870[48] = 0;
   out_425547638922626870[49] = 0;
   out_425547638922626870[50] = 0;
   out_425547638922626870[51] = 0;
   out_425547638922626870[52] = 0;
   out_425547638922626870[53] = 0;
}
void h_10(double *state, double *unused, double *out_6421583794262292879) {
   out_6421583794262292879[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6421583794262292879[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6421583794262292879[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2093218466854338741) {
   out_2093218466854338741[0] = 0;
   out_2093218466854338741[1] = 9.8100000000000005*cos(state[1]);
   out_2093218466854338741[2] = 0;
   out_2093218466854338741[3] = 0;
   out_2093218466854338741[4] = -state[8];
   out_2093218466854338741[5] = state[7];
   out_2093218466854338741[6] = 0;
   out_2093218466854338741[7] = state[5];
   out_2093218466854338741[8] = -state[4];
   out_2093218466854338741[9] = 0;
   out_2093218466854338741[10] = 0;
   out_2093218466854338741[11] = 0;
   out_2093218466854338741[12] = 1;
   out_2093218466854338741[13] = 0;
   out_2093218466854338741[14] = 0;
   out_2093218466854338741[15] = 1;
   out_2093218466854338741[16] = 0;
   out_2093218466854338741[17] = 0;
   out_2093218466854338741[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2093218466854338741[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2093218466854338741[20] = 0;
   out_2093218466854338741[21] = state[8];
   out_2093218466854338741[22] = 0;
   out_2093218466854338741[23] = -state[6];
   out_2093218466854338741[24] = -state[5];
   out_2093218466854338741[25] = 0;
   out_2093218466854338741[26] = state[3];
   out_2093218466854338741[27] = 0;
   out_2093218466854338741[28] = 0;
   out_2093218466854338741[29] = 0;
   out_2093218466854338741[30] = 0;
   out_2093218466854338741[31] = 1;
   out_2093218466854338741[32] = 0;
   out_2093218466854338741[33] = 0;
   out_2093218466854338741[34] = 1;
   out_2093218466854338741[35] = 0;
   out_2093218466854338741[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2093218466854338741[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2093218466854338741[38] = 0;
   out_2093218466854338741[39] = -state[7];
   out_2093218466854338741[40] = state[6];
   out_2093218466854338741[41] = 0;
   out_2093218466854338741[42] = state[4];
   out_2093218466854338741[43] = -state[3];
   out_2093218466854338741[44] = 0;
   out_2093218466854338741[45] = 0;
   out_2093218466854338741[46] = 0;
   out_2093218466854338741[47] = 0;
   out_2093218466854338741[48] = 0;
   out_2093218466854338741[49] = 0;
   out_2093218466854338741[50] = 1;
   out_2093218466854338741[51] = 0;
   out_2093218466854338741[52] = 0;
   out_2093218466854338741[53] = 1;
}
void h_13(double *state, double *unused, double *out_3950551688454018720) {
   out_3950551688454018720[0] = state[3];
   out_3950551688454018720[1] = state[4];
   out_3950551688454018720[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3637821464254959671) {
   out_3637821464254959671[0] = 0;
   out_3637821464254959671[1] = 0;
   out_3637821464254959671[2] = 0;
   out_3637821464254959671[3] = 1;
   out_3637821464254959671[4] = 0;
   out_3637821464254959671[5] = 0;
   out_3637821464254959671[6] = 0;
   out_3637821464254959671[7] = 0;
   out_3637821464254959671[8] = 0;
   out_3637821464254959671[9] = 0;
   out_3637821464254959671[10] = 0;
   out_3637821464254959671[11] = 0;
   out_3637821464254959671[12] = 0;
   out_3637821464254959671[13] = 0;
   out_3637821464254959671[14] = 0;
   out_3637821464254959671[15] = 0;
   out_3637821464254959671[16] = 0;
   out_3637821464254959671[17] = 0;
   out_3637821464254959671[18] = 0;
   out_3637821464254959671[19] = 0;
   out_3637821464254959671[20] = 0;
   out_3637821464254959671[21] = 0;
   out_3637821464254959671[22] = 1;
   out_3637821464254959671[23] = 0;
   out_3637821464254959671[24] = 0;
   out_3637821464254959671[25] = 0;
   out_3637821464254959671[26] = 0;
   out_3637821464254959671[27] = 0;
   out_3637821464254959671[28] = 0;
   out_3637821464254959671[29] = 0;
   out_3637821464254959671[30] = 0;
   out_3637821464254959671[31] = 0;
   out_3637821464254959671[32] = 0;
   out_3637821464254959671[33] = 0;
   out_3637821464254959671[34] = 0;
   out_3637821464254959671[35] = 0;
   out_3637821464254959671[36] = 0;
   out_3637821464254959671[37] = 0;
   out_3637821464254959671[38] = 0;
   out_3637821464254959671[39] = 0;
   out_3637821464254959671[40] = 0;
   out_3637821464254959671[41] = 1;
   out_3637821464254959671[42] = 0;
   out_3637821464254959671[43] = 0;
   out_3637821464254959671[44] = 0;
   out_3637821464254959671[45] = 0;
   out_3637821464254959671[46] = 0;
   out_3637821464254959671[47] = 0;
   out_3637821464254959671[48] = 0;
   out_3637821464254959671[49] = 0;
   out_3637821464254959671[50] = 0;
   out_3637821464254959671[51] = 0;
   out_3637821464254959671[52] = 0;
   out_3637821464254959671[53] = 0;
}
void h_14(double *state, double *unused, double *out_4675773390607303658) {
   out_4675773390607303658[0] = state[6];
   out_4675773390607303658[1] = state[7];
   out_4675773390607303658[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2657240793372745426) {
   out_2657240793372745426[0] = 0;
   out_2657240793372745426[1] = 0;
   out_2657240793372745426[2] = 0;
   out_2657240793372745426[3] = 0;
   out_2657240793372745426[4] = 0;
   out_2657240793372745426[5] = 0;
   out_2657240793372745426[6] = 1;
   out_2657240793372745426[7] = 0;
   out_2657240793372745426[8] = 0;
   out_2657240793372745426[9] = 0;
   out_2657240793372745426[10] = 0;
   out_2657240793372745426[11] = 0;
   out_2657240793372745426[12] = 0;
   out_2657240793372745426[13] = 0;
   out_2657240793372745426[14] = 0;
   out_2657240793372745426[15] = 0;
   out_2657240793372745426[16] = 0;
   out_2657240793372745426[17] = 0;
   out_2657240793372745426[18] = 0;
   out_2657240793372745426[19] = 0;
   out_2657240793372745426[20] = 0;
   out_2657240793372745426[21] = 0;
   out_2657240793372745426[22] = 0;
   out_2657240793372745426[23] = 0;
   out_2657240793372745426[24] = 0;
   out_2657240793372745426[25] = 1;
   out_2657240793372745426[26] = 0;
   out_2657240793372745426[27] = 0;
   out_2657240793372745426[28] = 0;
   out_2657240793372745426[29] = 0;
   out_2657240793372745426[30] = 0;
   out_2657240793372745426[31] = 0;
   out_2657240793372745426[32] = 0;
   out_2657240793372745426[33] = 0;
   out_2657240793372745426[34] = 0;
   out_2657240793372745426[35] = 0;
   out_2657240793372745426[36] = 0;
   out_2657240793372745426[37] = 0;
   out_2657240793372745426[38] = 0;
   out_2657240793372745426[39] = 0;
   out_2657240793372745426[40] = 0;
   out_2657240793372745426[41] = 0;
   out_2657240793372745426[42] = 0;
   out_2657240793372745426[43] = 0;
   out_2657240793372745426[44] = 1;
   out_2657240793372745426[45] = 0;
   out_2657240793372745426[46] = 0;
   out_2657240793372745426[47] = 0;
   out_2657240793372745426[48] = 0;
   out_2657240793372745426[49] = 0;
   out_2657240793372745426[50] = 0;
   out_2657240793372745426[51] = 0;
   out_2657240793372745426[52] = 0;
   out_2657240793372745426[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_3892827861815398533) {
  err_fun(nom_x, delta_x, out_3892827861815398533);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_341451131886162609) {
  inv_err_fun(nom_x, true_x, out_341451131886162609);
}
void pose_H_mod_fun(double *state, double *out_328613363132085737) {
  H_mod_fun(state, out_328613363132085737);
}
void pose_f_fun(double *state, double dt, double *out_2411932017416861366) {
  f_fun(state,  dt, out_2411932017416861366);
}
void pose_F_fun(double *state, double dt, double *out_8127227481367081246) {
  F_fun(state,  dt, out_8127227481367081246);
}
void pose_h_4(double *state, double *unused, double *out_3493540261963132576) {
  h_4(state, unused, out_3493540261963132576);
}
void pose_H_4(double *state, double *unused, double *out_425547638922626870) {
  H_4(state, unused, out_425547638922626870);
}
void pose_h_10(double *state, double *unused, double *out_6421583794262292879) {
  h_10(state, unused, out_6421583794262292879);
}
void pose_H_10(double *state, double *unused, double *out_2093218466854338741) {
  H_10(state, unused, out_2093218466854338741);
}
void pose_h_13(double *state, double *unused, double *out_3950551688454018720) {
  h_13(state, unused, out_3950551688454018720);
}
void pose_H_13(double *state, double *unused, double *out_3637821464254959671) {
  H_13(state, unused, out_3637821464254959671);
}
void pose_h_14(double *state, double *unused, double *out_4675773390607303658) {
  h_14(state, unused, out_4675773390607303658);
}
void pose_H_14(double *state, double *unused, double *out_2657240793372745426) {
  H_14(state, unused, out_2657240793372745426);
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
