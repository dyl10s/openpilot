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
void err_fun(double *nom_x, double *delta_x, double *out_1416756098750413745) {
   out_1416756098750413745[0] = delta_x[0] + nom_x[0];
   out_1416756098750413745[1] = delta_x[1] + nom_x[1];
   out_1416756098750413745[2] = delta_x[2] + nom_x[2];
   out_1416756098750413745[3] = delta_x[3] + nom_x[3];
   out_1416756098750413745[4] = delta_x[4] + nom_x[4];
   out_1416756098750413745[5] = delta_x[5] + nom_x[5];
   out_1416756098750413745[6] = delta_x[6] + nom_x[6];
   out_1416756098750413745[7] = delta_x[7] + nom_x[7];
   out_1416756098750413745[8] = delta_x[8] + nom_x[8];
   out_1416756098750413745[9] = delta_x[9] + nom_x[9];
   out_1416756098750413745[10] = delta_x[10] + nom_x[10];
   out_1416756098750413745[11] = delta_x[11] + nom_x[11];
   out_1416756098750413745[12] = delta_x[12] + nom_x[12];
   out_1416756098750413745[13] = delta_x[13] + nom_x[13];
   out_1416756098750413745[14] = delta_x[14] + nom_x[14];
   out_1416756098750413745[15] = delta_x[15] + nom_x[15];
   out_1416756098750413745[16] = delta_x[16] + nom_x[16];
   out_1416756098750413745[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_288660278795817354) {
   out_288660278795817354[0] = -nom_x[0] + true_x[0];
   out_288660278795817354[1] = -nom_x[1] + true_x[1];
   out_288660278795817354[2] = -nom_x[2] + true_x[2];
   out_288660278795817354[3] = -nom_x[3] + true_x[3];
   out_288660278795817354[4] = -nom_x[4] + true_x[4];
   out_288660278795817354[5] = -nom_x[5] + true_x[5];
   out_288660278795817354[6] = -nom_x[6] + true_x[6];
   out_288660278795817354[7] = -nom_x[7] + true_x[7];
   out_288660278795817354[8] = -nom_x[8] + true_x[8];
   out_288660278795817354[9] = -nom_x[9] + true_x[9];
   out_288660278795817354[10] = -nom_x[10] + true_x[10];
   out_288660278795817354[11] = -nom_x[11] + true_x[11];
   out_288660278795817354[12] = -nom_x[12] + true_x[12];
   out_288660278795817354[13] = -nom_x[13] + true_x[13];
   out_288660278795817354[14] = -nom_x[14] + true_x[14];
   out_288660278795817354[15] = -nom_x[15] + true_x[15];
   out_288660278795817354[16] = -nom_x[16] + true_x[16];
   out_288660278795817354[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_8072626393727229290) {
   out_8072626393727229290[0] = 1.0;
   out_8072626393727229290[1] = 0.0;
   out_8072626393727229290[2] = 0.0;
   out_8072626393727229290[3] = 0.0;
   out_8072626393727229290[4] = 0.0;
   out_8072626393727229290[5] = 0.0;
   out_8072626393727229290[6] = 0.0;
   out_8072626393727229290[7] = 0.0;
   out_8072626393727229290[8] = 0.0;
   out_8072626393727229290[9] = 0.0;
   out_8072626393727229290[10] = 0.0;
   out_8072626393727229290[11] = 0.0;
   out_8072626393727229290[12] = 0.0;
   out_8072626393727229290[13] = 0.0;
   out_8072626393727229290[14] = 0.0;
   out_8072626393727229290[15] = 0.0;
   out_8072626393727229290[16] = 0.0;
   out_8072626393727229290[17] = 0.0;
   out_8072626393727229290[18] = 0.0;
   out_8072626393727229290[19] = 1.0;
   out_8072626393727229290[20] = 0.0;
   out_8072626393727229290[21] = 0.0;
   out_8072626393727229290[22] = 0.0;
   out_8072626393727229290[23] = 0.0;
   out_8072626393727229290[24] = 0.0;
   out_8072626393727229290[25] = 0.0;
   out_8072626393727229290[26] = 0.0;
   out_8072626393727229290[27] = 0.0;
   out_8072626393727229290[28] = 0.0;
   out_8072626393727229290[29] = 0.0;
   out_8072626393727229290[30] = 0.0;
   out_8072626393727229290[31] = 0.0;
   out_8072626393727229290[32] = 0.0;
   out_8072626393727229290[33] = 0.0;
   out_8072626393727229290[34] = 0.0;
   out_8072626393727229290[35] = 0.0;
   out_8072626393727229290[36] = 0.0;
   out_8072626393727229290[37] = 0.0;
   out_8072626393727229290[38] = 1.0;
   out_8072626393727229290[39] = 0.0;
   out_8072626393727229290[40] = 0.0;
   out_8072626393727229290[41] = 0.0;
   out_8072626393727229290[42] = 0.0;
   out_8072626393727229290[43] = 0.0;
   out_8072626393727229290[44] = 0.0;
   out_8072626393727229290[45] = 0.0;
   out_8072626393727229290[46] = 0.0;
   out_8072626393727229290[47] = 0.0;
   out_8072626393727229290[48] = 0.0;
   out_8072626393727229290[49] = 0.0;
   out_8072626393727229290[50] = 0.0;
   out_8072626393727229290[51] = 0.0;
   out_8072626393727229290[52] = 0.0;
   out_8072626393727229290[53] = 0.0;
   out_8072626393727229290[54] = 0.0;
   out_8072626393727229290[55] = 0.0;
   out_8072626393727229290[56] = 0.0;
   out_8072626393727229290[57] = 1.0;
   out_8072626393727229290[58] = 0.0;
   out_8072626393727229290[59] = 0.0;
   out_8072626393727229290[60] = 0.0;
   out_8072626393727229290[61] = 0.0;
   out_8072626393727229290[62] = 0.0;
   out_8072626393727229290[63] = 0.0;
   out_8072626393727229290[64] = 0.0;
   out_8072626393727229290[65] = 0.0;
   out_8072626393727229290[66] = 0.0;
   out_8072626393727229290[67] = 0.0;
   out_8072626393727229290[68] = 0.0;
   out_8072626393727229290[69] = 0.0;
   out_8072626393727229290[70] = 0.0;
   out_8072626393727229290[71] = 0.0;
   out_8072626393727229290[72] = 0.0;
   out_8072626393727229290[73] = 0.0;
   out_8072626393727229290[74] = 0.0;
   out_8072626393727229290[75] = 0.0;
   out_8072626393727229290[76] = 1.0;
   out_8072626393727229290[77] = 0.0;
   out_8072626393727229290[78] = 0.0;
   out_8072626393727229290[79] = 0.0;
   out_8072626393727229290[80] = 0.0;
   out_8072626393727229290[81] = 0.0;
   out_8072626393727229290[82] = 0.0;
   out_8072626393727229290[83] = 0.0;
   out_8072626393727229290[84] = 0.0;
   out_8072626393727229290[85] = 0.0;
   out_8072626393727229290[86] = 0.0;
   out_8072626393727229290[87] = 0.0;
   out_8072626393727229290[88] = 0.0;
   out_8072626393727229290[89] = 0.0;
   out_8072626393727229290[90] = 0.0;
   out_8072626393727229290[91] = 0.0;
   out_8072626393727229290[92] = 0.0;
   out_8072626393727229290[93] = 0.0;
   out_8072626393727229290[94] = 0.0;
   out_8072626393727229290[95] = 1.0;
   out_8072626393727229290[96] = 0.0;
   out_8072626393727229290[97] = 0.0;
   out_8072626393727229290[98] = 0.0;
   out_8072626393727229290[99] = 0.0;
   out_8072626393727229290[100] = 0.0;
   out_8072626393727229290[101] = 0.0;
   out_8072626393727229290[102] = 0.0;
   out_8072626393727229290[103] = 0.0;
   out_8072626393727229290[104] = 0.0;
   out_8072626393727229290[105] = 0.0;
   out_8072626393727229290[106] = 0.0;
   out_8072626393727229290[107] = 0.0;
   out_8072626393727229290[108] = 0.0;
   out_8072626393727229290[109] = 0.0;
   out_8072626393727229290[110] = 0.0;
   out_8072626393727229290[111] = 0.0;
   out_8072626393727229290[112] = 0.0;
   out_8072626393727229290[113] = 0.0;
   out_8072626393727229290[114] = 1.0;
   out_8072626393727229290[115] = 0.0;
   out_8072626393727229290[116] = 0.0;
   out_8072626393727229290[117] = 0.0;
   out_8072626393727229290[118] = 0.0;
   out_8072626393727229290[119] = 0.0;
   out_8072626393727229290[120] = 0.0;
   out_8072626393727229290[121] = 0.0;
   out_8072626393727229290[122] = 0.0;
   out_8072626393727229290[123] = 0.0;
   out_8072626393727229290[124] = 0.0;
   out_8072626393727229290[125] = 0.0;
   out_8072626393727229290[126] = 0.0;
   out_8072626393727229290[127] = 0.0;
   out_8072626393727229290[128] = 0.0;
   out_8072626393727229290[129] = 0.0;
   out_8072626393727229290[130] = 0.0;
   out_8072626393727229290[131] = 0.0;
   out_8072626393727229290[132] = 0.0;
   out_8072626393727229290[133] = 1.0;
   out_8072626393727229290[134] = 0.0;
   out_8072626393727229290[135] = 0.0;
   out_8072626393727229290[136] = 0.0;
   out_8072626393727229290[137] = 0.0;
   out_8072626393727229290[138] = 0.0;
   out_8072626393727229290[139] = 0.0;
   out_8072626393727229290[140] = 0.0;
   out_8072626393727229290[141] = 0.0;
   out_8072626393727229290[142] = 0.0;
   out_8072626393727229290[143] = 0.0;
   out_8072626393727229290[144] = 0.0;
   out_8072626393727229290[145] = 0.0;
   out_8072626393727229290[146] = 0.0;
   out_8072626393727229290[147] = 0.0;
   out_8072626393727229290[148] = 0.0;
   out_8072626393727229290[149] = 0.0;
   out_8072626393727229290[150] = 0.0;
   out_8072626393727229290[151] = 0.0;
   out_8072626393727229290[152] = 1.0;
   out_8072626393727229290[153] = 0.0;
   out_8072626393727229290[154] = 0.0;
   out_8072626393727229290[155] = 0.0;
   out_8072626393727229290[156] = 0.0;
   out_8072626393727229290[157] = 0.0;
   out_8072626393727229290[158] = 0.0;
   out_8072626393727229290[159] = 0.0;
   out_8072626393727229290[160] = 0.0;
   out_8072626393727229290[161] = 0.0;
   out_8072626393727229290[162] = 0.0;
   out_8072626393727229290[163] = 0.0;
   out_8072626393727229290[164] = 0.0;
   out_8072626393727229290[165] = 0.0;
   out_8072626393727229290[166] = 0.0;
   out_8072626393727229290[167] = 0.0;
   out_8072626393727229290[168] = 0.0;
   out_8072626393727229290[169] = 0.0;
   out_8072626393727229290[170] = 0.0;
   out_8072626393727229290[171] = 1.0;
   out_8072626393727229290[172] = 0.0;
   out_8072626393727229290[173] = 0.0;
   out_8072626393727229290[174] = 0.0;
   out_8072626393727229290[175] = 0.0;
   out_8072626393727229290[176] = 0.0;
   out_8072626393727229290[177] = 0.0;
   out_8072626393727229290[178] = 0.0;
   out_8072626393727229290[179] = 0.0;
   out_8072626393727229290[180] = 0.0;
   out_8072626393727229290[181] = 0.0;
   out_8072626393727229290[182] = 0.0;
   out_8072626393727229290[183] = 0.0;
   out_8072626393727229290[184] = 0.0;
   out_8072626393727229290[185] = 0.0;
   out_8072626393727229290[186] = 0.0;
   out_8072626393727229290[187] = 0.0;
   out_8072626393727229290[188] = 0.0;
   out_8072626393727229290[189] = 0.0;
   out_8072626393727229290[190] = 1.0;
   out_8072626393727229290[191] = 0.0;
   out_8072626393727229290[192] = 0.0;
   out_8072626393727229290[193] = 0.0;
   out_8072626393727229290[194] = 0.0;
   out_8072626393727229290[195] = 0.0;
   out_8072626393727229290[196] = 0.0;
   out_8072626393727229290[197] = 0.0;
   out_8072626393727229290[198] = 0.0;
   out_8072626393727229290[199] = 0.0;
   out_8072626393727229290[200] = 0.0;
   out_8072626393727229290[201] = 0.0;
   out_8072626393727229290[202] = 0.0;
   out_8072626393727229290[203] = 0.0;
   out_8072626393727229290[204] = 0.0;
   out_8072626393727229290[205] = 0.0;
   out_8072626393727229290[206] = 0.0;
   out_8072626393727229290[207] = 0.0;
   out_8072626393727229290[208] = 0.0;
   out_8072626393727229290[209] = 1.0;
   out_8072626393727229290[210] = 0.0;
   out_8072626393727229290[211] = 0.0;
   out_8072626393727229290[212] = 0.0;
   out_8072626393727229290[213] = 0.0;
   out_8072626393727229290[214] = 0.0;
   out_8072626393727229290[215] = 0.0;
   out_8072626393727229290[216] = 0.0;
   out_8072626393727229290[217] = 0.0;
   out_8072626393727229290[218] = 0.0;
   out_8072626393727229290[219] = 0.0;
   out_8072626393727229290[220] = 0.0;
   out_8072626393727229290[221] = 0.0;
   out_8072626393727229290[222] = 0.0;
   out_8072626393727229290[223] = 0.0;
   out_8072626393727229290[224] = 0.0;
   out_8072626393727229290[225] = 0.0;
   out_8072626393727229290[226] = 0.0;
   out_8072626393727229290[227] = 0.0;
   out_8072626393727229290[228] = 1.0;
   out_8072626393727229290[229] = 0.0;
   out_8072626393727229290[230] = 0.0;
   out_8072626393727229290[231] = 0.0;
   out_8072626393727229290[232] = 0.0;
   out_8072626393727229290[233] = 0.0;
   out_8072626393727229290[234] = 0.0;
   out_8072626393727229290[235] = 0.0;
   out_8072626393727229290[236] = 0.0;
   out_8072626393727229290[237] = 0.0;
   out_8072626393727229290[238] = 0.0;
   out_8072626393727229290[239] = 0.0;
   out_8072626393727229290[240] = 0.0;
   out_8072626393727229290[241] = 0.0;
   out_8072626393727229290[242] = 0.0;
   out_8072626393727229290[243] = 0.0;
   out_8072626393727229290[244] = 0.0;
   out_8072626393727229290[245] = 0.0;
   out_8072626393727229290[246] = 0.0;
   out_8072626393727229290[247] = 1.0;
   out_8072626393727229290[248] = 0.0;
   out_8072626393727229290[249] = 0.0;
   out_8072626393727229290[250] = 0.0;
   out_8072626393727229290[251] = 0.0;
   out_8072626393727229290[252] = 0.0;
   out_8072626393727229290[253] = 0.0;
   out_8072626393727229290[254] = 0.0;
   out_8072626393727229290[255] = 0.0;
   out_8072626393727229290[256] = 0.0;
   out_8072626393727229290[257] = 0.0;
   out_8072626393727229290[258] = 0.0;
   out_8072626393727229290[259] = 0.0;
   out_8072626393727229290[260] = 0.0;
   out_8072626393727229290[261] = 0.0;
   out_8072626393727229290[262] = 0.0;
   out_8072626393727229290[263] = 0.0;
   out_8072626393727229290[264] = 0.0;
   out_8072626393727229290[265] = 0.0;
   out_8072626393727229290[266] = 1.0;
   out_8072626393727229290[267] = 0.0;
   out_8072626393727229290[268] = 0.0;
   out_8072626393727229290[269] = 0.0;
   out_8072626393727229290[270] = 0.0;
   out_8072626393727229290[271] = 0.0;
   out_8072626393727229290[272] = 0.0;
   out_8072626393727229290[273] = 0.0;
   out_8072626393727229290[274] = 0.0;
   out_8072626393727229290[275] = 0.0;
   out_8072626393727229290[276] = 0.0;
   out_8072626393727229290[277] = 0.0;
   out_8072626393727229290[278] = 0.0;
   out_8072626393727229290[279] = 0.0;
   out_8072626393727229290[280] = 0.0;
   out_8072626393727229290[281] = 0.0;
   out_8072626393727229290[282] = 0.0;
   out_8072626393727229290[283] = 0.0;
   out_8072626393727229290[284] = 0.0;
   out_8072626393727229290[285] = 1.0;
   out_8072626393727229290[286] = 0.0;
   out_8072626393727229290[287] = 0.0;
   out_8072626393727229290[288] = 0.0;
   out_8072626393727229290[289] = 0.0;
   out_8072626393727229290[290] = 0.0;
   out_8072626393727229290[291] = 0.0;
   out_8072626393727229290[292] = 0.0;
   out_8072626393727229290[293] = 0.0;
   out_8072626393727229290[294] = 0.0;
   out_8072626393727229290[295] = 0.0;
   out_8072626393727229290[296] = 0.0;
   out_8072626393727229290[297] = 0.0;
   out_8072626393727229290[298] = 0.0;
   out_8072626393727229290[299] = 0.0;
   out_8072626393727229290[300] = 0.0;
   out_8072626393727229290[301] = 0.0;
   out_8072626393727229290[302] = 0.0;
   out_8072626393727229290[303] = 0.0;
   out_8072626393727229290[304] = 1.0;
   out_8072626393727229290[305] = 0.0;
   out_8072626393727229290[306] = 0.0;
   out_8072626393727229290[307] = 0.0;
   out_8072626393727229290[308] = 0.0;
   out_8072626393727229290[309] = 0.0;
   out_8072626393727229290[310] = 0.0;
   out_8072626393727229290[311] = 0.0;
   out_8072626393727229290[312] = 0.0;
   out_8072626393727229290[313] = 0.0;
   out_8072626393727229290[314] = 0.0;
   out_8072626393727229290[315] = 0.0;
   out_8072626393727229290[316] = 0.0;
   out_8072626393727229290[317] = 0.0;
   out_8072626393727229290[318] = 0.0;
   out_8072626393727229290[319] = 0.0;
   out_8072626393727229290[320] = 0.0;
   out_8072626393727229290[321] = 0.0;
   out_8072626393727229290[322] = 0.0;
   out_8072626393727229290[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3550739231859078198) {
   out_3550739231859078198[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3550739231859078198[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3550739231859078198[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3550739231859078198[3] = dt*state[12] + state[3];
   out_3550739231859078198[4] = dt*state[13] + state[4];
   out_3550739231859078198[5] = dt*state[14] + state[5];
   out_3550739231859078198[6] = state[6];
   out_3550739231859078198[7] = state[7];
   out_3550739231859078198[8] = state[8];
   out_3550739231859078198[9] = state[9];
   out_3550739231859078198[10] = state[10];
   out_3550739231859078198[11] = state[11];
   out_3550739231859078198[12] = state[12];
   out_3550739231859078198[13] = state[13];
   out_3550739231859078198[14] = state[14];
   out_3550739231859078198[15] = state[15];
   out_3550739231859078198[16] = state[16];
   out_3550739231859078198[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4236350099338455825) {
   out_4236350099338455825[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4236350099338455825[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4236350099338455825[2] = 0;
   out_4236350099338455825[3] = 0;
   out_4236350099338455825[4] = 0;
   out_4236350099338455825[5] = 0;
   out_4236350099338455825[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4236350099338455825[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4236350099338455825[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4236350099338455825[9] = 0;
   out_4236350099338455825[10] = 0;
   out_4236350099338455825[11] = 0;
   out_4236350099338455825[12] = 0;
   out_4236350099338455825[13] = 0;
   out_4236350099338455825[14] = 0;
   out_4236350099338455825[15] = 0;
   out_4236350099338455825[16] = 0;
   out_4236350099338455825[17] = 0;
   out_4236350099338455825[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4236350099338455825[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4236350099338455825[20] = 0;
   out_4236350099338455825[21] = 0;
   out_4236350099338455825[22] = 0;
   out_4236350099338455825[23] = 0;
   out_4236350099338455825[24] = 0;
   out_4236350099338455825[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4236350099338455825[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4236350099338455825[27] = 0;
   out_4236350099338455825[28] = 0;
   out_4236350099338455825[29] = 0;
   out_4236350099338455825[30] = 0;
   out_4236350099338455825[31] = 0;
   out_4236350099338455825[32] = 0;
   out_4236350099338455825[33] = 0;
   out_4236350099338455825[34] = 0;
   out_4236350099338455825[35] = 0;
   out_4236350099338455825[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4236350099338455825[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4236350099338455825[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4236350099338455825[39] = 0;
   out_4236350099338455825[40] = 0;
   out_4236350099338455825[41] = 0;
   out_4236350099338455825[42] = 0;
   out_4236350099338455825[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4236350099338455825[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4236350099338455825[45] = 0;
   out_4236350099338455825[46] = 0;
   out_4236350099338455825[47] = 0;
   out_4236350099338455825[48] = 0;
   out_4236350099338455825[49] = 0;
   out_4236350099338455825[50] = 0;
   out_4236350099338455825[51] = 0;
   out_4236350099338455825[52] = 0;
   out_4236350099338455825[53] = 0;
   out_4236350099338455825[54] = 0;
   out_4236350099338455825[55] = 0;
   out_4236350099338455825[56] = 0;
   out_4236350099338455825[57] = 1;
   out_4236350099338455825[58] = 0;
   out_4236350099338455825[59] = 0;
   out_4236350099338455825[60] = 0;
   out_4236350099338455825[61] = 0;
   out_4236350099338455825[62] = 0;
   out_4236350099338455825[63] = 0;
   out_4236350099338455825[64] = 0;
   out_4236350099338455825[65] = 0;
   out_4236350099338455825[66] = dt;
   out_4236350099338455825[67] = 0;
   out_4236350099338455825[68] = 0;
   out_4236350099338455825[69] = 0;
   out_4236350099338455825[70] = 0;
   out_4236350099338455825[71] = 0;
   out_4236350099338455825[72] = 0;
   out_4236350099338455825[73] = 0;
   out_4236350099338455825[74] = 0;
   out_4236350099338455825[75] = 0;
   out_4236350099338455825[76] = 1;
   out_4236350099338455825[77] = 0;
   out_4236350099338455825[78] = 0;
   out_4236350099338455825[79] = 0;
   out_4236350099338455825[80] = 0;
   out_4236350099338455825[81] = 0;
   out_4236350099338455825[82] = 0;
   out_4236350099338455825[83] = 0;
   out_4236350099338455825[84] = 0;
   out_4236350099338455825[85] = dt;
   out_4236350099338455825[86] = 0;
   out_4236350099338455825[87] = 0;
   out_4236350099338455825[88] = 0;
   out_4236350099338455825[89] = 0;
   out_4236350099338455825[90] = 0;
   out_4236350099338455825[91] = 0;
   out_4236350099338455825[92] = 0;
   out_4236350099338455825[93] = 0;
   out_4236350099338455825[94] = 0;
   out_4236350099338455825[95] = 1;
   out_4236350099338455825[96] = 0;
   out_4236350099338455825[97] = 0;
   out_4236350099338455825[98] = 0;
   out_4236350099338455825[99] = 0;
   out_4236350099338455825[100] = 0;
   out_4236350099338455825[101] = 0;
   out_4236350099338455825[102] = 0;
   out_4236350099338455825[103] = 0;
   out_4236350099338455825[104] = dt;
   out_4236350099338455825[105] = 0;
   out_4236350099338455825[106] = 0;
   out_4236350099338455825[107] = 0;
   out_4236350099338455825[108] = 0;
   out_4236350099338455825[109] = 0;
   out_4236350099338455825[110] = 0;
   out_4236350099338455825[111] = 0;
   out_4236350099338455825[112] = 0;
   out_4236350099338455825[113] = 0;
   out_4236350099338455825[114] = 1;
   out_4236350099338455825[115] = 0;
   out_4236350099338455825[116] = 0;
   out_4236350099338455825[117] = 0;
   out_4236350099338455825[118] = 0;
   out_4236350099338455825[119] = 0;
   out_4236350099338455825[120] = 0;
   out_4236350099338455825[121] = 0;
   out_4236350099338455825[122] = 0;
   out_4236350099338455825[123] = 0;
   out_4236350099338455825[124] = 0;
   out_4236350099338455825[125] = 0;
   out_4236350099338455825[126] = 0;
   out_4236350099338455825[127] = 0;
   out_4236350099338455825[128] = 0;
   out_4236350099338455825[129] = 0;
   out_4236350099338455825[130] = 0;
   out_4236350099338455825[131] = 0;
   out_4236350099338455825[132] = 0;
   out_4236350099338455825[133] = 1;
   out_4236350099338455825[134] = 0;
   out_4236350099338455825[135] = 0;
   out_4236350099338455825[136] = 0;
   out_4236350099338455825[137] = 0;
   out_4236350099338455825[138] = 0;
   out_4236350099338455825[139] = 0;
   out_4236350099338455825[140] = 0;
   out_4236350099338455825[141] = 0;
   out_4236350099338455825[142] = 0;
   out_4236350099338455825[143] = 0;
   out_4236350099338455825[144] = 0;
   out_4236350099338455825[145] = 0;
   out_4236350099338455825[146] = 0;
   out_4236350099338455825[147] = 0;
   out_4236350099338455825[148] = 0;
   out_4236350099338455825[149] = 0;
   out_4236350099338455825[150] = 0;
   out_4236350099338455825[151] = 0;
   out_4236350099338455825[152] = 1;
   out_4236350099338455825[153] = 0;
   out_4236350099338455825[154] = 0;
   out_4236350099338455825[155] = 0;
   out_4236350099338455825[156] = 0;
   out_4236350099338455825[157] = 0;
   out_4236350099338455825[158] = 0;
   out_4236350099338455825[159] = 0;
   out_4236350099338455825[160] = 0;
   out_4236350099338455825[161] = 0;
   out_4236350099338455825[162] = 0;
   out_4236350099338455825[163] = 0;
   out_4236350099338455825[164] = 0;
   out_4236350099338455825[165] = 0;
   out_4236350099338455825[166] = 0;
   out_4236350099338455825[167] = 0;
   out_4236350099338455825[168] = 0;
   out_4236350099338455825[169] = 0;
   out_4236350099338455825[170] = 0;
   out_4236350099338455825[171] = 1;
   out_4236350099338455825[172] = 0;
   out_4236350099338455825[173] = 0;
   out_4236350099338455825[174] = 0;
   out_4236350099338455825[175] = 0;
   out_4236350099338455825[176] = 0;
   out_4236350099338455825[177] = 0;
   out_4236350099338455825[178] = 0;
   out_4236350099338455825[179] = 0;
   out_4236350099338455825[180] = 0;
   out_4236350099338455825[181] = 0;
   out_4236350099338455825[182] = 0;
   out_4236350099338455825[183] = 0;
   out_4236350099338455825[184] = 0;
   out_4236350099338455825[185] = 0;
   out_4236350099338455825[186] = 0;
   out_4236350099338455825[187] = 0;
   out_4236350099338455825[188] = 0;
   out_4236350099338455825[189] = 0;
   out_4236350099338455825[190] = 1;
   out_4236350099338455825[191] = 0;
   out_4236350099338455825[192] = 0;
   out_4236350099338455825[193] = 0;
   out_4236350099338455825[194] = 0;
   out_4236350099338455825[195] = 0;
   out_4236350099338455825[196] = 0;
   out_4236350099338455825[197] = 0;
   out_4236350099338455825[198] = 0;
   out_4236350099338455825[199] = 0;
   out_4236350099338455825[200] = 0;
   out_4236350099338455825[201] = 0;
   out_4236350099338455825[202] = 0;
   out_4236350099338455825[203] = 0;
   out_4236350099338455825[204] = 0;
   out_4236350099338455825[205] = 0;
   out_4236350099338455825[206] = 0;
   out_4236350099338455825[207] = 0;
   out_4236350099338455825[208] = 0;
   out_4236350099338455825[209] = 1;
   out_4236350099338455825[210] = 0;
   out_4236350099338455825[211] = 0;
   out_4236350099338455825[212] = 0;
   out_4236350099338455825[213] = 0;
   out_4236350099338455825[214] = 0;
   out_4236350099338455825[215] = 0;
   out_4236350099338455825[216] = 0;
   out_4236350099338455825[217] = 0;
   out_4236350099338455825[218] = 0;
   out_4236350099338455825[219] = 0;
   out_4236350099338455825[220] = 0;
   out_4236350099338455825[221] = 0;
   out_4236350099338455825[222] = 0;
   out_4236350099338455825[223] = 0;
   out_4236350099338455825[224] = 0;
   out_4236350099338455825[225] = 0;
   out_4236350099338455825[226] = 0;
   out_4236350099338455825[227] = 0;
   out_4236350099338455825[228] = 1;
   out_4236350099338455825[229] = 0;
   out_4236350099338455825[230] = 0;
   out_4236350099338455825[231] = 0;
   out_4236350099338455825[232] = 0;
   out_4236350099338455825[233] = 0;
   out_4236350099338455825[234] = 0;
   out_4236350099338455825[235] = 0;
   out_4236350099338455825[236] = 0;
   out_4236350099338455825[237] = 0;
   out_4236350099338455825[238] = 0;
   out_4236350099338455825[239] = 0;
   out_4236350099338455825[240] = 0;
   out_4236350099338455825[241] = 0;
   out_4236350099338455825[242] = 0;
   out_4236350099338455825[243] = 0;
   out_4236350099338455825[244] = 0;
   out_4236350099338455825[245] = 0;
   out_4236350099338455825[246] = 0;
   out_4236350099338455825[247] = 1;
   out_4236350099338455825[248] = 0;
   out_4236350099338455825[249] = 0;
   out_4236350099338455825[250] = 0;
   out_4236350099338455825[251] = 0;
   out_4236350099338455825[252] = 0;
   out_4236350099338455825[253] = 0;
   out_4236350099338455825[254] = 0;
   out_4236350099338455825[255] = 0;
   out_4236350099338455825[256] = 0;
   out_4236350099338455825[257] = 0;
   out_4236350099338455825[258] = 0;
   out_4236350099338455825[259] = 0;
   out_4236350099338455825[260] = 0;
   out_4236350099338455825[261] = 0;
   out_4236350099338455825[262] = 0;
   out_4236350099338455825[263] = 0;
   out_4236350099338455825[264] = 0;
   out_4236350099338455825[265] = 0;
   out_4236350099338455825[266] = 1;
   out_4236350099338455825[267] = 0;
   out_4236350099338455825[268] = 0;
   out_4236350099338455825[269] = 0;
   out_4236350099338455825[270] = 0;
   out_4236350099338455825[271] = 0;
   out_4236350099338455825[272] = 0;
   out_4236350099338455825[273] = 0;
   out_4236350099338455825[274] = 0;
   out_4236350099338455825[275] = 0;
   out_4236350099338455825[276] = 0;
   out_4236350099338455825[277] = 0;
   out_4236350099338455825[278] = 0;
   out_4236350099338455825[279] = 0;
   out_4236350099338455825[280] = 0;
   out_4236350099338455825[281] = 0;
   out_4236350099338455825[282] = 0;
   out_4236350099338455825[283] = 0;
   out_4236350099338455825[284] = 0;
   out_4236350099338455825[285] = 1;
   out_4236350099338455825[286] = 0;
   out_4236350099338455825[287] = 0;
   out_4236350099338455825[288] = 0;
   out_4236350099338455825[289] = 0;
   out_4236350099338455825[290] = 0;
   out_4236350099338455825[291] = 0;
   out_4236350099338455825[292] = 0;
   out_4236350099338455825[293] = 0;
   out_4236350099338455825[294] = 0;
   out_4236350099338455825[295] = 0;
   out_4236350099338455825[296] = 0;
   out_4236350099338455825[297] = 0;
   out_4236350099338455825[298] = 0;
   out_4236350099338455825[299] = 0;
   out_4236350099338455825[300] = 0;
   out_4236350099338455825[301] = 0;
   out_4236350099338455825[302] = 0;
   out_4236350099338455825[303] = 0;
   out_4236350099338455825[304] = 1;
   out_4236350099338455825[305] = 0;
   out_4236350099338455825[306] = 0;
   out_4236350099338455825[307] = 0;
   out_4236350099338455825[308] = 0;
   out_4236350099338455825[309] = 0;
   out_4236350099338455825[310] = 0;
   out_4236350099338455825[311] = 0;
   out_4236350099338455825[312] = 0;
   out_4236350099338455825[313] = 0;
   out_4236350099338455825[314] = 0;
   out_4236350099338455825[315] = 0;
   out_4236350099338455825[316] = 0;
   out_4236350099338455825[317] = 0;
   out_4236350099338455825[318] = 0;
   out_4236350099338455825[319] = 0;
   out_4236350099338455825[320] = 0;
   out_4236350099338455825[321] = 0;
   out_4236350099338455825[322] = 0;
   out_4236350099338455825[323] = 1;
}
void h_4(double *state, double *unused, double *out_2031088737794184983) {
   out_2031088737794184983[0] = state[6] + state[9];
   out_2031088737794184983[1] = state[7] + state[10];
   out_2031088737794184983[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6602310470138414754) {
   out_6602310470138414754[0] = 0;
   out_6602310470138414754[1] = 0;
   out_6602310470138414754[2] = 0;
   out_6602310470138414754[3] = 0;
   out_6602310470138414754[4] = 0;
   out_6602310470138414754[5] = 0;
   out_6602310470138414754[6] = 1;
   out_6602310470138414754[7] = 0;
   out_6602310470138414754[8] = 0;
   out_6602310470138414754[9] = 1;
   out_6602310470138414754[10] = 0;
   out_6602310470138414754[11] = 0;
   out_6602310470138414754[12] = 0;
   out_6602310470138414754[13] = 0;
   out_6602310470138414754[14] = 0;
   out_6602310470138414754[15] = 0;
   out_6602310470138414754[16] = 0;
   out_6602310470138414754[17] = 0;
   out_6602310470138414754[18] = 0;
   out_6602310470138414754[19] = 0;
   out_6602310470138414754[20] = 0;
   out_6602310470138414754[21] = 0;
   out_6602310470138414754[22] = 0;
   out_6602310470138414754[23] = 0;
   out_6602310470138414754[24] = 0;
   out_6602310470138414754[25] = 1;
   out_6602310470138414754[26] = 0;
   out_6602310470138414754[27] = 0;
   out_6602310470138414754[28] = 1;
   out_6602310470138414754[29] = 0;
   out_6602310470138414754[30] = 0;
   out_6602310470138414754[31] = 0;
   out_6602310470138414754[32] = 0;
   out_6602310470138414754[33] = 0;
   out_6602310470138414754[34] = 0;
   out_6602310470138414754[35] = 0;
   out_6602310470138414754[36] = 0;
   out_6602310470138414754[37] = 0;
   out_6602310470138414754[38] = 0;
   out_6602310470138414754[39] = 0;
   out_6602310470138414754[40] = 0;
   out_6602310470138414754[41] = 0;
   out_6602310470138414754[42] = 0;
   out_6602310470138414754[43] = 0;
   out_6602310470138414754[44] = 1;
   out_6602310470138414754[45] = 0;
   out_6602310470138414754[46] = 0;
   out_6602310470138414754[47] = 1;
   out_6602310470138414754[48] = 0;
   out_6602310470138414754[49] = 0;
   out_6602310470138414754[50] = 0;
   out_6602310470138414754[51] = 0;
   out_6602310470138414754[52] = 0;
   out_6602310470138414754[53] = 0;
}
void h_10(double *state, double *unused, double *out_2254252755933878198) {
   out_2254252755933878198[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2254252755933878198[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2254252755933878198[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4753607725561450752) {
   out_4753607725561450752[0] = 0;
   out_4753607725561450752[1] = 9.8100000000000005*cos(state[1]);
   out_4753607725561450752[2] = 0;
   out_4753607725561450752[3] = 0;
   out_4753607725561450752[4] = -state[8];
   out_4753607725561450752[5] = state[7];
   out_4753607725561450752[6] = 0;
   out_4753607725561450752[7] = state[5];
   out_4753607725561450752[8] = -state[4];
   out_4753607725561450752[9] = 0;
   out_4753607725561450752[10] = 0;
   out_4753607725561450752[11] = 0;
   out_4753607725561450752[12] = 1;
   out_4753607725561450752[13] = 0;
   out_4753607725561450752[14] = 0;
   out_4753607725561450752[15] = 1;
   out_4753607725561450752[16] = 0;
   out_4753607725561450752[17] = 0;
   out_4753607725561450752[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4753607725561450752[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4753607725561450752[20] = 0;
   out_4753607725561450752[21] = state[8];
   out_4753607725561450752[22] = 0;
   out_4753607725561450752[23] = -state[6];
   out_4753607725561450752[24] = -state[5];
   out_4753607725561450752[25] = 0;
   out_4753607725561450752[26] = state[3];
   out_4753607725561450752[27] = 0;
   out_4753607725561450752[28] = 0;
   out_4753607725561450752[29] = 0;
   out_4753607725561450752[30] = 0;
   out_4753607725561450752[31] = 1;
   out_4753607725561450752[32] = 0;
   out_4753607725561450752[33] = 0;
   out_4753607725561450752[34] = 1;
   out_4753607725561450752[35] = 0;
   out_4753607725561450752[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4753607725561450752[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4753607725561450752[38] = 0;
   out_4753607725561450752[39] = -state[7];
   out_4753607725561450752[40] = state[6];
   out_4753607725561450752[41] = 0;
   out_4753607725561450752[42] = state[4];
   out_4753607725561450752[43] = -state[3];
   out_4753607725561450752[44] = 0;
   out_4753607725561450752[45] = 0;
   out_4753607725561450752[46] = 0;
   out_4753607725561450752[47] = 0;
   out_4753607725561450752[48] = 0;
   out_4753607725561450752[49] = 0;
   out_4753607725561450752[50] = 1;
   out_4753607725561450752[51] = 0;
   out_4753607725561450752[52] = 0;
   out_4753607725561450752[53] = 1;
}
void h_13(double *state, double *unused, double *out_561467872228044768) {
   out_561467872228044768[0] = state[3];
   out_561467872228044768[1] = state[4];
   out_561467872228044768[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3390036644806081953) {
   out_3390036644806081953[0] = 0;
   out_3390036644806081953[1] = 0;
   out_3390036644806081953[2] = 0;
   out_3390036644806081953[3] = 1;
   out_3390036644806081953[4] = 0;
   out_3390036644806081953[5] = 0;
   out_3390036644806081953[6] = 0;
   out_3390036644806081953[7] = 0;
   out_3390036644806081953[8] = 0;
   out_3390036644806081953[9] = 0;
   out_3390036644806081953[10] = 0;
   out_3390036644806081953[11] = 0;
   out_3390036644806081953[12] = 0;
   out_3390036644806081953[13] = 0;
   out_3390036644806081953[14] = 0;
   out_3390036644806081953[15] = 0;
   out_3390036644806081953[16] = 0;
   out_3390036644806081953[17] = 0;
   out_3390036644806081953[18] = 0;
   out_3390036644806081953[19] = 0;
   out_3390036644806081953[20] = 0;
   out_3390036644806081953[21] = 0;
   out_3390036644806081953[22] = 1;
   out_3390036644806081953[23] = 0;
   out_3390036644806081953[24] = 0;
   out_3390036644806081953[25] = 0;
   out_3390036644806081953[26] = 0;
   out_3390036644806081953[27] = 0;
   out_3390036644806081953[28] = 0;
   out_3390036644806081953[29] = 0;
   out_3390036644806081953[30] = 0;
   out_3390036644806081953[31] = 0;
   out_3390036644806081953[32] = 0;
   out_3390036644806081953[33] = 0;
   out_3390036644806081953[34] = 0;
   out_3390036644806081953[35] = 0;
   out_3390036644806081953[36] = 0;
   out_3390036644806081953[37] = 0;
   out_3390036644806081953[38] = 0;
   out_3390036644806081953[39] = 0;
   out_3390036644806081953[40] = 0;
   out_3390036644806081953[41] = 1;
   out_3390036644806081953[42] = 0;
   out_3390036644806081953[43] = 0;
   out_3390036644806081953[44] = 0;
   out_3390036644806081953[45] = 0;
   out_3390036644806081953[46] = 0;
   out_3390036644806081953[47] = 0;
   out_3390036644806081953[48] = 0;
   out_3390036644806081953[49] = 0;
   out_3390036644806081953[50] = 0;
   out_3390036644806081953[51] = 0;
   out_3390036644806081953[52] = 0;
   out_3390036644806081953[53] = 0;
}
void h_14(double *state, double *unused, double *out_5074055792402957007) {
   out_5074055792402957007[0] = state[6];
   out_5074055792402957007[1] = state[7];
   out_5074055792402957007[2] = state[8];
}
void H_14(double *state, double *unused, double *out_8761645171275764566) {
   out_8761645171275764566[0] = 0;
   out_8761645171275764566[1] = 0;
   out_8761645171275764566[2] = 0;
   out_8761645171275764566[3] = 0;
   out_8761645171275764566[4] = 0;
   out_8761645171275764566[5] = 0;
   out_8761645171275764566[6] = 1;
   out_8761645171275764566[7] = 0;
   out_8761645171275764566[8] = 0;
   out_8761645171275764566[9] = 0;
   out_8761645171275764566[10] = 0;
   out_8761645171275764566[11] = 0;
   out_8761645171275764566[12] = 0;
   out_8761645171275764566[13] = 0;
   out_8761645171275764566[14] = 0;
   out_8761645171275764566[15] = 0;
   out_8761645171275764566[16] = 0;
   out_8761645171275764566[17] = 0;
   out_8761645171275764566[18] = 0;
   out_8761645171275764566[19] = 0;
   out_8761645171275764566[20] = 0;
   out_8761645171275764566[21] = 0;
   out_8761645171275764566[22] = 0;
   out_8761645171275764566[23] = 0;
   out_8761645171275764566[24] = 0;
   out_8761645171275764566[25] = 1;
   out_8761645171275764566[26] = 0;
   out_8761645171275764566[27] = 0;
   out_8761645171275764566[28] = 0;
   out_8761645171275764566[29] = 0;
   out_8761645171275764566[30] = 0;
   out_8761645171275764566[31] = 0;
   out_8761645171275764566[32] = 0;
   out_8761645171275764566[33] = 0;
   out_8761645171275764566[34] = 0;
   out_8761645171275764566[35] = 0;
   out_8761645171275764566[36] = 0;
   out_8761645171275764566[37] = 0;
   out_8761645171275764566[38] = 0;
   out_8761645171275764566[39] = 0;
   out_8761645171275764566[40] = 0;
   out_8761645171275764566[41] = 0;
   out_8761645171275764566[42] = 0;
   out_8761645171275764566[43] = 0;
   out_8761645171275764566[44] = 1;
   out_8761645171275764566[45] = 0;
   out_8761645171275764566[46] = 0;
   out_8761645171275764566[47] = 0;
   out_8761645171275764566[48] = 0;
   out_8761645171275764566[49] = 0;
   out_8761645171275764566[50] = 0;
   out_8761645171275764566[51] = 0;
   out_8761645171275764566[52] = 0;
   out_8761645171275764566[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_1416756098750413745) {
  err_fun(nom_x, delta_x, out_1416756098750413745);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_288660278795817354) {
  inv_err_fun(nom_x, true_x, out_288660278795817354);
}
void pose_H_mod_fun(double *state, double *out_8072626393727229290) {
  H_mod_fun(state, out_8072626393727229290);
}
void pose_f_fun(double *state, double dt, double *out_3550739231859078198) {
  f_fun(state,  dt, out_3550739231859078198);
}
void pose_F_fun(double *state, double dt, double *out_4236350099338455825) {
  F_fun(state,  dt, out_4236350099338455825);
}
void pose_h_4(double *state, double *unused, double *out_2031088737794184983) {
  h_4(state, unused, out_2031088737794184983);
}
void pose_H_4(double *state, double *unused, double *out_6602310470138414754) {
  H_4(state, unused, out_6602310470138414754);
}
void pose_h_10(double *state, double *unused, double *out_2254252755933878198) {
  h_10(state, unused, out_2254252755933878198);
}
void pose_H_10(double *state, double *unused, double *out_4753607725561450752) {
  H_10(state, unused, out_4753607725561450752);
}
void pose_h_13(double *state, double *unused, double *out_561467872228044768) {
  h_13(state, unused, out_561467872228044768);
}
void pose_H_13(double *state, double *unused, double *out_3390036644806081953) {
  H_13(state, unused, out_3390036644806081953);
}
void pose_h_14(double *state, double *unused, double *out_5074055792402957007) {
  h_14(state, unused, out_5074055792402957007);
}
void pose_H_14(double *state, double *unused, double *out_8761645171275764566) {
  H_14(state, unused, out_8761645171275764566);
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
