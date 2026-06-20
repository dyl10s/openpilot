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
void err_fun(double *nom_x, double *delta_x, double *out_6656391008125290288) {
   out_6656391008125290288[0] = delta_x[0] + nom_x[0];
   out_6656391008125290288[1] = delta_x[1] + nom_x[1];
   out_6656391008125290288[2] = delta_x[2] + nom_x[2];
   out_6656391008125290288[3] = delta_x[3] + nom_x[3];
   out_6656391008125290288[4] = delta_x[4] + nom_x[4];
   out_6656391008125290288[5] = delta_x[5] + nom_x[5];
   out_6656391008125290288[6] = delta_x[6] + nom_x[6];
   out_6656391008125290288[7] = delta_x[7] + nom_x[7];
   out_6656391008125290288[8] = delta_x[8] + nom_x[8];
   out_6656391008125290288[9] = delta_x[9] + nom_x[9];
   out_6656391008125290288[10] = delta_x[10] + nom_x[10];
   out_6656391008125290288[11] = delta_x[11] + nom_x[11];
   out_6656391008125290288[12] = delta_x[12] + nom_x[12];
   out_6656391008125290288[13] = delta_x[13] + nom_x[13];
   out_6656391008125290288[14] = delta_x[14] + nom_x[14];
   out_6656391008125290288[15] = delta_x[15] + nom_x[15];
   out_6656391008125290288[16] = delta_x[16] + nom_x[16];
   out_6656391008125290288[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2808972743269739579) {
   out_2808972743269739579[0] = -nom_x[0] + true_x[0];
   out_2808972743269739579[1] = -nom_x[1] + true_x[1];
   out_2808972743269739579[2] = -nom_x[2] + true_x[2];
   out_2808972743269739579[3] = -nom_x[3] + true_x[3];
   out_2808972743269739579[4] = -nom_x[4] + true_x[4];
   out_2808972743269739579[5] = -nom_x[5] + true_x[5];
   out_2808972743269739579[6] = -nom_x[6] + true_x[6];
   out_2808972743269739579[7] = -nom_x[7] + true_x[7];
   out_2808972743269739579[8] = -nom_x[8] + true_x[8];
   out_2808972743269739579[9] = -nom_x[9] + true_x[9];
   out_2808972743269739579[10] = -nom_x[10] + true_x[10];
   out_2808972743269739579[11] = -nom_x[11] + true_x[11];
   out_2808972743269739579[12] = -nom_x[12] + true_x[12];
   out_2808972743269739579[13] = -nom_x[13] + true_x[13];
   out_2808972743269739579[14] = -nom_x[14] + true_x[14];
   out_2808972743269739579[15] = -nom_x[15] + true_x[15];
   out_2808972743269739579[16] = -nom_x[16] + true_x[16];
   out_2808972743269739579[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1869854945663891945) {
   out_1869854945663891945[0] = 1.0;
   out_1869854945663891945[1] = 0.0;
   out_1869854945663891945[2] = 0.0;
   out_1869854945663891945[3] = 0.0;
   out_1869854945663891945[4] = 0.0;
   out_1869854945663891945[5] = 0.0;
   out_1869854945663891945[6] = 0.0;
   out_1869854945663891945[7] = 0.0;
   out_1869854945663891945[8] = 0.0;
   out_1869854945663891945[9] = 0.0;
   out_1869854945663891945[10] = 0.0;
   out_1869854945663891945[11] = 0.0;
   out_1869854945663891945[12] = 0.0;
   out_1869854945663891945[13] = 0.0;
   out_1869854945663891945[14] = 0.0;
   out_1869854945663891945[15] = 0.0;
   out_1869854945663891945[16] = 0.0;
   out_1869854945663891945[17] = 0.0;
   out_1869854945663891945[18] = 0.0;
   out_1869854945663891945[19] = 1.0;
   out_1869854945663891945[20] = 0.0;
   out_1869854945663891945[21] = 0.0;
   out_1869854945663891945[22] = 0.0;
   out_1869854945663891945[23] = 0.0;
   out_1869854945663891945[24] = 0.0;
   out_1869854945663891945[25] = 0.0;
   out_1869854945663891945[26] = 0.0;
   out_1869854945663891945[27] = 0.0;
   out_1869854945663891945[28] = 0.0;
   out_1869854945663891945[29] = 0.0;
   out_1869854945663891945[30] = 0.0;
   out_1869854945663891945[31] = 0.0;
   out_1869854945663891945[32] = 0.0;
   out_1869854945663891945[33] = 0.0;
   out_1869854945663891945[34] = 0.0;
   out_1869854945663891945[35] = 0.0;
   out_1869854945663891945[36] = 0.0;
   out_1869854945663891945[37] = 0.0;
   out_1869854945663891945[38] = 1.0;
   out_1869854945663891945[39] = 0.0;
   out_1869854945663891945[40] = 0.0;
   out_1869854945663891945[41] = 0.0;
   out_1869854945663891945[42] = 0.0;
   out_1869854945663891945[43] = 0.0;
   out_1869854945663891945[44] = 0.0;
   out_1869854945663891945[45] = 0.0;
   out_1869854945663891945[46] = 0.0;
   out_1869854945663891945[47] = 0.0;
   out_1869854945663891945[48] = 0.0;
   out_1869854945663891945[49] = 0.0;
   out_1869854945663891945[50] = 0.0;
   out_1869854945663891945[51] = 0.0;
   out_1869854945663891945[52] = 0.0;
   out_1869854945663891945[53] = 0.0;
   out_1869854945663891945[54] = 0.0;
   out_1869854945663891945[55] = 0.0;
   out_1869854945663891945[56] = 0.0;
   out_1869854945663891945[57] = 1.0;
   out_1869854945663891945[58] = 0.0;
   out_1869854945663891945[59] = 0.0;
   out_1869854945663891945[60] = 0.0;
   out_1869854945663891945[61] = 0.0;
   out_1869854945663891945[62] = 0.0;
   out_1869854945663891945[63] = 0.0;
   out_1869854945663891945[64] = 0.0;
   out_1869854945663891945[65] = 0.0;
   out_1869854945663891945[66] = 0.0;
   out_1869854945663891945[67] = 0.0;
   out_1869854945663891945[68] = 0.0;
   out_1869854945663891945[69] = 0.0;
   out_1869854945663891945[70] = 0.0;
   out_1869854945663891945[71] = 0.0;
   out_1869854945663891945[72] = 0.0;
   out_1869854945663891945[73] = 0.0;
   out_1869854945663891945[74] = 0.0;
   out_1869854945663891945[75] = 0.0;
   out_1869854945663891945[76] = 1.0;
   out_1869854945663891945[77] = 0.0;
   out_1869854945663891945[78] = 0.0;
   out_1869854945663891945[79] = 0.0;
   out_1869854945663891945[80] = 0.0;
   out_1869854945663891945[81] = 0.0;
   out_1869854945663891945[82] = 0.0;
   out_1869854945663891945[83] = 0.0;
   out_1869854945663891945[84] = 0.0;
   out_1869854945663891945[85] = 0.0;
   out_1869854945663891945[86] = 0.0;
   out_1869854945663891945[87] = 0.0;
   out_1869854945663891945[88] = 0.0;
   out_1869854945663891945[89] = 0.0;
   out_1869854945663891945[90] = 0.0;
   out_1869854945663891945[91] = 0.0;
   out_1869854945663891945[92] = 0.0;
   out_1869854945663891945[93] = 0.0;
   out_1869854945663891945[94] = 0.0;
   out_1869854945663891945[95] = 1.0;
   out_1869854945663891945[96] = 0.0;
   out_1869854945663891945[97] = 0.0;
   out_1869854945663891945[98] = 0.0;
   out_1869854945663891945[99] = 0.0;
   out_1869854945663891945[100] = 0.0;
   out_1869854945663891945[101] = 0.0;
   out_1869854945663891945[102] = 0.0;
   out_1869854945663891945[103] = 0.0;
   out_1869854945663891945[104] = 0.0;
   out_1869854945663891945[105] = 0.0;
   out_1869854945663891945[106] = 0.0;
   out_1869854945663891945[107] = 0.0;
   out_1869854945663891945[108] = 0.0;
   out_1869854945663891945[109] = 0.0;
   out_1869854945663891945[110] = 0.0;
   out_1869854945663891945[111] = 0.0;
   out_1869854945663891945[112] = 0.0;
   out_1869854945663891945[113] = 0.0;
   out_1869854945663891945[114] = 1.0;
   out_1869854945663891945[115] = 0.0;
   out_1869854945663891945[116] = 0.0;
   out_1869854945663891945[117] = 0.0;
   out_1869854945663891945[118] = 0.0;
   out_1869854945663891945[119] = 0.0;
   out_1869854945663891945[120] = 0.0;
   out_1869854945663891945[121] = 0.0;
   out_1869854945663891945[122] = 0.0;
   out_1869854945663891945[123] = 0.0;
   out_1869854945663891945[124] = 0.0;
   out_1869854945663891945[125] = 0.0;
   out_1869854945663891945[126] = 0.0;
   out_1869854945663891945[127] = 0.0;
   out_1869854945663891945[128] = 0.0;
   out_1869854945663891945[129] = 0.0;
   out_1869854945663891945[130] = 0.0;
   out_1869854945663891945[131] = 0.0;
   out_1869854945663891945[132] = 0.0;
   out_1869854945663891945[133] = 1.0;
   out_1869854945663891945[134] = 0.0;
   out_1869854945663891945[135] = 0.0;
   out_1869854945663891945[136] = 0.0;
   out_1869854945663891945[137] = 0.0;
   out_1869854945663891945[138] = 0.0;
   out_1869854945663891945[139] = 0.0;
   out_1869854945663891945[140] = 0.0;
   out_1869854945663891945[141] = 0.0;
   out_1869854945663891945[142] = 0.0;
   out_1869854945663891945[143] = 0.0;
   out_1869854945663891945[144] = 0.0;
   out_1869854945663891945[145] = 0.0;
   out_1869854945663891945[146] = 0.0;
   out_1869854945663891945[147] = 0.0;
   out_1869854945663891945[148] = 0.0;
   out_1869854945663891945[149] = 0.0;
   out_1869854945663891945[150] = 0.0;
   out_1869854945663891945[151] = 0.0;
   out_1869854945663891945[152] = 1.0;
   out_1869854945663891945[153] = 0.0;
   out_1869854945663891945[154] = 0.0;
   out_1869854945663891945[155] = 0.0;
   out_1869854945663891945[156] = 0.0;
   out_1869854945663891945[157] = 0.0;
   out_1869854945663891945[158] = 0.0;
   out_1869854945663891945[159] = 0.0;
   out_1869854945663891945[160] = 0.0;
   out_1869854945663891945[161] = 0.0;
   out_1869854945663891945[162] = 0.0;
   out_1869854945663891945[163] = 0.0;
   out_1869854945663891945[164] = 0.0;
   out_1869854945663891945[165] = 0.0;
   out_1869854945663891945[166] = 0.0;
   out_1869854945663891945[167] = 0.0;
   out_1869854945663891945[168] = 0.0;
   out_1869854945663891945[169] = 0.0;
   out_1869854945663891945[170] = 0.0;
   out_1869854945663891945[171] = 1.0;
   out_1869854945663891945[172] = 0.0;
   out_1869854945663891945[173] = 0.0;
   out_1869854945663891945[174] = 0.0;
   out_1869854945663891945[175] = 0.0;
   out_1869854945663891945[176] = 0.0;
   out_1869854945663891945[177] = 0.0;
   out_1869854945663891945[178] = 0.0;
   out_1869854945663891945[179] = 0.0;
   out_1869854945663891945[180] = 0.0;
   out_1869854945663891945[181] = 0.0;
   out_1869854945663891945[182] = 0.0;
   out_1869854945663891945[183] = 0.0;
   out_1869854945663891945[184] = 0.0;
   out_1869854945663891945[185] = 0.0;
   out_1869854945663891945[186] = 0.0;
   out_1869854945663891945[187] = 0.0;
   out_1869854945663891945[188] = 0.0;
   out_1869854945663891945[189] = 0.0;
   out_1869854945663891945[190] = 1.0;
   out_1869854945663891945[191] = 0.0;
   out_1869854945663891945[192] = 0.0;
   out_1869854945663891945[193] = 0.0;
   out_1869854945663891945[194] = 0.0;
   out_1869854945663891945[195] = 0.0;
   out_1869854945663891945[196] = 0.0;
   out_1869854945663891945[197] = 0.0;
   out_1869854945663891945[198] = 0.0;
   out_1869854945663891945[199] = 0.0;
   out_1869854945663891945[200] = 0.0;
   out_1869854945663891945[201] = 0.0;
   out_1869854945663891945[202] = 0.0;
   out_1869854945663891945[203] = 0.0;
   out_1869854945663891945[204] = 0.0;
   out_1869854945663891945[205] = 0.0;
   out_1869854945663891945[206] = 0.0;
   out_1869854945663891945[207] = 0.0;
   out_1869854945663891945[208] = 0.0;
   out_1869854945663891945[209] = 1.0;
   out_1869854945663891945[210] = 0.0;
   out_1869854945663891945[211] = 0.0;
   out_1869854945663891945[212] = 0.0;
   out_1869854945663891945[213] = 0.0;
   out_1869854945663891945[214] = 0.0;
   out_1869854945663891945[215] = 0.0;
   out_1869854945663891945[216] = 0.0;
   out_1869854945663891945[217] = 0.0;
   out_1869854945663891945[218] = 0.0;
   out_1869854945663891945[219] = 0.0;
   out_1869854945663891945[220] = 0.0;
   out_1869854945663891945[221] = 0.0;
   out_1869854945663891945[222] = 0.0;
   out_1869854945663891945[223] = 0.0;
   out_1869854945663891945[224] = 0.0;
   out_1869854945663891945[225] = 0.0;
   out_1869854945663891945[226] = 0.0;
   out_1869854945663891945[227] = 0.0;
   out_1869854945663891945[228] = 1.0;
   out_1869854945663891945[229] = 0.0;
   out_1869854945663891945[230] = 0.0;
   out_1869854945663891945[231] = 0.0;
   out_1869854945663891945[232] = 0.0;
   out_1869854945663891945[233] = 0.0;
   out_1869854945663891945[234] = 0.0;
   out_1869854945663891945[235] = 0.0;
   out_1869854945663891945[236] = 0.0;
   out_1869854945663891945[237] = 0.0;
   out_1869854945663891945[238] = 0.0;
   out_1869854945663891945[239] = 0.0;
   out_1869854945663891945[240] = 0.0;
   out_1869854945663891945[241] = 0.0;
   out_1869854945663891945[242] = 0.0;
   out_1869854945663891945[243] = 0.0;
   out_1869854945663891945[244] = 0.0;
   out_1869854945663891945[245] = 0.0;
   out_1869854945663891945[246] = 0.0;
   out_1869854945663891945[247] = 1.0;
   out_1869854945663891945[248] = 0.0;
   out_1869854945663891945[249] = 0.0;
   out_1869854945663891945[250] = 0.0;
   out_1869854945663891945[251] = 0.0;
   out_1869854945663891945[252] = 0.0;
   out_1869854945663891945[253] = 0.0;
   out_1869854945663891945[254] = 0.0;
   out_1869854945663891945[255] = 0.0;
   out_1869854945663891945[256] = 0.0;
   out_1869854945663891945[257] = 0.0;
   out_1869854945663891945[258] = 0.0;
   out_1869854945663891945[259] = 0.0;
   out_1869854945663891945[260] = 0.0;
   out_1869854945663891945[261] = 0.0;
   out_1869854945663891945[262] = 0.0;
   out_1869854945663891945[263] = 0.0;
   out_1869854945663891945[264] = 0.0;
   out_1869854945663891945[265] = 0.0;
   out_1869854945663891945[266] = 1.0;
   out_1869854945663891945[267] = 0.0;
   out_1869854945663891945[268] = 0.0;
   out_1869854945663891945[269] = 0.0;
   out_1869854945663891945[270] = 0.0;
   out_1869854945663891945[271] = 0.0;
   out_1869854945663891945[272] = 0.0;
   out_1869854945663891945[273] = 0.0;
   out_1869854945663891945[274] = 0.0;
   out_1869854945663891945[275] = 0.0;
   out_1869854945663891945[276] = 0.0;
   out_1869854945663891945[277] = 0.0;
   out_1869854945663891945[278] = 0.0;
   out_1869854945663891945[279] = 0.0;
   out_1869854945663891945[280] = 0.0;
   out_1869854945663891945[281] = 0.0;
   out_1869854945663891945[282] = 0.0;
   out_1869854945663891945[283] = 0.0;
   out_1869854945663891945[284] = 0.0;
   out_1869854945663891945[285] = 1.0;
   out_1869854945663891945[286] = 0.0;
   out_1869854945663891945[287] = 0.0;
   out_1869854945663891945[288] = 0.0;
   out_1869854945663891945[289] = 0.0;
   out_1869854945663891945[290] = 0.0;
   out_1869854945663891945[291] = 0.0;
   out_1869854945663891945[292] = 0.0;
   out_1869854945663891945[293] = 0.0;
   out_1869854945663891945[294] = 0.0;
   out_1869854945663891945[295] = 0.0;
   out_1869854945663891945[296] = 0.0;
   out_1869854945663891945[297] = 0.0;
   out_1869854945663891945[298] = 0.0;
   out_1869854945663891945[299] = 0.0;
   out_1869854945663891945[300] = 0.0;
   out_1869854945663891945[301] = 0.0;
   out_1869854945663891945[302] = 0.0;
   out_1869854945663891945[303] = 0.0;
   out_1869854945663891945[304] = 1.0;
   out_1869854945663891945[305] = 0.0;
   out_1869854945663891945[306] = 0.0;
   out_1869854945663891945[307] = 0.0;
   out_1869854945663891945[308] = 0.0;
   out_1869854945663891945[309] = 0.0;
   out_1869854945663891945[310] = 0.0;
   out_1869854945663891945[311] = 0.0;
   out_1869854945663891945[312] = 0.0;
   out_1869854945663891945[313] = 0.0;
   out_1869854945663891945[314] = 0.0;
   out_1869854945663891945[315] = 0.0;
   out_1869854945663891945[316] = 0.0;
   out_1869854945663891945[317] = 0.0;
   out_1869854945663891945[318] = 0.0;
   out_1869854945663891945[319] = 0.0;
   out_1869854945663891945[320] = 0.0;
   out_1869854945663891945[321] = 0.0;
   out_1869854945663891945[322] = 0.0;
   out_1869854945663891945[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1891205901656639709) {
   out_1891205901656639709[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1891205901656639709[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1891205901656639709[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1891205901656639709[3] = dt*state[12] + state[3];
   out_1891205901656639709[4] = dt*state[13] + state[4];
   out_1891205901656639709[5] = dt*state[14] + state[5];
   out_1891205901656639709[6] = state[6];
   out_1891205901656639709[7] = state[7];
   out_1891205901656639709[8] = state[8];
   out_1891205901656639709[9] = state[9];
   out_1891205901656639709[10] = state[10];
   out_1891205901656639709[11] = state[11];
   out_1891205901656639709[12] = state[12];
   out_1891205901656639709[13] = state[13];
   out_1891205901656639709[14] = state[14];
   out_1891205901656639709[15] = state[15];
   out_1891205901656639709[16] = state[16];
   out_1891205901656639709[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6621216135717119405) {
   out_6621216135717119405[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6621216135717119405[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6621216135717119405[2] = 0;
   out_6621216135717119405[3] = 0;
   out_6621216135717119405[4] = 0;
   out_6621216135717119405[5] = 0;
   out_6621216135717119405[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6621216135717119405[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6621216135717119405[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6621216135717119405[9] = 0;
   out_6621216135717119405[10] = 0;
   out_6621216135717119405[11] = 0;
   out_6621216135717119405[12] = 0;
   out_6621216135717119405[13] = 0;
   out_6621216135717119405[14] = 0;
   out_6621216135717119405[15] = 0;
   out_6621216135717119405[16] = 0;
   out_6621216135717119405[17] = 0;
   out_6621216135717119405[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6621216135717119405[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6621216135717119405[20] = 0;
   out_6621216135717119405[21] = 0;
   out_6621216135717119405[22] = 0;
   out_6621216135717119405[23] = 0;
   out_6621216135717119405[24] = 0;
   out_6621216135717119405[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6621216135717119405[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6621216135717119405[27] = 0;
   out_6621216135717119405[28] = 0;
   out_6621216135717119405[29] = 0;
   out_6621216135717119405[30] = 0;
   out_6621216135717119405[31] = 0;
   out_6621216135717119405[32] = 0;
   out_6621216135717119405[33] = 0;
   out_6621216135717119405[34] = 0;
   out_6621216135717119405[35] = 0;
   out_6621216135717119405[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6621216135717119405[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6621216135717119405[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6621216135717119405[39] = 0;
   out_6621216135717119405[40] = 0;
   out_6621216135717119405[41] = 0;
   out_6621216135717119405[42] = 0;
   out_6621216135717119405[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6621216135717119405[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6621216135717119405[45] = 0;
   out_6621216135717119405[46] = 0;
   out_6621216135717119405[47] = 0;
   out_6621216135717119405[48] = 0;
   out_6621216135717119405[49] = 0;
   out_6621216135717119405[50] = 0;
   out_6621216135717119405[51] = 0;
   out_6621216135717119405[52] = 0;
   out_6621216135717119405[53] = 0;
   out_6621216135717119405[54] = 0;
   out_6621216135717119405[55] = 0;
   out_6621216135717119405[56] = 0;
   out_6621216135717119405[57] = 1;
   out_6621216135717119405[58] = 0;
   out_6621216135717119405[59] = 0;
   out_6621216135717119405[60] = 0;
   out_6621216135717119405[61] = 0;
   out_6621216135717119405[62] = 0;
   out_6621216135717119405[63] = 0;
   out_6621216135717119405[64] = 0;
   out_6621216135717119405[65] = 0;
   out_6621216135717119405[66] = dt;
   out_6621216135717119405[67] = 0;
   out_6621216135717119405[68] = 0;
   out_6621216135717119405[69] = 0;
   out_6621216135717119405[70] = 0;
   out_6621216135717119405[71] = 0;
   out_6621216135717119405[72] = 0;
   out_6621216135717119405[73] = 0;
   out_6621216135717119405[74] = 0;
   out_6621216135717119405[75] = 0;
   out_6621216135717119405[76] = 1;
   out_6621216135717119405[77] = 0;
   out_6621216135717119405[78] = 0;
   out_6621216135717119405[79] = 0;
   out_6621216135717119405[80] = 0;
   out_6621216135717119405[81] = 0;
   out_6621216135717119405[82] = 0;
   out_6621216135717119405[83] = 0;
   out_6621216135717119405[84] = 0;
   out_6621216135717119405[85] = dt;
   out_6621216135717119405[86] = 0;
   out_6621216135717119405[87] = 0;
   out_6621216135717119405[88] = 0;
   out_6621216135717119405[89] = 0;
   out_6621216135717119405[90] = 0;
   out_6621216135717119405[91] = 0;
   out_6621216135717119405[92] = 0;
   out_6621216135717119405[93] = 0;
   out_6621216135717119405[94] = 0;
   out_6621216135717119405[95] = 1;
   out_6621216135717119405[96] = 0;
   out_6621216135717119405[97] = 0;
   out_6621216135717119405[98] = 0;
   out_6621216135717119405[99] = 0;
   out_6621216135717119405[100] = 0;
   out_6621216135717119405[101] = 0;
   out_6621216135717119405[102] = 0;
   out_6621216135717119405[103] = 0;
   out_6621216135717119405[104] = dt;
   out_6621216135717119405[105] = 0;
   out_6621216135717119405[106] = 0;
   out_6621216135717119405[107] = 0;
   out_6621216135717119405[108] = 0;
   out_6621216135717119405[109] = 0;
   out_6621216135717119405[110] = 0;
   out_6621216135717119405[111] = 0;
   out_6621216135717119405[112] = 0;
   out_6621216135717119405[113] = 0;
   out_6621216135717119405[114] = 1;
   out_6621216135717119405[115] = 0;
   out_6621216135717119405[116] = 0;
   out_6621216135717119405[117] = 0;
   out_6621216135717119405[118] = 0;
   out_6621216135717119405[119] = 0;
   out_6621216135717119405[120] = 0;
   out_6621216135717119405[121] = 0;
   out_6621216135717119405[122] = 0;
   out_6621216135717119405[123] = 0;
   out_6621216135717119405[124] = 0;
   out_6621216135717119405[125] = 0;
   out_6621216135717119405[126] = 0;
   out_6621216135717119405[127] = 0;
   out_6621216135717119405[128] = 0;
   out_6621216135717119405[129] = 0;
   out_6621216135717119405[130] = 0;
   out_6621216135717119405[131] = 0;
   out_6621216135717119405[132] = 0;
   out_6621216135717119405[133] = 1;
   out_6621216135717119405[134] = 0;
   out_6621216135717119405[135] = 0;
   out_6621216135717119405[136] = 0;
   out_6621216135717119405[137] = 0;
   out_6621216135717119405[138] = 0;
   out_6621216135717119405[139] = 0;
   out_6621216135717119405[140] = 0;
   out_6621216135717119405[141] = 0;
   out_6621216135717119405[142] = 0;
   out_6621216135717119405[143] = 0;
   out_6621216135717119405[144] = 0;
   out_6621216135717119405[145] = 0;
   out_6621216135717119405[146] = 0;
   out_6621216135717119405[147] = 0;
   out_6621216135717119405[148] = 0;
   out_6621216135717119405[149] = 0;
   out_6621216135717119405[150] = 0;
   out_6621216135717119405[151] = 0;
   out_6621216135717119405[152] = 1;
   out_6621216135717119405[153] = 0;
   out_6621216135717119405[154] = 0;
   out_6621216135717119405[155] = 0;
   out_6621216135717119405[156] = 0;
   out_6621216135717119405[157] = 0;
   out_6621216135717119405[158] = 0;
   out_6621216135717119405[159] = 0;
   out_6621216135717119405[160] = 0;
   out_6621216135717119405[161] = 0;
   out_6621216135717119405[162] = 0;
   out_6621216135717119405[163] = 0;
   out_6621216135717119405[164] = 0;
   out_6621216135717119405[165] = 0;
   out_6621216135717119405[166] = 0;
   out_6621216135717119405[167] = 0;
   out_6621216135717119405[168] = 0;
   out_6621216135717119405[169] = 0;
   out_6621216135717119405[170] = 0;
   out_6621216135717119405[171] = 1;
   out_6621216135717119405[172] = 0;
   out_6621216135717119405[173] = 0;
   out_6621216135717119405[174] = 0;
   out_6621216135717119405[175] = 0;
   out_6621216135717119405[176] = 0;
   out_6621216135717119405[177] = 0;
   out_6621216135717119405[178] = 0;
   out_6621216135717119405[179] = 0;
   out_6621216135717119405[180] = 0;
   out_6621216135717119405[181] = 0;
   out_6621216135717119405[182] = 0;
   out_6621216135717119405[183] = 0;
   out_6621216135717119405[184] = 0;
   out_6621216135717119405[185] = 0;
   out_6621216135717119405[186] = 0;
   out_6621216135717119405[187] = 0;
   out_6621216135717119405[188] = 0;
   out_6621216135717119405[189] = 0;
   out_6621216135717119405[190] = 1;
   out_6621216135717119405[191] = 0;
   out_6621216135717119405[192] = 0;
   out_6621216135717119405[193] = 0;
   out_6621216135717119405[194] = 0;
   out_6621216135717119405[195] = 0;
   out_6621216135717119405[196] = 0;
   out_6621216135717119405[197] = 0;
   out_6621216135717119405[198] = 0;
   out_6621216135717119405[199] = 0;
   out_6621216135717119405[200] = 0;
   out_6621216135717119405[201] = 0;
   out_6621216135717119405[202] = 0;
   out_6621216135717119405[203] = 0;
   out_6621216135717119405[204] = 0;
   out_6621216135717119405[205] = 0;
   out_6621216135717119405[206] = 0;
   out_6621216135717119405[207] = 0;
   out_6621216135717119405[208] = 0;
   out_6621216135717119405[209] = 1;
   out_6621216135717119405[210] = 0;
   out_6621216135717119405[211] = 0;
   out_6621216135717119405[212] = 0;
   out_6621216135717119405[213] = 0;
   out_6621216135717119405[214] = 0;
   out_6621216135717119405[215] = 0;
   out_6621216135717119405[216] = 0;
   out_6621216135717119405[217] = 0;
   out_6621216135717119405[218] = 0;
   out_6621216135717119405[219] = 0;
   out_6621216135717119405[220] = 0;
   out_6621216135717119405[221] = 0;
   out_6621216135717119405[222] = 0;
   out_6621216135717119405[223] = 0;
   out_6621216135717119405[224] = 0;
   out_6621216135717119405[225] = 0;
   out_6621216135717119405[226] = 0;
   out_6621216135717119405[227] = 0;
   out_6621216135717119405[228] = 1;
   out_6621216135717119405[229] = 0;
   out_6621216135717119405[230] = 0;
   out_6621216135717119405[231] = 0;
   out_6621216135717119405[232] = 0;
   out_6621216135717119405[233] = 0;
   out_6621216135717119405[234] = 0;
   out_6621216135717119405[235] = 0;
   out_6621216135717119405[236] = 0;
   out_6621216135717119405[237] = 0;
   out_6621216135717119405[238] = 0;
   out_6621216135717119405[239] = 0;
   out_6621216135717119405[240] = 0;
   out_6621216135717119405[241] = 0;
   out_6621216135717119405[242] = 0;
   out_6621216135717119405[243] = 0;
   out_6621216135717119405[244] = 0;
   out_6621216135717119405[245] = 0;
   out_6621216135717119405[246] = 0;
   out_6621216135717119405[247] = 1;
   out_6621216135717119405[248] = 0;
   out_6621216135717119405[249] = 0;
   out_6621216135717119405[250] = 0;
   out_6621216135717119405[251] = 0;
   out_6621216135717119405[252] = 0;
   out_6621216135717119405[253] = 0;
   out_6621216135717119405[254] = 0;
   out_6621216135717119405[255] = 0;
   out_6621216135717119405[256] = 0;
   out_6621216135717119405[257] = 0;
   out_6621216135717119405[258] = 0;
   out_6621216135717119405[259] = 0;
   out_6621216135717119405[260] = 0;
   out_6621216135717119405[261] = 0;
   out_6621216135717119405[262] = 0;
   out_6621216135717119405[263] = 0;
   out_6621216135717119405[264] = 0;
   out_6621216135717119405[265] = 0;
   out_6621216135717119405[266] = 1;
   out_6621216135717119405[267] = 0;
   out_6621216135717119405[268] = 0;
   out_6621216135717119405[269] = 0;
   out_6621216135717119405[270] = 0;
   out_6621216135717119405[271] = 0;
   out_6621216135717119405[272] = 0;
   out_6621216135717119405[273] = 0;
   out_6621216135717119405[274] = 0;
   out_6621216135717119405[275] = 0;
   out_6621216135717119405[276] = 0;
   out_6621216135717119405[277] = 0;
   out_6621216135717119405[278] = 0;
   out_6621216135717119405[279] = 0;
   out_6621216135717119405[280] = 0;
   out_6621216135717119405[281] = 0;
   out_6621216135717119405[282] = 0;
   out_6621216135717119405[283] = 0;
   out_6621216135717119405[284] = 0;
   out_6621216135717119405[285] = 1;
   out_6621216135717119405[286] = 0;
   out_6621216135717119405[287] = 0;
   out_6621216135717119405[288] = 0;
   out_6621216135717119405[289] = 0;
   out_6621216135717119405[290] = 0;
   out_6621216135717119405[291] = 0;
   out_6621216135717119405[292] = 0;
   out_6621216135717119405[293] = 0;
   out_6621216135717119405[294] = 0;
   out_6621216135717119405[295] = 0;
   out_6621216135717119405[296] = 0;
   out_6621216135717119405[297] = 0;
   out_6621216135717119405[298] = 0;
   out_6621216135717119405[299] = 0;
   out_6621216135717119405[300] = 0;
   out_6621216135717119405[301] = 0;
   out_6621216135717119405[302] = 0;
   out_6621216135717119405[303] = 0;
   out_6621216135717119405[304] = 1;
   out_6621216135717119405[305] = 0;
   out_6621216135717119405[306] = 0;
   out_6621216135717119405[307] = 0;
   out_6621216135717119405[308] = 0;
   out_6621216135717119405[309] = 0;
   out_6621216135717119405[310] = 0;
   out_6621216135717119405[311] = 0;
   out_6621216135717119405[312] = 0;
   out_6621216135717119405[313] = 0;
   out_6621216135717119405[314] = 0;
   out_6621216135717119405[315] = 0;
   out_6621216135717119405[316] = 0;
   out_6621216135717119405[317] = 0;
   out_6621216135717119405[318] = 0;
   out_6621216135717119405[319] = 0;
   out_6621216135717119405[320] = 0;
   out_6621216135717119405[321] = 0;
   out_6621216135717119405[322] = 0;
   out_6621216135717119405[323] = 1;
}
void h_4(double *state, double *unused, double *out_6788230556268759212) {
   out_6788230556268759212[0] = state[6] + state[9];
   out_6788230556268759212[1] = state[7] + state[10];
   out_6788230556268759212[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7632527461987838329) {
   out_7632527461987838329[0] = 0;
   out_7632527461987838329[1] = 0;
   out_7632527461987838329[2] = 0;
   out_7632527461987838329[3] = 0;
   out_7632527461987838329[4] = 0;
   out_7632527461987838329[5] = 0;
   out_7632527461987838329[6] = 1;
   out_7632527461987838329[7] = 0;
   out_7632527461987838329[8] = 0;
   out_7632527461987838329[9] = 1;
   out_7632527461987838329[10] = 0;
   out_7632527461987838329[11] = 0;
   out_7632527461987838329[12] = 0;
   out_7632527461987838329[13] = 0;
   out_7632527461987838329[14] = 0;
   out_7632527461987838329[15] = 0;
   out_7632527461987838329[16] = 0;
   out_7632527461987838329[17] = 0;
   out_7632527461987838329[18] = 0;
   out_7632527461987838329[19] = 0;
   out_7632527461987838329[20] = 0;
   out_7632527461987838329[21] = 0;
   out_7632527461987838329[22] = 0;
   out_7632527461987838329[23] = 0;
   out_7632527461987838329[24] = 0;
   out_7632527461987838329[25] = 1;
   out_7632527461987838329[26] = 0;
   out_7632527461987838329[27] = 0;
   out_7632527461987838329[28] = 1;
   out_7632527461987838329[29] = 0;
   out_7632527461987838329[30] = 0;
   out_7632527461987838329[31] = 0;
   out_7632527461987838329[32] = 0;
   out_7632527461987838329[33] = 0;
   out_7632527461987838329[34] = 0;
   out_7632527461987838329[35] = 0;
   out_7632527461987838329[36] = 0;
   out_7632527461987838329[37] = 0;
   out_7632527461987838329[38] = 0;
   out_7632527461987838329[39] = 0;
   out_7632527461987838329[40] = 0;
   out_7632527461987838329[41] = 0;
   out_7632527461987838329[42] = 0;
   out_7632527461987838329[43] = 0;
   out_7632527461987838329[44] = 1;
   out_7632527461987838329[45] = 0;
   out_7632527461987838329[46] = 0;
   out_7632527461987838329[47] = 1;
   out_7632527461987838329[48] = 0;
   out_7632527461987838329[49] = 0;
   out_7632527461987838329[50] = 0;
   out_7632527461987838329[51] = 0;
   out_7632527461987838329[52] = 0;
   out_7632527461987838329[53] = 0;
}
void h_10(double *state, double *unused, double *out_8432036585650852946) {
   out_8432036585650852946[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8432036585650852946[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8432036585650852946[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8928260110437863487) {
   out_8928260110437863487[0] = 0;
   out_8928260110437863487[1] = 9.8100000000000005*cos(state[1]);
   out_8928260110437863487[2] = 0;
   out_8928260110437863487[3] = 0;
   out_8928260110437863487[4] = -state[8];
   out_8928260110437863487[5] = state[7];
   out_8928260110437863487[6] = 0;
   out_8928260110437863487[7] = state[5];
   out_8928260110437863487[8] = -state[4];
   out_8928260110437863487[9] = 0;
   out_8928260110437863487[10] = 0;
   out_8928260110437863487[11] = 0;
   out_8928260110437863487[12] = 1;
   out_8928260110437863487[13] = 0;
   out_8928260110437863487[14] = 0;
   out_8928260110437863487[15] = 1;
   out_8928260110437863487[16] = 0;
   out_8928260110437863487[17] = 0;
   out_8928260110437863487[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8928260110437863487[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8928260110437863487[20] = 0;
   out_8928260110437863487[21] = state[8];
   out_8928260110437863487[22] = 0;
   out_8928260110437863487[23] = -state[6];
   out_8928260110437863487[24] = -state[5];
   out_8928260110437863487[25] = 0;
   out_8928260110437863487[26] = state[3];
   out_8928260110437863487[27] = 0;
   out_8928260110437863487[28] = 0;
   out_8928260110437863487[29] = 0;
   out_8928260110437863487[30] = 0;
   out_8928260110437863487[31] = 1;
   out_8928260110437863487[32] = 0;
   out_8928260110437863487[33] = 0;
   out_8928260110437863487[34] = 1;
   out_8928260110437863487[35] = 0;
   out_8928260110437863487[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8928260110437863487[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8928260110437863487[38] = 0;
   out_8928260110437863487[39] = -state[7];
   out_8928260110437863487[40] = state[6];
   out_8928260110437863487[41] = 0;
   out_8928260110437863487[42] = state[4];
   out_8928260110437863487[43] = -state[3];
   out_8928260110437863487[44] = 0;
   out_8928260110437863487[45] = 0;
   out_8928260110437863487[46] = 0;
   out_8928260110437863487[47] = 0;
   out_8928260110437863487[48] = 0;
   out_8928260110437863487[49] = 0;
   out_8928260110437863487[50] = 1;
   out_8928260110437863487[51] = 0;
   out_8928260110437863487[52] = 0;
   out_8928260110437863487[53] = 1;
}
void h_13(double *state, double *unused, double *out_2724236674667547577) {
   out_2724236674667547577[0] = state[3];
   out_2724236674667547577[1] = state[4];
   out_2724236674667547577[2] = state[5];
}
void H_13(double *state, double *unused, double *out_8197129381669682433) {
   out_8197129381669682433[0] = 0;
   out_8197129381669682433[1] = 0;
   out_8197129381669682433[2] = 0;
   out_8197129381669682433[3] = 1;
   out_8197129381669682433[4] = 0;
   out_8197129381669682433[5] = 0;
   out_8197129381669682433[6] = 0;
   out_8197129381669682433[7] = 0;
   out_8197129381669682433[8] = 0;
   out_8197129381669682433[9] = 0;
   out_8197129381669682433[10] = 0;
   out_8197129381669682433[11] = 0;
   out_8197129381669682433[12] = 0;
   out_8197129381669682433[13] = 0;
   out_8197129381669682433[14] = 0;
   out_8197129381669682433[15] = 0;
   out_8197129381669682433[16] = 0;
   out_8197129381669682433[17] = 0;
   out_8197129381669682433[18] = 0;
   out_8197129381669682433[19] = 0;
   out_8197129381669682433[20] = 0;
   out_8197129381669682433[21] = 0;
   out_8197129381669682433[22] = 1;
   out_8197129381669682433[23] = 0;
   out_8197129381669682433[24] = 0;
   out_8197129381669682433[25] = 0;
   out_8197129381669682433[26] = 0;
   out_8197129381669682433[27] = 0;
   out_8197129381669682433[28] = 0;
   out_8197129381669682433[29] = 0;
   out_8197129381669682433[30] = 0;
   out_8197129381669682433[31] = 0;
   out_8197129381669682433[32] = 0;
   out_8197129381669682433[33] = 0;
   out_8197129381669682433[34] = 0;
   out_8197129381669682433[35] = 0;
   out_8197129381669682433[36] = 0;
   out_8197129381669682433[37] = 0;
   out_8197129381669682433[38] = 0;
   out_8197129381669682433[39] = 0;
   out_8197129381669682433[40] = 0;
   out_8197129381669682433[41] = 1;
   out_8197129381669682433[42] = 0;
   out_8197129381669682433[43] = 0;
   out_8197129381669682433[44] = 0;
   out_8197129381669682433[45] = 0;
   out_8197129381669682433[46] = 0;
   out_8197129381669682433[47] = 0;
   out_8197129381669682433[48] = 0;
   out_8197129381669682433[49] = 0;
   out_8197129381669682433[50] = 0;
   out_8197129381669682433[51] = 0;
   out_8197129381669682433[52] = 0;
   out_8197129381669682433[53] = 0;
}
void h_14(double *state, double *unused, double *out_7287061467575581493) {
   out_7287061467575581493[0] = state[6];
   out_7287061467575581493[1] = state[7];
   out_7287061467575581493[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4549739029692466033) {
   out_4549739029692466033[0] = 0;
   out_4549739029692466033[1] = 0;
   out_4549739029692466033[2] = 0;
   out_4549739029692466033[3] = 0;
   out_4549739029692466033[4] = 0;
   out_4549739029692466033[5] = 0;
   out_4549739029692466033[6] = 1;
   out_4549739029692466033[7] = 0;
   out_4549739029692466033[8] = 0;
   out_4549739029692466033[9] = 0;
   out_4549739029692466033[10] = 0;
   out_4549739029692466033[11] = 0;
   out_4549739029692466033[12] = 0;
   out_4549739029692466033[13] = 0;
   out_4549739029692466033[14] = 0;
   out_4549739029692466033[15] = 0;
   out_4549739029692466033[16] = 0;
   out_4549739029692466033[17] = 0;
   out_4549739029692466033[18] = 0;
   out_4549739029692466033[19] = 0;
   out_4549739029692466033[20] = 0;
   out_4549739029692466033[21] = 0;
   out_4549739029692466033[22] = 0;
   out_4549739029692466033[23] = 0;
   out_4549739029692466033[24] = 0;
   out_4549739029692466033[25] = 1;
   out_4549739029692466033[26] = 0;
   out_4549739029692466033[27] = 0;
   out_4549739029692466033[28] = 0;
   out_4549739029692466033[29] = 0;
   out_4549739029692466033[30] = 0;
   out_4549739029692466033[31] = 0;
   out_4549739029692466033[32] = 0;
   out_4549739029692466033[33] = 0;
   out_4549739029692466033[34] = 0;
   out_4549739029692466033[35] = 0;
   out_4549739029692466033[36] = 0;
   out_4549739029692466033[37] = 0;
   out_4549739029692466033[38] = 0;
   out_4549739029692466033[39] = 0;
   out_4549739029692466033[40] = 0;
   out_4549739029692466033[41] = 0;
   out_4549739029692466033[42] = 0;
   out_4549739029692466033[43] = 0;
   out_4549739029692466033[44] = 1;
   out_4549739029692466033[45] = 0;
   out_4549739029692466033[46] = 0;
   out_4549739029692466033[47] = 0;
   out_4549739029692466033[48] = 0;
   out_4549739029692466033[49] = 0;
   out_4549739029692466033[50] = 0;
   out_4549739029692466033[51] = 0;
   out_4549739029692466033[52] = 0;
   out_4549739029692466033[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_6656391008125290288) {
  err_fun(nom_x, delta_x, out_6656391008125290288);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2808972743269739579) {
  inv_err_fun(nom_x, true_x, out_2808972743269739579);
}
void pose_H_mod_fun(double *state, double *out_1869854945663891945) {
  H_mod_fun(state, out_1869854945663891945);
}
void pose_f_fun(double *state, double dt, double *out_1891205901656639709) {
  f_fun(state,  dt, out_1891205901656639709);
}
void pose_F_fun(double *state, double dt, double *out_6621216135717119405) {
  F_fun(state,  dt, out_6621216135717119405);
}
void pose_h_4(double *state, double *unused, double *out_6788230556268759212) {
  h_4(state, unused, out_6788230556268759212);
}
void pose_H_4(double *state, double *unused, double *out_7632527461987838329) {
  H_4(state, unused, out_7632527461987838329);
}
void pose_h_10(double *state, double *unused, double *out_8432036585650852946) {
  h_10(state, unused, out_8432036585650852946);
}
void pose_H_10(double *state, double *unused, double *out_8928260110437863487) {
  H_10(state, unused, out_8928260110437863487);
}
void pose_h_13(double *state, double *unused, double *out_2724236674667547577) {
  h_13(state, unused, out_2724236674667547577);
}
void pose_H_13(double *state, double *unused, double *out_8197129381669682433) {
  H_13(state, unused, out_8197129381669682433);
}
void pose_h_14(double *state, double *unused, double *out_7287061467575581493) {
  h_14(state, unused, out_7287061467575581493);
}
void pose_H_14(double *state, double *unused, double *out_4549739029692466033) {
  H_14(state, unused, out_4549739029692466033);
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
