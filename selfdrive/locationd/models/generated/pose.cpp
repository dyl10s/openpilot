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
void err_fun(double *nom_x, double *delta_x, double *out_5567810526154209734) {
   out_5567810526154209734[0] = delta_x[0] + nom_x[0];
   out_5567810526154209734[1] = delta_x[1] + nom_x[1];
   out_5567810526154209734[2] = delta_x[2] + nom_x[2];
   out_5567810526154209734[3] = delta_x[3] + nom_x[3];
   out_5567810526154209734[4] = delta_x[4] + nom_x[4];
   out_5567810526154209734[5] = delta_x[5] + nom_x[5];
   out_5567810526154209734[6] = delta_x[6] + nom_x[6];
   out_5567810526154209734[7] = delta_x[7] + nom_x[7];
   out_5567810526154209734[8] = delta_x[8] + nom_x[8];
   out_5567810526154209734[9] = delta_x[9] + nom_x[9];
   out_5567810526154209734[10] = delta_x[10] + nom_x[10];
   out_5567810526154209734[11] = delta_x[11] + nom_x[11];
   out_5567810526154209734[12] = delta_x[12] + nom_x[12];
   out_5567810526154209734[13] = delta_x[13] + nom_x[13];
   out_5567810526154209734[14] = delta_x[14] + nom_x[14];
   out_5567810526154209734[15] = delta_x[15] + nom_x[15];
   out_5567810526154209734[16] = delta_x[16] + nom_x[16];
   out_5567810526154209734[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7908491346196944566) {
   out_7908491346196944566[0] = -nom_x[0] + true_x[0];
   out_7908491346196944566[1] = -nom_x[1] + true_x[1];
   out_7908491346196944566[2] = -nom_x[2] + true_x[2];
   out_7908491346196944566[3] = -nom_x[3] + true_x[3];
   out_7908491346196944566[4] = -nom_x[4] + true_x[4];
   out_7908491346196944566[5] = -nom_x[5] + true_x[5];
   out_7908491346196944566[6] = -nom_x[6] + true_x[6];
   out_7908491346196944566[7] = -nom_x[7] + true_x[7];
   out_7908491346196944566[8] = -nom_x[8] + true_x[8];
   out_7908491346196944566[9] = -nom_x[9] + true_x[9];
   out_7908491346196944566[10] = -nom_x[10] + true_x[10];
   out_7908491346196944566[11] = -nom_x[11] + true_x[11];
   out_7908491346196944566[12] = -nom_x[12] + true_x[12];
   out_7908491346196944566[13] = -nom_x[13] + true_x[13];
   out_7908491346196944566[14] = -nom_x[14] + true_x[14];
   out_7908491346196944566[15] = -nom_x[15] + true_x[15];
   out_7908491346196944566[16] = -nom_x[16] + true_x[16];
   out_7908491346196944566[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1058329813454059053) {
   out_1058329813454059053[0] = 1.0;
   out_1058329813454059053[1] = 0.0;
   out_1058329813454059053[2] = 0.0;
   out_1058329813454059053[3] = 0.0;
   out_1058329813454059053[4] = 0.0;
   out_1058329813454059053[5] = 0.0;
   out_1058329813454059053[6] = 0.0;
   out_1058329813454059053[7] = 0.0;
   out_1058329813454059053[8] = 0.0;
   out_1058329813454059053[9] = 0.0;
   out_1058329813454059053[10] = 0.0;
   out_1058329813454059053[11] = 0.0;
   out_1058329813454059053[12] = 0.0;
   out_1058329813454059053[13] = 0.0;
   out_1058329813454059053[14] = 0.0;
   out_1058329813454059053[15] = 0.0;
   out_1058329813454059053[16] = 0.0;
   out_1058329813454059053[17] = 0.0;
   out_1058329813454059053[18] = 0.0;
   out_1058329813454059053[19] = 1.0;
   out_1058329813454059053[20] = 0.0;
   out_1058329813454059053[21] = 0.0;
   out_1058329813454059053[22] = 0.0;
   out_1058329813454059053[23] = 0.0;
   out_1058329813454059053[24] = 0.0;
   out_1058329813454059053[25] = 0.0;
   out_1058329813454059053[26] = 0.0;
   out_1058329813454059053[27] = 0.0;
   out_1058329813454059053[28] = 0.0;
   out_1058329813454059053[29] = 0.0;
   out_1058329813454059053[30] = 0.0;
   out_1058329813454059053[31] = 0.0;
   out_1058329813454059053[32] = 0.0;
   out_1058329813454059053[33] = 0.0;
   out_1058329813454059053[34] = 0.0;
   out_1058329813454059053[35] = 0.0;
   out_1058329813454059053[36] = 0.0;
   out_1058329813454059053[37] = 0.0;
   out_1058329813454059053[38] = 1.0;
   out_1058329813454059053[39] = 0.0;
   out_1058329813454059053[40] = 0.0;
   out_1058329813454059053[41] = 0.0;
   out_1058329813454059053[42] = 0.0;
   out_1058329813454059053[43] = 0.0;
   out_1058329813454059053[44] = 0.0;
   out_1058329813454059053[45] = 0.0;
   out_1058329813454059053[46] = 0.0;
   out_1058329813454059053[47] = 0.0;
   out_1058329813454059053[48] = 0.0;
   out_1058329813454059053[49] = 0.0;
   out_1058329813454059053[50] = 0.0;
   out_1058329813454059053[51] = 0.0;
   out_1058329813454059053[52] = 0.0;
   out_1058329813454059053[53] = 0.0;
   out_1058329813454059053[54] = 0.0;
   out_1058329813454059053[55] = 0.0;
   out_1058329813454059053[56] = 0.0;
   out_1058329813454059053[57] = 1.0;
   out_1058329813454059053[58] = 0.0;
   out_1058329813454059053[59] = 0.0;
   out_1058329813454059053[60] = 0.0;
   out_1058329813454059053[61] = 0.0;
   out_1058329813454059053[62] = 0.0;
   out_1058329813454059053[63] = 0.0;
   out_1058329813454059053[64] = 0.0;
   out_1058329813454059053[65] = 0.0;
   out_1058329813454059053[66] = 0.0;
   out_1058329813454059053[67] = 0.0;
   out_1058329813454059053[68] = 0.0;
   out_1058329813454059053[69] = 0.0;
   out_1058329813454059053[70] = 0.0;
   out_1058329813454059053[71] = 0.0;
   out_1058329813454059053[72] = 0.0;
   out_1058329813454059053[73] = 0.0;
   out_1058329813454059053[74] = 0.0;
   out_1058329813454059053[75] = 0.0;
   out_1058329813454059053[76] = 1.0;
   out_1058329813454059053[77] = 0.0;
   out_1058329813454059053[78] = 0.0;
   out_1058329813454059053[79] = 0.0;
   out_1058329813454059053[80] = 0.0;
   out_1058329813454059053[81] = 0.0;
   out_1058329813454059053[82] = 0.0;
   out_1058329813454059053[83] = 0.0;
   out_1058329813454059053[84] = 0.0;
   out_1058329813454059053[85] = 0.0;
   out_1058329813454059053[86] = 0.0;
   out_1058329813454059053[87] = 0.0;
   out_1058329813454059053[88] = 0.0;
   out_1058329813454059053[89] = 0.0;
   out_1058329813454059053[90] = 0.0;
   out_1058329813454059053[91] = 0.0;
   out_1058329813454059053[92] = 0.0;
   out_1058329813454059053[93] = 0.0;
   out_1058329813454059053[94] = 0.0;
   out_1058329813454059053[95] = 1.0;
   out_1058329813454059053[96] = 0.0;
   out_1058329813454059053[97] = 0.0;
   out_1058329813454059053[98] = 0.0;
   out_1058329813454059053[99] = 0.0;
   out_1058329813454059053[100] = 0.0;
   out_1058329813454059053[101] = 0.0;
   out_1058329813454059053[102] = 0.0;
   out_1058329813454059053[103] = 0.0;
   out_1058329813454059053[104] = 0.0;
   out_1058329813454059053[105] = 0.0;
   out_1058329813454059053[106] = 0.0;
   out_1058329813454059053[107] = 0.0;
   out_1058329813454059053[108] = 0.0;
   out_1058329813454059053[109] = 0.0;
   out_1058329813454059053[110] = 0.0;
   out_1058329813454059053[111] = 0.0;
   out_1058329813454059053[112] = 0.0;
   out_1058329813454059053[113] = 0.0;
   out_1058329813454059053[114] = 1.0;
   out_1058329813454059053[115] = 0.0;
   out_1058329813454059053[116] = 0.0;
   out_1058329813454059053[117] = 0.0;
   out_1058329813454059053[118] = 0.0;
   out_1058329813454059053[119] = 0.0;
   out_1058329813454059053[120] = 0.0;
   out_1058329813454059053[121] = 0.0;
   out_1058329813454059053[122] = 0.0;
   out_1058329813454059053[123] = 0.0;
   out_1058329813454059053[124] = 0.0;
   out_1058329813454059053[125] = 0.0;
   out_1058329813454059053[126] = 0.0;
   out_1058329813454059053[127] = 0.0;
   out_1058329813454059053[128] = 0.0;
   out_1058329813454059053[129] = 0.0;
   out_1058329813454059053[130] = 0.0;
   out_1058329813454059053[131] = 0.0;
   out_1058329813454059053[132] = 0.0;
   out_1058329813454059053[133] = 1.0;
   out_1058329813454059053[134] = 0.0;
   out_1058329813454059053[135] = 0.0;
   out_1058329813454059053[136] = 0.0;
   out_1058329813454059053[137] = 0.0;
   out_1058329813454059053[138] = 0.0;
   out_1058329813454059053[139] = 0.0;
   out_1058329813454059053[140] = 0.0;
   out_1058329813454059053[141] = 0.0;
   out_1058329813454059053[142] = 0.0;
   out_1058329813454059053[143] = 0.0;
   out_1058329813454059053[144] = 0.0;
   out_1058329813454059053[145] = 0.0;
   out_1058329813454059053[146] = 0.0;
   out_1058329813454059053[147] = 0.0;
   out_1058329813454059053[148] = 0.0;
   out_1058329813454059053[149] = 0.0;
   out_1058329813454059053[150] = 0.0;
   out_1058329813454059053[151] = 0.0;
   out_1058329813454059053[152] = 1.0;
   out_1058329813454059053[153] = 0.0;
   out_1058329813454059053[154] = 0.0;
   out_1058329813454059053[155] = 0.0;
   out_1058329813454059053[156] = 0.0;
   out_1058329813454059053[157] = 0.0;
   out_1058329813454059053[158] = 0.0;
   out_1058329813454059053[159] = 0.0;
   out_1058329813454059053[160] = 0.0;
   out_1058329813454059053[161] = 0.0;
   out_1058329813454059053[162] = 0.0;
   out_1058329813454059053[163] = 0.0;
   out_1058329813454059053[164] = 0.0;
   out_1058329813454059053[165] = 0.0;
   out_1058329813454059053[166] = 0.0;
   out_1058329813454059053[167] = 0.0;
   out_1058329813454059053[168] = 0.0;
   out_1058329813454059053[169] = 0.0;
   out_1058329813454059053[170] = 0.0;
   out_1058329813454059053[171] = 1.0;
   out_1058329813454059053[172] = 0.0;
   out_1058329813454059053[173] = 0.0;
   out_1058329813454059053[174] = 0.0;
   out_1058329813454059053[175] = 0.0;
   out_1058329813454059053[176] = 0.0;
   out_1058329813454059053[177] = 0.0;
   out_1058329813454059053[178] = 0.0;
   out_1058329813454059053[179] = 0.0;
   out_1058329813454059053[180] = 0.0;
   out_1058329813454059053[181] = 0.0;
   out_1058329813454059053[182] = 0.0;
   out_1058329813454059053[183] = 0.0;
   out_1058329813454059053[184] = 0.0;
   out_1058329813454059053[185] = 0.0;
   out_1058329813454059053[186] = 0.0;
   out_1058329813454059053[187] = 0.0;
   out_1058329813454059053[188] = 0.0;
   out_1058329813454059053[189] = 0.0;
   out_1058329813454059053[190] = 1.0;
   out_1058329813454059053[191] = 0.0;
   out_1058329813454059053[192] = 0.0;
   out_1058329813454059053[193] = 0.0;
   out_1058329813454059053[194] = 0.0;
   out_1058329813454059053[195] = 0.0;
   out_1058329813454059053[196] = 0.0;
   out_1058329813454059053[197] = 0.0;
   out_1058329813454059053[198] = 0.0;
   out_1058329813454059053[199] = 0.0;
   out_1058329813454059053[200] = 0.0;
   out_1058329813454059053[201] = 0.0;
   out_1058329813454059053[202] = 0.0;
   out_1058329813454059053[203] = 0.0;
   out_1058329813454059053[204] = 0.0;
   out_1058329813454059053[205] = 0.0;
   out_1058329813454059053[206] = 0.0;
   out_1058329813454059053[207] = 0.0;
   out_1058329813454059053[208] = 0.0;
   out_1058329813454059053[209] = 1.0;
   out_1058329813454059053[210] = 0.0;
   out_1058329813454059053[211] = 0.0;
   out_1058329813454059053[212] = 0.0;
   out_1058329813454059053[213] = 0.0;
   out_1058329813454059053[214] = 0.0;
   out_1058329813454059053[215] = 0.0;
   out_1058329813454059053[216] = 0.0;
   out_1058329813454059053[217] = 0.0;
   out_1058329813454059053[218] = 0.0;
   out_1058329813454059053[219] = 0.0;
   out_1058329813454059053[220] = 0.0;
   out_1058329813454059053[221] = 0.0;
   out_1058329813454059053[222] = 0.0;
   out_1058329813454059053[223] = 0.0;
   out_1058329813454059053[224] = 0.0;
   out_1058329813454059053[225] = 0.0;
   out_1058329813454059053[226] = 0.0;
   out_1058329813454059053[227] = 0.0;
   out_1058329813454059053[228] = 1.0;
   out_1058329813454059053[229] = 0.0;
   out_1058329813454059053[230] = 0.0;
   out_1058329813454059053[231] = 0.0;
   out_1058329813454059053[232] = 0.0;
   out_1058329813454059053[233] = 0.0;
   out_1058329813454059053[234] = 0.0;
   out_1058329813454059053[235] = 0.0;
   out_1058329813454059053[236] = 0.0;
   out_1058329813454059053[237] = 0.0;
   out_1058329813454059053[238] = 0.0;
   out_1058329813454059053[239] = 0.0;
   out_1058329813454059053[240] = 0.0;
   out_1058329813454059053[241] = 0.0;
   out_1058329813454059053[242] = 0.0;
   out_1058329813454059053[243] = 0.0;
   out_1058329813454059053[244] = 0.0;
   out_1058329813454059053[245] = 0.0;
   out_1058329813454059053[246] = 0.0;
   out_1058329813454059053[247] = 1.0;
   out_1058329813454059053[248] = 0.0;
   out_1058329813454059053[249] = 0.0;
   out_1058329813454059053[250] = 0.0;
   out_1058329813454059053[251] = 0.0;
   out_1058329813454059053[252] = 0.0;
   out_1058329813454059053[253] = 0.0;
   out_1058329813454059053[254] = 0.0;
   out_1058329813454059053[255] = 0.0;
   out_1058329813454059053[256] = 0.0;
   out_1058329813454059053[257] = 0.0;
   out_1058329813454059053[258] = 0.0;
   out_1058329813454059053[259] = 0.0;
   out_1058329813454059053[260] = 0.0;
   out_1058329813454059053[261] = 0.0;
   out_1058329813454059053[262] = 0.0;
   out_1058329813454059053[263] = 0.0;
   out_1058329813454059053[264] = 0.0;
   out_1058329813454059053[265] = 0.0;
   out_1058329813454059053[266] = 1.0;
   out_1058329813454059053[267] = 0.0;
   out_1058329813454059053[268] = 0.0;
   out_1058329813454059053[269] = 0.0;
   out_1058329813454059053[270] = 0.0;
   out_1058329813454059053[271] = 0.0;
   out_1058329813454059053[272] = 0.0;
   out_1058329813454059053[273] = 0.0;
   out_1058329813454059053[274] = 0.0;
   out_1058329813454059053[275] = 0.0;
   out_1058329813454059053[276] = 0.0;
   out_1058329813454059053[277] = 0.0;
   out_1058329813454059053[278] = 0.0;
   out_1058329813454059053[279] = 0.0;
   out_1058329813454059053[280] = 0.0;
   out_1058329813454059053[281] = 0.0;
   out_1058329813454059053[282] = 0.0;
   out_1058329813454059053[283] = 0.0;
   out_1058329813454059053[284] = 0.0;
   out_1058329813454059053[285] = 1.0;
   out_1058329813454059053[286] = 0.0;
   out_1058329813454059053[287] = 0.0;
   out_1058329813454059053[288] = 0.0;
   out_1058329813454059053[289] = 0.0;
   out_1058329813454059053[290] = 0.0;
   out_1058329813454059053[291] = 0.0;
   out_1058329813454059053[292] = 0.0;
   out_1058329813454059053[293] = 0.0;
   out_1058329813454059053[294] = 0.0;
   out_1058329813454059053[295] = 0.0;
   out_1058329813454059053[296] = 0.0;
   out_1058329813454059053[297] = 0.0;
   out_1058329813454059053[298] = 0.0;
   out_1058329813454059053[299] = 0.0;
   out_1058329813454059053[300] = 0.0;
   out_1058329813454059053[301] = 0.0;
   out_1058329813454059053[302] = 0.0;
   out_1058329813454059053[303] = 0.0;
   out_1058329813454059053[304] = 1.0;
   out_1058329813454059053[305] = 0.0;
   out_1058329813454059053[306] = 0.0;
   out_1058329813454059053[307] = 0.0;
   out_1058329813454059053[308] = 0.0;
   out_1058329813454059053[309] = 0.0;
   out_1058329813454059053[310] = 0.0;
   out_1058329813454059053[311] = 0.0;
   out_1058329813454059053[312] = 0.0;
   out_1058329813454059053[313] = 0.0;
   out_1058329813454059053[314] = 0.0;
   out_1058329813454059053[315] = 0.0;
   out_1058329813454059053[316] = 0.0;
   out_1058329813454059053[317] = 0.0;
   out_1058329813454059053[318] = 0.0;
   out_1058329813454059053[319] = 0.0;
   out_1058329813454059053[320] = 0.0;
   out_1058329813454059053[321] = 0.0;
   out_1058329813454059053[322] = 0.0;
   out_1058329813454059053[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6164632031260569200) {
   out_6164632031260569200[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6164632031260569200[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6164632031260569200[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6164632031260569200[3] = dt*state[12] + state[3];
   out_6164632031260569200[4] = dt*state[13] + state[4];
   out_6164632031260569200[5] = dt*state[14] + state[5];
   out_6164632031260569200[6] = state[6];
   out_6164632031260569200[7] = state[7];
   out_6164632031260569200[8] = state[8];
   out_6164632031260569200[9] = state[9];
   out_6164632031260569200[10] = state[10];
   out_6164632031260569200[11] = state[11];
   out_6164632031260569200[12] = state[12];
   out_6164632031260569200[13] = state[13];
   out_6164632031260569200[14] = state[14];
   out_6164632031260569200[15] = state[15];
   out_6164632031260569200[16] = state[16];
   out_6164632031260569200[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2115210801735647822) {
   out_2115210801735647822[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2115210801735647822[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2115210801735647822[2] = 0;
   out_2115210801735647822[3] = 0;
   out_2115210801735647822[4] = 0;
   out_2115210801735647822[5] = 0;
   out_2115210801735647822[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2115210801735647822[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2115210801735647822[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2115210801735647822[9] = 0;
   out_2115210801735647822[10] = 0;
   out_2115210801735647822[11] = 0;
   out_2115210801735647822[12] = 0;
   out_2115210801735647822[13] = 0;
   out_2115210801735647822[14] = 0;
   out_2115210801735647822[15] = 0;
   out_2115210801735647822[16] = 0;
   out_2115210801735647822[17] = 0;
   out_2115210801735647822[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2115210801735647822[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2115210801735647822[20] = 0;
   out_2115210801735647822[21] = 0;
   out_2115210801735647822[22] = 0;
   out_2115210801735647822[23] = 0;
   out_2115210801735647822[24] = 0;
   out_2115210801735647822[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2115210801735647822[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2115210801735647822[27] = 0;
   out_2115210801735647822[28] = 0;
   out_2115210801735647822[29] = 0;
   out_2115210801735647822[30] = 0;
   out_2115210801735647822[31] = 0;
   out_2115210801735647822[32] = 0;
   out_2115210801735647822[33] = 0;
   out_2115210801735647822[34] = 0;
   out_2115210801735647822[35] = 0;
   out_2115210801735647822[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2115210801735647822[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2115210801735647822[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2115210801735647822[39] = 0;
   out_2115210801735647822[40] = 0;
   out_2115210801735647822[41] = 0;
   out_2115210801735647822[42] = 0;
   out_2115210801735647822[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2115210801735647822[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2115210801735647822[45] = 0;
   out_2115210801735647822[46] = 0;
   out_2115210801735647822[47] = 0;
   out_2115210801735647822[48] = 0;
   out_2115210801735647822[49] = 0;
   out_2115210801735647822[50] = 0;
   out_2115210801735647822[51] = 0;
   out_2115210801735647822[52] = 0;
   out_2115210801735647822[53] = 0;
   out_2115210801735647822[54] = 0;
   out_2115210801735647822[55] = 0;
   out_2115210801735647822[56] = 0;
   out_2115210801735647822[57] = 1;
   out_2115210801735647822[58] = 0;
   out_2115210801735647822[59] = 0;
   out_2115210801735647822[60] = 0;
   out_2115210801735647822[61] = 0;
   out_2115210801735647822[62] = 0;
   out_2115210801735647822[63] = 0;
   out_2115210801735647822[64] = 0;
   out_2115210801735647822[65] = 0;
   out_2115210801735647822[66] = dt;
   out_2115210801735647822[67] = 0;
   out_2115210801735647822[68] = 0;
   out_2115210801735647822[69] = 0;
   out_2115210801735647822[70] = 0;
   out_2115210801735647822[71] = 0;
   out_2115210801735647822[72] = 0;
   out_2115210801735647822[73] = 0;
   out_2115210801735647822[74] = 0;
   out_2115210801735647822[75] = 0;
   out_2115210801735647822[76] = 1;
   out_2115210801735647822[77] = 0;
   out_2115210801735647822[78] = 0;
   out_2115210801735647822[79] = 0;
   out_2115210801735647822[80] = 0;
   out_2115210801735647822[81] = 0;
   out_2115210801735647822[82] = 0;
   out_2115210801735647822[83] = 0;
   out_2115210801735647822[84] = 0;
   out_2115210801735647822[85] = dt;
   out_2115210801735647822[86] = 0;
   out_2115210801735647822[87] = 0;
   out_2115210801735647822[88] = 0;
   out_2115210801735647822[89] = 0;
   out_2115210801735647822[90] = 0;
   out_2115210801735647822[91] = 0;
   out_2115210801735647822[92] = 0;
   out_2115210801735647822[93] = 0;
   out_2115210801735647822[94] = 0;
   out_2115210801735647822[95] = 1;
   out_2115210801735647822[96] = 0;
   out_2115210801735647822[97] = 0;
   out_2115210801735647822[98] = 0;
   out_2115210801735647822[99] = 0;
   out_2115210801735647822[100] = 0;
   out_2115210801735647822[101] = 0;
   out_2115210801735647822[102] = 0;
   out_2115210801735647822[103] = 0;
   out_2115210801735647822[104] = dt;
   out_2115210801735647822[105] = 0;
   out_2115210801735647822[106] = 0;
   out_2115210801735647822[107] = 0;
   out_2115210801735647822[108] = 0;
   out_2115210801735647822[109] = 0;
   out_2115210801735647822[110] = 0;
   out_2115210801735647822[111] = 0;
   out_2115210801735647822[112] = 0;
   out_2115210801735647822[113] = 0;
   out_2115210801735647822[114] = 1;
   out_2115210801735647822[115] = 0;
   out_2115210801735647822[116] = 0;
   out_2115210801735647822[117] = 0;
   out_2115210801735647822[118] = 0;
   out_2115210801735647822[119] = 0;
   out_2115210801735647822[120] = 0;
   out_2115210801735647822[121] = 0;
   out_2115210801735647822[122] = 0;
   out_2115210801735647822[123] = 0;
   out_2115210801735647822[124] = 0;
   out_2115210801735647822[125] = 0;
   out_2115210801735647822[126] = 0;
   out_2115210801735647822[127] = 0;
   out_2115210801735647822[128] = 0;
   out_2115210801735647822[129] = 0;
   out_2115210801735647822[130] = 0;
   out_2115210801735647822[131] = 0;
   out_2115210801735647822[132] = 0;
   out_2115210801735647822[133] = 1;
   out_2115210801735647822[134] = 0;
   out_2115210801735647822[135] = 0;
   out_2115210801735647822[136] = 0;
   out_2115210801735647822[137] = 0;
   out_2115210801735647822[138] = 0;
   out_2115210801735647822[139] = 0;
   out_2115210801735647822[140] = 0;
   out_2115210801735647822[141] = 0;
   out_2115210801735647822[142] = 0;
   out_2115210801735647822[143] = 0;
   out_2115210801735647822[144] = 0;
   out_2115210801735647822[145] = 0;
   out_2115210801735647822[146] = 0;
   out_2115210801735647822[147] = 0;
   out_2115210801735647822[148] = 0;
   out_2115210801735647822[149] = 0;
   out_2115210801735647822[150] = 0;
   out_2115210801735647822[151] = 0;
   out_2115210801735647822[152] = 1;
   out_2115210801735647822[153] = 0;
   out_2115210801735647822[154] = 0;
   out_2115210801735647822[155] = 0;
   out_2115210801735647822[156] = 0;
   out_2115210801735647822[157] = 0;
   out_2115210801735647822[158] = 0;
   out_2115210801735647822[159] = 0;
   out_2115210801735647822[160] = 0;
   out_2115210801735647822[161] = 0;
   out_2115210801735647822[162] = 0;
   out_2115210801735647822[163] = 0;
   out_2115210801735647822[164] = 0;
   out_2115210801735647822[165] = 0;
   out_2115210801735647822[166] = 0;
   out_2115210801735647822[167] = 0;
   out_2115210801735647822[168] = 0;
   out_2115210801735647822[169] = 0;
   out_2115210801735647822[170] = 0;
   out_2115210801735647822[171] = 1;
   out_2115210801735647822[172] = 0;
   out_2115210801735647822[173] = 0;
   out_2115210801735647822[174] = 0;
   out_2115210801735647822[175] = 0;
   out_2115210801735647822[176] = 0;
   out_2115210801735647822[177] = 0;
   out_2115210801735647822[178] = 0;
   out_2115210801735647822[179] = 0;
   out_2115210801735647822[180] = 0;
   out_2115210801735647822[181] = 0;
   out_2115210801735647822[182] = 0;
   out_2115210801735647822[183] = 0;
   out_2115210801735647822[184] = 0;
   out_2115210801735647822[185] = 0;
   out_2115210801735647822[186] = 0;
   out_2115210801735647822[187] = 0;
   out_2115210801735647822[188] = 0;
   out_2115210801735647822[189] = 0;
   out_2115210801735647822[190] = 1;
   out_2115210801735647822[191] = 0;
   out_2115210801735647822[192] = 0;
   out_2115210801735647822[193] = 0;
   out_2115210801735647822[194] = 0;
   out_2115210801735647822[195] = 0;
   out_2115210801735647822[196] = 0;
   out_2115210801735647822[197] = 0;
   out_2115210801735647822[198] = 0;
   out_2115210801735647822[199] = 0;
   out_2115210801735647822[200] = 0;
   out_2115210801735647822[201] = 0;
   out_2115210801735647822[202] = 0;
   out_2115210801735647822[203] = 0;
   out_2115210801735647822[204] = 0;
   out_2115210801735647822[205] = 0;
   out_2115210801735647822[206] = 0;
   out_2115210801735647822[207] = 0;
   out_2115210801735647822[208] = 0;
   out_2115210801735647822[209] = 1;
   out_2115210801735647822[210] = 0;
   out_2115210801735647822[211] = 0;
   out_2115210801735647822[212] = 0;
   out_2115210801735647822[213] = 0;
   out_2115210801735647822[214] = 0;
   out_2115210801735647822[215] = 0;
   out_2115210801735647822[216] = 0;
   out_2115210801735647822[217] = 0;
   out_2115210801735647822[218] = 0;
   out_2115210801735647822[219] = 0;
   out_2115210801735647822[220] = 0;
   out_2115210801735647822[221] = 0;
   out_2115210801735647822[222] = 0;
   out_2115210801735647822[223] = 0;
   out_2115210801735647822[224] = 0;
   out_2115210801735647822[225] = 0;
   out_2115210801735647822[226] = 0;
   out_2115210801735647822[227] = 0;
   out_2115210801735647822[228] = 1;
   out_2115210801735647822[229] = 0;
   out_2115210801735647822[230] = 0;
   out_2115210801735647822[231] = 0;
   out_2115210801735647822[232] = 0;
   out_2115210801735647822[233] = 0;
   out_2115210801735647822[234] = 0;
   out_2115210801735647822[235] = 0;
   out_2115210801735647822[236] = 0;
   out_2115210801735647822[237] = 0;
   out_2115210801735647822[238] = 0;
   out_2115210801735647822[239] = 0;
   out_2115210801735647822[240] = 0;
   out_2115210801735647822[241] = 0;
   out_2115210801735647822[242] = 0;
   out_2115210801735647822[243] = 0;
   out_2115210801735647822[244] = 0;
   out_2115210801735647822[245] = 0;
   out_2115210801735647822[246] = 0;
   out_2115210801735647822[247] = 1;
   out_2115210801735647822[248] = 0;
   out_2115210801735647822[249] = 0;
   out_2115210801735647822[250] = 0;
   out_2115210801735647822[251] = 0;
   out_2115210801735647822[252] = 0;
   out_2115210801735647822[253] = 0;
   out_2115210801735647822[254] = 0;
   out_2115210801735647822[255] = 0;
   out_2115210801735647822[256] = 0;
   out_2115210801735647822[257] = 0;
   out_2115210801735647822[258] = 0;
   out_2115210801735647822[259] = 0;
   out_2115210801735647822[260] = 0;
   out_2115210801735647822[261] = 0;
   out_2115210801735647822[262] = 0;
   out_2115210801735647822[263] = 0;
   out_2115210801735647822[264] = 0;
   out_2115210801735647822[265] = 0;
   out_2115210801735647822[266] = 1;
   out_2115210801735647822[267] = 0;
   out_2115210801735647822[268] = 0;
   out_2115210801735647822[269] = 0;
   out_2115210801735647822[270] = 0;
   out_2115210801735647822[271] = 0;
   out_2115210801735647822[272] = 0;
   out_2115210801735647822[273] = 0;
   out_2115210801735647822[274] = 0;
   out_2115210801735647822[275] = 0;
   out_2115210801735647822[276] = 0;
   out_2115210801735647822[277] = 0;
   out_2115210801735647822[278] = 0;
   out_2115210801735647822[279] = 0;
   out_2115210801735647822[280] = 0;
   out_2115210801735647822[281] = 0;
   out_2115210801735647822[282] = 0;
   out_2115210801735647822[283] = 0;
   out_2115210801735647822[284] = 0;
   out_2115210801735647822[285] = 1;
   out_2115210801735647822[286] = 0;
   out_2115210801735647822[287] = 0;
   out_2115210801735647822[288] = 0;
   out_2115210801735647822[289] = 0;
   out_2115210801735647822[290] = 0;
   out_2115210801735647822[291] = 0;
   out_2115210801735647822[292] = 0;
   out_2115210801735647822[293] = 0;
   out_2115210801735647822[294] = 0;
   out_2115210801735647822[295] = 0;
   out_2115210801735647822[296] = 0;
   out_2115210801735647822[297] = 0;
   out_2115210801735647822[298] = 0;
   out_2115210801735647822[299] = 0;
   out_2115210801735647822[300] = 0;
   out_2115210801735647822[301] = 0;
   out_2115210801735647822[302] = 0;
   out_2115210801735647822[303] = 0;
   out_2115210801735647822[304] = 1;
   out_2115210801735647822[305] = 0;
   out_2115210801735647822[306] = 0;
   out_2115210801735647822[307] = 0;
   out_2115210801735647822[308] = 0;
   out_2115210801735647822[309] = 0;
   out_2115210801735647822[310] = 0;
   out_2115210801735647822[311] = 0;
   out_2115210801735647822[312] = 0;
   out_2115210801735647822[313] = 0;
   out_2115210801735647822[314] = 0;
   out_2115210801735647822[315] = 0;
   out_2115210801735647822[316] = 0;
   out_2115210801735647822[317] = 0;
   out_2115210801735647822[318] = 0;
   out_2115210801735647822[319] = 0;
   out_2115210801735647822[320] = 0;
   out_2115210801735647822[321] = 0;
   out_2115210801735647822[322] = 0;
   out_2115210801735647822[323] = 1;
}
void h_4(double *state, double *unused, double *out_5340316977089833419) {
   out_5340316977089833419[0] = state[6] + state[9];
   out_5340316977089833419[1] = state[7] + state[10];
   out_5340316977089833419[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4789751993297899668) {
   out_4789751993297899668[0] = 0;
   out_4789751993297899668[1] = 0;
   out_4789751993297899668[2] = 0;
   out_4789751993297899668[3] = 0;
   out_4789751993297899668[4] = 0;
   out_4789751993297899668[5] = 0;
   out_4789751993297899668[6] = 1;
   out_4789751993297899668[7] = 0;
   out_4789751993297899668[8] = 0;
   out_4789751993297899668[9] = 1;
   out_4789751993297899668[10] = 0;
   out_4789751993297899668[11] = 0;
   out_4789751993297899668[12] = 0;
   out_4789751993297899668[13] = 0;
   out_4789751993297899668[14] = 0;
   out_4789751993297899668[15] = 0;
   out_4789751993297899668[16] = 0;
   out_4789751993297899668[17] = 0;
   out_4789751993297899668[18] = 0;
   out_4789751993297899668[19] = 0;
   out_4789751993297899668[20] = 0;
   out_4789751993297899668[21] = 0;
   out_4789751993297899668[22] = 0;
   out_4789751993297899668[23] = 0;
   out_4789751993297899668[24] = 0;
   out_4789751993297899668[25] = 1;
   out_4789751993297899668[26] = 0;
   out_4789751993297899668[27] = 0;
   out_4789751993297899668[28] = 1;
   out_4789751993297899668[29] = 0;
   out_4789751993297899668[30] = 0;
   out_4789751993297899668[31] = 0;
   out_4789751993297899668[32] = 0;
   out_4789751993297899668[33] = 0;
   out_4789751993297899668[34] = 0;
   out_4789751993297899668[35] = 0;
   out_4789751993297899668[36] = 0;
   out_4789751993297899668[37] = 0;
   out_4789751993297899668[38] = 0;
   out_4789751993297899668[39] = 0;
   out_4789751993297899668[40] = 0;
   out_4789751993297899668[41] = 0;
   out_4789751993297899668[42] = 0;
   out_4789751993297899668[43] = 0;
   out_4789751993297899668[44] = 1;
   out_4789751993297899668[45] = 0;
   out_4789751993297899668[46] = 0;
   out_4789751993297899668[47] = 1;
   out_4789751993297899668[48] = 0;
   out_4789751993297899668[49] = 0;
   out_4789751993297899668[50] = 0;
   out_4789751993297899668[51] = 0;
   out_4789751993297899668[52] = 0;
   out_4789751993297899668[53] = 0;
}
void h_10(double *state, double *unused, double *out_4503836725223465124) {
   out_4503836725223465124[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4503836725223465124[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4503836725223465124[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8320315452592553094) {
   out_8320315452592553094[0] = 0;
   out_8320315452592553094[1] = 9.8100000000000005*cos(state[1]);
   out_8320315452592553094[2] = 0;
   out_8320315452592553094[3] = 0;
   out_8320315452592553094[4] = -state[8];
   out_8320315452592553094[5] = state[7];
   out_8320315452592553094[6] = 0;
   out_8320315452592553094[7] = state[5];
   out_8320315452592553094[8] = -state[4];
   out_8320315452592553094[9] = 0;
   out_8320315452592553094[10] = 0;
   out_8320315452592553094[11] = 0;
   out_8320315452592553094[12] = 1;
   out_8320315452592553094[13] = 0;
   out_8320315452592553094[14] = 0;
   out_8320315452592553094[15] = 1;
   out_8320315452592553094[16] = 0;
   out_8320315452592553094[17] = 0;
   out_8320315452592553094[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8320315452592553094[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8320315452592553094[20] = 0;
   out_8320315452592553094[21] = state[8];
   out_8320315452592553094[22] = 0;
   out_8320315452592553094[23] = -state[6];
   out_8320315452592553094[24] = -state[5];
   out_8320315452592553094[25] = 0;
   out_8320315452592553094[26] = state[3];
   out_8320315452592553094[27] = 0;
   out_8320315452592553094[28] = 0;
   out_8320315452592553094[29] = 0;
   out_8320315452592553094[30] = 0;
   out_8320315452592553094[31] = 1;
   out_8320315452592553094[32] = 0;
   out_8320315452592553094[33] = 0;
   out_8320315452592553094[34] = 1;
   out_8320315452592553094[35] = 0;
   out_8320315452592553094[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8320315452592553094[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8320315452592553094[38] = 0;
   out_8320315452592553094[39] = -state[7];
   out_8320315452592553094[40] = state[6];
   out_8320315452592553094[41] = 0;
   out_8320315452592553094[42] = state[4];
   out_8320315452592553094[43] = -state[3];
   out_8320315452592553094[44] = 0;
   out_8320315452592553094[45] = 0;
   out_8320315452592553094[46] = 0;
   out_8320315452592553094[47] = 0;
   out_8320315452592553094[48] = 0;
   out_8320315452592553094[49] = 0;
   out_8320315452592553094[50] = 1;
   out_8320315452592553094[51] = 0;
   out_8320315452592553094[52] = 0;
   out_8320315452592553094[53] = 1;
}
void h_13(double *state, double *unused, double *out_743896610209905980) {
   out_743896610209905980[0] = state[3];
   out_743896610209905980[1] = state[4];
   out_743896610209905980[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1577478167965566867) {
   out_1577478167965566867[0] = 0;
   out_1577478167965566867[1] = 0;
   out_1577478167965566867[2] = 0;
   out_1577478167965566867[3] = 1;
   out_1577478167965566867[4] = 0;
   out_1577478167965566867[5] = 0;
   out_1577478167965566867[6] = 0;
   out_1577478167965566867[7] = 0;
   out_1577478167965566867[8] = 0;
   out_1577478167965566867[9] = 0;
   out_1577478167965566867[10] = 0;
   out_1577478167965566867[11] = 0;
   out_1577478167965566867[12] = 0;
   out_1577478167965566867[13] = 0;
   out_1577478167965566867[14] = 0;
   out_1577478167965566867[15] = 0;
   out_1577478167965566867[16] = 0;
   out_1577478167965566867[17] = 0;
   out_1577478167965566867[18] = 0;
   out_1577478167965566867[19] = 0;
   out_1577478167965566867[20] = 0;
   out_1577478167965566867[21] = 0;
   out_1577478167965566867[22] = 1;
   out_1577478167965566867[23] = 0;
   out_1577478167965566867[24] = 0;
   out_1577478167965566867[25] = 0;
   out_1577478167965566867[26] = 0;
   out_1577478167965566867[27] = 0;
   out_1577478167965566867[28] = 0;
   out_1577478167965566867[29] = 0;
   out_1577478167965566867[30] = 0;
   out_1577478167965566867[31] = 0;
   out_1577478167965566867[32] = 0;
   out_1577478167965566867[33] = 0;
   out_1577478167965566867[34] = 0;
   out_1577478167965566867[35] = 0;
   out_1577478167965566867[36] = 0;
   out_1577478167965566867[37] = 0;
   out_1577478167965566867[38] = 0;
   out_1577478167965566867[39] = 0;
   out_1577478167965566867[40] = 0;
   out_1577478167965566867[41] = 1;
   out_1577478167965566867[42] = 0;
   out_1577478167965566867[43] = 0;
   out_1577478167965566867[44] = 0;
   out_1577478167965566867[45] = 0;
   out_1577478167965566867[46] = 0;
   out_1577478167965566867[47] = 0;
   out_1577478167965566867[48] = 0;
   out_1577478167965566867[49] = 0;
   out_1577478167965566867[50] = 0;
   out_1577478167965566867[51] = 0;
   out_1577478167965566867[52] = 0;
   out_1577478167965566867[53] = 0;
}
void h_14(double *state, double *unused, double *out_2801914335576561864) {
   out_2801914335576561864[0] = state[6];
   out_2801914335576561864[1] = state[7];
   out_2801914335576561864[2] = state[8];
}
void H_14(double *state, double *unused, double *out_826511136958415139) {
   out_826511136958415139[0] = 0;
   out_826511136958415139[1] = 0;
   out_826511136958415139[2] = 0;
   out_826511136958415139[3] = 0;
   out_826511136958415139[4] = 0;
   out_826511136958415139[5] = 0;
   out_826511136958415139[6] = 1;
   out_826511136958415139[7] = 0;
   out_826511136958415139[8] = 0;
   out_826511136958415139[9] = 0;
   out_826511136958415139[10] = 0;
   out_826511136958415139[11] = 0;
   out_826511136958415139[12] = 0;
   out_826511136958415139[13] = 0;
   out_826511136958415139[14] = 0;
   out_826511136958415139[15] = 0;
   out_826511136958415139[16] = 0;
   out_826511136958415139[17] = 0;
   out_826511136958415139[18] = 0;
   out_826511136958415139[19] = 0;
   out_826511136958415139[20] = 0;
   out_826511136958415139[21] = 0;
   out_826511136958415139[22] = 0;
   out_826511136958415139[23] = 0;
   out_826511136958415139[24] = 0;
   out_826511136958415139[25] = 1;
   out_826511136958415139[26] = 0;
   out_826511136958415139[27] = 0;
   out_826511136958415139[28] = 0;
   out_826511136958415139[29] = 0;
   out_826511136958415139[30] = 0;
   out_826511136958415139[31] = 0;
   out_826511136958415139[32] = 0;
   out_826511136958415139[33] = 0;
   out_826511136958415139[34] = 0;
   out_826511136958415139[35] = 0;
   out_826511136958415139[36] = 0;
   out_826511136958415139[37] = 0;
   out_826511136958415139[38] = 0;
   out_826511136958415139[39] = 0;
   out_826511136958415139[40] = 0;
   out_826511136958415139[41] = 0;
   out_826511136958415139[42] = 0;
   out_826511136958415139[43] = 0;
   out_826511136958415139[44] = 1;
   out_826511136958415139[45] = 0;
   out_826511136958415139[46] = 0;
   out_826511136958415139[47] = 0;
   out_826511136958415139[48] = 0;
   out_826511136958415139[49] = 0;
   out_826511136958415139[50] = 0;
   out_826511136958415139[51] = 0;
   out_826511136958415139[52] = 0;
   out_826511136958415139[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_5567810526154209734) {
  err_fun(nom_x, delta_x, out_5567810526154209734);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7908491346196944566) {
  inv_err_fun(nom_x, true_x, out_7908491346196944566);
}
void pose_H_mod_fun(double *state, double *out_1058329813454059053) {
  H_mod_fun(state, out_1058329813454059053);
}
void pose_f_fun(double *state, double dt, double *out_6164632031260569200) {
  f_fun(state,  dt, out_6164632031260569200);
}
void pose_F_fun(double *state, double dt, double *out_2115210801735647822) {
  F_fun(state,  dt, out_2115210801735647822);
}
void pose_h_4(double *state, double *unused, double *out_5340316977089833419) {
  h_4(state, unused, out_5340316977089833419);
}
void pose_H_4(double *state, double *unused, double *out_4789751993297899668) {
  H_4(state, unused, out_4789751993297899668);
}
void pose_h_10(double *state, double *unused, double *out_4503836725223465124) {
  h_10(state, unused, out_4503836725223465124);
}
void pose_H_10(double *state, double *unused, double *out_8320315452592553094) {
  H_10(state, unused, out_8320315452592553094);
}
void pose_h_13(double *state, double *unused, double *out_743896610209905980) {
  h_13(state, unused, out_743896610209905980);
}
void pose_H_13(double *state, double *unused, double *out_1577478167965566867) {
  H_13(state, unused, out_1577478167965566867);
}
void pose_h_14(double *state, double *unused, double *out_2801914335576561864) {
  h_14(state, unused, out_2801914335576561864);
}
void pose_H_14(double *state, double *unused, double *out_826511136958415139) {
  H_14(state, unused, out_826511136958415139);
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
