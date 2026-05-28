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
void err_fun(double *nom_x, double *delta_x, double *out_7019737380087612192) {
   out_7019737380087612192[0] = delta_x[0] + nom_x[0];
   out_7019737380087612192[1] = delta_x[1] + nom_x[1];
   out_7019737380087612192[2] = delta_x[2] + nom_x[2];
   out_7019737380087612192[3] = delta_x[3] + nom_x[3];
   out_7019737380087612192[4] = delta_x[4] + nom_x[4];
   out_7019737380087612192[5] = delta_x[5] + nom_x[5];
   out_7019737380087612192[6] = delta_x[6] + nom_x[6];
   out_7019737380087612192[7] = delta_x[7] + nom_x[7];
   out_7019737380087612192[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5837591879726777447) {
   out_5837591879726777447[0] = -nom_x[0] + true_x[0];
   out_5837591879726777447[1] = -nom_x[1] + true_x[1];
   out_5837591879726777447[2] = -nom_x[2] + true_x[2];
   out_5837591879726777447[3] = -nom_x[3] + true_x[3];
   out_5837591879726777447[4] = -nom_x[4] + true_x[4];
   out_5837591879726777447[5] = -nom_x[5] + true_x[5];
   out_5837591879726777447[6] = -nom_x[6] + true_x[6];
   out_5837591879726777447[7] = -nom_x[7] + true_x[7];
   out_5837591879726777447[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7212341887433844410) {
   out_7212341887433844410[0] = 1.0;
   out_7212341887433844410[1] = 0.0;
   out_7212341887433844410[2] = 0.0;
   out_7212341887433844410[3] = 0.0;
   out_7212341887433844410[4] = 0.0;
   out_7212341887433844410[5] = 0.0;
   out_7212341887433844410[6] = 0.0;
   out_7212341887433844410[7] = 0.0;
   out_7212341887433844410[8] = 0.0;
   out_7212341887433844410[9] = 0.0;
   out_7212341887433844410[10] = 1.0;
   out_7212341887433844410[11] = 0.0;
   out_7212341887433844410[12] = 0.0;
   out_7212341887433844410[13] = 0.0;
   out_7212341887433844410[14] = 0.0;
   out_7212341887433844410[15] = 0.0;
   out_7212341887433844410[16] = 0.0;
   out_7212341887433844410[17] = 0.0;
   out_7212341887433844410[18] = 0.0;
   out_7212341887433844410[19] = 0.0;
   out_7212341887433844410[20] = 1.0;
   out_7212341887433844410[21] = 0.0;
   out_7212341887433844410[22] = 0.0;
   out_7212341887433844410[23] = 0.0;
   out_7212341887433844410[24] = 0.0;
   out_7212341887433844410[25] = 0.0;
   out_7212341887433844410[26] = 0.0;
   out_7212341887433844410[27] = 0.0;
   out_7212341887433844410[28] = 0.0;
   out_7212341887433844410[29] = 0.0;
   out_7212341887433844410[30] = 1.0;
   out_7212341887433844410[31] = 0.0;
   out_7212341887433844410[32] = 0.0;
   out_7212341887433844410[33] = 0.0;
   out_7212341887433844410[34] = 0.0;
   out_7212341887433844410[35] = 0.0;
   out_7212341887433844410[36] = 0.0;
   out_7212341887433844410[37] = 0.0;
   out_7212341887433844410[38] = 0.0;
   out_7212341887433844410[39] = 0.0;
   out_7212341887433844410[40] = 1.0;
   out_7212341887433844410[41] = 0.0;
   out_7212341887433844410[42] = 0.0;
   out_7212341887433844410[43] = 0.0;
   out_7212341887433844410[44] = 0.0;
   out_7212341887433844410[45] = 0.0;
   out_7212341887433844410[46] = 0.0;
   out_7212341887433844410[47] = 0.0;
   out_7212341887433844410[48] = 0.0;
   out_7212341887433844410[49] = 0.0;
   out_7212341887433844410[50] = 1.0;
   out_7212341887433844410[51] = 0.0;
   out_7212341887433844410[52] = 0.0;
   out_7212341887433844410[53] = 0.0;
   out_7212341887433844410[54] = 0.0;
   out_7212341887433844410[55] = 0.0;
   out_7212341887433844410[56] = 0.0;
   out_7212341887433844410[57] = 0.0;
   out_7212341887433844410[58] = 0.0;
   out_7212341887433844410[59] = 0.0;
   out_7212341887433844410[60] = 1.0;
   out_7212341887433844410[61] = 0.0;
   out_7212341887433844410[62] = 0.0;
   out_7212341887433844410[63] = 0.0;
   out_7212341887433844410[64] = 0.0;
   out_7212341887433844410[65] = 0.0;
   out_7212341887433844410[66] = 0.0;
   out_7212341887433844410[67] = 0.0;
   out_7212341887433844410[68] = 0.0;
   out_7212341887433844410[69] = 0.0;
   out_7212341887433844410[70] = 1.0;
   out_7212341887433844410[71] = 0.0;
   out_7212341887433844410[72] = 0.0;
   out_7212341887433844410[73] = 0.0;
   out_7212341887433844410[74] = 0.0;
   out_7212341887433844410[75] = 0.0;
   out_7212341887433844410[76] = 0.0;
   out_7212341887433844410[77] = 0.0;
   out_7212341887433844410[78] = 0.0;
   out_7212341887433844410[79] = 0.0;
   out_7212341887433844410[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_884422573903963140) {
   out_884422573903963140[0] = state[0];
   out_884422573903963140[1] = state[1];
   out_884422573903963140[2] = state[2];
   out_884422573903963140[3] = state[3];
   out_884422573903963140[4] = state[4];
   out_884422573903963140[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_884422573903963140[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_884422573903963140[7] = state[7];
   out_884422573903963140[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7930257990036637257) {
   out_7930257990036637257[0] = 1;
   out_7930257990036637257[1] = 0;
   out_7930257990036637257[2] = 0;
   out_7930257990036637257[3] = 0;
   out_7930257990036637257[4] = 0;
   out_7930257990036637257[5] = 0;
   out_7930257990036637257[6] = 0;
   out_7930257990036637257[7] = 0;
   out_7930257990036637257[8] = 0;
   out_7930257990036637257[9] = 0;
   out_7930257990036637257[10] = 1;
   out_7930257990036637257[11] = 0;
   out_7930257990036637257[12] = 0;
   out_7930257990036637257[13] = 0;
   out_7930257990036637257[14] = 0;
   out_7930257990036637257[15] = 0;
   out_7930257990036637257[16] = 0;
   out_7930257990036637257[17] = 0;
   out_7930257990036637257[18] = 0;
   out_7930257990036637257[19] = 0;
   out_7930257990036637257[20] = 1;
   out_7930257990036637257[21] = 0;
   out_7930257990036637257[22] = 0;
   out_7930257990036637257[23] = 0;
   out_7930257990036637257[24] = 0;
   out_7930257990036637257[25] = 0;
   out_7930257990036637257[26] = 0;
   out_7930257990036637257[27] = 0;
   out_7930257990036637257[28] = 0;
   out_7930257990036637257[29] = 0;
   out_7930257990036637257[30] = 1;
   out_7930257990036637257[31] = 0;
   out_7930257990036637257[32] = 0;
   out_7930257990036637257[33] = 0;
   out_7930257990036637257[34] = 0;
   out_7930257990036637257[35] = 0;
   out_7930257990036637257[36] = 0;
   out_7930257990036637257[37] = 0;
   out_7930257990036637257[38] = 0;
   out_7930257990036637257[39] = 0;
   out_7930257990036637257[40] = 1;
   out_7930257990036637257[41] = 0;
   out_7930257990036637257[42] = 0;
   out_7930257990036637257[43] = 0;
   out_7930257990036637257[44] = 0;
   out_7930257990036637257[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7930257990036637257[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7930257990036637257[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7930257990036637257[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7930257990036637257[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7930257990036637257[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7930257990036637257[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7930257990036637257[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7930257990036637257[53] = -9.8100000000000005*dt;
   out_7930257990036637257[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7930257990036637257[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7930257990036637257[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7930257990036637257[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7930257990036637257[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7930257990036637257[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7930257990036637257[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7930257990036637257[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7930257990036637257[62] = 0;
   out_7930257990036637257[63] = 0;
   out_7930257990036637257[64] = 0;
   out_7930257990036637257[65] = 0;
   out_7930257990036637257[66] = 0;
   out_7930257990036637257[67] = 0;
   out_7930257990036637257[68] = 0;
   out_7930257990036637257[69] = 0;
   out_7930257990036637257[70] = 1;
   out_7930257990036637257[71] = 0;
   out_7930257990036637257[72] = 0;
   out_7930257990036637257[73] = 0;
   out_7930257990036637257[74] = 0;
   out_7930257990036637257[75] = 0;
   out_7930257990036637257[76] = 0;
   out_7930257990036637257[77] = 0;
   out_7930257990036637257[78] = 0;
   out_7930257990036637257[79] = 0;
   out_7930257990036637257[80] = 1;
}
void h_25(double *state, double *unused, double *out_7492620826943930634) {
   out_7492620826943930634[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6439571343347838097) {
   out_6439571343347838097[0] = 0;
   out_6439571343347838097[1] = 0;
   out_6439571343347838097[2] = 0;
   out_6439571343347838097[3] = 0;
   out_6439571343347838097[4] = 0;
   out_6439571343347838097[5] = 0;
   out_6439571343347838097[6] = 1;
   out_6439571343347838097[7] = 0;
   out_6439571343347838097[8] = 0;
}
void h_24(double *state, double *unused, double *out_4985338018763469281) {
   out_4985338018763469281[0] = state[4];
   out_4985338018763469281[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7852599591386246934) {
   out_7852599591386246934[0] = 0;
   out_7852599591386246934[1] = 0;
   out_7852599591386246934[2] = 0;
   out_7852599591386246934[3] = 0;
   out_7852599591386246934[4] = 1;
   out_7852599591386246934[5] = 0;
   out_7852599591386246934[6] = 0;
   out_7852599591386246934[7] = 0;
   out_7852599591386246934[8] = 0;
   out_7852599591386246934[9] = 0;
   out_7852599591386246934[10] = 0;
   out_7852599591386246934[11] = 0;
   out_7852599591386246934[12] = 0;
   out_7852599591386246934[13] = 0;
   out_7852599591386246934[14] = 1;
   out_7852599591386246934[15] = 0;
   out_7852599591386246934[16] = 0;
   out_7852599591386246934[17] = 0;
}
void h_30(double *state, double *unused, double *out_3190857989944948541) {
   out_3190857989944948541[0] = state[4];
}
void H_30(double *state, double *unused, double *out_8957904301855086724) {
   out_8957904301855086724[0] = 0;
   out_8957904301855086724[1] = 0;
   out_8957904301855086724[2] = 0;
   out_8957904301855086724[3] = 0;
   out_8957904301855086724[4] = 1;
   out_8957904301855086724[5] = 0;
   out_8957904301855086724[6] = 0;
   out_8957904301855086724[7] = 0;
   out_8957904301855086724[8] = 0;
}
void h_26(double *state, double *unused, double *out_1810815277715897104) {
   out_1810815277715897104[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2698068024473781873) {
   out_2698068024473781873[0] = 0;
   out_2698068024473781873[1] = 0;
   out_2698068024473781873[2] = 0;
   out_2698068024473781873[3] = 0;
   out_2698068024473781873[4] = 0;
   out_2698068024473781873[5] = 0;
   out_2698068024473781873[6] = 0;
   out_2698068024473781873[7] = 1;
   out_2698068024473781873[8] = 0;
}
void h_27(double *state, double *unused, double *out_1225216092924761692) {
   out_1225216092924761692[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6783140990054661813) {
   out_6783140990054661813[0] = 0;
   out_6783140990054661813[1] = 0;
   out_6783140990054661813[2] = 0;
   out_6783140990054661813[3] = 1;
   out_6783140990054661813[4] = 0;
   out_6783140990054661813[5] = 0;
   out_6783140990054661813[6] = 0;
   out_6783140990054661813[7] = 0;
   out_6783140990054661813[8] = 0;
}
void h_29(double *state, double *unused, double *out_8192531257605794186) {
   out_8192531257605794186[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8978608427540072708) {
   out_8978608427540072708[0] = 0;
   out_8978608427540072708[1] = 1;
   out_8978608427540072708[2] = 0;
   out_8978608427540072708[3] = 0;
   out_8978608427540072708[4] = 0;
   out_8978608427540072708[5] = 0;
   out_8978608427540072708[6] = 0;
   out_8978608427540072708[7] = 0;
   out_8978608427540072708[8] = 0;
}
void h_28(double *state, double *unused, double *out_6973827342419625862) {
   out_6973827342419625862[0] = state[0];
}
void H_28(double *state, double *unused, double *out_4385736629099948334) {
   out_4385736629099948334[0] = 1;
   out_4385736629099948334[1] = 0;
   out_4385736629099948334[2] = 0;
   out_4385736629099948334[3] = 0;
   out_4385736629099948334[4] = 0;
   out_4385736629099948334[5] = 0;
   out_4385736629099948334[6] = 0;
   out_4385736629099948334[7] = 0;
   out_4385736629099948334[8] = 0;
}
void h_31(double *state, double *unused, double *out_7638140651164585605) {
   out_7638140651164585605[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2071859922240430397) {
   out_2071859922240430397[0] = 0;
   out_2071859922240430397[1] = 0;
   out_2071859922240430397[2] = 0;
   out_2071859922240430397[3] = 0;
   out_2071859922240430397[4] = 0;
   out_2071859922240430397[5] = 0;
   out_2071859922240430397[6] = 0;
   out_2071859922240430397[7] = 0;
   out_2071859922240430397[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_7019737380087612192) {
  err_fun(nom_x, delta_x, out_7019737380087612192);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5837591879726777447) {
  inv_err_fun(nom_x, true_x, out_5837591879726777447);
}
void car_H_mod_fun(double *state, double *out_7212341887433844410) {
  H_mod_fun(state, out_7212341887433844410);
}
void car_f_fun(double *state, double dt, double *out_884422573903963140) {
  f_fun(state,  dt, out_884422573903963140);
}
void car_F_fun(double *state, double dt, double *out_7930257990036637257) {
  F_fun(state,  dt, out_7930257990036637257);
}
void car_h_25(double *state, double *unused, double *out_7492620826943930634) {
  h_25(state, unused, out_7492620826943930634);
}
void car_H_25(double *state, double *unused, double *out_6439571343347838097) {
  H_25(state, unused, out_6439571343347838097);
}
void car_h_24(double *state, double *unused, double *out_4985338018763469281) {
  h_24(state, unused, out_4985338018763469281);
}
void car_H_24(double *state, double *unused, double *out_7852599591386246934) {
  H_24(state, unused, out_7852599591386246934);
}
void car_h_30(double *state, double *unused, double *out_3190857989944948541) {
  h_30(state, unused, out_3190857989944948541);
}
void car_H_30(double *state, double *unused, double *out_8957904301855086724) {
  H_30(state, unused, out_8957904301855086724);
}
void car_h_26(double *state, double *unused, double *out_1810815277715897104) {
  h_26(state, unused, out_1810815277715897104);
}
void car_H_26(double *state, double *unused, double *out_2698068024473781873) {
  H_26(state, unused, out_2698068024473781873);
}
void car_h_27(double *state, double *unused, double *out_1225216092924761692) {
  h_27(state, unused, out_1225216092924761692);
}
void car_H_27(double *state, double *unused, double *out_6783140990054661813) {
  H_27(state, unused, out_6783140990054661813);
}
void car_h_29(double *state, double *unused, double *out_8192531257605794186) {
  h_29(state, unused, out_8192531257605794186);
}
void car_H_29(double *state, double *unused, double *out_8978608427540072708) {
  H_29(state, unused, out_8978608427540072708);
}
void car_h_28(double *state, double *unused, double *out_6973827342419625862) {
  h_28(state, unused, out_6973827342419625862);
}
void car_H_28(double *state, double *unused, double *out_4385736629099948334) {
  H_28(state, unused, out_4385736629099948334);
}
void car_h_31(double *state, double *unused, double *out_7638140651164585605) {
  h_31(state, unused, out_7638140651164585605);
}
void car_H_31(double *state, double *unused, double *out_2071859922240430397) {
  H_31(state, unused, out_2071859922240430397);
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
