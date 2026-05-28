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
void err_fun(double *nom_x, double *delta_x, double *out_628539194751276084) {
   out_628539194751276084[0] = delta_x[0] + nom_x[0];
   out_628539194751276084[1] = delta_x[1] + nom_x[1];
   out_628539194751276084[2] = delta_x[2] + nom_x[2];
   out_628539194751276084[3] = delta_x[3] + nom_x[3];
   out_628539194751276084[4] = delta_x[4] + nom_x[4];
   out_628539194751276084[5] = delta_x[5] + nom_x[5];
   out_628539194751276084[6] = delta_x[6] + nom_x[6];
   out_628539194751276084[7] = delta_x[7] + nom_x[7];
   out_628539194751276084[8] = delta_x[8] + nom_x[8];
   out_628539194751276084[9] = delta_x[9] + nom_x[9];
   out_628539194751276084[10] = delta_x[10] + nom_x[10];
   out_628539194751276084[11] = delta_x[11] + nom_x[11];
   out_628539194751276084[12] = delta_x[12] + nom_x[12];
   out_628539194751276084[13] = delta_x[13] + nom_x[13];
   out_628539194751276084[14] = delta_x[14] + nom_x[14];
   out_628539194751276084[15] = delta_x[15] + nom_x[15];
   out_628539194751276084[16] = delta_x[16] + nom_x[16];
   out_628539194751276084[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5785405288888399451) {
   out_5785405288888399451[0] = -nom_x[0] + true_x[0];
   out_5785405288888399451[1] = -nom_x[1] + true_x[1];
   out_5785405288888399451[2] = -nom_x[2] + true_x[2];
   out_5785405288888399451[3] = -nom_x[3] + true_x[3];
   out_5785405288888399451[4] = -nom_x[4] + true_x[4];
   out_5785405288888399451[5] = -nom_x[5] + true_x[5];
   out_5785405288888399451[6] = -nom_x[6] + true_x[6];
   out_5785405288888399451[7] = -nom_x[7] + true_x[7];
   out_5785405288888399451[8] = -nom_x[8] + true_x[8];
   out_5785405288888399451[9] = -nom_x[9] + true_x[9];
   out_5785405288888399451[10] = -nom_x[10] + true_x[10];
   out_5785405288888399451[11] = -nom_x[11] + true_x[11];
   out_5785405288888399451[12] = -nom_x[12] + true_x[12];
   out_5785405288888399451[13] = -nom_x[13] + true_x[13];
   out_5785405288888399451[14] = -nom_x[14] + true_x[14];
   out_5785405288888399451[15] = -nom_x[15] + true_x[15];
   out_5785405288888399451[16] = -nom_x[16] + true_x[16];
   out_5785405288888399451[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1308901075637477725) {
   out_1308901075637477725[0] = 1.0;
   out_1308901075637477725[1] = 0.0;
   out_1308901075637477725[2] = 0.0;
   out_1308901075637477725[3] = 0.0;
   out_1308901075637477725[4] = 0.0;
   out_1308901075637477725[5] = 0.0;
   out_1308901075637477725[6] = 0.0;
   out_1308901075637477725[7] = 0.0;
   out_1308901075637477725[8] = 0.0;
   out_1308901075637477725[9] = 0.0;
   out_1308901075637477725[10] = 0.0;
   out_1308901075637477725[11] = 0.0;
   out_1308901075637477725[12] = 0.0;
   out_1308901075637477725[13] = 0.0;
   out_1308901075637477725[14] = 0.0;
   out_1308901075637477725[15] = 0.0;
   out_1308901075637477725[16] = 0.0;
   out_1308901075637477725[17] = 0.0;
   out_1308901075637477725[18] = 0.0;
   out_1308901075637477725[19] = 1.0;
   out_1308901075637477725[20] = 0.0;
   out_1308901075637477725[21] = 0.0;
   out_1308901075637477725[22] = 0.0;
   out_1308901075637477725[23] = 0.0;
   out_1308901075637477725[24] = 0.0;
   out_1308901075637477725[25] = 0.0;
   out_1308901075637477725[26] = 0.0;
   out_1308901075637477725[27] = 0.0;
   out_1308901075637477725[28] = 0.0;
   out_1308901075637477725[29] = 0.0;
   out_1308901075637477725[30] = 0.0;
   out_1308901075637477725[31] = 0.0;
   out_1308901075637477725[32] = 0.0;
   out_1308901075637477725[33] = 0.0;
   out_1308901075637477725[34] = 0.0;
   out_1308901075637477725[35] = 0.0;
   out_1308901075637477725[36] = 0.0;
   out_1308901075637477725[37] = 0.0;
   out_1308901075637477725[38] = 1.0;
   out_1308901075637477725[39] = 0.0;
   out_1308901075637477725[40] = 0.0;
   out_1308901075637477725[41] = 0.0;
   out_1308901075637477725[42] = 0.0;
   out_1308901075637477725[43] = 0.0;
   out_1308901075637477725[44] = 0.0;
   out_1308901075637477725[45] = 0.0;
   out_1308901075637477725[46] = 0.0;
   out_1308901075637477725[47] = 0.0;
   out_1308901075637477725[48] = 0.0;
   out_1308901075637477725[49] = 0.0;
   out_1308901075637477725[50] = 0.0;
   out_1308901075637477725[51] = 0.0;
   out_1308901075637477725[52] = 0.0;
   out_1308901075637477725[53] = 0.0;
   out_1308901075637477725[54] = 0.0;
   out_1308901075637477725[55] = 0.0;
   out_1308901075637477725[56] = 0.0;
   out_1308901075637477725[57] = 1.0;
   out_1308901075637477725[58] = 0.0;
   out_1308901075637477725[59] = 0.0;
   out_1308901075637477725[60] = 0.0;
   out_1308901075637477725[61] = 0.0;
   out_1308901075637477725[62] = 0.0;
   out_1308901075637477725[63] = 0.0;
   out_1308901075637477725[64] = 0.0;
   out_1308901075637477725[65] = 0.0;
   out_1308901075637477725[66] = 0.0;
   out_1308901075637477725[67] = 0.0;
   out_1308901075637477725[68] = 0.0;
   out_1308901075637477725[69] = 0.0;
   out_1308901075637477725[70] = 0.0;
   out_1308901075637477725[71] = 0.0;
   out_1308901075637477725[72] = 0.0;
   out_1308901075637477725[73] = 0.0;
   out_1308901075637477725[74] = 0.0;
   out_1308901075637477725[75] = 0.0;
   out_1308901075637477725[76] = 1.0;
   out_1308901075637477725[77] = 0.0;
   out_1308901075637477725[78] = 0.0;
   out_1308901075637477725[79] = 0.0;
   out_1308901075637477725[80] = 0.0;
   out_1308901075637477725[81] = 0.0;
   out_1308901075637477725[82] = 0.0;
   out_1308901075637477725[83] = 0.0;
   out_1308901075637477725[84] = 0.0;
   out_1308901075637477725[85] = 0.0;
   out_1308901075637477725[86] = 0.0;
   out_1308901075637477725[87] = 0.0;
   out_1308901075637477725[88] = 0.0;
   out_1308901075637477725[89] = 0.0;
   out_1308901075637477725[90] = 0.0;
   out_1308901075637477725[91] = 0.0;
   out_1308901075637477725[92] = 0.0;
   out_1308901075637477725[93] = 0.0;
   out_1308901075637477725[94] = 0.0;
   out_1308901075637477725[95] = 1.0;
   out_1308901075637477725[96] = 0.0;
   out_1308901075637477725[97] = 0.0;
   out_1308901075637477725[98] = 0.0;
   out_1308901075637477725[99] = 0.0;
   out_1308901075637477725[100] = 0.0;
   out_1308901075637477725[101] = 0.0;
   out_1308901075637477725[102] = 0.0;
   out_1308901075637477725[103] = 0.0;
   out_1308901075637477725[104] = 0.0;
   out_1308901075637477725[105] = 0.0;
   out_1308901075637477725[106] = 0.0;
   out_1308901075637477725[107] = 0.0;
   out_1308901075637477725[108] = 0.0;
   out_1308901075637477725[109] = 0.0;
   out_1308901075637477725[110] = 0.0;
   out_1308901075637477725[111] = 0.0;
   out_1308901075637477725[112] = 0.0;
   out_1308901075637477725[113] = 0.0;
   out_1308901075637477725[114] = 1.0;
   out_1308901075637477725[115] = 0.0;
   out_1308901075637477725[116] = 0.0;
   out_1308901075637477725[117] = 0.0;
   out_1308901075637477725[118] = 0.0;
   out_1308901075637477725[119] = 0.0;
   out_1308901075637477725[120] = 0.0;
   out_1308901075637477725[121] = 0.0;
   out_1308901075637477725[122] = 0.0;
   out_1308901075637477725[123] = 0.0;
   out_1308901075637477725[124] = 0.0;
   out_1308901075637477725[125] = 0.0;
   out_1308901075637477725[126] = 0.0;
   out_1308901075637477725[127] = 0.0;
   out_1308901075637477725[128] = 0.0;
   out_1308901075637477725[129] = 0.0;
   out_1308901075637477725[130] = 0.0;
   out_1308901075637477725[131] = 0.0;
   out_1308901075637477725[132] = 0.0;
   out_1308901075637477725[133] = 1.0;
   out_1308901075637477725[134] = 0.0;
   out_1308901075637477725[135] = 0.0;
   out_1308901075637477725[136] = 0.0;
   out_1308901075637477725[137] = 0.0;
   out_1308901075637477725[138] = 0.0;
   out_1308901075637477725[139] = 0.0;
   out_1308901075637477725[140] = 0.0;
   out_1308901075637477725[141] = 0.0;
   out_1308901075637477725[142] = 0.0;
   out_1308901075637477725[143] = 0.0;
   out_1308901075637477725[144] = 0.0;
   out_1308901075637477725[145] = 0.0;
   out_1308901075637477725[146] = 0.0;
   out_1308901075637477725[147] = 0.0;
   out_1308901075637477725[148] = 0.0;
   out_1308901075637477725[149] = 0.0;
   out_1308901075637477725[150] = 0.0;
   out_1308901075637477725[151] = 0.0;
   out_1308901075637477725[152] = 1.0;
   out_1308901075637477725[153] = 0.0;
   out_1308901075637477725[154] = 0.0;
   out_1308901075637477725[155] = 0.0;
   out_1308901075637477725[156] = 0.0;
   out_1308901075637477725[157] = 0.0;
   out_1308901075637477725[158] = 0.0;
   out_1308901075637477725[159] = 0.0;
   out_1308901075637477725[160] = 0.0;
   out_1308901075637477725[161] = 0.0;
   out_1308901075637477725[162] = 0.0;
   out_1308901075637477725[163] = 0.0;
   out_1308901075637477725[164] = 0.0;
   out_1308901075637477725[165] = 0.0;
   out_1308901075637477725[166] = 0.0;
   out_1308901075637477725[167] = 0.0;
   out_1308901075637477725[168] = 0.0;
   out_1308901075637477725[169] = 0.0;
   out_1308901075637477725[170] = 0.0;
   out_1308901075637477725[171] = 1.0;
   out_1308901075637477725[172] = 0.0;
   out_1308901075637477725[173] = 0.0;
   out_1308901075637477725[174] = 0.0;
   out_1308901075637477725[175] = 0.0;
   out_1308901075637477725[176] = 0.0;
   out_1308901075637477725[177] = 0.0;
   out_1308901075637477725[178] = 0.0;
   out_1308901075637477725[179] = 0.0;
   out_1308901075637477725[180] = 0.0;
   out_1308901075637477725[181] = 0.0;
   out_1308901075637477725[182] = 0.0;
   out_1308901075637477725[183] = 0.0;
   out_1308901075637477725[184] = 0.0;
   out_1308901075637477725[185] = 0.0;
   out_1308901075637477725[186] = 0.0;
   out_1308901075637477725[187] = 0.0;
   out_1308901075637477725[188] = 0.0;
   out_1308901075637477725[189] = 0.0;
   out_1308901075637477725[190] = 1.0;
   out_1308901075637477725[191] = 0.0;
   out_1308901075637477725[192] = 0.0;
   out_1308901075637477725[193] = 0.0;
   out_1308901075637477725[194] = 0.0;
   out_1308901075637477725[195] = 0.0;
   out_1308901075637477725[196] = 0.0;
   out_1308901075637477725[197] = 0.0;
   out_1308901075637477725[198] = 0.0;
   out_1308901075637477725[199] = 0.0;
   out_1308901075637477725[200] = 0.0;
   out_1308901075637477725[201] = 0.0;
   out_1308901075637477725[202] = 0.0;
   out_1308901075637477725[203] = 0.0;
   out_1308901075637477725[204] = 0.0;
   out_1308901075637477725[205] = 0.0;
   out_1308901075637477725[206] = 0.0;
   out_1308901075637477725[207] = 0.0;
   out_1308901075637477725[208] = 0.0;
   out_1308901075637477725[209] = 1.0;
   out_1308901075637477725[210] = 0.0;
   out_1308901075637477725[211] = 0.0;
   out_1308901075637477725[212] = 0.0;
   out_1308901075637477725[213] = 0.0;
   out_1308901075637477725[214] = 0.0;
   out_1308901075637477725[215] = 0.0;
   out_1308901075637477725[216] = 0.0;
   out_1308901075637477725[217] = 0.0;
   out_1308901075637477725[218] = 0.0;
   out_1308901075637477725[219] = 0.0;
   out_1308901075637477725[220] = 0.0;
   out_1308901075637477725[221] = 0.0;
   out_1308901075637477725[222] = 0.0;
   out_1308901075637477725[223] = 0.0;
   out_1308901075637477725[224] = 0.0;
   out_1308901075637477725[225] = 0.0;
   out_1308901075637477725[226] = 0.0;
   out_1308901075637477725[227] = 0.0;
   out_1308901075637477725[228] = 1.0;
   out_1308901075637477725[229] = 0.0;
   out_1308901075637477725[230] = 0.0;
   out_1308901075637477725[231] = 0.0;
   out_1308901075637477725[232] = 0.0;
   out_1308901075637477725[233] = 0.0;
   out_1308901075637477725[234] = 0.0;
   out_1308901075637477725[235] = 0.0;
   out_1308901075637477725[236] = 0.0;
   out_1308901075637477725[237] = 0.0;
   out_1308901075637477725[238] = 0.0;
   out_1308901075637477725[239] = 0.0;
   out_1308901075637477725[240] = 0.0;
   out_1308901075637477725[241] = 0.0;
   out_1308901075637477725[242] = 0.0;
   out_1308901075637477725[243] = 0.0;
   out_1308901075637477725[244] = 0.0;
   out_1308901075637477725[245] = 0.0;
   out_1308901075637477725[246] = 0.0;
   out_1308901075637477725[247] = 1.0;
   out_1308901075637477725[248] = 0.0;
   out_1308901075637477725[249] = 0.0;
   out_1308901075637477725[250] = 0.0;
   out_1308901075637477725[251] = 0.0;
   out_1308901075637477725[252] = 0.0;
   out_1308901075637477725[253] = 0.0;
   out_1308901075637477725[254] = 0.0;
   out_1308901075637477725[255] = 0.0;
   out_1308901075637477725[256] = 0.0;
   out_1308901075637477725[257] = 0.0;
   out_1308901075637477725[258] = 0.0;
   out_1308901075637477725[259] = 0.0;
   out_1308901075637477725[260] = 0.0;
   out_1308901075637477725[261] = 0.0;
   out_1308901075637477725[262] = 0.0;
   out_1308901075637477725[263] = 0.0;
   out_1308901075637477725[264] = 0.0;
   out_1308901075637477725[265] = 0.0;
   out_1308901075637477725[266] = 1.0;
   out_1308901075637477725[267] = 0.0;
   out_1308901075637477725[268] = 0.0;
   out_1308901075637477725[269] = 0.0;
   out_1308901075637477725[270] = 0.0;
   out_1308901075637477725[271] = 0.0;
   out_1308901075637477725[272] = 0.0;
   out_1308901075637477725[273] = 0.0;
   out_1308901075637477725[274] = 0.0;
   out_1308901075637477725[275] = 0.0;
   out_1308901075637477725[276] = 0.0;
   out_1308901075637477725[277] = 0.0;
   out_1308901075637477725[278] = 0.0;
   out_1308901075637477725[279] = 0.0;
   out_1308901075637477725[280] = 0.0;
   out_1308901075637477725[281] = 0.0;
   out_1308901075637477725[282] = 0.0;
   out_1308901075637477725[283] = 0.0;
   out_1308901075637477725[284] = 0.0;
   out_1308901075637477725[285] = 1.0;
   out_1308901075637477725[286] = 0.0;
   out_1308901075637477725[287] = 0.0;
   out_1308901075637477725[288] = 0.0;
   out_1308901075637477725[289] = 0.0;
   out_1308901075637477725[290] = 0.0;
   out_1308901075637477725[291] = 0.0;
   out_1308901075637477725[292] = 0.0;
   out_1308901075637477725[293] = 0.0;
   out_1308901075637477725[294] = 0.0;
   out_1308901075637477725[295] = 0.0;
   out_1308901075637477725[296] = 0.0;
   out_1308901075637477725[297] = 0.0;
   out_1308901075637477725[298] = 0.0;
   out_1308901075637477725[299] = 0.0;
   out_1308901075637477725[300] = 0.0;
   out_1308901075637477725[301] = 0.0;
   out_1308901075637477725[302] = 0.0;
   out_1308901075637477725[303] = 0.0;
   out_1308901075637477725[304] = 1.0;
   out_1308901075637477725[305] = 0.0;
   out_1308901075637477725[306] = 0.0;
   out_1308901075637477725[307] = 0.0;
   out_1308901075637477725[308] = 0.0;
   out_1308901075637477725[309] = 0.0;
   out_1308901075637477725[310] = 0.0;
   out_1308901075637477725[311] = 0.0;
   out_1308901075637477725[312] = 0.0;
   out_1308901075637477725[313] = 0.0;
   out_1308901075637477725[314] = 0.0;
   out_1308901075637477725[315] = 0.0;
   out_1308901075637477725[316] = 0.0;
   out_1308901075637477725[317] = 0.0;
   out_1308901075637477725[318] = 0.0;
   out_1308901075637477725[319] = 0.0;
   out_1308901075637477725[320] = 0.0;
   out_1308901075637477725[321] = 0.0;
   out_1308901075637477725[322] = 0.0;
   out_1308901075637477725[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_8416334481406024670) {
   out_8416334481406024670[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_8416334481406024670[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_8416334481406024670[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_8416334481406024670[3] = dt*state[12] + state[3];
   out_8416334481406024670[4] = dt*state[13] + state[4];
   out_8416334481406024670[5] = dt*state[14] + state[5];
   out_8416334481406024670[6] = state[6];
   out_8416334481406024670[7] = state[7];
   out_8416334481406024670[8] = state[8];
   out_8416334481406024670[9] = state[9];
   out_8416334481406024670[10] = state[10];
   out_8416334481406024670[11] = state[11];
   out_8416334481406024670[12] = state[12];
   out_8416334481406024670[13] = state[13];
   out_8416334481406024670[14] = state[14];
   out_8416334481406024670[15] = state[15];
   out_8416334481406024670[16] = state[16];
   out_8416334481406024670[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5288884962144890875) {
   out_5288884962144890875[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5288884962144890875[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5288884962144890875[2] = 0;
   out_5288884962144890875[3] = 0;
   out_5288884962144890875[4] = 0;
   out_5288884962144890875[5] = 0;
   out_5288884962144890875[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5288884962144890875[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5288884962144890875[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5288884962144890875[9] = 0;
   out_5288884962144890875[10] = 0;
   out_5288884962144890875[11] = 0;
   out_5288884962144890875[12] = 0;
   out_5288884962144890875[13] = 0;
   out_5288884962144890875[14] = 0;
   out_5288884962144890875[15] = 0;
   out_5288884962144890875[16] = 0;
   out_5288884962144890875[17] = 0;
   out_5288884962144890875[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5288884962144890875[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5288884962144890875[20] = 0;
   out_5288884962144890875[21] = 0;
   out_5288884962144890875[22] = 0;
   out_5288884962144890875[23] = 0;
   out_5288884962144890875[24] = 0;
   out_5288884962144890875[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5288884962144890875[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5288884962144890875[27] = 0;
   out_5288884962144890875[28] = 0;
   out_5288884962144890875[29] = 0;
   out_5288884962144890875[30] = 0;
   out_5288884962144890875[31] = 0;
   out_5288884962144890875[32] = 0;
   out_5288884962144890875[33] = 0;
   out_5288884962144890875[34] = 0;
   out_5288884962144890875[35] = 0;
   out_5288884962144890875[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5288884962144890875[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5288884962144890875[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5288884962144890875[39] = 0;
   out_5288884962144890875[40] = 0;
   out_5288884962144890875[41] = 0;
   out_5288884962144890875[42] = 0;
   out_5288884962144890875[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5288884962144890875[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5288884962144890875[45] = 0;
   out_5288884962144890875[46] = 0;
   out_5288884962144890875[47] = 0;
   out_5288884962144890875[48] = 0;
   out_5288884962144890875[49] = 0;
   out_5288884962144890875[50] = 0;
   out_5288884962144890875[51] = 0;
   out_5288884962144890875[52] = 0;
   out_5288884962144890875[53] = 0;
   out_5288884962144890875[54] = 0;
   out_5288884962144890875[55] = 0;
   out_5288884962144890875[56] = 0;
   out_5288884962144890875[57] = 1;
   out_5288884962144890875[58] = 0;
   out_5288884962144890875[59] = 0;
   out_5288884962144890875[60] = 0;
   out_5288884962144890875[61] = 0;
   out_5288884962144890875[62] = 0;
   out_5288884962144890875[63] = 0;
   out_5288884962144890875[64] = 0;
   out_5288884962144890875[65] = 0;
   out_5288884962144890875[66] = dt;
   out_5288884962144890875[67] = 0;
   out_5288884962144890875[68] = 0;
   out_5288884962144890875[69] = 0;
   out_5288884962144890875[70] = 0;
   out_5288884962144890875[71] = 0;
   out_5288884962144890875[72] = 0;
   out_5288884962144890875[73] = 0;
   out_5288884962144890875[74] = 0;
   out_5288884962144890875[75] = 0;
   out_5288884962144890875[76] = 1;
   out_5288884962144890875[77] = 0;
   out_5288884962144890875[78] = 0;
   out_5288884962144890875[79] = 0;
   out_5288884962144890875[80] = 0;
   out_5288884962144890875[81] = 0;
   out_5288884962144890875[82] = 0;
   out_5288884962144890875[83] = 0;
   out_5288884962144890875[84] = 0;
   out_5288884962144890875[85] = dt;
   out_5288884962144890875[86] = 0;
   out_5288884962144890875[87] = 0;
   out_5288884962144890875[88] = 0;
   out_5288884962144890875[89] = 0;
   out_5288884962144890875[90] = 0;
   out_5288884962144890875[91] = 0;
   out_5288884962144890875[92] = 0;
   out_5288884962144890875[93] = 0;
   out_5288884962144890875[94] = 0;
   out_5288884962144890875[95] = 1;
   out_5288884962144890875[96] = 0;
   out_5288884962144890875[97] = 0;
   out_5288884962144890875[98] = 0;
   out_5288884962144890875[99] = 0;
   out_5288884962144890875[100] = 0;
   out_5288884962144890875[101] = 0;
   out_5288884962144890875[102] = 0;
   out_5288884962144890875[103] = 0;
   out_5288884962144890875[104] = dt;
   out_5288884962144890875[105] = 0;
   out_5288884962144890875[106] = 0;
   out_5288884962144890875[107] = 0;
   out_5288884962144890875[108] = 0;
   out_5288884962144890875[109] = 0;
   out_5288884962144890875[110] = 0;
   out_5288884962144890875[111] = 0;
   out_5288884962144890875[112] = 0;
   out_5288884962144890875[113] = 0;
   out_5288884962144890875[114] = 1;
   out_5288884962144890875[115] = 0;
   out_5288884962144890875[116] = 0;
   out_5288884962144890875[117] = 0;
   out_5288884962144890875[118] = 0;
   out_5288884962144890875[119] = 0;
   out_5288884962144890875[120] = 0;
   out_5288884962144890875[121] = 0;
   out_5288884962144890875[122] = 0;
   out_5288884962144890875[123] = 0;
   out_5288884962144890875[124] = 0;
   out_5288884962144890875[125] = 0;
   out_5288884962144890875[126] = 0;
   out_5288884962144890875[127] = 0;
   out_5288884962144890875[128] = 0;
   out_5288884962144890875[129] = 0;
   out_5288884962144890875[130] = 0;
   out_5288884962144890875[131] = 0;
   out_5288884962144890875[132] = 0;
   out_5288884962144890875[133] = 1;
   out_5288884962144890875[134] = 0;
   out_5288884962144890875[135] = 0;
   out_5288884962144890875[136] = 0;
   out_5288884962144890875[137] = 0;
   out_5288884962144890875[138] = 0;
   out_5288884962144890875[139] = 0;
   out_5288884962144890875[140] = 0;
   out_5288884962144890875[141] = 0;
   out_5288884962144890875[142] = 0;
   out_5288884962144890875[143] = 0;
   out_5288884962144890875[144] = 0;
   out_5288884962144890875[145] = 0;
   out_5288884962144890875[146] = 0;
   out_5288884962144890875[147] = 0;
   out_5288884962144890875[148] = 0;
   out_5288884962144890875[149] = 0;
   out_5288884962144890875[150] = 0;
   out_5288884962144890875[151] = 0;
   out_5288884962144890875[152] = 1;
   out_5288884962144890875[153] = 0;
   out_5288884962144890875[154] = 0;
   out_5288884962144890875[155] = 0;
   out_5288884962144890875[156] = 0;
   out_5288884962144890875[157] = 0;
   out_5288884962144890875[158] = 0;
   out_5288884962144890875[159] = 0;
   out_5288884962144890875[160] = 0;
   out_5288884962144890875[161] = 0;
   out_5288884962144890875[162] = 0;
   out_5288884962144890875[163] = 0;
   out_5288884962144890875[164] = 0;
   out_5288884962144890875[165] = 0;
   out_5288884962144890875[166] = 0;
   out_5288884962144890875[167] = 0;
   out_5288884962144890875[168] = 0;
   out_5288884962144890875[169] = 0;
   out_5288884962144890875[170] = 0;
   out_5288884962144890875[171] = 1;
   out_5288884962144890875[172] = 0;
   out_5288884962144890875[173] = 0;
   out_5288884962144890875[174] = 0;
   out_5288884962144890875[175] = 0;
   out_5288884962144890875[176] = 0;
   out_5288884962144890875[177] = 0;
   out_5288884962144890875[178] = 0;
   out_5288884962144890875[179] = 0;
   out_5288884962144890875[180] = 0;
   out_5288884962144890875[181] = 0;
   out_5288884962144890875[182] = 0;
   out_5288884962144890875[183] = 0;
   out_5288884962144890875[184] = 0;
   out_5288884962144890875[185] = 0;
   out_5288884962144890875[186] = 0;
   out_5288884962144890875[187] = 0;
   out_5288884962144890875[188] = 0;
   out_5288884962144890875[189] = 0;
   out_5288884962144890875[190] = 1;
   out_5288884962144890875[191] = 0;
   out_5288884962144890875[192] = 0;
   out_5288884962144890875[193] = 0;
   out_5288884962144890875[194] = 0;
   out_5288884962144890875[195] = 0;
   out_5288884962144890875[196] = 0;
   out_5288884962144890875[197] = 0;
   out_5288884962144890875[198] = 0;
   out_5288884962144890875[199] = 0;
   out_5288884962144890875[200] = 0;
   out_5288884962144890875[201] = 0;
   out_5288884962144890875[202] = 0;
   out_5288884962144890875[203] = 0;
   out_5288884962144890875[204] = 0;
   out_5288884962144890875[205] = 0;
   out_5288884962144890875[206] = 0;
   out_5288884962144890875[207] = 0;
   out_5288884962144890875[208] = 0;
   out_5288884962144890875[209] = 1;
   out_5288884962144890875[210] = 0;
   out_5288884962144890875[211] = 0;
   out_5288884962144890875[212] = 0;
   out_5288884962144890875[213] = 0;
   out_5288884962144890875[214] = 0;
   out_5288884962144890875[215] = 0;
   out_5288884962144890875[216] = 0;
   out_5288884962144890875[217] = 0;
   out_5288884962144890875[218] = 0;
   out_5288884962144890875[219] = 0;
   out_5288884962144890875[220] = 0;
   out_5288884962144890875[221] = 0;
   out_5288884962144890875[222] = 0;
   out_5288884962144890875[223] = 0;
   out_5288884962144890875[224] = 0;
   out_5288884962144890875[225] = 0;
   out_5288884962144890875[226] = 0;
   out_5288884962144890875[227] = 0;
   out_5288884962144890875[228] = 1;
   out_5288884962144890875[229] = 0;
   out_5288884962144890875[230] = 0;
   out_5288884962144890875[231] = 0;
   out_5288884962144890875[232] = 0;
   out_5288884962144890875[233] = 0;
   out_5288884962144890875[234] = 0;
   out_5288884962144890875[235] = 0;
   out_5288884962144890875[236] = 0;
   out_5288884962144890875[237] = 0;
   out_5288884962144890875[238] = 0;
   out_5288884962144890875[239] = 0;
   out_5288884962144890875[240] = 0;
   out_5288884962144890875[241] = 0;
   out_5288884962144890875[242] = 0;
   out_5288884962144890875[243] = 0;
   out_5288884962144890875[244] = 0;
   out_5288884962144890875[245] = 0;
   out_5288884962144890875[246] = 0;
   out_5288884962144890875[247] = 1;
   out_5288884962144890875[248] = 0;
   out_5288884962144890875[249] = 0;
   out_5288884962144890875[250] = 0;
   out_5288884962144890875[251] = 0;
   out_5288884962144890875[252] = 0;
   out_5288884962144890875[253] = 0;
   out_5288884962144890875[254] = 0;
   out_5288884962144890875[255] = 0;
   out_5288884962144890875[256] = 0;
   out_5288884962144890875[257] = 0;
   out_5288884962144890875[258] = 0;
   out_5288884962144890875[259] = 0;
   out_5288884962144890875[260] = 0;
   out_5288884962144890875[261] = 0;
   out_5288884962144890875[262] = 0;
   out_5288884962144890875[263] = 0;
   out_5288884962144890875[264] = 0;
   out_5288884962144890875[265] = 0;
   out_5288884962144890875[266] = 1;
   out_5288884962144890875[267] = 0;
   out_5288884962144890875[268] = 0;
   out_5288884962144890875[269] = 0;
   out_5288884962144890875[270] = 0;
   out_5288884962144890875[271] = 0;
   out_5288884962144890875[272] = 0;
   out_5288884962144890875[273] = 0;
   out_5288884962144890875[274] = 0;
   out_5288884962144890875[275] = 0;
   out_5288884962144890875[276] = 0;
   out_5288884962144890875[277] = 0;
   out_5288884962144890875[278] = 0;
   out_5288884962144890875[279] = 0;
   out_5288884962144890875[280] = 0;
   out_5288884962144890875[281] = 0;
   out_5288884962144890875[282] = 0;
   out_5288884962144890875[283] = 0;
   out_5288884962144890875[284] = 0;
   out_5288884962144890875[285] = 1;
   out_5288884962144890875[286] = 0;
   out_5288884962144890875[287] = 0;
   out_5288884962144890875[288] = 0;
   out_5288884962144890875[289] = 0;
   out_5288884962144890875[290] = 0;
   out_5288884962144890875[291] = 0;
   out_5288884962144890875[292] = 0;
   out_5288884962144890875[293] = 0;
   out_5288884962144890875[294] = 0;
   out_5288884962144890875[295] = 0;
   out_5288884962144890875[296] = 0;
   out_5288884962144890875[297] = 0;
   out_5288884962144890875[298] = 0;
   out_5288884962144890875[299] = 0;
   out_5288884962144890875[300] = 0;
   out_5288884962144890875[301] = 0;
   out_5288884962144890875[302] = 0;
   out_5288884962144890875[303] = 0;
   out_5288884962144890875[304] = 1;
   out_5288884962144890875[305] = 0;
   out_5288884962144890875[306] = 0;
   out_5288884962144890875[307] = 0;
   out_5288884962144890875[308] = 0;
   out_5288884962144890875[309] = 0;
   out_5288884962144890875[310] = 0;
   out_5288884962144890875[311] = 0;
   out_5288884962144890875[312] = 0;
   out_5288884962144890875[313] = 0;
   out_5288884962144890875[314] = 0;
   out_5288884962144890875[315] = 0;
   out_5288884962144890875[316] = 0;
   out_5288884962144890875[317] = 0;
   out_5288884962144890875[318] = 0;
   out_5288884962144890875[319] = 0;
   out_5288884962144890875[320] = 0;
   out_5288884962144890875[321] = 0;
   out_5288884962144890875[322] = 0;
   out_5288884962144890875[323] = 1;
}
void h_4(double *state, double *unused, double *out_90872324407998874) {
   out_90872324407998874[0] = state[6] + state[9];
   out_90872324407998874[1] = state[7] + state[10];
   out_90872324407998874[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7635460590420343617) {
   out_7635460590420343617[0] = 0;
   out_7635460590420343617[1] = 0;
   out_7635460590420343617[2] = 0;
   out_7635460590420343617[3] = 0;
   out_7635460590420343617[4] = 0;
   out_7635460590420343617[5] = 0;
   out_7635460590420343617[6] = 1;
   out_7635460590420343617[7] = 0;
   out_7635460590420343617[8] = 0;
   out_7635460590420343617[9] = 1;
   out_7635460590420343617[10] = 0;
   out_7635460590420343617[11] = 0;
   out_7635460590420343617[12] = 0;
   out_7635460590420343617[13] = 0;
   out_7635460590420343617[14] = 0;
   out_7635460590420343617[15] = 0;
   out_7635460590420343617[16] = 0;
   out_7635460590420343617[17] = 0;
   out_7635460590420343617[18] = 0;
   out_7635460590420343617[19] = 0;
   out_7635460590420343617[20] = 0;
   out_7635460590420343617[21] = 0;
   out_7635460590420343617[22] = 0;
   out_7635460590420343617[23] = 0;
   out_7635460590420343617[24] = 0;
   out_7635460590420343617[25] = 1;
   out_7635460590420343617[26] = 0;
   out_7635460590420343617[27] = 0;
   out_7635460590420343617[28] = 1;
   out_7635460590420343617[29] = 0;
   out_7635460590420343617[30] = 0;
   out_7635460590420343617[31] = 0;
   out_7635460590420343617[32] = 0;
   out_7635460590420343617[33] = 0;
   out_7635460590420343617[34] = 0;
   out_7635460590420343617[35] = 0;
   out_7635460590420343617[36] = 0;
   out_7635460590420343617[37] = 0;
   out_7635460590420343617[38] = 0;
   out_7635460590420343617[39] = 0;
   out_7635460590420343617[40] = 0;
   out_7635460590420343617[41] = 0;
   out_7635460590420343617[42] = 0;
   out_7635460590420343617[43] = 0;
   out_7635460590420343617[44] = 1;
   out_7635460590420343617[45] = 0;
   out_7635460590420343617[46] = 0;
   out_7635460590420343617[47] = 1;
   out_7635460590420343617[48] = 0;
   out_7635460590420343617[49] = 0;
   out_7635460590420343617[50] = 0;
   out_7635460590420343617[51] = 0;
   out_7635460590420343617[52] = 0;
   out_7635460590420343617[53] = 0;
}
void h_10(double *state, double *unused, double *out_729559215867171711) {
   out_729559215867171711[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_729559215867171711[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_729559215867171711[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4724811786445925588) {
   out_4724811786445925588[0] = 0;
   out_4724811786445925588[1] = 9.8100000000000005*cos(state[1]);
   out_4724811786445925588[2] = 0;
   out_4724811786445925588[3] = 0;
   out_4724811786445925588[4] = -state[8];
   out_4724811786445925588[5] = state[7];
   out_4724811786445925588[6] = 0;
   out_4724811786445925588[7] = state[5];
   out_4724811786445925588[8] = -state[4];
   out_4724811786445925588[9] = 0;
   out_4724811786445925588[10] = 0;
   out_4724811786445925588[11] = 0;
   out_4724811786445925588[12] = 1;
   out_4724811786445925588[13] = 0;
   out_4724811786445925588[14] = 0;
   out_4724811786445925588[15] = 1;
   out_4724811786445925588[16] = 0;
   out_4724811786445925588[17] = 0;
   out_4724811786445925588[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4724811786445925588[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4724811786445925588[20] = 0;
   out_4724811786445925588[21] = state[8];
   out_4724811786445925588[22] = 0;
   out_4724811786445925588[23] = -state[6];
   out_4724811786445925588[24] = -state[5];
   out_4724811786445925588[25] = 0;
   out_4724811786445925588[26] = state[3];
   out_4724811786445925588[27] = 0;
   out_4724811786445925588[28] = 0;
   out_4724811786445925588[29] = 0;
   out_4724811786445925588[30] = 0;
   out_4724811786445925588[31] = 1;
   out_4724811786445925588[32] = 0;
   out_4724811786445925588[33] = 0;
   out_4724811786445925588[34] = 1;
   out_4724811786445925588[35] = 0;
   out_4724811786445925588[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4724811786445925588[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4724811786445925588[38] = 0;
   out_4724811786445925588[39] = -state[7];
   out_4724811786445925588[40] = state[6];
   out_4724811786445925588[41] = 0;
   out_4724811786445925588[42] = state[4];
   out_4724811786445925588[43] = -state[3];
   out_4724811786445925588[44] = 0;
   out_4724811786445925588[45] = 0;
   out_4724811786445925588[46] = 0;
   out_4724811786445925588[47] = 0;
   out_4724811786445925588[48] = 0;
   out_4724811786445925588[49] = 0;
   out_4724811786445925588[50] = 1;
   out_4724811786445925588[51] = 0;
   out_4724811786445925588[52] = 0;
   out_4724811786445925588[53] = 1;
}
void h_13(double *state, double *unused, double *out_6088791521295825946) {
   out_6088791521295825946[0] = state[3];
   out_6088791521295825946[1] = state[4];
   out_6088791521295825946[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4423186765088010816) {
   out_4423186765088010816[0] = 0;
   out_4423186765088010816[1] = 0;
   out_4423186765088010816[2] = 0;
   out_4423186765088010816[3] = 1;
   out_4423186765088010816[4] = 0;
   out_4423186765088010816[5] = 0;
   out_4423186765088010816[6] = 0;
   out_4423186765088010816[7] = 0;
   out_4423186765088010816[8] = 0;
   out_4423186765088010816[9] = 0;
   out_4423186765088010816[10] = 0;
   out_4423186765088010816[11] = 0;
   out_4423186765088010816[12] = 0;
   out_4423186765088010816[13] = 0;
   out_4423186765088010816[14] = 0;
   out_4423186765088010816[15] = 0;
   out_4423186765088010816[16] = 0;
   out_4423186765088010816[17] = 0;
   out_4423186765088010816[18] = 0;
   out_4423186765088010816[19] = 0;
   out_4423186765088010816[20] = 0;
   out_4423186765088010816[21] = 0;
   out_4423186765088010816[22] = 1;
   out_4423186765088010816[23] = 0;
   out_4423186765088010816[24] = 0;
   out_4423186765088010816[25] = 0;
   out_4423186765088010816[26] = 0;
   out_4423186765088010816[27] = 0;
   out_4423186765088010816[28] = 0;
   out_4423186765088010816[29] = 0;
   out_4423186765088010816[30] = 0;
   out_4423186765088010816[31] = 0;
   out_4423186765088010816[32] = 0;
   out_4423186765088010816[33] = 0;
   out_4423186765088010816[34] = 0;
   out_4423186765088010816[35] = 0;
   out_4423186765088010816[36] = 0;
   out_4423186765088010816[37] = 0;
   out_4423186765088010816[38] = 0;
   out_4423186765088010816[39] = 0;
   out_4423186765088010816[40] = 0;
   out_4423186765088010816[41] = 1;
   out_4423186765088010816[42] = 0;
   out_4423186765088010816[43] = 0;
   out_4423186765088010816[44] = 0;
   out_4423186765088010816[45] = 0;
   out_4423186765088010816[46] = 0;
   out_4423186765088010816[47] = 0;
   out_4423186765088010816[48] = 0;
   out_4423186765088010816[49] = 0;
   out_4423186765088010816[50] = 0;
   out_4423186765088010816[51] = 0;
   out_4423186765088010816[52] = 0;
   out_4423186765088010816[53] = 0;
}
void h_14(double *state, double *unused, double *out_1848639786756728796) {
   out_1848639786756728796[0] = state[6];
   out_1848639786756728796[1] = state[7];
   out_1848639786756728796[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7728495050993835703) {
   out_7728495050993835703[0] = 0;
   out_7728495050993835703[1] = 0;
   out_7728495050993835703[2] = 0;
   out_7728495050993835703[3] = 0;
   out_7728495050993835703[4] = 0;
   out_7728495050993835703[5] = 0;
   out_7728495050993835703[6] = 1;
   out_7728495050993835703[7] = 0;
   out_7728495050993835703[8] = 0;
   out_7728495050993835703[9] = 0;
   out_7728495050993835703[10] = 0;
   out_7728495050993835703[11] = 0;
   out_7728495050993835703[12] = 0;
   out_7728495050993835703[13] = 0;
   out_7728495050993835703[14] = 0;
   out_7728495050993835703[15] = 0;
   out_7728495050993835703[16] = 0;
   out_7728495050993835703[17] = 0;
   out_7728495050993835703[18] = 0;
   out_7728495050993835703[19] = 0;
   out_7728495050993835703[20] = 0;
   out_7728495050993835703[21] = 0;
   out_7728495050993835703[22] = 0;
   out_7728495050993835703[23] = 0;
   out_7728495050993835703[24] = 0;
   out_7728495050993835703[25] = 1;
   out_7728495050993835703[26] = 0;
   out_7728495050993835703[27] = 0;
   out_7728495050993835703[28] = 0;
   out_7728495050993835703[29] = 0;
   out_7728495050993835703[30] = 0;
   out_7728495050993835703[31] = 0;
   out_7728495050993835703[32] = 0;
   out_7728495050993835703[33] = 0;
   out_7728495050993835703[34] = 0;
   out_7728495050993835703[35] = 0;
   out_7728495050993835703[36] = 0;
   out_7728495050993835703[37] = 0;
   out_7728495050993835703[38] = 0;
   out_7728495050993835703[39] = 0;
   out_7728495050993835703[40] = 0;
   out_7728495050993835703[41] = 0;
   out_7728495050993835703[42] = 0;
   out_7728495050993835703[43] = 0;
   out_7728495050993835703[44] = 1;
   out_7728495050993835703[45] = 0;
   out_7728495050993835703[46] = 0;
   out_7728495050993835703[47] = 0;
   out_7728495050993835703[48] = 0;
   out_7728495050993835703[49] = 0;
   out_7728495050993835703[50] = 0;
   out_7728495050993835703[51] = 0;
   out_7728495050993835703[52] = 0;
   out_7728495050993835703[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_628539194751276084) {
  err_fun(nom_x, delta_x, out_628539194751276084);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5785405288888399451) {
  inv_err_fun(nom_x, true_x, out_5785405288888399451);
}
void pose_H_mod_fun(double *state, double *out_1308901075637477725) {
  H_mod_fun(state, out_1308901075637477725);
}
void pose_f_fun(double *state, double dt, double *out_8416334481406024670) {
  f_fun(state,  dt, out_8416334481406024670);
}
void pose_F_fun(double *state, double dt, double *out_5288884962144890875) {
  F_fun(state,  dt, out_5288884962144890875);
}
void pose_h_4(double *state, double *unused, double *out_90872324407998874) {
  h_4(state, unused, out_90872324407998874);
}
void pose_H_4(double *state, double *unused, double *out_7635460590420343617) {
  H_4(state, unused, out_7635460590420343617);
}
void pose_h_10(double *state, double *unused, double *out_729559215867171711) {
  h_10(state, unused, out_729559215867171711);
}
void pose_H_10(double *state, double *unused, double *out_4724811786445925588) {
  H_10(state, unused, out_4724811786445925588);
}
void pose_h_13(double *state, double *unused, double *out_6088791521295825946) {
  h_13(state, unused, out_6088791521295825946);
}
void pose_H_13(double *state, double *unused, double *out_4423186765088010816) {
  H_13(state, unused, out_4423186765088010816);
}
void pose_h_14(double *state, double *unused, double *out_1848639786756728796) {
  h_14(state, unused, out_1848639786756728796);
}
void pose_H_14(double *state, double *unused, double *out_7728495050993835703) {
  H_14(state, unused, out_7728495050993835703);
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
