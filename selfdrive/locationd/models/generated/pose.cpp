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
void err_fun(double *nom_x, double *delta_x, double *out_6009088715125097596) {
   out_6009088715125097596[0] = delta_x[0] + nom_x[0];
   out_6009088715125097596[1] = delta_x[1] + nom_x[1];
   out_6009088715125097596[2] = delta_x[2] + nom_x[2];
   out_6009088715125097596[3] = delta_x[3] + nom_x[3];
   out_6009088715125097596[4] = delta_x[4] + nom_x[4];
   out_6009088715125097596[5] = delta_x[5] + nom_x[5];
   out_6009088715125097596[6] = delta_x[6] + nom_x[6];
   out_6009088715125097596[7] = delta_x[7] + nom_x[7];
   out_6009088715125097596[8] = delta_x[8] + nom_x[8];
   out_6009088715125097596[9] = delta_x[9] + nom_x[9];
   out_6009088715125097596[10] = delta_x[10] + nom_x[10];
   out_6009088715125097596[11] = delta_x[11] + nom_x[11];
   out_6009088715125097596[12] = delta_x[12] + nom_x[12];
   out_6009088715125097596[13] = delta_x[13] + nom_x[13];
   out_6009088715125097596[14] = delta_x[14] + nom_x[14];
   out_6009088715125097596[15] = delta_x[15] + nom_x[15];
   out_6009088715125097596[16] = delta_x[16] + nom_x[16];
   out_6009088715125097596[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5460684038605246490) {
   out_5460684038605246490[0] = -nom_x[0] + true_x[0];
   out_5460684038605246490[1] = -nom_x[1] + true_x[1];
   out_5460684038605246490[2] = -nom_x[2] + true_x[2];
   out_5460684038605246490[3] = -nom_x[3] + true_x[3];
   out_5460684038605246490[4] = -nom_x[4] + true_x[4];
   out_5460684038605246490[5] = -nom_x[5] + true_x[5];
   out_5460684038605246490[6] = -nom_x[6] + true_x[6];
   out_5460684038605246490[7] = -nom_x[7] + true_x[7];
   out_5460684038605246490[8] = -nom_x[8] + true_x[8];
   out_5460684038605246490[9] = -nom_x[9] + true_x[9];
   out_5460684038605246490[10] = -nom_x[10] + true_x[10];
   out_5460684038605246490[11] = -nom_x[11] + true_x[11];
   out_5460684038605246490[12] = -nom_x[12] + true_x[12];
   out_5460684038605246490[13] = -nom_x[13] + true_x[13];
   out_5460684038605246490[14] = -nom_x[14] + true_x[14];
   out_5460684038605246490[15] = -nom_x[15] + true_x[15];
   out_5460684038605246490[16] = -nom_x[16] + true_x[16];
   out_5460684038605246490[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_2180245129448668184) {
   out_2180245129448668184[0] = 1.0;
   out_2180245129448668184[1] = 0.0;
   out_2180245129448668184[2] = 0.0;
   out_2180245129448668184[3] = 0.0;
   out_2180245129448668184[4] = 0.0;
   out_2180245129448668184[5] = 0.0;
   out_2180245129448668184[6] = 0.0;
   out_2180245129448668184[7] = 0.0;
   out_2180245129448668184[8] = 0.0;
   out_2180245129448668184[9] = 0.0;
   out_2180245129448668184[10] = 0.0;
   out_2180245129448668184[11] = 0.0;
   out_2180245129448668184[12] = 0.0;
   out_2180245129448668184[13] = 0.0;
   out_2180245129448668184[14] = 0.0;
   out_2180245129448668184[15] = 0.0;
   out_2180245129448668184[16] = 0.0;
   out_2180245129448668184[17] = 0.0;
   out_2180245129448668184[18] = 0.0;
   out_2180245129448668184[19] = 1.0;
   out_2180245129448668184[20] = 0.0;
   out_2180245129448668184[21] = 0.0;
   out_2180245129448668184[22] = 0.0;
   out_2180245129448668184[23] = 0.0;
   out_2180245129448668184[24] = 0.0;
   out_2180245129448668184[25] = 0.0;
   out_2180245129448668184[26] = 0.0;
   out_2180245129448668184[27] = 0.0;
   out_2180245129448668184[28] = 0.0;
   out_2180245129448668184[29] = 0.0;
   out_2180245129448668184[30] = 0.0;
   out_2180245129448668184[31] = 0.0;
   out_2180245129448668184[32] = 0.0;
   out_2180245129448668184[33] = 0.0;
   out_2180245129448668184[34] = 0.0;
   out_2180245129448668184[35] = 0.0;
   out_2180245129448668184[36] = 0.0;
   out_2180245129448668184[37] = 0.0;
   out_2180245129448668184[38] = 1.0;
   out_2180245129448668184[39] = 0.0;
   out_2180245129448668184[40] = 0.0;
   out_2180245129448668184[41] = 0.0;
   out_2180245129448668184[42] = 0.0;
   out_2180245129448668184[43] = 0.0;
   out_2180245129448668184[44] = 0.0;
   out_2180245129448668184[45] = 0.0;
   out_2180245129448668184[46] = 0.0;
   out_2180245129448668184[47] = 0.0;
   out_2180245129448668184[48] = 0.0;
   out_2180245129448668184[49] = 0.0;
   out_2180245129448668184[50] = 0.0;
   out_2180245129448668184[51] = 0.0;
   out_2180245129448668184[52] = 0.0;
   out_2180245129448668184[53] = 0.0;
   out_2180245129448668184[54] = 0.0;
   out_2180245129448668184[55] = 0.0;
   out_2180245129448668184[56] = 0.0;
   out_2180245129448668184[57] = 1.0;
   out_2180245129448668184[58] = 0.0;
   out_2180245129448668184[59] = 0.0;
   out_2180245129448668184[60] = 0.0;
   out_2180245129448668184[61] = 0.0;
   out_2180245129448668184[62] = 0.0;
   out_2180245129448668184[63] = 0.0;
   out_2180245129448668184[64] = 0.0;
   out_2180245129448668184[65] = 0.0;
   out_2180245129448668184[66] = 0.0;
   out_2180245129448668184[67] = 0.0;
   out_2180245129448668184[68] = 0.0;
   out_2180245129448668184[69] = 0.0;
   out_2180245129448668184[70] = 0.0;
   out_2180245129448668184[71] = 0.0;
   out_2180245129448668184[72] = 0.0;
   out_2180245129448668184[73] = 0.0;
   out_2180245129448668184[74] = 0.0;
   out_2180245129448668184[75] = 0.0;
   out_2180245129448668184[76] = 1.0;
   out_2180245129448668184[77] = 0.0;
   out_2180245129448668184[78] = 0.0;
   out_2180245129448668184[79] = 0.0;
   out_2180245129448668184[80] = 0.0;
   out_2180245129448668184[81] = 0.0;
   out_2180245129448668184[82] = 0.0;
   out_2180245129448668184[83] = 0.0;
   out_2180245129448668184[84] = 0.0;
   out_2180245129448668184[85] = 0.0;
   out_2180245129448668184[86] = 0.0;
   out_2180245129448668184[87] = 0.0;
   out_2180245129448668184[88] = 0.0;
   out_2180245129448668184[89] = 0.0;
   out_2180245129448668184[90] = 0.0;
   out_2180245129448668184[91] = 0.0;
   out_2180245129448668184[92] = 0.0;
   out_2180245129448668184[93] = 0.0;
   out_2180245129448668184[94] = 0.0;
   out_2180245129448668184[95] = 1.0;
   out_2180245129448668184[96] = 0.0;
   out_2180245129448668184[97] = 0.0;
   out_2180245129448668184[98] = 0.0;
   out_2180245129448668184[99] = 0.0;
   out_2180245129448668184[100] = 0.0;
   out_2180245129448668184[101] = 0.0;
   out_2180245129448668184[102] = 0.0;
   out_2180245129448668184[103] = 0.0;
   out_2180245129448668184[104] = 0.0;
   out_2180245129448668184[105] = 0.0;
   out_2180245129448668184[106] = 0.0;
   out_2180245129448668184[107] = 0.0;
   out_2180245129448668184[108] = 0.0;
   out_2180245129448668184[109] = 0.0;
   out_2180245129448668184[110] = 0.0;
   out_2180245129448668184[111] = 0.0;
   out_2180245129448668184[112] = 0.0;
   out_2180245129448668184[113] = 0.0;
   out_2180245129448668184[114] = 1.0;
   out_2180245129448668184[115] = 0.0;
   out_2180245129448668184[116] = 0.0;
   out_2180245129448668184[117] = 0.0;
   out_2180245129448668184[118] = 0.0;
   out_2180245129448668184[119] = 0.0;
   out_2180245129448668184[120] = 0.0;
   out_2180245129448668184[121] = 0.0;
   out_2180245129448668184[122] = 0.0;
   out_2180245129448668184[123] = 0.0;
   out_2180245129448668184[124] = 0.0;
   out_2180245129448668184[125] = 0.0;
   out_2180245129448668184[126] = 0.0;
   out_2180245129448668184[127] = 0.0;
   out_2180245129448668184[128] = 0.0;
   out_2180245129448668184[129] = 0.0;
   out_2180245129448668184[130] = 0.0;
   out_2180245129448668184[131] = 0.0;
   out_2180245129448668184[132] = 0.0;
   out_2180245129448668184[133] = 1.0;
   out_2180245129448668184[134] = 0.0;
   out_2180245129448668184[135] = 0.0;
   out_2180245129448668184[136] = 0.0;
   out_2180245129448668184[137] = 0.0;
   out_2180245129448668184[138] = 0.0;
   out_2180245129448668184[139] = 0.0;
   out_2180245129448668184[140] = 0.0;
   out_2180245129448668184[141] = 0.0;
   out_2180245129448668184[142] = 0.0;
   out_2180245129448668184[143] = 0.0;
   out_2180245129448668184[144] = 0.0;
   out_2180245129448668184[145] = 0.0;
   out_2180245129448668184[146] = 0.0;
   out_2180245129448668184[147] = 0.0;
   out_2180245129448668184[148] = 0.0;
   out_2180245129448668184[149] = 0.0;
   out_2180245129448668184[150] = 0.0;
   out_2180245129448668184[151] = 0.0;
   out_2180245129448668184[152] = 1.0;
   out_2180245129448668184[153] = 0.0;
   out_2180245129448668184[154] = 0.0;
   out_2180245129448668184[155] = 0.0;
   out_2180245129448668184[156] = 0.0;
   out_2180245129448668184[157] = 0.0;
   out_2180245129448668184[158] = 0.0;
   out_2180245129448668184[159] = 0.0;
   out_2180245129448668184[160] = 0.0;
   out_2180245129448668184[161] = 0.0;
   out_2180245129448668184[162] = 0.0;
   out_2180245129448668184[163] = 0.0;
   out_2180245129448668184[164] = 0.0;
   out_2180245129448668184[165] = 0.0;
   out_2180245129448668184[166] = 0.0;
   out_2180245129448668184[167] = 0.0;
   out_2180245129448668184[168] = 0.0;
   out_2180245129448668184[169] = 0.0;
   out_2180245129448668184[170] = 0.0;
   out_2180245129448668184[171] = 1.0;
   out_2180245129448668184[172] = 0.0;
   out_2180245129448668184[173] = 0.0;
   out_2180245129448668184[174] = 0.0;
   out_2180245129448668184[175] = 0.0;
   out_2180245129448668184[176] = 0.0;
   out_2180245129448668184[177] = 0.0;
   out_2180245129448668184[178] = 0.0;
   out_2180245129448668184[179] = 0.0;
   out_2180245129448668184[180] = 0.0;
   out_2180245129448668184[181] = 0.0;
   out_2180245129448668184[182] = 0.0;
   out_2180245129448668184[183] = 0.0;
   out_2180245129448668184[184] = 0.0;
   out_2180245129448668184[185] = 0.0;
   out_2180245129448668184[186] = 0.0;
   out_2180245129448668184[187] = 0.0;
   out_2180245129448668184[188] = 0.0;
   out_2180245129448668184[189] = 0.0;
   out_2180245129448668184[190] = 1.0;
   out_2180245129448668184[191] = 0.0;
   out_2180245129448668184[192] = 0.0;
   out_2180245129448668184[193] = 0.0;
   out_2180245129448668184[194] = 0.0;
   out_2180245129448668184[195] = 0.0;
   out_2180245129448668184[196] = 0.0;
   out_2180245129448668184[197] = 0.0;
   out_2180245129448668184[198] = 0.0;
   out_2180245129448668184[199] = 0.0;
   out_2180245129448668184[200] = 0.0;
   out_2180245129448668184[201] = 0.0;
   out_2180245129448668184[202] = 0.0;
   out_2180245129448668184[203] = 0.0;
   out_2180245129448668184[204] = 0.0;
   out_2180245129448668184[205] = 0.0;
   out_2180245129448668184[206] = 0.0;
   out_2180245129448668184[207] = 0.0;
   out_2180245129448668184[208] = 0.0;
   out_2180245129448668184[209] = 1.0;
   out_2180245129448668184[210] = 0.0;
   out_2180245129448668184[211] = 0.0;
   out_2180245129448668184[212] = 0.0;
   out_2180245129448668184[213] = 0.0;
   out_2180245129448668184[214] = 0.0;
   out_2180245129448668184[215] = 0.0;
   out_2180245129448668184[216] = 0.0;
   out_2180245129448668184[217] = 0.0;
   out_2180245129448668184[218] = 0.0;
   out_2180245129448668184[219] = 0.0;
   out_2180245129448668184[220] = 0.0;
   out_2180245129448668184[221] = 0.0;
   out_2180245129448668184[222] = 0.0;
   out_2180245129448668184[223] = 0.0;
   out_2180245129448668184[224] = 0.0;
   out_2180245129448668184[225] = 0.0;
   out_2180245129448668184[226] = 0.0;
   out_2180245129448668184[227] = 0.0;
   out_2180245129448668184[228] = 1.0;
   out_2180245129448668184[229] = 0.0;
   out_2180245129448668184[230] = 0.0;
   out_2180245129448668184[231] = 0.0;
   out_2180245129448668184[232] = 0.0;
   out_2180245129448668184[233] = 0.0;
   out_2180245129448668184[234] = 0.0;
   out_2180245129448668184[235] = 0.0;
   out_2180245129448668184[236] = 0.0;
   out_2180245129448668184[237] = 0.0;
   out_2180245129448668184[238] = 0.0;
   out_2180245129448668184[239] = 0.0;
   out_2180245129448668184[240] = 0.0;
   out_2180245129448668184[241] = 0.0;
   out_2180245129448668184[242] = 0.0;
   out_2180245129448668184[243] = 0.0;
   out_2180245129448668184[244] = 0.0;
   out_2180245129448668184[245] = 0.0;
   out_2180245129448668184[246] = 0.0;
   out_2180245129448668184[247] = 1.0;
   out_2180245129448668184[248] = 0.0;
   out_2180245129448668184[249] = 0.0;
   out_2180245129448668184[250] = 0.0;
   out_2180245129448668184[251] = 0.0;
   out_2180245129448668184[252] = 0.0;
   out_2180245129448668184[253] = 0.0;
   out_2180245129448668184[254] = 0.0;
   out_2180245129448668184[255] = 0.0;
   out_2180245129448668184[256] = 0.0;
   out_2180245129448668184[257] = 0.0;
   out_2180245129448668184[258] = 0.0;
   out_2180245129448668184[259] = 0.0;
   out_2180245129448668184[260] = 0.0;
   out_2180245129448668184[261] = 0.0;
   out_2180245129448668184[262] = 0.0;
   out_2180245129448668184[263] = 0.0;
   out_2180245129448668184[264] = 0.0;
   out_2180245129448668184[265] = 0.0;
   out_2180245129448668184[266] = 1.0;
   out_2180245129448668184[267] = 0.0;
   out_2180245129448668184[268] = 0.0;
   out_2180245129448668184[269] = 0.0;
   out_2180245129448668184[270] = 0.0;
   out_2180245129448668184[271] = 0.0;
   out_2180245129448668184[272] = 0.0;
   out_2180245129448668184[273] = 0.0;
   out_2180245129448668184[274] = 0.0;
   out_2180245129448668184[275] = 0.0;
   out_2180245129448668184[276] = 0.0;
   out_2180245129448668184[277] = 0.0;
   out_2180245129448668184[278] = 0.0;
   out_2180245129448668184[279] = 0.0;
   out_2180245129448668184[280] = 0.0;
   out_2180245129448668184[281] = 0.0;
   out_2180245129448668184[282] = 0.0;
   out_2180245129448668184[283] = 0.0;
   out_2180245129448668184[284] = 0.0;
   out_2180245129448668184[285] = 1.0;
   out_2180245129448668184[286] = 0.0;
   out_2180245129448668184[287] = 0.0;
   out_2180245129448668184[288] = 0.0;
   out_2180245129448668184[289] = 0.0;
   out_2180245129448668184[290] = 0.0;
   out_2180245129448668184[291] = 0.0;
   out_2180245129448668184[292] = 0.0;
   out_2180245129448668184[293] = 0.0;
   out_2180245129448668184[294] = 0.0;
   out_2180245129448668184[295] = 0.0;
   out_2180245129448668184[296] = 0.0;
   out_2180245129448668184[297] = 0.0;
   out_2180245129448668184[298] = 0.0;
   out_2180245129448668184[299] = 0.0;
   out_2180245129448668184[300] = 0.0;
   out_2180245129448668184[301] = 0.0;
   out_2180245129448668184[302] = 0.0;
   out_2180245129448668184[303] = 0.0;
   out_2180245129448668184[304] = 1.0;
   out_2180245129448668184[305] = 0.0;
   out_2180245129448668184[306] = 0.0;
   out_2180245129448668184[307] = 0.0;
   out_2180245129448668184[308] = 0.0;
   out_2180245129448668184[309] = 0.0;
   out_2180245129448668184[310] = 0.0;
   out_2180245129448668184[311] = 0.0;
   out_2180245129448668184[312] = 0.0;
   out_2180245129448668184[313] = 0.0;
   out_2180245129448668184[314] = 0.0;
   out_2180245129448668184[315] = 0.0;
   out_2180245129448668184[316] = 0.0;
   out_2180245129448668184[317] = 0.0;
   out_2180245129448668184[318] = 0.0;
   out_2180245129448668184[319] = 0.0;
   out_2180245129448668184[320] = 0.0;
   out_2180245129448668184[321] = 0.0;
   out_2180245129448668184[322] = 0.0;
   out_2180245129448668184[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1359935913624561504) {
   out_1359935913624561504[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1359935913624561504[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1359935913624561504[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1359935913624561504[3] = dt*state[12] + state[3];
   out_1359935913624561504[4] = dt*state[13] + state[4];
   out_1359935913624561504[5] = dt*state[14] + state[5];
   out_1359935913624561504[6] = state[6];
   out_1359935913624561504[7] = state[7];
   out_1359935913624561504[8] = state[8];
   out_1359935913624561504[9] = state[9];
   out_1359935913624561504[10] = state[10];
   out_1359935913624561504[11] = state[11];
   out_1359935913624561504[12] = state[12];
   out_1359935913624561504[13] = state[13];
   out_1359935913624561504[14] = state[14];
   out_1359935913624561504[15] = state[15];
   out_1359935913624561504[16] = state[16];
   out_1359935913624561504[17] = state[17];
}
void F_fun(double *state, double dt, double *out_3401373591342797666) {
   out_3401373591342797666[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3401373591342797666[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3401373591342797666[2] = 0;
   out_3401373591342797666[3] = 0;
   out_3401373591342797666[4] = 0;
   out_3401373591342797666[5] = 0;
   out_3401373591342797666[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3401373591342797666[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3401373591342797666[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3401373591342797666[9] = 0;
   out_3401373591342797666[10] = 0;
   out_3401373591342797666[11] = 0;
   out_3401373591342797666[12] = 0;
   out_3401373591342797666[13] = 0;
   out_3401373591342797666[14] = 0;
   out_3401373591342797666[15] = 0;
   out_3401373591342797666[16] = 0;
   out_3401373591342797666[17] = 0;
   out_3401373591342797666[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3401373591342797666[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3401373591342797666[20] = 0;
   out_3401373591342797666[21] = 0;
   out_3401373591342797666[22] = 0;
   out_3401373591342797666[23] = 0;
   out_3401373591342797666[24] = 0;
   out_3401373591342797666[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3401373591342797666[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3401373591342797666[27] = 0;
   out_3401373591342797666[28] = 0;
   out_3401373591342797666[29] = 0;
   out_3401373591342797666[30] = 0;
   out_3401373591342797666[31] = 0;
   out_3401373591342797666[32] = 0;
   out_3401373591342797666[33] = 0;
   out_3401373591342797666[34] = 0;
   out_3401373591342797666[35] = 0;
   out_3401373591342797666[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3401373591342797666[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3401373591342797666[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3401373591342797666[39] = 0;
   out_3401373591342797666[40] = 0;
   out_3401373591342797666[41] = 0;
   out_3401373591342797666[42] = 0;
   out_3401373591342797666[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3401373591342797666[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3401373591342797666[45] = 0;
   out_3401373591342797666[46] = 0;
   out_3401373591342797666[47] = 0;
   out_3401373591342797666[48] = 0;
   out_3401373591342797666[49] = 0;
   out_3401373591342797666[50] = 0;
   out_3401373591342797666[51] = 0;
   out_3401373591342797666[52] = 0;
   out_3401373591342797666[53] = 0;
   out_3401373591342797666[54] = 0;
   out_3401373591342797666[55] = 0;
   out_3401373591342797666[56] = 0;
   out_3401373591342797666[57] = 1;
   out_3401373591342797666[58] = 0;
   out_3401373591342797666[59] = 0;
   out_3401373591342797666[60] = 0;
   out_3401373591342797666[61] = 0;
   out_3401373591342797666[62] = 0;
   out_3401373591342797666[63] = 0;
   out_3401373591342797666[64] = 0;
   out_3401373591342797666[65] = 0;
   out_3401373591342797666[66] = dt;
   out_3401373591342797666[67] = 0;
   out_3401373591342797666[68] = 0;
   out_3401373591342797666[69] = 0;
   out_3401373591342797666[70] = 0;
   out_3401373591342797666[71] = 0;
   out_3401373591342797666[72] = 0;
   out_3401373591342797666[73] = 0;
   out_3401373591342797666[74] = 0;
   out_3401373591342797666[75] = 0;
   out_3401373591342797666[76] = 1;
   out_3401373591342797666[77] = 0;
   out_3401373591342797666[78] = 0;
   out_3401373591342797666[79] = 0;
   out_3401373591342797666[80] = 0;
   out_3401373591342797666[81] = 0;
   out_3401373591342797666[82] = 0;
   out_3401373591342797666[83] = 0;
   out_3401373591342797666[84] = 0;
   out_3401373591342797666[85] = dt;
   out_3401373591342797666[86] = 0;
   out_3401373591342797666[87] = 0;
   out_3401373591342797666[88] = 0;
   out_3401373591342797666[89] = 0;
   out_3401373591342797666[90] = 0;
   out_3401373591342797666[91] = 0;
   out_3401373591342797666[92] = 0;
   out_3401373591342797666[93] = 0;
   out_3401373591342797666[94] = 0;
   out_3401373591342797666[95] = 1;
   out_3401373591342797666[96] = 0;
   out_3401373591342797666[97] = 0;
   out_3401373591342797666[98] = 0;
   out_3401373591342797666[99] = 0;
   out_3401373591342797666[100] = 0;
   out_3401373591342797666[101] = 0;
   out_3401373591342797666[102] = 0;
   out_3401373591342797666[103] = 0;
   out_3401373591342797666[104] = dt;
   out_3401373591342797666[105] = 0;
   out_3401373591342797666[106] = 0;
   out_3401373591342797666[107] = 0;
   out_3401373591342797666[108] = 0;
   out_3401373591342797666[109] = 0;
   out_3401373591342797666[110] = 0;
   out_3401373591342797666[111] = 0;
   out_3401373591342797666[112] = 0;
   out_3401373591342797666[113] = 0;
   out_3401373591342797666[114] = 1;
   out_3401373591342797666[115] = 0;
   out_3401373591342797666[116] = 0;
   out_3401373591342797666[117] = 0;
   out_3401373591342797666[118] = 0;
   out_3401373591342797666[119] = 0;
   out_3401373591342797666[120] = 0;
   out_3401373591342797666[121] = 0;
   out_3401373591342797666[122] = 0;
   out_3401373591342797666[123] = 0;
   out_3401373591342797666[124] = 0;
   out_3401373591342797666[125] = 0;
   out_3401373591342797666[126] = 0;
   out_3401373591342797666[127] = 0;
   out_3401373591342797666[128] = 0;
   out_3401373591342797666[129] = 0;
   out_3401373591342797666[130] = 0;
   out_3401373591342797666[131] = 0;
   out_3401373591342797666[132] = 0;
   out_3401373591342797666[133] = 1;
   out_3401373591342797666[134] = 0;
   out_3401373591342797666[135] = 0;
   out_3401373591342797666[136] = 0;
   out_3401373591342797666[137] = 0;
   out_3401373591342797666[138] = 0;
   out_3401373591342797666[139] = 0;
   out_3401373591342797666[140] = 0;
   out_3401373591342797666[141] = 0;
   out_3401373591342797666[142] = 0;
   out_3401373591342797666[143] = 0;
   out_3401373591342797666[144] = 0;
   out_3401373591342797666[145] = 0;
   out_3401373591342797666[146] = 0;
   out_3401373591342797666[147] = 0;
   out_3401373591342797666[148] = 0;
   out_3401373591342797666[149] = 0;
   out_3401373591342797666[150] = 0;
   out_3401373591342797666[151] = 0;
   out_3401373591342797666[152] = 1;
   out_3401373591342797666[153] = 0;
   out_3401373591342797666[154] = 0;
   out_3401373591342797666[155] = 0;
   out_3401373591342797666[156] = 0;
   out_3401373591342797666[157] = 0;
   out_3401373591342797666[158] = 0;
   out_3401373591342797666[159] = 0;
   out_3401373591342797666[160] = 0;
   out_3401373591342797666[161] = 0;
   out_3401373591342797666[162] = 0;
   out_3401373591342797666[163] = 0;
   out_3401373591342797666[164] = 0;
   out_3401373591342797666[165] = 0;
   out_3401373591342797666[166] = 0;
   out_3401373591342797666[167] = 0;
   out_3401373591342797666[168] = 0;
   out_3401373591342797666[169] = 0;
   out_3401373591342797666[170] = 0;
   out_3401373591342797666[171] = 1;
   out_3401373591342797666[172] = 0;
   out_3401373591342797666[173] = 0;
   out_3401373591342797666[174] = 0;
   out_3401373591342797666[175] = 0;
   out_3401373591342797666[176] = 0;
   out_3401373591342797666[177] = 0;
   out_3401373591342797666[178] = 0;
   out_3401373591342797666[179] = 0;
   out_3401373591342797666[180] = 0;
   out_3401373591342797666[181] = 0;
   out_3401373591342797666[182] = 0;
   out_3401373591342797666[183] = 0;
   out_3401373591342797666[184] = 0;
   out_3401373591342797666[185] = 0;
   out_3401373591342797666[186] = 0;
   out_3401373591342797666[187] = 0;
   out_3401373591342797666[188] = 0;
   out_3401373591342797666[189] = 0;
   out_3401373591342797666[190] = 1;
   out_3401373591342797666[191] = 0;
   out_3401373591342797666[192] = 0;
   out_3401373591342797666[193] = 0;
   out_3401373591342797666[194] = 0;
   out_3401373591342797666[195] = 0;
   out_3401373591342797666[196] = 0;
   out_3401373591342797666[197] = 0;
   out_3401373591342797666[198] = 0;
   out_3401373591342797666[199] = 0;
   out_3401373591342797666[200] = 0;
   out_3401373591342797666[201] = 0;
   out_3401373591342797666[202] = 0;
   out_3401373591342797666[203] = 0;
   out_3401373591342797666[204] = 0;
   out_3401373591342797666[205] = 0;
   out_3401373591342797666[206] = 0;
   out_3401373591342797666[207] = 0;
   out_3401373591342797666[208] = 0;
   out_3401373591342797666[209] = 1;
   out_3401373591342797666[210] = 0;
   out_3401373591342797666[211] = 0;
   out_3401373591342797666[212] = 0;
   out_3401373591342797666[213] = 0;
   out_3401373591342797666[214] = 0;
   out_3401373591342797666[215] = 0;
   out_3401373591342797666[216] = 0;
   out_3401373591342797666[217] = 0;
   out_3401373591342797666[218] = 0;
   out_3401373591342797666[219] = 0;
   out_3401373591342797666[220] = 0;
   out_3401373591342797666[221] = 0;
   out_3401373591342797666[222] = 0;
   out_3401373591342797666[223] = 0;
   out_3401373591342797666[224] = 0;
   out_3401373591342797666[225] = 0;
   out_3401373591342797666[226] = 0;
   out_3401373591342797666[227] = 0;
   out_3401373591342797666[228] = 1;
   out_3401373591342797666[229] = 0;
   out_3401373591342797666[230] = 0;
   out_3401373591342797666[231] = 0;
   out_3401373591342797666[232] = 0;
   out_3401373591342797666[233] = 0;
   out_3401373591342797666[234] = 0;
   out_3401373591342797666[235] = 0;
   out_3401373591342797666[236] = 0;
   out_3401373591342797666[237] = 0;
   out_3401373591342797666[238] = 0;
   out_3401373591342797666[239] = 0;
   out_3401373591342797666[240] = 0;
   out_3401373591342797666[241] = 0;
   out_3401373591342797666[242] = 0;
   out_3401373591342797666[243] = 0;
   out_3401373591342797666[244] = 0;
   out_3401373591342797666[245] = 0;
   out_3401373591342797666[246] = 0;
   out_3401373591342797666[247] = 1;
   out_3401373591342797666[248] = 0;
   out_3401373591342797666[249] = 0;
   out_3401373591342797666[250] = 0;
   out_3401373591342797666[251] = 0;
   out_3401373591342797666[252] = 0;
   out_3401373591342797666[253] = 0;
   out_3401373591342797666[254] = 0;
   out_3401373591342797666[255] = 0;
   out_3401373591342797666[256] = 0;
   out_3401373591342797666[257] = 0;
   out_3401373591342797666[258] = 0;
   out_3401373591342797666[259] = 0;
   out_3401373591342797666[260] = 0;
   out_3401373591342797666[261] = 0;
   out_3401373591342797666[262] = 0;
   out_3401373591342797666[263] = 0;
   out_3401373591342797666[264] = 0;
   out_3401373591342797666[265] = 0;
   out_3401373591342797666[266] = 1;
   out_3401373591342797666[267] = 0;
   out_3401373591342797666[268] = 0;
   out_3401373591342797666[269] = 0;
   out_3401373591342797666[270] = 0;
   out_3401373591342797666[271] = 0;
   out_3401373591342797666[272] = 0;
   out_3401373591342797666[273] = 0;
   out_3401373591342797666[274] = 0;
   out_3401373591342797666[275] = 0;
   out_3401373591342797666[276] = 0;
   out_3401373591342797666[277] = 0;
   out_3401373591342797666[278] = 0;
   out_3401373591342797666[279] = 0;
   out_3401373591342797666[280] = 0;
   out_3401373591342797666[281] = 0;
   out_3401373591342797666[282] = 0;
   out_3401373591342797666[283] = 0;
   out_3401373591342797666[284] = 0;
   out_3401373591342797666[285] = 1;
   out_3401373591342797666[286] = 0;
   out_3401373591342797666[287] = 0;
   out_3401373591342797666[288] = 0;
   out_3401373591342797666[289] = 0;
   out_3401373591342797666[290] = 0;
   out_3401373591342797666[291] = 0;
   out_3401373591342797666[292] = 0;
   out_3401373591342797666[293] = 0;
   out_3401373591342797666[294] = 0;
   out_3401373591342797666[295] = 0;
   out_3401373591342797666[296] = 0;
   out_3401373591342797666[297] = 0;
   out_3401373591342797666[298] = 0;
   out_3401373591342797666[299] = 0;
   out_3401373591342797666[300] = 0;
   out_3401373591342797666[301] = 0;
   out_3401373591342797666[302] = 0;
   out_3401373591342797666[303] = 0;
   out_3401373591342797666[304] = 1;
   out_3401373591342797666[305] = 0;
   out_3401373591342797666[306] = 0;
   out_3401373591342797666[307] = 0;
   out_3401373591342797666[308] = 0;
   out_3401373591342797666[309] = 0;
   out_3401373591342797666[310] = 0;
   out_3401373591342797666[311] = 0;
   out_3401373591342797666[312] = 0;
   out_3401373591342797666[313] = 0;
   out_3401373591342797666[314] = 0;
   out_3401373591342797666[315] = 0;
   out_3401373591342797666[316] = 0;
   out_3401373591342797666[317] = 0;
   out_3401373591342797666[318] = 0;
   out_3401373591342797666[319] = 0;
   out_3401373591342797666[320] = 0;
   out_3401373591342797666[321] = 0;
   out_3401373591342797666[322] = 0;
   out_3401373591342797666[323] = 1;
}
void h_4(double *state, double *unused, double *out_2493922315843674136) {
   out_2493922315843674136[0] = state[6] + state[9];
   out_2493922315843674136[1] = state[7] + state[10];
   out_2493922315843674136[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_1093976949342281069) {
   out_1093976949342281069[0] = 0;
   out_1093976949342281069[1] = 0;
   out_1093976949342281069[2] = 0;
   out_1093976949342281069[3] = 0;
   out_1093976949342281069[4] = 0;
   out_1093976949342281069[5] = 0;
   out_1093976949342281069[6] = 1;
   out_1093976949342281069[7] = 0;
   out_1093976949342281069[8] = 0;
   out_1093976949342281069[9] = 1;
   out_1093976949342281069[10] = 0;
   out_1093976949342281069[11] = 0;
   out_1093976949342281069[12] = 0;
   out_1093976949342281069[13] = 0;
   out_1093976949342281069[14] = 0;
   out_1093976949342281069[15] = 0;
   out_1093976949342281069[16] = 0;
   out_1093976949342281069[17] = 0;
   out_1093976949342281069[18] = 0;
   out_1093976949342281069[19] = 0;
   out_1093976949342281069[20] = 0;
   out_1093976949342281069[21] = 0;
   out_1093976949342281069[22] = 0;
   out_1093976949342281069[23] = 0;
   out_1093976949342281069[24] = 0;
   out_1093976949342281069[25] = 1;
   out_1093976949342281069[26] = 0;
   out_1093976949342281069[27] = 0;
   out_1093976949342281069[28] = 1;
   out_1093976949342281069[29] = 0;
   out_1093976949342281069[30] = 0;
   out_1093976949342281069[31] = 0;
   out_1093976949342281069[32] = 0;
   out_1093976949342281069[33] = 0;
   out_1093976949342281069[34] = 0;
   out_1093976949342281069[35] = 0;
   out_1093976949342281069[36] = 0;
   out_1093976949342281069[37] = 0;
   out_1093976949342281069[38] = 0;
   out_1093976949342281069[39] = 0;
   out_1093976949342281069[40] = 0;
   out_1093976949342281069[41] = 0;
   out_1093976949342281069[42] = 0;
   out_1093976949342281069[43] = 0;
   out_1093976949342281069[44] = 1;
   out_1093976949342281069[45] = 0;
   out_1093976949342281069[46] = 0;
   out_1093976949342281069[47] = 1;
   out_1093976949342281069[48] = 0;
   out_1093976949342281069[49] = 0;
   out_1093976949342281069[50] = 0;
   out_1093976949342281069[51] = 0;
   out_1093976949342281069[52] = 0;
   out_1093976949342281069[53] = 0;
}
void h_10(double *state, double *unused, double *out_288808481596522343) {
   out_288808481596522343[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_288808481596522343[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_288808481596522343[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4474711072663792050) {
   out_4474711072663792050[0] = 0;
   out_4474711072663792050[1] = 9.8100000000000005*cos(state[1]);
   out_4474711072663792050[2] = 0;
   out_4474711072663792050[3] = 0;
   out_4474711072663792050[4] = -state[8];
   out_4474711072663792050[5] = state[7];
   out_4474711072663792050[6] = 0;
   out_4474711072663792050[7] = state[5];
   out_4474711072663792050[8] = -state[4];
   out_4474711072663792050[9] = 0;
   out_4474711072663792050[10] = 0;
   out_4474711072663792050[11] = 0;
   out_4474711072663792050[12] = 1;
   out_4474711072663792050[13] = 0;
   out_4474711072663792050[14] = 0;
   out_4474711072663792050[15] = 1;
   out_4474711072663792050[16] = 0;
   out_4474711072663792050[17] = 0;
   out_4474711072663792050[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4474711072663792050[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4474711072663792050[20] = 0;
   out_4474711072663792050[21] = state[8];
   out_4474711072663792050[22] = 0;
   out_4474711072663792050[23] = -state[6];
   out_4474711072663792050[24] = -state[5];
   out_4474711072663792050[25] = 0;
   out_4474711072663792050[26] = state[3];
   out_4474711072663792050[27] = 0;
   out_4474711072663792050[28] = 0;
   out_4474711072663792050[29] = 0;
   out_4474711072663792050[30] = 0;
   out_4474711072663792050[31] = 1;
   out_4474711072663792050[32] = 0;
   out_4474711072663792050[33] = 0;
   out_4474711072663792050[34] = 1;
   out_4474711072663792050[35] = 0;
   out_4474711072663792050[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4474711072663792050[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4474711072663792050[38] = 0;
   out_4474711072663792050[39] = -state[7];
   out_4474711072663792050[40] = state[6];
   out_4474711072663792050[41] = 0;
   out_4474711072663792050[42] = state[4];
   out_4474711072663792050[43] = -state[3];
   out_4474711072663792050[44] = 0;
   out_4474711072663792050[45] = 0;
   out_4474711072663792050[46] = 0;
   out_4474711072663792050[47] = 0;
   out_4474711072663792050[48] = 0;
   out_4474711072663792050[49] = 0;
   out_4474711072663792050[50] = 1;
   out_4474711072663792050[51] = 0;
   out_4474711072663792050[52] = 0;
   out_4474711072663792050[53] = 1;
}
void h_13(double *state, double *unused, double *out_5108938482451502751) {
   out_5108938482451502751[0] = state[3];
   out_5108938482451502751[1] = state[4];
   out_5108938482451502751[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2118296875990051732) {
   out_2118296875990051732[0] = 0;
   out_2118296875990051732[1] = 0;
   out_2118296875990051732[2] = 0;
   out_2118296875990051732[3] = 1;
   out_2118296875990051732[4] = 0;
   out_2118296875990051732[5] = 0;
   out_2118296875990051732[6] = 0;
   out_2118296875990051732[7] = 0;
   out_2118296875990051732[8] = 0;
   out_2118296875990051732[9] = 0;
   out_2118296875990051732[10] = 0;
   out_2118296875990051732[11] = 0;
   out_2118296875990051732[12] = 0;
   out_2118296875990051732[13] = 0;
   out_2118296875990051732[14] = 0;
   out_2118296875990051732[15] = 0;
   out_2118296875990051732[16] = 0;
   out_2118296875990051732[17] = 0;
   out_2118296875990051732[18] = 0;
   out_2118296875990051732[19] = 0;
   out_2118296875990051732[20] = 0;
   out_2118296875990051732[21] = 0;
   out_2118296875990051732[22] = 1;
   out_2118296875990051732[23] = 0;
   out_2118296875990051732[24] = 0;
   out_2118296875990051732[25] = 0;
   out_2118296875990051732[26] = 0;
   out_2118296875990051732[27] = 0;
   out_2118296875990051732[28] = 0;
   out_2118296875990051732[29] = 0;
   out_2118296875990051732[30] = 0;
   out_2118296875990051732[31] = 0;
   out_2118296875990051732[32] = 0;
   out_2118296875990051732[33] = 0;
   out_2118296875990051732[34] = 0;
   out_2118296875990051732[35] = 0;
   out_2118296875990051732[36] = 0;
   out_2118296875990051732[37] = 0;
   out_2118296875990051732[38] = 0;
   out_2118296875990051732[39] = 0;
   out_2118296875990051732[40] = 0;
   out_2118296875990051732[41] = 1;
   out_2118296875990051732[42] = 0;
   out_2118296875990051732[43] = 0;
   out_2118296875990051732[44] = 0;
   out_2118296875990051732[45] = 0;
   out_2118296875990051732[46] = 0;
   out_2118296875990051732[47] = 0;
   out_2118296875990051732[48] = 0;
   out_2118296875990051732[49] = 0;
   out_2118296875990051732[50] = 0;
   out_2118296875990051732[51] = 0;
   out_2118296875990051732[52] = 0;
   out_2118296875990051732[53] = 0;
}
void h_14(double *state, double *unused, double *out_5863792870354861000) {
   out_5863792870354861000[0] = state[6];
   out_5863792870354861000[1] = state[7];
   out_5863792870354861000[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2869263906997203460) {
   out_2869263906997203460[0] = 0;
   out_2869263906997203460[1] = 0;
   out_2869263906997203460[2] = 0;
   out_2869263906997203460[3] = 0;
   out_2869263906997203460[4] = 0;
   out_2869263906997203460[5] = 0;
   out_2869263906997203460[6] = 1;
   out_2869263906997203460[7] = 0;
   out_2869263906997203460[8] = 0;
   out_2869263906997203460[9] = 0;
   out_2869263906997203460[10] = 0;
   out_2869263906997203460[11] = 0;
   out_2869263906997203460[12] = 0;
   out_2869263906997203460[13] = 0;
   out_2869263906997203460[14] = 0;
   out_2869263906997203460[15] = 0;
   out_2869263906997203460[16] = 0;
   out_2869263906997203460[17] = 0;
   out_2869263906997203460[18] = 0;
   out_2869263906997203460[19] = 0;
   out_2869263906997203460[20] = 0;
   out_2869263906997203460[21] = 0;
   out_2869263906997203460[22] = 0;
   out_2869263906997203460[23] = 0;
   out_2869263906997203460[24] = 0;
   out_2869263906997203460[25] = 1;
   out_2869263906997203460[26] = 0;
   out_2869263906997203460[27] = 0;
   out_2869263906997203460[28] = 0;
   out_2869263906997203460[29] = 0;
   out_2869263906997203460[30] = 0;
   out_2869263906997203460[31] = 0;
   out_2869263906997203460[32] = 0;
   out_2869263906997203460[33] = 0;
   out_2869263906997203460[34] = 0;
   out_2869263906997203460[35] = 0;
   out_2869263906997203460[36] = 0;
   out_2869263906997203460[37] = 0;
   out_2869263906997203460[38] = 0;
   out_2869263906997203460[39] = 0;
   out_2869263906997203460[40] = 0;
   out_2869263906997203460[41] = 0;
   out_2869263906997203460[42] = 0;
   out_2869263906997203460[43] = 0;
   out_2869263906997203460[44] = 1;
   out_2869263906997203460[45] = 0;
   out_2869263906997203460[46] = 0;
   out_2869263906997203460[47] = 0;
   out_2869263906997203460[48] = 0;
   out_2869263906997203460[49] = 0;
   out_2869263906997203460[50] = 0;
   out_2869263906997203460[51] = 0;
   out_2869263906997203460[52] = 0;
   out_2869263906997203460[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_6009088715125097596) {
  err_fun(nom_x, delta_x, out_6009088715125097596);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5460684038605246490) {
  inv_err_fun(nom_x, true_x, out_5460684038605246490);
}
void pose_H_mod_fun(double *state, double *out_2180245129448668184) {
  H_mod_fun(state, out_2180245129448668184);
}
void pose_f_fun(double *state, double dt, double *out_1359935913624561504) {
  f_fun(state,  dt, out_1359935913624561504);
}
void pose_F_fun(double *state, double dt, double *out_3401373591342797666) {
  F_fun(state,  dt, out_3401373591342797666);
}
void pose_h_4(double *state, double *unused, double *out_2493922315843674136) {
  h_4(state, unused, out_2493922315843674136);
}
void pose_H_4(double *state, double *unused, double *out_1093976949342281069) {
  H_4(state, unused, out_1093976949342281069);
}
void pose_h_10(double *state, double *unused, double *out_288808481596522343) {
  h_10(state, unused, out_288808481596522343);
}
void pose_H_10(double *state, double *unused, double *out_4474711072663792050) {
  H_10(state, unused, out_4474711072663792050);
}
void pose_h_13(double *state, double *unused, double *out_5108938482451502751) {
  h_13(state, unused, out_5108938482451502751);
}
void pose_H_13(double *state, double *unused, double *out_2118296875990051732) {
  H_13(state, unused, out_2118296875990051732);
}
void pose_h_14(double *state, double *unused, double *out_5863792870354861000) {
  h_14(state, unused, out_5863792870354861000);
}
void pose_H_14(double *state, double *unused, double *out_2869263906997203460) {
  H_14(state, unused, out_2869263906997203460);
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
