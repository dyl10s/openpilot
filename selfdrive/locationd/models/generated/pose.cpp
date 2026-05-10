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
void err_fun(double *nom_x, double *delta_x, double *out_8259662850093450970) {
   out_8259662850093450970[0] = delta_x[0] + nom_x[0];
   out_8259662850093450970[1] = delta_x[1] + nom_x[1];
   out_8259662850093450970[2] = delta_x[2] + nom_x[2];
   out_8259662850093450970[3] = delta_x[3] + nom_x[3];
   out_8259662850093450970[4] = delta_x[4] + nom_x[4];
   out_8259662850093450970[5] = delta_x[5] + nom_x[5];
   out_8259662850093450970[6] = delta_x[6] + nom_x[6];
   out_8259662850093450970[7] = delta_x[7] + nom_x[7];
   out_8259662850093450970[8] = delta_x[8] + nom_x[8];
   out_8259662850093450970[9] = delta_x[9] + nom_x[9];
   out_8259662850093450970[10] = delta_x[10] + nom_x[10];
   out_8259662850093450970[11] = delta_x[11] + nom_x[11];
   out_8259662850093450970[12] = delta_x[12] + nom_x[12];
   out_8259662850093450970[13] = delta_x[13] + nom_x[13];
   out_8259662850093450970[14] = delta_x[14] + nom_x[14];
   out_8259662850093450970[15] = delta_x[15] + nom_x[15];
   out_8259662850093450970[16] = delta_x[16] + nom_x[16];
   out_8259662850093450970[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7477554158578246383) {
   out_7477554158578246383[0] = -nom_x[0] + true_x[0];
   out_7477554158578246383[1] = -nom_x[1] + true_x[1];
   out_7477554158578246383[2] = -nom_x[2] + true_x[2];
   out_7477554158578246383[3] = -nom_x[3] + true_x[3];
   out_7477554158578246383[4] = -nom_x[4] + true_x[4];
   out_7477554158578246383[5] = -nom_x[5] + true_x[5];
   out_7477554158578246383[6] = -nom_x[6] + true_x[6];
   out_7477554158578246383[7] = -nom_x[7] + true_x[7];
   out_7477554158578246383[8] = -nom_x[8] + true_x[8];
   out_7477554158578246383[9] = -nom_x[9] + true_x[9];
   out_7477554158578246383[10] = -nom_x[10] + true_x[10];
   out_7477554158578246383[11] = -nom_x[11] + true_x[11];
   out_7477554158578246383[12] = -nom_x[12] + true_x[12];
   out_7477554158578246383[13] = -nom_x[13] + true_x[13];
   out_7477554158578246383[14] = -nom_x[14] + true_x[14];
   out_7477554158578246383[15] = -nom_x[15] + true_x[15];
   out_7477554158578246383[16] = -nom_x[16] + true_x[16];
   out_7477554158578246383[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6622639630704307229) {
   out_6622639630704307229[0] = 1.0;
   out_6622639630704307229[1] = 0.0;
   out_6622639630704307229[2] = 0.0;
   out_6622639630704307229[3] = 0.0;
   out_6622639630704307229[4] = 0.0;
   out_6622639630704307229[5] = 0.0;
   out_6622639630704307229[6] = 0.0;
   out_6622639630704307229[7] = 0.0;
   out_6622639630704307229[8] = 0.0;
   out_6622639630704307229[9] = 0.0;
   out_6622639630704307229[10] = 0.0;
   out_6622639630704307229[11] = 0.0;
   out_6622639630704307229[12] = 0.0;
   out_6622639630704307229[13] = 0.0;
   out_6622639630704307229[14] = 0.0;
   out_6622639630704307229[15] = 0.0;
   out_6622639630704307229[16] = 0.0;
   out_6622639630704307229[17] = 0.0;
   out_6622639630704307229[18] = 0.0;
   out_6622639630704307229[19] = 1.0;
   out_6622639630704307229[20] = 0.0;
   out_6622639630704307229[21] = 0.0;
   out_6622639630704307229[22] = 0.0;
   out_6622639630704307229[23] = 0.0;
   out_6622639630704307229[24] = 0.0;
   out_6622639630704307229[25] = 0.0;
   out_6622639630704307229[26] = 0.0;
   out_6622639630704307229[27] = 0.0;
   out_6622639630704307229[28] = 0.0;
   out_6622639630704307229[29] = 0.0;
   out_6622639630704307229[30] = 0.0;
   out_6622639630704307229[31] = 0.0;
   out_6622639630704307229[32] = 0.0;
   out_6622639630704307229[33] = 0.0;
   out_6622639630704307229[34] = 0.0;
   out_6622639630704307229[35] = 0.0;
   out_6622639630704307229[36] = 0.0;
   out_6622639630704307229[37] = 0.0;
   out_6622639630704307229[38] = 1.0;
   out_6622639630704307229[39] = 0.0;
   out_6622639630704307229[40] = 0.0;
   out_6622639630704307229[41] = 0.0;
   out_6622639630704307229[42] = 0.0;
   out_6622639630704307229[43] = 0.0;
   out_6622639630704307229[44] = 0.0;
   out_6622639630704307229[45] = 0.0;
   out_6622639630704307229[46] = 0.0;
   out_6622639630704307229[47] = 0.0;
   out_6622639630704307229[48] = 0.0;
   out_6622639630704307229[49] = 0.0;
   out_6622639630704307229[50] = 0.0;
   out_6622639630704307229[51] = 0.0;
   out_6622639630704307229[52] = 0.0;
   out_6622639630704307229[53] = 0.0;
   out_6622639630704307229[54] = 0.0;
   out_6622639630704307229[55] = 0.0;
   out_6622639630704307229[56] = 0.0;
   out_6622639630704307229[57] = 1.0;
   out_6622639630704307229[58] = 0.0;
   out_6622639630704307229[59] = 0.0;
   out_6622639630704307229[60] = 0.0;
   out_6622639630704307229[61] = 0.0;
   out_6622639630704307229[62] = 0.0;
   out_6622639630704307229[63] = 0.0;
   out_6622639630704307229[64] = 0.0;
   out_6622639630704307229[65] = 0.0;
   out_6622639630704307229[66] = 0.0;
   out_6622639630704307229[67] = 0.0;
   out_6622639630704307229[68] = 0.0;
   out_6622639630704307229[69] = 0.0;
   out_6622639630704307229[70] = 0.0;
   out_6622639630704307229[71] = 0.0;
   out_6622639630704307229[72] = 0.0;
   out_6622639630704307229[73] = 0.0;
   out_6622639630704307229[74] = 0.0;
   out_6622639630704307229[75] = 0.0;
   out_6622639630704307229[76] = 1.0;
   out_6622639630704307229[77] = 0.0;
   out_6622639630704307229[78] = 0.0;
   out_6622639630704307229[79] = 0.0;
   out_6622639630704307229[80] = 0.0;
   out_6622639630704307229[81] = 0.0;
   out_6622639630704307229[82] = 0.0;
   out_6622639630704307229[83] = 0.0;
   out_6622639630704307229[84] = 0.0;
   out_6622639630704307229[85] = 0.0;
   out_6622639630704307229[86] = 0.0;
   out_6622639630704307229[87] = 0.0;
   out_6622639630704307229[88] = 0.0;
   out_6622639630704307229[89] = 0.0;
   out_6622639630704307229[90] = 0.0;
   out_6622639630704307229[91] = 0.0;
   out_6622639630704307229[92] = 0.0;
   out_6622639630704307229[93] = 0.0;
   out_6622639630704307229[94] = 0.0;
   out_6622639630704307229[95] = 1.0;
   out_6622639630704307229[96] = 0.0;
   out_6622639630704307229[97] = 0.0;
   out_6622639630704307229[98] = 0.0;
   out_6622639630704307229[99] = 0.0;
   out_6622639630704307229[100] = 0.0;
   out_6622639630704307229[101] = 0.0;
   out_6622639630704307229[102] = 0.0;
   out_6622639630704307229[103] = 0.0;
   out_6622639630704307229[104] = 0.0;
   out_6622639630704307229[105] = 0.0;
   out_6622639630704307229[106] = 0.0;
   out_6622639630704307229[107] = 0.0;
   out_6622639630704307229[108] = 0.0;
   out_6622639630704307229[109] = 0.0;
   out_6622639630704307229[110] = 0.0;
   out_6622639630704307229[111] = 0.0;
   out_6622639630704307229[112] = 0.0;
   out_6622639630704307229[113] = 0.0;
   out_6622639630704307229[114] = 1.0;
   out_6622639630704307229[115] = 0.0;
   out_6622639630704307229[116] = 0.0;
   out_6622639630704307229[117] = 0.0;
   out_6622639630704307229[118] = 0.0;
   out_6622639630704307229[119] = 0.0;
   out_6622639630704307229[120] = 0.0;
   out_6622639630704307229[121] = 0.0;
   out_6622639630704307229[122] = 0.0;
   out_6622639630704307229[123] = 0.0;
   out_6622639630704307229[124] = 0.0;
   out_6622639630704307229[125] = 0.0;
   out_6622639630704307229[126] = 0.0;
   out_6622639630704307229[127] = 0.0;
   out_6622639630704307229[128] = 0.0;
   out_6622639630704307229[129] = 0.0;
   out_6622639630704307229[130] = 0.0;
   out_6622639630704307229[131] = 0.0;
   out_6622639630704307229[132] = 0.0;
   out_6622639630704307229[133] = 1.0;
   out_6622639630704307229[134] = 0.0;
   out_6622639630704307229[135] = 0.0;
   out_6622639630704307229[136] = 0.0;
   out_6622639630704307229[137] = 0.0;
   out_6622639630704307229[138] = 0.0;
   out_6622639630704307229[139] = 0.0;
   out_6622639630704307229[140] = 0.0;
   out_6622639630704307229[141] = 0.0;
   out_6622639630704307229[142] = 0.0;
   out_6622639630704307229[143] = 0.0;
   out_6622639630704307229[144] = 0.0;
   out_6622639630704307229[145] = 0.0;
   out_6622639630704307229[146] = 0.0;
   out_6622639630704307229[147] = 0.0;
   out_6622639630704307229[148] = 0.0;
   out_6622639630704307229[149] = 0.0;
   out_6622639630704307229[150] = 0.0;
   out_6622639630704307229[151] = 0.0;
   out_6622639630704307229[152] = 1.0;
   out_6622639630704307229[153] = 0.0;
   out_6622639630704307229[154] = 0.0;
   out_6622639630704307229[155] = 0.0;
   out_6622639630704307229[156] = 0.0;
   out_6622639630704307229[157] = 0.0;
   out_6622639630704307229[158] = 0.0;
   out_6622639630704307229[159] = 0.0;
   out_6622639630704307229[160] = 0.0;
   out_6622639630704307229[161] = 0.0;
   out_6622639630704307229[162] = 0.0;
   out_6622639630704307229[163] = 0.0;
   out_6622639630704307229[164] = 0.0;
   out_6622639630704307229[165] = 0.0;
   out_6622639630704307229[166] = 0.0;
   out_6622639630704307229[167] = 0.0;
   out_6622639630704307229[168] = 0.0;
   out_6622639630704307229[169] = 0.0;
   out_6622639630704307229[170] = 0.0;
   out_6622639630704307229[171] = 1.0;
   out_6622639630704307229[172] = 0.0;
   out_6622639630704307229[173] = 0.0;
   out_6622639630704307229[174] = 0.0;
   out_6622639630704307229[175] = 0.0;
   out_6622639630704307229[176] = 0.0;
   out_6622639630704307229[177] = 0.0;
   out_6622639630704307229[178] = 0.0;
   out_6622639630704307229[179] = 0.0;
   out_6622639630704307229[180] = 0.0;
   out_6622639630704307229[181] = 0.0;
   out_6622639630704307229[182] = 0.0;
   out_6622639630704307229[183] = 0.0;
   out_6622639630704307229[184] = 0.0;
   out_6622639630704307229[185] = 0.0;
   out_6622639630704307229[186] = 0.0;
   out_6622639630704307229[187] = 0.0;
   out_6622639630704307229[188] = 0.0;
   out_6622639630704307229[189] = 0.0;
   out_6622639630704307229[190] = 1.0;
   out_6622639630704307229[191] = 0.0;
   out_6622639630704307229[192] = 0.0;
   out_6622639630704307229[193] = 0.0;
   out_6622639630704307229[194] = 0.0;
   out_6622639630704307229[195] = 0.0;
   out_6622639630704307229[196] = 0.0;
   out_6622639630704307229[197] = 0.0;
   out_6622639630704307229[198] = 0.0;
   out_6622639630704307229[199] = 0.0;
   out_6622639630704307229[200] = 0.0;
   out_6622639630704307229[201] = 0.0;
   out_6622639630704307229[202] = 0.0;
   out_6622639630704307229[203] = 0.0;
   out_6622639630704307229[204] = 0.0;
   out_6622639630704307229[205] = 0.0;
   out_6622639630704307229[206] = 0.0;
   out_6622639630704307229[207] = 0.0;
   out_6622639630704307229[208] = 0.0;
   out_6622639630704307229[209] = 1.0;
   out_6622639630704307229[210] = 0.0;
   out_6622639630704307229[211] = 0.0;
   out_6622639630704307229[212] = 0.0;
   out_6622639630704307229[213] = 0.0;
   out_6622639630704307229[214] = 0.0;
   out_6622639630704307229[215] = 0.0;
   out_6622639630704307229[216] = 0.0;
   out_6622639630704307229[217] = 0.0;
   out_6622639630704307229[218] = 0.0;
   out_6622639630704307229[219] = 0.0;
   out_6622639630704307229[220] = 0.0;
   out_6622639630704307229[221] = 0.0;
   out_6622639630704307229[222] = 0.0;
   out_6622639630704307229[223] = 0.0;
   out_6622639630704307229[224] = 0.0;
   out_6622639630704307229[225] = 0.0;
   out_6622639630704307229[226] = 0.0;
   out_6622639630704307229[227] = 0.0;
   out_6622639630704307229[228] = 1.0;
   out_6622639630704307229[229] = 0.0;
   out_6622639630704307229[230] = 0.0;
   out_6622639630704307229[231] = 0.0;
   out_6622639630704307229[232] = 0.0;
   out_6622639630704307229[233] = 0.0;
   out_6622639630704307229[234] = 0.0;
   out_6622639630704307229[235] = 0.0;
   out_6622639630704307229[236] = 0.0;
   out_6622639630704307229[237] = 0.0;
   out_6622639630704307229[238] = 0.0;
   out_6622639630704307229[239] = 0.0;
   out_6622639630704307229[240] = 0.0;
   out_6622639630704307229[241] = 0.0;
   out_6622639630704307229[242] = 0.0;
   out_6622639630704307229[243] = 0.0;
   out_6622639630704307229[244] = 0.0;
   out_6622639630704307229[245] = 0.0;
   out_6622639630704307229[246] = 0.0;
   out_6622639630704307229[247] = 1.0;
   out_6622639630704307229[248] = 0.0;
   out_6622639630704307229[249] = 0.0;
   out_6622639630704307229[250] = 0.0;
   out_6622639630704307229[251] = 0.0;
   out_6622639630704307229[252] = 0.0;
   out_6622639630704307229[253] = 0.0;
   out_6622639630704307229[254] = 0.0;
   out_6622639630704307229[255] = 0.0;
   out_6622639630704307229[256] = 0.0;
   out_6622639630704307229[257] = 0.0;
   out_6622639630704307229[258] = 0.0;
   out_6622639630704307229[259] = 0.0;
   out_6622639630704307229[260] = 0.0;
   out_6622639630704307229[261] = 0.0;
   out_6622639630704307229[262] = 0.0;
   out_6622639630704307229[263] = 0.0;
   out_6622639630704307229[264] = 0.0;
   out_6622639630704307229[265] = 0.0;
   out_6622639630704307229[266] = 1.0;
   out_6622639630704307229[267] = 0.0;
   out_6622639630704307229[268] = 0.0;
   out_6622639630704307229[269] = 0.0;
   out_6622639630704307229[270] = 0.0;
   out_6622639630704307229[271] = 0.0;
   out_6622639630704307229[272] = 0.0;
   out_6622639630704307229[273] = 0.0;
   out_6622639630704307229[274] = 0.0;
   out_6622639630704307229[275] = 0.0;
   out_6622639630704307229[276] = 0.0;
   out_6622639630704307229[277] = 0.0;
   out_6622639630704307229[278] = 0.0;
   out_6622639630704307229[279] = 0.0;
   out_6622639630704307229[280] = 0.0;
   out_6622639630704307229[281] = 0.0;
   out_6622639630704307229[282] = 0.0;
   out_6622639630704307229[283] = 0.0;
   out_6622639630704307229[284] = 0.0;
   out_6622639630704307229[285] = 1.0;
   out_6622639630704307229[286] = 0.0;
   out_6622639630704307229[287] = 0.0;
   out_6622639630704307229[288] = 0.0;
   out_6622639630704307229[289] = 0.0;
   out_6622639630704307229[290] = 0.0;
   out_6622639630704307229[291] = 0.0;
   out_6622639630704307229[292] = 0.0;
   out_6622639630704307229[293] = 0.0;
   out_6622639630704307229[294] = 0.0;
   out_6622639630704307229[295] = 0.0;
   out_6622639630704307229[296] = 0.0;
   out_6622639630704307229[297] = 0.0;
   out_6622639630704307229[298] = 0.0;
   out_6622639630704307229[299] = 0.0;
   out_6622639630704307229[300] = 0.0;
   out_6622639630704307229[301] = 0.0;
   out_6622639630704307229[302] = 0.0;
   out_6622639630704307229[303] = 0.0;
   out_6622639630704307229[304] = 1.0;
   out_6622639630704307229[305] = 0.0;
   out_6622639630704307229[306] = 0.0;
   out_6622639630704307229[307] = 0.0;
   out_6622639630704307229[308] = 0.0;
   out_6622639630704307229[309] = 0.0;
   out_6622639630704307229[310] = 0.0;
   out_6622639630704307229[311] = 0.0;
   out_6622639630704307229[312] = 0.0;
   out_6622639630704307229[313] = 0.0;
   out_6622639630704307229[314] = 0.0;
   out_6622639630704307229[315] = 0.0;
   out_6622639630704307229[316] = 0.0;
   out_6622639630704307229[317] = 0.0;
   out_6622639630704307229[318] = 0.0;
   out_6622639630704307229[319] = 0.0;
   out_6622639630704307229[320] = 0.0;
   out_6622639630704307229[321] = 0.0;
   out_6622639630704307229[322] = 0.0;
   out_6622639630704307229[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2747407686181114080) {
   out_2747407686181114080[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2747407686181114080[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2747407686181114080[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2747407686181114080[3] = dt*state[12] + state[3];
   out_2747407686181114080[4] = dt*state[13] + state[4];
   out_2747407686181114080[5] = dt*state[14] + state[5];
   out_2747407686181114080[6] = state[6];
   out_2747407686181114080[7] = state[7];
   out_2747407686181114080[8] = state[8];
   out_2747407686181114080[9] = state[9];
   out_2747407686181114080[10] = state[10];
   out_2747407686181114080[11] = state[11];
   out_2747407686181114080[12] = state[12];
   out_2747407686181114080[13] = state[13];
   out_2747407686181114080[14] = state[14];
   out_2747407686181114080[15] = state[15];
   out_2747407686181114080[16] = state[16];
   out_2747407686181114080[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5168326300746653192) {
   out_5168326300746653192[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5168326300746653192[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5168326300746653192[2] = 0;
   out_5168326300746653192[3] = 0;
   out_5168326300746653192[4] = 0;
   out_5168326300746653192[5] = 0;
   out_5168326300746653192[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5168326300746653192[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5168326300746653192[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5168326300746653192[9] = 0;
   out_5168326300746653192[10] = 0;
   out_5168326300746653192[11] = 0;
   out_5168326300746653192[12] = 0;
   out_5168326300746653192[13] = 0;
   out_5168326300746653192[14] = 0;
   out_5168326300746653192[15] = 0;
   out_5168326300746653192[16] = 0;
   out_5168326300746653192[17] = 0;
   out_5168326300746653192[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5168326300746653192[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5168326300746653192[20] = 0;
   out_5168326300746653192[21] = 0;
   out_5168326300746653192[22] = 0;
   out_5168326300746653192[23] = 0;
   out_5168326300746653192[24] = 0;
   out_5168326300746653192[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5168326300746653192[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5168326300746653192[27] = 0;
   out_5168326300746653192[28] = 0;
   out_5168326300746653192[29] = 0;
   out_5168326300746653192[30] = 0;
   out_5168326300746653192[31] = 0;
   out_5168326300746653192[32] = 0;
   out_5168326300746653192[33] = 0;
   out_5168326300746653192[34] = 0;
   out_5168326300746653192[35] = 0;
   out_5168326300746653192[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5168326300746653192[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5168326300746653192[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5168326300746653192[39] = 0;
   out_5168326300746653192[40] = 0;
   out_5168326300746653192[41] = 0;
   out_5168326300746653192[42] = 0;
   out_5168326300746653192[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5168326300746653192[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5168326300746653192[45] = 0;
   out_5168326300746653192[46] = 0;
   out_5168326300746653192[47] = 0;
   out_5168326300746653192[48] = 0;
   out_5168326300746653192[49] = 0;
   out_5168326300746653192[50] = 0;
   out_5168326300746653192[51] = 0;
   out_5168326300746653192[52] = 0;
   out_5168326300746653192[53] = 0;
   out_5168326300746653192[54] = 0;
   out_5168326300746653192[55] = 0;
   out_5168326300746653192[56] = 0;
   out_5168326300746653192[57] = 1;
   out_5168326300746653192[58] = 0;
   out_5168326300746653192[59] = 0;
   out_5168326300746653192[60] = 0;
   out_5168326300746653192[61] = 0;
   out_5168326300746653192[62] = 0;
   out_5168326300746653192[63] = 0;
   out_5168326300746653192[64] = 0;
   out_5168326300746653192[65] = 0;
   out_5168326300746653192[66] = dt;
   out_5168326300746653192[67] = 0;
   out_5168326300746653192[68] = 0;
   out_5168326300746653192[69] = 0;
   out_5168326300746653192[70] = 0;
   out_5168326300746653192[71] = 0;
   out_5168326300746653192[72] = 0;
   out_5168326300746653192[73] = 0;
   out_5168326300746653192[74] = 0;
   out_5168326300746653192[75] = 0;
   out_5168326300746653192[76] = 1;
   out_5168326300746653192[77] = 0;
   out_5168326300746653192[78] = 0;
   out_5168326300746653192[79] = 0;
   out_5168326300746653192[80] = 0;
   out_5168326300746653192[81] = 0;
   out_5168326300746653192[82] = 0;
   out_5168326300746653192[83] = 0;
   out_5168326300746653192[84] = 0;
   out_5168326300746653192[85] = dt;
   out_5168326300746653192[86] = 0;
   out_5168326300746653192[87] = 0;
   out_5168326300746653192[88] = 0;
   out_5168326300746653192[89] = 0;
   out_5168326300746653192[90] = 0;
   out_5168326300746653192[91] = 0;
   out_5168326300746653192[92] = 0;
   out_5168326300746653192[93] = 0;
   out_5168326300746653192[94] = 0;
   out_5168326300746653192[95] = 1;
   out_5168326300746653192[96] = 0;
   out_5168326300746653192[97] = 0;
   out_5168326300746653192[98] = 0;
   out_5168326300746653192[99] = 0;
   out_5168326300746653192[100] = 0;
   out_5168326300746653192[101] = 0;
   out_5168326300746653192[102] = 0;
   out_5168326300746653192[103] = 0;
   out_5168326300746653192[104] = dt;
   out_5168326300746653192[105] = 0;
   out_5168326300746653192[106] = 0;
   out_5168326300746653192[107] = 0;
   out_5168326300746653192[108] = 0;
   out_5168326300746653192[109] = 0;
   out_5168326300746653192[110] = 0;
   out_5168326300746653192[111] = 0;
   out_5168326300746653192[112] = 0;
   out_5168326300746653192[113] = 0;
   out_5168326300746653192[114] = 1;
   out_5168326300746653192[115] = 0;
   out_5168326300746653192[116] = 0;
   out_5168326300746653192[117] = 0;
   out_5168326300746653192[118] = 0;
   out_5168326300746653192[119] = 0;
   out_5168326300746653192[120] = 0;
   out_5168326300746653192[121] = 0;
   out_5168326300746653192[122] = 0;
   out_5168326300746653192[123] = 0;
   out_5168326300746653192[124] = 0;
   out_5168326300746653192[125] = 0;
   out_5168326300746653192[126] = 0;
   out_5168326300746653192[127] = 0;
   out_5168326300746653192[128] = 0;
   out_5168326300746653192[129] = 0;
   out_5168326300746653192[130] = 0;
   out_5168326300746653192[131] = 0;
   out_5168326300746653192[132] = 0;
   out_5168326300746653192[133] = 1;
   out_5168326300746653192[134] = 0;
   out_5168326300746653192[135] = 0;
   out_5168326300746653192[136] = 0;
   out_5168326300746653192[137] = 0;
   out_5168326300746653192[138] = 0;
   out_5168326300746653192[139] = 0;
   out_5168326300746653192[140] = 0;
   out_5168326300746653192[141] = 0;
   out_5168326300746653192[142] = 0;
   out_5168326300746653192[143] = 0;
   out_5168326300746653192[144] = 0;
   out_5168326300746653192[145] = 0;
   out_5168326300746653192[146] = 0;
   out_5168326300746653192[147] = 0;
   out_5168326300746653192[148] = 0;
   out_5168326300746653192[149] = 0;
   out_5168326300746653192[150] = 0;
   out_5168326300746653192[151] = 0;
   out_5168326300746653192[152] = 1;
   out_5168326300746653192[153] = 0;
   out_5168326300746653192[154] = 0;
   out_5168326300746653192[155] = 0;
   out_5168326300746653192[156] = 0;
   out_5168326300746653192[157] = 0;
   out_5168326300746653192[158] = 0;
   out_5168326300746653192[159] = 0;
   out_5168326300746653192[160] = 0;
   out_5168326300746653192[161] = 0;
   out_5168326300746653192[162] = 0;
   out_5168326300746653192[163] = 0;
   out_5168326300746653192[164] = 0;
   out_5168326300746653192[165] = 0;
   out_5168326300746653192[166] = 0;
   out_5168326300746653192[167] = 0;
   out_5168326300746653192[168] = 0;
   out_5168326300746653192[169] = 0;
   out_5168326300746653192[170] = 0;
   out_5168326300746653192[171] = 1;
   out_5168326300746653192[172] = 0;
   out_5168326300746653192[173] = 0;
   out_5168326300746653192[174] = 0;
   out_5168326300746653192[175] = 0;
   out_5168326300746653192[176] = 0;
   out_5168326300746653192[177] = 0;
   out_5168326300746653192[178] = 0;
   out_5168326300746653192[179] = 0;
   out_5168326300746653192[180] = 0;
   out_5168326300746653192[181] = 0;
   out_5168326300746653192[182] = 0;
   out_5168326300746653192[183] = 0;
   out_5168326300746653192[184] = 0;
   out_5168326300746653192[185] = 0;
   out_5168326300746653192[186] = 0;
   out_5168326300746653192[187] = 0;
   out_5168326300746653192[188] = 0;
   out_5168326300746653192[189] = 0;
   out_5168326300746653192[190] = 1;
   out_5168326300746653192[191] = 0;
   out_5168326300746653192[192] = 0;
   out_5168326300746653192[193] = 0;
   out_5168326300746653192[194] = 0;
   out_5168326300746653192[195] = 0;
   out_5168326300746653192[196] = 0;
   out_5168326300746653192[197] = 0;
   out_5168326300746653192[198] = 0;
   out_5168326300746653192[199] = 0;
   out_5168326300746653192[200] = 0;
   out_5168326300746653192[201] = 0;
   out_5168326300746653192[202] = 0;
   out_5168326300746653192[203] = 0;
   out_5168326300746653192[204] = 0;
   out_5168326300746653192[205] = 0;
   out_5168326300746653192[206] = 0;
   out_5168326300746653192[207] = 0;
   out_5168326300746653192[208] = 0;
   out_5168326300746653192[209] = 1;
   out_5168326300746653192[210] = 0;
   out_5168326300746653192[211] = 0;
   out_5168326300746653192[212] = 0;
   out_5168326300746653192[213] = 0;
   out_5168326300746653192[214] = 0;
   out_5168326300746653192[215] = 0;
   out_5168326300746653192[216] = 0;
   out_5168326300746653192[217] = 0;
   out_5168326300746653192[218] = 0;
   out_5168326300746653192[219] = 0;
   out_5168326300746653192[220] = 0;
   out_5168326300746653192[221] = 0;
   out_5168326300746653192[222] = 0;
   out_5168326300746653192[223] = 0;
   out_5168326300746653192[224] = 0;
   out_5168326300746653192[225] = 0;
   out_5168326300746653192[226] = 0;
   out_5168326300746653192[227] = 0;
   out_5168326300746653192[228] = 1;
   out_5168326300746653192[229] = 0;
   out_5168326300746653192[230] = 0;
   out_5168326300746653192[231] = 0;
   out_5168326300746653192[232] = 0;
   out_5168326300746653192[233] = 0;
   out_5168326300746653192[234] = 0;
   out_5168326300746653192[235] = 0;
   out_5168326300746653192[236] = 0;
   out_5168326300746653192[237] = 0;
   out_5168326300746653192[238] = 0;
   out_5168326300746653192[239] = 0;
   out_5168326300746653192[240] = 0;
   out_5168326300746653192[241] = 0;
   out_5168326300746653192[242] = 0;
   out_5168326300746653192[243] = 0;
   out_5168326300746653192[244] = 0;
   out_5168326300746653192[245] = 0;
   out_5168326300746653192[246] = 0;
   out_5168326300746653192[247] = 1;
   out_5168326300746653192[248] = 0;
   out_5168326300746653192[249] = 0;
   out_5168326300746653192[250] = 0;
   out_5168326300746653192[251] = 0;
   out_5168326300746653192[252] = 0;
   out_5168326300746653192[253] = 0;
   out_5168326300746653192[254] = 0;
   out_5168326300746653192[255] = 0;
   out_5168326300746653192[256] = 0;
   out_5168326300746653192[257] = 0;
   out_5168326300746653192[258] = 0;
   out_5168326300746653192[259] = 0;
   out_5168326300746653192[260] = 0;
   out_5168326300746653192[261] = 0;
   out_5168326300746653192[262] = 0;
   out_5168326300746653192[263] = 0;
   out_5168326300746653192[264] = 0;
   out_5168326300746653192[265] = 0;
   out_5168326300746653192[266] = 1;
   out_5168326300746653192[267] = 0;
   out_5168326300746653192[268] = 0;
   out_5168326300746653192[269] = 0;
   out_5168326300746653192[270] = 0;
   out_5168326300746653192[271] = 0;
   out_5168326300746653192[272] = 0;
   out_5168326300746653192[273] = 0;
   out_5168326300746653192[274] = 0;
   out_5168326300746653192[275] = 0;
   out_5168326300746653192[276] = 0;
   out_5168326300746653192[277] = 0;
   out_5168326300746653192[278] = 0;
   out_5168326300746653192[279] = 0;
   out_5168326300746653192[280] = 0;
   out_5168326300746653192[281] = 0;
   out_5168326300746653192[282] = 0;
   out_5168326300746653192[283] = 0;
   out_5168326300746653192[284] = 0;
   out_5168326300746653192[285] = 1;
   out_5168326300746653192[286] = 0;
   out_5168326300746653192[287] = 0;
   out_5168326300746653192[288] = 0;
   out_5168326300746653192[289] = 0;
   out_5168326300746653192[290] = 0;
   out_5168326300746653192[291] = 0;
   out_5168326300746653192[292] = 0;
   out_5168326300746653192[293] = 0;
   out_5168326300746653192[294] = 0;
   out_5168326300746653192[295] = 0;
   out_5168326300746653192[296] = 0;
   out_5168326300746653192[297] = 0;
   out_5168326300746653192[298] = 0;
   out_5168326300746653192[299] = 0;
   out_5168326300746653192[300] = 0;
   out_5168326300746653192[301] = 0;
   out_5168326300746653192[302] = 0;
   out_5168326300746653192[303] = 0;
   out_5168326300746653192[304] = 1;
   out_5168326300746653192[305] = 0;
   out_5168326300746653192[306] = 0;
   out_5168326300746653192[307] = 0;
   out_5168326300746653192[308] = 0;
   out_5168326300746653192[309] = 0;
   out_5168326300746653192[310] = 0;
   out_5168326300746653192[311] = 0;
   out_5168326300746653192[312] = 0;
   out_5168326300746653192[313] = 0;
   out_5168326300746653192[314] = 0;
   out_5168326300746653192[315] = 0;
   out_5168326300746653192[316] = 0;
   out_5168326300746653192[317] = 0;
   out_5168326300746653192[318] = 0;
   out_5168326300746653192[319] = 0;
   out_5168326300746653192[320] = 0;
   out_5168326300746653192[321] = 0;
   out_5168326300746653192[322] = 0;
   out_5168326300746653192[323] = 1;
}
void h_4(double *state, double *unused, double *out_8670716112105694718) {
   out_8670716112105694718[0] = state[6] + state[9];
   out_8670716112105694718[1] = state[7] + state[10];
   out_8670716112105694718[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_1470121245665226494) {
   out_1470121245665226494[0] = 0;
   out_1470121245665226494[1] = 0;
   out_1470121245665226494[2] = 0;
   out_1470121245665226494[3] = 0;
   out_1470121245665226494[4] = 0;
   out_1470121245665226494[5] = 0;
   out_1470121245665226494[6] = 1;
   out_1470121245665226494[7] = 0;
   out_1470121245665226494[8] = 0;
   out_1470121245665226494[9] = 1;
   out_1470121245665226494[10] = 0;
   out_1470121245665226494[11] = 0;
   out_1470121245665226494[12] = 0;
   out_1470121245665226494[13] = 0;
   out_1470121245665226494[14] = 0;
   out_1470121245665226494[15] = 0;
   out_1470121245665226494[16] = 0;
   out_1470121245665226494[17] = 0;
   out_1470121245665226494[18] = 0;
   out_1470121245665226494[19] = 0;
   out_1470121245665226494[20] = 0;
   out_1470121245665226494[21] = 0;
   out_1470121245665226494[22] = 0;
   out_1470121245665226494[23] = 0;
   out_1470121245665226494[24] = 0;
   out_1470121245665226494[25] = 1;
   out_1470121245665226494[26] = 0;
   out_1470121245665226494[27] = 0;
   out_1470121245665226494[28] = 1;
   out_1470121245665226494[29] = 0;
   out_1470121245665226494[30] = 0;
   out_1470121245665226494[31] = 0;
   out_1470121245665226494[32] = 0;
   out_1470121245665226494[33] = 0;
   out_1470121245665226494[34] = 0;
   out_1470121245665226494[35] = 0;
   out_1470121245665226494[36] = 0;
   out_1470121245665226494[37] = 0;
   out_1470121245665226494[38] = 0;
   out_1470121245665226494[39] = 0;
   out_1470121245665226494[40] = 0;
   out_1470121245665226494[41] = 0;
   out_1470121245665226494[42] = 0;
   out_1470121245665226494[43] = 0;
   out_1470121245665226494[44] = 1;
   out_1470121245665226494[45] = 0;
   out_1470121245665226494[46] = 0;
   out_1470121245665226494[47] = 1;
   out_1470121245665226494[48] = 0;
   out_1470121245665226494[49] = 0;
   out_1470121245665226494[50] = 0;
   out_1470121245665226494[51] = 0;
   out_1470121245665226494[52] = 0;
   out_1470121245665226494[53] = 0;
}
void h_10(double *state, double *unused, double *out_6106389642402371296) {
   out_6106389642402371296[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6106389642402371296[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6106389642402371296[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8155893514424523240) {
   out_8155893514424523240[0] = 0;
   out_8155893514424523240[1] = 9.8100000000000005*cos(state[1]);
   out_8155893514424523240[2] = 0;
   out_8155893514424523240[3] = 0;
   out_8155893514424523240[4] = -state[8];
   out_8155893514424523240[5] = state[7];
   out_8155893514424523240[6] = 0;
   out_8155893514424523240[7] = state[5];
   out_8155893514424523240[8] = -state[4];
   out_8155893514424523240[9] = 0;
   out_8155893514424523240[10] = 0;
   out_8155893514424523240[11] = 0;
   out_8155893514424523240[12] = 1;
   out_8155893514424523240[13] = 0;
   out_8155893514424523240[14] = 0;
   out_8155893514424523240[15] = 1;
   out_8155893514424523240[16] = 0;
   out_8155893514424523240[17] = 0;
   out_8155893514424523240[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8155893514424523240[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8155893514424523240[20] = 0;
   out_8155893514424523240[21] = state[8];
   out_8155893514424523240[22] = 0;
   out_8155893514424523240[23] = -state[6];
   out_8155893514424523240[24] = -state[5];
   out_8155893514424523240[25] = 0;
   out_8155893514424523240[26] = state[3];
   out_8155893514424523240[27] = 0;
   out_8155893514424523240[28] = 0;
   out_8155893514424523240[29] = 0;
   out_8155893514424523240[30] = 0;
   out_8155893514424523240[31] = 1;
   out_8155893514424523240[32] = 0;
   out_8155893514424523240[33] = 0;
   out_8155893514424523240[34] = 1;
   out_8155893514424523240[35] = 0;
   out_8155893514424523240[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8155893514424523240[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8155893514424523240[38] = 0;
   out_8155893514424523240[39] = -state[7];
   out_8155893514424523240[40] = state[6];
   out_8155893514424523240[41] = 0;
   out_8155893514424523240[42] = state[4];
   out_8155893514424523240[43] = -state[3];
   out_8155893514424523240[44] = 0;
   out_8155893514424523240[45] = 0;
   out_8155893514424523240[46] = 0;
   out_8155893514424523240[47] = 0;
   out_8155893514424523240[48] = 0;
   out_8155893514424523240[49] = 0;
   out_8155893514424523240[50] = 1;
   out_8155893514424523240[51] = 0;
   out_8155893514424523240[52] = 0;
   out_8155893514424523240[53] = 1;
}
void h_13(double *state, double *unused, double *out_8157156466131107868) {
   out_8157156466131107868[0] = state[3];
   out_8157156466131107868[1] = state[4];
   out_8157156466131107868[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1742152579667106307) {
   out_1742152579667106307[0] = 0;
   out_1742152579667106307[1] = 0;
   out_1742152579667106307[2] = 0;
   out_1742152579667106307[3] = 1;
   out_1742152579667106307[4] = 0;
   out_1742152579667106307[5] = 0;
   out_1742152579667106307[6] = 0;
   out_1742152579667106307[7] = 0;
   out_1742152579667106307[8] = 0;
   out_1742152579667106307[9] = 0;
   out_1742152579667106307[10] = 0;
   out_1742152579667106307[11] = 0;
   out_1742152579667106307[12] = 0;
   out_1742152579667106307[13] = 0;
   out_1742152579667106307[14] = 0;
   out_1742152579667106307[15] = 0;
   out_1742152579667106307[16] = 0;
   out_1742152579667106307[17] = 0;
   out_1742152579667106307[18] = 0;
   out_1742152579667106307[19] = 0;
   out_1742152579667106307[20] = 0;
   out_1742152579667106307[21] = 0;
   out_1742152579667106307[22] = 1;
   out_1742152579667106307[23] = 0;
   out_1742152579667106307[24] = 0;
   out_1742152579667106307[25] = 0;
   out_1742152579667106307[26] = 0;
   out_1742152579667106307[27] = 0;
   out_1742152579667106307[28] = 0;
   out_1742152579667106307[29] = 0;
   out_1742152579667106307[30] = 0;
   out_1742152579667106307[31] = 0;
   out_1742152579667106307[32] = 0;
   out_1742152579667106307[33] = 0;
   out_1742152579667106307[34] = 0;
   out_1742152579667106307[35] = 0;
   out_1742152579667106307[36] = 0;
   out_1742152579667106307[37] = 0;
   out_1742152579667106307[38] = 0;
   out_1742152579667106307[39] = 0;
   out_1742152579667106307[40] = 0;
   out_1742152579667106307[41] = 1;
   out_1742152579667106307[42] = 0;
   out_1742152579667106307[43] = 0;
   out_1742152579667106307[44] = 0;
   out_1742152579667106307[45] = 0;
   out_1742152579667106307[46] = 0;
   out_1742152579667106307[47] = 0;
   out_1742152579667106307[48] = 0;
   out_1742152579667106307[49] = 0;
   out_1742152579667106307[50] = 0;
   out_1742152579667106307[51] = 0;
   out_1742152579667106307[52] = 0;
   out_1742152579667106307[53] = 0;
}
void h_14(double *state, double *unused, double *out_568036792274749064) {
   out_568036792274749064[0] = state[6];
   out_568036792274749064[1] = state[7];
   out_568036792274749064[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4552909677960598790) {
   out_4552909677960598790[0] = 0;
   out_4552909677960598790[1] = 0;
   out_4552909677960598790[2] = 0;
   out_4552909677960598790[3] = 0;
   out_4552909677960598790[4] = 0;
   out_4552909677960598790[5] = 0;
   out_4552909677960598790[6] = 1;
   out_4552909677960598790[7] = 0;
   out_4552909677960598790[8] = 0;
   out_4552909677960598790[9] = 0;
   out_4552909677960598790[10] = 0;
   out_4552909677960598790[11] = 0;
   out_4552909677960598790[12] = 0;
   out_4552909677960598790[13] = 0;
   out_4552909677960598790[14] = 0;
   out_4552909677960598790[15] = 0;
   out_4552909677960598790[16] = 0;
   out_4552909677960598790[17] = 0;
   out_4552909677960598790[18] = 0;
   out_4552909677960598790[19] = 0;
   out_4552909677960598790[20] = 0;
   out_4552909677960598790[21] = 0;
   out_4552909677960598790[22] = 0;
   out_4552909677960598790[23] = 0;
   out_4552909677960598790[24] = 0;
   out_4552909677960598790[25] = 1;
   out_4552909677960598790[26] = 0;
   out_4552909677960598790[27] = 0;
   out_4552909677960598790[28] = 0;
   out_4552909677960598790[29] = 0;
   out_4552909677960598790[30] = 0;
   out_4552909677960598790[31] = 0;
   out_4552909677960598790[32] = 0;
   out_4552909677960598790[33] = 0;
   out_4552909677960598790[34] = 0;
   out_4552909677960598790[35] = 0;
   out_4552909677960598790[36] = 0;
   out_4552909677960598790[37] = 0;
   out_4552909677960598790[38] = 0;
   out_4552909677960598790[39] = 0;
   out_4552909677960598790[40] = 0;
   out_4552909677960598790[41] = 0;
   out_4552909677960598790[42] = 0;
   out_4552909677960598790[43] = 0;
   out_4552909677960598790[44] = 1;
   out_4552909677960598790[45] = 0;
   out_4552909677960598790[46] = 0;
   out_4552909677960598790[47] = 0;
   out_4552909677960598790[48] = 0;
   out_4552909677960598790[49] = 0;
   out_4552909677960598790[50] = 0;
   out_4552909677960598790[51] = 0;
   out_4552909677960598790[52] = 0;
   out_4552909677960598790[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_8259662850093450970) {
  err_fun(nom_x, delta_x, out_8259662850093450970);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7477554158578246383) {
  inv_err_fun(nom_x, true_x, out_7477554158578246383);
}
void pose_H_mod_fun(double *state, double *out_6622639630704307229) {
  H_mod_fun(state, out_6622639630704307229);
}
void pose_f_fun(double *state, double dt, double *out_2747407686181114080) {
  f_fun(state,  dt, out_2747407686181114080);
}
void pose_F_fun(double *state, double dt, double *out_5168326300746653192) {
  F_fun(state,  dt, out_5168326300746653192);
}
void pose_h_4(double *state, double *unused, double *out_8670716112105694718) {
  h_4(state, unused, out_8670716112105694718);
}
void pose_H_4(double *state, double *unused, double *out_1470121245665226494) {
  H_4(state, unused, out_1470121245665226494);
}
void pose_h_10(double *state, double *unused, double *out_6106389642402371296) {
  h_10(state, unused, out_6106389642402371296);
}
void pose_H_10(double *state, double *unused, double *out_8155893514424523240) {
  H_10(state, unused, out_8155893514424523240);
}
void pose_h_13(double *state, double *unused, double *out_8157156466131107868) {
  h_13(state, unused, out_8157156466131107868);
}
void pose_H_13(double *state, double *unused, double *out_1742152579667106307) {
  H_13(state, unused, out_1742152579667106307);
}
void pose_h_14(double *state, double *unused, double *out_568036792274749064) {
  h_14(state, unused, out_568036792274749064);
}
void pose_H_14(double *state, double *unused, double *out_4552909677960598790) {
  H_14(state, unused, out_4552909677960598790);
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
