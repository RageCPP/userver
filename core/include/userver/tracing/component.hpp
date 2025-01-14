#pragma once

/// @file userver/tracing/component.hpp
/// @brief @copybrief components::Tracer

#include <userver/components/component_fwd.hpp>
#include <userver/components/raw_component_base.hpp>

USERVER_NAMESPACE_BEGIN

namespace components {

// clang-format off

/// @ingroup userver_components
///
/// @brief Component that initializes the request tracing facilities.
///
/// Finds the components::Logging component.
///
/// The component must be configured in service config.
///
/// ## Static options:
/// Name | Description | Default value
/// ---- | ----------- | -------------
/// service-name | name of the service to write in traces | ''
/// tracer | type of the tracer to trace, currently supported only 'native' | 'native'
///
/// ## Static configuration example:
///
/// @snippet components/common_component_list_test.cpp  Sample tracer component config

// clang-format on
class Tracer final : public RawComponentBase {
public:
    /// @ingroup userver_component_names
    /// @brief The default name of components::Tracer
    static constexpr std::string_view kName = "tracer";

    Tracer(const ComponentConfig& config, const ComponentContext& context);

    static yaml_config::Schema GetStaticConfigSchema();
};

template <>
inline constexpr bool kHasValidate<Tracer> = true;

template <>
inline constexpr auto kConfigFileMode<Tracer> = ConfigFileMode::kNotRequired;

}  // namespace components

USERVER_NAMESPACE_END
