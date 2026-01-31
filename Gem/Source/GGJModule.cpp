
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "GGJSystemComponent.h"

#include <GGJ/GGJTypeIds.h>

namespace GGJ
{
    class GGJModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(GGJModule, GGJModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(GGJModule, AZ::SystemAllocator);

        GGJModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                GGJSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<GGJSystemComponent>(),
            };
        }
    };
}// namespace GGJ

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), GGJ::GGJModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_GGJ, GGJ::GGJModule)
#endif
