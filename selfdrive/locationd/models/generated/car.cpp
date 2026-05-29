#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2814030462933274886) {
   out_2814030462933274886[0] = delta_x[0] + nom_x[0];
   out_2814030462933274886[1] = delta_x[1] + nom_x[1];
   out_2814030462933274886[2] = delta_x[2] + nom_x[2];
   out_2814030462933274886[3] = delta_x[3] + nom_x[3];
   out_2814030462933274886[4] = delta_x[4] + nom_x[4];
   out_2814030462933274886[5] = delta_x[5] + nom_x[5];
   out_2814030462933274886[6] = delta_x[6] + nom_x[6];
   out_2814030462933274886[7] = delta_x[7] + nom_x[7];
   out_2814030462933274886[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1640667606358073333) {
   out_1640667606358073333[0] = -nom_x[0] + true_x[0];
   out_1640667606358073333[1] = -nom_x[1] + true_x[1];
   out_1640667606358073333[2] = -nom_x[2] + true_x[2];
   out_1640667606358073333[3] = -nom_x[3] + true_x[3];
   out_1640667606358073333[4] = -nom_x[4] + true_x[4];
   out_1640667606358073333[5] = -nom_x[5] + true_x[5];
   out_1640667606358073333[6] = -nom_x[6] + true_x[6];
   out_1640667606358073333[7] = -nom_x[7] + true_x[7];
   out_1640667606358073333[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1064503278714903732) {
   out_1064503278714903732[0] = 1.0;
   out_1064503278714903732[1] = 0.0;
   out_1064503278714903732[2] = 0.0;
   out_1064503278714903732[3] = 0.0;
   out_1064503278714903732[4] = 0.0;
   out_1064503278714903732[5] = 0.0;
   out_1064503278714903732[6] = 0.0;
   out_1064503278714903732[7] = 0.0;
   out_1064503278714903732[8] = 0.0;
   out_1064503278714903732[9] = 0.0;
   out_1064503278714903732[10] = 1.0;
   out_1064503278714903732[11] = 0.0;
   out_1064503278714903732[12] = 0.0;
   out_1064503278714903732[13] = 0.0;
   out_1064503278714903732[14] = 0.0;
   out_1064503278714903732[15] = 0.0;
   out_1064503278714903732[16] = 0.0;
   out_1064503278714903732[17] = 0.0;
   out_1064503278714903732[18] = 0.0;
   out_1064503278714903732[19] = 0.0;
   out_1064503278714903732[20] = 1.0;
   out_1064503278714903732[21] = 0.0;
   out_1064503278714903732[22] = 0.0;
   out_1064503278714903732[23] = 0.0;
   out_1064503278714903732[24] = 0.0;
   out_1064503278714903732[25] = 0.0;
   out_1064503278714903732[26] = 0.0;
   out_1064503278714903732[27] = 0.0;
   out_1064503278714903732[28] = 0.0;
   out_1064503278714903732[29] = 0.0;
   out_1064503278714903732[30] = 1.0;
   out_1064503278714903732[31] = 0.0;
   out_1064503278714903732[32] = 0.0;
   out_1064503278714903732[33] = 0.0;
   out_1064503278714903732[34] = 0.0;
   out_1064503278714903732[35] = 0.0;
   out_1064503278714903732[36] = 0.0;
   out_1064503278714903732[37] = 0.0;
   out_1064503278714903732[38] = 0.0;
   out_1064503278714903732[39] = 0.0;
   out_1064503278714903732[40] = 1.0;
   out_1064503278714903732[41] = 0.0;
   out_1064503278714903732[42] = 0.0;
   out_1064503278714903732[43] = 0.0;
   out_1064503278714903732[44] = 0.0;
   out_1064503278714903732[45] = 0.0;
   out_1064503278714903732[46] = 0.0;
   out_1064503278714903732[47] = 0.0;
   out_1064503278714903732[48] = 0.0;
   out_1064503278714903732[49] = 0.0;
   out_1064503278714903732[50] = 1.0;
   out_1064503278714903732[51] = 0.0;
   out_1064503278714903732[52] = 0.0;
   out_1064503278714903732[53] = 0.0;
   out_1064503278714903732[54] = 0.0;
   out_1064503278714903732[55] = 0.0;
   out_1064503278714903732[56] = 0.0;
   out_1064503278714903732[57] = 0.0;
   out_1064503278714903732[58] = 0.0;
   out_1064503278714903732[59] = 0.0;
   out_1064503278714903732[60] = 1.0;
   out_1064503278714903732[61] = 0.0;
   out_1064503278714903732[62] = 0.0;
   out_1064503278714903732[63] = 0.0;
   out_1064503278714903732[64] = 0.0;
   out_1064503278714903732[65] = 0.0;
   out_1064503278714903732[66] = 0.0;
   out_1064503278714903732[67] = 0.0;
   out_1064503278714903732[68] = 0.0;
   out_1064503278714903732[69] = 0.0;
   out_1064503278714903732[70] = 1.0;
   out_1064503278714903732[71] = 0.0;
   out_1064503278714903732[72] = 0.0;
   out_1064503278714903732[73] = 0.0;
   out_1064503278714903732[74] = 0.0;
   out_1064503278714903732[75] = 0.0;
   out_1064503278714903732[76] = 0.0;
   out_1064503278714903732[77] = 0.0;
   out_1064503278714903732[78] = 0.0;
   out_1064503278714903732[79] = 0.0;
   out_1064503278714903732[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4383566153016226252) {
   out_4383566153016226252[0] = state[0];
   out_4383566153016226252[1] = state[1];
   out_4383566153016226252[2] = state[2];
   out_4383566153016226252[3] = state[3];
   out_4383566153016226252[4] = state[4];
   out_4383566153016226252[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4383566153016226252[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4383566153016226252[7] = state[7];
   out_4383566153016226252[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5929650816649805655) {
   out_5929650816649805655[0] = 1;
   out_5929650816649805655[1] = 0;
   out_5929650816649805655[2] = 0;
   out_5929650816649805655[3] = 0;
   out_5929650816649805655[4] = 0;
   out_5929650816649805655[5] = 0;
   out_5929650816649805655[6] = 0;
   out_5929650816649805655[7] = 0;
   out_5929650816649805655[8] = 0;
   out_5929650816649805655[9] = 0;
   out_5929650816649805655[10] = 1;
   out_5929650816649805655[11] = 0;
   out_5929650816649805655[12] = 0;
   out_5929650816649805655[13] = 0;
   out_5929650816649805655[14] = 0;
   out_5929650816649805655[15] = 0;
   out_5929650816649805655[16] = 0;
   out_5929650816649805655[17] = 0;
   out_5929650816649805655[18] = 0;
   out_5929650816649805655[19] = 0;
   out_5929650816649805655[20] = 1;
   out_5929650816649805655[21] = 0;
   out_5929650816649805655[22] = 0;
   out_5929650816649805655[23] = 0;
   out_5929650816649805655[24] = 0;
   out_5929650816649805655[25] = 0;
   out_5929650816649805655[26] = 0;
   out_5929650816649805655[27] = 0;
   out_5929650816649805655[28] = 0;
   out_5929650816649805655[29] = 0;
   out_5929650816649805655[30] = 1;
   out_5929650816649805655[31] = 0;
   out_5929650816649805655[32] = 0;
   out_5929650816649805655[33] = 0;
   out_5929650816649805655[34] = 0;
   out_5929650816649805655[35] = 0;
   out_5929650816649805655[36] = 0;
   out_5929650816649805655[37] = 0;
   out_5929650816649805655[38] = 0;
   out_5929650816649805655[39] = 0;
   out_5929650816649805655[40] = 1;
   out_5929650816649805655[41] = 0;
   out_5929650816649805655[42] = 0;
   out_5929650816649805655[43] = 0;
   out_5929650816649805655[44] = 0;
   out_5929650816649805655[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5929650816649805655[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5929650816649805655[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5929650816649805655[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5929650816649805655[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5929650816649805655[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5929650816649805655[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5929650816649805655[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5929650816649805655[53] = -9.8100000000000005*dt;
   out_5929650816649805655[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5929650816649805655[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5929650816649805655[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5929650816649805655[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5929650816649805655[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5929650816649805655[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5929650816649805655[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5929650816649805655[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5929650816649805655[62] = 0;
   out_5929650816649805655[63] = 0;
   out_5929650816649805655[64] = 0;
   out_5929650816649805655[65] = 0;
   out_5929650816649805655[66] = 0;
   out_5929650816649805655[67] = 0;
   out_5929650816649805655[68] = 0;
   out_5929650816649805655[69] = 0;
   out_5929650816649805655[70] = 1;
   out_5929650816649805655[71] = 0;
   out_5929650816649805655[72] = 0;
   out_5929650816649805655[73] = 0;
   out_5929650816649805655[74] = 0;
   out_5929650816649805655[75] = 0;
   out_5929650816649805655[76] = 0;
   out_5929650816649805655[77] = 0;
   out_5929650816649805655[78] = 0;
   out_5929650816649805655[79] = 0;
   out_5929650816649805655[80] = 1;
}
void h_25(double *state, double *unused, double *out_257622994030229427) {
   out_257622994030229427[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1569837720915200444) {
   out_1569837720915200444[0] = 0;
   out_1569837720915200444[1] = 0;
   out_1569837720915200444[2] = 0;
   out_1569837720915200444[3] = 0;
   out_1569837720915200444[4] = 0;
   out_1569837720915200444[5] = 0;
   out_1569837720915200444[6] = 1;
   out_1569837720915200444[7] = 0;
   out_1569837720915200444[8] = 0;
}
void h_24(double *state, double *unused, double *out_5563077321127263871) {
   out_5563077321127263871[0] = state[4];
   out_5563077321127263871[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1474479489089147748) {
   out_1474479489089147748[0] = 0;
   out_1474479489089147748[1] = 0;
   out_1474479489089147748[2] = 0;
   out_1474479489089147748[3] = 0;
   out_1474479489089147748[4] = 1;
   out_1474479489089147748[5] = 0;
   out_1474479489089147748[6] = 0;
   out_1474479489089147748[7] = 0;
   out_1474479489089147748[8] = 0;
   out_1474479489089147748[9] = 0;
   out_1474479489089147748[10] = 0;
   out_1474479489089147748[11] = 0;
   out_1474479489089147748[12] = 0;
   out_1474479489089147748[13] = 0;
   out_1474479489089147748[14] = 1;
   out_1474479489089147748[15] = 0;
   out_1474479489089147748[16] = 0;
   out_1474479489089147748[17] = 0;
}
void h_30(double *state, double *unused, double *out_3604060482398272225) {
   out_3604060482398272225[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1440498773771960374) {
   out_1440498773771960374[0] = 0;
   out_1440498773771960374[1] = 0;
   out_1440498773771960374[2] = 0;
   out_1440498773771960374[3] = 0;
   out_1440498773771960374[4] = 1;
   out_1440498773771960374[5] = 0;
   out_1440498773771960374[6] = 0;
   out_1440498773771960374[7] = 0;
   out_1440498773771960374[8] = 0;
}
void h_26(double *state, double *unused, double *out_5860714419304438626) {
   out_5860714419304438626[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2171665597958855780) {
   out_2171665597958855780[0] = 0;
   out_2171665597958855780[1] = 0;
   out_2171665597958855780[2] = 0;
   out_2171665597958855780[3] = 0;
   out_2171665597958855780[4] = 0;
   out_2171665597958855780[5] = 0;
   out_2171665597958855780[6] = 0;
   out_2171665597958855780[7] = 1;
   out_2171665597958855780[8] = 0;
}
void h_27(double *state, double *unused, double *out_8762920418410247015) {
   out_8762920418410247015[0] = state[3];
}
void H_27(double *state, double *unused, double *out_734264538028464537) {
   out_734264538028464537[0] = 0;
   out_734264538028464537[1] = 0;
   out_734264538028464537[2] = 0;
   out_734264538028464537[3] = 1;
   out_734264538028464537[4] = 0;
   out_734264538028464537[5] = 0;
   out_734264538028464537[6] = 0;
   out_734264538028464537[7] = 0;
   out_734264538028464537[8] = 0;
}
void h_29(double *state, double *unused, double *out_8605733750059117870) {
   out_8605733750059117870[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1950730118086352558) {
   out_1950730118086352558[0] = 0;
   out_1950730118086352558[1] = 1;
   out_1950730118086352558[2] = 0;
   out_1950730118086352558[3] = 0;
   out_1950730118086352558[4] = 0;
   out_1950730118086352558[5] = 0;
   out_1950730118086352558[6] = 0;
   out_1950730118086352558[7] = 0;
   out_1950730118086352558[8] = 0;
}
void h_28(double *state, double *unused, double *out_1327776983981546202) {
   out_1327776983981546202[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3914360389651678809) {
   out_3914360389651678809[0] = 1;
   out_3914360389651678809[1] = 0;
   out_3914360389651678809[2] = 0;
   out_3914360389651678809[3] = 0;
   out_3914360389651678809[4] = 0;
   out_3914360389651678809[5] = 0;
   out_3914360389651678809[6] = 0;
   out_3914360389651678809[7] = 0;
   out_3914360389651678809[8] = 0;
}
void h_31(double *state, double *unused, double *out_7224938158711261921) {
   out_7224938158711261921[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1600483682792160872) {
   out_1600483682792160872[0] = 0;
   out_1600483682792160872[1] = 0;
   out_1600483682792160872[2] = 0;
   out_1600483682792160872[3] = 0;
   out_1600483682792160872[4] = 0;
   out_1600483682792160872[5] = 0;
   out_1600483682792160872[6] = 0;
   out_1600483682792160872[7] = 0;
   out_1600483682792160872[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_2814030462933274886) {
  err_fun(nom_x, delta_x, out_2814030462933274886);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1640667606358073333) {
  inv_err_fun(nom_x, true_x, out_1640667606358073333);
}
void car_H_mod_fun(double *state, double *out_1064503278714903732) {
  H_mod_fun(state, out_1064503278714903732);
}
void car_f_fun(double *state, double dt, double *out_4383566153016226252) {
  f_fun(state,  dt, out_4383566153016226252);
}
void car_F_fun(double *state, double dt, double *out_5929650816649805655) {
  F_fun(state,  dt, out_5929650816649805655);
}
void car_h_25(double *state, double *unused, double *out_257622994030229427) {
  h_25(state, unused, out_257622994030229427);
}
void car_H_25(double *state, double *unused, double *out_1569837720915200444) {
  H_25(state, unused, out_1569837720915200444);
}
void car_h_24(double *state, double *unused, double *out_5563077321127263871) {
  h_24(state, unused, out_5563077321127263871);
}
void car_H_24(double *state, double *unused, double *out_1474479489089147748) {
  H_24(state, unused, out_1474479489089147748);
}
void car_h_30(double *state, double *unused, double *out_3604060482398272225) {
  h_30(state, unused, out_3604060482398272225);
}
void car_H_30(double *state, double *unused, double *out_1440498773771960374) {
  H_30(state, unused, out_1440498773771960374);
}
void car_h_26(double *state, double *unused, double *out_5860714419304438626) {
  h_26(state, unused, out_5860714419304438626);
}
void car_H_26(double *state, double *unused, double *out_2171665597958855780) {
  H_26(state, unused, out_2171665597958855780);
}
void car_h_27(double *state, double *unused, double *out_8762920418410247015) {
  h_27(state, unused, out_8762920418410247015);
}
void car_H_27(double *state, double *unused, double *out_734264538028464537) {
  H_27(state, unused, out_734264538028464537);
}
void car_h_29(double *state, double *unused, double *out_8605733750059117870) {
  h_29(state, unused, out_8605733750059117870);
}
void car_H_29(double *state, double *unused, double *out_1950730118086352558) {
  H_29(state, unused, out_1950730118086352558);
}
void car_h_28(double *state, double *unused, double *out_1327776983981546202) {
  h_28(state, unused, out_1327776983981546202);
}
void car_H_28(double *state, double *unused, double *out_3914360389651678809) {
  H_28(state, unused, out_3914360389651678809);
}
void car_h_31(double *state, double *unused, double *out_7224938158711261921) {
  h_31(state, unused, out_7224938158711261921);
}
void car_H_31(double *state, double *unused, double *out_1600483682792160872) {
  H_31(state, unused, out_1600483682792160872);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
