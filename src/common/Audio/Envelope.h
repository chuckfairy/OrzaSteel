/**
 * Envelope struct
 *
 * attack 0-1
 * sustain seconds?
 * state int frames
 * volume 0-1
 */
#pragma once

#include <cmath>
#include <cstdint>


namespace Orza { namespace Audio {


/**
 * Main struct
 */

struct Envelope {

    /**
     * Props
     */

    float_t attack = 1.0;

    float_t sustain = 1.0;

    uint32_t state = 0;

    float_t volume = 1.0;


    /**
     * Helpers
     */

    Envelope(
        float_t attack_ = 1.0,
        float_t sustain_ = 0.0,
        uint32_t state_ = 0,
        float_t volume_ = 1.0
    ) {
        attack = attack_;
        sustain = sustain_;
        state = state_;
        volume = volume_;
    };

    Envelope clone() {

        return Envelope(
            attack,
            sustain,
            state,
            volume
        );

    };

};

const Envelope DefaultEnvelope();

} }
