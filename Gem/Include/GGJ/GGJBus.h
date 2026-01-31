
#pragma once

#include <GGJ/GGJTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace GGJ
{
    class GGJRequests
    {
    public:
        AZ_RTTI(GGJRequests, GGJRequestsTypeId);
        virtual ~GGJRequests() = default;
        // Put your public methods here
    };

    class GGJBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using GGJRequestBus = AZ::EBus<GGJRequests, GGJBusTraits>;
    using GGJInterface = AZ::Interface<GGJRequests>;

} // namespace GGJ
