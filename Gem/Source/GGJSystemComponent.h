
#pragma once

#include <AzCore/Component/Component.h>

#include <GGJ/GGJBus.h>

namespace GGJ
{
    class GGJSystemComponent
        : public AZ::Component
        , protected GGJRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(GGJSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        GGJSystemComponent();
        ~GGJSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // GGJRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
