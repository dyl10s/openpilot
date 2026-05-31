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
void err_fun(double *nom_x, double *delta_x, double *out_4567767818172860295) {
   out_4567767818172860295[0] = delta_x[0] + nom_x[0];
   out_4567767818172860295[1] = delta_x[1] + nom_x[1];
   out_4567767818172860295[2] = delta_x[2] + nom_x[2];
   out_4567767818172860295[3] = delta_x[3] + nom_x[3];
   out_4567767818172860295[4] = delta_x[4] + nom_x[4];
   out_4567767818172860295[5] = delta_x[5] + nom_x[5];
   out_4567767818172860295[6] = delta_x[6] + nom_x[6];
   out_4567767818172860295[7] = delta_x[7] + nom_x[7];
   out_4567767818172860295[8] = delta_x[8] + nom_x[8];
   out_4567767818172860295[9] = delta_x[9] + nom_x[9];
   out_4567767818172860295[10] = delta_x[10] + nom_x[10];
   out_4567767818172860295[11] = delta_x[11] + nom_x[11];
   out_4567767818172860295[12] = delta_x[12] + nom_x[12];
   out_4567767818172860295[13] = delta_x[13] + nom_x[13];
   out_4567767818172860295[14] = delta_x[14] + nom_x[14];
   out_4567767818172860295[15] = delta_x[15] + nom_x[15];
   out_4567767818172860295[16] = delta_x[16] + nom_x[16];
   out_4567767818172860295[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4613807108104960206) {
   out_4613807108104960206[0] = -nom_x[0] + true_x[0];
   out_4613807108104960206[1] = -nom_x[1] + true_x[1];
   out_4613807108104960206[2] = -nom_x[2] + true_x[2];
   out_4613807108104960206[3] = -nom_x[3] + true_x[3];
   out_4613807108104960206[4] = -nom_x[4] + true_x[4];
   out_4613807108104960206[5] = -nom_x[5] + true_x[5];
   out_4613807108104960206[6] = -nom_x[6] + true_x[6];
   out_4613807108104960206[7] = -nom_x[7] + true_x[7];
   out_4613807108104960206[8] = -nom_x[8] + true_x[8];
   out_4613807108104960206[9] = -nom_x[9] + true_x[9];
   out_4613807108104960206[10] = -nom_x[10] + true_x[10];
   out_4613807108104960206[11] = -nom_x[11] + true_x[11];
   out_4613807108104960206[12] = -nom_x[12] + true_x[12];
   out_4613807108104960206[13] = -nom_x[13] + true_x[13];
   out_4613807108104960206[14] = -nom_x[14] + true_x[14];
   out_4613807108104960206[15] = -nom_x[15] + true_x[15];
   out_4613807108104960206[16] = -nom_x[16] + true_x[16];
   out_4613807108104960206[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6572770099193808423) {
   out_6572770099193808423[0] = 1.0;
   out_6572770099193808423[1] = 0.0;
   out_6572770099193808423[2] = 0.0;
   out_6572770099193808423[3] = 0.0;
   out_6572770099193808423[4] = 0.0;
   out_6572770099193808423[5] = 0.0;
   out_6572770099193808423[6] = 0.0;
   out_6572770099193808423[7] = 0.0;
   out_6572770099193808423[8] = 0.0;
   out_6572770099193808423[9] = 0.0;
   out_6572770099193808423[10] = 0.0;
   out_6572770099193808423[11] = 0.0;
   out_6572770099193808423[12] = 0.0;
   out_6572770099193808423[13] = 0.0;
   out_6572770099193808423[14] = 0.0;
   out_6572770099193808423[15] = 0.0;
   out_6572770099193808423[16] = 0.0;
   out_6572770099193808423[17] = 0.0;
   out_6572770099193808423[18] = 0.0;
   out_6572770099193808423[19] = 1.0;
   out_6572770099193808423[20] = 0.0;
   out_6572770099193808423[21] = 0.0;
   out_6572770099193808423[22] = 0.0;
   out_6572770099193808423[23] = 0.0;
   out_6572770099193808423[24] = 0.0;
   out_6572770099193808423[25] = 0.0;
   out_6572770099193808423[26] = 0.0;
   out_6572770099193808423[27] = 0.0;
   out_6572770099193808423[28] = 0.0;
   out_6572770099193808423[29] = 0.0;
   out_6572770099193808423[30] = 0.0;
   out_6572770099193808423[31] = 0.0;
   out_6572770099193808423[32] = 0.0;
   out_6572770099193808423[33] = 0.0;
   out_6572770099193808423[34] = 0.0;
   out_6572770099193808423[35] = 0.0;
   out_6572770099193808423[36] = 0.0;
   out_6572770099193808423[37] = 0.0;
   out_6572770099193808423[38] = 1.0;
   out_6572770099193808423[39] = 0.0;
   out_6572770099193808423[40] = 0.0;
   out_6572770099193808423[41] = 0.0;
   out_6572770099193808423[42] = 0.0;
   out_6572770099193808423[43] = 0.0;
   out_6572770099193808423[44] = 0.0;
   out_6572770099193808423[45] = 0.0;
   out_6572770099193808423[46] = 0.0;
   out_6572770099193808423[47] = 0.0;
   out_6572770099193808423[48] = 0.0;
   out_6572770099193808423[49] = 0.0;
   out_6572770099193808423[50] = 0.0;
   out_6572770099193808423[51] = 0.0;
   out_6572770099193808423[52] = 0.0;
   out_6572770099193808423[53] = 0.0;
   out_6572770099193808423[54] = 0.0;
   out_6572770099193808423[55] = 0.0;
   out_6572770099193808423[56] = 0.0;
   out_6572770099193808423[57] = 1.0;
   out_6572770099193808423[58] = 0.0;
   out_6572770099193808423[59] = 0.0;
   out_6572770099193808423[60] = 0.0;
   out_6572770099193808423[61] = 0.0;
   out_6572770099193808423[62] = 0.0;
   out_6572770099193808423[63] = 0.0;
   out_6572770099193808423[64] = 0.0;
   out_6572770099193808423[65] = 0.0;
   out_6572770099193808423[66] = 0.0;
   out_6572770099193808423[67] = 0.0;
   out_6572770099193808423[68] = 0.0;
   out_6572770099193808423[69] = 0.0;
   out_6572770099193808423[70] = 0.0;
   out_6572770099193808423[71] = 0.0;
   out_6572770099193808423[72] = 0.0;
   out_6572770099193808423[73] = 0.0;
   out_6572770099193808423[74] = 0.0;
   out_6572770099193808423[75] = 0.0;
   out_6572770099193808423[76] = 1.0;
   out_6572770099193808423[77] = 0.0;
   out_6572770099193808423[78] = 0.0;
   out_6572770099193808423[79] = 0.0;
   out_6572770099193808423[80] = 0.0;
   out_6572770099193808423[81] = 0.0;
   out_6572770099193808423[82] = 0.0;
   out_6572770099193808423[83] = 0.0;
   out_6572770099193808423[84] = 0.0;
   out_6572770099193808423[85] = 0.0;
   out_6572770099193808423[86] = 0.0;
   out_6572770099193808423[87] = 0.0;
   out_6572770099193808423[88] = 0.0;
   out_6572770099193808423[89] = 0.0;
   out_6572770099193808423[90] = 0.0;
   out_6572770099193808423[91] = 0.0;
   out_6572770099193808423[92] = 0.0;
   out_6572770099193808423[93] = 0.0;
   out_6572770099193808423[94] = 0.0;
   out_6572770099193808423[95] = 1.0;
   out_6572770099193808423[96] = 0.0;
   out_6572770099193808423[97] = 0.0;
   out_6572770099193808423[98] = 0.0;
   out_6572770099193808423[99] = 0.0;
   out_6572770099193808423[100] = 0.0;
   out_6572770099193808423[101] = 0.0;
   out_6572770099193808423[102] = 0.0;
   out_6572770099193808423[103] = 0.0;
   out_6572770099193808423[104] = 0.0;
   out_6572770099193808423[105] = 0.0;
   out_6572770099193808423[106] = 0.0;
   out_6572770099193808423[107] = 0.0;
   out_6572770099193808423[108] = 0.0;
   out_6572770099193808423[109] = 0.0;
   out_6572770099193808423[110] = 0.0;
   out_6572770099193808423[111] = 0.0;
   out_6572770099193808423[112] = 0.0;
   out_6572770099193808423[113] = 0.0;
   out_6572770099193808423[114] = 1.0;
   out_6572770099193808423[115] = 0.0;
   out_6572770099193808423[116] = 0.0;
   out_6572770099193808423[117] = 0.0;
   out_6572770099193808423[118] = 0.0;
   out_6572770099193808423[119] = 0.0;
   out_6572770099193808423[120] = 0.0;
   out_6572770099193808423[121] = 0.0;
   out_6572770099193808423[122] = 0.0;
   out_6572770099193808423[123] = 0.0;
   out_6572770099193808423[124] = 0.0;
   out_6572770099193808423[125] = 0.0;
   out_6572770099193808423[126] = 0.0;
   out_6572770099193808423[127] = 0.0;
   out_6572770099193808423[128] = 0.0;
   out_6572770099193808423[129] = 0.0;
   out_6572770099193808423[130] = 0.0;
   out_6572770099193808423[131] = 0.0;
   out_6572770099193808423[132] = 0.0;
   out_6572770099193808423[133] = 1.0;
   out_6572770099193808423[134] = 0.0;
   out_6572770099193808423[135] = 0.0;
   out_6572770099193808423[136] = 0.0;
   out_6572770099193808423[137] = 0.0;
   out_6572770099193808423[138] = 0.0;
   out_6572770099193808423[139] = 0.0;
   out_6572770099193808423[140] = 0.0;
   out_6572770099193808423[141] = 0.0;
   out_6572770099193808423[142] = 0.0;
   out_6572770099193808423[143] = 0.0;
   out_6572770099193808423[144] = 0.0;
   out_6572770099193808423[145] = 0.0;
   out_6572770099193808423[146] = 0.0;
   out_6572770099193808423[147] = 0.0;
   out_6572770099193808423[148] = 0.0;
   out_6572770099193808423[149] = 0.0;
   out_6572770099193808423[150] = 0.0;
   out_6572770099193808423[151] = 0.0;
   out_6572770099193808423[152] = 1.0;
   out_6572770099193808423[153] = 0.0;
   out_6572770099193808423[154] = 0.0;
   out_6572770099193808423[155] = 0.0;
   out_6572770099193808423[156] = 0.0;
   out_6572770099193808423[157] = 0.0;
   out_6572770099193808423[158] = 0.0;
   out_6572770099193808423[159] = 0.0;
   out_6572770099193808423[160] = 0.0;
   out_6572770099193808423[161] = 0.0;
   out_6572770099193808423[162] = 0.0;
   out_6572770099193808423[163] = 0.0;
   out_6572770099193808423[164] = 0.0;
   out_6572770099193808423[165] = 0.0;
   out_6572770099193808423[166] = 0.0;
   out_6572770099193808423[167] = 0.0;
   out_6572770099193808423[168] = 0.0;
   out_6572770099193808423[169] = 0.0;
   out_6572770099193808423[170] = 0.0;
   out_6572770099193808423[171] = 1.0;
   out_6572770099193808423[172] = 0.0;
   out_6572770099193808423[173] = 0.0;
   out_6572770099193808423[174] = 0.0;
   out_6572770099193808423[175] = 0.0;
   out_6572770099193808423[176] = 0.0;
   out_6572770099193808423[177] = 0.0;
   out_6572770099193808423[178] = 0.0;
   out_6572770099193808423[179] = 0.0;
   out_6572770099193808423[180] = 0.0;
   out_6572770099193808423[181] = 0.0;
   out_6572770099193808423[182] = 0.0;
   out_6572770099193808423[183] = 0.0;
   out_6572770099193808423[184] = 0.0;
   out_6572770099193808423[185] = 0.0;
   out_6572770099193808423[186] = 0.0;
   out_6572770099193808423[187] = 0.0;
   out_6572770099193808423[188] = 0.0;
   out_6572770099193808423[189] = 0.0;
   out_6572770099193808423[190] = 1.0;
   out_6572770099193808423[191] = 0.0;
   out_6572770099193808423[192] = 0.0;
   out_6572770099193808423[193] = 0.0;
   out_6572770099193808423[194] = 0.0;
   out_6572770099193808423[195] = 0.0;
   out_6572770099193808423[196] = 0.0;
   out_6572770099193808423[197] = 0.0;
   out_6572770099193808423[198] = 0.0;
   out_6572770099193808423[199] = 0.0;
   out_6572770099193808423[200] = 0.0;
   out_6572770099193808423[201] = 0.0;
   out_6572770099193808423[202] = 0.0;
   out_6572770099193808423[203] = 0.0;
   out_6572770099193808423[204] = 0.0;
   out_6572770099193808423[205] = 0.0;
   out_6572770099193808423[206] = 0.0;
   out_6572770099193808423[207] = 0.0;
   out_6572770099193808423[208] = 0.0;
   out_6572770099193808423[209] = 1.0;
   out_6572770099193808423[210] = 0.0;
   out_6572770099193808423[211] = 0.0;
   out_6572770099193808423[212] = 0.0;
   out_6572770099193808423[213] = 0.0;
   out_6572770099193808423[214] = 0.0;
   out_6572770099193808423[215] = 0.0;
   out_6572770099193808423[216] = 0.0;
   out_6572770099193808423[217] = 0.0;
   out_6572770099193808423[218] = 0.0;
   out_6572770099193808423[219] = 0.0;
   out_6572770099193808423[220] = 0.0;
   out_6572770099193808423[221] = 0.0;
   out_6572770099193808423[222] = 0.0;
   out_6572770099193808423[223] = 0.0;
   out_6572770099193808423[224] = 0.0;
   out_6572770099193808423[225] = 0.0;
   out_6572770099193808423[226] = 0.0;
   out_6572770099193808423[227] = 0.0;
   out_6572770099193808423[228] = 1.0;
   out_6572770099193808423[229] = 0.0;
   out_6572770099193808423[230] = 0.0;
   out_6572770099193808423[231] = 0.0;
   out_6572770099193808423[232] = 0.0;
   out_6572770099193808423[233] = 0.0;
   out_6572770099193808423[234] = 0.0;
   out_6572770099193808423[235] = 0.0;
   out_6572770099193808423[236] = 0.0;
   out_6572770099193808423[237] = 0.0;
   out_6572770099193808423[238] = 0.0;
   out_6572770099193808423[239] = 0.0;
   out_6572770099193808423[240] = 0.0;
   out_6572770099193808423[241] = 0.0;
   out_6572770099193808423[242] = 0.0;
   out_6572770099193808423[243] = 0.0;
   out_6572770099193808423[244] = 0.0;
   out_6572770099193808423[245] = 0.0;
   out_6572770099193808423[246] = 0.0;
   out_6572770099193808423[247] = 1.0;
   out_6572770099193808423[248] = 0.0;
   out_6572770099193808423[249] = 0.0;
   out_6572770099193808423[250] = 0.0;
   out_6572770099193808423[251] = 0.0;
   out_6572770099193808423[252] = 0.0;
   out_6572770099193808423[253] = 0.0;
   out_6572770099193808423[254] = 0.0;
   out_6572770099193808423[255] = 0.0;
   out_6572770099193808423[256] = 0.0;
   out_6572770099193808423[257] = 0.0;
   out_6572770099193808423[258] = 0.0;
   out_6572770099193808423[259] = 0.0;
   out_6572770099193808423[260] = 0.0;
   out_6572770099193808423[261] = 0.0;
   out_6572770099193808423[262] = 0.0;
   out_6572770099193808423[263] = 0.0;
   out_6572770099193808423[264] = 0.0;
   out_6572770099193808423[265] = 0.0;
   out_6572770099193808423[266] = 1.0;
   out_6572770099193808423[267] = 0.0;
   out_6572770099193808423[268] = 0.0;
   out_6572770099193808423[269] = 0.0;
   out_6572770099193808423[270] = 0.0;
   out_6572770099193808423[271] = 0.0;
   out_6572770099193808423[272] = 0.0;
   out_6572770099193808423[273] = 0.0;
   out_6572770099193808423[274] = 0.0;
   out_6572770099193808423[275] = 0.0;
   out_6572770099193808423[276] = 0.0;
   out_6572770099193808423[277] = 0.0;
   out_6572770099193808423[278] = 0.0;
   out_6572770099193808423[279] = 0.0;
   out_6572770099193808423[280] = 0.0;
   out_6572770099193808423[281] = 0.0;
   out_6572770099193808423[282] = 0.0;
   out_6572770099193808423[283] = 0.0;
   out_6572770099193808423[284] = 0.0;
   out_6572770099193808423[285] = 1.0;
   out_6572770099193808423[286] = 0.0;
   out_6572770099193808423[287] = 0.0;
   out_6572770099193808423[288] = 0.0;
   out_6572770099193808423[289] = 0.0;
   out_6572770099193808423[290] = 0.0;
   out_6572770099193808423[291] = 0.0;
   out_6572770099193808423[292] = 0.0;
   out_6572770099193808423[293] = 0.0;
   out_6572770099193808423[294] = 0.0;
   out_6572770099193808423[295] = 0.0;
   out_6572770099193808423[296] = 0.0;
   out_6572770099193808423[297] = 0.0;
   out_6572770099193808423[298] = 0.0;
   out_6572770099193808423[299] = 0.0;
   out_6572770099193808423[300] = 0.0;
   out_6572770099193808423[301] = 0.0;
   out_6572770099193808423[302] = 0.0;
   out_6572770099193808423[303] = 0.0;
   out_6572770099193808423[304] = 1.0;
   out_6572770099193808423[305] = 0.0;
   out_6572770099193808423[306] = 0.0;
   out_6572770099193808423[307] = 0.0;
   out_6572770099193808423[308] = 0.0;
   out_6572770099193808423[309] = 0.0;
   out_6572770099193808423[310] = 0.0;
   out_6572770099193808423[311] = 0.0;
   out_6572770099193808423[312] = 0.0;
   out_6572770099193808423[313] = 0.0;
   out_6572770099193808423[314] = 0.0;
   out_6572770099193808423[315] = 0.0;
   out_6572770099193808423[316] = 0.0;
   out_6572770099193808423[317] = 0.0;
   out_6572770099193808423[318] = 0.0;
   out_6572770099193808423[319] = 0.0;
   out_6572770099193808423[320] = 0.0;
   out_6572770099193808423[321] = 0.0;
   out_6572770099193808423[322] = 0.0;
   out_6572770099193808423[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_972215043360367871) {
   out_972215043360367871[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_972215043360367871[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_972215043360367871[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_972215043360367871[3] = dt*state[12] + state[3];
   out_972215043360367871[4] = dt*state[13] + state[4];
   out_972215043360367871[5] = dt*state[14] + state[5];
   out_972215043360367871[6] = state[6];
   out_972215043360367871[7] = state[7];
   out_972215043360367871[8] = state[8];
   out_972215043360367871[9] = state[9];
   out_972215043360367871[10] = state[10];
   out_972215043360367871[11] = state[11];
   out_972215043360367871[12] = state[12];
   out_972215043360367871[13] = state[13];
   out_972215043360367871[14] = state[14];
   out_972215043360367871[15] = state[15];
   out_972215043360367871[16] = state[16];
   out_972215043360367871[17] = state[17];
}
void F_fun(double *state, double dt, double *out_9096792433349462064) {
   out_9096792433349462064[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9096792433349462064[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9096792433349462064[2] = 0;
   out_9096792433349462064[3] = 0;
   out_9096792433349462064[4] = 0;
   out_9096792433349462064[5] = 0;
   out_9096792433349462064[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9096792433349462064[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9096792433349462064[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_9096792433349462064[9] = 0;
   out_9096792433349462064[10] = 0;
   out_9096792433349462064[11] = 0;
   out_9096792433349462064[12] = 0;
   out_9096792433349462064[13] = 0;
   out_9096792433349462064[14] = 0;
   out_9096792433349462064[15] = 0;
   out_9096792433349462064[16] = 0;
   out_9096792433349462064[17] = 0;
   out_9096792433349462064[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9096792433349462064[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9096792433349462064[20] = 0;
   out_9096792433349462064[21] = 0;
   out_9096792433349462064[22] = 0;
   out_9096792433349462064[23] = 0;
   out_9096792433349462064[24] = 0;
   out_9096792433349462064[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9096792433349462064[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_9096792433349462064[27] = 0;
   out_9096792433349462064[28] = 0;
   out_9096792433349462064[29] = 0;
   out_9096792433349462064[30] = 0;
   out_9096792433349462064[31] = 0;
   out_9096792433349462064[32] = 0;
   out_9096792433349462064[33] = 0;
   out_9096792433349462064[34] = 0;
   out_9096792433349462064[35] = 0;
   out_9096792433349462064[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9096792433349462064[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9096792433349462064[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9096792433349462064[39] = 0;
   out_9096792433349462064[40] = 0;
   out_9096792433349462064[41] = 0;
   out_9096792433349462064[42] = 0;
   out_9096792433349462064[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9096792433349462064[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_9096792433349462064[45] = 0;
   out_9096792433349462064[46] = 0;
   out_9096792433349462064[47] = 0;
   out_9096792433349462064[48] = 0;
   out_9096792433349462064[49] = 0;
   out_9096792433349462064[50] = 0;
   out_9096792433349462064[51] = 0;
   out_9096792433349462064[52] = 0;
   out_9096792433349462064[53] = 0;
   out_9096792433349462064[54] = 0;
   out_9096792433349462064[55] = 0;
   out_9096792433349462064[56] = 0;
   out_9096792433349462064[57] = 1;
   out_9096792433349462064[58] = 0;
   out_9096792433349462064[59] = 0;
   out_9096792433349462064[60] = 0;
   out_9096792433349462064[61] = 0;
   out_9096792433349462064[62] = 0;
   out_9096792433349462064[63] = 0;
   out_9096792433349462064[64] = 0;
   out_9096792433349462064[65] = 0;
   out_9096792433349462064[66] = dt;
   out_9096792433349462064[67] = 0;
   out_9096792433349462064[68] = 0;
   out_9096792433349462064[69] = 0;
   out_9096792433349462064[70] = 0;
   out_9096792433349462064[71] = 0;
   out_9096792433349462064[72] = 0;
   out_9096792433349462064[73] = 0;
   out_9096792433349462064[74] = 0;
   out_9096792433349462064[75] = 0;
   out_9096792433349462064[76] = 1;
   out_9096792433349462064[77] = 0;
   out_9096792433349462064[78] = 0;
   out_9096792433349462064[79] = 0;
   out_9096792433349462064[80] = 0;
   out_9096792433349462064[81] = 0;
   out_9096792433349462064[82] = 0;
   out_9096792433349462064[83] = 0;
   out_9096792433349462064[84] = 0;
   out_9096792433349462064[85] = dt;
   out_9096792433349462064[86] = 0;
   out_9096792433349462064[87] = 0;
   out_9096792433349462064[88] = 0;
   out_9096792433349462064[89] = 0;
   out_9096792433349462064[90] = 0;
   out_9096792433349462064[91] = 0;
   out_9096792433349462064[92] = 0;
   out_9096792433349462064[93] = 0;
   out_9096792433349462064[94] = 0;
   out_9096792433349462064[95] = 1;
   out_9096792433349462064[96] = 0;
   out_9096792433349462064[97] = 0;
   out_9096792433349462064[98] = 0;
   out_9096792433349462064[99] = 0;
   out_9096792433349462064[100] = 0;
   out_9096792433349462064[101] = 0;
   out_9096792433349462064[102] = 0;
   out_9096792433349462064[103] = 0;
   out_9096792433349462064[104] = dt;
   out_9096792433349462064[105] = 0;
   out_9096792433349462064[106] = 0;
   out_9096792433349462064[107] = 0;
   out_9096792433349462064[108] = 0;
   out_9096792433349462064[109] = 0;
   out_9096792433349462064[110] = 0;
   out_9096792433349462064[111] = 0;
   out_9096792433349462064[112] = 0;
   out_9096792433349462064[113] = 0;
   out_9096792433349462064[114] = 1;
   out_9096792433349462064[115] = 0;
   out_9096792433349462064[116] = 0;
   out_9096792433349462064[117] = 0;
   out_9096792433349462064[118] = 0;
   out_9096792433349462064[119] = 0;
   out_9096792433349462064[120] = 0;
   out_9096792433349462064[121] = 0;
   out_9096792433349462064[122] = 0;
   out_9096792433349462064[123] = 0;
   out_9096792433349462064[124] = 0;
   out_9096792433349462064[125] = 0;
   out_9096792433349462064[126] = 0;
   out_9096792433349462064[127] = 0;
   out_9096792433349462064[128] = 0;
   out_9096792433349462064[129] = 0;
   out_9096792433349462064[130] = 0;
   out_9096792433349462064[131] = 0;
   out_9096792433349462064[132] = 0;
   out_9096792433349462064[133] = 1;
   out_9096792433349462064[134] = 0;
   out_9096792433349462064[135] = 0;
   out_9096792433349462064[136] = 0;
   out_9096792433349462064[137] = 0;
   out_9096792433349462064[138] = 0;
   out_9096792433349462064[139] = 0;
   out_9096792433349462064[140] = 0;
   out_9096792433349462064[141] = 0;
   out_9096792433349462064[142] = 0;
   out_9096792433349462064[143] = 0;
   out_9096792433349462064[144] = 0;
   out_9096792433349462064[145] = 0;
   out_9096792433349462064[146] = 0;
   out_9096792433349462064[147] = 0;
   out_9096792433349462064[148] = 0;
   out_9096792433349462064[149] = 0;
   out_9096792433349462064[150] = 0;
   out_9096792433349462064[151] = 0;
   out_9096792433349462064[152] = 1;
   out_9096792433349462064[153] = 0;
   out_9096792433349462064[154] = 0;
   out_9096792433349462064[155] = 0;
   out_9096792433349462064[156] = 0;
   out_9096792433349462064[157] = 0;
   out_9096792433349462064[158] = 0;
   out_9096792433349462064[159] = 0;
   out_9096792433349462064[160] = 0;
   out_9096792433349462064[161] = 0;
   out_9096792433349462064[162] = 0;
   out_9096792433349462064[163] = 0;
   out_9096792433349462064[164] = 0;
   out_9096792433349462064[165] = 0;
   out_9096792433349462064[166] = 0;
   out_9096792433349462064[167] = 0;
   out_9096792433349462064[168] = 0;
   out_9096792433349462064[169] = 0;
   out_9096792433349462064[170] = 0;
   out_9096792433349462064[171] = 1;
   out_9096792433349462064[172] = 0;
   out_9096792433349462064[173] = 0;
   out_9096792433349462064[174] = 0;
   out_9096792433349462064[175] = 0;
   out_9096792433349462064[176] = 0;
   out_9096792433349462064[177] = 0;
   out_9096792433349462064[178] = 0;
   out_9096792433349462064[179] = 0;
   out_9096792433349462064[180] = 0;
   out_9096792433349462064[181] = 0;
   out_9096792433349462064[182] = 0;
   out_9096792433349462064[183] = 0;
   out_9096792433349462064[184] = 0;
   out_9096792433349462064[185] = 0;
   out_9096792433349462064[186] = 0;
   out_9096792433349462064[187] = 0;
   out_9096792433349462064[188] = 0;
   out_9096792433349462064[189] = 0;
   out_9096792433349462064[190] = 1;
   out_9096792433349462064[191] = 0;
   out_9096792433349462064[192] = 0;
   out_9096792433349462064[193] = 0;
   out_9096792433349462064[194] = 0;
   out_9096792433349462064[195] = 0;
   out_9096792433349462064[196] = 0;
   out_9096792433349462064[197] = 0;
   out_9096792433349462064[198] = 0;
   out_9096792433349462064[199] = 0;
   out_9096792433349462064[200] = 0;
   out_9096792433349462064[201] = 0;
   out_9096792433349462064[202] = 0;
   out_9096792433349462064[203] = 0;
   out_9096792433349462064[204] = 0;
   out_9096792433349462064[205] = 0;
   out_9096792433349462064[206] = 0;
   out_9096792433349462064[207] = 0;
   out_9096792433349462064[208] = 0;
   out_9096792433349462064[209] = 1;
   out_9096792433349462064[210] = 0;
   out_9096792433349462064[211] = 0;
   out_9096792433349462064[212] = 0;
   out_9096792433349462064[213] = 0;
   out_9096792433349462064[214] = 0;
   out_9096792433349462064[215] = 0;
   out_9096792433349462064[216] = 0;
   out_9096792433349462064[217] = 0;
   out_9096792433349462064[218] = 0;
   out_9096792433349462064[219] = 0;
   out_9096792433349462064[220] = 0;
   out_9096792433349462064[221] = 0;
   out_9096792433349462064[222] = 0;
   out_9096792433349462064[223] = 0;
   out_9096792433349462064[224] = 0;
   out_9096792433349462064[225] = 0;
   out_9096792433349462064[226] = 0;
   out_9096792433349462064[227] = 0;
   out_9096792433349462064[228] = 1;
   out_9096792433349462064[229] = 0;
   out_9096792433349462064[230] = 0;
   out_9096792433349462064[231] = 0;
   out_9096792433349462064[232] = 0;
   out_9096792433349462064[233] = 0;
   out_9096792433349462064[234] = 0;
   out_9096792433349462064[235] = 0;
   out_9096792433349462064[236] = 0;
   out_9096792433349462064[237] = 0;
   out_9096792433349462064[238] = 0;
   out_9096792433349462064[239] = 0;
   out_9096792433349462064[240] = 0;
   out_9096792433349462064[241] = 0;
   out_9096792433349462064[242] = 0;
   out_9096792433349462064[243] = 0;
   out_9096792433349462064[244] = 0;
   out_9096792433349462064[245] = 0;
   out_9096792433349462064[246] = 0;
   out_9096792433349462064[247] = 1;
   out_9096792433349462064[248] = 0;
   out_9096792433349462064[249] = 0;
   out_9096792433349462064[250] = 0;
   out_9096792433349462064[251] = 0;
   out_9096792433349462064[252] = 0;
   out_9096792433349462064[253] = 0;
   out_9096792433349462064[254] = 0;
   out_9096792433349462064[255] = 0;
   out_9096792433349462064[256] = 0;
   out_9096792433349462064[257] = 0;
   out_9096792433349462064[258] = 0;
   out_9096792433349462064[259] = 0;
   out_9096792433349462064[260] = 0;
   out_9096792433349462064[261] = 0;
   out_9096792433349462064[262] = 0;
   out_9096792433349462064[263] = 0;
   out_9096792433349462064[264] = 0;
   out_9096792433349462064[265] = 0;
   out_9096792433349462064[266] = 1;
   out_9096792433349462064[267] = 0;
   out_9096792433349462064[268] = 0;
   out_9096792433349462064[269] = 0;
   out_9096792433349462064[270] = 0;
   out_9096792433349462064[271] = 0;
   out_9096792433349462064[272] = 0;
   out_9096792433349462064[273] = 0;
   out_9096792433349462064[274] = 0;
   out_9096792433349462064[275] = 0;
   out_9096792433349462064[276] = 0;
   out_9096792433349462064[277] = 0;
   out_9096792433349462064[278] = 0;
   out_9096792433349462064[279] = 0;
   out_9096792433349462064[280] = 0;
   out_9096792433349462064[281] = 0;
   out_9096792433349462064[282] = 0;
   out_9096792433349462064[283] = 0;
   out_9096792433349462064[284] = 0;
   out_9096792433349462064[285] = 1;
   out_9096792433349462064[286] = 0;
   out_9096792433349462064[287] = 0;
   out_9096792433349462064[288] = 0;
   out_9096792433349462064[289] = 0;
   out_9096792433349462064[290] = 0;
   out_9096792433349462064[291] = 0;
   out_9096792433349462064[292] = 0;
   out_9096792433349462064[293] = 0;
   out_9096792433349462064[294] = 0;
   out_9096792433349462064[295] = 0;
   out_9096792433349462064[296] = 0;
   out_9096792433349462064[297] = 0;
   out_9096792433349462064[298] = 0;
   out_9096792433349462064[299] = 0;
   out_9096792433349462064[300] = 0;
   out_9096792433349462064[301] = 0;
   out_9096792433349462064[302] = 0;
   out_9096792433349462064[303] = 0;
   out_9096792433349462064[304] = 1;
   out_9096792433349462064[305] = 0;
   out_9096792433349462064[306] = 0;
   out_9096792433349462064[307] = 0;
   out_9096792433349462064[308] = 0;
   out_9096792433349462064[309] = 0;
   out_9096792433349462064[310] = 0;
   out_9096792433349462064[311] = 0;
   out_9096792433349462064[312] = 0;
   out_9096792433349462064[313] = 0;
   out_9096792433349462064[314] = 0;
   out_9096792433349462064[315] = 0;
   out_9096792433349462064[316] = 0;
   out_9096792433349462064[317] = 0;
   out_9096792433349462064[318] = 0;
   out_9096792433349462064[319] = 0;
   out_9096792433349462064[320] = 0;
   out_9096792433349462064[321] = 0;
   out_9096792433349462064[322] = 0;
   out_9096792433349462064[323] = 1;
}
void h_4(double *state, double *unused, double *out_2265781100835663155) {
   out_2265781100835663155[0] = state[6] + state[9];
   out_2265781100835663155[1] = state[7] + state[10];
   out_2265781100835663155[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8392468825100105284) {
   out_8392468825100105284[0] = 0;
   out_8392468825100105284[1] = 0;
   out_8392468825100105284[2] = 0;
   out_8392468825100105284[3] = 0;
   out_8392468825100105284[4] = 0;
   out_8392468825100105284[5] = 0;
   out_8392468825100105284[6] = 1;
   out_8392468825100105284[7] = 0;
   out_8392468825100105284[8] = 0;
   out_8392468825100105284[9] = 1;
   out_8392468825100105284[10] = 0;
   out_8392468825100105284[11] = 0;
   out_8392468825100105284[12] = 0;
   out_8392468825100105284[13] = 0;
   out_8392468825100105284[14] = 0;
   out_8392468825100105284[15] = 0;
   out_8392468825100105284[16] = 0;
   out_8392468825100105284[17] = 0;
   out_8392468825100105284[18] = 0;
   out_8392468825100105284[19] = 0;
   out_8392468825100105284[20] = 0;
   out_8392468825100105284[21] = 0;
   out_8392468825100105284[22] = 0;
   out_8392468825100105284[23] = 0;
   out_8392468825100105284[24] = 0;
   out_8392468825100105284[25] = 1;
   out_8392468825100105284[26] = 0;
   out_8392468825100105284[27] = 0;
   out_8392468825100105284[28] = 1;
   out_8392468825100105284[29] = 0;
   out_8392468825100105284[30] = 0;
   out_8392468825100105284[31] = 0;
   out_8392468825100105284[32] = 0;
   out_8392468825100105284[33] = 0;
   out_8392468825100105284[34] = 0;
   out_8392468825100105284[35] = 0;
   out_8392468825100105284[36] = 0;
   out_8392468825100105284[37] = 0;
   out_8392468825100105284[38] = 0;
   out_8392468825100105284[39] = 0;
   out_8392468825100105284[40] = 0;
   out_8392468825100105284[41] = 0;
   out_8392468825100105284[42] = 0;
   out_8392468825100105284[43] = 0;
   out_8392468825100105284[44] = 1;
   out_8392468825100105284[45] = 0;
   out_8392468825100105284[46] = 0;
   out_8392468825100105284[47] = 1;
   out_8392468825100105284[48] = 0;
   out_8392468825100105284[49] = 0;
   out_8392468825100105284[50] = 0;
   out_8392468825100105284[51] = 0;
   out_8392468825100105284[52] = 0;
   out_8392468825100105284[53] = 0;
}
void h_10(double *state, double *unused, double *out_316139620022094761) {
   out_316139620022094761[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_316139620022094761[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_316139620022094761[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3533745887327993443) {
   out_3533745887327993443[0] = 0;
   out_3533745887327993443[1] = 9.8100000000000005*cos(state[1]);
   out_3533745887327993443[2] = 0;
   out_3533745887327993443[3] = 0;
   out_3533745887327993443[4] = -state[8];
   out_3533745887327993443[5] = state[7];
   out_3533745887327993443[6] = 0;
   out_3533745887327993443[7] = state[5];
   out_3533745887327993443[8] = -state[4];
   out_3533745887327993443[9] = 0;
   out_3533745887327993443[10] = 0;
   out_3533745887327993443[11] = 0;
   out_3533745887327993443[12] = 1;
   out_3533745887327993443[13] = 0;
   out_3533745887327993443[14] = 0;
   out_3533745887327993443[15] = 1;
   out_3533745887327993443[16] = 0;
   out_3533745887327993443[17] = 0;
   out_3533745887327993443[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3533745887327993443[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3533745887327993443[20] = 0;
   out_3533745887327993443[21] = state[8];
   out_3533745887327993443[22] = 0;
   out_3533745887327993443[23] = -state[6];
   out_3533745887327993443[24] = -state[5];
   out_3533745887327993443[25] = 0;
   out_3533745887327993443[26] = state[3];
   out_3533745887327993443[27] = 0;
   out_3533745887327993443[28] = 0;
   out_3533745887327993443[29] = 0;
   out_3533745887327993443[30] = 0;
   out_3533745887327993443[31] = 1;
   out_3533745887327993443[32] = 0;
   out_3533745887327993443[33] = 0;
   out_3533745887327993443[34] = 1;
   out_3533745887327993443[35] = 0;
   out_3533745887327993443[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3533745887327993443[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3533745887327993443[38] = 0;
   out_3533745887327993443[39] = -state[7];
   out_3533745887327993443[40] = state[6];
   out_3533745887327993443[41] = 0;
   out_3533745887327993443[42] = state[4];
   out_3533745887327993443[43] = -state[3];
   out_3533745887327993443[44] = 0;
   out_3533745887327993443[45] = 0;
   out_3533745887327993443[46] = 0;
   out_3533745887327993443[47] = 0;
   out_3533745887327993443[48] = 0;
   out_3533745887327993443[49] = 0;
   out_3533745887327993443[50] = 1;
   out_3533745887327993443[51] = 0;
   out_3533745887327993443[52] = 0;
   out_3533745887327993443[53] = 1;
}
void h_13(double *state, double *unused, double *out_5506810827115614970) {
   out_5506810827115614970[0] = state[3];
   out_5506810827115614970[1] = state[4];
   out_5506810827115614970[2] = state[5];
}
void H_13(double *state, double *unused, double *out_781837616783404355) {
   out_781837616783404355[0] = 0;
   out_781837616783404355[1] = 0;
   out_781837616783404355[2] = 0;
   out_781837616783404355[3] = 1;
   out_781837616783404355[4] = 0;
   out_781837616783404355[5] = 0;
   out_781837616783404355[6] = 0;
   out_781837616783404355[7] = 0;
   out_781837616783404355[8] = 0;
   out_781837616783404355[9] = 0;
   out_781837616783404355[10] = 0;
   out_781837616783404355[11] = 0;
   out_781837616783404355[12] = 0;
   out_781837616783404355[13] = 0;
   out_781837616783404355[14] = 0;
   out_781837616783404355[15] = 0;
   out_781837616783404355[16] = 0;
   out_781837616783404355[17] = 0;
   out_781837616783404355[18] = 0;
   out_781837616783404355[19] = 0;
   out_781837616783404355[20] = 0;
   out_781837616783404355[21] = 0;
   out_781837616783404355[22] = 1;
   out_781837616783404355[23] = 0;
   out_781837616783404355[24] = 0;
   out_781837616783404355[25] = 0;
   out_781837616783404355[26] = 0;
   out_781837616783404355[27] = 0;
   out_781837616783404355[28] = 0;
   out_781837616783404355[29] = 0;
   out_781837616783404355[30] = 0;
   out_781837616783404355[31] = 0;
   out_781837616783404355[32] = 0;
   out_781837616783404355[33] = 0;
   out_781837616783404355[34] = 0;
   out_781837616783404355[35] = 0;
   out_781837616783404355[36] = 0;
   out_781837616783404355[37] = 0;
   out_781837616783404355[38] = 0;
   out_781837616783404355[39] = 0;
   out_781837616783404355[40] = 0;
   out_781837616783404355[41] = 1;
   out_781837616783404355[42] = 0;
   out_781837616783404355[43] = 0;
   out_781837616783404355[44] = 0;
   out_781837616783404355[45] = 0;
   out_781837616783404355[46] = 0;
   out_781837616783404355[47] = 0;
   out_781837616783404355[48] = 0;
   out_781837616783404355[49] = 0;
   out_781837616783404355[50] = 0;
   out_781837616783404355[51] = 0;
   out_781837616783404355[52] = 0;
   out_781837616783404355[53] = 0;
}
void h_14(double *state, double *unused, double *out_3429617090731340208) {
   out_3429617090731340208[0] = state[6];
   out_3429617090731340208[1] = state[7];
   out_3429617090731340208[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4429227968760620755) {
   out_4429227968760620755[0] = 0;
   out_4429227968760620755[1] = 0;
   out_4429227968760620755[2] = 0;
   out_4429227968760620755[3] = 0;
   out_4429227968760620755[4] = 0;
   out_4429227968760620755[5] = 0;
   out_4429227968760620755[6] = 1;
   out_4429227968760620755[7] = 0;
   out_4429227968760620755[8] = 0;
   out_4429227968760620755[9] = 0;
   out_4429227968760620755[10] = 0;
   out_4429227968760620755[11] = 0;
   out_4429227968760620755[12] = 0;
   out_4429227968760620755[13] = 0;
   out_4429227968760620755[14] = 0;
   out_4429227968760620755[15] = 0;
   out_4429227968760620755[16] = 0;
   out_4429227968760620755[17] = 0;
   out_4429227968760620755[18] = 0;
   out_4429227968760620755[19] = 0;
   out_4429227968760620755[20] = 0;
   out_4429227968760620755[21] = 0;
   out_4429227968760620755[22] = 0;
   out_4429227968760620755[23] = 0;
   out_4429227968760620755[24] = 0;
   out_4429227968760620755[25] = 1;
   out_4429227968760620755[26] = 0;
   out_4429227968760620755[27] = 0;
   out_4429227968760620755[28] = 0;
   out_4429227968760620755[29] = 0;
   out_4429227968760620755[30] = 0;
   out_4429227968760620755[31] = 0;
   out_4429227968760620755[32] = 0;
   out_4429227968760620755[33] = 0;
   out_4429227968760620755[34] = 0;
   out_4429227968760620755[35] = 0;
   out_4429227968760620755[36] = 0;
   out_4429227968760620755[37] = 0;
   out_4429227968760620755[38] = 0;
   out_4429227968760620755[39] = 0;
   out_4429227968760620755[40] = 0;
   out_4429227968760620755[41] = 0;
   out_4429227968760620755[42] = 0;
   out_4429227968760620755[43] = 0;
   out_4429227968760620755[44] = 1;
   out_4429227968760620755[45] = 0;
   out_4429227968760620755[46] = 0;
   out_4429227968760620755[47] = 0;
   out_4429227968760620755[48] = 0;
   out_4429227968760620755[49] = 0;
   out_4429227968760620755[50] = 0;
   out_4429227968760620755[51] = 0;
   out_4429227968760620755[52] = 0;
   out_4429227968760620755[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_4567767818172860295) {
  err_fun(nom_x, delta_x, out_4567767818172860295);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4613807108104960206) {
  inv_err_fun(nom_x, true_x, out_4613807108104960206);
}
void pose_H_mod_fun(double *state, double *out_6572770099193808423) {
  H_mod_fun(state, out_6572770099193808423);
}
void pose_f_fun(double *state, double dt, double *out_972215043360367871) {
  f_fun(state,  dt, out_972215043360367871);
}
void pose_F_fun(double *state, double dt, double *out_9096792433349462064) {
  F_fun(state,  dt, out_9096792433349462064);
}
void pose_h_4(double *state, double *unused, double *out_2265781100835663155) {
  h_4(state, unused, out_2265781100835663155);
}
void pose_H_4(double *state, double *unused, double *out_8392468825100105284) {
  H_4(state, unused, out_8392468825100105284);
}
void pose_h_10(double *state, double *unused, double *out_316139620022094761) {
  h_10(state, unused, out_316139620022094761);
}
void pose_H_10(double *state, double *unused, double *out_3533745887327993443) {
  H_10(state, unused, out_3533745887327993443);
}
void pose_h_13(double *state, double *unused, double *out_5506810827115614970) {
  h_13(state, unused, out_5506810827115614970);
}
void pose_H_13(double *state, double *unused, double *out_781837616783404355) {
  H_13(state, unused, out_781837616783404355);
}
void pose_h_14(double *state, double *unused, double *out_3429617090731340208) {
  h_14(state, unused, out_3429617090731340208);
}
void pose_H_14(double *state, double *unused, double *out_4429227968760620755) {
  H_14(state, unused, out_4429227968760620755);
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
