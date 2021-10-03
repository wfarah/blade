#include "blade/kernels/beamformer.hh"

using namespace Blade;

Result Run(const Kernel::Beamformer::Config & config);

int main() {
    Logger guard{};

    BL_INFO("Testing beamformer with the ATA kernel.");

    Kernel::Beamformer::Config config = {
        .NBEAMS = 16,
        .NANTS  = 20,
        .NCHANS = 384,
        .NTIME  = 8750,
        .NPOLS  = 2,
        .TBLOCK = 350,
        .recipe = Kernel::Beamformer::Recipe::ATA,
    };

    if (Run(config) != Result::SUCCESS) {
        BL_FATAL("Test failed.");
        return 1;
    }

    BL_INFO("Test succeeded.");

    return 0;
}
