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
void err_fun(double *nom_x, double *delta_x, double *out_5715232905817063541) {
   out_5715232905817063541[0] = delta_x[0] + nom_x[0];
   out_5715232905817063541[1] = delta_x[1] + nom_x[1];
   out_5715232905817063541[2] = delta_x[2] + nom_x[2];
   out_5715232905817063541[3] = delta_x[3] + nom_x[3];
   out_5715232905817063541[4] = delta_x[4] + nom_x[4];
   out_5715232905817063541[5] = delta_x[5] + nom_x[5];
   out_5715232905817063541[6] = delta_x[6] + nom_x[6];
   out_5715232905817063541[7] = delta_x[7] + nom_x[7];
   out_5715232905817063541[8] = delta_x[8] + nom_x[8];
   out_5715232905817063541[9] = delta_x[9] + nom_x[9];
   out_5715232905817063541[10] = delta_x[10] + nom_x[10];
   out_5715232905817063541[11] = delta_x[11] + nom_x[11];
   out_5715232905817063541[12] = delta_x[12] + nom_x[12];
   out_5715232905817063541[13] = delta_x[13] + nom_x[13];
   out_5715232905817063541[14] = delta_x[14] + nom_x[14];
   out_5715232905817063541[15] = delta_x[15] + nom_x[15];
   out_5715232905817063541[16] = delta_x[16] + nom_x[16];
   out_5715232905817063541[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5652160587936785451) {
   out_5652160587936785451[0] = -nom_x[0] + true_x[0];
   out_5652160587936785451[1] = -nom_x[1] + true_x[1];
   out_5652160587936785451[2] = -nom_x[2] + true_x[2];
   out_5652160587936785451[3] = -nom_x[3] + true_x[3];
   out_5652160587936785451[4] = -nom_x[4] + true_x[4];
   out_5652160587936785451[5] = -nom_x[5] + true_x[5];
   out_5652160587936785451[6] = -nom_x[6] + true_x[6];
   out_5652160587936785451[7] = -nom_x[7] + true_x[7];
   out_5652160587936785451[8] = -nom_x[8] + true_x[8];
   out_5652160587936785451[9] = -nom_x[9] + true_x[9];
   out_5652160587936785451[10] = -nom_x[10] + true_x[10];
   out_5652160587936785451[11] = -nom_x[11] + true_x[11];
   out_5652160587936785451[12] = -nom_x[12] + true_x[12];
   out_5652160587936785451[13] = -nom_x[13] + true_x[13];
   out_5652160587936785451[14] = -nom_x[14] + true_x[14];
   out_5652160587936785451[15] = -nom_x[15] + true_x[15];
   out_5652160587936785451[16] = -nom_x[16] + true_x[16];
   out_5652160587936785451[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4347742436966495208) {
   out_4347742436966495208[0] = 1.0;
   out_4347742436966495208[1] = 0.0;
   out_4347742436966495208[2] = 0.0;
   out_4347742436966495208[3] = 0.0;
   out_4347742436966495208[4] = 0.0;
   out_4347742436966495208[5] = 0.0;
   out_4347742436966495208[6] = 0.0;
   out_4347742436966495208[7] = 0.0;
   out_4347742436966495208[8] = 0.0;
   out_4347742436966495208[9] = 0.0;
   out_4347742436966495208[10] = 0.0;
   out_4347742436966495208[11] = 0.0;
   out_4347742436966495208[12] = 0.0;
   out_4347742436966495208[13] = 0.0;
   out_4347742436966495208[14] = 0.0;
   out_4347742436966495208[15] = 0.0;
   out_4347742436966495208[16] = 0.0;
   out_4347742436966495208[17] = 0.0;
   out_4347742436966495208[18] = 0.0;
   out_4347742436966495208[19] = 1.0;
   out_4347742436966495208[20] = 0.0;
   out_4347742436966495208[21] = 0.0;
   out_4347742436966495208[22] = 0.0;
   out_4347742436966495208[23] = 0.0;
   out_4347742436966495208[24] = 0.0;
   out_4347742436966495208[25] = 0.0;
   out_4347742436966495208[26] = 0.0;
   out_4347742436966495208[27] = 0.0;
   out_4347742436966495208[28] = 0.0;
   out_4347742436966495208[29] = 0.0;
   out_4347742436966495208[30] = 0.0;
   out_4347742436966495208[31] = 0.0;
   out_4347742436966495208[32] = 0.0;
   out_4347742436966495208[33] = 0.0;
   out_4347742436966495208[34] = 0.0;
   out_4347742436966495208[35] = 0.0;
   out_4347742436966495208[36] = 0.0;
   out_4347742436966495208[37] = 0.0;
   out_4347742436966495208[38] = 1.0;
   out_4347742436966495208[39] = 0.0;
   out_4347742436966495208[40] = 0.0;
   out_4347742436966495208[41] = 0.0;
   out_4347742436966495208[42] = 0.0;
   out_4347742436966495208[43] = 0.0;
   out_4347742436966495208[44] = 0.0;
   out_4347742436966495208[45] = 0.0;
   out_4347742436966495208[46] = 0.0;
   out_4347742436966495208[47] = 0.0;
   out_4347742436966495208[48] = 0.0;
   out_4347742436966495208[49] = 0.0;
   out_4347742436966495208[50] = 0.0;
   out_4347742436966495208[51] = 0.0;
   out_4347742436966495208[52] = 0.0;
   out_4347742436966495208[53] = 0.0;
   out_4347742436966495208[54] = 0.0;
   out_4347742436966495208[55] = 0.0;
   out_4347742436966495208[56] = 0.0;
   out_4347742436966495208[57] = 1.0;
   out_4347742436966495208[58] = 0.0;
   out_4347742436966495208[59] = 0.0;
   out_4347742436966495208[60] = 0.0;
   out_4347742436966495208[61] = 0.0;
   out_4347742436966495208[62] = 0.0;
   out_4347742436966495208[63] = 0.0;
   out_4347742436966495208[64] = 0.0;
   out_4347742436966495208[65] = 0.0;
   out_4347742436966495208[66] = 0.0;
   out_4347742436966495208[67] = 0.0;
   out_4347742436966495208[68] = 0.0;
   out_4347742436966495208[69] = 0.0;
   out_4347742436966495208[70] = 0.0;
   out_4347742436966495208[71] = 0.0;
   out_4347742436966495208[72] = 0.0;
   out_4347742436966495208[73] = 0.0;
   out_4347742436966495208[74] = 0.0;
   out_4347742436966495208[75] = 0.0;
   out_4347742436966495208[76] = 1.0;
   out_4347742436966495208[77] = 0.0;
   out_4347742436966495208[78] = 0.0;
   out_4347742436966495208[79] = 0.0;
   out_4347742436966495208[80] = 0.0;
   out_4347742436966495208[81] = 0.0;
   out_4347742436966495208[82] = 0.0;
   out_4347742436966495208[83] = 0.0;
   out_4347742436966495208[84] = 0.0;
   out_4347742436966495208[85] = 0.0;
   out_4347742436966495208[86] = 0.0;
   out_4347742436966495208[87] = 0.0;
   out_4347742436966495208[88] = 0.0;
   out_4347742436966495208[89] = 0.0;
   out_4347742436966495208[90] = 0.0;
   out_4347742436966495208[91] = 0.0;
   out_4347742436966495208[92] = 0.0;
   out_4347742436966495208[93] = 0.0;
   out_4347742436966495208[94] = 0.0;
   out_4347742436966495208[95] = 1.0;
   out_4347742436966495208[96] = 0.0;
   out_4347742436966495208[97] = 0.0;
   out_4347742436966495208[98] = 0.0;
   out_4347742436966495208[99] = 0.0;
   out_4347742436966495208[100] = 0.0;
   out_4347742436966495208[101] = 0.0;
   out_4347742436966495208[102] = 0.0;
   out_4347742436966495208[103] = 0.0;
   out_4347742436966495208[104] = 0.0;
   out_4347742436966495208[105] = 0.0;
   out_4347742436966495208[106] = 0.0;
   out_4347742436966495208[107] = 0.0;
   out_4347742436966495208[108] = 0.0;
   out_4347742436966495208[109] = 0.0;
   out_4347742436966495208[110] = 0.0;
   out_4347742436966495208[111] = 0.0;
   out_4347742436966495208[112] = 0.0;
   out_4347742436966495208[113] = 0.0;
   out_4347742436966495208[114] = 1.0;
   out_4347742436966495208[115] = 0.0;
   out_4347742436966495208[116] = 0.0;
   out_4347742436966495208[117] = 0.0;
   out_4347742436966495208[118] = 0.0;
   out_4347742436966495208[119] = 0.0;
   out_4347742436966495208[120] = 0.0;
   out_4347742436966495208[121] = 0.0;
   out_4347742436966495208[122] = 0.0;
   out_4347742436966495208[123] = 0.0;
   out_4347742436966495208[124] = 0.0;
   out_4347742436966495208[125] = 0.0;
   out_4347742436966495208[126] = 0.0;
   out_4347742436966495208[127] = 0.0;
   out_4347742436966495208[128] = 0.0;
   out_4347742436966495208[129] = 0.0;
   out_4347742436966495208[130] = 0.0;
   out_4347742436966495208[131] = 0.0;
   out_4347742436966495208[132] = 0.0;
   out_4347742436966495208[133] = 1.0;
   out_4347742436966495208[134] = 0.0;
   out_4347742436966495208[135] = 0.0;
   out_4347742436966495208[136] = 0.0;
   out_4347742436966495208[137] = 0.0;
   out_4347742436966495208[138] = 0.0;
   out_4347742436966495208[139] = 0.0;
   out_4347742436966495208[140] = 0.0;
   out_4347742436966495208[141] = 0.0;
   out_4347742436966495208[142] = 0.0;
   out_4347742436966495208[143] = 0.0;
   out_4347742436966495208[144] = 0.0;
   out_4347742436966495208[145] = 0.0;
   out_4347742436966495208[146] = 0.0;
   out_4347742436966495208[147] = 0.0;
   out_4347742436966495208[148] = 0.0;
   out_4347742436966495208[149] = 0.0;
   out_4347742436966495208[150] = 0.0;
   out_4347742436966495208[151] = 0.0;
   out_4347742436966495208[152] = 1.0;
   out_4347742436966495208[153] = 0.0;
   out_4347742436966495208[154] = 0.0;
   out_4347742436966495208[155] = 0.0;
   out_4347742436966495208[156] = 0.0;
   out_4347742436966495208[157] = 0.0;
   out_4347742436966495208[158] = 0.0;
   out_4347742436966495208[159] = 0.0;
   out_4347742436966495208[160] = 0.0;
   out_4347742436966495208[161] = 0.0;
   out_4347742436966495208[162] = 0.0;
   out_4347742436966495208[163] = 0.0;
   out_4347742436966495208[164] = 0.0;
   out_4347742436966495208[165] = 0.0;
   out_4347742436966495208[166] = 0.0;
   out_4347742436966495208[167] = 0.0;
   out_4347742436966495208[168] = 0.0;
   out_4347742436966495208[169] = 0.0;
   out_4347742436966495208[170] = 0.0;
   out_4347742436966495208[171] = 1.0;
   out_4347742436966495208[172] = 0.0;
   out_4347742436966495208[173] = 0.0;
   out_4347742436966495208[174] = 0.0;
   out_4347742436966495208[175] = 0.0;
   out_4347742436966495208[176] = 0.0;
   out_4347742436966495208[177] = 0.0;
   out_4347742436966495208[178] = 0.0;
   out_4347742436966495208[179] = 0.0;
   out_4347742436966495208[180] = 0.0;
   out_4347742436966495208[181] = 0.0;
   out_4347742436966495208[182] = 0.0;
   out_4347742436966495208[183] = 0.0;
   out_4347742436966495208[184] = 0.0;
   out_4347742436966495208[185] = 0.0;
   out_4347742436966495208[186] = 0.0;
   out_4347742436966495208[187] = 0.0;
   out_4347742436966495208[188] = 0.0;
   out_4347742436966495208[189] = 0.0;
   out_4347742436966495208[190] = 1.0;
   out_4347742436966495208[191] = 0.0;
   out_4347742436966495208[192] = 0.0;
   out_4347742436966495208[193] = 0.0;
   out_4347742436966495208[194] = 0.0;
   out_4347742436966495208[195] = 0.0;
   out_4347742436966495208[196] = 0.0;
   out_4347742436966495208[197] = 0.0;
   out_4347742436966495208[198] = 0.0;
   out_4347742436966495208[199] = 0.0;
   out_4347742436966495208[200] = 0.0;
   out_4347742436966495208[201] = 0.0;
   out_4347742436966495208[202] = 0.0;
   out_4347742436966495208[203] = 0.0;
   out_4347742436966495208[204] = 0.0;
   out_4347742436966495208[205] = 0.0;
   out_4347742436966495208[206] = 0.0;
   out_4347742436966495208[207] = 0.0;
   out_4347742436966495208[208] = 0.0;
   out_4347742436966495208[209] = 1.0;
   out_4347742436966495208[210] = 0.0;
   out_4347742436966495208[211] = 0.0;
   out_4347742436966495208[212] = 0.0;
   out_4347742436966495208[213] = 0.0;
   out_4347742436966495208[214] = 0.0;
   out_4347742436966495208[215] = 0.0;
   out_4347742436966495208[216] = 0.0;
   out_4347742436966495208[217] = 0.0;
   out_4347742436966495208[218] = 0.0;
   out_4347742436966495208[219] = 0.0;
   out_4347742436966495208[220] = 0.0;
   out_4347742436966495208[221] = 0.0;
   out_4347742436966495208[222] = 0.0;
   out_4347742436966495208[223] = 0.0;
   out_4347742436966495208[224] = 0.0;
   out_4347742436966495208[225] = 0.0;
   out_4347742436966495208[226] = 0.0;
   out_4347742436966495208[227] = 0.0;
   out_4347742436966495208[228] = 1.0;
   out_4347742436966495208[229] = 0.0;
   out_4347742436966495208[230] = 0.0;
   out_4347742436966495208[231] = 0.0;
   out_4347742436966495208[232] = 0.0;
   out_4347742436966495208[233] = 0.0;
   out_4347742436966495208[234] = 0.0;
   out_4347742436966495208[235] = 0.0;
   out_4347742436966495208[236] = 0.0;
   out_4347742436966495208[237] = 0.0;
   out_4347742436966495208[238] = 0.0;
   out_4347742436966495208[239] = 0.0;
   out_4347742436966495208[240] = 0.0;
   out_4347742436966495208[241] = 0.0;
   out_4347742436966495208[242] = 0.0;
   out_4347742436966495208[243] = 0.0;
   out_4347742436966495208[244] = 0.0;
   out_4347742436966495208[245] = 0.0;
   out_4347742436966495208[246] = 0.0;
   out_4347742436966495208[247] = 1.0;
   out_4347742436966495208[248] = 0.0;
   out_4347742436966495208[249] = 0.0;
   out_4347742436966495208[250] = 0.0;
   out_4347742436966495208[251] = 0.0;
   out_4347742436966495208[252] = 0.0;
   out_4347742436966495208[253] = 0.0;
   out_4347742436966495208[254] = 0.0;
   out_4347742436966495208[255] = 0.0;
   out_4347742436966495208[256] = 0.0;
   out_4347742436966495208[257] = 0.0;
   out_4347742436966495208[258] = 0.0;
   out_4347742436966495208[259] = 0.0;
   out_4347742436966495208[260] = 0.0;
   out_4347742436966495208[261] = 0.0;
   out_4347742436966495208[262] = 0.0;
   out_4347742436966495208[263] = 0.0;
   out_4347742436966495208[264] = 0.0;
   out_4347742436966495208[265] = 0.0;
   out_4347742436966495208[266] = 1.0;
   out_4347742436966495208[267] = 0.0;
   out_4347742436966495208[268] = 0.0;
   out_4347742436966495208[269] = 0.0;
   out_4347742436966495208[270] = 0.0;
   out_4347742436966495208[271] = 0.0;
   out_4347742436966495208[272] = 0.0;
   out_4347742436966495208[273] = 0.0;
   out_4347742436966495208[274] = 0.0;
   out_4347742436966495208[275] = 0.0;
   out_4347742436966495208[276] = 0.0;
   out_4347742436966495208[277] = 0.0;
   out_4347742436966495208[278] = 0.0;
   out_4347742436966495208[279] = 0.0;
   out_4347742436966495208[280] = 0.0;
   out_4347742436966495208[281] = 0.0;
   out_4347742436966495208[282] = 0.0;
   out_4347742436966495208[283] = 0.0;
   out_4347742436966495208[284] = 0.0;
   out_4347742436966495208[285] = 1.0;
   out_4347742436966495208[286] = 0.0;
   out_4347742436966495208[287] = 0.0;
   out_4347742436966495208[288] = 0.0;
   out_4347742436966495208[289] = 0.0;
   out_4347742436966495208[290] = 0.0;
   out_4347742436966495208[291] = 0.0;
   out_4347742436966495208[292] = 0.0;
   out_4347742436966495208[293] = 0.0;
   out_4347742436966495208[294] = 0.0;
   out_4347742436966495208[295] = 0.0;
   out_4347742436966495208[296] = 0.0;
   out_4347742436966495208[297] = 0.0;
   out_4347742436966495208[298] = 0.0;
   out_4347742436966495208[299] = 0.0;
   out_4347742436966495208[300] = 0.0;
   out_4347742436966495208[301] = 0.0;
   out_4347742436966495208[302] = 0.0;
   out_4347742436966495208[303] = 0.0;
   out_4347742436966495208[304] = 1.0;
   out_4347742436966495208[305] = 0.0;
   out_4347742436966495208[306] = 0.0;
   out_4347742436966495208[307] = 0.0;
   out_4347742436966495208[308] = 0.0;
   out_4347742436966495208[309] = 0.0;
   out_4347742436966495208[310] = 0.0;
   out_4347742436966495208[311] = 0.0;
   out_4347742436966495208[312] = 0.0;
   out_4347742436966495208[313] = 0.0;
   out_4347742436966495208[314] = 0.0;
   out_4347742436966495208[315] = 0.0;
   out_4347742436966495208[316] = 0.0;
   out_4347742436966495208[317] = 0.0;
   out_4347742436966495208[318] = 0.0;
   out_4347742436966495208[319] = 0.0;
   out_4347742436966495208[320] = 0.0;
   out_4347742436966495208[321] = 0.0;
   out_4347742436966495208[322] = 0.0;
   out_4347742436966495208[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4741478081702887425) {
   out_4741478081702887425[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4741478081702887425[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4741478081702887425[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4741478081702887425[3] = dt*state[12] + state[3];
   out_4741478081702887425[4] = dt*state[13] + state[4];
   out_4741478081702887425[5] = dt*state[14] + state[5];
   out_4741478081702887425[6] = state[6];
   out_4741478081702887425[7] = state[7];
   out_4741478081702887425[8] = state[8];
   out_4741478081702887425[9] = state[9];
   out_4741478081702887425[10] = state[10];
   out_4741478081702887425[11] = state[11];
   out_4741478081702887425[12] = state[12];
   out_4741478081702887425[13] = state[13];
   out_4741478081702887425[14] = state[14];
   out_4741478081702887425[15] = state[15];
   out_4741478081702887425[16] = state[16];
   out_4741478081702887425[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2534421229889867694) {
   out_2534421229889867694[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2534421229889867694[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2534421229889867694[2] = 0;
   out_2534421229889867694[3] = 0;
   out_2534421229889867694[4] = 0;
   out_2534421229889867694[5] = 0;
   out_2534421229889867694[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2534421229889867694[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2534421229889867694[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2534421229889867694[9] = 0;
   out_2534421229889867694[10] = 0;
   out_2534421229889867694[11] = 0;
   out_2534421229889867694[12] = 0;
   out_2534421229889867694[13] = 0;
   out_2534421229889867694[14] = 0;
   out_2534421229889867694[15] = 0;
   out_2534421229889867694[16] = 0;
   out_2534421229889867694[17] = 0;
   out_2534421229889867694[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2534421229889867694[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2534421229889867694[20] = 0;
   out_2534421229889867694[21] = 0;
   out_2534421229889867694[22] = 0;
   out_2534421229889867694[23] = 0;
   out_2534421229889867694[24] = 0;
   out_2534421229889867694[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2534421229889867694[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2534421229889867694[27] = 0;
   out_2534421229889867694[28] = 0;
   out_2534421229889867694[29] = 0;
   out_2534421229889867694[30] = 0;
   out_2534421229889867694[31] = 0;
   out_2534421229889867694[32] = 0;
   out_2534421229889867694[33] = 0;
   out_2534421229889867694[34] = 0;
   out_2534421229889867694[35] = 0;
   out_2534421229889867694[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2534421229889867694[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2534421229889867694[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2534421229889867694[39] = 0;
   out_2534421229889867694[40] = 0;
   out_2534421229889867694[41] = 0;
   out_2534421229889867694[42] = 0;
   out_2534421229889867694[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2534421229889867694[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2534421229889867694[45] = 0;
   out_2534421229889867694[46] = 0;
   out_2534421229889867694[47] = 0;
   out_2534421229889867694[48] = 0;
   out_2534421229889867694[49] = 0;
   out_2534421229889867694[50] = 0;
   out_2534421229889867694[51] = 0;
   out_2534421229889867694[52] = 0;
   out_2534421229889867694[53] = 0;
   out_2534421229889867694[54] = 0;
   out_2534421229889867694[55] = 0;
   out_2534421229889867694[56] = 0;
   out_2534421229889867694[57] = 1;
   out_2534421229889867694[58] = 0;
   out_2534421229889867694[59] = 0;
   out_2534421229889867694[60] = 0;
   out_2534421229889867694[61] = 0;
   out_2534421229889867694[62] = 0;
   out_2534421229889867694[63] = 0;
   out_2534421229889867694[64] = 0;
   out_2534421229889867694[65] = 0;
   out_2534421229889867694[66] = dt;
   out_2534421229889867694[67] = 0;
   out_2534421229889867694[68] = 0;
   out_2534421229889867694[69] = 0;
   out_2534421229889867694[70] = 0;
   out_2534421229889867694[71] = 0;
   out_2534421229889867694[72] = 0;
   out_2534421229889867694[73] = 0;
   out_2534421229889867694[74] = 0;
   out_2534421229889867694[75] = 0;
   out_2534421229889867694[76] = 1;
   out_2534421229889867694[77] = 0;
   out_2534421229889867694[78] = 0;
   out_2534421229889867694[79] = 0;
   out_2534421229889867694[80] = 0;
   out_2534421229889867694[81] = 0;
   out_2534421229889867694[82] = 0;
   out_2534421229889867694[83] = 0;
   out_2534421229889867694[84] = 0;
   out_2534421229889867694[85] = dt;
   out_2534421229889867694[86] = 0;
   out_2534421229889867694[87] = 0;
   out_2534421229889867694[88] = 0;
   out_2534421229889867694[89] = 0;
   out_2534421229889867694[90] = 0;
   out_2534421229889867694[91] = 0;
   out_2534421229889867694[92] = 0;
   out_2534421229889867694[93] = 0;
   out_2534421229889867694[94] = 0;
   out_2534421229889867694[95] = 1;
   out_2534421229889867694[96] = 0;
   out_2534421229889867694[97] = 0;
   out_2534421229889867694[98] = 0;
   out_2534421229889867694[99] = 0;
   out_2534421229889867694[100] = 0;
   out_2534421229889867694[101] = 0;
   out_2534421229889867694[102] = 0;
   out_2534421229889867694[103] = 0;
   out_2534421229889867694[104] = dt;
   out_2534421229889867694[105] = 0;
   out_2534421229889867694[106] = 0;
   out_2534421229889867694[107] = 0;
   out_2534421229889867694[108] = 0;
   out_2534421229889867694[109] = 0;
   out_2534421229889867694[110] = 0;
   out_2534421229889867694[111] = 0;
   out_2534421229889867694[112] = 0;
   out_2534421229889867694[113] = 0;
   out_2534421229889867694[114] = 1;
   out_2534421229889867694[115] = 0;
   out_2534421229889867694[116] = 0;
   out_2534421229889867694[117] = 0;
   out_2534421229889867694[118] = 0;
   out_2534421229889867694[119] = 0;
   out_2534421229889867694[120] = 0;
   out_2534421229889867694[121] = 0;
   out_2534421229889867694[122] = 0;
   out_2534421229889867694[123] = 0;
   out_2534421229889867694[124] = 0;
   out_2534421229889867694[125] = 0;
   out_2534421229889867694[126] = 0;
   out_2534421229889867694[127] = 0;
   out_2534421229889867694[128] = 0;
   out_2534421229889867694[129] = 0;
   out_2534421229889867694[130] = 0;
   out_2534421229889867694[131] = 0;
   out_2534421229889867694[132] = 0;
   out_2534421229889867694[133] = 1;
   out_2534421229889867694[134] = 0;
   out_2534421229889867694[135] = 0;
   out_2534421229889867694[136] = 0;
   out_2534421229889867694[137] = 0;
   out_2534421229889867694[138] = 0;
   out_2534421229889867694[139] = 0;
   out_2534421229889867694[140] = 0;
   out_2534421229889867694[141] = 0;
   out_2534421229889867694[142] = 0;
   out_2534421229889867694[143] = 0;
   out_2534421229889867694[144] = 0;
   out_2534421229889867694[145] = 0;
   out_2534421229889867694[146] = 0;
   out_2534421229889867694[147] = 0;
   out_2534421229889867694[148] = 0;
   out_2534421229889867694[149] = 0;
   out_2534421229889867694[150] = 0;
   out_2534421229889867694[151] = 0;
   out_2534421229889867694[152] = 1;
   out_2534421229889867694[153] = 0;
   out_2534421229889867694[154] = 0;
   out_2534421229889867694[155] = 0;
   out_2534421229889867694[156] = 0;
   out_2534421229889867694[157] = 0;
   out_2534421229889867694[158] = 0;
   out_2534421229889867694[159] = 0;
   out_2534421229889867694[160] = 0;
   out_2534421229889867694[161] = 0;
   out_2534421229889867694[162] = 0;
   out_2534421229889867694[163] = 0;
   out_2534421229889867694[164] = 0;
   out_2534421229889867694[165] = 0;
   out_2534421229889867694[166] = 0;
   out_2534421229889867694[167] = 0;
   out_2534421229889867694[168] = 0;
   out_2534421229889867694[169] = 0;
   out_2534421229889867694[170] = 0;
   out_2534421229889867694[171] = 1;
   out_2534421229889867694[172] = 0;
   out_2534421229889867694[173] = 0;
   out_2534421229889867694[174] = 0;
   out_2534421229889867694[175] = 0;
   out_2534421229889867694[176] = 0;
   out_2534421229889867694[177] = 0;
   out_2534421229889867694[178] = 0;
   out_2534421229889867694[179] = 0;
   out_2534421229889867694[180] = 0;
   out_2534421229889867694[181] = 0;
   out_2534421229889867694[182] = 0;
   out_2534421229889867694[183] = 0;
   out_2534421229889867694[184] = 0;
   out_2534421229889867694[185] = 0;
   out_2534421229889867694[186] = 0;
   out_2534421229889867694[187] = 0;
   out_2534421229889867694[188] = 0;
   out_2534421229889867694[189] = 0;
   out_2534421229889867694[190] = 1;
   out_2534421229889867694[191] = 0;
   out_2534421229889867694[192] = 0;
   out_2534421229889867694[193] = 0;
   out_2534421229889867694[194] = 0;
   out_2534421229889867694[195] = 0;
   out_2534421229889867694[196] = 0;
   out_2534421229889867694[197] = 0;
   out_2534421229889867694[198] = 0;
   out_2534421229889867694[199] = 0;
   out_2534421229889867694[200] = 0;
   out_2534421229889867694[201] = 0;
   out_2534421229889867694[202] = 0;
   out_2534421229889867694[203] = 0;
   out_2534421229889867694[204] = 0;
   out_2534421229889867694[205] = 0;
   out_2534421229889867694[206] = 0;
   out_2534421229889867694[207] = 0;
   out_2534421229889867694[208] = 0;
   out_2534421229889867694[209] = 1;
   out_2534421229889867694[210] = 0;
   out_2534421229889867694[211] = 0;
   out_2534421229889867694[212] = 0;
   out_2534421229889867694[213] = 0;
   out_2534421229889867694[214] = 0;
   out_2534421229889867694[215] = 0;
   out_2534421229889867694[216] = 0;
   out_2534421229889867694[217] = 0;
   out_2534421229889867694[218] = 0;
   out_2534421229889867694[219] = 0;
   out_2534421229889867694[220] = 0;
   out_2534421229889867694[221] = 0;
   out_2534421229889867694[222] = 0;
   out_2534421229889867694[223] = 0;
   out_2534421229889867694[224] = 0;
   out_2534421229889867694[225] = 0;
   out_2534421229889867694[226] = 0;
   out_2534421229889867694[227] = 0;
   out_2534421229889867694[228] = 1;
   out_2534421229889867694[229] = 0;
   out_2534421229889867694[230] = 0;
   out_2534421229889867694[231] = 0;
   out_2534421229889867694[232] = 0;
   out_2534421229889867694[233] = 0;
   out_2534421229889867694[234] = 0;
   out_2534421229889867694[235] = 0;
   out_2534421229889867694[236] = 0;
   out_2534421229889867694[237] = 0;
   out_2534421229889867694[238] = 0;
   out_2534421229889867694[239] = 0;
   out_2534421229889867694[240] = 0;
   out_2534421229889867694[241] = 0;
   out_2534421229889867694[242] = 0;
   out_2534421229889867694[243] = 0;
   out_2534421229889867694[244] = 0;
   out_2534421229889867694[245] = 0;
   out_2534421229889867694[246] = 0;
   out_2534421229889867694[247] = 1;
   out_2534421229889867694[248] = 0;
   out_2534421229889867694[249] = 0;
   out_2534421229889867694[250] = 0;
   out_2534421229889867694[251] = 0;
   out_2534421229889867694[252] = 0;
   out_2534421229889867694[253] = 0;
   out_2534421229889867694[254] = 0;
   out_2534421229889867694[255] = 0;
   out_2534421229889867694[256] = 0;
   out_2534421229889867694[257] = 0;
   out_2534421229889867694[258] = 0;
   out_2534421229889867694[259] = 0;
   out_2534421229889867694[260] = 0;
   out_2534421229889867694[261] = 0;
   out_2534421229889867694[262] = 0;
   out_2534421229889867694[263] = 0;
   out_2534421229889867694[264] = 0;
   out_2534421229889867694[265] = 0;
   out_2534421229889867694[266] = 1;
   out_2534421229889867694[267] = 0;
   out_2534421229889867694[268] = 0;
   out_2534421229889867694[269] = 0;
   out_2534421229889867694[270] = 0;
   out_2534421229889867694[271] = 0;
   out_2534421229889867694[272] = 0;
   out_2534421229889867694[273] = 0;
   out_2534421229889867694[274] = 0;
   out_2534421229889867694[275] = 0;
   out_2534421229889867694[276] = 0;
   out_2534421229889867694[277] = 0;
   out_2534421229889867694[278] = 0;
   out_2534421229889867694[279] = 0;
   out_2534421229889867694[280] = 0;
   out_2534421229889867694[281] = 0;
   out_2534421229889867694[282] = 0;
   out_2534421229889867694[283] = 0;
   out_2534421229889867694[284] = 0;
   out_2534421229889867694[285] = 1;
   out_2534421229889867694[286] = 0;
   out_2534421229889867694[287] = 0;
   out_2534421229889867694[288] = 0;
   out_2534421229889867694[289] = 0;
   out_2534421229889867694[290] = 0;
   out_2534421229889867694[291] = 0;
   out_2534421229889867694[292] = 0;
   out_2534421229889867694[293] = 0;
   out_2534421229889867694[294] = 0;
   out_2534421229889867694[295] = 0;
   out_2534421229889867694[296] = 0;
   out_2534421229889867694[297] = 0;
   out_2534421229889867694[298] = 0;
   out_2534421229889867694[299] = 0;
   out_2534421229889867694[300] = 0;
   out_2534421229889867694[301] = 0;
   out_2534421229889867694[302] = 0;
   out_2534421229889867694[303] = 0;
   out_2534421229889867694[304] = 1;
   out_2534421229889867694[305] = 0;
   out_2534421229889867694[306] = 0;
   out_2534421229889867694[307] = 0;
   out_2534421229889867694[308] = 0;
   out_2534421229889867694[309] = 0;
   out_2534421229889867694[310] = 0;
   out_2534421229889867694[311] = 0;
   out_2534421229889867694[312] = 0;
   out_2534421229889867694[313] = 0;
   out_2534421229889867694[314] = 0;
   out_2534421229889867694[315] = 0;
   out_2534421229889867694[316] = 0;
   out_2534421229889867694[317] = 0;
   out_2534421229889867694[318] = 0;
   out_2534421229889867694[319] = 0;
   out_2534421229889867694[320] = 0;
   out_2534421229889867694[321] = 0;
   out_2534421229889867694[322] = 0;
   out_2534421229889867694[323] = 1;
}
void h_4(double *state, double *unused, double *out_9104738239612597067) {
   out_9104738239612597067[0] = state[6] + state[9];
   out_9104738239612597067[1] = state[7] + state[10];
   out_9104738239612597067[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_804775948072585527) {
   out_804775948072585527[0] = 0;
   out_804775948072585527[1] = 0;
   out_804775948072585527[2] = 0;
   out_804775948072585527[3] = 0;
   out_804775948072585527[4] = 0;
   out_804775948072585527[5] = 0;
   out_804775948072585527[6] = 1;
   out_804775948072585527[7] = 0;
   out_804775948072585527[8] = 0;
   out_804775948072585527[9] = 1;
   out_804775948072585527[10] = 0;
   out_804775948072585527[11] = 0;
   out_804775948072585527[12] = 0;
   out_804775948072585527[13] = 0;
   out_804775948072585527[14] = 0;
   out_804775948072585527[15] = 0;
   out_804775948072585527[16] = 0;
   out_804775948072585527[17] = 0;
   out_804775948072585527[18] = 0;
   out_804775948072585527[19] = 0;
   out_804775948072585527[20] = 0;
   out_804775948072585527[21] = 0;
   out_804775948072585527[22] = 0;
   out_804775948072585527[23] = 0;
   out_804775948072585527[24] = 0;
   out_804775948072585527[25] = 1;
   out_804775948072585527[26] = 0;
   out_804775948072585527[27] = 0;
   out_804775948072585527[28] = 1;
   out_804775948072585527[29] = 0;
   out_804775948072585527[30] = 0;
   out_804775948072585527[31] = 0;
   out_804775948072585527[32] = 0;
   out_804775948072585527[33] = 0;
   out_804775948072585527[34] = 0;
   out_804775948072585527[35] = 0;
   out_804775948072585527[36] = 0;
   out_804775948072585527[37] = 0;
   out_804775948072585527[38] = 0;
   out_804775948072585527[39] = 0;
   out_804775948072585527[40] = 0;
   out_804775948072585527[41] = 0;
   out_804775948072585527[42] = 0;
   out_804775948072585527[43] = 0;
   out_804775948072585527[44] = 1;
   out_804775948072585527[45] = 0;
   out_804775948072585527[46] = 0;
   out_804775948072585527[47] = 1;
   out_804775948072585527[48] = 0;
   out_804775948072585527[49] = 0;
   out_804775948072585527[50] = 0;
   out_804775948072585527[51] = 0;
   out_804775948072585527[52] = 0;
   out_804775948072585527[53] = 0;
}
void h_10(double *state, double *unused, double *out_2185381895971378953) {
   out_2185381895971378953[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2185381895971378953[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2185381895971378953[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5839728363410394932) {
   out_5839728363410394932[0] = 0;
   out_5839728363410394932[1] = 9.8100000000000005*cos(state[1]);
   out_5839728363410394932[2] = 0;
   out_5839728363410394932[3] = 0;
   out_5839728363410394932[4] = -state[8];
   out_5839728363410394932[5] = state[7];
   out_5839728363410394932[6] = 0;
   out_5839728363410394932[7] = state[5];
   out_5839728363410394932[8] = -state[4];
   out_5839728363410394932[9] = 0;
   out_5839728363410394932[10] = 0;
   out_5839728363410394932[11] = 0;
   out_5839728363410394932[12] = 1;
   out_5839728363410394932[13] = 0;
   out_5839728363410394932[14] = 0;
   out_5839728363410394932[15] = 1;
   out_5839728363410394932[16] = 0;
   out_5839728363410394932[17] = 0;
   out_5839728363410394932[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5839728363410394932[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5839728363410394932[20] = 0;
   out_5839728363410394932[21] = state[8];
   out_5839728363410394932[22] = 0;
   out_5839728363410394932[23] = -state[6];
   out_5839728363410394932[24] = -state[5];
   out_5839728363410394932[25] = 0;
   out_5839728363410394932[26] = state[3];
   out_5839728363410394932[27] = 0;
   out_5839728363410394932[28] = 0;
   out_5839728363410394932[29] = 0;
   out_5839728363410394932[30] = 0;
   out_5839728363410394932[31] = 1;
   out_5839728363410394932[32] = 0;
   out_5839728363410394932[33] = 0;
   out_5839728363410394932[34] = 1;
   out_5839728363410394932[35] = 0;
   out_5839728363410394932[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5839728363410394932[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5839728363410394932[38] = 0;
   out_5839728363410394932[39] = -state[7];
   out_5839728363410394932[40] = state[6];
   out_5839728363410394932[41] = 0;
   out_5839728363410394932[42] = state[4];
   out_5839728363410394932[43] = -state[3];
   out_5839728363410394932[44] = 0;
   out_5839728363410394932[45] = 0;
   out_5839728363410394932[46] = 0;
   out_5839728363410394932[47] = 0;
   out_5839728363410394932[48] = 0;
   out_5839728363410394932[49] = 0;
   out_5839728363410394932[50] = 1;
   out_5839728363410394932[51] = 0;
   out_5839728363410394932[52] = 0;
   out_5839728363410394932[53] = 1;
}
void h_13(double *state, double *unused, double *out_2250384613419215699) {
   out_2250384613419215699[0] = state[3];
   out_2250384613419215699[1] = state[4];
   out_2250384613419215699[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4017049773404918328) {
   out_4017049773404918328[0] = 0;
   out_4017049773404918328[1] = 0;
   out_4017049773404918328[2] = 0;
   out_4017049773404918328[3] = 1;
   out_4017049773404918328[4] = 0;
   out_4017049773404918328[5] = 0;
   out_4017049773404918328[6] = 0;
   out_4017049773404918328[7] = 0;
   out_4017049773404918328[8] = 0;
   out_4017049773404918328[9] = 0;
   out_4017049773404918328[10] = 0;
   out_4017049773404918328[11] = 0;
   out_4017049773404918328[12] = 0;
   out_4017049773404918328[13] = 0;
   out_4017049773404918328[14] = 0;
   out_4017049773404918328[15] = 0;
   out_4017049773404918328[16] = 0;
   out_4017049773404918328[17] = 0;
   out_4017049773404918328[18] = 0;
   out_4017049773404918328[19] = 0;
   out_4017049773404918328[20] = 0;
   out_4017049773404918328[21] = 0;
   out_4017049773404918328[22] = 1;
   out_4017049773404918328[23] = 0;
   out_4017049773404918328[24] = 0;
   out_4017049773404918328[25] = 0;
   out_4017049773404918328[26] = 0;
   out_4017049773404918328[27] = 0;
   out_4017049773404918328[28] = 0;
   out_4017049773404918328[29] = 0;
   out_4017049773404918328[30] = 0;
   out_4017049773404918328[31] = 0;
   out_4017049773404918328[32] = 0;
   out_4017049773404918328[33] = 0;
   out_4017049773404918328[34] = 0;
   out_4017049773404918328[35] = 0;
   out_4017049773404918328[36] = 0;
   out_4017049773404918328[37] = 0;
   out_4017049773404918328[38] = 0;
   out_4017049773404918328[39] = 0;
   out_4017049773404918328[40] = 0;
   out_4017049773404918328[41] = 1;
   out_4017049773404918328[42] = 0;
   out_4017049773404918328[43] = 0;
   out_4017049773404918328[44] = 0;
   out_4017049773404918328[45] = 0;
   out_4017049773404918328[46] = 0;
   out_4017049773404918328[47] = 0;
   out_4017049773404918328[48] = 0;
   out_4017049773404918328[49] = 0;
   out_4017049773404918328[50] = 0;
   out_4017049773404918328[51] = 0;
   out_4017049773404918328[52] = 0;
   out_4017049773404918328[53] = 0;
}
void h_14(double *state, double *unused, double *out_3608499155932113812) {
   out_3608499155932113812[0] = state[6];
   out_3608499155932113812[1] = state[7];
   out_3608499155932113812[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2278012484222786769) {
   out_2278012484222786769[0] = 0;
   out_2278012484222786769[1] = 0;
   out_2278012484222786769[2] = 0;
   out_2278012484222786769[3] = 0;
   out_2278012484222786769[4] = 0;
   out_2278012484222786769[5] = 0;
   out_2278012484222786769[6] = 1;
   out_2278012484222786769[7] = 0;
   out_2278012484222786769[8] = 0;
   out_2278012484222786769[9] = 0;
   out_2278012484222786769[10] = 0;
   out_2278012484222786769[11] = 0;
   out_2278012484222786769[12] = 0;
   out_2278012484222786769[13] = 0;
   out_2278012484222786769[14] = 0;
   out_2278012484222786769[15] = 0;
   out_2278012484222786769[16] = 0;
   out_2278012484222786769[17] = 0;
   out_2278012484222786769[18] = 0;
   out_2278012484222786769[19] = 0;
   out_2278012484222786769[20] = 0;
   out_2278012484222786769[21] = 0;
   out_2278012484222786769[22] = 0;
   out_2278012484222786769[23] = 0;
   out_2278012484222786769[24] = 0;
   out_2278012484222786769[25] = 1;
   out_2278012484222786769[26] = 0;
   out_2278012484222786769[27] = 0;
   out_2278012484222786769[28] = 0;
   out_2278012484222786769[29] = 0;
   out_2278012484222786769[30] = 0;
   out_2278012484222786769[31] = 0;
   out_2278012484222786769[32] = 0;
   out_2278012484222786769[33] = 0;
   out_2278012484222786769[34] = 0;
   out_2278012484222786769[35] = 0;
   out_2278012484222786769[36] = 0;
   out_2278012484222786769[37] = 0;
   out_2278012484222786769[38] = 0;
   out_2278012484222786769[39] = 0;
   out_2278012484222786769[40] = 0;
   out_2278012484222786769[41] = 0;
   out_2278012484222786769[42] = 0;
   out_2278012484222786769[43] = 0;
   out_2278012484222786769[44] = 1;
   out_2278012484222786769[45] = 0;
   out_2278012484222786769[46] = 0;
   out_2278012484222786769[47] = 0;
   out_2278012484222786769[48] = 0;
   out_2278012484222786769[49] = 0;
   out_2278012484222786769[50] = 0;
   out_2278012484222786769[51] = 0;
   out_2278012484222786769[52] = 0;
   out_2278012484222786769[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_5715232905817063541) {
  err_fun(nom_x, delta_x, out_5715232905817063541);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5652160587936785451) {
  inv_err_fun(nom_x, true_x, out_5652160587936785451);
}
void pose_H_mod_fun(double *state, double *out_4347742436966495208) {
  H_mod_fun(state, out_4347742436966495208);
}
void pose_f_fun(double *state, double dt, double *out_4741478081702887425) {
  f_fun(state,  dt, out_4741478081702887425);
}
void pose_F_fun(double *state, double dt, double *out_2534421229889867694) {
  F_fun(state,  dt, out_2534421229889867694);
}
void pose_h_4(double *state, double *unused, double *out_9104738239612597067) {
  h_4(state, unused, out_9104738239612597067);
}
void pose_H_4(double *state, double *unused, double *out_804775948072585527) {
  H_4(state, unused, out_804775948072585527);
}
void pose_h_10(double *state, double *unused, double *out_2185381895971378953) {
  h_10(state, unused, out_2185381895971378953);
}
void pose_H_10(double *state, double *unused, double *out_5839728363410394932) {
  H_10(state, unused, out_5839728363410394932);
}
void pose_h_13(double *state, double *unused, double *out_2250384613419215699) {
  h_13(state, unused, out_2250384613419215699);
}
void pose_H_13(double *state, double *unused, double *out_4017049773404918328) {
  H_13(state, unused, out_4017049773404918328);
}
void pose_h_14(double *state, double *unused, double *out_3608499155932113812) {
  h_14(state, unused, out_3608499155932113812);
}
void pose_H_14(double *state, double *unused, double *out_2278012484222786769) {
  H_14(state, unused, out_2278012484222786769);
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
