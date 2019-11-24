#ifndef PBDDIRECTPOSITIONBASEDSOLVERFORSTIFFRODSINTERFACE_H
#define PBDDIRECTPOSITIONBASEDSOLVERFORSTIFFRODSINTERFACE_H

#include "PBDCommon/PBDCommon.h"

namespace sofa
{
    namespace simulation
    {
        namespace PBDSimulation
        {
            // Implementation of "Direct Position-Based Solver for Stiff Rods" paper
            // (https://animation.rwth-aachen.de/publication/0557/)
            //
            //	Implemented by:
            //
            //	Crispin Deul
            //	Graduate School CE
            //	Technische Universität Darmstadt
            //
            //  deul[at] gsc.tu-darmstadt.de
            //


            class RodSegment
            {
            public:
                    virtual bool isDynamic() = 0;
                    virtual Real Mass() = 0;
                    virtual const Vector3r & InertiaTensor() = 0;
                    virtual const Vector3r & Position() = 0;
                    virtual const Quaternionr & Rotation() = 0;
            };

            class RodConstraint
            {
            public:
                    using Vector6r = Eigen::Matrix<Real, 6, 1>;
                    virtual unsigned int segmentIndex(unsigned int i) = 0;
                    virtual Eigen::Matrix<Real, 3, 4> & getConstraintInfo() = 0;
                    virtual Real getAverageSegmentLength() = 0;
                    virtual Vector3r &getRestDarbouxVector() = 0;
                    virtual Vector3r &getStiffnessCoefficientK() = 0;
                    virtual Vector3r & getStretchCompliance() = 0;
                    virtual Vector3r & getBendingAndTorsionCompliance() = 0;
            };
        }
    }
}

#endif // PBDDIRECTPOSITIONBASEDSOLVERFORSTIFFRODSINTERFACE_H