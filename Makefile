M5_FOLDER=/home/gem5/CRONO/m5
export # So sub-makes can see the env var

SUBDIRS= apsp bc sssp community connected_components dfs bfs pagerank triangle_counting

CRONO_DIR=$(PWD)

all:
	@printf "\033[0;33mmaking m5\n\033[0m"
	cd m5 && $(MAKE) && cd ..
	for dir in $(SUBDIRS); do \
		echo "\033[0;33mmaking $$dir\033[0m"; \
		$(MAKE) -C $(CRONO_DIR)/apps/$$dir; \
	done

clean:
	@printf "\033[0;33mcleaning m5\n\033[0m"
	cd m5 && $(MAKE) clean && cd ..
	for dir in $(SUBDIRS); do \
		echo "\033[0;33mcleaning $$dir\033[0m"; \
		$(MAKE) clean -C $(CRONO_DIR)/apps/$$dir; \
	done
