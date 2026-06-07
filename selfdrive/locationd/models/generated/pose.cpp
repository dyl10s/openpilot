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
void err_fun(double *nom_x, double *delta_x, double *out_4711793940499862270) {
   out_4711793940499862270[0] = delta_x[0] + nom_x[0];
   out_4711793940499862270[1] = delta_x[1] + nom_x[1];
   out_4711793940499862270[2] = delta_x[2] + nom_x[2];
   out_4711793940499862270[3] = delta_x[3] + nom_x[3];
   out_4711793940499862270[4] = delta_x[4] + nom_x[4];
   out_4711793940499862270[5] = delta_x[5] + nom_x[5];
   out_4711793940499862270[6] = delta_x[6] + nom_x[6];
   out_4711793940499862270[7] = delta_x[7] + nom_x[7];
   out_4711793940499862270[8] = delta_x[8] + nom_x[8];
   out_4711793940499862270[9] = delta_x[9] + nom_x[9];
   out_4711793940499862270[10] = delta_x[10] + nom_x[10];
   out_4711793940499862270[11] = delta_x[11] + nom_x[11];
   out_4711793940499862270[12] = delta_x[12] + nom_x[12];
   out_4711793940499862270[13] = delta_x[13] + nom_x[13];
   out_4711793940499862270[14] = delta_x[14] + nom_x[14];
   out_4711793940499862270[15] = delta_x[15] + nom_x[15];
   out_4711793940499862270[16] = delta_x[16] + nom_x[16];
   out_4711793940499862270[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8790106481935061031) {
   out_8790106481935061031[0] = -nom_x[0] + true_x[0];
   out_8790106481935061031[1] = -nom_x[1] + true_x[1];
   out_8790106481935061031[2] = -nom_x[2] + true_x[2];
   out_8790106481935061031[3] = -nom_x[3] + true_x[3];
   out_8790106481935061031[4] = -nom_x[4] + true_x[4];
   out_8790106481935061031[5] = -nom_x[5] + true_x[5];
   out_8790106481935061031[6] = -nom_x[6] + true_x[6];
   out_8790106481935061031[7] = -nom_x[7] + true_x[7];
   out_8790106481935061031[8] = -nom_x[8] + true_x[8];
   out_8790106481935061031[9] = -nom_x[9] + true_x[9];
   out_8790106481935061031[10] = -nom_x[10] + true_x[10];
   out_8790106481935061031[11] = -nom_x[11] + true_x[11];
   out_8790106481935061031[12] = -nom_x[12] + true_x[12];
   out_8790106481935061031[13] = -nom_x[13] + true_x[13];
   out_8790106481935061031[14] = -nom_x[14] + true_x[14];
   out_8790106481935061031[15] = -nom_x[15] + true_x[15];
   out_8790106481935061031[16] = -nom_x[16] + true_x[16];
   out_8790106481935061031[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3710500625877642434) {
   out_3710500625877642434[0] = 1.0;
   out_3710500625877642434[1] = 0.0;
   out_3710500625877642434[2] = 0.0;
   out_3710500625877642434[3] = 0.0;
   out_3710500625877642434[4] = 0.0;
   out_3710500625877642434[5] = 0.0;
   out_3710500625877642434[6] = 0.0;
   out_3710500625877642434[7] = 0.0;
   out_3710500625877642434[8] = 0.0;
   out_3710500625877642434[9] = 0.0;
   out_3710500625877642434[10] = 0.0;
   out_3710500625877642434[11] = 0.0;
   out_3710500625877642434[12] = 0.0;
   out_3710500625877642434[13] = 0.0;
   out_3710500625877642434[14] = 0.0;
   out_3710500625877642434[15] = 0.0;
   out_3710500625877642434[16] = 0.0;
   out_3710500625877642434[17] = 0.0;
   out_3710500625877642434[18] = 0.0;
   out_3710500625877642434[19] = 1.0;
   out_3710500625877642434[20] = 0.0;
   out_3710500625877642434[21] = 0.0;
   out_3710500625877642434[22] = 0.0;
   out_3710500625877642434[23] = 0.0;
   out_3710500625877642434[24] = 0.0;
   out_3710500625877642434[25] = 0.0;
   out_3710500625877642434[26] = 0.0;
   out_3710500625877642434[27] = 0.0;
   out_3710500625877642434[28] = 0.0;
   out_3710500625877642434[29] = 0.0;
   out_3710500625877642434[30] = 0.0;
   out_3710500625877642434[31] = 0.0;
   out_3710500625877642434[32] = 0.0;
   out_3710500625877642434[33] = 0.0;
   out_3710500625877642434[34] = 0.0;
   out_3710500625877642434[35] = 0.0;
   out_3710500625877642434[36] = 0.0;
   out_3710500625877642434[37] = 0.0;
   out_3710500625877642434[38] = 1.0;
   out_3710500625877642434[39] = 0.0;
   out_3710500625877642434[40] = 0.0;
   out_3710500625877642434[41] = 0.0;
   out_3710500625877642434[42] = 0.0;
   out_3710500625877642434[43] = 0.0;
   out_3710500625877642434[44] = 0.0;
   out_3710500625877642434[45] = 0.0;
   out_3710500625877642434[46] = 0.0;
   out_3710500625877642434[47] = 0.0;
   out_3710500625877642434[48] = 0.0;
   out_3710500625877642434[49] = 0.0;
   out_3710500625877642434[50] = 0.0;
   out_3710500625877642434[51] = 0.0;
   out_3710500625877642434[52] = 0.0;
   out_3710500625877642434[53] = 0.0;
   out_3710500625877642434[54] = 0.0;
   out_3710500625877642434[55] = 0.0;
   out_3710500625877642434[56] = 0.0;
   out_3710500625877642434[57] = 1.0;
   out_3710500625877642434[58] = 0.0;
   out_3710500625877642434[59] = 0.0;
   out_3710500625877642434[60] = 0.0;
   out_3710500625877642434[61] = 0.0;
   out_3710500625877642434[62] = 0.0;
   out_3710500625877642434[63] = 0.0;
   out_3710500625877642434[64] = 0.0;
   out_3710500625877642434[65] = 0.0;
   out_3710500625877642434[66] = 0.0;
   out_3710500625877642434[67] = 0.0;
   out_3710500625877642434[68] = 0.0;
   out_3710500625877642434[69] = 0.0;
   out_3710500625877642434[70] = 0.0;
   out_3710500625877642434[71] = 0.0;
   out_3710500625877642434[72] = 0.0;
   out_3710500625877642434[73] = 0.0;
   out_3710500625877642434[74] = 0.0;
   out_3710500625877642434[75] = 0.0;
   out_3710500625877642434[76] = 1.0;
   out_3710500625877642434[77] = 0.0;
   out_3710500625877642434[78] = 0.0;
   out_3710500625877642434[79] = 0.0;
   out_3710500625877642434[80] = 0.0;
   out_3710500625877642434[81] = 0.0;
   out_3710500625877642434[82] = 0.0;
   out_3710500625877642434[83] = 0.0;
   out_3710500625877642434[84] = 0.0;
   out_3710500625877642434[85] = 0.0;
   out_3710500625877642434[86] = 0.0;
   out_3710500625877642434[87] = 0.0;
   out_3710500625877642434[88] = 0.0;
   out_3710500625877642434[89] = 0.0;
   out_3710500625877642434[90] = 0.0;
   out_3710500625877642434[91] = 0.0;
   out_3710500625877642434[92] = 0.0;
   out_3710500625877642434[93] = 0.0;
   out_3710500625877642434[94] = 0.0;
   out_3710500625877642434[95] = 1.0;
   out_3710500625877642434[96] = 0.0;
   out_3710500625877642434[97] = 0.0;
   out_3710500625877642434[98] = 0.0;
   out_3710500625877642434[99] = 0.0;
   out_3710500625877642434[100] = 0.0;
   out_3710500625877642434[101] = 0.0;
   out_3710500625877642434[102] = 0.0;
   out_3710500625877642434[103] = 0.0;
   out_3710500625877642434[104] = 0.0;
   out_3710500625877642434[105] = 0.0;
   out_3710500625877642434[106] = 0.0;
   out_3710500625877642434[107] = 0.0;
   out_3710500625877642434[108] = 0.0;
   out_3710500625877642434[109] = 0.0;
   out_3710500625877642434[110] = 0.0;
   out_3710500625877642434[111] = 0.0;
   out_3710500625877642434[112] = 0.0;
   out_3710500625877642434[113] = 0.0;
   out_3710500625877642434[114] = 1.0;
   out_3710500625877642434[115] = 0.0;
   out_3710500625877642434[116] = 0.0;
   out_3710500625877642434[117] = 0.0;
   out_3710500625877642434[118] = 0.0;
   out_3710500625877642434[119] = 0.0;
   out_3710500625877642434[120] = 0.0;
   out_3710500625877642434[121] = 0.0;
   out_3710500625877642434[122] = 0.0;
   out_3710500625877642434[123] = 0.0;
   out_3710500625877642434[124] = 0.0;
   out_3710500625877642434[125] = 0.0;
   out_3710500625877642434[126] = 0.0;
   out_3710500625877642434[127] = 0.0;
   out_3710500625877642434[128] = 0.0;
   out_3710500625877642434[129] = 0.0;
   out_3710500625877642434[130] = 0.0;
   out_3710500625877642434[131] = 0.0;
   out_3710500625877642434[132] = 0.0;
   out_3710500625877642434[133] = 1.0;
   out_3710500625877642434[134] = 0.0;
   out_3710500625877642434[135] = 0.0;
   out_3710500625877642434[136] = 0.0;
   out_3710500625877642434[137] = 0.0;
   out_3710500625877642434[138] = 0.0;
   out_3710500625877642434[139] = 0.0;
   out_3710500625877642434[140] = 0.0;
   out_3710500625877642434[141] = 0.0;
   out_3710500625877642434[142] = 0.0;
   out_3710500625877642434[143] = 0.0;
   out_3710500625877642434[144] = 0.0;
   out_3710500625877642434[145] = 0.0;
   out_3710500625877642434[146] = 0.0;
   out_3710500625877642434[147] = 0.0;
   out_3710500625877642434[148] = 0.0;
   out_3710500625877642434[149] = 0.0;
   out_3710500625877642434[150] = 0.0;
   out_3710500625877642434[151] = 0.0;
   out_3710500625877642434[152] = 1.0;
   out_3710500625877642434[153] = 0.0;
   out_3710500625877642434[154] = 0.0;
   out_3710500625877642434[155] = 0.0;
   out_3710500625877642434[156] = 0.0;
   out_3710500625877642434[157] = 0.0;
   out_3710500625877642434[158] = 0.0;
   out_3710500625877642434[159] = 0.0;
   out_3710500625877642434[160] = 0.0;
   out_3710500625877642434[161] = 0.0;
   out_3710500625877642434[162] = 0.0;
   out_3710500625877642434[163] = 0.0;
   out_3710500625877642434[164] = 0.0;
   out_3710500625877642434[165] = 0.0;
   out_3710500625877642434[166] = 0.0;
   out_3710500625877642434[167] = 0.0;
   out_3710500625877642434[168] = 0.0;
   out_3710500625877642434[169] = 0.0;
   out_3710500625877642434[170] = 0.0;
   out_3710500625877642434[171] = 1.0;
   out_3710500625877642434[172] = 0.0;
   out_3710500625877642434[173] = 0.0;
   out_3710500625877642434[174] = 0.0;
   out_3710500625877642434[175] = 0.0;
   out_3710500625877642434[176] = 0.0;
   out_3710500625877642434[177] = 0.0;
   out_3710500625877642434[178] = 0.0;
   out_3710500625877642434[179] = 0.0;
   out_3710500625877642434[180] = 0.0;
   out_3710500625877642434[181] = 0.0;
   out_3710500625877642434[182] = 0.0;
   out_3710500625877642434[183] = 0.0;
   out_3710500625877642434[184] = 0.0;
   out_3710500625877642434[185] = 0.0;
   out_3710500625877642434[186] = 0.0;
   out_3710500625877642434[187] = 0.0;
   out_3710500625877642434[188] = 0.0;
   out_3710500625877642434[189] = 0.0;
   out_3710500625877642434[190] = 1.0;
   out_3710500625877642434[191] = 0.0;
   out_3710500625877642434[192] = 0.0;
   out_3710500625877642434[193] = 0.0;
   out_3710500625877642434[194] = 0.0;
   out_3710500625877642434[195] = 0.0;
   out_3710500625877642434[196] = 0.0;
   out_3710500625877642434[197] = 0.0;
   out_3710500625877642434[198] = 0.0;
   out_3710500625877642434[199] = 0.0;
   out_3710500625877642434[200] = 0.0;
   out_3710500625877642434[201] = 0.0;
   out_3710500625877642434[202] = 0.0;
   out_3710500625877642434[203] = 0.0;
   out_3710500625877642434[204] = 0.0;
   out_3710500625877642434[205] = 0.0;
   out_3710500625877642434[206] = 0.0;
   out_3710500625877642434[207] = 0.0;
   out_3710500625877642434[208] = 0.0;
   out_3710500625877642434[209] = 1.0;
   out_3710500625877642434[210] = 0.0;
   out_3710500625877642434[211] = 0.0;
   out_3710500625877642434[212] = 0.0;
   out_3710500625877642434[213] = 0.0;
   out_3710500625877642434[214] = 0.0;
   out_3710500625877642434[215] = 0.0;
   out_3710500625877642434[216] = 0.0;
   out_3710500625877642434[217] = 0.0;
   out_3710500625877642434[218] = 0.0;
   out_3710500625877642434[219] = 0.0;
   out_3710500625877642434[220] = 0.0;
   out_3710500625877642434[221] = 0.0;
   out_3710500625877642434[222] = 0.0;
   out_3710500625877642434[223] = 0.0;
   out_3710500625877642434[224] = 0.0;
   out_3710500625877642434[225] = 0.0;
   out_3710500625877642434[226] = 0.0;
   out_3710500625877642434[227] = 0.0;
   out_3710500625877642434[228] = 1.0;
   out_3710500625877642434[229] = 0.0;
   out_3710500625877642434[230] = 0.0;
   out_3710500625877642434[231] = 0.0;
   out_3710500625877642434[232] = 0.0;
   out_3710500625877642434[233] = 0.0;
   out_3710500625877642434[234] = 0.0;
   out_3710500625877642434[235] = 0.0;
   out_3710500625877642434[236] = 0.0;
   out_3710500625877642434[237] = 0.0;
   out_3710500625877642434[238] = 0.0;
   out_3710500625877642434[239] = 0.0;
   out_3710500625877642434[240] = 0.0;
   out_3710500625877642434[241] = 0.0;
   out_3710500625877642434[242] = 0.0;
   out_3710500625877642434[243] = 0.0;
   out_3710500625877642434[244] = 0.0;
   out_3710500625877642434[245] = 0.0;
   out_3710500625877642434[246] = 0.0;
   out_3710500625877642434[247] = 1.0;
   out_3710500625877642434[248] = 0.0;
   out_3710500625877642434[249] = 0.0;
   out_3710500625877642434[250] = 0.0;
   out_3710500625877642434[251] = 0.0;
   out_3710500625877642434[252] = 0.0;
   out_3710500625877642434[253] = 0.0;
   out_3710500625877642434[254] = 0.0;
   out_3710500625877642434[255] = 0.0;
   out_3710500625877642434[256] = 0.0;
   out_3710500625877642434[257] = 0.0;
   out_3710500625877642434[258] = 0.0;
   out_3710500625877642434[259] = 0.0;
   out_3710500625877642434[260] = 0.0;
   out_3710500625877642434[261] = 0.0;
   out_3710500625877642434[262] = 0.0;
   out_3710500625877642434[263] = 0.0;
   out_3710500625877642434[264] = 0.0;
   out_3710500625877642434[265] = 0.0;
   out_3710500625877642434[266] = 1.0;
   out_3710500625877642434[267] = 0.0;
   out_3710500625877642434[268] = 0.0;
   out_3710500625877642434[269] = 0.0;
   out_3710500625877642434[270] = 0.0;
   out_3710500625877642434[271] = 0.0;
   out_3710500625877642434[272] = 0.0;
   out_3710500625877642434[273] = 0.0;
   out_3710500625877642434[274] = 0.0;
   out_3710500625877642434[275] = 0.0;
   out_3710500625877642434[276] = 0.0;
   out_3710500625877642434[277] = 0.0;
   out_3710500625877642434[278] = 0.0;
   out_3710500625877642434[279] = 0.0;
   out_3710500625877642434[280] = 0.0;
   out_3710500625877642434[281] = 0.0;
   out_3710500625877642434[282] = 0.0;
   out_3710500625877642434[283] = 0.0;
   out_3710500625877642434[284] = 0.0;
   out_3710500625877642434[285] = 1.0;
   out_3710500625877642434[286] = 0.0;
   out_3710500625877642434[287] = 0.0;
   out_3710500625877642434[288] = 0.0;
   out_3710500625877642434[289] = 0.0;
   out_3710500625877642434[290] = 0.0;
   out_3710500625877642434[291] = 0.0;
   out_3710500625877642434[292] = 0.0;
   out_3710500625877642434[293] = 0.0;
   out_3710500625877642434[294] = 0.0;
   out_3710500625877642434[295] = 0.0;
   out_3710500625877642434[296] = 0.0;
   out_3710500625877642434[297] = 0.0;
   out_3710500625877642434[298] = 0.0;
   out_3710500625877642434[299] = 0.0;
   out_3710500625877642434[300] = 0.0;
   out_3710500625877642434[301] = 0.0;
   out_3710500625877642434[302] = 0.0;
   out_3710500625877642434[303] = 0.0;
   out_3710500625877642434[304] = 1.0;
   out_3710500625877642434[305] = 0.0;
   out_3710500625877642434[306] = 0.0;
   out_3710500625877642434[307] = 0.0;
   out_3710500625877642434[308] = 0.0;
   out_3710500625877642434[309] = 0.0;
   out_3710500625877642434[310] = 0.0;
   out_3710500625877642434[311] = 0.0;
   out_3710500625877642434[312] = 0.0;
   out_3710500625877642434[313] = 0.0;
   out_3710500625877642434[314] = 0.0;
   out_3710500625877642434[315] = 0.0;
   out_3710500625877642434[316] = 0.0;
   out_3710500625877642434[317] = 0.0;
   out_3710500625877642434[318] = 0.0;
   out_3710500625877642434[319] = 0.0;
   out_3710500625877642434[320] = 0.0;
   out_3710500625877642434[321] = 0.0;
   out_3710500625877642434[322] = 0.0;
   out_3710500625877642434[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5725984385602899057) {
   out_5725984385602899057[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5725984385602899057[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5725984385602899057[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5725984385602899057[3] = dt*state[12] + state[3];
   out_5725984385602899057[4] = dt*state[13] + state[4];
   out_5725984385602899057[5] = dt*state[14] + state[5];
   out_5725984385602899057[6] = state[6];
   out_5725984385602899057[7] = state[7];
   out_5725984385602899057[8] = state[8];
   out_5725984385602899057[9] = state[9];
   out_5725984385602899057[10] = state[10];
   out_5725984385602899057[11] = state[11];
   out_5725984385602899057[12] = state[12];
   out_5725984385602899057[13] = state[13];
   out_5725984385602899057[14] = state[14];
   out_5725984385602899057[15] = state[15];
   out_5725984385602899057[16] = state[16];
   out_5725984385602899057[17] = state[17];
}
void F_fun(double *state, double dt, double *out_3503616768446574438) {
   out_3503616768446574438[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3503616768446574438[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3503616768446574438[2] = 0;
   out_3503616768446574438[3] = 0;
   out_3503616768446574438[4] = 0;
   out_3503616768446574438[5] = 0;
   out_3503616768446574438[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3503616768446574438[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3503616768446574438[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3503616768446574438[9] = 0;
   out_3503616768446574438[10] = 0;
   out_3503616768446574438[11] = 0;
   out_3503616768446574438[12] = 0;
   out_3503616768446574438[13] = 0;
   out_3503616768446574438[14] = 0;
   out_3503616768446574438[15] = 0;
   out_3503616768446574438[16] = 0;
   out_3503616768446574438[17] = 0;
   out_3503616768446574438[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3503616768446574438[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3503616768446574438[20] = 0;
   out_3503616768446574438[21] = 0;
   out_3503616768446574438[22] = 0;
   out_3503616768446574438[23] = 0;
   out_3503616768446574438[24] = 0;
   out_3503616768446574438[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3503616768446574438[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3503616768446574438[27] = 0;
   out_3503616768446574438[28] = 0;
   out_3503616768446574438[29] = 0;
   out_3503616768446574438[30] = 0;
   out_3503616768446574438[31] = 0;
   out_3503616768446574438[32] = 0;
   out_3503616768446574438[33] = 0;
   out_3503616768446574438[34] = 0;
   out_3503616768446574438[35] = 0;
   out_3503616768446574438[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3503616768446574438[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3503616768446574438[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3503616768446574438[39] = 0;
   out_3503616768446574438[40] = 0;
   out_3503616768446574438[41] = 0;
   out_3503616768446574438[42] = 0;
   out_3503616768446574438[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3503616768446574438[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3503616768446574438[45] = 0;
   out_3503616768446574438[46] = 0;
   out_3503616768446574438[47] = 0;
   out_3503616768446574438[48] = 0;
   out_3503616768446574438[49] = 0;
   out_3503616768446574438[50] = 0;
   out_3503616768446574438[51] = 0;
   out_3503616768446574438[52] = 0;
   out_3503616768446574438[53] = 0;
   out_3503616768446574438[54] = 0;
   out_3503616768446574438[55] = 0;
   out_3503616768446574438[56] = 0;
   out_3503616768446574438[57] = 1;
   out_3503616768446574438[58] = 0;
   out_3503616768446574438[59] = 0;
   out_3503616768446574438[60] = 0;
   out_3503616768446574438[61] = 0;
   out_3503616768446574438[62] = 0;
   out_3503616768446574438[63] = 0;
   out_3503616768446574438[64] = 0;
   out_3503616768446574438[65] = 0;
   out_3503616768446574438[66] = dt;
   out_3503616768446574438[67] = 0;
   out_3503616768446574438[68] = 0;
   out_3503616768446574438[69] = 0;
   out_3503616768446574438[70] = 0;
   out_3503616768446574438[71] = 0;
   out_3503616768446574438[72] = 0;
   out_3503616768446574438[73] = 0;
   out_3503616768446574438[74] = 0;
   out_3503616768446574438[75] = 0;
   out_3503616768446574438[76] = 1;
   out_3503616768446574438[77] = 0;
   out_3503616768446574438[78] = 0;
   out_3503616768446574438[79] = 0;
   out_3503616768446574438[80] = 0;
   out_3503616768446574438[81] = 0;
   out_3503616768446574438[82] = 0;
   out_3503616768446574438[83] = 0;
   out_3503616768446574438[84] = 0;
   out_3503616768446574438[85] = dt;
   out_3503616768446574438[86] = 0;
   out_3503616768446574438[87] = 0;
   out_3503616768446574438[88] = 0;
   out_3503616768446574438[89] = 0;
   out_3503616768446574438[90] = 0;
   out_3503616768446574438[91] = 0;
   out_3503616768446574438[92] = 0;
   out_3503616768446574438[93] = 0;
   out_3503616768446574438[94] = 0;
   out_3503616768446574438[95] = 1;
   out_3503616768446574438[96] = 0;
   out_3503616768446574438[97] = 0;
   out_3503616768446574438[98] = 0;
   out_3503616768446574438[99] = 0;
   out_3503616768446574438[100] = 0;
   out_3503616768446574438[101] = 0;
   out_3503616768446574438[102] = 0;
   out_3503616768446574438[103] = 0;
   out_3503616768446574438[104] = dt;
   out_3503616768446574438[105] = 0;
   out_3503616768446574438[106] = 0;
   out_3503616768446574438[107] = 0;
   out_3503616768446574438[108] = 0;
   out_3503616768446574438[109] = 0;
   out_3503616768446574438[110] = 0;
   out_3503616768446574438[111] = 0;
   out_3503616768446574438[112] = 0;
   out_3503616768446574438[113] = 0;
   out_3503616768446574438[114] = 1;
   out_3503616768446574438[115] = 0;
   out_3503616768446574438[116] = 0;
   out_3503616768446574438[117] = 0;
   out_3503616768446574438[118] = 0;
   out_3503616768446574438[119] = 0;
   out_3503616768446574438[120] = 0;
   out_3503616768446574438[121] = 0;
   out_3503616768446574438[122] = 0;
   out_3503616768446574438[123] = 0;
   out_3503616768446574438[124] = 0;
   out_3503616768446574438[125] = 0;
   out_3503616768446574438[126] = 0;
   out_3503616768446574438[127] = 0;
   out_3503616768446574438[128] = 0;
   out_3503616768446574438[129] = 0;
   out_3503616768446574438[130] = 0;
   out_3503616768446574438[131] = 0;
   out_3503616768446574438[132] = 0;
   out_3503616768446574438[133] = 1;
   out_3503616768446574438[134] = 0;
   out_3503616768446574438[135] = 0;
   out_3503616768446574438[136] = 0;
   out_3503616768446574438[137] = 0;
   out_3503616768446574438[138] = 0;
   out_3503616768446574438[139] = 0;
   out_3503616768446574438[140] = 0;
   out_3503616768446574438[141] = 0;
   out_3503616768446574438[142] = 0;
   out_3503616768446574438[143] = 0;
   out_3503616768446574438[144] = 0;
   out_3503616768446574438[145] = 0;
   out_3503616768446574438[146] = 0;
   out_3503616768446574438[147] = 0;
   out_3503616768446574438[148] = 0;
   out_3503616768446574438[149] = 0;
   out_3503616768446574438[150] = 0;
   out_3503616768446574438[151] = 0;
   out_3503616768446574438[152] = 1;
   out_3503616768446574438[153] = 0;
   out_3503616768446574438[154] = 0;
   out_3503616768446574438[155] = 0;
   out_3503616768446574438[156] = 0;
   out_3503616768446574438[157] = 0;
   out_3503616768446574438[158] = 0;
   out_3503616768446574438[159] = 0;
   out_3503616768446574438[160] = 0;
   out_3503616768446574438[161] = 0;
   out_3503616768446574438[162] = 0;
   out_3503616768446574438[163] = 0;
   out_3503616768446574438[164] = 0;
   out_3503616768446574438[165] = 0;
   out_3503616768446574438[166] = 0;
   out_3503616768446574438[167] = 0;
   out_3503616768446574438[168] = 0;
   out_3503616768446574438[169] = 0;
   out_3503616768446574438[170] = 0;
   out_3503616768446574438[171] = 1;
   out_3503616768446574438[172] = 0;
   out_3503616768446574438[173] = 0;
   out_3503616768446574438[174] = 0;
   out_3503616768446574438[175] = 0;
   out_3503616768446574438[176] = 0;
   out_3503616768446574438[177] = 0;
   out_3503616768446574438[178] = 0;
   out_3503616768446574438[179] = 0;
   out_3503616768446574438[180] = 0;
   out_3503616768446574438[181] = 0;
   out_3503616768446574438[182] = 0;
   out_3503616768446574438[183] = 0;
   out_3503616768446574438[184] = 0;
   out_3503616768446574438[185] = 0;
   out_3503616768446574438[186] = 0;
   out_3503616768446574438[187] = 0;
   out_3503616768446574438[188] = 0;
   out_3503616768446574438[189] = 0;
   out_3503616768446574438[190] = 1;
   out_3503616768446574438[191] = 0;
   out_3503616768446574438[192] = 0;
   out_3503616768446574438[193] = 0;
   out_3503616768446574438[194] = 0;
   out_3503616768446574438[195] = 0;
   out_3503616768446574438[196] = 0;
   out_3503616768446574438[197] = 0;
   out_3503616768446574438[198] = 0;
   out_3503616768446574438[199] = 0;
   out_3503616768446574438[200] = 0;
   out_3503616768446574438[201] = 0;
   out_3503616768446574438[202] = 0;
   out_3503616768446574438[203] = 0;
   out_3503616768446574438[204] = 0;
   out_3503616768446574438[205] = 0;
   out_3503616768446574438[206] = 0;
   out_3503616768446574438[207] = 0;
   out_3503616768446574438[208] = 0;
   out_3503616768446574438[209] = 1;
   out_3503616768446574438[210] = 0;
   out_3503616768446574438[211] = 0;
   out_3503616768446574438[212] = 0;
   out_3503616768446574438[213] = 0;
   out_3503616768446574438[214] = 0;
   out_3503616768446574438[215] = 0;
   out_3503616768446574438[216] = 0;
   out_3503616768446574438[217] = 0;
   out_3503616768446574438[218] = 0;
   out_3503616768446574438[219] = 0;
   out_3503616768446574438[220] = 0;
   out_3503616768446574438[221] = 0;
   out_3503616768446574438[222] = 0;
   out_3503616768446574438[223] = 0;
   out_3503616768446574438[224] = 0;
   out_3503616768446574438[225] = 0;
   out_3503616768446574438[226] = 0;
   out_3503616768446574438[227] = 0;
   out_3503616768446574438[228] = 1;
   out_3503616768446574438[229] = 0;
   out_3503616768446574438[230] = 0;
   out_3503616768446574438[231] = 0;
   out_3503616768446574438[232] = 0;
   out_3503616768446574438[233] = 0;
   out_3503616768446574438[234] = 0;
   out_3503616768446574438[235] = 0;
   out_3503616768446574438[236] = 0;
   out_3503616768446574438[237] = 0;
   out_3503616768446574438[238] = 0;
   out_3503616768446574438[239] = 0;
   out_3503616768446574438[240] = 0;
   out_3503616768446574438[241] = 0;
   out_3503616768446574438[242] = 0;
   out_3503616768446574438[243] = 0;
   out_3503616768446574438[244] = 0;
   out_3503616768446574438[245] = 0;
   out_3503616768446574438[246] = 0;
   out_3503616768446574438[247] = 1;
   out_3503616768446574438[248] = 0;
   out_3503616768446574438[249] = 0;
   out_3503616768446574438[250] = 0;
   out_3503616768446574438[251] = 0;
   out_3503616768446574438[252] = 0;
   out_3503616768446574438[253] = 0;
   out_3503616768446574438[254] = 0;
   out_3503616768446574438[255] = 0;
   out_3503616768446574438[256] = 0;
   out_3503616768446574438[257] = 0;
   out_3503616768446574438[258] = 0;
   out_3503616768446574438[259] = 0;
   out_3503616768446574438[260] = 0;
   out_3503616768446574438[261] = 0;
   out_3503616768446574438[262] = 0;
   out_3503616768446574438[263] = 0;
   out_3503616768446574438[264] = 0;
   out_3503616768446574438[265] = 0;
   out_3503616768446574438[266] = 1;
   out_3503616768446574438[267] = 0;
   out_3503616768446574438[268] = 0;
   out_3503616768446574438[269] = 0;
   out_3503616768446574438[270] = 0;
   out_3503616768446574438[271] = 0;
   out_3503616768446574438[272] = 0;
   out_3503616768446574438[273] = 0;
   out_3503616768446574438[274] = 0;
   out_3503616768446574438[275] = 0;
   out_3503616768446574438[276] = 0;
   out_3503616768446574438[277] = 0;
   out_3503616768446574438[278] = 0;
   out_3503616768446574438[279] = 0;
   out_3503616768446574438[280] = 0;
   out_3503616768446574438[281] = 0;
   out_3503616768446574438[282] = 0;
   out_3503616768446574438[283] = 0;
   out_3503616768446574438[284] = 0;
   out_3503616768446574438[285] = 1;
   out_3503616768446574438[286] = 0;
   out_3503616768446574438[287] = 0;
   out_3503616768446574438[288] = 0;
   out_3503616768446574438[289] = 0;
   out_3503616768446574438[290] = 0;
   out_3503616768446574438[291] = 0;
   out_3503616768446574438[292] = 0;
   out_3503616768446574438[293] = 0;
   out_3503616768446574438[294] = 0;
   out_3503616768446574438[295] = 0;
   out_3503616768446574438[296] = 0;
   out_3503616768446574438[297] = 0;
   out_3503616768446574438[298] = 0;
   out_3503616768446574438[299] = 0;
   out_3503616768446574438[300] = 0;
   out_3503616768446574438[301] = 0;
   out_3503616768446574438[302] = 0;
   out_3503616768446574438[303] = 0;
   out_3503616768446574438[304] = 1;
   out_3503616768446574438[305] = 0;
   out_3503616768446574438[306] = 0;
   out_3503616768446574438[307] = 0;
   out_3503616768446574438[308] = 0;
   out_3503616768446574438[309] = 0;
   out_3503616768446574438[310] = 0;
   out_3503616768446574438[311] = 0;
   out_3503616768446574438[312] = 0;
   out_3503616768446574438[313] = 0;
   out_3503616768446574438[314] = 0;
   out_3503616768446574438[315] = 0;
   out_3503616768446574438[316] = 0;
   out_3503616768446574438[317] = 0;
   out_3503616768446574438[318] = 0;
   out_3503616768446574438[319] = 0;
   out_3503616768446574438[320] = 0;
   out_3503616768446574438[321] = 0;
   out_3503616768446574438[322] = 0;
   out_3503616768446574438[323] = 1;
}
void h_4(double *state, double *unused, double *out_3803432647309987328) {
   out_3803432647309987328[0] = state[6] + state[9];
   out_3803432647309987328[1] = state[7] + state[10];
   out_3803432647309987328[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7950155699686530755) {
   out_7950155699686530755[0] = 0;
   out_7950155699686530755[1] = 0;
   out_7950155699686530755[2] = 0;
   out_7950155699686530755[3] = 0;
   out_7950155699686530755[4] = 0;
   out_7950155699686530755[5] = 0;
   out_7950155699686530755[6] = 1;
   out_7950155699686530755[7] = 0;
   out_7950155699686530755[8] = 0;
   out_7950155699686530755[9] = 1;
   out_7950155699686530755[10] = 0;
   out_7950155699686530755[11] = 0;
   out_7950155699686530755[12] = 0;
   out_7950155699686530755[13] = 0;
   out_7950155699686530755[14] = 0;
   out_7950155699686530755[15] = 0;
   out_7950155699686530755[16] = 0;
   out_7950155699686530755[17] = 0;
   out_7950155699686530755[18] = 0;
   out_7950155699686530755[19] = 0;
   out_7950155699686530755[20] = 0;
   out_7950155699686530755[21] = 0;
   out_7950155699686530755[22] = 0;
   out_7950155699686530755[23] = 0;
   out_7950155699686530755[24] = 0;
   out_7950155699686530755[25] = 1;
   out_7950155699686530755[26] = 0;
   out_7950155699686530755[27] = 0;
   out_7950155699686530755[28] = 1;
   out_7950155699686530755[29] = 0;
   out_7950155699686530755[30] = 0;
   out_7950155699686530755[31] = 0;
   out_7950155699686530755[32] = 0;
   out_7950155699686530755[33] = 0;
   out_7950155699686530755[34] = 0;
   out_7950155699686530755[35] = 0;
   out_7950155699686530755[36] = 0;
   out_7950155699686530755[37] = 0;
   out_7950155699686530755[38] = 0;
   out_7950155699686530755[39] = 0;
   out_7950155699686530755[40] = 0;
   out_7950155699686530755[41] = 0;
   out_7950155699686530755[42] = 0;
   out_7950155699686530755[43] = 0;
   out_7950155699686530755[44] = 1;
   out_7950155699686530755[45] = 0;
   out_7950155699686530755[46] = 0;
   out_7950155699686530755[47] = 1;
   out_7950155699686530755[48] = 0;
   out_7950155699686530755[49] = 0;
   out_7950155699686530755[50] = 0;
   out_7950155699686530755[51] = 0;
   out_7950155699686530755[52] = 0;
   out_7950155699686530755[53] = 0;
}
void h_10(double *state, double *unused, double *out_477421004614984104) {
   out_477421004614984104[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_477421004614984104[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_477421004614984104[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8536057142137197060) {
   out_8536057142137197060[0] = 0;
   out_8536057142137197060[1] = 9.8100000000000005*cos(state[1]);
   out_8536057142137197060[2] = 0;
   out_8536057142137197060[3] = 0;
   out_8536057142137197060[4] = -state[8];
   out_8536057142137197060[5] = state[7];
   out_8536057142137197060[6] = 0;
   out_8536057142137197060[7] = state[5];
   out_8536057142137197060[8] = -state[4];
   out_8536057142137197060[9] = 0;
   out_8536057142137197060[10] = 0;
   out_8536057142137197060[11] = 0;
   out_8536057142137197060[12] = 1;
   out_8536057142137197060[13] = 0;
   out_8536057142137197060[14] = 0;
   out_8536057142137197060[15] = 1;
   out_8536057142137197060[16] = 0;
   out_8536057142137197060[17] = 0;
   out_8536057142137197060[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8536057142137197060[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8536057142137197060[20] = 0;
   out_8536057142137197060[21] = state[8];
   out_8536057142137197060[22] = 0;
   out_8536057142137197060[23] = -state[6];
   out_8536057142137197060[24] = -state[5];
   out_8536057142137197060[25] = 0;
   out_8536057142137197060[26] = state[3];
   out_8536057142137197060[27] = 0;
   out_8536057142137197060[28] = 0;
   out_8536057142137197060[29] = 0;
   out_8536057142137197060[30] = 0;
   out_8536057142137197060[31] = 1;
   out_8536057142137197060[32] = 0;
   out_8536057142137197060[33] = 0;
   out_8536057142137197060[34] = 1;
   out_8536057142137197060[35] = 0;
   out_8536057142137197060[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8536057142137197060[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8536057142137197060[38] = 0;
   out_8536057142137197060[39] = -state[7];
   out_8536057142137197060[40] = state[6];
   out_8536057142137197060[41] = 0;
   out_8536057142137197060[42] = state[4];
   out_8536057142137197060[43] = -state[3];
   out_8536057142137197060[44] = 0;
   out_8536057142137197060[45] = 0;
   out_8536057142137197060[46] = 0;
   out_8536057142137197060[47] = 0;
   out_8536057142137197060[48] = 0;
   out_8536057142137197060[49] = 0;
   out_8536057142137197060[50] = 1;
   out_8536057142137197060[51] = 0;
   out_8536057142137197060[52] = 0;
   out_8536057142137197060[53] = 1;
}
void h_13(double *state, double *unused, double *out_1243321013145270066) {
   out_1243321013145270066[0] = state[3];
   out_1243321013145270066[1] = state[4];
   out_1243321013145270066[2] = state[5];
}
void H_13(double *state, double *unused, double *out_8514757619368374859) {
   out_8514757619368374859[0] = 0;
   out_8514757619368374859[1] = 0;
   out_8514757619368374859[2] = 0;
   out_8514757619368374859[3] = 1;
   out_8514757619368374859[4] = 0;
   out_8514757619368374859[5] = 0;
   out_8514757619368374859[6] = 0;
   out_8514757619368374859[7] = 0;
   out_8514757619368374859[8] = 0;
   out_8514757619368374859[9] = 0;
   out_8514757619368374859[10] = 0;
   out_8514757619368374859[11] = 0;
   out_8514757619368374859[12] = 0;
   out_8514757619368374859[13] = 0;
   out_8514757619368374859[14] = 0;
   out_8514757619368374859[15] = 0;
   out_8514757619368374859[16] = 0;
   out_8514757619368374859[17] = 0;
   out_8514757619368374859[18] = 0;
   out_8514757619368374859[19] = 0;
   out_8514757619368374859[20] = 0;
   out_8514757619368374859[21] = 0;
   out_8514757619368374859[22] = 1;
   out_8514757619368374859[23] = 0;
   out_8514757619368374859[24] = 0;
   out_8514757619368374859[25] = 0;
   out_8514757619368374859[26] = 0;
   out_8514757619368374859[27] = 0;
   out_8514757619368374859[28] = 0;
   out_8514757619368374859[29] = 0;
   out_8514757619368374859[30] = 0;
   out_8514757619368374859[31] = 0;
   out_8514757619368374859[32] = 0;
   out_8514757619368374859[33] = 0;
   out_8514757619368374859[34] = 0;
   out_8514757619368374859[35] = 0;
   out_8514757619368374859[36] = 0;
   out_8514757619368374859[37] = 0;
   out_8514757619368374859[38] = 0;
   out_8514757619368374859[39] = 0;
   out_8514757619368374859[40] = 0;
   out_8514757619368374859[41] = 1;
   out_8514757619368374859[42] = 0;
   out_8514757619368374859[43] = 0;
   out_8514757619368374859[44] = 0;
   out_8514757619368374859[45] = 0;
   out_8514757619368374859[46] = 0;
   out_8514757619368374859[47] = 0;
   out_8514757619368374859[48] = 0;
   out_8514757619368374859[49] = 0;
   out_8514757619368374859[50] = 0;
   out_8514757619368374859[51] = 0;
   out_8514757619368374859[52] = 0;
   out_8514757619368374859[53] = 0;
}
void h_14(double *state, double *unused, double *out_7694485530011040401) {
   out_7694485530011040401[0] = state[6];
   out_7694485530011040401[1] = state[7];
   out_7694485530011040401[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4867367267391158459) {
   out_4867367267391158459[0] = 0;
   out_4867367267391158459[1] = 0;
   out_4867367267391158459[2] = 0;
   out_4867367267391158459[3] = 0;
   out_4867367267391158459[4] = 0;
   out_4867367267391158459[5] = 0;
   out_4867367267391158459[6] = 1;
   out_4867367267391158459[7] = 0;
   out_4867367267391158459[8] = 0;
   out_4867367267391158459[9] = 0;
   out_4867367267391158459[10] = 0;
   out_4867367267391158459[11] = 0;
   out_4867367267391158459[12] = 0;
   out_4867367267391158459[13] = 0;
   out_4867367267391158459[14] = 0;
   out_4867367267391158459[15] = 0;
   out_4867367267391158459[16] = 0;
   out_4867367267391158459[17] = 0;
   out_4867367267391158459[18] = 0;
   out_4867367267391158459[19] = 0;
   out_4867367267391158459[20] = 0;
   out_4867367267391158459[21] = 0;
   out_4867367267391158459[22] = 0;
   out_4867367267391158459[23] = 0;
   out_4867367267391158459[24] = 0;
   out_4867367267391158459[25] = 1;
   out_4867367267391158459[26] = 0;
   out_4867367267391158459[27] = 0;
   out_4867367267391158459[28] = 0;
   out_4867367267391158459[29] = 0;
   out_4867367267391158459[30] = 0;
   out_4867367267391158459[31] = 0;
   out_4867367267391158459[32] = 0;
   out_4867367267391158459[33] = 0;
   out_4867367267391158459[34] = 0;
   out_4867367267391158459[35] = 0;
   out_4867367267391158459[36] = 0;
   out_4867367267391158459[37] = 0;
   out_4867367267391158459[38] = 0;
   out_4867367267391158459[39] = 0;
   out_4867367267391158459[40] = 0;
   out_4867367267391158459[41] = 0;
   out_4867367267391158459[42] = 0;
   out_4867367267391158459[43] = 0;
   out_4867367267391158459[44] = 1;
   out_4867367267391158459[45] = 0;
   out_4867367267391158459[46] = 0;
   out_4867367267391158459[47] = 0;
   out_4867367267391158459[48] = 0;
   out_4867367267391158459[49] = 0;
   out_4867367267391158459[50] = 0;
   out_4867367267391158459[51] = 0;
   out_4867367267391158459[52] = 0;
   out_4867367267391158459[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_4711793940499862270) {
  err_fun(nom_x, delta_x, out_4711793940499862270);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8790106481935061031) {
  inv_err_fun(nom_x, true_x, out_8790106481935061031);
}
void pose_H_mod_fun(double *state, double *out_3710500625877642434) {
  H_mod_fun(state, out_3710500625877642434);
}
void pose_f_fun(double *state, double dt, double *out_5725984385602899057) {
  f_fun(state,  dt, out_5725984385602899057);
}
void pose_F_fun(double *state, double dt, double *out_3503616768446574438) {
  F_fun(state,  dt, out_3503616768446574438);
}
void pose_h_4(double *state, double *unused, double *out_3803432647309987328) {
  h_4(state, unused, out_3803432647309987328);
}
void pose_H_4(double *state, double *unused, double *out_7950155699686530755) {
  H_4(state, unused, out_7950155699686530755);
}
void pose_h_10(double *state, double *unused, double *out_477421004614984104) {
  h_10(state, unused, out_477421004614984104);
}
void pose_H_10(double *state, double *unused, double *out_8536057142137197060) {
  H_10(state, unused, out_8536057142137197060);
}
void pose_h_13(double *state, double *unused, double *out_1243321013145270066) {
  h_13(state, unused, out_1243321013145270066);
}
void pose_H_13(double *state, double *unused, double *out_8514757619368374859) {
  H_13(state, unused, out_8514757619368374859);
}
void pose_h_14(double *state, double *unused, double *out_7694485530011040401) {
  h_14(state, unused, out_7694485530011040401);
}
void pose_H_14(double *state, double *unused, double *out_4867367267391158459) {
  H_14(state, unused, out_4867367267391158459);
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
