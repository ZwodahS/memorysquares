#ifndef _Z_FRAMEWORK_ZF_COMMON_ROUTE_H_
#define _Z_FRAMEWORK_ZF_COMMON_ROUTE_H_
#include "Grid.hpp"
#include <vector>
namespace zf
{
    /**
     * Defines a route to take from a start point to end point.
     * I know I can store this as a vector but I kind of feel that abstracting this can allow me to 
     * provide a common implementation for path finding later, like using TwoDSpace.
     */
    struct Route
    {
        zf::Grid start;
        zf::Grid end;
        /**
         * This route include the start and end.
         * This route can be use in both direction.
         */
        std::vector<zf::Grid> path;
        Route();
        Route(zf::Grid start, zf::Grid end);
        Route(std::vector<zf::Grid> path);
        /**
         * Return true if this route is for this start and end
         */
        bool isRouteFor(zf::Grid start, zf::Grid end);
        /**
         * Merge 2 route to form a new route.
         * This only works if route1.end = route2.start.
         * The new route will be stored in newRoute.
         * If the route cannot be merge, then false will be returned.
         * THIS DO NOT take care of repeating routes.
         * The pathfinding for that should be don't elsewhere.
         * This only works IF and ONLY IF route1.start != route2.start, route1.end == route2.start, route2.end != route1.end
         * and route1 and route2 size > 1
         */
        static bool mergeRoute(zf::Route& route1, zf::Route& route2, zf::Route& newRoute);
        /**
         * Construct a route from path, and put it in the route object
         */
        static bool constructRoute(std::vector<zf::Grid> path, zf::Route& route);
    };
}

#endif
