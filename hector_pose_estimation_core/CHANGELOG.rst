^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package hector_pose_estimation_core
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.1.5 (2014-10-02)
------------------
* fixed rate conversion to nav frame for the state message
* initialize reference values to NaN instead of 0.0 and added measurement/auto_* parameters consitently
  Added parameters:
  - gps/auto_reference
  - height/auto_elevation
  - baro/auto_elevation
  Already existed before:
  - magnetic/auto_heading
  All auto_* parameters are true by default.
* Contributors: Johannes Meyer

0.1.4 (2014-08-28)
------------------
* calculate euler angles directly in pose update without Eigen
  Eigen's eulerAngles() returns wrong yaw angles in Trusty for some reason.
* Contributors: Johannes Meyer

0.1.3 (2014-07-09)
------------------

0.1.2 (2014-06-02)
------------------
* added cmake_modules dependency for the Eigen cmake config
* Contributors: Johannes Meyer

0.1.1 (2014-03-30)
------------------
* Fixed boost 1.53 issues
  changed boost::shared_dynamic_cast to boost::dynamic_pointer_cast and
  boost::shared_static_cast to boost::static_pointer_cast
* hector_pose_estimation_core: rotate rate vector to nav frame in PoseEstimation::getState()
  All vectors in state messages (e.g. on topic /state) are given in nav frame. The rate vector
  has not been converted from body until now.
* Contributors: Christopher Hrabia, Johannes Meyer

0.1.0 (2013-09-03)
------------------
* catkinized stack hector_localization
