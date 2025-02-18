#ifndef BLADE_MODULES_BEAMFORMER_GENERIC_HH
#define BLADE_MODULES_BEAMFORMER_GENERIC_HH

#include <string>

#include "blade/base.hh"
#include "blade/module.hh"

namespace Blade::Modules::Beamformer {

template<typename IT, typename OT>
class BLADE_API Generic : public Module {
 public:
    struct Config {
        U64 numberOfBeams;
        U64 numberOfAntennas;
        U64 numberOfFrequencyChannels;
        U64 numberOfTimeSamples;
        U64 numberOfPolarizations; 

        U64 blockSize = 512;
    };

    struct Input {
        const Vector<Device::CUDA, IT>& buf;
        const Vector<Device::CUDA, IT>& phasors;
    };

    struct Output {
        Vector<Device::CUDA, OT> buf;
    };

    explicit Generic(const Config& config, const Input& input);
    virtual ~Generic() = default;

    constexpr Vector<Device::CUDA, IT>& getInput() {
        return const_cast<Vector<Device::CUDA, IT>&>(this->input.buf);
    }

    constexpr Vector<Device::CUDA, IT>& getPhasors() {
        return const_cast<Vector<Device::CUDA, IT>&>(this->input.phasors);
    }

    constexpr const Vector<Device::CUDA, OT>& getOutput() const {
        return this->output.buf;
    }

    constexpr Config getConfig() const {
        return config;
    }

    virtual constexpr U64 getInputSize() const = 0;
    virtual constexpr U64 getOutputSize() const = 0;
    virtual constexpr U64 getPhasorsSize() const = 0;

    Result process(const cudaStream_t& stream = 0) final;

 protected:
    const Config config;
    const Input input;
    Output output;
};

}  // namespace Blade::Modules::Beamformer

#endif
