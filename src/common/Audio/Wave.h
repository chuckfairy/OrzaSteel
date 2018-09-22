/**
 * Wavefrom base class
 */
#pragma once

#include <cmath>
#include <cstdint>
#include <map>
#include <vector>


using std::vector;


namespace Orza { namespace Steel { namespace Audio {

class Wave {

    public:

        /**
         * Get frequency value on -1.0 to 1.0
         * Maybe overly complicated
         * This should also update the time based on the delta
         */

        virtual float * setOutputForTime(
            float * output,
            uint32_t nframes,
            float_t volume = 1.0
        ) {};

        void set(
            vector<float_t> newFreqs,
            uint32_t newRate,
            float_t newDelta
        ) {
            rate = newRate;
            delta = newDelta;
        }

    protected:

        Wave();

        /**
         * Props
         */

        float_t delta = 2.0;

        vector<float_t> freqs;

        uint32_t rate;

};

} } }
