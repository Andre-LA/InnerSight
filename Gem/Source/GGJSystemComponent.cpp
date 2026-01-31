
#include <AzCore/Serialization/SerializeContext.h>

#include "GGJSystemComponent.h"

#include <GGJ/GGJTypeIds.h>

namespace GGJ
{
    AZ_COMPONENT_IMPL(GGJSystemComponent, "GGJSystemComponent",
        GGJSystemComponentTypeId);

    void GGJSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<GGJSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void GGJSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("GGJService"));
    }

    void GGJSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("GGJService"));
    }

    void GGJSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void GGJSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    GGJSystemComponent::GGJSystemComponent()
    {
        if (GGJInterface::Get() == nullptr)
        {
            GGJInterface::Register(this);
        }
    }

    GGJSystemComponent::~GGJSystemComponent()
    {
        if (GGJInterface::Get() == this)
        {
            GGJInterface::Unregister(this);
        }
    }

    void GGJSystemComponent::Init()
    {
    }

    void GGJSystemComponent::Activate()
    {
        GGJRequestBus::Handler::BusConnect();
    }

    void GGJSystemComponent::Deactivate()
    {
        GGJRequestBus::Handler::BusDisconnect();
    }
}
