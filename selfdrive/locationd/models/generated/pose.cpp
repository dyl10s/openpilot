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
void err_fun(double *nom_x, double *delta_x, double *out_3574067617578089570) {
   out_3574067617578089570[0] = delta_x[0] + nom_x[0];
   out_3574067617578089570[1] = delta_x[1] + nom_x[1];
   out_3574067617578089570[2] = delta_x[2] + nom_x[2];
   out_3574067617578089570[3] = delta_x[3] + nom_x[3];
   out_3574067617578089570[4] = delta_x[4] + nom_x[4];
   out_3574067617578089570[5] = delta_x[5] + nom_x[5];
   out_3574067617578089570[6] = delta_x[6] + nom_x[6];
   out_3574067617578089570[7] = delta_x[7] + nom_x[7];
   out_3574067617578089570[8] = delta_x[8] + nom_x[8];
   out_3574067617578089570[9] = delta_x[9] + nom_x[9];
   out_3574067617578089570[10] = delta_x[10] + nom_x[10];
   out_3574067617578089570[11] = delta_x[11] + nom_x[11];
   out_3574067617578089570[12] = delta_x[12] + nom_x[12];
   out_3574067617578089570[13] = delta_x[13] + nom_x[13];
   out_3574067617578089570[14] = delta_x[14] + nom_x[14];
   out_3574067617578089570[15] = delta_x[15] + nom_x[15];
   out_3574067617578089570[16] = delta_x[16] + nom_x[16];
   out_3574067617578089570[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1515328263168530495) {
   out_1515328263168530495[0] = -nom_x[0] + true_x[0];
   out_1515328263168530495[1] = -nom_x[1] + true_x[1];
   out_1515328263168530495[2] = -nom_x[2] + true_x[2];
   out_1515328263168530495[3] = -nom_x[3] + true_x[3];
   out_1515328263168530495[4] = -nom_x[4] + true_x[4];
   out_1515328263168530495[5] = -nom_x[5] + true_x[5];
   out_1515328263168530495[6] = -nom_x[6] + true_x[6];
   out_1515328263168530495[7] = -nom_x[7] + true_x[7];
   out_1515328263168530495[8] = -nom_x[8] + true_x[8];
   out_1515328263168530495[9] = -nom_x[9] + true_x[9];
   out_1515328263168530495[10] = -nom_x[10] + true_x[10];
   out_1515328263168530495[11] = -nom_x[11] + true_x[11];
   out_1515328263168530495[12] = -nom_x[12] + true_x[12];
   out_1515328263168530495[13] = -nom_x[13] + true_x[13];
   out_1515328263168530495[14] = -nom_x[14] + true_x[14];
   out_1515328263168530495[15] = -nom_x[15] + true_x[15];
   out_1515328263168530495[16] = -nom_x[16] + true_x[16];
   out_1515328263168530495[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_207229337745545750) {
   out_207229337745545750[0] = 1.0;
   out_207229337745545750[1] = 0.0;
   out_207229337745545750[2] = 0.0;
   out_207229337745545750[3] = 0.0;
   out_207229337745545750[4] = 0.0;
   out_207229337745545750[5] = 0.0;
   out_207229337745545750[6] = 0.0;
   out_207229337745545750[7] = 0.0;
   out_207229337745545750[8] = 0.0;
   out_207229337745545750[9] = 0.0;
   out_207229337745545750[10] = 0.0;
   out_207229337745545750[11] = 0.0;
   out_207229337745545750[12] = 0.0;
   out_207229337745545750[13] = 0.0;
   out_207229337745545750[14] = 0.0;
   out_207229337745545750[15] = 0.0;
   out_207229337745545750[16] = 0.0;
   out_207229337745545750[17] = 0.0;
   out_207229337745545750[18] = 0.0;
   out_207229337745545750[19] = 1.0;
   out_207229337745545750[20] = 0.0;
   out_207229337745545750[21] = 0.0;
   out_207229337745545750[22] = 0.0;
   out_207229337745545750[23] = 0.0;
   out_207229337745545750[24] = 0.0;
   out_207229337745545750[25] = 0.0;
   out_207229337745545750[26] = 0.0;
   out_207229337745545750[27] = 0.0;
   out_207229337745545750[28] = 0.0;
   out_207229337745545750[29] = 0.0;
   out_207229337745545750[30] = 0.0;
   out_207229337745545750[31] = 0.0;
   out_207229337745545750[32] = 0.0;
   out_207229337745545750[33] = 0.0;
   out_207229337745545750[34] = 0.0;
   out_207229337745545750[35] = 0.0;
   out_207229337745545750[36] = 0.0;
   out_207229337745545750[37] = 0.0;
   out_207229337745545750[38] = 1.0;
   out_207229337745545750[39] = 0.0;
   out_207229337745545750[40] = 0.0;
   out_207229337745545750[41] = 0.0;
   out_207229337745545750[42] = 0.0;
   out_207229337745545750[43] = 0.0;
   out_207229337745545750[44] = 0.0;
   out_207229337745545750[45] = 0.0;
   out_207229337745545750[46] = 0.0;
   out_207229337745545750[47] = 0.0;
   out_207229337745545750[48] = 0.0;
   out_207229337745545750[49] = 0.0;
   out_207229337745545750[50] = 0.0;
   out_207229337745545750[51] = 0.0;
   out_207229337745545750[52] = 0.0;
   out_207229337745545750[53] = 0.0;
   out_207229337745545750[54] = 0.0;
   out_207229337745545750[55] = 0.0;
   out_207229337745545750[56] = 0.0;
   out_207229337745545750[57] = 1.0;
   out_207229337745545750[58] = 0.0;
   out_207229337745545750[59] = 0.0;
   out_207229337745545750[60] = 0.0;
   out_207229337745545750[61] = 0.0;
   out_207229337745545750[62] = 0.0;
   out_207229337745545750[63] = 0.0;
   out_207229337745545750[64] = 0.0;
   out_207229337745545750[65] = 0.0;
   out_207229337745545750[66] = 0.0;
   out_207229337745545750[67] = 0.0;
   out_207229337745545750[68] = 0.0;
   out_207229337745545750[69] = 0.0;
   out_207229337745545750[70] = 0.0;
   out_207229337745545750[71] = 0.0;
   out_207229337745545750[72] = 0.0;
   out_207229337745545750[73] = 0.0;
   out_207229337745545750[74] = 0.0;
   out_207229337745545750[75] = 0.0;
   out_207229337745545750[76] = 1.0;
   out_207229337745545750[77] = 0.0;
   out_207229337745545750[78] = 0.0;
   out_207229337745545750[79] = 0.0;
   out_207229337745545750[80] = 0.0;
   out_207229337745545750[81] = 0.0;
   out_207229337745545750[82] = 0.0;
   out_207229337745545750[83] = 0.0;
   out_207229337745545750[84] = 0.0;
   out_207229337745545750[85] = 0.0;
   out_207229337745545750[86] = 0.0;
   out_207229337745545750[87] = 0.0;
   out_207229337745545750[88] = 0.0;
   out_207229337745545750[89] = 0.0;
   out_207229337745545750[90] = 0.0;
   out_207229337745545750[91] = 0.0;
   out_207229337745545750[92] = 0.0;
   out_207229337745545750[93] = 0.0;
   out_207229337745545750[94] = 0.0;
   out_207229337745545750[95] = 1.0;
   out_207229337745545750[96] = 0.0;
   out_207229337745545750[97] = 0.0;
   out_207229337745545750[98] = 0.0;
   out_207229337745545750[99] = 0.0;
   out_207229337745545750[100] = 0.0;
   out_207229337745545750[101] = 0.0;
   out_207229337745545750[102] = 0.0;
   out_207229337745545750[103] = 0.0;
   out_207229337745545750[104] = 0.0;
   out_207229337745545750[105] = 0.0;
   out_207229337745545750[106] = 0.0;
   out_207229337745545750[107] = 0.0;
   out_207229337745545750[108] = 0.0;
   out_207229337745545750[109] = 0.0;
   out_207229337745545750[110] = 0.0;
   out_207229337745545750[111] = 0.0;
   out_207229337745545750[112] = 0.0;
   out_207229337745545750[113] = 0.0;
   out_207229337745545750[114] = 1.0;
   out_207229337745545750[115] = 0.0;
   out_207229337745545750[116] = 0.0;
   out_207229337745545750[117] = 0.0;
   out_207229337745545750[118] = 0.0;
   out_207229337745545750[119] = 0.0;
   out_207229337745545750[120] = 0.0;
   out_207229337745545750[121] = 0.0;
   out_207229337745545750[122] = 0.0;
   out_207229337745545750[123] = 0.0;
   out_207229337745545750[124] = 0.0;
   out_207229337745545750[125] = 0.0;
   out_207229337745545750[126] = 0.0;
   out_207229337745545750[127] = 0.0;
   out_207229337745545750[128] = 0.0;
   out_207229337745545750[129] = 0.0;
   out_207229337745545750[130] = 0.0;
   out_207229337745545750[131] = 0.0;
   out_207229337745545750[132] = 0.0;
   out_207229337745545750[133] = 1.0;
   out_207229337745545750[134] = 0.0;
   out_207229337745545750[135] = 0.0;
   out_207229337745545750[136] = 0.0;
   out_207229337745545750[137] = 0.0;
   out_207229337745545750[138] = 0.0;
   out_207229337745545750[139] = 0.0;
   out_207229337745545750[140] = 0.0;
   out_207229337745545750[141] = 0.0;
   out_207229337745545750[142] = 0.0;
   out_207229337745545750[143] = 0.0;
   out_207229337745545750[144] = 0.0;
   out_207229337745545750[145] = 0.0;
   out_207229337745545750[146] = 0.0;
   out_207229337745545750[147] = 0.0;
   out_207229337745545750[148] = 0.0;
   out_207229337745545750[149] = 0.0;
   out_207229337745545750[150] = 0.0;
   out_207229337745545750[151] = 0.0;
   out_207229337745545750[152] = 1.0;
   out_207229337745545750[153] = 0.0;
   out_207229337745545750[154] = 0.0;
   out_207229337745545750[155] = 0.0;
   out_207229337745545750[156] = 0.0;
   out_207229337745545750[157] = 0.0;
   out_207229337745545750[158] = 0.0;
   out_207229337745545750[159] = 0.0;
   out_207229337745545750[160] = 0.0;
   out_207229337745545750[161] = 0.0;
   out_207229337745545750[162] = 0.0;
   out_207229337745545750[163] = 0.0;
   out_207229337745545750[164] = 0.0;
   out_207229337745545750[165] = 0.0;
   out_207229337745545750[166] = 0.0;
   out_207229337745545750[167] = 0.0;
   out_207229337745545750[168] = 0.0;
   out_207229337745545750[169] = 0.0;
   out_207229337745545750[170] = 0.0;
   out_207229337745545750[171] = 1.0;
   out_207229337745545750[172] = 0.0;
   out_207229337745545750[173] = 0.0;
   out_207229337745545750[174] = 0.0;
   out_207229337745545750[175] = 0.0;
   out_207229337745545750[176] = 0.0;
   out_207229337745545750[177] = 0.0;
   out_207229337745545750[178] = 0.0;
   out_207229337745545750[179] = 0.0;
   out_207229337745545750[180] = 0.0;
   out_207229337745545750[181] = 0.0;
   out_207229337745545750[182] = 0.0;
   out_207229337745545750[183] = 0.0;
   out_207229337745545750[184] = 0.0;
   out_207229337745545750[185] = 0.0;
   out_207229337745545750[186] = 0.0;
   out_207229337745545750[187] = 0.0;
   out_207229337745545750[188] = 0.0;
   out_207229337745545750[189] = 0.0;
   out_207229337745545750[190] = 1.0;
   out_207229337745545750[191] = 0.0;
   out_207229337745545750[192] = 0.0;
   out_207229337745545750[193] = 0.0;
   out_207229337745545750[194] = 0.0;
   out_207229337745545750[195] = 0.0;
   out_207229337745545750[196] = 0.0;
   out_207229337745545750[197] = 0.0;
   out_207229337745545750[198] = 0.0;
   out_207229337745545750[199] = 0.0;
   out_207229337745545750[200] = 0.0;
   out_207229337745545750[201] = 0.0;
   out_207229337745545750[202] = 0.0;
   out_207229337745545750[203] = 0.0;
   out_207229337745545750[204] = 0.0;
   out_207229337745545750[205] = 0.0;
   out_207229337745545750[206] = 0.0;
   out_207229337745545750[207] = 0.0;
   out_207229337745545750[208] = 0.0;
   out_207229337745545750[209] = 1.0;
   out_207229337745545750[210] = 0.0;
   out_207229337745545750[211] = 0.0;
   out_207229337745545750[212] = 0.0;
   out_207229337745545750[213] = 0.0;
   out_207229337745545750[214] = 0.0;
   out_207229337745545750[215] = 0.0;
   out_207229337745545750[216] = 0.0;
   out_207229337745545750[217] = 0.0;
   out_207229337745545750[218] = 0.0;
   out_207229337745545750[219] = 0.0;
   out_207229337745545750[220] = 0.0;
   out_207229337745545750[221] = 0.0;
   out_207229337745545750[222] = 0.0;
   out_207229337745545750[223] = 0.0;
   out_207229337745545750[224] = 0.0;
   out_207229337745545750[225] = 0.0;
   out_207229337745545750[226] = 0.0;
   out_207229337745545750[227] = 0.0;
   out_207229337745545750[228] = 1.0;
   out_207229337745545750[229] = 0.0;
   out_207229337745545750[230] = 0.0;
   out_207229337745545750[231] = 0.0;
   out_207229337745545750[232] = 0.0;
   out_207229337745545750[233] = 0.0;
   out_207229337745545750[234] = 0.0;
   out_207229337745545750[235] = 0.0;
   out_207229337745545750[236] = 0.0;
   out_207229337745545750[237] = 0.0;
   out_207229337745545750[238] = 0.0;
   out_207229337745545750[239] = 0.0;
   out_207229337745545750[240] = 0.0;
   out_207229337745545750[241] = 0.0;
   out_207229337745545750[242] = 0.0;
   out_207229337745545750[243] = 0.0;
   out_207229337745545750[244] = 0.0;
   out_207229337745545750[245] = 0.0;
   out_207229337745545750[246] = 0.0;
   out_207229337745545750[247] = 1.0;
   out_207229337745545750[248] = 0.0;
   out_207229337745545750[249] = 0.0;
   out_207229337745545750[250] = 0.0;
   out_207229337745545750[251] = 0.0;
   out_207229337745545750[252] = 0.0;
   out_207229337745545750[253] = 0.0;
   out_207229337745545750[254] = 0.0;
   out_207229337745545750[255] = 0.0;
   out_207229337745545750[256] = 0.0;
   out_207229337745545750[257] = 0.0;
   out_207229337745545750[258] = 0.0;
   out_207229337745545750[259] = 0.0;
   out_207229337745545750[260] = 0.0;
   out_207229337745545750[261] = 0.0;
   out_207229337745545750[262] = 0.0;
   out_207229337745545750[263] = 0.0;
   out_207229337745545750[264] = 0.0;
   out_207229337745545750[265] = 0.0;
   out_207229337745545750[266] = 1.0;
   out_207229337745545750[267] = 0.0;
   out_207229337745545750[268] = 0.0;
   out_207229337745545750[269] = 0.0;
   out_207229337745545750[270] = 0.0;
   out_207229337745545750[271] = 0.0;
   out_207229337745545750[272] = 0.0;
   out_207229337745545750[273] = 0.0;
   out_207229337745545750[274] = 0.0;
   out_207229337745545750[275] = 0.0;
   out_207229337745545750[276] = 0.0;
   out_207229337745545750[277] = 0.0;
   out_207229337745545750[278] = 0.0;
   out_207229337745545750[279] = 0.0;
   out_207229337745545750[280] = 0.0;
   out_207229337745545750[281] = 0.0;
   out_207229337745545750[282] = 0.0;
   out_207229337745545750[283] = 0.0;
   out_207229337745545750[284] = 0.0;
   out_207229337745545750[285] = 1.0;
   out_207229337745545750[286] = 0.0;
   out_207229337745545750[287] = 0.0;
   out_207229337745545750[288] = 0.0;
   out_207229337745545750[289] = 0.0;
   out_207229337745545750[290] = 0.0;
   out_207229337745545750[291] = 0.0;
   out_207229337745545750[292] = 0.0;
   out_207229337745545750[293] = 0.0;
   out_207229337745545750[294] = 0.0;
   out_207229337745545750[295] = 0.0;
   out_207229337745545750[296] = 0.0;
   out_207229337745545750[297] = 0.0;
   out_207229337745545750[298] = 0.0;
   out_207229337745545750[299] = 0.0;
   out_207229337745545750[300] = 0.0;
   out_207229337745545750[301] = 0.0;
   out_207229337745545750[302] = 0.0;
   out_207229337745545750[303] = 0.0;
   out_207229337745545750[304] = 1.0;
   out_207229337745545750[305] = 0.0;
   out_207229337745545750[306] = 0.0;
   out_207229337745545750[307] = 0.0;
   out_207229337745545750[308] = 0.0;
   out_207229337745545750[309] = 0.0;
   out_207229337745545750[310] = 0.0;
   out_207229337745545750[311] = 0.0;
   out_207229337745545750[312] = 0.0;
   out_207229337745545750[313] = 0.0;
   out_207229337745545750[314] = 0.0;
   out_207229337745545750[315] = 0.0;
   out_207229337745545750[316] = 0.0;
   out_207229337745545750[317] = 0.0;
   out_207229337745545750[318] = 0.0;
   out_207229337745545750[319] = 0.0;
   out_207229337745545750[320] = 0.0;
   out_207229337745545750[321] = 0.0;
   out_207229337745545750[322] = 0.0;
   out_207229337745545750[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3493541226789963130) {
   out_3493541226789963130[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3493541226789963130[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3493541226789963130[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3493541226789963130[3] = dt*state[12] + state[3];
   out_3493541226789963130[4] = dt*state[13] + state[4];
   out_3493541226789963130[5] = dt*state[14] + state[5];
   out_3493541226789963130[6] = state[6];
   out_3493541226789963130[7] = state[7];
   out_3493541226789963130[8] = state[8];
   out_3493541226789963130[9] = state[9];
   out_3493541226789963130[10] = state[10];
   out_3493541226789963130[11] = state[11];
   out_3493541226789963130[12] = state[12];
   out_3493541226789963130[13] = state[13];
   out_3493541226789963130[14] = state[14];
   out_3493541226789963130[15] = state[15];
   out_3493541226789963130[16] = state[16];
   out_3493541226789963130[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5154051058888586616) {
   out_5154051058888586616[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5154051058888586616[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5154051058888586616[2] = 0;
   out_5154051058888586616[3] = 0;
   out_5154051058888586616[4] = 0;
   out_5154051058888586616[5] = 0;
   out_5154051058888586616[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5154051058888586616[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5154051058888586616[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5154051058888586616[9] = 0;
   out_5154051058888586616[10] = 0;
   out_5154051058888586616[11] = 0;
   out_5154051058888586616[12] = 0;
   out_5154051058888586616[13] = 0;
   out_5154051058888586616[14] = 0;
   out_5154051058888586616[15] = 0;
   out_5154051058888586616[16] = 0;
   out_5154051058888586616[17] = 0;
   out_5154051058888586616[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5154051058888586616[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5154051058888586616[20] = 0;
   out_5154051058888586616[21] = 0;
   out_5154051058888586616[22] = 0;
   out_5154051058888586616[23] = 0;
   out_5154051058888586616[24] = 0;
   out_5154051058888586616[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5154051058888586616[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5154051058888586616[27] = 0;
   out_5154051058888586616[28] = 0;
   out_5154051058888586616[29] = 0;
   out_5154051058888586616[30] = 0;
   out_5154051058888586616[31] = 0;
   out_5154051058888586616[32] = 0;
   out_5154051058888586616[33] = 0;
   out_5154051058888586616[34] = 0;
   out_5154051058888586616[35] = 0;
   out_5154051058888586616[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5154051058888586616[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5154051058888586616[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5154051058888586616[39] = 0;
   out_5154051058888586616[40] = 0;
   out_5154051058888586616[41] = 0;
   out_5154051058888586616[42] = 0;
   out_5154051058888586616[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5154051058888586616[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5154051058888586616[45] = 0;
   out_5154051058888586616[46] = 0;
   out_5154051058888586616[47] = 0;
   out_5154051058888586616[48] = 0;
   out_5154051058888586616[49] = 0;
   out_5154051058888586616[50] = 0;
   out_5154051058888586616[51] = 0;
   out_5154051058888586616[52] = 0;
   out_5154051058888586616[53] = 0;
   out_5154051058888586616[54] = 0;
   out_5154051058888586616[55] = 0;
   out_5154051058888586616[56] = 0;
   out_5154051058888586616[57] = 1;
   out_5154051058888586616[58] = 0;
   out_5154051058888586616[59] = 0;
   out_5154051058888586616[60] = 0;
   out_5154051058888586616[61] = 0;
   out_5154051058888586616[62] = 0;
   out_5154051058888586616[63] = 0;
   out_5154051058888586616[64] = 0;
   out_5154051058888586616[65] = 0;
   out_5154051058888586616[66] = dt;
   out_5154051058888586616[67] = 0;
   out_5154051058888586616[68] = 0;
   out_5154051058888586616[69] = 0;
   out_5154051058888586616[70] = 0;
   out_5154051058888586616[71] = 0;
   out_5154051058888586616[72] = 0;
   out_5154051058888586616[73] = 0;
   out_5154051058888586616[74] = 0;
   out_5154051058888586616[75] = 0;
   out_5154051058888586616[76] = 1;
   out_5154051058888586616[77] = 0;
   out_5154051058888586616[78] = 0;
   out_5154051058888586616[79] = 0;
   out_5154051058888586616[80] = 0;
   out_5154051058888586616[81] = 0;
   out_5154051058888586616[82] = 0;
   out_5154051058888586616[83] = 0;
   out_5154051058888586616[84] = 0;
   out_5154051058888586616[85] = dt;
   out_5154051058888586616[86] = 0;
   out_5154051058888586616[87] = 0;
   out_5154051058888586616[88] = 0;
   out_5154051058888586616[89] = 0;
   out_5154051058888586616[90] = 0;
   out_5154051058888586616[91] = 0;
   out_5154051058888586616[92] = 0;
   out_5154051058888586616[93] = 0;
   out_5154051058888586616[94] = 0;
   out_5154051058888586616[95] = 1;
   out_5154051058888586616[96] = 0;
   out_5154051058888586616[97] = 0;
   out_5154051058888586616[98] = 0;
   out_5154051058888586616[99] = 0;
   out_5154051058888586616[100] = 0;
   out_5154051058888586616[101] = 0;
   out_5154051058888586616[102] = 0;
   out_5154051058888586616[103] = 0;
   out_5154051058888586616[104] = dt;
   out_5154051058888586616[105] = 0;
   out_5154051058888586616[106] = 0;
   out_5154051058888586616[107] = 0;
   out_5154051058888586616[108] = 0;
   out_5154051058888586616[109] = 0;
   out_5154051058888586616[110] = 0;
   out_5154051058888586616[111] = 0;
   out_5154051058888586616[112] = 0;
   out_5154051058888586616[113] = 0;
   out_5154051058888586616[114] = 1;
   out_5154051058888586616[115] = 0;
   out_5154051058888586616[116] = 0;
   out_5154051058888586616[117] = 0;
   out_5154051058888586616[118] = 0;
   out_5154051058888586616[119] = 0;
   out_5154051058888586616[120] = 0;
   out_5154051058888586616[121] = 0;
   out_5154051058888586616[122] = 0;
   out_5154051058888586616[123] = 0;
   out_5154051058888586616[124] = 0;
   out_5154051058888586616[125] = 0;
   out_5154051058888586616[126] = 0;
   out_5154051058888586616[127] = 0;
   out_5154051058888586616[128] = 0;
   out_5154051058888586616[129] = 0;
   out_5154051058888586616[130] = 0;
   out_5154051058888586616[131] = 0;
   out_5154051058888586616[132] = 0;
   out_5154051058888586616[133] = 1;
   out_5154051058888586616[134] = 0;
   out_5154051058888586616[135] = 0;
   out_5154051058888586616[136] = 0;
   out_5154051058888586616[137] = 0;
   out_5154051058888586616[138] = 0;
   out_5154051058888586616[139] = 0;
   out_5154051058888586616[140] = 0;
   out_5154051058888586616[141] = 0;
   out_5154051058888586616[142] = 0;
   out_5154051058888586616[143] = 0;
   out_5154051058888586616[144] = 0;
   out_5154051058888586616[145] = 0;
   out_5154051058888586616[146] = 0;
   out_5154051058888586616[147] = 0;
   out_5154051058888586616[148] = 0;
   out_5154051058888586616[149] = 0;
   out_5154051058888586616[150] = 0;
   out_5154051058888586616[151] = 0;
   out_5154051058888586616[152] = 1;
   out_5154051058888586616[153] = 0;
   out_5154051058888586616[154] = 0;
   out_5154051058888586616[155] = 0;
   out_5154051058888586616[156] = 0;
   out_5154051058888586616[157] = 0;
   out_5154051058888586616[158] = 0;
   out_5154051058888586616[159] = 0;
   out_5154051058888586616[160] = 0;
   out_5154051058888586616[161] = 0;
   out_5154051058888586616[162] = 0;
   out_5154051058888586616[163] = 0;
   out_5154051058888586616[164] = 0;
   out_5154051058888586616[165] = 0;
   out_5154051058888586616[166] = 0;
   out_5154051058888586616[167] = 0;
   out_5154051058888586616[168] = 0;
   out_5154051058888586616[169] = 0;
   out_5154051058888586616[170] = 0;
   out_5154051058888586616[171] = 1;
   out_5154051058888586616[172] = 0;
   out_5154051058888586616[173] = 0;
   out_5154051058888586616[174] = 0;
   out_5154051058888586616[175] = 0;
   out_5154051058888586616[176] = 0;
   out_5154051058888586616[177] = 0;
   out_5154051058888586616[178] = 0;
   out_5154051058888586616[179] = 0;
   out_5154051058888586616[180] = 0;
   out_5154051058888586616[181] = 0;
   out_5154051058888586616[182] = 0;
   out_5154051058888586616[183] = 0;
   out_5154051058888586616[184] = 0;
   out_5154051058888586616[185] = 0;
   out_5154051058888586616[186] = 0;
   out_5154051058888586616[187] = 0;
   out_5154051058888586616[188] = 0;
   out_5154051058888586616[189] = 0;
   out_5154051058888586616[190] = 1;
   out_5154051058888586616[191] = 0;
   out_5154051058888586616[192] = 0;
   out_5154051058888586616[193] = 0;
   out_5154051058888586616[194] = 0;
   out_5154051058888586616[195] = 0;
   out_5154051058888586616[196] = 0;
   out_5154051058888586616[197] = 0;
   out_5154051058888586616[198] = 0;
   out_5154051058888586616[199] = 0;
   out_5154051058888586616[200] = 0;
   out_5154051058888586616[201] = 0;
   out_5154051058888586616[202] = 0;
   out_5154051058888586616[203] = 0;
   out_5154051058888586616[204] = 0;
   out_5154051058888586616[205] = 0;
   out_5154051058888586616[206] = 0;
   out_5154051058888586616[207] = 0;
   out_5154051058888586616[208] = 0;
   out_5154051058888586616[209] = 1;
   out_5154051058888586616[210] = 0;
   out_5154051058888586616[211] = 0;
   out_5154051058888586616[212] = 0;
   out_5154051058888586616[213] = 0;
   out_5154051058888586616[214] = 0;
   out_5154051058888586616[215] = 0;
   out_5154051058888586616[216] = 0;
   out_5154051058888586616[217] = 0;
   out_5154051058888586616[218] = 0;
   out_5154051058888586616[219] = 0;
   out_5154051058888586616[220] = 0;
   out_5154051058888586616[221] = 0;
   out_5154051058888586616[222] = 0;
   out_5154051058888586616[223] = 0;
   out_5154051058888586616[224] = 0;
   out_5154051058888586616[225] = 0;
   out_5154051058888586616[226] = 0;
   out_5154051058888586616[227] = 0;
   out_5154051058888586616[228] = 1;
   out_5154051058888586616[229] = 0;
   out_5154051058888586616[230] = 0;
   out_5154051058888586616[231] = 0;
   out_5154051058888586616[232] = 0;
   out_5154051058888586616[233] = 0;
   out_5154051058888586616[234] = 0;
   out_5154051058888586616[235] = 0;
   out_5154051058888586616[236] = 0;
   out_5154051058888586616[237] = 0;
   out_5154051058888586616[238] = 0;
   out_5154051058888586616[239] = 0;
   out_5154051058888586616[240] = 0;
   out_5154051058888586616[241] = 0;
   out_5154051058888586616[242] = 0;
   out_5154051058888586616[243] = 0;
   out_5154051058888586616[244] = 0;
   out_5154051058888586616[245] = 0;
   out_5154051058888586616[246] = 0;
   out_5154051058888586616[247] = 1;
   out_5154051058888586616[248] = 0;
   out_5154051058888586616[249] = 0;
   out_5154051058888586616[250] = 0;
   out_5154051058888586616[251] = 0;
   out_5154051058888586616[252] = 0;
   out_5154051058888586616[253] = 0;
   out_5154051058888586616[254] = 0;
   out_5154051058888586616[255] = 0;
   out_5154051058888586616[256] = 0;
   out_5154051058888586616[257] = 0;
   out_5154051058888586616[258] = 0;
   out_5154051058888586616[259] = 0;
   out_5154051058888586616[260] = 0;
   out_5154051058888586616[261] = 0;
   out_5154051058888586616[262] = 0;
   out_5154051058888586616[263] = 0;
   out_5154051058888586616[264] = 0;
   out_5154051058888586616[265] = 0;
   out_5154051058888586616[266] = 1;
   out_5154051058888586616[267] = 0;
   out_5154051058888586616[268] = 0;
   out_5154051058888586616[269] = 0;
   out_5154051058888586616[270] = 0;
   out_5154051058888586616[271] = 0;
   out_5154051058888586616[272] = 0;
   out_5154051058888586616[273] = 0;
   out_5154051058888586616[274] = 0;
   out_5154051058888586616[275] = 0;
   out_5154051058888586616[276] = 0;
   out_5154051058888586616[277] = 0;
   out_5154051058888586616[278] = 0;
   out_5154051058888586616[279] = 0;
   out_5154051058888586616[280] = 0;
   out_5154051058888586616[281] = 0;
   out_5154051058888586616[282] = 0;
   out_5154051058888586616[283] = 0;
   out_5154051058888586616[284] = 0;
   out_5154051058888586616[285] = 1;
   out_5154051058888586616[286] = 0;
   out_5154051058888586616[287] = 0;
   out_5154051058888586616[288] = 0;
   out_5154051058888586616[289] = 0;
   out_5154051058888586616[290] = 0;
   out_5154051058888586616[291] = 0;
   out_5154051058888586616[292] = 0;
   out_5154051058888586616[293] = 0;
   out_5154051058888586616[294] = 0;
   out_5154051058888586616[295] = 0;
   out_5154051058888586616[296] = 0;
   out_5154051058888586616[297] = 0;
   out_5154051058888586616[298] = 0;
   out_5154051058888586616[299] = 0;
   out_5154051058888586616[300] = 0;
   out_5154051058888586616[301] = 0;
   out_5154051058888586616[302] = 0;
   out_5154051058888586616[303] = 0;
   out_5154051058888586616[304] = 1;
   out_5154051058888586616[305] = 0;
   out_5154051058888586616[306] = 0;
   out_5154051058888586616[307] = 0;
   out_5154051058888586616[308] = 0;
   out_5154051058888586616[309] = 0;
   out_5154051058888586616[310] = 0;
   out_5154051058888586616[311] = 0;
   out_5154051058888586616[312] = 0;
   out_5154051058888586616[313] = 0;
   out_5154051058888586616[314] = 0;
   out_5154051058888586616[315] = 0;
   out_5154051058888586616[316] = 0;
   out_5154051058888586616[317] = 0;
   out_5154051058888586616[318] = 0;
   out_5154051058888586616[319] = 0;
   out_5154051058888586616[320] = 0;
   out_5154051058888586616[321] = 0;
   out_5154051058888586616[322] = 0;
   out_5154051058888586616[323] = 1;
}
void h_4(double *state, double *unused, double *out_5970382648807117116) {
   out_5970382648807117116[0] = state[6] + state[9];
   out_5970382648807117116[1] = state[7] + state[10];
   out_5970382648807117116[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4945289047293534985) {
   out_4945289047293534985[0] = 0;
   out_4945289047293534985[1] = 0;
   out_4945289047293534985[2] = 0;
   out_4945289047293534985[3] = 0;
   out_4945289047293534985[4] = 0;
   out_4945289047293534985[5] = 0;
   out_4945289047293534985[6] = 1;
   out_4945289047293534985[7] = 0;
   out_4945289047293534985[8] = 0;
   out_4945289047293534985[9] = 1;
   out_4945289047293534985[10] = 0;
   out_4945289047293534985[11] = 0;
   out_4945289047293534985[12] = 0;
   out_4945289047293534985[13] = 0;
   out_4945289047293534985[14] = 0;
   out_4945289047293534985[15] = 0;
   out_4945289047293534985[16] = 0;
   out_4945289047293534985[17] = 0;
   out_4945289047293534985[18] = 0;
   out_4945289047293534985[19] = 0;
   out_4945289047293534985[20] = 0;
   out_4945289047293534985[21] = 0;
   out_4945289047293534985[22] = 0;
   out_4945289047293534985[23] = 0;
   out_4945289047293534985[24] = 0;
   out_4945289047293534985[25] = 1;
   out_4945289047293534985[26] = 0;
   out_4945289047293534985[27] = 0;
   out_4945289047293534985[28] = 1;
   out_4945289047293534985[29] = 0;
   out_4945289047293534985[30] = 0;
   out_4945289047293534985[31] = 0;
   out_4945289047293534985[32] = 0;
   out_4945289047293534985[33] = 0;
   out_4945289047293534985[34] = 0;
   out_4945289047293534985[35] = 0;
   out_4945289047293534985[36] = 0;
   out_4945289047293534985[37] = 0;
   out_4945289047293534985[38] = 0;
   out_4945289047293534985[39] = 0;
   out_4945289047293534985[40] = 0;
   out_4945289047293534985[41] = 0;
   out_4945289047293534985[42] = 0;
   out_4945289047293534985[43] = 0;
   out_4945289047293534985[44] = 1;
   out_4945289047293534985[45] = 0;
   out_4945289047293534985[46] = 0;
   out_4945289047293534985[47] = 1;
   out_4945289047293534985[48] = 0;
   out_4945289047293534985[49] = 0;
   out_4945289047293534985[50] = 0;
   out_4945289047293534985[51] = 0;
   out_4945289047293534985[52] = 0;
   out_4945289047293534985[53] = 0;
}
void h_10(double *state, double *unused, double *out_520088425664385209) {
   out_520088425664385209[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_520088425664385209[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_520088425664385209[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4050335309714945768) {
   out_4050335309714945768[0] = 0;
   out_4050335309714945768[1] = 9.8100000000000005*cos(state[1]);
   out_4050335309714945768[2] = 0;
   out_4050335309714945768[3] = 0;
   out_4050335309714945768[4] = -state[8];
   out_4050335309714945768[5] = state[7];
   out_4050335309714945768[6] = 0;
   out_4050335309714945768[7] = state[5];
   out_4050335309714945768[8] = -state[4];
   out_4050335309714945768[9] = 0;
   out_4050335309714945768[10] = 0;
   out_4050335309714945768[11] = 0;
   out_4050335309714945768[12] = 1;
   out_4050335309714945768[13] = 0;
   out_4050335309714945768[14] = 0;
   out_4050335309714945768[15] = 1;
   out_4050335309714945768[16] = 0;
   out_4050335309714945768[17] = 0;
   out_4050335309714945768[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4050335309714945768[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4050335309714945768[20] = 0;
   out_4050335309714945768[21] = state[8];
   out_4050335309714945768[22] = 0;
   out_4050335309714945768[23] = -state[6];
   out_4050335309714945768[24] = -state[5];
   out_4050335309714945768[25] = 0;
   out_4050335309714945768[26] = state[3];
   out_4050335309714945768[27] = 0;
   out_4050335309714945768[28] = 0;
   out_4050335309714945768[29] = 0;
   out_4050335309714945768[30] = 0;
   out_4050335309714945768[31] = 1;
   out_4050335309714945768[32] = 0;
   out_4050335309714945768[33] = 0;
   out_4050335309714945768[34] = 1;
   out_4050335309714945768[35] = 0;
   out_4050335309714945768[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4050335309714945768[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4050335309714945768[38] = 0;
   out_4050335309714945768[39] = -state[7];
   out_4050335309714945768[40] = state[6];
   out_4050335309714945768[41] = 0;
   out_4050335309714945768[42] = state[4];
   out_4050335309714945768[43] = -state[3];
   out_4050335309714945768[44] = 0;
   out_4050335309714945768[45] = 0;
   out_4050335309714945768[46] = 0;
   out_4050335309714945768[47] = 0;
   out_4050335309714945768[48] = 0;
   out_4050335309714945768[49] = 0;
   out_4050335309714945768[50] = 1;
   out_4050335309714945768[51] = 0;
   out_4050335309714945768[52] = 0;
   out_4050335309714945768[53] = 1;
}
void h_13(double *state, double *unused, double *out_1434579794425570866) {
   out_1434579794425570866[0] = state[3];
   out_1434579794425570866[1] = state[4];
   out_1434579794425570866[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1111533583991010961) {
   out_1111533583991010961[0] = 0;
   out_1111533583991010961[1] = 0;
   out_1111533583991010961[2] = 0;
   out_1111533583991010961[3] = 1;
   out_1111533583991010961[4] = 0;
   out_1111533583991010961[5] = 0;
   out_1111533583991010961[6] = 0;
   out_1111533583991010961[7] = 0;
   out_1111533583991010961[8] = 0;
   out_1111533583991010961[9] = 0;
   out_1111533583991010961[10] = 0;
   out_1111533583991010961[11] = 0;
   out_1111533583991010961[12] = 0;
   out_1111533583991010961[13] = 0;
   out_1111533583991010961[14] = 0;
   out_1111533583991010961[15] = 0;
   out_1111533583991010961[16] = 0;
   out_1111533583991010961[17] = 0;
   out_1111533583991010961[18] = 0;
   out_1111533583991010961[19] = 0;
   out_1111533583991010961[20] = 0;
   out_1111533583991010961[21] = 0;
   out_1111533583991010961[22] = 1;
   out_1111533583991010961[23] = 0;
   out_1111533583991010961[24] = 0;
   out_1111533583991010961[25] = 0;
   out_1111533583991010961[26] = 0;
   out_1111533583991010961[27] = 0;
   out_1111533583991010961[28] = 0;
   out_1111533583991010961[29] = 0;
   out_1111533583991010961[30] = 0;
   out_1111533583991010961[31] = 0;
   out_1111533583991010961[32] = 0;
   out_1111533583991010961[33] = 0;
   out_1111533583991010961[34] = 0;
   out_1111533583991010961[35] = 0;
   out_1111533583991010961[36] = 0;
   out_1111533583991010961[37] = 0;
   out_1111533583991010961[38] = 0;
   out_1111533583991010961[39] = 0;
   out_1111533583991010961[40] = 0;
   out_1111533583991010961[41] = 1;
   out_1111533583991010961[42] = 0;
   out_1111533583991010961[43] = 0;
   out_1111533583991010961[44] = 0;
   out_1111533583991010961[45] = 0;
   out_1111533583991010961[46] = 0;
   out_1111533583991010961[47] = 0;
   out_1111533583991010961[48] = 0;
   out_1111533583991010961[49] = 0;
   out_1111533583991010961[50] = 0;
   out_1111533583991010961[51] = 0;
   out_1111533583991010961[52] = 0;
   out_1111533583991010961[53] = 0;
}
void h_14(double *state, double *unused, double *out_5370135948753942539) {
   out_5370135948753942539[0] = state[6];
   out_5370135948753942539[1] = state[7];
   out_5370135948753942539[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1862500614998162689) {
   out_1862500614998162689[0] = 0;
   out_1862500614998162689[1] = 0;
   out_1862500614998162689[2] = 0;
   out_1862500614998162689[3] = 0;
   out_1862500614998162689[4] = 0;
   out_1862500614998162689[5] = 0;
   out_1862500614998162689[6] = 1;
   out_1862500614998162689[7] = 0;
   out_1862500614998162689[8] = 0;
   out_1862500614998162689[9] = 0;
   out_1862500614998162689[10] = 0;
   out_1862500614998162689[11] = 0;
   out_1862500614998162689[12] = 0;
   out_1862500614998162689[13] = 0;
   out_1862500614998162689[14] = 0;
   out_1862500614998162689[15] = 0;
   out_1862500614998162689[16] = 0;
   out_1862500614998162689[17] = 0;
   out_1862500614998162689[18] = 0;
   out_1862500614998162689[19] = 0;
   out_1862500614998162689[20] = 0;
   out_1862500614998162689[21] = 0;
   out_1862500614998162689[22] = 0;
   out_1862500614998162689[23] = 0;
   out_1862500614998162689[24] = 0;
   out_1862500614998162689[25] = 1;
   out_1862500614998162689[26] = 0;
   out_1862500614998162689[27] = 0;
   out_1862500614998162689[28] = 0;
   out_1862500614998162689[29] = 0;
   out_1862500614998162689[30] = 0;
   out_1862500614998162689[31] = 0;
   out_1862500614998162689[32] = 0;
   out_1862500614998162689[33] = 0;
   out_1862500614998162689[34] = 0;
   out_1862500614998162689[35] = 0;
   out_1862500614998162689[36] = 0;
   out_1862500614998162689[37] = 0;
   out_1862500614998162689[38] = 0;
   out_1862500614998162689[39] = 0;
   out_1862500614998162689[40] = 0;
   out_1862500614998162689[41] = 0;
   out_1862500614998162689[42] = 0;
   out_1862500614998162689[43] = 0;
   out_1862500614998162689[44] = 1;
   out_1862500614998162689[45] = 0;
   out_1862500614998162689[46] = 0;
   out_1862500614998162689[47] = 0;
   out_1862500614998162689[48] = 0;
   out_1862500614998162689[49] = 0;
   out_1862500614998162689[50] = 0;
   out_1862500614998162689[51] = 0;
   out_1862500614998162689[52] = 0;
   out_1862500614998162689[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_3574067617578089570) {
  err_fun(nom_x, delta_x, out_3574067617578089570);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_1515328263168530495) {
  inv_err_fun(nom_x, true_x, out_1515328263168530495);
}
void pose_H_mod_fun(double *state, double *out_207229337745545750) {
  H_mod_fun(state, out_207229337745545750);
}
void pose_f_fun(double *state, double dt, double *out_3493541226789963130) {
  f_fun(state,  dt, out_3493541226789963130);
}
void pose_F_fun(double *state, double dt, double *out_5154051058888586616) {
  F_fun(state,  dt, out_5154051058888586616);
}
void pose_h_4(double *state, double *unused, double *out_5970382648807117116) {
  h_4(state, unused, out_5970382648807117116);
}
void pose_H_4(double *state, double *unused, double *out_4945289047293534985) {
  H_4(state, unused, out_4945289047293534985);
}
void pose_h_10(double *state, double *unused, double *out_520088425664385209) {
  h_10(state, unused, out_520088425664385209);
}
void pose_H_10(double *state, double *unused, double *out_4050335309714945768) {
  H_10(state, unused, out_4050335309714945768);
}
void pose_h_13(double *state, double *unused, double *out_1434579794425570866) {
  h_13(state, unused, out_1434579794425570866);
}
void pose_H_13(double *state, double *unused, double *out_1111533583991010961) {
  H_13(state, unused, out_1111533583991010961);
}
void pose_h_14(double *state, double *unused, double *out_5370135948753942539) {
  h_14(state, unused, out_5370135948753942539);
}
void pose_H_14(double *state, double *unused, double *out_1862500614998162689) {
  H_14(state, unused, out_1862500614998162689);
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
