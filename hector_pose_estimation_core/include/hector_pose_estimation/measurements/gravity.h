//=================================================================================================
// Copyright (c) 2011, Johannes Meyer, TU Darmstadt
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the Flight Systems and Automatic Control group,
//       TU Darmstadt, nor the names of its contributors may be used to
//       endorse or promote products derived from this software without
//       specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//=================================================================================================

#ifndef HECTOR_POSE_ESTIMATION_GRAVITY_H
#define HECTOR_POSE_ESTIMATION_GRAVITY_H

#include <hector_pose_estimation/measurement.h>

namespace hector_pose_estimation {

class GravityModel : public MeasurementModel_<GravityModel,3> {
public:
  using MeasurementModel_<GravityModel,3>::MeasurementVector;
  using MeasurementModel_<GravityModel,3>::NoiseVariance;

  GravityModel();
  virtual ~GravityModel();

  virtual bool init(PoseEstimation &estimator, State &state);

  virtual void setGravity(double gravity) { gravity_.z() = gravity; }
  virtual double getGravity() const { return gravity_.z(); }

  virtual bool active(const State &state) { return !(state.getSystemStatus() & STATE_ROLLPITCH); }
  virtual SystemStatus getStatusFlags() { return STATE_PSEUDO_ROLLPITCH; }

  virtual void getMeasurementNoise(NoiseVariance& R, const State&, bool init);
  virtual void getExpectedValue(MeasurementVector& y_pred, const State& state);
  virtual void getStateJacobian(MeasurementMatrix& C, const State& state, bool init);

protected:
  double stddev_;
  MeasurementVector gravity_;
};

typedef Measurement_<GravityModel> Gravity;
extern template class Measurement_<GravityModel>;

} // namespace hector_pose_estimation

#endif // HECTOR_POSE_ESTIMATION_GRAVITY_H
