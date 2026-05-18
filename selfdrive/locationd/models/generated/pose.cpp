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
void err_fun(double *nom_x, double *delta_x, double *out_6520327552806096841) {
   out_6520327552806096841[0] = delta_x[0] + nom_x[0];
   out_6520327552806096841[1] = delta_x[1] + nom_x[1];
   out_6520327552806096841[2] = delta_x[2] + nom_x[2];
   out_6520327552806096841[3] = delta_x[3] + nom_x[3];
   out_6520327552806096841[4] = delta_x[4] + nom_x[4];
   out_6520327552806096841[5] = delta_x[5] + nom_x[5];
   out_6520327552806096841[6] = delta_x[6] + nom_x[6];
   out_6520327552806096841[7] = delta_x[7] + nom_x[7];
   out_6520327552806096841[8] = delta_x[8] + nom_x[8];
   out_6520327552806096841[9] = delta_x[9] + nom_x[9];
   out_6520327552806096841[10] = delta_x[10] + nom_x[10];
   out_6520327552806096841[11] = delta_x[11] + nom_x[11];
   out_6520327552806096841[12] = delta_x[12] + nom_x[12];
   out_6520327552806096841[13] = delta_x[13] + nom_x[13];
   out_6520327552806096841[14] = delta_x[14] + nom_x[14];
   out_6520327552806096841[15] = delta_x[15] + nom_x[15];
   out_6520327552806096841[16] = delta_x[16] + nom_x[16];
   out_6520327552806096841[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3933583929675800728) {
   out_3933583929675800728[0] = -nom_x[0] + true_x[0];
   out_3933583929675800728[1] = -nom_x[1] + true_x[1];
   out_3933583929675800728[2] = -nom_x[2] + true_x[2];
   out_3933583929675800728[3] = -nom_x[3] + true_x[3];
   out_3933583929675800728[4] = -nom_x[4] + true_x[4];
   out_3933583929675800728[5] = -nom_x[5] + true_x[5];
   out_3933583929675800728[6] = -nom_x[6] + true_x[6];
   out_3933583929675800728[7] = -nom_x[7] + true_x[7];
   out_3933583929675800728[8] = -nom_x[8] + true_x[8];
   out_3933583929675800728[9] = -nom_x[9] + true_x[9];
   out_3933583929675800728[10] = -nom_x[10] + true_x[10];
   out_3933583929675800728[11] = -nom_x[11] + true_x[11];
   out_3933583929675800728[12] = -nom_x[12] + true_x[12];
   out_3933583929675800728[13] = -nom_x[13] + true_x[13];
   out_3933583929675800728[14] = -nom_x[14] + true_x[14];
   out_3933583929675800728[15] = -nom_x[15] + true_x[15];
   out_3933583929675800728[16] = -nom_x[16] + true_x[16];
   out_3933583929675800728[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6974741239016485936) {
   out_6974741239016485936[0] = 1.0;
   out_6974741239016485936[1] = 0.0;
   out_6974741239016485936[2] = 0.0;
   out_6974741239016485936[3] = 0.0;
   out_6974741239016485936[4] = 0.0;
   out_6974741239016485936[5] = 0.0;
   out_6974741239016485936[6] = 0.0;
   out_6974741239016485936[7] = 0.0;
   out_6974741239016485936[8] = 0.0;
   out_6974741239016485936[9] = 0.0;
   out_6974741239016485936[10] = 0.0;
   out_6974741239016485936[11] = 0.0;
   out_6974741239016485936[12] = 0.0;
   out_6974741239016485936[13] = 0.0;
   out_6974741239016485936[14] = 0.0;
   out_6974741239016485936[15] = 0.0;
   out_6974741239016485936[16] = 0.0;
   out_6974741239016485936[17] = 0.0;
   out_6974741239016485936[18] = 0.0;
   out_6974741239016485936[19] = 1.0;
   out_6974741239016485936[20] = 0.0;
   out_6974741239016485936[21] = 0.0;
   out_6974741239016485936[22] = 0.0;
   out_6974741239016485936[23] = 0.0;
   out_6974741239016485936[24] = 0.0;
   out_6974741239016485936[25] = 0.0;
   out_6974741239016485936[26] = 0.0;
   out_6974741239016485936[27] = 0.0;
   out_6974741239016485936[28] = 0.0;
   out_6974741239016485936[29] = 0.0;
   out_6974741239016485936[30] = 0.0;
   out_6974741239016485936[31] = 0.0;
   out_6974741239016485936[32] = 0.0;
   out_6974741239016485936[33] = 0.0;
   out_6974741239016485936[34] = 0.0;
   out_6974741239016485936[35] = 0.0;
   out_6974741239016485936[36] = 0.0;
   out_6974741239016485936[37] = 0.0;
   out_6974741239016485936[38] = 1.0;
   out_6974741239016485936[39] = 0.0;
   out_6974741239016485936[40] = 0.0;
   out_6974741239016485936[41] = 0.0;
   out_6974741239016485936[42] = 0.0;
   out_6974741239016485936[43] = 0.0;
   out_6974741239016485936[44] = 0.0;
   out_6974741239016485936[45] = 0.0;
   out_6974741239016485936[46] = 0.0;
   out_6974741239016485936[47] = 0.0;
   out_6974741239016485936[48] = 0.0;
   out_6974741239016485936[49] = 0.0;
   out_6974741239016485936[50] = 0.0;
   out_6974741239016485936[51] = 0.0;
   out_6974741239016485936[52] = 0.0;
   out_6974741239016485936[53] = 0.0;
   out_6974741239016485936[54] = 0.0;
   out_6974741239016485936[55] = 0.0;
   out_6974741239016485936[56] = 0.0;
   out_6974741239016485936[57] = 1.0;
   out_6974741239016485936[58] = 0.0;
   out_6974741239016485936[59] = 0.0;
   out_6974741239016485936[60] = 0.0;
   out_6974741239016485936[61] = 0.0;
   out_6974741239016485936[62] = 0.0;
   out_6974741239016485936[63] = 0.0;
   out_6974741239016485936[64] = 0.0;
   out_6974741239016485936[65] = 0.0;
   out_6974741239016485936[66] = 0.0;
   out_6974741239016485936[67] = 0.0;
   out_6974741239016485936[68] = 0.0;
   out_6974741239016485936[69] = 0.0;
   out_6974741239016485936[70] = 0.0;
   out_6974741239016485936[71] = 0.0;
   out_6974741239016485936[72] = 0.0;
   out_6974741239016485936[73] = 0.0;
   out_6974741239016485936[74] = 0.0;
   out_6974741239016485936[75] = 0.0;
   out_6974741239016485936[76] = 1.0;
   out_6974741239016485936[77] = 0.0;
   out_6974741239016485936[78] = 0.0;
   out_6974741239016485936[79] = 0.0;
   out_6974741239016485936[80] = 0.0;
   out_6974741239016485936[81] = 0.0;
   out_6974741239016485936[82] = 0.0;
   out_6974741239016485936[83] = 0.0;
   out_6974741239016485936[84] = 0.0;
   out_6974741239016485936[85] = 0.0;
   out_6974741239016485936[86] = 0.0;
   out_6974741239016485936[87] = 0.0;
   out_6974741239016485936[88] = 0.0;
   out_6974741239016485936[89] = 0.0;
   out_6974741239016485936[90] = 0.0;
   out_6974741239016485936[91] = 0.0;
   out_6974741239016485936[92] = 0.0;
   out_6974741239016485936[93] = 0.0;
   out_6974741239016485936[94] = 0.0;
   out_6974741239016485936[95] = 1.0;
   out_6974741239016485936[96] = 0.0;
   out_6974741239016485936[97] = 0.0;
   out_6974741239016485936[98] = 0.0;
   out_6974741239016485936[99] = 0.0;
   out_6974741239016485936[100] = 0.0;
   out_6974741239016485936[101] = 0.0;
   out_6974741239016485936[102] = 0.0;
   out_6974741239016485936[103] = 0.0;
   out_6974741239016485936[104] = 0.0;
   out_6974741239016485936[105] = 0.0;
   out_6974741239016485936[106] = 0.0;
   out_6974741239016485936[107] = 0.0;
   out_6974741239016485936[108] = 0.0;
   out_6974741239016485936[109] = 0.0;
   out_6974741239016485936[110] = 0.0;
   out_6974741239016485936[111] = 0.0;
   out_6974741239016485936[112] = 0.0;
   out_6974741239016485936[113] = 0.0;
   out_6974741239016485936[114] = 1.0;
   out_6974741239016485936[115] = 0.0;
   out_6974741239016485936[116] = 0.0;
   out_6974741239016485936[117] = 0.0;
   out_6974741239016485936[118] = 0.0;
   out_6974741239016485936[119] = 0.0;
   out_6974741239016485936[120] = 0.0;
   out_6974741239016485936[121] = 0.0;
   out_6974741239016485936[122] = 0.0;
   out_6974741239016485936[123] = 0.0;
   out_6974741239016485936[124] = 0.0;
   out_6974741239016485936[125] = 0.0;
   out_6974741239016485936[126] = 0.0;
   out_6974741239016485936[127] = 0.0;
   out_6974741239016485936[128] = 0.0;
   out_6974741239016485936[129] = 0.0;
   out_6974741239016485936[130] = 0.0;
   out_6974741239016485936[131] = 0.0;
   out_6974741239016485936[132] = 0.0;
   out_6974741239016485936[133] = 1.0;
   out_6974741239016485936[134] = 0.0;
   out_6974741239016485936[135] = 0.0;
   out_6974741239016485936[136] = 0.0;
   out_6974741239016485936[137] = 0.0;
   out_6974741239016485936[138] = 0.0;
   out_6974741239016485936[139] = 0.0;
   out_6974741239016485936[140] = 0.0;
   out_6974741239016485936[141] = 0.0;
   out_6974741239016485936[142] = 0.0;
   out_6974741239016485936[143] = 0.0;
   out_6974741239016485936[144] = 0.0;
   out_6974741239016485936[145] = 0.0;
   out_6974741239016485936[146] = 0.0;
   out_6974741239016485936[147] = 0.0;
   out_6974741239016485936[148] = 0.0;
   out_6974741239016485936[149] = 0.0;
   out_6974741239016485936[150] = 0.0;
   out_6974741239016485936[151] = 0.0;
   out_6974741239016485936[152] = 1.0;
   out_6974741239016485936[153] = 0.0;
   out_6974741239016485936[154] = 0.0;
   out_6974741239016485936[155] = 0.0;
   out_6974741239016485936[156] = 0.0;
   out_6974741239016485936[157] = 0.0;
   out_6974741239016485936[158] = 0.0;
   out_6974741239016485936[159] = 0.0;
   out_6974741239016485936[160] = 0.0;
   out_6974741239016485936[161] = 0.0;
   out_6974741239016485936[162] = 0.0;
   out_6974741239016485936[163] = 0.0;
   out_6974741239016485936[164] = 0.0;
   out_6974741239016485936[165] = 0.0;
   out_6974741239016485936[166] = 0.0;
   out_6974741239016485936[167] = 0.0;
   out_6974741239016485936[168] = 0.0;
   out_6974741239016485936[169] = 0.0;
   out_6974741239016485936[170] = 0.0;
   out_6974741239016485936[171] = 1.0;
   out_6974741239016485936[172] = 0.0;
   out_6974741239016485936[173] = 0.0;
   out_6974741239016485936[174] = 0.0;
   out_6974741239016485936[175] = 0.0;
   out_6974741239016485936[176] = 0.0;
   out_6974741239016485936[177] = 0.0;
   out_6974741239016485936[178] = 0.0;
   out_6974741239016485936[179] = 0.0;
   out_6974741239016485936[180] = 0.0;
   out_6974741239016485936[181] = 0.0;
   out_6974741239016485936[182] = 0.0;
   out_6974741239016485936[183] = 0.0;
   out_6974741239016485936[184] = 0.0;
   out_6974741239016485936[185] = 0.0;
   out_6974741239016485936[186] = 0.0;
   out_6974741239016485936[187] = 0.0;
   out_6974741239016485936[188] = 0.0;
   out_6974741239016485936[189] = 0.0;
   out_6974741239016485936[190] = 1.0;
   out_6974741239016485936[191] = 0.0;
   out_6974741239016485936[192] = 0.0;
   out_6974741239016485936[193] = 0.0;
   out_6974741239016485936[194] = 0.0;
   out_6974741239016485936[195] = 0.0;
   out_6974741239016485936[196] = 0.0;
   out_6974741239016485936[197] = 0.0;
   out_6974741239016485936[198] = 0.0;
   out_6974741239016485936[199] = 0.0;
   out_6974741239016485936[200] = 0.0;
   out_6974741239016485936[201] = 0.0;
   out_6974741239016485936[202] = 0.0;
   out_6974741239016485936[203] = 0.0;
   out_6974741239016485936[204] = 0.0;
   out_6974741239016485936[205] = 0.0;
   out_6974741239016485936[206] = 0.0;
   out_6974741239016485936[207] = 0.0;
   out_6974741239016485936[208] = 0.0;
   out_6974741239016485936[209] = 1.0;
   out_6974741239016485936[210] = 0.0;
   out_6974741239016485936[211] = 0.0;
   out_6974741239016485936[212] = 0.0;
   out_6974741239016485936[213] = 0.0;
   out_6974741239016485936[214] = 0.0;
   out_6974741239016485936[215] = 0.0;
   out_6974741239016485936[216] = 0.0;
   out_6974741239016485936[217] = 0.0;
   out_6974741239016485936[218] = 0.0;
   out_6974741239016485936[219] = 0.0;
   out_6974741239016485936[220] = 0.0;
   out_6974741239016485936[221] = 0.0;
   out_6974741239016485936[222] = 0.0;
   out_6974741239016485936[223] = 0.0;
   out_6974741239016485936[224] = 0.0;
   out_6974741239016485936[225] = 0.0;
   out_6974741239016485936[226] = 0.0;
   out_6974741239016485936[227] = 0.0;
   out_6974741239016485936[228] = 1.0;
   out_6974741239016485936[229] = 0.0;
   out_6974741239016485936[230] = 0.0;
   out_6974741239016485936[231] = 0.0;
   out_6974741239016485936[232] = 0.0;
   out_6974741239016485936[233] = 0.0;
   out_6974741239016485936[234] = 0.0;
   out_6974741239016485936[235] = 0.0;
   out_6974741239016485936[236] = 0.0;
   out_6974741239016485936[237] = 0.0;
   out_6974741239016485936[238] = 0.0;
   out_6974741239016485936[239] = 0.0;
   out_6974741239016485936[240] = 0.0;
   out_6974741239016485936[241] = 0.0;
   out_6974741239016485936[242] = 0.0;
   out_6974741239016485936[243] = 0.0;
   out_6974741239016485936[244] = 0.0;
   out_6974741239016485936[245] = 0.0;
   out_6974741239016485936[246] = 0.0;
   out_6974741239016485936[247] = 1.0;
   out_6974741239016485936[248] = 0.0;
   out_6974741239016485936[249] = 0.0;
   out_6974741239016485936[250] = 0.0;
   out_6974741239016485936[251] = 0.0;
   out_6974741239016485936[252] = 0.0;
   out_6974741239016485936[253] = 0.0;
   out_6974741239016485936[254] = 0.0;
   out_6974741239016485936[255] = 0.0;
   out_6974741239016485936[256] = 0.0;
   out_6974741239016485936[257] = 0.0;
   out_6974741239016485936[258] = 0.0;
   out_6974741239016485936[259] = 0.0;
   out_6974741239016485936[260] = 0.0;
   out_6974741239016485936[261] = 0.0;
   out_6974741239016485936[262] = 0.0;
   out_6974741239016485936[263] = 0.0;
   out_6974741239016485936[264] = 0.0;
   out_6974741239016485936[265] = 0.0;
   out_6974741239016485936[266] = 1.0;
   out_6974741239016485936[267] = 0.0;
   out_6974741239016485936[268] = 0.0;
   out_6974741239016485936[269] = 0.0;
   out_6974741239016485936[270] = 0.0;
   out_6974741239016485936[271] = 0.0;
   out_6974741239016485936[272] = 0.0;
   out_6974741239016485936[273] = 0.0;
   out_6974741239016485936[274] = 0.0;
   out_6974741239016485936[275] = 0.0;
   out_6974741239016485936[276] = 0.0;
   out_6974741239016485936[277] = 0.0;
   out_6974741239016485936[278] = 0.0;
   out_6974741239016485936[279] = 0.0;
   out_6974741239016485936[280] = 0.0;
   out_6974741239016485936[281] = 0.0;
   out_6974741239016485936[282] = 0.0;
   out_6974741239016485936[283] = 0.0;
   out_6974741239016485936[284] = 0.0;
   out_6974741239016485936[285] = 1.0;
   out_6974741239016485936[286] = 0.0;
   out_6974741239016485936[287] = 0.0;
   out_6974741239016485936[288] = 0.0;
   out_6974741239016485936[289] = 0.0;
   out_6974741239016485936[290] = 0.0;
   out_6974741239016485936[291] = 0.0;
   out_6974741239016485936[292] = 0.0;
   out_6974741239016485936[293] = 0.0;
   out_6974741239016485936[294] = 0.0;
   out_6974741239016485936[295] = 0.0;
   out_6974741239016485936[296] = 0.0;
   out_6974741239016485936[297] = 0.0;
   out_6974741239016485936[298] = 0.0;
   out_6974741239016485936[299] = 0.0;
   out_6974741239016485936[300] = 0.0;
   out_6974741239016485936[301] = 0.0;
   out_6974741239016485936[302] = 0.0;
   out_6974741239016485936[303] = 0.0;
   out_6974741239016485936[304] = 1.0;
   out_6974741239016485936[305] = 0.0;
   out_6974741239016485936[306] = 0.0;
   out_6974741239016485936[307] = 0.0;
   out_6974741239016485936[308] = 0.0;
   out_6974741239016485936[309] = 0.0;
   out_6974741239016485936[310] = 0.0;
   out_6974741239016485936[311] = 0.0;
   out_6974741239016485936[312] = 0.0;
   out_6974741239016485936[313] = 0.0;
   out_6974741239016485936[314] = 0.0;
   out_6974741239016485936[315] = 0.0;
   out_6974741239016485936[316] = 0.0;
   out_6974741239016485936[317] = 0.0;
   out_6974741239016485936[318] = 0.0;
   out_6974741239016485936[319] = 0.0;
   out_6974741239016485936[320] = 0.0;
   out_6974741239016485936[321] = 0.0;
   out_6974741239016485936[322] = 0.0;
   out_6974741239016485936[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7579043913228931093) {
   out_7579043913228931093[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7579043913228931093[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7579043913228931093[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7579043913228931093[3] = dt*state[12] + state[3];
   out_7579043913228931093[4] = dt*state[13] + state[4];
   out_7579043913228931093[5] = dt*state[14] + state[5];
   out_7579043913228931093[6] = state[6];
   out_7579043913228931093[7] = state[7];
   out_7579043913228931093[8] = state[8];
   out_7579043913228931093[9] = state[9];
   out_7579043913228931093[10] = state[10];
   out_7579043913228931093[11] = state[11];
   out_7579043913228931093[12] = state[12];
   out_7579043913228931093[13] = state[13];
   out_7579043913228931093[14] = state[14];
   out_7579043913228931093[15] = state[15];
   out_7579043913228931093[16] = state[16];
   out_7579043913228931093[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7552939469662313928) {
   out_7552939469662313928[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7552939469662313928[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7552939469662313928[2] = 0;
   out_7552939469662313928[3] = 0;
   out_7552939469662313928[4] = 0;
   out_7552939469662313928[5] = 0;
   out_7552939469662313928[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7552939469662313928[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7552939469662313928[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7552939469662313928[9] = 0;
   out_7552939469662313928[10] = 0;
   out_7552939469662313928[11] = 0;
   out_7552939469662313928[12] = 0;
   out_7552939469662313928[13] = 0;
   out_7552939469662313928[14] = 0;
   out_7552939469662313928[15] = 0;
   out_7552939469662313928[16] = 0;
   out_7552939469662313928[17] = 0;
   out_7552939469662313928[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7552939469662313928[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7552939469662313928[20] = 0;
   out_7552939469662313928[21] = 0;
   out_7552939469662313928[22] = 0;
   out_7552939469662313928[23] = 0;
   out_7552939469662313928[24] = 0;
   out_7552939469662313928[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7552939469662313928[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7552939469662313928[27] = 0;
   out_7552939469662313928[28] = 0;
   out_7552939469662313928[29] = 0;
   out_7552939469662313928[30] = 0;
   out_7552939469662313928[31] = 0;
   out_7552939469662313928[32] = 0;
   out_7552939469662313928[33] = 0;
   out_7552939469662313928[34] = 0;
   out_7552939469662313928[35] = 0;
   out_7552939469662313928[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7552939469662313928[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7552939469662313928[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7552939469662313928[39] = 0;
   out_7552939469662313928[40] = 0;
   out_7552939469662313928[41] = 0;
   out_7552939469662313928[42] = 0;
   out_7552939469662313928[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7552939469662313928[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7552939469662313928[45] = 0;
   out_7552939469662313928[46] = 0;
   out_7552939469662313928[47] = 0;
   out_7552939469662313928[48] = 0;
   out_7552939469662313928[49] = 0;
   out_7552939469662313928[50] = 0;
   out_7552939469662313928[51] = 0;
   out_7552939469662313928[52] = 0;
   out_7552939469662313928[53] = 0;
   out_7552939469662313928[54] = 0;
   out_7552939469662313928[55] = 0;
   out_7552939469662313928[56] = 0;
   out_7552939469662313928[57] = 1;
   out_7552939469662313928[58] = 0;
   out_7552939469662313928[59] = 0;
   out_7552939469662313928[60] = 0;
   out_7552939469662313928[61] = 0;
   out_7552939469662313928[62] = 0;
   out_7552939469662313928[63] = 0;
   out_7552939469662313928[64] = 0;
   out_7552939469662313928[65] = 0;
   out_7552939469662313928[66] = dt;
   out_7552939469662313928[67] = 0;
   out_7552939469662313928[68] = 0;
   out_7552939469662313928[69] = 0;
   out_7552939469662313928[70] = 0;
   out_7552939469662313928[71] = 0;
   out_7552939469662313928[72] = 0;
   out_7552939469662313928[73] = 0;
   out_7552939469662313928[74] = 0;
   out_7552939469662313928[75] = 0;
   out_7552939469662313928[76] = 1;
   out_7552939469662313928[77] = 0;
   out_7552939469662313928[78] = 0;
   out_7552939469662313928[79] = 0;
   out_7552939469662313928[80] = 0;
   out_7552939469662313928[81] = 0;
   out_7552939469662313928[82] = 0;
   out_7552939469662313928[83] = 0;
   out_7552939469662313928[84] = 0;
   out_7552939469662313928[85] = dt;
   out_7552939469662313928[86] = 0;
   out_7552939469662313928[87] = 0;
   out_7552939469662313928[88] = 0;
   out_7552939469662313928[89] = 0;
   out_7552939469662313928[90] = 0;
   out_7552939469662313928[91] = 0;
   out_7552939469662313928[92] = 0;
   out_7552939469662313928[93] = 0;
   out_7552939469662313928[94] = 0;
   out_7552939469662313928[95] = 1;
   out_7552939469662313928[96] = 0;
   out_7552939469662313928[97] = 0;
   out_7552939469662313928[98] = 0;
   out_7552939469662313928[99] = 0;
   out_7552939469662313928[100] = 0;
   out_7552939469662313928[101] = 0;
   out_7552939469662313928[102] = 0;
   out_7552939469662313928[103] = 0;
   out_7552939469662313928[104] = dt;
   out_7552939469662313928[105] = 0;
   out_7552939469662313928[106] = 0;
   out_7552939469662313928[107] = 0;
   out_7552939469662313928[108] = 0;
   out_7552939469662313928[109] = 0;
   out_7552939469662313928[110] = 0;
   out_7552939469662313928[111] = 0;
   out_7552939469662313928[112] = 0;
   out_7552939469662313928[113] = 0;
   out_7552939469662313928[114] = 1;
   out_7552939469662313928[115] = 0;
   out_7552939469662313928[116] = 0;
   out_7552939469662313928[117] = 0;
   out_7552939469662313928[118] = 0;
   out_7552939469662313928[119] = 0;
   out_7552939469662313928[120] = 0;
   out_7552939469662313928[121] = 0;
   out_7552939469662313928[122] = 0;
   out_7552939469662313928[123] = 0;
   out_7552939469662313928[124] = 0;
   out_7552939469662313928[125] = 0;
   out_7552939469662313928[126] = 0;
   out_7552939469662313928[127] = 0;
   out_7552939469662313928[128] = 0;
   out_7552939469662313928[129] = 0;
   out_7552939469662313928[130] = 0;
   out_7552939469662313928[131] = 0;
   out_7552939469662313928[132] = 0;
   out_7552939469662313928[133] = 1;
   out_7552939469662313928[134] = 0;
   out_7552939469662313928[135] = 0;
   out_7552939469662313928[136] = 0;
   out_7552939469662313928[137] = 0;
   out_7552939469662313928[138] = 0;
   out_7552939469662313928[139] = 0;
   out_7552939469662313928[140] = 0;
   out_7552939469662313928[141] = 0;
   out_7552939469662313928[142] = 0;
   out_7552939469662313928[143] = 0;
   out_7552939469662313928[144] = 0;
   out_7552939469662313928[145] = 0;
   out_7552939469662313928[146] = 0;
   out_7552939469662313928[147] = 0;
   out_7552939469662313928[148] = 0;
   out_7552939469662313928[149] = 0;
   out_7552939469662313928[150] = 0;
   out_7552939469662313928[151] = 0;
   out_7552939469662313928[152] = 1;
   out_7552939469662313928[153] = 0;
   out_7552939469662313928[154] = 0;
   out_7552939469662313928[155] = 0;
   out_7552939469662313928[156] = 0;
   out_7552939469662313928[157] = 0;
   out_7552939469662313928[158] = 0;
   out_7552939469662313928[159] = 0;
   out_7552939469662313928[160] = 0;
   out_7552939469662313928[161] = 0;
   out_7552939469662313928[162] = 0;
   out_7552939469662313928[163] = 0;
   out_7552939469662313928[164] = 0;
   out_7552939469662313928[165] = 0;
   out_7552939469662313928[166] = 0;
   out_7552939469662313928[167] = 0;
   out_7552939469662313928[168] = 0;
   out_7552939469662313928[169] = 0;
   out_7552939469662313928[170] = 0;
   out_7552939469662313928[171] = 1;
   out_7552939469662313928[172] = 0;
   out_7552939469662313928[173] = 0;
   out_7552939469662313928[174] = 0;
   out_7552939469662313928[175] = 0;
   out_7552939469662313928[176] = 0;
   out_7552939469662313928[177] = 0;
   out_7552939469662313928[178] = 0;
   out_7552939469662313928[179] = 0;
   out_7552939469662313928[180] = 0;
   out_7552939469662313928[181] = 0;
   out_7552939469662313928[182] = 0;
   out_7552939469662313928[183] = 0;
   out_7552939469662313928[184] = 0;
   out_7552939469662313928[185] = 0;
   out_7552939469662313928[186] = 0;
   out_7552939469662313928[187] = 0;
   out_7552939469662313928[188] = 0;
   out_7552939469662313928[189] = 0;
   out_7552939469662313928[190] = 1;
   out_7552939469662313928[191] = 0;
   out_7552939469662313928[192] = 0;
   out_7552939469662313928[193] = 0;
   out_7552939469662313928[194] = 0;
   out_7552939469662313928[195] = 0;
   out_7552939469662313928[196] = 0;
   out_7552939469662313928[197] = 0;
   out_7552939469662313928[198] = 0;
   out_7552939469662313928[199] = 0;
   out_7552939469662313928[200] = 0;
   out_7552939469662313928[201] = 0;
   out_7552939469662313928[202] = 0;
   out_7552939469662313928[203] = 0;
   out_7552939469662313928[204] = 0;
   out_7552939469662313928[205] = 0;
   out_7552939469662313928[206] = 0;
   out_7552939469662313928[207] = 0;
   out_7552939469662313928[208] = 0;
   out_7552939469662313928[209] = 1;
   out_7552939469662313928[210] = 0;
   out_7552939469662313928[211] = 0;
   out_7552939469662313928[212] = 0;
   out_7552939469662313928[213] = 0;
   out_7552939469662313928[214] = 0;
   out_7552939469662313928[215] = 0;
   out_7552939469662313928[216] = 0;
   out_7552939469662313928[217] = 0;
   out_7552939469662313928[218] = 0;
   out_7552939469662313928[219] = 0;
   out_7552939469662313928[220] = 0;
   out_7552939469662313928[221] = 0;
   out_7552939469662313928[222] = 0;
   out_7552939469662313928[223] = 0;
   out_7552939469662313928[224] = 0;
   out_7552939469662313928[225] = 0;
   out_7552939469662313928[226] = 0;
   out_7552939469662313928[227] = 0;
   out_7552939469662313928[228] = 1;
   out_7552939469662313928[229] = 0;
   out_7552939469662313928[230] = 0;
   out_7552939469662313928[231] = 0;
   out_7552939469662313928[232] = 0;
   out_7552939469662313928[233] = 0;
   out_7552939469662313928[234] = 0;
   out_7552939469662313928[235] = 0;
   out_7552939469662313928[236] = 0;
   out_7552939469662313928[237] = 0;
   out_7552939469662313928[238] = 0;
   out_7552939469662313928[239] = 0;
   out_7552939469662313928[240] = 0;
   out_7552939469662313928[241] = 0;
   out_7552939469662313928[242] = 0;
   out_7552939469662313928[243] = 0;
   out_7552939469662313928[244] = 0;
   out_7552939469662313928[245] = 0;
   out_7552939469662313928[246] = 0;
   out_7552939469662313928[247] = 1;
   out_7552939469662313928[248] = 0;
   out_7552939469662313928[249] = 0;
   out_7552939469662313928[250] = 0;
   out_7552939469662313928[251] = 0;
   out_7552939469662313928[252] = 0;
   out_7552939469662313928[253] = 0;
   out_7552939469662313928[254] = 0;
   out_7552939469662313928[255] = 0;
   out_7552939469662313928[256] = 0;
   out_7552939469662313928[257] = 0;
   out_7552939469662313928[258] = 0;
   out_7552939469662313928[259] = 0;
   out_7552939469662313928[260] = 0;
   out_7552939469662313928[261] = 0;
   out_7552939469662313928[262] = 0;
   out_7552939469662313928[263] = 0;
   out_7552939469662313928[264] = 0;
   out_7552939469662313928[265] = 0;
   out_7552939469662313928[266] = 1;
   out_7552939469662313928[267] = 0;
   out_7552939469662313928[268] = 0;
   out_7552939469662313928[269] = 0;
   out_7552939469662313928[270] = 0;
   out_7552939469662313928[271] = 0;
   out_7552939469662313928[272] = 0;
   out_7552939469662313928[273] = 0;
   out_7552939469662313928[274] = 0;
   out_7552939469662313928[275] = 0;
   out_7552939469662313928[276] = 0;
   out_7552939469662313928[277] = 0;
   out_7552939469662313928[278] = 0;
   out_7552939469662313928[279] = 0;
   out_7552939469662313928[280] = 0;
   out_7552939469662313928[281] = 0;
   out_7552939469662313928[282] = 0;
   out_7552939469662313928[283] = 0;
   out_7552939469662313928[284] = 0;
   out_7552939469662313928[285] = 1;
   out_7552939469662313928[286] = 0;
   out_7552939469662313928[287] = 0;
   out_7552939469662313928[288] = 0;
   out_7552939469662313928[289] = 0;
   out_7552939469662313928[290] = 0;
   out_7552939469662313928[291] = 0;
   out_7552939469662313928[292] = 0;
   out_7552939469662313928[293] = 0;
   out_7552939469662313928[294] = 0;
   out_7552939469662313928[295] = 0;
   out_7552939469662313928[296] = 0;
   out_7552939469662313928[297] = 0;
   out_7552939469662313928[298] = 0;
   out_7552939469662313928[299] = 0;
   out_7552939469662313928[300] = 0;
   out_7552939469662313928[301] = 0;
   out_7552939469662313928[302] = 0;
   out_7552939469662313928[303] = 0;
   out_7552939469662313928[304] = 1;
   out_7552939469662313928[305] = 0;
   out_7552939469662313928[306] = 0;
   out_7552939469662313928[307] = 0;
   out_7552939469662313928[308] = 0;
   out_7552939469662313928[309] = 0;
   out_7552939469662313928[310] = 0;
   out_7552939469662313928[311] = 0;
   out_7552939469662313928[312] = 0;
   out_7552939469662313928[313] = 0;
   out_7552939469662313928[314] = 0;
   out_7552939469662313928[315] = 0;
   out_7552939469662313928[316] = 0;
   out_7552939469662313928[317] = 0;
   out_7552939469662313928[318] = 0;
   out_7552939469662313928[319] = 0;
   out_7552939469662313928[320] = 0;
   out_7552939469662313928[321] = 0;
   out_7552939469662313928[322] = 0;
   out_7552939469662313928[323] = 1;
}
void h_4(double *state, double *unused, double *out_3550900755285532144) {
   out_3550900755285532144[0] = state[6] + state[9];
   out_3550900755285532144[1] = state[7] + state[10];
   out_3550900755285532144[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3202934029172578364) {
   out_3202934029172578364[0] = 0;
   out_3202934029172578364[1] = 0;
   out_3202934029172578364[2] = 0;
   out_3202934029172578364[3] = 0;
   out_3202934029172578364[4] = 0;
   out_3202934029172578364[5] = 0;
   out_3202934029172578364[6] = 1;
   out_3202934029172578364[7] = 0;
   out_3202934029172578364[8] = 0;
   out_3202934029172578364[9] = 1;
   out_3202934029172578364[10] = 0;
   out_3202934029172578364[11] = 0;
   out_3202934029172578364[12] = 0;
   out_3202934029172578364[13] = 0;
   out_3202934029172578364[14] = 0;
   out_3202934029172578364[15] = 0;
   out_3202934029172578364[16] = 0;
   out_3202934029172578364[17] = 0;
   out_3202934029172578364[18] = 0;
   out_3202934029172578364[19] = 0;
   out_3202934029172578364[20] = 0;
   out_3202934029172578364[21] = 0;
   out_3202934029172578364[22] = 0;
   out_3202934029172578364[23] = 0;
   out_3202934029172578364[24] = 0;
   out_3202934029172578364[25] = 1;
   out_3202934029172578364[26] = 0;
   out_3202934029172578364[27] = 0;
   out_3202934029172578364[28] = 1;
   out_3202934029172578364[29] = 0;
   out_3202934029172578364[30] = 0;
   out_3202934029172578364[31] = 0;
   out_3202934029172578364[32] = 0;
   out_3202934029172578364[33] = 0;
   out_3202934029172578364[34] = 0;
   out_3202934029172578364[35] = 0;
   out_3202934029172578364[36] = 0;
   out_3202934029172578364[37] = 0;
   out_3202934029172578364[38] = 0;
   out_3202934029172578364[39] = 0;
   out_3202934029172578364[40] = 0;
   out_3202934029172578364[41] = 0;
   out_3202934029172578364[42] = 0;
   out_3202934029172578364[43] = 0;
   out_3202934029172578364[44] = 1;
   out_3202934029172578364[45] = 0;
   out_3202934029172578364[46] = 0;
   out_3202934029172578364[47] = 1;
   out_3202934029172578364[48] = 0;
   out_3202934029172578364[49] = 0;
   out_3202934029172578364[50] = 0;
   out_3202934029172578364[51] = 0;
   out_3202934029172578364[52] = 0;
   out_3202934029172578364[53] = 0;
}
void h_10(double *state, double *unused, double *out_7067714338468602861) {
   out_7067714338468602861[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7067714338468602861[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7067714338468602861[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4832878358593471680) {
   out_4832878358593471680[0] = 0;
   out_4832878358593471680[1] = 9.8100000000000005*cos(state[1]);
   out_4832878358593471680[2] = 0;
   out_4832878358593471680[3] = 0;
   out_4832878358593471680[4] = -state[8];
   out_4832878358593471680[5] = state[7];
   out_4832878358593471680[6] = 0;
   out_4832878358593471680[7] = state[5];
   out_4832878358593471680[8] = -state[4];
   out_4832878358593471680[9] = 0;
   out_4832878358593471680[10] = 0;
   out_4832878358593471680[11] = 0;
   out_4832878358593471680[12] = 1;
   out_4832878358593471680[13] = 0;
   out_4832878358593471680[14] = 0;
   out_4832878358593471680[15] = 1;
   out_4832878358593471680[16] = 0;
   out_4832878358593471680[17] = 0;
   out_4832878358593471680[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4832878358593471680[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4832878358593471680[20] = 0;
   out_4832878358593471680[21] = state[8];
   out_4832878358593471680[22] = 0;
   out_4832878358593471680[23] = -state[6];
   out_4832878358593471680[24] = -state[5];
   out_4832878358593471680[25] = 0;
   out_4832878358593471680[26] = state[3];
   out_4832878358593471680[27] = 0;
   out_4832878358593471680[28] = 0;
   out_4832878358593471680[29] = 0;
   out_4832878358593471680[30] = 0;
   out_4832878358593471680[31] = 1;
   out_4832878358593471680[32] = 0;
   out_4832878358593471680[33] = 0;
   out_4832878358593471680[34] = 1;
   out_4832878358593471680[35] = 0;
   out_4832878358593471680[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4832878358593471680[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4832878358593471680[38] = 0;
   out_4832878358593471680[39] = -state[7];
   out_4832878358593471680[40] = state[6];
   out_4832878358593471680[41] = 0;
   out_4832878358593471680[42] = state[4];
   out_4832878358593471680[43] = -state[3];
   out_4832878358593471680[44] = 0;
   out_4832878358593471680[45] = 0;
   out_4832878358593471680[46] = 0;
   out_4832878358593471680[47] = 0;
   out_4832878358593471680[48] = 0;
   out_4832878358593471680[49] = 0;
   out_4832878358593471680[50] = 1;
   out_4832878358593471680[51] = 0;
   out_4832878358593471680[52] = 0;
   out_4832878358593471680[53] = 1;
}
void h_13(double *state, double *unused, double *out_6451839863147612103) {
   out_6451839863147612103[0] = state[3];
   out_6451839863147612103[1] = state[4];
   out_6451839863147612103[2] = state[5];
}
void H_13(double *state, double *unused, double *out_9339796159754437) {
   out_9339796159754437[0] = 0;
   out_9339796159754437[1] = 0;
   out_9339796159754437[2] = 0;
   out_9339796159754437[3] = 1;
   out_9339796159754437[4] = 0;
   out_9339796159754437[5] = 0;
   out_9339796159754437[6] = 0;
   out_9339796159754437[7] = 0;
   out_9339796159754437[8] = 0;
   out_9339796159754437[9] = 0;
   out_9339796159754437[10] = 0;
   out_9339796159754437[11] = 0;
   out_9339796159754437[12] = 0;
   out_9339796159754437[13] = 0;
   out_9339796159754437[14] = 0;
   out_9339796159754437[15] = 0;
   out_9339796159754437[16] = 0;
   out_9339796159754437[17] = 0;
   out_9339796159754437[18] = 0;
   out_9339796159754437[19] = 0;
   out_9339796159754437[20] = 0;
   out_9339796159754437[21] = 0;
   out_9339796159754437[22] = 1;
   out_9339796159754437[23] = 0;
   out_9339796159754437[24] = 0;
   out_9339796159754437[25] = 0;
   out_9339796159754437[26] = 0;
   out_9339796159754437[27] = 0;
   out_9339796159754437[28] = 0;
   out_9339796159754437[29] = 0;
   out_9339796159754437[30] = 0;
   out_9339796159754437[31] = 0;
   out_9339796159754437[32] = 0;
   out_9339796159754437[33] = 0;
   out_9339796159754437[34] = 0;
   out_9339796159754437[35] = 0;
   out_9339796159754437[36] = 0;
   out_9339796159754437[37] = 0;
   out_9339796159754437[38] = 0;
   out_9339796159754437[39] = 0;
   out_9339796159754437[40] = 0;
   out_9339796159754437[41] = 1;
   out_9339796159754437[42] = 0;
   out_9339796159754437[43] = 0;
   out_9339796159754437[44] = 0;
   out_9339796159754437[45] = 0;
   out_9339796159754437[46] = 0;
   out_9339796159754437[47] = 0;
   out_9339796159754437[48] = 0;
   out_9339796159754437[49] = 0;
   out_9339796159754437[50] = 0;
   out_9339796159754437[51] = 0;
   out_9339796159754437[52] = 0;
   out_9339796159754437[53] = 0;
}
void h_14(double *state, double *unused, double *out_3486571009539339858) {
   out_3486571009539339858[0] = state[6];
   out_3486571009539339858[1] = state[7];
   out_3486571009539339858[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6285722461467950660) {
   out_6285722461467950660[0] = 0;
   out_6285722461467950660[1] = 0;
   out_6285722461467950660[2] = 0;
   out_6285722461467950660[3] = 0;
   out_6285722461467950660[4] = 0;
   out_6285722461467950660[5] = 0;
   out_6285722461467950660[6] = 1;
   out_6285722461467950660[7] = 0;
   out_6285722461467950660[8] = 0;
   out_6285722461467950660[9] = 0;
   out_6285722461467950660[10] = 0;
   out_6285722461467950660[11] = 0;
   out_6285722461467950660[12] = 0;
   out_6285722461467950660[13] = 0;
   out_6285722461467950660[14] = 0;
   out_6285722461467950660[15] = 0;
   out_6285722461467950660[16] = 0;
   out_6285722461467950660[17] = 0;
   out_6285722461467950660[18] = 0;
   out_6285722461467950660[19] = 0;
   out_6285722461467950660[20] = 0;
   out_6285722461467950660[21] = 0;
   out_6285722461467950660[22] = 0;
   out_6285722461467950660[23] = 0;
   out_6285722461467950660[24] = 0;
   out_6285722461467950660[25] = 1;
   out_6285722461467950660[26] = 0;
   out_6285722461467950660[27] = 0;
   out_6285722461467950660[28] = 0;
   out_6285722461467950660[29] = 0;
   out_6285722461467950660[30] = 0;
   out_6285722461467950660[31] = 0;
   out_6285722461467950660[32] = 0;
   out_6285722461467950660[33] = 0;
   out_6285722461467950660[34] = 0;
   out_6285722461467950660[35] = 0;
   out_6285722461467950660[36] = 0;
   out_6285722461467950660[37] = 0;
   out_6285722461467950660[38] = 0;
   out_6285722461467950660[39] = 0;
   out_6285722461467950660[40] = 0;
   out_6285722461467950660[41] = 0;
   out_6285722461467950660[42] = 0;
   out_6285722461467950660[43] = 0;
   out_6285722461467950660[44] = 1;
   out_6285722461467950660[45] = 0;
   out_6285722461467950660[46] = 0;
   out_6285722461467950660[47] = 0;
   out_6285722461467950660[48] = 0;
   out_6285722461467950660[49] = 0;
   out_6285722461467950660[50] = 0;
   out_6285722461467950660[51] = 0;
   out_6285722461467950660[52] = 0;
   out_6285722461467950660[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_6520327552806096841) {
  err_fun(nom_x, delta_x, out_6520327552806096841);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3933583929675800728) {
  inv_err_fun(nom_x, true_x, out_3933583929675800728);
}
void pose_H_mod_fun(double *state, double *out_6974741239016485936) {
  H_mod_fun(state, out_6974741239016485936);
}
void pose_f_fun(double *state, double dt, double *out_7579043913228931093) {
  f_fun(state,  dt, out_7579043913228931093);
}
void pose_F_fun(double *state, double dt, double *out_7552939469662313928) {
  F_fun(state,  dt, out_7552939469662313928);
}
void pose_h_4(double *state, double *unused, double *out_3550900755285532144) {
  h_4(state, unused, out_3550900755285532144);
}
void pose_H_4(double *state, double *unused, double *out_3202934029172578364) {
  H_4(state, unused, out_3202934029172578364);
}
void pose_h_10(double *state, double *unused, double *out_7067714338468602861) {
  h_10(state, unused, out_7067714338468602861);
}
void pose_H_10(double *state, double *unused, double *out_4832878358593471680) {
  H_10(state, unused, out_4832878358593471680);
}
void pose_h_13(double *state, double *unused, double *out_6451839863147612103) {
  h_13(state, unused, out_6451839863147612103);
}
void pose_H_13(double *state, double *unused, double *out_9339796159754437) {
  H_13(state, unused, out_9339796159754437);
}
void pose_h_14(double *state, double *unused, double *out_3486571009539339858) {
  h_14(state, unused, out_3486571009539339858);
}
void pose_H_14(double *state, double *unused, double *out_6285722461467950660) {
  H_14(state, unused, out_6285722461467950660);
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
