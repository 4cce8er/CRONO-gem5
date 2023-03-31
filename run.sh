TARGETS=(
    "apsp"
    "bc"
    "bc_non_partitioned"
    "bfs"
    "bfs_atomic"
    "community_atomic"
    "community_lock"
    "connected_components_atomic"
    "connected_components_lock"
    "dfs"
    "pagerank"
    "pagerank_lock"
    "sssp"
    "sssp_outer"
    "sssp_outer_atomic"
    "triangle_counting_atomic"
    "triangle_counting_lock"
    "sorted_neighbors_tri_lock"
)

if [ "$#" -ne 3 ]; then
    echo "Arg: [bm] [core_num]"
    echo "Possible bm choices:"
    echo "${TARGETS[@]}"
    exit 1
fi

BM=$1
CORE_NUM=$2
INPUT_SIZE=$3

GRAPH_ARGS="524288 1024"

FOLDER=""
case $BM in
    "apsp")
        FOLDER="apsp"
        cd apps/${FOLDER}
        ./${BM} ${CORE_NUM} ${GRAPH_ARGS}
    ;;
    "bc"|"bc_non_partitioned")
        FOLDER="bc"
        cd apps/${FOLDER}
        ./${BM} ${CORE_NUM} ${GRAPH_ARGS}
    ;;
    "bfs"|"bfs_atomic")
        FOLDER="bfs"
        cd apps/${FOLDER}
        ./${BM} 0 ${CORE_NUM} ${GRAPH_ARGS}
    ;;
    "community_atomic"|"community_lock")
        FOLDER="community"
        cd apps/${FOLDER}
        ./${BM} 0 ${CORE_NUM} 4 ${GRAPH_ARGS}
        # 4 for 4 iterations
    ;;
    "connected_components_atomic"|"connected_components_lock")
        FOLDER="connected_components"
        cd apps/${FOLDER}
        ./${BM} 0 ${CORE_NUM} ${GRAPH_ARGS}
    ;;
    "dfs")
        FOLDER="dfs"
        cd apps/${FOLDER}
        ./${BM} 0 ${CORE_NUM} ${GRAPH_ARGS}
    ;;
    "pagerank"|"pagerank_lock")
        FOLDER="pagerank"
        cd apps/${FOLDER}
        ./${BM} 0 ${CORE_NUM} ${GRAPH_ARGS}
    ;;
    "sssp"|"sssp_outer"|"sssp_outer_atomic")
        FOLDER="sssp"
        cd apps/${FOLDER}
        ./${BM} 0 ${CORE_NUM} ${GRAPH_ARGS}
    ;;
    "triangle_counting_atomic"|"triangle_counting_lock"|"sorted_neighbors_tri_lock")
        FOLDER="triangle_counting"
        cd apps/${FOLDER}
        ./${BM} 0 ${CORE_NUM} ${GRAPH_ARGS}
    ;;
    *)
        echo "No such bm option ${BM}"
        exit 1
    ;;
esac
